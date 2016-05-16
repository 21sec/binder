#include <stdio.h>
#include <sbinder/sbinderServ.h>

#if defined(BINDER_CLIENT)
#include <pthread.h>
#include <unistd.h>
#include "os.h"
//#include "fpi_debug_helper.h"
#include "tos_booking.h"

SET_MODEL_ID(SITA_MODULE_BOOKING);

#define fpi_trace printf
#define fpi_err printf


int main(int arg, char** argv) {

	if (arg <2){
		printf("must set param one: ./xxxx  x\n");
		return 0;
	}
	
    sbinder_start( );
	{
		int32_t ret = FPI_ERROR_SUCCESS;
		tos_schedule_info_t booking_info = {0};
		EN_TOS_BOOKING_ERROR_e state = 0;
		uint8_t count = 0;
		tos_schedule_info_t *info = NULL;
		int32_t schedule_id = 0;

		fpi_trace("Start test booking module \n");
		fpi_trace("modify currnt time to 2015/7/4 12:00:00 \n");
		fpi_trace("test tos_booking_add_item \n");
		//tuner type
		booking_info.tuner_mode = EN_TUNER_MODE_DTMB;
		//event name
		strcpy(booking_info.program_title, "test_event");
		//start time
		booking_info.start_time.weekday = 0;//for weekly mode
		booking_info.start_time.year = 2015;
		booking_info.start_time.month = 7;
		booking_info.start_time.day = 4;
		booking_info.start_time.hour = 12;
		booking_info.start_time.minute = 20;
		booking_info.start_time.second = 50;
		//duration
		booking_info.duration = 3600;
		//repeat mode
		booking_info.repeat_mode = EN_REPEAT_MODE_ONCE;
		//schedule mode
		booking_info.schedule_mode = EN_SCHEDULE_MODE_RECORD;
		//channel index
		booking_info.channel_index = 0;
		ret = tos_booking_add_item(&booking_info, &state);
		if (BOOKING_NO_ERROR != state || ret != FPI_ERROR_SUCCESS)
		{
			fpi_err("tos_booking_add_item failed ____ and state = %d \n", state);
		}

		fpi_trace("test tos_booking_get_count \n");
		ret = tos_booking_get_count(&count);
		if (ret != FPI_ERROR_SUCCESS)
		{
			fpi_err("tos_booking_get_count failed ____ \n");
			goto END_BOOKING_TEST;
		}

		if (count > 0)
		{
			fpi_trace("booking item count %d \n", count);
			info = malloc(count*sizeof(tos_schedule_info_t));
			if (NULL != info)
			{
				fpi_trace("test tos_booking_get_item_list \n");
				ret = tos_booking_get_item_list(count, info);
				if (ret != FPI_ERROR_SUCCESS)
				{
					fpi_err("tos_booking_get_item_list failed ____ \n");
				}

				free(info);
			}
		}
		else
		{
			fpi_trace("booking item count equal zero\n");
			goto END_BOOKING_TEST;
		}

		fpi_trace("test tos_booking_get_item_by_index \n");
		memset(&booking_info, 0, sizeof(booking_info));
		ret = tos_booking_get_item_by_index(0, &booking_info);
		if (ret != FPI_ERROR_SUCCESS)
		{
			fpi_err("tos_booking_get_item_by_index failed ____ \n");
		}
		else
		{
			fpi_trace("booking item info:\n");
			fpi_trace("start time %d-%d-%d %d:%d:%d \n", booking_info.start_time.year, 
				booking_info.start_time.month, booking_info.start_time.day,
				booking_info.start_time.hour, booking_info.start_time.minute, booking_info.start_time.second);
			fpi_trace("duration %d seconds \n", booking_info.duration);
		}

		fpi_trace("test tos_booking_get_item_by_schedule_id \n");
		schedule_id = booking_info.schedule_id;
		memset(&booking_info, 0, sizeof(booking_info));
		ret = tos_booking_get_item_by_schedule_id(schedule_id, &booking_info);
		if (ret != FPI_ERROR_SUCCESS)
		{
			fpi_err("tos_booking_get_item_by_index failed ____ \n");
		}

		fpi_trace("test tos_booking_set_item \n");
		//modify start time
		booking_info.start_time.year = 2015;
		booking_info.start_time.month = 7;
		booking_info.start_time.day = 5;
		booking_info.start_time.hour = 13;
		booking_info.start_time.minute = 30;
		booking_info.start_time.second = 20;
		ret = tos_booking_set_item(&booking_info, &state);
		if (BOOKING_NO_ERROR != state || ret != FPI_ERROR_SUCCESS)
		{
			fpi_err("tos_booking_set_item failed ____ and state = %d \n", state);
		}


		fpi_trace("test tos_booking_event_detect \n");
		tos_schedule_detect_para dstEvent = {0};
		tos_schedule_detect_result detectResult = {0};
		dstEvent.channel_num = booking_info.channel_num;
		dstEvent.service_type = booking_info.service_type;
		dstEvent.duration = 1800;
		dstEvent.start_time.year = 2015;
		dstEvent.start_time.month = 7;
		dstEvent.start_time.day = 5;
		dstEvent.start_time.hour = 13;
		dstEvent.start_time.minute = 50;
		dstEvent.start_time.second = 20;
		ret = tos_booking_event_detect(&dstEvent, &detectResult);
		if (ret != FPI_ERROR_SUCCESS)
		{
			fpi_err("tos_booking_event_detect failed ____ \n");
		}
		else
		{
			fpi_trace("detect result:%d \n", detectResult.is_booked);
		}


		fpi_trace("test tos_booking_delete_item \n");
		ret = tos_booking_delete_item(schedule_id);
		if (ret != FPI_ERROR_SUCCESS)
		{
			fpi_err("tos_booking_delete_item failed ____ \n");
		}


		fpi_trace("test tos_booking_start \n");
		ret = tos_booking_start(fpi_true);
		if (ret != FPI_ERROR_SUCCESS)
		{
			fpi_err("tos_booking_start failed ____ and start flag %d \n", fpi_true);
		}

		ret = tos_booking_start(fpi_false);
		if (ret != FPI_ERROR_SUCCESS)
		{
			fpi_err("tos_booking_start failed ____ and start flag %d \n", fpi_false);
		}


		fpi_trace("test tos_booking_get_ahead_second \n");
		uint32_t ahead_second = 0;
		ret = tos_booking_get_ahead_second(&ahead_second);
		if (ret != FPI_ERROR_SUCCESS)
		{
			fpi_err("tos_booking_get_ahead_second failed ____ \n");
		}
		

		END_BOOKING_TEST:
		fpi_trace("End test booking module \n");
    }
	
    //return sbinder_serv();
    return 0;
}

#else
 #error Must define BINDER_CLIENT
#endif
