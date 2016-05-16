#ifndef __TOS_MP_PICTURE_H__
#define __TOS_MP_PICTURE_H__

#include "fpi_base_type.h"
#include "fpi_error_code.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum{
    EN_FPI_PICTURE_PLAY_EFFECT_NONE,
    EN_FPI_PICTURE_PLAY_EFFECT_DISSOLVE,
    EN_FPI_PICTURE_PLAY_EFFECT_WIPE_RIGHT,
    EN_FPI_PICTURE_PLAY_EFFECT_WIPE_LEFT,
    EN_FPI_PICTURE_PLAY_EFFECT_WIPE_UP,
    EN_FPI_PICTURE_PLAY_EFFECT_WIPE_DOWN,
    EN_FPI_PICTURE_PLAY_EFFECT_BOX_IN,
    EN_FPI_PICTURE_PLAY_EFFECT_BOX_OUT,
    EN_FPI_PICTURE_PLAY_EFFECT_RANDOM,
    EN_FPI_PICTURE_PLAY_EFFECT_NUM
}FPI_PICTURE_PLAY_EFFECT_E;

/**
@brief ����ͼƬ��ת��ʽö��
*/
typedef enum{
    EN_FPI_PICTURE_ROTATION_ANTICLOCKWISE,   ///<��ʱ��
    EN_FPI_PICTURE_ROTATION_CLOCKWISE,       ///<˳ʱ��    
}FPI_PICTURE_ROTATION_E;

/**
@brief ����ͼƬ�ƶ�����ö��
*/
typedef enum{
    EN_FPI_PICTURE_MOVE_LEFT_TO_RIGHT =1,
    EN_FPI_PICTURE_MOVE_RIGHT_TO_LEFT ,
    EN_FPI_PICTURE_MOVE_UP_TO_DOWN,
    EN_FPI_PICTURE_MOVE_DOWN_TO_UP,
}FPI_PICTURE_MOVE_E;

/**
@brief ����ͼƬ�鱨�ṹ��
*/
typedef struct {
    int size;           ///< ���ṹ���С,���븳ֵ,����ֵ�������sizeof(FPI_MP_URLProtocol_S)
    unsigned int width;   ///< ͼƬ�Ŀ�
    unsigned int height;   ///< ͼƬ�ĸ�
} FPI_MP_PictureInfo_S;

/**
@brief ����ͼƬ����Ч��

@param[in] effect ͼƬ����Ч������

@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_mp_set_picture_play_effect(unsigned int playerId, FPI_PICTURE_PLAY_EFFECT_E effect);

/**
@brief ��ȡͼƬ����Ч��

@param[out] effect ͼƬ����Ч��

@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_mp_get_picture_play_effect(unsigned int playerId, FPI_PICTURE_PLAY_EFFECT_E *effect);


/**
@brief ����ͼƬ��ת��ʽ

@param[in] driction ͼƬ��ת��ʽ����

@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_mp_rotate_picture(unsigned int playerId, FPI_PICTURE_ROTATION_E driction);


/**
@brief �Ŵ���СͼƬ

@param[in] mode ͼƬ����ģʽ����
@param[in] scale ͼƬ���ŷ�Χ

@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_mp_zoom_picture(unsigned int playerId, int32_t scale);



/**
@brief ����ͼƬ�ƶ�����

@param[in] direction ͼƬ�ƶ��������

@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_mp_set_picture_move_direction(unsigned int playerId, FPI_PICTURE_MOVE_E direction, int32_t size);


/**
@brief ��ȡͼƬ�鱨

@param[in] uri ��Ҫ��ȡ�鱨��ͼƬ����·��
@param[out] pictureInfo �������,ͼƬ����Ϣ.

@return �ɹ�����FPI_ERROR_SUCCESS;ʧ�ܷ�������ֵ
*/
fpi_error tos_mp_get_picture_info(unsigned int playerId, const char* uri, FPI_MP_PictureInfo_S *pictureInfo);


#ifdef __cplusplus
}
#endif
/** @} */
#endif
