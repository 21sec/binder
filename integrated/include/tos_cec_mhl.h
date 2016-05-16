/**@defgroup cec ��mhl 
@{

@author 

@note 

@version 1.0.0 2014/12/17 linshunda ����
*/


#ifndef __TOS_CEC__
#define __TOS_CEC__

#include "fpi_base_type.h"
#include "fpi_error_code.h"


#ifdef __cplusplus
extern "C" {
#endif

/**
@brief CEC���Ƶ�Դ�Ķ���
**/
typedef enum
{
	EN_CEC_POWER_POWERON,
	EN_CEC_POWER_STANDBY,
}EN_CEC_POWER_TYPE;

/**
@brief ����CEC�豸�Ĺ���
**/
typedef enum{
	EN_CEC_VALUE_VOLUME,	
	EN_CEC_VALUE_MUTE,
}EN_CEC_VALUE_TYPE;

#define MAX_OSD_NAME_LEN   15

/**
@brief CEC�豸����Ϣ
**/
typedef struct
{
    uint8_t un8DevLogAddr;
    uint8_t un8DevPhyAddr;
    uint8_t un8DevNum;
    uint8_t un8DevType;
    char szDevName[MAX_OSD_NAME_LEN];
}st_fpi_cec_dev_base;

/**
@brief MHL��Ϣ����
**/
typedef enum
{
	EN_MHL_MSCE		= 0x02,
	EN_MHL_RCP		= 0x10,
	EN_MHL_RCPK		= 0x11,
	EN_MHL_RCPE		= 0x12,
	EN_MHL_RAP		= 0x20,
	EN_MHL_RAPK		= 0x21,
	EN_MHL_UCP		= 0x30,
	EN_MHL_UCPK		= 0x31,
	EN_MHL_UCPE		= 0x32,
	EN_NONE_CMD		= 0xff,	// not any cmd from mobile.
}EN_MHL_MSC_TOTV_CMD_TYPE;

/**
@brief MHL�豸�β�״̬
**/
typedef enum
{
	EN_MHL_CABLE			=0,
	EN_NOT_MHL_CABLE		=1,
}EN_MHL_PORT_STAT;

/**
@brief MHL�ź�״̬
**/
typedef enum
{
	EN_MHL_SIGNALS		=0,
	EN_NO_SIGNAL			=1,
}EN_MHL_SIGNAL_STAT;

/**
@brief MHL��Ϣ����
**/
typedef struct
{
    EN_MHL_MSC_TOTV_CMD_TYPE 	mhlMscSubCmdType;
    uint8_t 					un8cmd;		//follow MHL2.0 spec. the range is 0~255;
}st_fpi_mhl_msc_cmd;

typedef struct
{
    EN_MHL_PORT_STAT 			un8MhlCable;	// 1: mhl cable connect,  	0: not mhl cable, 	other: not mhl cable
    EN_MHL_SIGNAL_STAT 			un8MhlSignal;	// 1: is mhl signal,		0: not mhl signal, 	other: not mhl signal, 
    st_fpi_mhl_msc_cmd                 tvgetMHLcmd;
}st_fpi_tvget_mhl_dev_info; 

/**
@brief           CEC���ܿ��أ�����T-link״̬

@param[in]	enable	CEC���ܿ��ر�־��enable==1��ʾCEC���ܿ��� enable==0��ʾCEC���ܿ���
@param [in]	act  �ӿ�ִ�е�״̬���ò�����ʱû���õ�

@param[out]    NONE

@retval	    	  FPI_ERROR_SUCCESS    ��ʾ���ò����ɹ�
@retval           FPI_ERROR_FAIL          ��ʾ���ò���ʧ��  

*/
fpi_error tos_cec_set_enable(int32_t enable,EN_ACT_CTRL act);


/**
@brief 			��ȡT-LINK״̬

@param[in]		NONE

@param[out]	   	enable T-LINK״̬

@retval	    	  FPI_ERROR_SUCCESS    ��ʾ���ò����ɹ�
@retval           FPI_ERROR_FAIL          ��ʾ���ò���ʧ��  
*/
fpi_error tos_cec_get_enable(int32_t *enable);


/**
@brief		����ң������CEC�豸���ͼ�ֵ
			�����ϲ���ȡ����ֵ������android��Ҫ������İ���ֵӳ���ΪHTML UI��ֵ��linux��ֱ��ֻ��HTML UIֵ����.
			����HTML UIֵ����˽ӿں���ӳ��ΪHDMI��׼�ĵ������CEC��ֵ���Ӷ�ʵ��ң��������CEC�豸�Ĺ���.

@param[in] 	un16UiKey ����HTML UIֵ

@param[out]  NONE

@retval	    	 FPI_ERROR_SUCCESS    ��ʾ���ò����ɹ�
@retval          FPI_ERROR_FAIL          ��ʾ���ò���ʧ��
*/
fpi_error tos_cec_send_key(uint16_t un16UiKey);



/**
@brief 		��ȡ���ŵ�ARC(�����ش�)����״̬

			ARC������ARC���ܵ����һ�����أ�����ARC������Ҫ��֤������SAC���ܺ�SPDIF����

@param[in]    un8Num    Ŀ���豸���豸�ţ��ֱ�Ϊ1.2.3.4��Ӧ��HDMI1.2.3.4��   �ò�����ʱû������

@param[out]  pbStatus  Ŀ���豸��ARC����״̬���� 1���� 0.



@retval	    	 FPI_ERROR_SUCCESS    ��ʾ���ò����ɹ�
@retval          FPI_ERROR_FAIL          ��ʾ���ò���ʧ��
*/
fpi_error tos_cec_get_arc_status(uint8_t un8Num, int16_t *pbStatus);

/**
@brief 		���ù��ŵ�ARC(�����ش�)����״̬

	    		ARC������ARC���ܵ����һ�����أ�����ARC������Ҫ��֤������SAC���ܺ�SPDIF����

@param[in]    un8Num     Ŀ���豸���豸�ţ��ֱ�Ϊ1.2.3.4��Ӧ��HDMI1.2.3.4  ��  �ò�����ʱû������
@param[in]    pbStatus   Ŀ���豸���趨��ARC����״̬���� 1���� 0.
@param [in]	act  �ӿ�ִ�е�״̬���ò�����ʱû���õ�

@param[out]  NONE

@retval	    	 FPI_ERROR_SUCCESS    ��ʾ���ò����ɹ�
@retval          FPI_ERROR_FAIL          ��ʾ���ò���ʧ��
*/
fpi_error tos_cec_set_arc_status(uint8_t un8Num, int16_t bStatus,EN_ACT_CTRL act);


/**
@brief 		���ϲ���ã����ڻ�ȡ��ǰ����TV��CEC�豸����

		      CEC�豸�����Ǹ�UI���б�������ʾCEC�豸����

@param [in]   NONE

@param[out] pun8TotalNum  �豸����

@retval	    	 FPI_ERROR_SUCCESS    ��ʾ���ò����ɹ�
@retval          FPI_ERROR_FAIL          ��ʾ���ò���ʧ��
*/
fpi_error tos_cec_get_device_total_number(uint8_t *totalNum);


/**
@brief 		���ϲ���ã����豸��Ϣ�ϴ���UI������Ӧ����

@param [in]    NONE

@param[out] 	 pDevInfo���˲���������������:
						- un8DevLogAddr   ��ǰCEC�豸���߼���ַ
						- un8DevPhyAddr   ��ǰCEC�豸�������ַ
						- un8DevNum       ��ǰCEC�豸���豸�ţ�����HDMI1,2,3,4�ֱ�Ϊ1,2,3,4   ��  �ò�����ʱû������
						- un8DevType      CEC�豸���豸����
						- szDevName       CEC�豸������

@retval	    	 FPI_ERROR_SUCCESS    ��ʾ���ò����ɹ�
@retval          FPI_ERROR_FAIL          ��ʾ���ò���ʧ��
*/
fpi_error tos_cec_get_dev_info(st_fpi_cec_dev_base *pDevInfo);


/**
@brief 		  ��ȡĳһCEC�豸����״̬

@param [in] 	  un8Num  ��ʾHDMI�� 1: HDMI1 2: HDMI2 3: HDMI3 4: HDMI4    ���ò�����ʱû������

@param[out]    pIsMute  �Ƿ��� fpi_true ��ʾ����״̬ fpi_false ��ʾ�Ǿ���״̬

@retval	    	 FPI_ERROR_SUCCESS    ��ʾ���ò����ɹ�
@retval          FPI_ERROR_FAIL          ��ʾ���ò���ʧ��
*/
fpi_error tos_cec_get_device_mute_status(uint8_t un8Num, fpi_bool* pIsMute);

/**
@brief 		��ȡĳһCEC�豸������

@param [in]	un8Num  ��ʾHDMI�� 1: HDMI1 2: HDMI2 3: HDMI3 4: HDMI4    ���ò�����ʱû������

@param[out]	value  ��ʾ����ֵ 0 - 100
    
@retval	    	 FPI_ERROR_SUCCESS    ��ʾ���ò����ɹ�
@retval          FPI_ERROR_FAIL          ��ʾ���ò���ʧ��
*/
fpi_error tos_cec_get_device_volume(uint8_t un8Num, uint16_t *value);


/**
@brief		arc��֧��״̬ 

@param [in]	un8Num  ��ʾHDMI�� 1: HDMI1 2: HDMI2 3: HDMI3 4: HDMI4    ��  �ò�����ʱû������

@param[out]  un8Flag ARC֧��״̬

@retval	    	 FPI_ERROR_SUCCESS    ��ʾ���ò����ɹ�
@retval          FPI_ERROR_FAIL          ��ʾ���ò���ʧ��
*/
fpi_error tos_cec_get_arc_support_status(uint8_t un8Num, uint8_t  *un8Flag);




/**
@brief 		�������߻���CEC�豸�� �������DVD�豸��AMP�豸�в�ͬ�Ļ��ѷ�ʽ

@param[in] 	un8Num  Ŀ���豸���豸�ţ��ֱ�Ϊ1.2.3.4��Ӧ��HDMI1.2.3.4
@param[in] 	type       CEC���Ƶ�Դ�Ķ�����power on ��standby
@param[in]    b_OnOff  ���Ƶ�Դ�������أ���ʱû������

@param[out]  NONE

@retval	    	 FPI_ERROR_SUCCESS    ��ʾ���ò����ɹ�
@retval          FPI_ERROR_FAIL          ��ʾ���ò���ʧ��
*/
fpi_error tos_cec_power_device(uint8_t un8Num, EN_CEC_POWER_TYPE type,int16_t b_OnOff);



/**
@brief 		������ر�CEC����TV ��������TV �Զ������Ĺ���

@param[in]    type     CEC���Ƶ�Դ�Ķ�����power on ��standby
@param[in]	enable   fpi_true, �������ܣ�fpi_false���رչ���
@param[in]	act  �ӿ�ִ�е�״̬���ò�����ʱû���õ�

@param[out]  NONE

@retval	    	 FPI_ERROR_SUCCESS    ��ʾ���ò����ɹ�
@retval          FPI_ERROR_FAIL          ��ʾ���ò���ʧ��
*/
fpi_error tos_cec_set_auto_power_mode(EN_CEC_POWER_TYPE type,int16_t enable,EN_ACT_CTRL act);

/**
@brief 		�õ�������ر�CEC����TV ��������TV �Զ������Ĺ���״̬

@param[in]    type     CEC���Ƶ�Դ�Ķ�����power on ��standby		 

@param[out]  p_enable   ��ع��ܿ����ر�״̬

@retval	    	 FPI_ERROR_SUCCESS    ��ʾ���ò����ɹ�
@retval          FPI_ERROR_FAIL          ��ʾ���ò���ʧ��
*/
fpi_error tos_cec_get_auto_power_mode(EN_CEC_POWER_TYPE type,int16_t *p_enable);


/**
@brief 		��mhl�豸���Ͱ���

@param[in]	un16UiKey ����HTML UIֵ

@param[out]	NONE


@retval	    	 FPI_ERROR_SUCCESS    ��ʾ���ò����ɹ�
@retval          FPI_ERROR_FAIL          ��ʾ���ò���ʧ��
*/
fpi_error tos_mhl_send_key(uint16_t un16UiKey);


/**
@brief 		���mhl�豸����Ϣ��ͬʱ��ѯ��һ��send key�����ִ�н��
			

@param[in]	NONE

@param[out]	pDevInfo MHL�豸����Ϣ����һ��send key�����ִ�н��
			Ŀǰ��ʱ�����ѯ�ý������˻�ȡ���Ľ��������
			


@retval	    	 FPI_ERROR_SUCCESS    ��ʾ���ò����ɹ�
@retval          FPI_ERROR_FAIL          ��ʾ���ò���ʧ��
*/

fpi_error tos_mhl_get_mhl_dev_info(st_fpi_tvget_mhl_dev_info *pDevInfo);



#ifdef __cplusplus
}
#endif
/** @} */
#endif

