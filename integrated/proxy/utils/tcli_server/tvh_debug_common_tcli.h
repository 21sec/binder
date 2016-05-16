#ifndef _TVH_DEBUG_COMMON_H_
#define _TVH_DEBUG_COMMON_H_

#define TVH_PRIVATE_DATA_SIZE 1024
#define ROW_NUM 10
#define FUN_ROW_NUM 3
#define BUFFER_SIZE 2048
#define BUFFER_SIZE_1024 1024
#define BUFFER_SIZE_256 256
#define BUFFER_SIZE_128 128

typedef unsigned int uint32_t;
typedef int  int32_t;
typedef unsigned char uint8_t;
typedef int (*pfun)(char *buf, int len);

typedef struct tag_tvh_route_para
{
	uint32_t un32_client_id;
	uint8_t un32_entry_id[BUFFER_SIZE_128];
	uint32_t un32_data_length;
	int32_t request_result;
	int32_t exten_para;
	uint8_t request_para[TVH_PRIVATE_DATA_SIZE];
}tvh_route_para;


#endif // _TVH_DEBUG_COMMON_H_