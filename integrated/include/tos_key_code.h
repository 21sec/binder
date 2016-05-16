
#ifndef __TOS_KEYCODE_H__
#define __TOS_KEYCODE_H__

/**
* @brief �������͵Ķ���
*/
typedef enum 
{
    TosKeyDown = 0,                ///<��������Ϊ:keydown
    TosKeyUp                       ///<��������Ϊ:keyup
}TOS_KeyAction;


/**
* @brief SITA��Ҫ�İ�����ֵ����,����Android�ı�׼��ֵ��
*/
#define TOS_KEY_CODE_UP			19         ///<�ϼ�
#define TOS_KEY_CODE_DOWN      	20         ///<�¼�
#define TOS_KEY_CODE_RIGHT		22         ///<�Ҽ�
#define TOS_KEY_CODE_LEFT		21         ///<���
#define TOS_KEY_CODE_OK			23         ///<ȷ�ϼ�
#define TOS_KEY_CODE_BACK		4          ///<���ؼ�
#define TOS_KEY_CODE_PAUSE      85         ///<��ͣ��

#endif
