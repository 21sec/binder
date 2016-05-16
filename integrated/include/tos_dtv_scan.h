/**@defgroup ���ֵ�����̨ģ��
@{

@brief ���ڿ��Ƶ�������̨��صĲ���
���ļ�������������صĲ������������ļ�fpi_satellite.h�д���
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
	E_SCAN_TYPE_FULL,				/*ȫƵ����̨*/
	E_SCAN_TYPE_NIT,				/*NIT��̨*/
	E_SCAN_TYPE_SINGNLE,      	/* ��Ƶ����̨*/
	E_SCAN_TYPE_ADVANCED,			/*�߼���̨��ֻ����ָ��Ƶ���NIT��SDT_Acture��SDT_Other��*/
	E_SCAN_TYPE_OAD,				/*OAD����*/
	E_SCAN_TYPE_NUM
}EN_TOS_DTV_SCAN_TYPE;

typedef enum
{
	E_SCAN_STRATEGY_NORMAL,					/*��ͨ��̨*/
	E_SCAN_STRATEGY_UPDATE,					/*������̨�������ϴε���̨��ֻ���ӡ����½�Ŀ*/
	E_SCAN_STRATEGY_FILTER_BY_OPERATOR,		/*���ƻ���̨,������̨��������Ӫ��ƥ��������Ҫ*/
	E_SCAN_STRATEGY_UPC,						/* UPC��̨��euƽ̨ʹ��*/
	E_SCAN_STRATEGY_NUM
}EN_TOS_DTV_SCAN_STRATEGY;


typedef enum
{
	E_SCAN_STATUS_NONE,		/* ����̨״̬*/
	E_SCAN_STATUS_PROGRESS,	/* ��̨������*/
	E_SCAN_STATUS_PAUSED,		/*  ��̨��ͣ*/
	E_SCAN_STATUS_COMPLETED,	/* ��̨���*/
	E_SCAN_STATUS_ERROR,		/* ��̨����*/ 
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
	fpi_dtv_stream_port_t		port;			/* tuner�˿�*/ 
	EN_TOS_DTV_SCAN_TYPE		scanType;		/* ��̨���� */
	fpi_dtv_delivery_type_t		deliveryType;	/* �������� */
	fpi_dtv_qam_mode_t			modulation;	/* �����������ģʽ */

	EN_TOS_DTV_SCAN_STRATEGY   scanStrategy;	/* �������� */
	
	uint32_t	frequencyFrom;	/* ��ʼƵ�ʣ�����ȫƵ����̨����λ��KHZ ,���ֵ����0����С��255���ʾ���ֵΪƵ����*/
	uint32_t	frequencyTo;		/* ��ֹƵ�ʣ�����ȫƵ����̨����λ��KHZ ,���ֵ����0����С��255���ʾ���ֵΪƵ����*/
	uint32_t	frequency;		/* Ƶ����Ϣ�������ֶ���̨����λ��KHZ,���ֵ����0����С��255���ʾ���ֵΪƵ����*/
	uint32_t	symbol;			/* ������,0��ʾ����Ӧ����λ��Kbps */
	uint32_t	networkId;		/* ��Ӫ��Id */

	uint32_t	satelliteID;	/* dvb-s �ֶ���������satelliteID*/
	fpi_satellite_polairze_type_t satellitepol;		/* dvb-s �ֶ���������������ʽ*/

	uint32_t	satelliteoperatorID;		/* dvb-s �Զ���������operatorID*/
	EN_TOS_DTV_SATELLITE_SCAN_MODE		satellitescanMode;	/* dvb-s �Զ�������ʽ: network, all */
	EN_TOS_DTV_SATELLITE_SCAN_CH_MODE	satellitechMode;	/* dvb-s �Զ�����CHģʽ: all, free */
}tos_dtv_scan_param_t;

typedef struct
{
	EN_TOS_DTV_SCAN_TYPE		scanType;		/* ��̨���� */
	fpi_dtv_delivery_type_t		deliveryType;	/* �������� */
	uint8_t						progress;		/* ���� */
	EN_TOS_DTV_SCAN_STATUS		scanStatus;	/* ״̬��EN_FPI_DTV_SCAN_STATUS */
	uint16_t dtvCount;			/* ����������������dtvƵ��������������radio��data */
	uint16_t radioCount;		/* ���������������й㲥Ƶ������ */
	uint16_t dataCount;		/* ��������������������Ƶ������ */
	uint32_t frequency;		/* ��ǰ����������Ƶ�� */
	fpi_bool hasOperator;		/* �Ƿ���Ӫ����Ϣ�������̨�����м�⵽��Ӫ����Ϣ����������Ӫ����̨ */
}tos_dtv_scanning_info_t;


