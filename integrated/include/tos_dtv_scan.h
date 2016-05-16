/**@defgroup 数字电视搜台模块
@{

@brief 用于控制电视中搜台相关的操作
本文件不包含卫星相关的操作，在另外文件fpi_satellite.h中处理
**/

#ifndef __TOS_DTV_SCAN_H__
#define __TOS_DTV_SCAN_H__

#include "fpi_base_type.h"

#include "fpi_dtv_base.h"

#include "fpi_error_code.h"


#ifdef __cplusplus
extern "C" {
#endif

#define DTV_DEFALUT_SYMBOL_RATE     6875
#define DTV_DEFAULT_SCAN_BEGIN_FREQUENCY       259000
#define DTV_DEFAULT_SCAN_END_FREQUENCY     858000
#define DTV_DEFAULT_SCAN_NET_BEGIN_FREQUENCY       99000
#define MAX_NETWORK_NAME                        48


typedef enum
{
	E_SCAN_TYPE_FULL,				/*全频点搜台*/
	E_SCAN_TYPE_NIT,				/*NIT搜台*/
	E_SCAN_TYPE_SINGNLE,      	/* 单频点搜台*/
	E_SCAN_TYPE_ADVANCED,			/*高级搜台，只搜索指定频点的NIT表、SDT_Acture、SDT_Other表*/
	E_SCAN_TYPE_OAD,				/*OAD搜索*/
	E_SCAN_TYPE_NUM
}EN_TOS_DTV_SCAN_TYPE;

typedef enum
{
	E_SCAN_STRATEGY_NORMAL,					/*普通搜台*/
	E_SCAN_STRATEGY_UPDATE,					/*更新搜台，进行上次的搜台，只增加、更新节目*/
	E_SCAN_STRATEGY_FILTER_BY_OPERATOR,		/*定制化搜台,两次搜台，国内运营商匹配搜索需要*/
	E_SCAN_STRATEGY_UPC,						/* UPC搜台，eu平台使用*/
	E_SCAN_STRATEGY_NUM
}EN_TOS_DTV_SCAN_STRATEGY;


typedef enum
{
	E_SCAN_STATUS_NONE,		/* 非搜台状态*/
	E_SCAN_STATUS_PROGRESS,	/* 搜台过程中*/
	E_SCAN_STATUS_PAUSED,		/*  搜台暂停*/
	E_SCAN_STATUS_COMPLETED,	/* 搜台完成*/
	E_SCAN_STATUS_ERROR,		/* 搜台出错*/ 
	E_SCAN_STATUS_NUM
}EN_TOS_DTV_SCAN_STATUS;

typedef enum
{
    E_SCAN_SATELLITE_ALL, 
    E_SCAN_SATELLITE_NETWORK
} EN_TOS_DTV_SATELLITE_SCAN_MODE;


typedef enum
{
    E_SCAN_SATELLITE_CH_ALL, 
    E_SCAN_SATELLITE_CH_FREE,
} EN_TOS_DTV_SATELLITE_SCAN_CH_MODE;

typedef struct
{
	fpi_dtv_stream_port_t		port;			/* tuner端口*/ 
	EN_TOS_DTV_SCAN_TYPE		scanType;		/* 搜台类型 */
	fpi_dtv_delivery_type_t		deliveryType;	/* 天线类型 */
	fpi_dtv_qam_mode_t			modulation;	/* 正交振幅调制模式 */

	EN_TOS_DTV_SCAN_STRATEGY   scanStrategy;	/* 搜索策略 */
	
	uint32_t	frequencyFrom;	/* 开始频率，用于全频点搜台，单位是KHZ ,如果值大于0并且小于255则表示这个值为频道号*/
	uint32_t	frequencyTo;		/* 终止频率，用于全频点搜台，单位是KHZ ,如果值大于0并且小于255则表示这个值为频道号*/
	uint32_t	frequency;		/* 频点信息，用于手动搜台，单位是KHZ,如果值大于0并且小于255则表示这个值为频道号*/
	uint32_t	symbol;			/* 符号率,0表示自适应，单位是Kbps */
	uint32_t	networkId;		/* 运营商Id */

	uint32_t	satelliteID;	/* dvb-s 手动搜索参数satelliteID*/
	fpi_satellite_polairze_type_t satellitepol;		/* dvb-s 手动搜索参数极化方式*/

	uint32_t	satelliteoperatorID;		/* dvb-s 自动搜索参数operatorID*/
	EN_TOS_DTV_SATELLITE_SCAN_MODE		satellitescanMode;	/* dvb-s 自动搜索方式: network, all */
	EN_TOS_DTV_SATELLITE_SCAN_CH_MODE	satellitechMode;	/* dvb-s 自动搜索CH模式: all, free */
}tos_dtv_scan_param_t;

typedef struct
{
	EN_TOS_DTV_SCAN_TYPE		scanType;		/* 搜台类型 */
	fpi_dtv_delivery_type_t		deliveryType;	/* 天线类型 */
	uint8_t						progress;		/* 进度 */
	EN_TOS_DTV_SCAN_STATUS		scanStatus;	/* 状态，EN_FPI_DTV_SCAN_STATUS */
	uint16_t dtvCount;			/* 本次搜索到的所有dtv频道个数，不包含radio及data */
	uint16_t radioCount;		/* 本次搜索到的所有广播频道个数 */
	uint16_t dataCount;		/* 本次搜索到的所有数据频道个数 */
	uint32_t frequency;		/* 当前正在搜索的频点 */
	fpi_bool hasOperator;		/* 是否含运营商信息，如果搜台过程中检测到运营商信息，则启动运营商搜台 */
}tos_dtv_scanning_info_t;


typedef struct
{
    uint16_t u16NetworkId; 
    uint8_t u8NetWorkName[MAX_NETWORK_NAME];
}tos_dtv_muti_network_info;


/**
@brief 开始dtv搜台操作
@param[in] param 搜台的参数配置信息指针
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_dtv_scan_start(tos_dtv_scan_param_t *param);

#if		1	/*ATV	DTV	*/

/**
@brief 暂停搜台操作
@param[in]  port 高频头端口选择，多个高频头时可用
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_tv_scan_pause(fpi_dtv_stream_port_t port);

/**
@brief 恢复tv搜台操作
一般是在搜台暂停后,进行搜台动作的恢复
@param[in]  port 高频头端口选择，多个高频头时可用
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_tv_scan_resume(fpi_dtv_stream_port_t port);

/**
@brief 结束tv搜台操作
@param[in]  port 高频头端口选择，多个高频头时可用
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_tv_scan_stop(fpi_dtv_stream_port_t port);

#endif

/**
@brief 频道数据的保存
一般在搜台结束后全部保存，目前中间件自行处理数据的保存，作为预留使用，由应用控制节目的保存。

@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_dtv_scan_db_save();

/**
@brief 频道数据库清除
一般在搜台前进行数据的清除，目前中间件自行处理数据的清除，目前作为预留使用，由应用控制节目的清除。
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_dtv_scan_db_clear();

/**
@brief 获取Dtv搜台的状态
@param[out] status 返回搜台状态的指针
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_dtv_scan_get_status(EN_TOS_DTV_SCAN_STATUS *status);


/**
@brief 获取Dtv搜台的信息
@param[in] info 返回搜台回调结果的指针，和当前回调中数据相同，便于应用单独获取
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_dtv_scan_get_current_scan_info(tos_dtv_scanning_info_t *info);


/**
@brief 搜台模块处理回调
当搜台过程中发送搜台信息更新的消息时,包含的消息内容

@param[in] port 高频头端口选择，多个高频头时可用
@param[in] info 回调包含的内容
@param[in] userdata 返回用户注册的数据
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
typedef int32_t (*tos_dtv_scan_callback)(fpi_dtv_stream_port_t port, const tos_dtv_scanning_info_t *info, void* userdata);

/**
@brief 添加搜台模块处理回调
当搜台过程中，中间件会调用应用注册的本接口配合完成相应的操作的功能.

@param[in] port 高频头端口选择，多个高频头时可用
@param[in] callbakc 搜台回调函数指针
@param[in] userdata 用户数据,注册此回调时的userdata参数.
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/

fpi_error tos_dtv_scan_add_callback(fpi_dtv_stream_port_t port, tos_dtv_scan_callback callback, void* userdata);


/**
@brief 删除搜台回调函数

@param[in] port 高频头端口选择，多个高频头时可用
@param[in] callbakc Dtv搜台回调函数指针
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_dtv_scan_remove_callback(fpi_dtv_stream_port_t port, tos_dtv_scan_callback callback);

/**
@brief 根据deliveryType、networkId 获取multi_network_list

@param[in] 
@param[in] 
@note deliveryType、networkId 后续使用，目前接口中未用到
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
int tos_dtv_scan_get_multi_network_list(tos_dtv_muti_network_info *pstNetworkList, int listSize, fpi_dtv_delivery_type_t deliveryType,uint32_t networkId);

#ifdef __cplusplus
}
#endif
/** @} */
#endif
