#ifndef __TOS_HOTEL_H__
#define __TOS_HOTEL_H__

#include "fpi_base_type.h"
#include "fpi_error_code.h"

#ifdef __cplusplus
extern "C" 
{
#endif

typedef enum
{
    TYPE_LOCK_TUNER,     //��סTuner type
    TYPE_LOCK_MENU,      //��ס�˵�
    TYPE_LOCK_USB,       //��סUSB����
    TYPE_LOCK_SOURCE,    //��ס��Դ
    TYPE_LOCK_PANEL_KEY, //��ס��尴��
    TYPE_LOCK_CHANNEL    //��סƵ��
}EN_TOS_LOCK_TYPE;

typedef enum
{
    FUNC_TYPE_AUTO_SET,     //Auto set����
    FUNC_TYPE_FAV_LIST,     //ϲ����Ŀ�б���
    FUNC_TYPE_POWER_ON_LOGO //����logo���ܿ���
}EN_TOS_FUNCTION_TYPE;

typedef enum
{
    TYPE_POWER_ON_VOLUME,     //�Ƶ�ģʽ�µĿ�������
    TYPE_MAX_VOLUME           //�Ƶ�ģʽ�µ��������
}EN_TOS_VOLUME_TYPE;

typedef enum
{
	EN_TOS_HOTEL_SND_MODE_MUSIC,
	EN_TOS_HOTEL_SND_MODE_MOVIE,
	EN_TOS_HOTEL_SND_MODE_NEWS,
	EN_TOS_HOTEL_SND_MODE_STANDARD,
	EN_TOS_HOTEL_SND_MODE_USER,         
	EN_TOS_HOTEL_SND_MODE_SUBWOFOFER,         
  EN_TOS_HOTEL_SND_MODE_STADIUM,    
  EN_TOS_HOTEL_SND_MODE_NUM
}EN_TOS_HOTEL_SOUND_MODE;

typedef enum
{
    E_TOS_HOTEL_POWER_ON_MODE_ON,
    E_TOS_HOTEL_POWER_ON_MODE_STB,
    E_TOS_HOTEL_POWER_ON_MODE_LAST
}EN_TOS_HOTEL_POWER_ON_MODE;



/**
@brief ͼ��ģʽ
**/
typedef enum
{
	E_TOS_HOTEL_MODE_STANDARD= 0, // Dynamic
	E_TOS_HOTEL_MODE_BRIGHT,
	E_TOS_HOTEL_MODE_SOFT,     //Movie
	E_TOS_HOTEL_MODE_STUDIO,
    E_TOS_HOTEL_MODE_USER,    //Personal  
           E_TOS_HOTEL_MODE_EX1,     
	E_TOS_HOTEL_MODE_NUM
}EN_TOS_HOTEL_PICTURE_MODE;

/** 
@brief ��ȡ�Ƶ�ģʽ�򿪹رյ�״̬
@param[out] *b_enable : fpi_trueΪ����fpi_falseΪ��
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ*/
fpi_error tos_hotel_get_hotel_mode(fpi_bool *b_enable);

/** 
@brief �򿪻��߹رվƵ�ģʽ
@param[in] b_enable:fpi_trueΪ����fpi_falseΪ��
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ*/
fpi_error tos_hotel_set_hotel_mode(fpi_bool b_enable);

/** 
@brief ��ȡ�Ƶ�ģʽ�µĿ��������Լ��������
@param[in] ui2_volume
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ*/
fpi_error tos_hotel_get_volume(EN_TOS_VOLUME_TYPE e_type, uint16_t *ui2_volume);

/** 
@brief ���þƵ�ģʽ�µĿ��������Լ��������
@param[in] ui2_volume
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ*/
fpi_error tos_hotel_set_volume(EN_TOS_VOLUME_TYPE e_type, uint16_t ui2_volume);

/** 
@brief ��ȡ�Ƶ�ģʽ�µĿ�����Դ
@param[out] e_source
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ*/
fpi_error tos_hotel_get_source(EN_API_SOURCE_INPUT *pe_source);

/** 
@brief ���þƵ�ģʽ�µĿ�����Դ
@param[out] e_source
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ*/
fpi_error tos_hotel_set_source(EN_API_SOURCE_INPUT e_source);

/** 
@brief ��ȡ�Ƶ�ģʽ�µ�����ģʽ
@param[out] pe_snd_mode
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ*/
fpi_error tos_hotel_get_sound_mode(EN_TOS_HOTEL_SOUND_MODE *pe_snd_mode);

/** 
@brief ���þƵ�ģʽ�µ�����ģʽ
@param[in] e_snd_mode
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ*/
fpi_error tos_hotel_set_sound_mode(EN_TOS_HOTEL_SOUND_MODE e_snd_mode);

/** 
@brief ��ȡ�Ƶ�ģʽ�µ�ͼЧģʽ
@param[out] pe_pic_mode
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ*/
fpi_error tos_hotel_get_picture_mode(EN_TOS_HOTEL_PICTURE_MODE *pe_pic_mode);

/** 
@brief ���þƵ�ģʽ�µ������Լ��������
@param[in] e_pic_mode
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ*/
fpi_error tos_hotel_set_picture_mode(EN_TOS_HOTEL_PICTURE_MODE e_pic_mode);

/** 
@brief �Ƶ�ģʽ�»�ȡ�Ƶ�ģʽ/Auto set����/ϲ����Ŀ�б�/����logo���ܵĿ���״̬
@param[out] b_enable :fpi_trueΪ��;fpi_falseΪ�ر�
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ*/
fpi_error tos_hotel_get_function_enable(EN_TOS_FUNCTION_TYPE e_fun_type, fpi_bool *b_enable);

/** 
@brief �Ƶ�ģʽ�����þƵ�ģʽ/Auto set����/ϲ����Ŀ�б�/����Logo���ܵĿ���״̬
@param[in] b_enable :fpi_trueΪ��;fpi_falseΪ�ر�
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ*/
fpi_error tos_hotel_set_function_enable(EN_TOS_FUNCTION_TYPE e_fun_type, fpi_bool b_enable);

/** 
@brief ��ȡ�Ƶ�ģʽ�µĿ���Ƶ�������tos_hotel_get_source()ʹ�ã�������ATV/DTV��
@param[out] i4_channel 
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ*/
fpi_error tos_hotel_get_power_on_channel(int32_t *i4_channel);

/** 
@brief ���þƵ�ģʽ�µĿ���Ƶ�������tos_hotel_get_source()ʹ�ã�������ATV/DTV��
@param[in] i4_channel 
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ*/
fpi_error tos_hotel_set_power_on_channel(int32_t i4_channel);

/** 
@brief ��ȡ�Ƶ�ģʽ�µ��ϵ�ģʽ
@param[out] *e_power_mode  POWERON_MODE_ON    �ϵ翪��      
                         POWERON_MODE_STB   �ϵ����
                         POWERON_MODE_LAST  �ϵ�����ϴιػ���״̬
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ*/
fpi_error tos_hotel_get_power_on_mode(EN_TOS_HOTEL_POWER_ON_MODE *e_power_mode);

/** 
@brief ���þƵ�ģʽ�µ��ϵ�ģʽ
@param[in] e_power_mode  POWERON_MODE_ON    �ϵ翪��      
                         POWERON_MODE_STB   �ϵ����
                         POWERON_MODE_LAST  �ϵ�����ϴιػ���״̬
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ*/
fpi_error tos_hotel_set_power_on_mode(EN_TOS_HOTEL_POWER_ON_MODE e_power_mode);


/** 
@brief ��ȡ�Ƶ�ģʽ��ĳЩ�����Ƿ�������״̬
@param[in] e_type :
                typedef enum
                {
                    TYPE_LOCK_TUNER,
                    TYPE_LOCK_MENU,
                    TYPE_LOCK_USB,
                    TYPE_LOCK_SOURCE,
                    TYPE_LOCK_PANEL_KEY,
                    TYPE_LOCK_CHANNEL
                }EN_TOS_LOCK_TYPE;
@param[out] b_state 
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ*/
fpi_error tos_hotel_get_lock_state(EN_TOS_LOCK_TYPE e_type, fpi_bool *b_state);

/** 
@brief �Ƶ�ģʽ������ĳЩ���ܣ������û�����
@param[in] e_type :
                typedef enum
                {
                    TYPE_LOCK_TUNER,
                    TYPE_LOCK_MENU,
                    TYPE_LOCK_USB,
                    TYPE_LOCK_SOURCE,
                    TYPE_LOCK_PANEL_KEY,
                    TYPE_LOCK_CHANNEL
                }EN_TOS_LOCK_TYPE;
@param[in] b_state 
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ*/
fpi_error tos_hotel_set_lock_state(EN_TOS_LOCK_TYPE e_type, fpi_bool b_state);

#ifdef __cplusplus
}
#endif


#endif


