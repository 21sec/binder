
#ifndef __TOS_KEYCODE_H__
#define __TOS_KEYCODE_H__

/**
* @brief 按键类型的定义
*/
typedef enum 
{
    TosKeyDown = 0,                ///<按键类型为:keydown
    TosKeyUp                       ///<按键类型为:keyup
}TOS_KeyAction;


/**
* @brief SITA需要的按键键值定义,按照Android的标准键值来
*/
#define TOS_KEY_CODE_UP			19         ///<上键
#define TOS_KEY_CODE_DOWN      	20         ///<下键
#define TOS_KEY_CODE_RIGHT		22         ///<右键
#define TOS_KEY_CODE_LEFT		21         ///<左键
#define TOS_KEY_CODE_OK			23         ///<确认键
#define TOS_KEY_CODE_BACK		4          ///<返回键
#define TOS_KEY_CODE_PAUSE      85         ///<暂停键

#endif
