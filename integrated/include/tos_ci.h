/**@defgroup CI模块

@{
@brief 用于控制电视中CI相关操作

@version 1.0.0
**/

#ifndef __TOS_CI_H__
#define __TOS_CI_H__
#include "fpi_base_type.h"
#include "fpi_error_code.h"

#ifdef __cplusplus
extern "C" {
#endif



/** @brief CI菜单每行所支持的最大字符串长度*/
#define FPI_CI_MMI_ITEM_LEN_MAX 256

/** @brief CI菜单所支持的最大Item 个数*/
#define FPI_CI_MMI_ITEM_NUM_MAX 128

/** @brief CI OP Name 所支持的最大字符串长度*/
#define FPI_CI_OP_NAME_LENGTH  48


/** @brief 菜单类型枚举*/
typedef enum
{
    E_MMI_TYPE_MENU, /**< Menu菜单*/
    E_MMI_TYPE_ENQ   /**< Enq菜单*/
} EN_FPI_MMI_TYPE;

/** @brief CAM卡状态*/
typedef enum
{
    E_CARD_EXTRACTED,   /**<卡已拔出*/
	E_CARD_INSERTED,    /**<卡已插入*/
	E_CARD_ACTIVE,      /**<卡可用*/
} EN_FPI_CI_CARD_STATE;

/** @brief CI Certficate类型*/
typedef enum
{
    E_CI_CERT_TEST = 0x00,/**<测试Key*/
    E_CI_CERT_PRODUCTION = 0x01,/**<量产Key*/
}EN_FPI_CI_CERT_TYPE;

/**
@brief 定义CAM状态回调事件枚举
*/
typedef enum {
    EN_FPI_CI_EVENT_CARD_INSERTED,         ///< 表示CAM卡插入
    EN_FPI_CI_EVENT_CARD_REMOVED,          ///< 表示CAM卡拔出
    EN_FPI_CI_EVENT_MMI_DATA_READY,     ///< 表示Cam有数据要显示
    EN_FPI_CI_EVENT_MMI_CLOSE,          ///< 用户关闭Ci菜单后回调，可用于Ui刷屏操作
    EN_FPI_CI_EVENT_UPGR_INPROGRESS,       ///< 用户CI+卡升级过程，需屏蔽所有用户除开关机按键其他按键操作，
    EN_FPI_CI_EVENT_UPGR_FINISH,           ///< 用户CI+卡升级完成回调，取消按键屏蔽
    EN_FPI_CI_EVENT_OP_UPDATE_CHANNEL,  ///< CI+更新频道，用于Ui显示
    EN_FPI_CI_EVENT_OP_UPDATE_NIT,      ///< CI+更新nit，用于Ui显示
    EN_FPI_CI_EVENT_OP_UPDATE_INFO,     ///< CI+更新op信息
    EN_FPI_CI_EVENT_AMMI_MHEG_OPEN,        ///< CI+ application man-machine interface,需要清屏，需要键值操作，应用传递键值到中间件
    EN_FPI_CI_EVENT_AMMI_MHEG_CLOSE,       ///< CI+需要取消键值操作
    EN_FPI_CI_EVENT_AI_NAME_READY,      ///< 进入AI infolist菜单回调，然后更新显示ai的内容
    EN_FPI_CI_EVENT_PROGRAM_CHANGED,      ///< 通知UI CI已换台，需获取播放节目的INFO，并显示
    EN_FPI_CI_EVENT_NUM
}FPI_CI_CB_EVENT_E;

/** @brief CI字符串显示信息*/
typedef struct
{
    unsigned char buf[FPI_CI_MMI_ITEM_LEN_MAX]; /**<需显示的字符串*/
    uint16_t length;                          /**<需显示的字符串长度*/
}fpi_ci_string_t;

/** @brief CI Menu 菜单显示信息*/
typedef struct
{
    fpi_ci_string_t title;      /**<CI Title*/
    fpi_ci_string_t subtitle;   /**<CI SubTitle*/
    fpi_ci_string_t bottom;     /**<CI Bottom*/
    fpi_ci_string_t item[FPI_CI_MMI_ITEM_NUM_MAX];   /**<CI Item*/
    uint8_t item_count;       /**<CI  item count*/
}fpi_ci_mmi_menu_t;


/** @brief CI Enq 菜单显示信息*/
typedef struct
{
    uint8_t ansLen;           ///< answer的长度
    uint8_t blindAns;         ///< 是否可见
    fpi_ci_string_t title;  ///< title string
}fpi_ci_mmi_enq_t;


/** @brief CI certificate信息*/
typedef struct
{
    uint8_t *filePath;          ///< cert路径及文件名
    EN_FPI_CI_CERT_TYPE cerType;///< production or test
}fpi_ci_cert_info_t;


/** @brief CI msg信息*/
typedef struct
{
    uint32_t msg_type; ///< CI消息枚举值
    uint8_t resend_flag;///< resend flag
}fpi_ci_msg_info_t;


/**
@brief 获取CI卡的状态
@param[out] card_state CI卡的状态指针
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_ci_get_card_state(EN_FPI_CI_CARD_STATE *card_state);

/**
@brief 获取ai数量
ai: application information
应用收到回调信息类型为FPI_CI_CB_EVENT_E.EN_FPI_CI_EVENT_AI_NAME_READY时进行调用
@param[out] count CI 菜单卡名称数量指针
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_ci_ai_get_count(uint16_t *count);

/**
@brief 根据Index,获取ai name
ai: application information
应用收到回调信息类型为FPI_CI_CB_EVENT_E.EN_FPI_CI_EVENT_AI_NAME_READY时进行调用
@param[in] index 将要获取的name的index，[0，count-1]
@param[out] pstr name数据指针
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_ci_ai_get_name(uint8_t index, fpi_ci_string_t* name);

/**
@brief 响应进入CI或CIPLUS 主菜单
回调时回传id
@param[in] id 表示需要操作页面的id，根据回调返回的id传入
@param[in] index 用户已选择的选项序号       
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_ci_mmi_enter(int id, uint8_t index);

/**
@brief 响应菜单键返回上一级菜单
回调时回传id
@param[in] id 表示需要操作页面的id，根据回调返回的id传入
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
@deprecated 后续项目中不再使用该接口
*/
fpi_error tos_ci_mmi_back(int id);

/**
@brief 响应返回键退出CI界面
回调时回传id
@param[in] id 表示需要操作页面的id，根据回调返回的id传入
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_ci_mmi_close(int id);

/**
@brief 获取菜单类型
回调时回传id
@param[in] id 表示需要操作页面的id，根据回调返回的id传入
@param[out] mmi_type EN_FPI_MMI_TYPE 指针: E_MMI_TYPE_NONE,
                               E_MMI_TYPE_MENU, 
                               E_MMI_TYPE_LIST,
                               E_MMI_TYPE_ENQ,
                               E_MMI_TYPE_TEXT
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_ci_mmi_get_type(int id, EN_FPI_MMI_TYPE *mmi_type);

/**
@brief 获取mmi menu内容
回调时回传id
@param[in] id 表示需要操作页面的id，根据回调返回的id传入
@param[out] menu mmi menu内容指针，fpi_ci_mmi_menu_t，包含title subtitle bottom item choiceNumber信息
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_ci_mmi_get_menu(int id, fpi_ci_mmi_menu_t *menu);

/**
@brief 响应OK(确认)键进入下一级菜单
回调时回传id
@param[in] id 表示需要操作页面的id，根据回调返回的id传入
@param[in] index 当前ci菜单的菜单项索引 ,索引从0开始
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_ci_mmi_select_item(int id, uint8_t index);

/**
@brief 获取mmi enq内容
回调时回传id
@param[in] id 表示需要操作页面的id，根据回调返回的id传入
@param[out] enq mmi enq内容指针，fpi_ci_mmi_enq_t，包含blandAns AnsLen AnsText信息
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_ci_mmi_get_enq(int id,fpi_ci_mmi_enq_t *enq);

/**
@brief 检测用户输入的密码
回调时回传id
@param[in] id 表示需要操作页面的id，根据回调返回的id传入
@param[in] pin 密码字符串指针
@param[out] value fpi_ture -- 密码正确，fpi_false 密码错误
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_ci_mmi_answer_enq(int id, char* pin);

/**
@brief 获取CI_MHEG5的状态
判断mheg是否打开，如果打开，应用传递键值给中间件处理
@param[out] mheg5_state fpi_ture -- mehg 打开，fpi_false mehg 关闭
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_ci_ammi_get_mheg5_state(fpi_bool *mheg5_state);

/**
@brief 获取CI op的状态
本身存在频道列表，是否存在op频道列表
@param[out] exist fpi_ture--op存在，fpi_false--op不存在
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_ci_op_is_exist(fpi_bool *exist);

/**
@brief 获取ci op channellist名称
@param[out] profile_name profile name,utf-8
@param[in] len profile name长度
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_ci_op_get_name(fpi_ci_string_t *profile_name);


/**
@brief 更新CI CHANNEL
应用收到回调信息类型为FPI_CI_CB_EVENT_E.EN_FPI_CI_EVENT_UI_OP_UPDATE_CHANNEL时进行调用
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_ci_op_handle_channel_update();

/**
@brief 更新CI nit
根据ci回调消息进行显示，应用收到回调信息类型为FPI_CI_CB_EVENT_E.EN_FPI_CI_EVENT_UI_OP_UPDATE_NIT时进行调用
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_ci_op_handle_nit_update();

/**
@brief 删除CI节目列表
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_ci_op_delete_all_channel();

/**
@brief 更新CIPlus Certificate
工厂菜单烧写CI+的key使用
@param[in] certInfo cert路径及文件名等数据指针
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_ci_cert_update(fpi_ci_cert_info_t *cert_info);

/**
@brief 擦除CIPlus Certificate
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_ci_cert_erase(void);

/**
@brief 获取Certificate中的Custom Code信息
用于菜单显示
@param[out] custom_code Certificate中的Custom Code信息指针
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_ci_cert_get_custom_code(fpi_ci_string_t* custom_code);

/**
@brief 获取Certificate中Device Cert的Serial Num信息
用于菜单显示
@param[out] Device  Certificate中的Serial Num信息指针
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_ci_cert_get_serial_num(fpi_ci_string_t* serial_num);


/**
@brief 触发CI模块重新发送消息，仅供Android系统使用
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_ci_msg_resend(void);

/**
@brief 应用接收到CI消息后，设置对应消息的Resend Flag,仅供Android系统使用
@param[in] ci_msg CI消息
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_ci_msg_set_resend_flag(fpi_ci_msg_info_t ci_msg);

/**
@brief CI模块处理回调
@param[in] eventType 产生的事件类型枚举FPI_CI_CB_EVENT_E
@param[in] data1 产生的事件附带数据,
@param[in] data1 产生的事件附带数据,
@param[in] id Cam卡数据
@param[in] userdata 为用户注册数据，回调时原样返回
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
typedef int32_t (*fpi_dtv_ci_callback)(FPI_CI_CB_EVENT_E event_type, int data1,int data2, int id, void* userdata);

/**
@brief 添加Dtv CI模块处理回调
当CI的状态发生变化时，中间件会调用应用注册的本接口配合完成相应的操作的功能.

@param[in] callbakc 播放回调函数指针
@param[in] userdata 用户数据,注册此回调时的userdata参数.
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/

fpi_error tos_ci_add_callback(fpi_dtv_ci_callback callback, void* userdata);


/**
@brief 删除CI模块回调函数

@param[in] callbakc Dtv CI回调函数指针
@return 成功返回FPI_ERROR_SUCCESS;失败返回其他值
*/
fpi_error tos_ci_remove_callback(fpi_dtv_ci_callback callback);

#ifdef __cplusplus
}
#endif
/** @} */
#endif
