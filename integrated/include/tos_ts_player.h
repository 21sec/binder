#ifndef __TOS_TS_PLAYER_H__
#define __TOS_TS_PLAYER_H__

#include "fpi_base_type.h"
#include "fpi_error_code.h"
//#include "tvh_ts_player.h"
#ifdef __cplusplus
extern "C" 
{
#endif


typedef enum 
{
	tos_pay_null = 0x00,
    tos_play_fail = 0x01,
    tos_play_prep = 0x02,
    tos_play_start = 0x03,
    tos_play_over = 0x04,
}tos_en_play_event;




typedef fpi_error ( *tos_event_handle_t)(tos_en_play_event ev, void *user_data);

fpi_error tos_ts_play_create_fifo(void);
fpi_error tos_ts_play_env_init(void);
fpi_error tos_ts_play_env_uninit(void);
fpi_error tos_ts_play_init(void);
fpi_error tos_ts_play_uninit(void);
fpi_error tos_ts_play_set_param(uint16_t video_pid, uint16_t audio_pid);
fpi_error tos_ts_play_start(void);
fpi_error tos_ts_play_pause(void);
fpi_error tos_ts_play_resume(void);
fpi_error tos_ts_play_push_data(uint16_t data_len);
fpi_error tos_ts_play_stop(void);
fpi_error tos_ts_play_get_pts(int32_t  *n32_pts);

fpi_error tos_ts_play_add_callback(tos_event_handle_t ev_cb,void *userdata);
fpi_error tos_ts_play_remove_callback(tos_event_handle_t ev_cb);

#ifdef __cplusplus
}
#endif

#endif

