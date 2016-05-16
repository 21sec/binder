/**@defgroup 安全管理模块
@{

@brief 

@author 

@note 

@version 1.0.0 2014/12/30 linshunda 初稿
@version 1.0.1 2016/03/08 fuyong 更新

*/




#ifndef __TOS_SAFETY_H__
#define __TOS_SAFETY_H__
#include "fpi_base_type.h"
#include "fpi_error_code.h"
#include "tos_input_source.h"
//#include "fpi_database_types.h"

#ifdef __cplusplus
extern "C" {
#endif



  /**
  @brief 锁的类型
  **/

  typedef enum{
 	EN_LOCK_TYPE_FRONT_PANEL, ///<前面板
	EN_LOCK_TYPE_INSTALLATION,	///<导航
	EN_LOCK_TYPE_SYSTEM,   
	EN_LOCK_TYPE_CHILDREN,	///儿童锁
}EN_LOCK_TYPE;

/**
 @brief 星期
 **/
typedef enum
{
	EN_FPI_TIME_INTERVAL_LOCK_OFF,
	EN_FPI_TIME_INTERVAL_LOCK_DAILY,
	EN_FPI_TIME_INTERVAL_LOCK_SUNDAY,
	EN_FPI_TIME_INTERVAL_LOCK_MONDAY,
	EN_FPI_TIME_INTERVAL_LOCK_TUESDAY,
	EN_FPI_TIME_INTERVAL_LOCK_WEDNESDAY,
	EN_FPI_TIME_INTERVAL_LOCK_THURDAY,
	EN_FPI_TIME_INTERVAL_LOCK_FRIDAY,
	EN_FPI_TIME_INTERVAL_LOCK_SATURDAY
} EN_FPI_TIME_INTERVAL_LOCK_TYPE;


typedef struct
{
    uint8_t     hour;
    uint8_t     minute;
    uint8_t     second;
    uint8_t     reserved;
} st_tos_clock_time;

typedef struct
{
	EN_FPI_TIME_INTERVAL_LOCK_TYPE type;
	st_tos_clock_time start_time;
	st_tos_clock_time end_time;
} st_tos_time_interval_lock_setting;
/**
@brief 获取密码

@note  原来密码为 int ，这里修改为char ,由调用者传入字符串

@note 

@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_safety_get_password(EN_LOCK_TYPE type, char *pass,int16_t size );
 
  /**
 @brief 设置密码
 
 @note	原来密码为 int ，这里修改为char ,由调用者传入字符串
 
 @note 
 
 @return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
 */
 fpi_error tos_safety_set_password(EN_LOCK_TYPE type, const char *pass );
/**
@brief 检查密码是否正确

@note  原来密码为 int ，这里修改为char ,由调用者传入字符串

@note 

@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
 fpi_error tos_safety_check_password(EN_LOCK_TYPE type, const char *pass,int16_t *value);



 /**
@brief  获取系统设置的parental_rating等级状态

@note  

@note 

@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
 fpi_error tos_safety_get_parental_rating(int32_t *value);
 
 

 /**
@brief  设置parental_rating状态

@note  

@note 

@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
 fpi_error tos_safety_set_parental_rating(int32_t rating,EN_ACT_CTRL act);
 


 
  /**
@brief  设置某一类型的锁

@note  

@note 

@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
 fpi_error tos_safety_set_lock(EN_LOCK_TYPE type, int16_t state,EN_ACT_CTRL act); 
  /**
@brief  获得某一类型的锁

@note  

@note 

@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
 fpi_error tos_safety_get_lock(EN_LOCK_TYPE type, int16_t *state);
   

/**
@brief 设置某一信源的锁

@note  

@note 

@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_safety_set_source_lock( EN_API_SOURCE_INPUT input,int16_t state,EN_ACT_CTRL act);


/**
@brief 获取某一信源的锁

@note  

@note 

@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_safety_get_source_lock(EN_API_SOURCE_INPUT input,int16_t * state);


/**
@brief 设置时间间隔锁
@note  挪威有此要求，设置某一天的某一个时间段锁住电视

@note 

@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_safety_set_time_interval_lock(st_tos_time_interval_lock_setting time_interval_lock,EN_ACT_CTRL act);


/**
@brief 获取时间间隔锁设置
@note  

@note 

@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_safety_get_time_interval_lock(st_tos_time_interval_lock_setting *time_interval_lock);


/**
@brief 清除所有锁的状态
@note  

@note 

@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_safety_clean_all_lock();

 /**
@brief	设置content lock level状态

@note  

@note 

@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
 fpi_error tos_safety_set_content_lock_level(int32_t ContentLevel,EN_ACT_CTRL act);

   /**
 @brief  获取系统设置的content_lock_level等级状态
 
 @note	
 
 @note 
 
 @return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
 */
fpi_error tos_safety_get_content_lock_level(int32_t *value);

#define TOS_SAFETY_OPEN_VCHIP_MAX_RGN_TEXT_LEN			64
#define TOS_SAFETY_OPEN_VCHIP_MAX_DIM_TEXT_LEN			64
#define TOS_SAFETY_OPEN_VCHIP_MAX_LEVEL_TEXT_LEN		64
#define TOS_SAFETY_OPEN_VCHIP_MAX_LVL_ABBR_TEXT_LEN    64
#define TOS_SAFETY_OPEN_VCHIP_MAX_LEVEL_NUM				255

/**
 @brief VCHIP的不同种类锁和设置的分类
 **/
typedef enum
{
	E_TOS_SAFETY_VCHIP_TYPE_US_RATING_VALUE = 0x00,//User setting data of US TV rating
	E_TOS_SAFETY_VCHIP_TYPE_US_MOVIE_LEVEL  =0x01,//US MPAA rating current setting data
	E_TOS_SAFETY_VCHIP_TYPE_CAN_ENG_RATING_VALUE = 0X02,//Cannada english rating current setting data
	E_TOS_SAFETY_VCHIP_TYPE_CAN_FRE_RATING_VALUE = 0X03,//Cannada french rating current setting data
	E_TOS_SAFETY_VCHIP_TYPE_BLOCK_UNRATED = 0x04,//unrated block information of current settings
	E_TOS_SAFETY_VCHIP_TYPE_ENABLE_STATE = 0x05,//rating enabled state
	E_TOS_SAFETY_VCHIP_TYPE_MAX,
}tos_safety_vchip_rating_type_t;
/**
 @brief VCHIP的region信息
 **/
typedef struct
{
	uint8_t dim_num;            							/**< dimension number. */
	uint8_t version;            							/**< region version. */
	uint8_t id;             								/**< region id. */
	uint8_t text[TOS_SAFETY_OPEN_VCHIP_MAX_RGN_TEXT_LEN];   /**< region text. */
}tos_safety_vchip_region_info_t;

/**
 @brief VCHIP的dimension信息
 **/
typedef struct
{
	uint8_t level_num;													/**< level number. */
	fpi_bool grad;														/**< dimension grad. */
	uint8_t text[TOS_SAFETY_OPEN_VCHIP_MAX_DIM_TEXT_LEN];              /**< dimension text. */
}tos_safety_vchip_dimension_info_t;

/**
 @brief VCHIP的级别信息
 **/
typedef struct
{
	uint8_t text[TOS_SAFETY_OPEN_VCHIP_MAX_LEVEL_TEXT_LEN];             	  /**< level text. */
	uint8_t abbration_text[TOS_SAFETY_OPEN_VCHIP_MAX_LVL_ABBR_TEXT_LEN];    /**< level abbration text. */
}tos_safety_vchip_level_info_t;

/**
 @brief VCHIP的block设置
 **/
typedef struct tos_safety_vchip_block_data_st
{
    uint8_t   region_index;                            		/**< region index. */
    uint8_t   dimension_index;                            		/**< dimension index. */
    uint8_t   unrated;                                 			/**< block unrated. */                        
    fpi_bool  level_block[TOS_SAFETY_OPEN_VCHIP_MAX_LEVEL_NUM]; /*level block or not*/
}tos_safety_vchip_block_data_t;

/**
@brief 设置VCHIP的各种rating的值和状态
@param[in] vchip_rating_type 要设置的值范围如下：
	E_TOS_SAFETY_VCHIP_TYPE_US_RATING_VALUE,          
	E_TOS_SAFETY_VCHIP_TYPE_US_MOVIE_LEVEL ,           
	E_TOS_SAFETY_VCHIP_TYPE_CAN_ENG_RATING_VALUE, 
	E_TOS_SAFETY_VCHIP_TYPE_CAN_FRE_RATING_VALUE ,
	E_TOS_SAFETY_VCHIP_TYPE_BLOCK_UNRATED,
	E_TOS_SAFETY_VCHIP_TYPE_ENABLE_STATE,
@param[in] value 要设置的值范围如下：
    E_TOS_SAFETY_VCHIP_TYPE_US_RATING_VALUE要设置的值范围(这个是按比特位进行或的关系)： 
	    bit0 b_TV_AGE_Y_block;
	    bit1 b_TV_AGE_Y7_block;
	    bit2 b_TV_AGE_G_block;
	    bit3 b_TV_AGE_PG_block;
	    bit4 b_TV_AGE_14_block;
	    bit5 b_TV_AGE_MA_block;
	    bit6 b_TV_CNT_Y_block;
	    bit7 b_TV_CNT_Y7_block;
	    bit8 b_TV_CNT_Y7_FV_block;
	    bit9 b_TV_CNT_PG_D_block;
	    bit10 b_TV_CNT_PG_L_block;
	    bit11 b_TV_CNT_PG_S_block;
	    bit12 b_TV_CNT_PG_V_block;
	    bit13 b_TV_CNT_14_D_block;
	    bit14 b_TV_CNT_14_L_block;
	    bit15 b_TV_CNT_14_S_block;
	    bit16 b_TV_CNT_14_V_block;
	    bit17 b_TV_CNT_MA_L_block;
	    bit19 b_TV_CNT_MA_S_block;
	    bit20 b_TV_CNT_MA_V_block; 
  E_TOS_SAFETY_VCHIP_TYPE_US_MOVIE_LEVEL要设置的值范围(0~6)：      
         TV_G,TV_PG,TV_PG13,R,NC-17,X,OFF
  E_TOS_SAFETY_VCHIP_TYPE_CAN_ENG_RATING_VALUE要设置的值范围(0~7)：
         TV_E,TV_C,TV_C8+,TV_G,TV_PG,TV_14+,TV_18+,OFF
  E_TOS_SAFETY_VCHIP_TYPE_CAN_FRE_RATING_VALUE要设置的值范围(0~6)：
	   TV_E,TV_G,TV_8,TV_13,TV_16,TV_18,OFF
  E_TOS_SAFETY_VCHIP_TYPE_BLOCK_UNRATED要设置的值范围：
	    0，1
  E_TOS_SAFETY_VCHIP_TYPE_ENABLE_STATE要设置的值范围：
	    0，1
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_safety_set_vchip_rating(tos_safety_vchip_rating_type_t vchip_rating_type,uint32_t value);
/**
@brief 获取VCHIP的各种rating的值和状态
@param[in] vchip_rating_type 
              	E_TOS_SAFETY_VCHIP_TYPE_US_RATING_VALUE,          
			E_TOS_SAFETY_VCHIP_TYPE_US_MOVIE_LEVEL ,           
			E_TOS_SAFETY_VCHIP_TYPE_CAN_ENG_RATING_VALUE, 
			E_TOS_SAFETY_VCHIP_TYPE_CAN_FRE_RATING_VALUE ,
			E_TOS_SAFETY_VCHIP_TYPE_BLOCK_UNRATED,
			E_TOS_SAFETY_VCHIP_TYPE_ENABLE_STATE,
@param[out] value 
			根据传入的类型返回设置的值
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_safety_get_vchip_rating(tos_safety_vchip_rating_type_t vchip_rating_type,uint32_t* value);
/**
@brief  get the open vchip data is available
@param[in] NONE
@param[out] is_available - Buffer pointer of return value
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_safety_get_vchip_open_available(fpi_bool* is_available);
/**
@brief  get the open vchip region's number
@param[in] NONE
@param[out] ret_region_number - Buffer pointer of return value
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_safety_get_vchip_open_region_num(uint32_t* ret_region_number);
/**
@brief  get the open vchip region's information
@param[in] region_index - select region index
@param[out] ret_region_info - Buffer pointer of return value
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_safety_get_vchip_open_region_info(uint32_t region_index,tos_safety_vchip_region_info_t* ret_region_info);
/**
@brief  get the open vchip dimension's information
@param[in] region_index - select region index
@param[in] dimension_index - select dimension index
@param[out] ret_dim_info - Buffer pointer of return value
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_safety_get_vchip_open_dimension_info(uint32_t region_index,uint32_t dimension_index,tos_safety_vchip_dimension_info_t* ret_dim_info);
/**
@brief  get the open vchip level's information
@param[in] region_index - select region index
@param[in] dimension_index - select dimension index
@param[in] level_index - select level index
@param[out] ret_level_info - Buffer pointer of return value
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_safety_get_vchip_open_level_info(uint32_t region_index,uint32_t dimension_index,uint32_t level_index,tos_safety_vchip_level_info_t* ret_level_info);
/**
@brief  get the open vchip block setting data
@param[in] NONE
@param[out] ret_block_data - Buffer pointer of return value
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_safety_get_vchip_block_data(tos_safety_vchip_block_data_t* ret_block_data);
/**
@brief  set the open vchip block setting data
@param[in] block_data-Buffer pointer of block setting data
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_safety_set_vchip_block_data(tos_safety_vchip_block_data_t* block_data);

#ifdef __cplusplus
}
#endif
/** @} */

#endif //_FUNCTION_SETTING_H_
