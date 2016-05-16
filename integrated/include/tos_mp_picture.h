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
@brief 定义图片旋转方式枚举
*/
typedef enum{
    EN_FPI_PICTURE_ROTATION_ANTICLOCKWISE,   ///<逆时针
    EN_FPI_PICTURE_ROTATION_CLOCKWISE,       ///<顺时针    
}FPI_PICTURE_ROTATION_E;

/**
@brief 定义图片移动方向枚举
*/
typedef enum{
    EN_FPI_PICTURE_MOVE_LEFT_TO_RIGHT =1,
    EN_FPI_PICTURE_MOVE_RIGHT_TO_LEFT ,
    EN_FPI_PICTURE_MOVE_UP_TO_DOWN,
    EN_FPI_PICTURE_MOVE_DOWN_TO_UP,
}FPI_PICTURE_MOVE_E;

/**
@brief 定义图片情报结构体
*/
typedef struct {
    int size;           ///< 本结构体大小,必须赋值,且其值必须等于sizeof(FPI_MP_URLProtocol_S)
    unsigned int width;   ///< 图片的宽
    unsigned int height;   ///< 图片的高
} FPI_MP_PictureInfo_S;

/**
@brief 设置图片播放效果

@param[in] effect 图片播放效果参数

@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_mp_set_picture_play_effect(unsigned int playerId, FPI_PICTURE_PLAY_EFFECT_E effect);

/**
@brief 获取图片播放效果

@param[out] effect 图片播放效果

@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_mp_get_picture_play_effect(unsigned int playerId, FPI_PICTURE_PLAY_EFFECT_E *effect);


/**
@brief 设置图片旋转方式

@param[in] driction 图片旋转方式参数

@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_mp_rotate_picture(unsigned int playerId, FPI_PICTURE_ROTATION_E driction);


/**
@brief 放大缩小图片

@param[in] mode 图片缩放模式参数
@param[in] scale 图片缩放范围

@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_mp_zoom_picture(unsigned int playerId, int32_t scale);



/**
@brief 设置图片移动方向

@param[in] direction 图片移动方向参数

@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_mp_set_picture_move_direction(unsigned int playerId, FPI_PICTURE_MOVE_E direction, int32_t size);


/**
@brief 获取图片情报

@param[in] uri 需要获取情报的图片保存路径
@param[out] pictureInfo 输出参数,图片的信息.

@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_mp_get_picture_info(unsigned int playerId, const char* uri, FPI_MP_PictureInfo_S *pictureInfo);


#ifdef __cplusplus
}
#endif
/** @} */
#endif
