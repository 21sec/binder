/*********************************************************************************************
* Filename	: sita_request_property.c
* Author   	: wangzliang
* Description:   
* Version:   
* Function List:	
* 1. --------- 
* History: 	
* <author>  	  <time>   			<version >   <desc>	
* ganyue      2015-1-4 	 		   1.0    	 	build this moudle  	
* Copyright	: TCL Electronics(Shen Zhen) Co.,Ltd.
********************************************************************************************/
#include "fpi_debug_helper.h"
#include "sita_list.h"
#include <limits.h>
#include <string.h>

SET_MODEL_ID(SITA_MODULE_PROPERTY);

#if !defined(_HASHLIMIT)
#define _HASHLIMIT		5
#endif

#define _MAX_INT (INT_MAX-2)  /* maximum value of an int (-2 for safety) */
#define _DEFAULT_HASH_LENGTH (32)

typedef struct string_node {
    struct list_head list;
    unsigned int hash_value;
    char* key;
    unsigned int  key_len;
} string_node;

typedef struct string_pool {
  struct list_head **hash;
  unsigned int nuse;  /* number of elements */
  int size;
} string_pool;

static string_pool property_pool={0};
static unsigned int hash_seed=0x1234;

static unsigned int _hash_calculate (const char *str, size_t l, unsigned int seed) 
{
    unsigned int h = seed ^ ((unsigned int)l);
    size_t l1;
    size_t step = (l >> _HASHLIMIT) + 1;
    for (l1 = l; l1 >= step; l1 -= step)
        h = h ^ ((h<<5) + (h>>2) + (unsigned char)(str[l1 - 1]));
    return h;
}

static void _free_node(string_node* string_node)
{
    if(string_node==NULL)
    {
        return;
    }

    if(string_node->key!=NULL)
    {
        free(string_node->key);
    }

    free(string_node);
}

static int _clean_pool(void)
{
    string_node *content;
    struct list_head* pos;
    struct list_head* n;
    struct list_head* hash_list = NULL;
    int i;

    if(property_pool.size==0)
    {
        fpi_trace("[%s: %d]hash table is empty!!!\n",__FUNCTION__,__LINE__);
        return 0;
    }
    
    for(i=0;i<property_pool.size;i++)
    {
        hash_list=property_pool.hash[i];
        list_for_each_safe(pos,n,hash_list)
        {
            content=list_entry(pos,struct string_node,list);
            list_del(pos);
            _free_node(content);
        }
        free(hash_list);
    }
    if(hash_list!=NULL)
        free(property_pool.hash);
    property_pool.nuse=0;
    property_pool.size=0;
    
    return 0;
}

static void _pool_resize(int newsize)
{
    struct list_head **new_hash = NULL;
    struct list_head* pos;
    struct list_head* n;
    struct list_head* node_head;
    struct list_head* new_head;
    string_node *content;
    int i,num;
    
    if(newsize>property_pool.size)
    {
        new_hash=(struct list_head **)malloc(newsize*sizeof(struct list_head *));
        //init new hash node head
        for (i = 0; i < newsize; i++) 
        {
            new_hash[i]=(struct list_head *)malloc(sizeof(struct list_head));
            INIT_LIST_HEAD(new_hash[i]);
        }
    }
    else
    {
       fpi_err("[%s: %d]illegal newsize = %d, old size = %d!!!\n",__FUNCTION__,__LINE__,newsize,property_pool.size); 
       return;
    }

    //rehash
    for(i=0;i<property_pool.size;i++)
    {
        node_head=property_pool.hash[i];
        list_for_each_safe(pos,n,node_head)
        {
            content=list_entry(pos,struct string_node,list);
            new_head=new_hash[(int)(content->hash_value&(newsize-1))];
            list_del(pos);
            list_add(pos,new_head);
        }
    }

    num=property_pool.nuse;
    //delete old hash
    _clean_pool();

    //add new hash to table
    property_pool.size=newsize;
    property_pool.nuse=num;
    property_pool.hash=new_hash;
    
    return;
}

static const char* _add_node(const char *key,unsigned int hash_value,struct list_head* head)
{
    string_node *_node=(string_node *)malloc(sizeof(string_node));
    if(_node==NULL)
    {
        fpi_trace("[%s: %d]no memory!!!\n",__FUNCTION__,__LINE__);
        return NULL;
    }

    _node->hash_value=hash_value;
    _node->key_len=strlen(key);
    _node->key=(char*)malloc(_node->key_len+1);
    if(_node->key==NULL)
    {
        fpi_trace("[%s: %d]no memory!!!\n",__FUNCTION__,__LINE__);
        free(_node);
        return NULL;
    }
    strcpy(_node->key,key);
    list_add(&_node->list,head);
    property_pool.nuse++;
    //printf("[%s: %d]add key %s to pool, used is %d, size is %d!!!\n",__FUNCTION__,__LINE__,_node->key,property_pool.nuse,property_pool.size);
    return _node->key;
}

const char* strings_pool_get(const char *key)
{
    string_node *content;
    struct list_head* pos;
    struct list_head* n;
    struct list_head* hash_list;
    unsigned int h = _hash_calculate(key, strlen(key), hash_seed);

    if(property_pool.size>0)
    {
        //get head
        hash_list=property_pool.hash[(int)(h&(property_pool.size-1))];
        list_for_each_safe(pos,n,hash_list)
        {
            content=list_entry(pos,struct string_node,list);
            if (h == content->hash_value 
                &&content->key_len==strlen(key)
                &&(memcmp(key, content->key, content->key_len * sizeof(char)) == 0))
            {
                //key exist, then return the key address
                //printf("[%s: %d]find key %s from pool!!!\n",__FUNCTION__,__LINE__,content->key);
                return content->key;
            }
        }
    }

    //not found, add a new node
    if(property_pool.nuse>=(unsigned int)property_pool.size&&property_pool.size<=_MAX_INT/2)
    {
        if(property_pool.size==0)
        {
            _pool_resize(_DEFAULT_HASH_LENGTH);  /* first time add hash*/
        }
        else
        {
            _pool_resize(property_pool.size*2);  /* too crowded */
        }
    }
    hash_list=property_pool.hash[(int)(h&(property_pool.size-1))];
    return _add_node(key,h,hash_list);
}


