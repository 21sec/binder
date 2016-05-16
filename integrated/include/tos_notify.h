#ifndef __TOS_NOTIFY_H__
#define __TOS_NOTIFY_H__

#ifdef __cplusplus
extern "C" {
#endif

  typedef enum {
  // notify
    CMD_UI_NOTIFY_ATV_TUNE_FREQUENCY_CHANGE         = 1000,//ATV��ǰƵ����Ϣ8000
    CMD_UI_NOTIFY_ATV_SCAND_CHANNEL_NUM             = 1001,//ATVƵ���ѵ���Ŀ,no used 8001
    CMD_UI_NOTIFY_ATV_SCAN_FINISHED                 = 1002,//ATV��̨����8002
    CMD_UI_NOTIFY_SS_INVALID_SERVICE                = 1003,//8003
    CMD_UI_NOTIFY_SS_NO_CI_MODULE                   = 1004,//8004
    CMD_UI_NOTIFY_SS_CI_PLUS_AUTHENTICATION         = 1005,//8005
    CMD_UI_NOTIFY_SS_SCRAMBLED_PROGRAM              = 1006,//8006
    CMD_UI_NOTIFY_SS_CH_BLOCK                       = 1007,//8007
    CMD_UI_NOTIFY_SS_PARENTAL_BLOCK                 = 1008,//8008
    CMD_UI_NOTIFY_SS_AUDIO_ONLY                     = 1009,//8009
    CMD_UI_NOTIFY_SS_DATA_ONLY                      = 1010,//800a
    CMD_UI_NOTIFY_SS_COMMON_VIDEO                   = 1011,//800b
    CMD_UI_NOTIFY_SS_UNSUPPORTED_FORMAT             = 1012,//800c
    CMD_UI_NOTIFY_SS_INVALID_PMT                    = 1013,//800d
    CMD_UI_NOTIFY_CHANNEL_CHANGE_FINISH             = 1014,//800e
    CMD_UI_NOTIFY_SOURCE_CHANGE_FINISH              = 1015,//800f
    
    CMD_UI_NOTIFY_SIGNAL_UNLOCK                     = 1016,//8010
    CMD_UI_NOTIFY_SIGNAL_LOCK                       = 1017,//8011
    /*CI ֪ͨ��� */
    CMD_UI_NOTIFY_CI_CARD_INSERTED                  = 1018,//8012
    CMD_UI_NOTIFY_CI_CARD_REMOVE                    = 1019,//8013
    CMD_UI_NOTIFY_CI_DATA_READY                     = 1020,//8014
    CMD_UI_NOTIFY_CI_EXIT_CI                        = 1021,//8015
    CMD_UI_NOTIFY_CI_UPGR_INPROGRESS                = 1022,//8016
    CMD_UI_NOTIFY_CI_UPGR_NOT_INPROGRESS            = 1023,//8017

    CMD_UI_NOTIFY_DTV_TUNE_FREQUENCY_CHANGE         = 1024,//DTV��ǰƵ����Ϣ8018
    CMD_UI_NOTIFY_DTV_SCAN_FINISHED                 = 1025,//DTV��̨����8019

    CMD_UI_NOTIFY_MEDIA_USB_INSERTED                = 1026,//801a
    CMD_UI_NOTIFY_MEDIA_USB_REMOVE                  = 1027,//801b

/*��·��ص�֪ͨ*/
    CMD_UI_NOTIFY_WIRE_CONNECT_SUCCESS              = 1028,//�����������ӳɹ�801c
    CMD_UI_NOTIFY_WIRE_CONNECT_FAILURE              = 1029,//801d

//-----media begin-----

    CMD_UI_NOTIFY_MEDIA_EOS                         = 1030,//801e
    CMD_UI_NOTIFY_MEDIA_VIDEO_ERROR                 = 1031,//801f
    CMD_UI_NOTIFY_MEDIA_AUDIO_ERROR                 = 1032,//8020
    CMD_UI_NOTIFY_MEDIA_VIDEO_CANT_RECONGNIZE       = 1033,//8021
    CMD_UI_NOTIFY_MEDIA_AUDIO_CANT_RECONGNIZE       = 1034,//8022
    CMD_UI_NOTIFY_MEDIA_PLAY_ERROR_IS_PLAYING       = 1035,//8023
    CMD_UI_NOTIFY_MEDIA_PLAY_ERROR_FILE_NOT_EXIST   = 1036,//8024
    //CMD_UI_NOTIFY_MEDIA_STREAM_BUFFER_NO_DATA       = 1037,//8025
    CMD_UI_NOTIFY_MEDIA_OTHER_ERROR                 = 1038,//8026
    CMD_UI_NOTIFY_MEDIA_PLAYING_NEXT_PIC            = 1039,//8027
    CMD_UI_NOTIFY_MEDIA_PICTURE_PLAY_EXIT           = 1040,//normal  8028
    CMD_UI_NOTIFY_MEDIA_FIND_FILE_END               = 1041,//8029
 

//-----------dlna notify
    CMD_UI_NOTIFY_DLNA_DEVICE_INSERT                = 1042,//802a
    CMD_UI_NOTIFY_DLNA_DEVICE_REMOVE                = 1043,//802b
    CMD_UI_NOTIFY_DLNA_CURRENT_DEVICE_REMOVE        = 1044,//��ǰ����ʹ�õ�Ӳ���豸�Ƴ�802c
  
//-----media end-----

    CMD_UI_NOTIFY_KEY                               = 1045,//802d
    CMD_UI_NOTIFY_DMR_PLAY                          = 1046,//802e
    CMD_UI_NOTIFY_WIRELESS_DEVICE_NO_FOUND          = 1047,//802f
    CMD_UI_NOTIFY_WIRELESS_SCAN_FINISH              = 1048,//8030
    CMD_UI_NOTIFY_WIRELESS_CONNECT_SUCCESS          = 1049,//8031
   
    CMD_UI_NOTIFY_DLNA_DMR_PUSH_MOVIE               = 1050,//8032
    CMD_UI_NOTIFY_DLNA_DMR_PUSH_MUSIC               = 1051,//8033
    CMD_UI_NOTIFY_DLNA_DMR_PUSH_PICTURE             = 1052,//8034
    
    CMD_UI_NOTIFY_WIRELESS_CONNECT_FAILURE          = 1053,//8035
    
    CMD_UI_NOTIFY_VGA_AUTO_ADJUST_END               = 1054,//8036

    CMD_UI_NOTIFY_CIPLUS_PROGRAM_CHANGE             = 1055,//8037
	
    //-----book start-----//
    CMD_UI_NOTIFY_POWER_OFF_TIMER                   = 1056,//8038��ǰһ����֪ͨ�ػ�ʱ�䵽
    CMD_UI_NOTIFY_BOOKING_PLAY_START                = 1057,//8039 ֪ͨ�û��Ļ�̨��,���ڿ���ʱʱ���ѹ��ڵ�����£�����һ��channelNum �Ĳ���
    CMD_UI_NOTIFY_BOOKING_PLAY_END                  = 1058, //֪ͨԤԼ�տ���Ŀ��ʱ����Ѿ��������û�����ѡ���лص�ԭ�����Ž�Ŀ
    CMD_UI_NOTIFY_BOOKING_RECORD_START              = 1059,//֪ͨ����̨¼��ĳ����Ŀ��,���ڿ���ʱ���ѹ�������£�����һ��channelNum�Ĳ���
    CMD_UI_NOTIFY_BOOKING_RECORD_END                = 1060,//֪ͨԤԼ¼�ƽ����ˣ��û�����ֹͣ¼��
    CMD_UI_NOTIFY_BOOKING_AHEAD_PLAY_START          = 1061,//��ǰһ������̨�����������ʹ�ã�����һ��channelNum�Ĳ���
    CMD_UI_NOTIFY_BOOKING_AHEAD_RECORD_START        = 1062,//803e��ǰһ����֪ͨ¼��
    //-----book end-----//

    CMD_UI_NOTIFY_RESET_READY                       = 1063,//803f

    CMD_UI_NOTIFY_TV_EXCHANGE_END                   = 1064,//8040
    //-----pvr start-----//
    CMD_UI_NOTIFY_PVR_DISK_UNPLUG                   = 1065,//8041
    CMD_UI_NOTIFY_PVR_DISK_FULL                     = 1066,
    CMD_UI_NOTIFY_PVR_RECORD_END                    = 1067,
    CMD_UI_NOTIFY_PVR_PLAYBACK_END                  = 1068,//8044
    CMD_UI_NOTIFY_PVR_PLAYBACK_MOTION_CHANGE        = 1069,//8045,���в���Ϊö��PVR_MOTION
    CMD_UI_NOTIFY_PVR_NO_SIGNAL						= 1070,
    CMD_UI_NOTIFY_PVR_TIMESHIFT_AUTO_START						= 1071,
    CMD_UI_NOTIFY_PVR_TIMESHIFT_INIT_ERR						= 1072,
    CMD_UI_NOTIFY_PVR_SPEED_TEST_ERR						= 1073,
    CMD_UI_NOTIFY_PVR_END                           = 1074,//804a

    CMD_UI_NOTIFY_CI_OP_UPDATE_INFO                 = 1075,//804b
    CMD_UI_NOTIFY_CI_OP_UPDATE_CHANNEL              = 1076,//804c
    CMD_UI_NOTIFY_CI_OP_UPDATE_NIT                  = 1077,//804d
    CMD_UI_NOTIFY_CI_END                            = CMD_UI_NOTIFY_CI_OP_UPDATE_NIT + 2,//804f

    CMD_UI_NOTIFY_EXIT_MENU                         = 1080,//8050
    CMD_UI_NOTIFY_PIC_NOT_AVAILABLE                 = 1081,//8051ͼƬ���ɲ���
    CMD_UI_NOTIFY_MEDIA_DATA_READY                  = 1082,//8052��ý����u�̲���ʱ֪ͨҳ������׼����ɣ�����ͨ��������ȡ��

	//------update --------//
    CMD_UI_NOTIFY_UPDATE_ETHERNET_CABLE_NOT_INSERT  = 1083,//8053 ��������δ��
    CMD_UI_NOTIFY_UPDATE_NO_ACCESS_TO_THE_IP        = 1084,//8054 no access to the ip
    CMD_UI_NOTIFY_UPDATE_LOGIN_FAILED_POTAL         = 1085,//8055 login failed potal
    CMD_UI_NOTIFY_UPDATE_NOT_GET_TO_UPDATE_INFORMATION = 1086,//8056
    CMD_UI_NOTIFY_NETWORK_UPDATE_GET_UPDATED_INFORMATION    = 1087,//8057
    CMD_UI_NOTIFY_UPDATE_FILE_NOT_FOUND             = 1088,//8058
    CMD_UI_NOTIFY_UPDATE_HAVE_NO_DOWNLOAD_COMPLETELY= 1089,//8059
    CMD_UI_NOTIFY_UPDATE_DOWNLOAD_PROGRESS          = 1090,//805a
    CMD_UI_NOTIFY_UPDATE_DOWNLOAD_COMPLETE          = 1091,//805b
    CMD_UI_NOTIFY_UPDATE_ABORTED_LAST_TIME         = 1092,//805c
    CMD_UI_NOTIFY_UPDATE_VERIFIED_FAILED            = 1093,//805d
    CMD_UI_NOTITY_UPDATE_CHANNEL_GET_UPDATED_INFORMATION = 1094,//805e
    CMD_UI_NOTITY_UPDATE_DOWNLOAD_FAILED              = 1095,
    CMD_UI_NOTIFY_UPDATE_BGM_TRIGGER   				= 1096,
    CMD_UI_NOTIFY_UPDATE_END                        = 1102,// 1102 8066
    CMD_UI_NOTIFY_TELETEXT_NEWSFLASH                           = 1103,//8067 

    CMD_UI_NOTIFY_READY_TO_CHANGE_SCART				=1104,
    CMD_UI_NOTIFY_READY_TO_CHANGE_CEC				=1105, //�Ƿ��л�cec

    CMD_UI_NOTIFY_MEDIA_PLAYER_STATUS_PLAYING             =1106,
    CMD_UI_NOTIFY_MEDIA_PLAYER_STATUS_PAUSE               =1107,
    CMD_UI_NOTIFY_MEDIA_PLAYER_STATUS_STOP                =1108,
    CMD_UI_NOTIFY_MEDIA_PLAYER_STATUS_FORWORD             =1109,
    CMD_UI_NOTIFY_MEDIA_PLAYER_STATUS_QUIT_FORWORD        =1110,
    CMD_UI_NOTIFY_MEDIA_PLAYER_STATUS_BACKWORD            =1111,
    CMD_UI_NOTIFY_MEDIA_PLAYER_STATUS_QUIT_BACKWORD       =1112,
    CMD_UI_NOTIFY_MEDIA_PLAYER_STATUS_AB_MODE             =1113,
    //CMD_UI_NOTIFY_MEDIA_PLAYER_STATUS_QUIT_AB_MODE        =1114,
    CMD_UI_NOTIFY_MEDIA_PLAYER_STATUS_SLOWDOWN            =1115,
    CMD_UI_NOTIFY_MEDIA_PLAYER_STATUS_QUIT_SLOWDOWN       =1116,
    CMD_UI_NOTIFY_MEDIA_STREAM_BUFFERING                  =1117,
    CMD_UI_NOTIFY_MEDIA_STREAM_BUFFERING_COMPLETE         =1118,
    CMD_UI_NOTIFY_MEDIA_STREAM_VIDEO_ONLY                 =1119,
    
    CMD_UI_NOTIFY_DTV_SERVICE_PLAY                        = 1120,
    CMD_UI_NOTIFY_MEDIA_VIDEO_AUDIO_LOOP_EXIT             = 1121,//�˳�audio video ����ѭ����play normalʱ�õ�add bylwf 2013.08.29
    CMD_UI_NOTIFY_CHANNEL_PLAY_END                        =1122,//��̨������Ϣ֪ͨ��add by lwf 2013.09.05
    CMD_UI_NOTIFY_SCART_CHANGE_INPUT_SRC                  = 1123, 		// shane.xie 20130910 add

    CMD_UI_NOTIFY_DTV_EPG_PF_FINISH                       =1124,  //add by lwf 2013.09.13 //��ǰ֮����Ϣ���£�epg����		  
    CMD_UI_NOTIFY_DTV_EPG_SCH_FINISH                      =1125,  //add by lwf 2013.09.13
    CMD_UI_NOTIFY_CI_MHEG_OPEN                            = 1126,
    CMD_UI_NOTIFY_CI_MHEG_CLOSE                           = 1127,

   // CMD_UI_NOTIFY_MEDIA_HW_VIDEO_NO_SUPPORT               =1128 ,     //add by lwf 2013.09.16      
   // CMD_UI_NOTIFY_MEDIA_HW_AUDIO_NO_SUPPORT               =1129,      //add by lwf 2013.09.16 


    CMD_UI_NOTIFY_DTV_NIT_VERSION_CHANGED                 =1130, //add by lwf 2013.09.23
    CMD_UI_NOTIFY_SIGNAL_FORMAT_CHANGED                   = 1131, 		// shane.xie 20130927 add

    CMD_UI_NOTIFY_MEDIA_EXIT_FOR_CEC_HDMI_PLAY            =1132,  //add by lwf 2013.10.12
    CMD_UI_NOTIFY_CI_CAM_NAME_READY                       = 1133,  //add by lilijun 2013.10.16


    CMD_UI_NOTIFY_DTV_SS_INPUT_BLOCK                       =1134, //add by lwf lwf 2013.10.17
    CMD_UI_NOTIFY_FACTORY_PS_MODE_ON                       =1135, //add by hzz 2013.10.25
    CMD_UI_NOTIFY_FACTORY_PS_MODE_OFF                      =1136, //add by hzz 2013.10.25


    CMD_UI_NOTIFY_MEDIA_CUSTOM_VIDEO_NO_SUPPORT           =1137,//add by lwf 2013.11.08
    CMD_UI_NOTIFY_MEDIA_CUSTOM_AUDIO_NO_SUPPORT           =1138,//add by lwf 2013.11.08


    CMD_UI_NOTIFY_MEDIA_USB_REMOVE_OTHER                  =1139, //add by lwf 2013.11.12
               
    CMD_UI_NOTIFY_NETWORK_CONNECT_TEST_SUCCESS            =1140, //add by hzz 2013.11.19

    CMD_UI_NOTIFY_NETWORK_CONNECT_TEST_FAIL               =1141, //add by hzz 2013.11.19
    
    CMD_UI_NOTIFY_MEDIA_MEDIA_DIVX_NOT_AUTH               =1142,

    CMD_UI_NOTIFY_MEDIA_MEDIA_DIVX_RENTAL                 =1143,

    CMD_UI_NOTIFY_MEDIA_MEDIA_RENTAL_EXPIRED              =1144,
    CMD_UI_NOTIFY_SET_VIDEO_SIZE                          =1145, //add by zhangyuting 2013.11.20
    CMD_UI_NOTIFY_DTV_TOT_UPDATE                          =1146,

    CMD_UI_NOTIFY_DTV_SS_RUNNING_STATUS_NOT_RUNNING       =1147, //add by lwf 2013.11.28

    CMD_UI_NOTIFY_API_LIB_TRACE                           =1148,//add by lwf 2013.12.03

    CMD_UI_NOTIFY_MEDIA_LYRIC_PARSER_READY                =1149, //-M by liuxiaofeng 2013.11.29
    CMD_UI_NOTIFY_MEDIA_LYRIC_SYNC_UPDATE				  =1150, //-M by liuxiaofeng 2013.11.29
    CMD_UI_NOTIFY_CEC_COMMON                              =1151,//weibin 20131223



    //channel changed
    CMD_UI_NOTIFY_CHANNEL_UPDATE                         =1152,//channel list update
    CMD_UI_NOTIFY_CHANNEL_EDITED                         =1153,//channel is edit
    CMD_UI_NOTIFY_CHANNEL_CLEANED                        =1154,//channel list is cleaned


    CMD_UI_NOTIFY_TELETEXT_UPDATE_NEWSFLASH             = 1155,//add by lwf  2014.03.10
    CMD_UI_NOTIFY_TELETEXT_UPDATE_ALARMPAGE             = 1156,//add by lwf 2014.03.10
    
    CMD_UI_NOTIFY_SRC_CHANGE_SET_INPUT_SOURCE           = 1157,//add by wang.q 2014.03.13

    CMD_UI_NOTIFY_IS_CURRENT_3D_MODE                    = 1158,//add by chqy 2014.03.20
    CMD_UI_NORTIFY_CEC_HDMI_DEVICE_INSERTED             = 1159,//add by chqy 2014.03.20
    CMD_UI_NOTIFY_OSD_STATUS_ON                         = 1160,//add by hzz 2014.03.22
    CMD_UI_NOTIFY_OSD_STATUS_OFF                        = 1161,//add by hzz 2014.03.22
    CMD_UI_NOTIFY_MUTE_ON                               = 1162,//add by hzz 2014.03.26
    CMD_UI_NOTIFY_MUTE_OFF                              = 1163,//add by hzz 2014.03.26

    /********Matengfei add , 20140326**************************/
    CMD_UI_NOTIFY_FACTORY_OSD_SHOW                      = 1164,      
    CMD_UI_NOTIFY_FACTORY_OSD_HIDE                      =1165,          
    CMD_UI_NOTIFY_FACTORY_INFORMATION_SHOW              =1166,    
    CMD_UI_NOTIFY_FACTORY_INFORMATION_HIDE              =1167,        
    /***************************************/
	CMD_UI_NOTIFY_FACTORY_WARMUP_ON					  = 1168,//80a8 add by matengfei 20140328
	CMD_UI_NOTIFY_FACTORY_WARMUP_OFF					  = 1169,//80a9 add by matengfei 20140328
	/*|<--Matengfei add,20140404--*/
	CMD_UI_NOTIFY_FAC_IR_USB_TO_NVM					= 1170,
	CMD_UI_NOTIFY_FAC_IR_PORTAL_CHECK 				= 1171,
	CMD_UI_NOTIFY_FAC_IR_PCLINK_CHECK 				= 1172,
	CMD_UI_NOTIFY_FAC_IR_COLOR_TEMP_SHOW			= 1173,
	CMD_UI_NOTIFY_FAC_IR_VOLUME_SHOW				= 1174,
	CMD_UI_NOTIFY_FAC_IR_SOURCE_CHANGE				= 1175,
	/*--Matengfei add,20140404-->|*/
    /*|<--Matengfei add,20140411--*/	
    CMD_UI_NOTIFY_FAC_IR_SHOP_RESET					= 1176,
    CMD_UI_NOTIFY_FAC_IR_NVM_RESET					= 1177,
    /*--Matengfei add,20140411-->|*/
    CMD_UI_NOTIFY_UPDATE_USB_GET_UPDATE_INFO            = 1178,//80b2
    CMD_UI_NOTIFY_UPDATE_UPDATING_PROGRESS              = 1179,//80b3
    CMD_UI_NOTIFY_UPDATE_RESULT                     = 1180,//80b4

	CMD_UI_NOTIFY_MEDIA_DIVX_ENCRYPTED            = 1181,// add by zyt 2014.05.05
    CMD_UI_NOTIFY_DOWNLOADING_NETWORK_ABNORMAL          = 1182,//80b6
    CMD_UI_NOTIFY_MEDIA_PICTURE_PLAY                    = 1183,// add by zyt 2014.05.15
    CMD_UI_NOTIFY_LIGHT_SENSOR_START                    =1184,
    CMD_UI_NOTIFY_LIGHT_SENSOR_STOP                     =1185,
    CMD_UI_NOTIFY_SHOW_UPDATE_DIALOG                   = 1186,
    CMD_UI_NOTIFY_MEDIA_BACKWARD_EOS                = 1187,
    CMD_UI_NOTIFY_MEDIA_PLAYER_STATUS_RESUME_PLAYING = 1188,
    CMD_UI_NOTIFY_MEDIA_PLAYER_STATUS_SEEK_PLAYING   = 1189,
    CMD_UI_NOTIFY_MEDIA__STREAM_VIN                  = 1190,
    CMD_UI_NOTIFY_MEDIA__STREAM_VOUT                 = 1191,
    CMD_UI_NOTIFY_MEDIA_FIRST_PREVIOUS			     = 1192,
    CMD_UI_NOTIFY_MEDIA_PLAY_ERROR_CANT_OPEN         = 1193,
    CMD_UI_NOTIFY_MEDIA_PLAY_OPEN         = 1194,

    CMD_UI_NORTIFY_MHL_CABLE_INSERTED                    = 1195,//add by Jeffrey.duan 2014-06-15
    CMD_UI_NOTIFY_IS_CURRENT_MHL_SIGNAL_INPUT       = 1196,//add by Jeffrey.duan 2014-06-15

    //-----pvr extern start-----//
    CMD_UI_NOTIFY_PVR_PLAYBACK_ERR                   = 1201,
    CMD_UI_NOTIFY_PVR_PLAYBACK_LOOP_EXIT                   = 1202,
    CMD_UI_NOTIFY_PVR_RECORD_ERR                   = 1203,
    CMD_UI_NOTIFY_PVR_PLAYBACK_START                   = 1204,
    CMD_UI_NOTIFY_PVR_SIGNAL_RESUME				= 1205,
    CMD_UI_NOTIFY_PVR_EXTERN_END                           = 1220,//reserved
    //-----pvr extern end-----//
  	CMD_UI_NOTIFY_PANEL_TEST_ON				 		 =1221,
	CMD_UI_NOTIFY_PANEL_TEST_OFF						   =1222,
    CMD_UI_NOTIFY_FACTORY_P_MODE_CTRL                      =1223,
    CMD_UI_NOTIFY_WFD_STATUS                   		= 1224, //add for miracast by zhouyony
    CMD_UI_NOTIFY_BLUETOOTH_GLASS_MATCH_SUCESSFUL      =1225,  //add by wusongjiang for bt_3d match
    CMD_UI_NOTIFY_BLUETOOTH_GLASS_MATCH_FAIL           =1226,

    //hbbtv 
    CMD_UI_NOTIFY_HBBTV_STATE_CHANGE               = 1227,
    // DMR
    CMD_UI_NOTIFY_DMR_STOP                          = 1228,//add by ZHAOB 2014/7/21
    //hbbtv end

    CMD_UI_NOTIFY_HP_PLUGIN                         = 1229,
    CMD_UI_NOTIFY_HP_PLUGOUT                        = 1230,
    CMD_UI_NOTIFY_FAC_SOUND_TEST			  = 1231,
	
	CMD_UI_NOTIFY_TELETEXT_OFF                      = 1232,
	// network 
    CMD_UI_NOTIFY_WIRE_CONNECTING                  = 1233,
	CMD_UI_NOTIFY_FACTORY_WIFI_ON				 = 1234,
	CMD_UI_NOTIFY_FACTORY_WIFI_OFF 			   = 1235,
	CMD_UI_NOTIFY_FACTORY_ENTER_MEDIA 			   = 1236,
	CMD_UI_NOTIFY_DLNA_DMR_CONNECT                = 1237,
	CMD_UI_NOTIFY_DLNA_DMR_DISCONNECT          = 1238,
    CMD_UI_NOTIFY_MEDIA_FIND_FILE_START        = 1239,
    CMD_UI_NOTIFY_MEDIA_THUMBNAIL              = 1240,
    CMD_UI_NOTIFY_FAC_SHOP_INIT					= 1241,
    CMD_UI_NOTIFY_MEDIA_CUSTOM_VIDEO_AUDIO_NO_SUPPORT     = 1242,//add by shena 2014/09/05    
    CMD_UI_NOTIFY_TELETEXT_NEWSFLASH_OFF = 1243,
    CMD_UI_NOTIFY_MEDIA_CUSTOM_BOOKMARK = 1244,
    CMD_UI_NOTIFY_FAC_IR_ON = 1245,
	CMD_UI_NOTIFY_FAC_IR_OFF = 1246,
	CMD_UI_NOTIFY_DTV_EPG_UPDATE_ALL_PAGE = 1247, //add by maity 2014/10/23

    //�����ĸ���Ϣ��ͼƬ�������ͼ�ƶ���ͼƬ��Եʱ��nova���׵���Ϣ.add by shena 2014/10/24
    CMD_UI_NOTIFY_PIC_UP_EDGE = 1248,//�ƶ���ͼƬ�ϱ�Ե
    CMD_UI_NOTIFY_PIC_DOWN_EDGE = 1249,//�ƶ���ͼƬ�±�Ե
    CMD_UI_NOTIFY_PIC_LEFT_EDGE = 1250,//�ƶ���ͼƬ���Ե
    CMD_UI_NOTIFY_PIC_RIGHT_EDGE = 1251,//�ƶ���ͼƬ�ұ�Ե
    
	/**
	��Ƶ������Ϣ������Ϣ.

	�յ�����Ϣ��Ӧ�ÿ�/Ӧ�õ���api_get_audio_language_info�ӿڻ�ȡ/������Ƶ������Ϣ
	*/
    CMD_UI_NOTIFY_AUDIO_LANGUAGE_INFO_UPDATED = 1252,

    CMD_UI_NOTIFY_CEC_ARC_AUDIO_STATUS_CHANGE = 1253, //UI display arc audio status,add by lilijun
    CMD_UI_NOTIFY_MEDIA_LAST_NEXT = 1254,//��ǰ�ļ������һ���ļ������ڲ��ſ���

	/**
	��ǰ�ź��е�xvYCC�źŷ����仯

	��ʹ��api_get_signal_info�ӿڻ�ȡ�����xvYCC�źŵ�״̬��
	*/
	CMD_UI_NOTIFY_COLOR_XVYCC_INFO_CHANGED = 1255,
  	CMD_UI_NOTIFY_MEDIA_PPT_PLAY = 1256, //ͼƬppt������Ϣ
  	
    CMD_UI_NOTIFY_INPUT_SOURCE_PLUGOUT = 1257, //
  
  	CMD_UI_NOTIFY_DATABASE_FILE_DAMAGE = 1270,//wangzliang add for database damage 2014/12/22
  	CMD_UI_NOTIFY_UPDATE_CHANNEL_GET_FUTURE_UPDATED_INFO = 1271,
  	CMD_UI_NOTIFY_SET_PICTURE_MODE = 1272,
  	CMD_UI_NOTIFY_SESSION = 1273,
  	CMD_AM_NOTIFY_LINUX_RESUME_FINISHED = 1274, //data1Ϊ0��ʾpower����;1��ʾnetflix key ����
  	CMD_AM_NOTIFY_LINUX_STR_SILENCE_ON=1275,  //������Ĭ������ʼ�����BGM��PVR��ʱ��¼�ȣ�
	CMD_AM_NOTIFY_LINUX_STR_SILENCE_OFF=1276, //������Ĭ�������������BGM��PVR��ʱ��¼�ȣ�
	CMD_UI_NOTIFY_HBBTV_CLOSE_PORTAL = 1277,
	CMD_AM_NOTIFY_LINUX_SUSPENDED_START = 1278, //����
	CMD_UI_NOTIFY_SIGNAL_HDR_CHANGED = 1279,
	CMD_UI_NOTIFY_VIDEO_MUTE = 1280,
	CMD_UI_NOTIFY_FACTORY_CMD = 1281,
	CMD_UI_NOTIFY_SIGNAL_INFO_CHANGED = 1282,
	CMD_UI_NOTIFY_EAS_NOTIFY = 1283,
	CMD_UI_NOTIFY_FACTORY_OSD_LANGUAGE = 1284,
	CMD_UI_NOTIFY_ERROR_CODE = 9999,
    CMD_UI_NOTIFY_NUM,   //��Ϣ�ĸ��������������Ϣ������ڴ�ö��֮ǰ  
  }EN_API_NOTIFY;

//------add by lwf 2013.08.21 end-------
#ifdef __cplusplus
}
#endif

#endif //__API_NOTIFY_H__