typedef struct
{
    uint16_t u16NetworkId; 
    uint8_t u8NetWorkName[MAX_NETWORK_NAME];
}tos_dtv_muti_network_info;


/**
@brief ��ʼdtv��̨����
@param[in] param ��̨�Ĳ���������Ϣָ��
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_dtv_scan_start(tos_dtv_scan_param_t *param);

#if		1	/*ATV	DTV	*/

/**
@brief ��ͣ��̨����
@param[in]  port ��Ƶͷ�˿�ѡ�񣬶����Ƶͷʱ����
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_tv_scan_pause(fpi_dtv_stream_port_t port);

/**
@brief �ָ�tv��̨����
һ��������̨��ͣ��,������̨�����Ļָ�
@param[in]  port ��Ƶͷ�˿�ѡ�񣬶����Ƶͷʱ����
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_tv_scan_resume(fpi_dtv_stream_port_t port);

/**
@brief ����tv��̨����
@param[in]  port ��Ƶͷ�˿�ѡ�񣬶����Ƶͷʱ����
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_tv_scan_stop(fpi_dtv_stream_port_t port);

#endif

/**
@brief Ƶ�����ݵı���
һ������̨������ȫ�����棬Ŀǰ�м�����д������ݵı��棬��ΪԤ��ʹ�ã���Ӧ�ÿ��ƽ�Ŀ�ı��档

@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_dtv_scan_db_save();

/**
@brief Ƶ�����ݿ����
һ������̨ǰ�������ݵ������Ŀǰ�м�����д������ݵ������Ŀǰ��ΪԤ��ʹ�ã���Ӧ�ÿ��ƽ�Ŀ�������
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_dtv_scan_db_clear();

/**
@brief ��ȡDtv��̨��״̬
@param[out] status ������̨״̬��ָ��
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_dtv_scan_get_status(EN_TOS_DTV_SCAN_STATUS *status);


/**
@brief ��ȡDtv��̨����Ϣ
@param[in] info ������̨�ص������ָ�룬�͵�ǰ�ص���������ͬ������Ӧ�õ�����ȡ
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_dtv_scan_get_current_scan_info(tos_dtv_scanning_info_t *info);


/**
@brief ��̨ģ�鴦��ص�
����̨�����з�����̨��Ϣ���µ���Ϣʱ,��������Ϣ����

@param[in] port ��Ƶͷ�˿�ѡ�񣬶����Ƶͷʱ����
@param[in] info �ص�����������
@param[in] userdata �����û�ע�������
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
typedef int32_t (*tos_dtv_scan_callback)(fpi_dtv_stream_port_t port, const tos_dtv_scanning_info_t *info, void* userdata);

/**
@brief �����̨ģ�鴦��ص�
����̨�����У��м�������Ӧ��ע��ı��ӿ���������Ӧ�Ĳ����Ĺ���.

@param[in] port ��Ƶͷ�˿�ѡ�񣬶����Ƶͷʱ����
@param[in] callbakc ��̨�ص�����ָ��
@param[in] userdata �û�����,ע��˻ص�ʱ��userdata����.
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/

fpi_error tos_dtv_scan_add_callback(fpi_dtv_stream_port_t port, tos_dtv_scan_callback callback, void* userdata);


/**
@brief ɾ����̨�ص�����

@param[in] port ��Ƶͷ�˿�ѡ�񣬶����Ƶͷʱ����
@param[in] callbakc Dtv��̨�ص�����ָ��
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_dtv_scan_remove_callback(fpi_dtv_stream_port_t port, tos_dtv_scan_callback callback);

/**
@brief ����deliveryType��networkId ��ȡmulti_network_list

@param[in] 
@param[in] 
@note deliveryType��networkId ����ʹ�ã�Ŀǰ�ӿ���δ�õ�
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
int tos_dtv_scan_get_multi_network_list(tos_dtv_muti_network_info *pstNetworkList, int listSize, fpi_dtv_delivery_type_t deliveryType,uint32_t networkId);

#ifdef __cplusplus
}
#endif
/** @} */
#endif
