/**@defgroup SUBTITLEģ��

@{
@brief ���ڿ��Ƶ�������Ļ��صĲ���

@version 1.0.0
**/
#ifndef __TOS_SUBTITLE_H__
#define __TOS_SUBTITLE_H__
#include "fpi_base_type.h"
#include "fpi_error_code.h"
#include "tos_function_setting.h"
#ifdef __cplusplus
extern "C" 
{
#endif

#define FPI_SUBTITLE_SERVICES_NUMS   64

typedef enum
{
    E_SUBTITLE_PREFER_LANGUAGE_FIRST,       ///< ��һ����
    E_SUBTITLE_PREFER_LANGUAGE_SECOND,      ///< �ڶ�����
    E_SUBTITLE_PREFER_LANGUAGE_NUM,
} EN_FPI_SUBTITLE_PREFER_LANGUAGE;

typedef enum
{
    E_SUBTITLE_MODE_NORMAL,                ///< ����ģʽ
    E_SUBTITLE_MODE_HEARING_IMPAIRED,      ///< �����ϰ�ģʽ
    E_SUBTITLE_MODE_NUM,
} EN_FPI_SUBTITLE_MODE;

typedef enum
{
    SUBTITLE_VISIBLE_UI = 0x1, //for ui to control subtitle display or not
    SUBTITLE_VISIBLE_APP= 0x2,  //not used
    SUBTITLE_VISIBLE_ALL = 0xffff,
}EN_FPI_SUBTITLE_VISIBLE_LEVEL;


typedef struct st_fpi_menu_subtitle_service
{
    int32_t eLanguage;                     ///< ������������Ӧ����ö��
    EN_FPI_SUBTITLE_MODE  enSubtitleMode;  ///< subtitle��ģʽ�������������ϰ�
   // uint8_t  u8RefCount;                 ///< subtitle������ظ�����δʹ��
    uint8_t  StringCodes[4];               ///< the  ISO 639 �ַ���
} fpi_menu_subtitle_service_t;

typedef struct st_fpi_subtitle_info
{
    fpi_menu_subtitle_service_t menuSubtitle[FPI_SUBTITLE_SERVICES_NUMS]; ///< subtitle�˵���Ϣ
    uint8_t currentSubtitleIndex; ///< ��ǰ��subtitle��Ӧ������255 means has subtitle but not open
    uint8_t subtitleNumber;   ///< ��ǰ��Ŀ֧�ֵ�subtitle����
    fpi_bool bSubtitleOn;  ///< subtitle�Ƿ�򿪻�ر�
} fpi_subtitle_info_t;

/**
@brief ��ȡ��ǰ���ڲ��Ž�Ŀ��subtitle ��Ϣ
@param[out] sttInfo ��ǰ��Ŀ��subtitle ��Ϣָ��
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_subtitle_get_info(fpi_subtitle_info_t *sttInfo);

/**
@brief ���ø���subtitle ��ʾ������������ѡ����ʾ����subtitle���л���subtitle�б�ѡ��ʱʹ��
���ú��Ӧfpi_subtitle_info_t�ṹ��currentSubtitleIndex
@param[in] index ��subtitle������������0xffʱĬ�ϣ��м�����д���
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_subtitle_open(uint8_t index);

/**
@brief ����subtitle�ɼ�����Ӧ��ʹ�ã�����Ui����subtitle�Ŀɼ������أ�
������subtitle�Ĵ򿪺͹رգ������ڿ���Ui����subtitle�Ŀɼ�������
@param[in] flag �Ƿ�����
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_subtitle_set_visibility(EN_FPI_SUBTITLE_VISIBLE_LEVEL level,fpi_bool flag);

/**
@brief ��ȡsubtitle ��ʾ״̬���Ƿ�򿪻�ر�
@param[out] flag ��ȡsubtitle����״ָ̬�룬fpi_true�򿪡�fpi_false�ر�
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_subtitle_get_status(fpi_bool *flag);

/**
@brief ����subtitle ��ʾ״̬
�ýӿڻ���б��������������״̬����
@param[in] flag ���ø���subtitle����״̬��fpi_true�򿪡�fpi_false�ر�
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_subtitle_set_status(fpi_bool flag);

/**
@brief ��ȡsubtitle ģʽ�������������ϰ�
@param[out] mode ��ȡsubtitle ģʽ״ָ̬��
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_subtitle_get_mode(EN_FPI_SUBTITLE_MODE *mode);

/**
@brief ����subtitle ģʽ�������������ϰ�
��subtitle��ʱ����ѡ����Ҫ���б������
@param[in] mode ����subtitle ģʽ
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_subtitle_set_mode(EN_FPI_SUBTITLE_MODE mode);

/**
@brief ��ȡsubtitle��һ�ڶ�����
��subtitle��ʱ����ѡ��
@param[in] type ����subtitle��һ��ڶ���������
@param[out] language ��ȡsubtitle��һ��ڶ����Զ�Ӧ������ö��ָ��
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_subtitle_get_prefer_language(EN_FPI_SUBTITLE_PREFER_LANGUAGE type,MEMBER_LANGUAGE *language);

/**
@brief ����subtitle��һ�ڶ�����
��subtitle��ʱ����ѡ����Ҫ���б������
@param[in] type ����subtitle��һ��ڶ���������
@param[in] language ����subtitle��һ��ڶ����Զ�Ӧ������ö��
@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_subtitle_set_prefer_language(EN_FPI_SUBTITLE_PREFER_LANGUAGE type,MEMBER_LANGUAGE language);

#ifdef __cplusplus
}
#endif
/** @} */
#endif
