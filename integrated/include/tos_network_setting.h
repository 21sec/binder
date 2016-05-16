/**@defgroup 网络管理模块
@{

@brief 

@author 

@note 

@version 1.0.0 2015/06/17 linshunda 初稿
*/




#ifndef _TOS_NETWORK_SETTING_H_
#define _TOS_NETWORK_SETTING_H_
#include "fpi_error_code.h"
#include "fpi_base_type.h"
#ifdef __cplusplus
extern "C" {
#endif


#define NETWORK_16_LENGTH 16 //IP ,MASK,GATE DNS LENGTH
#define NETWORK_18_LENGTH 18 // MAC LENGTH

#define NETWORK_64_LENGTH 64
#define NETWORK_128_LENGTH 128
#define NETWORK_20_LENGTH 20
typedef struct ST_WIFI_LIST
{
    int page;
    int pageIndex;
}st_wifi_list_size_page;

typedef enum
{
    E_NETWORK_ACCESS_NOTIFY_PHY_DISCONNECT, //RJ45 pulled out
    E_NETWORK_ACCESS_NOTIFY_PHY_CONNECTTED, //RJ45 pluged in
    
}EN_NETWORK_ACCESS_NOTIFY_E;


typedef struct{
	char ip[NETWORK_16_LENGTH];
	char mask[NETWORK_16_LENGTH];
	char gateway[NETWORK_16_LENGTH];
	char dns[NETWORK_16_LENGTH];
	char mac[NETWORK_18_LENGTH];
} st_wire_network_info;

typedef enum
{
	E_WIRELESS_CIPHER_NONE = 0,
	E_WIRELESS_CIPHER_WEP,
	E_WIRELESS_CIPHER_TKIP,
	E_WIRELESS_CIPHER_AES,
	E_WIRELESS_CIPHER_CCMP
}EN_WIRELESS_CIPHER;

typedef enum
{
    ///WI-FI secutiry type is None
    API_ENCRY_NONE = 0,
    ///WI-FI security type is WEP
    API_ENCRY_WEP,
    ///WI-FI security type is WPA-PSK
    API_ENCRY_WPA_PSK,
    ///WI-FI security type is WPA2-PSK
    API_ENCRY_WPA2_PSK,
    ///WI-FI security type is WPA/WPA2-PSK
    API_ENCRY_MIXED_WPA_WPA2_PSK,
    ///WI-FI security type is WPA/WPA2-PSK
    API_ENCRY_NOT_SUPPORTED
}API_WIFI_SECURITY_TYPE;

typedef enum
{
    E_WIFI_MODE_B,      //802.11b
    E_WIFI_MODE_G,      //802.11g
    E_WIFI_MODE_N,     //802.11n
    E_WIFI_MODE_NUM
}API_EN_WIFI_MODE;

typedef enum   
{
    E_NET_PATTERN_WIRED,      
    E_NET_PATTERN_WIERLESS,      
    E_NET_PATTERN_PPPOE
}API_NET_PATTERN;

typedef struct
{
	char ssid[NETWORK_64_LENGTH];
	char name[NETWORK_64_LENGTH];
    char cipher[NETWORK_20_LENGTH ];
    API_WIFI_SECURITY_TYPE encryType;
    //EN_WIRELESS_CIPHER cipher;		// huangzezhan 20130613 
	API_EN_WIFI_MODE mode;              //802.11标准
	int strength;
} st_wireless_network_info;


//define ap info
typedef struct{
   //ssid of ap
   char ssid[NETWORK_64_LENGTH];
   //password of ap
   char pwd[NETWORK_64_LENGTH];
   //encryption of ap
   char encryption[NETWORK_20_LENGTH];
   // SECURITY of ap
   API_WIFI_SECURITY_TYPE SECURITY;
}st_ap_info;

typedef enum
{
	E_NETWORK_WIRE,
	E_NETWORK_WIRELESS,	
	E_NETWORK_PPPOE,
}EN_NETWORK_TYPE;

typedef enum
{
	E_NETWORK_IP,
	E_NETWORK_MASK,
	E_NETWORK_GATEWAY,
	E_NETWORK_DNS,
	E_NETWORK_MAC,	 
	E_NETWORK_SSID,
}EN_NETWORK_INFO_TYPE;

typedef enum{
	E_NETWORK_AUTO,//DHCP
	E_NETWORK_MANUAL,
	E_NETWORK_WIFI,
}E_NETWORK_CONNECT_TYPE;

typedef enum
{
	EN_NETWORK_NONE,
	EN_NETWORK_WIRED_CONNECTED,		//有线网络连接成功
	EN_NETWORK_WIRED_DISCONNECTED,			//有线网络连接断开	
	EN_NETWORK_WIRELESS_CONNECTED,		//无线网络连接成功
	EN_NETWORK_WIRELESS_DISCONNECTED,		//无线网络连接断开
	EN_NETWORK_TYPE_NUM,
}EN_NETWORK_CHANGE_TYPE;

/**
@brief 

@note 输入: 

@note 
//fpi_error api_network_get_wire_network_status(EN_API_NETWORK_ACCESS_NOTIFY_E *cable_status);
//fpi_error api_network_get_wireless_network_status(fpi_bool *value);

@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_network_get_hardware_status( EN_NETWORK_TYPE , int32_t*status);


/**
@brief 

@note 输入: 

@note 

@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/


/**
@brief 

@note 输入: 

@note 
fpi_error api_network_wire_network_manual(st_api_wire_network_info *info);
fpi_error api_network_wire_network_dhcp();

@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_network_wire_connect( E_NETWORK_CONNECT_TYPE type ,st_wire_network_info *info);

/**
@brief 

@note 输入: 

@note 
fpi_error api_network_get_wire_network_access(fpi_bool *connect_pattern);


@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_network_wire_get_connect_type( E_NETWORK_CONNECT_TYPE *type ); 


/*************************************************WIFI*******************************************************/



/**
@brief 

@note 输入: 

@note 
fpi_error api_network_get_wireless_network_connect_status(fpi_bool *value);

@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_network_get_connect_status(EN_NETWORK_TYPE,int32_t *value);


/**
@brief 

@note 输入: 

@note 
fpi_error api_network_wireless_get_current_speed(char *speed);

@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_network_get_current_speed(EN_NETWORK_TYPE,char *speed,int32_t size);



/**
@brief 

@note 输入: 

@note 
fpi_error api_network_wireless_get_current_signalquality(int32_t *value);


@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_network_wireless_get_current_signalquality(int32_t *value);//单位是什么(%)，范围


/**
@brief 

@note 输入: 

@note 
fpi_error api_network_wireless_get_current_signalstrength(int32_t *value);

@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_network_wireless_get_current_signalstrength(int32_t *value);//单位是什么，范围

/**
@brief 

@note 输入: 

@note 
	fpi_error api_network_wireless_status_type(int32_t *value);
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_network_wireless_get_encryption_mode(int32_t *value);


/**
@brief 

@note 输入: 

@note 
	fpi_error api_network_wireless_status_encrypt(char *data);
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_network_wireless_get_encrypt_algorithm(char *data,int32_t size );





/**
@brief 

@note 输入: 

@note 
	fpi_error api_network_wireless_status_channel_set(int32_t *channel_set);
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_network_wireless_get_channel( int32_t *channel,char *freq);



/**
@brief 

@note 输入: 

@note 
	fpi_error api_network_wireless_get_network_count(uint8_t *data);
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_network_wireless_get_ap_count(int32_t *data);


/**
@brief 

@note 输入: 

@note 
	fpi_error api_network_wireless_start_scan_network(void);
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_network_wireless_start_scan(void);

/**
@brief 

@note 输入: 

@note 
	
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_network_wireless_stop_scan(void);


/**
@brief 

@note 输入: 

@note 
	fpi_error api_network_wireless_get_available_network(int32_t count,int32_t pageIndex,st_api_wireless_network_info **ppwireless_info,int *sumNum);
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
//fpi_error tos_network_wireless_get_ap_list(int32_t count,int32_t pageIndex,st_wireless_network_info **ppwireless_info,int *sumNum);
fpi_error tos_network_wireless_get_ap_list( int32_t onePageApCount, \
                                              int32_t pageIndex, \
                                              st_wireless_network_info *pwireless_info,\
                                              int *pAvailableCount);
//fpi_error api_network_wireless_get_last_connect_ap_info(API_AP_INFO*  api_ap_info);
/**
@brief 

@note 输入: 

@note 
	fpi_error api_network_wireless_get_last_connect_ap_info(API_AP_INFO*  api_ap_info);
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_network_wireless_get_last_connect_ap_info(st_ap_info*  api_ap_info);

/**
@brief 

@note 输入: 

@note 
	fpi_error api_network_wireless_connect_network(char *ssid, char *psw,API_WIFI_SECURITY_TYPE SECURITY,char *encryption);
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_network_wireless_connect_manual(char *ssid, char *psw,API_WIFI_SECURITY_TYPE SECURITY,char *encryption);


/**
@brief 

@note 输入: 

@note 
	fpi_error api_network_connect_pbc();
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
 fpi_error tos_network_wireless_connect_pbc();

 /**
@brief 

@note 输入: 

@note 
	fpi_error api_network_abort_pbc();
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
 fpi_error tos_network_wireless_abort_pbc();


 /**
@brief 

@note 输入: 

@note 
	fpi_error api_wifi_connect_wps_pin(const char *pin_in,char *pin_out);
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_network_wireless_connect_wps_pin(const char *pin_in,char *pin_out,int32_t out_size);


 /**
@brief 

@note 输入: 

@note 
	fpi_error api_wifi_connect_wps_pin_fresh(char * pin);
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_network_wireless_wps_pin_fresh(char * pin_out);


 /**
@brief 

@note 输入: 

@note 
	fpi_error api_wifi_get_wps_pin(char *pin_out);
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_network_wireless_get_wps_pin(char *pin_out,int32_t size );


 /**
@brief 

@note 输入: 

@note 
	fpi_error tos_network_get_info(st_wire_network_info *network_info);
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_network_get_info(st_wire_network_info *network_info);

 /**
@brief 

@note 输入: 

@note 
	fpi_error tos_network_set_enable(fpi_bool enable);
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
 fpi_error tos_network_set_enable(fpi_bool enable);

 /**
@brief 

@note 输入: 

@note 
	fpi_error tos_network_get_enable(fpi_bool *enable);
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
  fpi_error tos_network_get_enable(fpi_bool *enable);
 
/**
@brief 

@note 输入: 

@note 
	fpi_error tos_network_set_select_pattern(EN_NETWORK_TYPE  connect_pattern);
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
 fpi_error tos_network_set_select_pattern(E_NETWORK_CONNECT_TYPE connect_pattern);

/**
@brief 

@note 输入: 

@note 
	fpi_error tos_network_get_select_pattern(EN_NETWORK_TYPE  *connect_pattern);
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_network_get_select_pattern(E_NETWORK_CONNECT_TYPE  *connect_pattern);
 
 /**
@brief 

@note 输入: 

@note 
	fpi_error tos_network_local_connection_test(void);
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
 fpi_error tos_network_local_connection_test(void);

/**
 @brief 
 
 @note 输入: 
 
 @note 
     fpi_error tos_network_connection_test(void);
 @return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
 */
  fpi_error tos_network_connection_test(void);
 

 /**
@brief 

@note 输入: 

@note 
	fpi_bool api_miracast_start();
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_network_wireless_miracast_start( void );
 /**
@brief 

@note 输入: 

@note 
	fpi_bool api_miracast_stop();
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_network_wireless_miracast_stop( void );


 /**
@brief 		used to send network changed status to middleware, current used in android system

@note 输入: type 	--EN_NETWORK_NONE 					无网络连接
					--EN_NETWORK_WIRED_CONNECTED		有线网络连接成功
					--EN_NETWORK_WIRELESS_CONNECTED	无线网络连接成功

@note 输出:none
	
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_network_change_notify(EN_NETWORK_CHANGE_TYPE type, int32_t reserved_data);


#if 0
/******************************************************************************
*Function: api_network_wireless_get_current_duration
*Description: 获取从网络初始化到目前的持续时间
*Input: char *time,the point to get the value.data buffer size API_NETWORK_64_LENGTH
*Output:time
*Return: fpi_error  FPI_ERROR_SUCCESS:获取成功 
                    FPI_ERROR_FAIL:获取失败
*Others:none
******************************************************************************/
fpi_error api_network_wireless_get_current_duration(char *time);



/******************************************************************************
*Function: api_network_wireless_get_current_mdis
*Description: 获取mdis
*Input: none
*Output:value:mdis size:128
*Return:FPI_ERROR_SUCCESS:获取成功  FPI_ERROR_FAIL:获取失败
*Others:none
******************************************************************************/
fpi_error tos_network_wireless_get_current_mdis(char *value);
/******************************************************************************
*Function: api_network_wireless_status_validation
*Description: 
*Input: 需要输入的ip、mask、gateway等
*Output:none
*Return:FPI_ERROR_SUCCESS:获取成功  FPI_ERROR_FAIL:获取失败
*Others:none
******************************************************************************/
//fpi_error api_network_wireless_status_validation(int32_t *value);

/******************************************************************************
*Function: api_network_wireless_status_channel_freq
*Description: 获取当前连接wifi信道频率
*Input: int32_t *  channel_freq:信道频率,the value range[] max_length:10
*Output:
*Return: fpi_error  FPI_ERROR_SUCCESS:获取成功
                    FPI_ERROR_FAIL:获取失败
*Others:none
******************************************************************************/
//fpi_error api_network_wireless_status_channel_freq(char *channel_freq);//和获取信道合并

/******************************************************************************
*Function: api_network_connection_test
*Description: test wifi connection (www.tcl.com)
*Input: none
*Output: result:true or false
*Return: fpi_error  FPI_ERROR_SUCCESS 
                    FPI_ERROR_FAIL     
*Others:none
******************************************************************************/
fpi_error api_network_connection_test(fpi_bool *result);


/******************************************************************************
*Function: api_network_local_connection_test
*Description: test local internet connection status
*Input: none
*Output: none
*Return: fpi_error  FPI_ERROR_SUCCESS 
                    FPI_ERROR_FAIL     
*Others:none
******************************************************************************/
fpi_error api_network_local_connection_test();


/******************************************************************************
*Function: api_network_set_network_enable
*Description: set the network enable
*Input: enable
*Output: 
*Return: fpi_error  FPI_ERROR_SUCCESS 
                    FPI_ERROR_FAIL     
*Others:none
******************************************************************************/
//fpi_error api_network_set_network_enable(fpi_bool enable);

/******************************************************************************
*Function: api_network_get_network_enable
*Description: get the network enable status
*Input: 
*Output: enable
*Return: fpi_error  FPI_ERROR_SUCCESS 
                    FPI_ERROR_FAIL     
*Others:none
******************************************************************************/
fpi_error tos_network_get_network_enable(fpi_bool *enable);

/******************************************************************************
*Function: api_network_get_network_pattern
*Description: get the network connect pattern
*Input: 
*Output: NET_CONNECT_PATTERN
*Return: fpi_error  FPI_ERROR_SUCCESS 
                    FPI_ERROR_FAIL     
*Others:none
******************************************************************************/
//fpi_error tos_network_get_connect_pattern(API_NET_PATTERN *NET_CONNECT_PATTERN);

/******************************************************************************
*Function: api_network_set_select_pattern
*Description: set the network connect pattern
*Input: NET_CONNECT_PATTERN
*Output: 
*Return: fpi_error  FPI_ERROR_SUCCESS 
                    FPI_ERROR_FAIL     
*Others:none
******************************************************************************/
//fpi_error tos_network_set_select_pattern(API_NET_PATTERN NET_CONNECT_PATTERN);


/******************************************************************************
*Function: api_network_switch_network
*Description: switch network between wired and wireless
*Input: none
*Output: none
*Return: fpi_error  FPI_ERROR_SUCCESS 
                    FPI_ERROR_FAIL     
*Others:none
******************************************************************************/

//fpi_error api_network_switch_network(void);

/******************************************************************************
*Function: api_network_get_connect_status
*Description: get network status
*Input: 
*Output: none
*Return: fpi_error  FPI_ERROR_SUCCESS 
                    FPI_ERROR_FAIL     
*Others:none
******************************************************************************/
//fpi_error api_network_get_connect_status(void);
#endif

#ifdef __cplusplus
}
#endif

#endif //_NETWORK_SETTING_H_
