#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <sbinder/sbinderServ.h>
#include "fpp_zoom.h"

#define __funtion__ 	"RECORD_TEST"

void record_test(void)
{
	fpi_error err = FPI_ERROR_FAIL;
	EN_FPP_ZOOM_CAPTURE_TYPE_T capture_type = EN_FPP_ZOOM_CAPTURE_ONLY_VIDEO;
	ST_RECORD_VIDEO_PARAM_T record_video_param;
	uint32_t realsize = 0;
	uint32_t *read_addr = NULL;
	uint32_t read_size = 0;

	printf("[%s]:%d,Start...\n",__funtion__,__LINE__);
	printf("[%s]:%d,fpp_zoom_record_init...\n",__funtion__,__LINE__);
	err = fpp_zoom_record_init(0);
	if(err != FPI_ERROR_SUCCESS)
	{
		printf("--ERROR:fpp_zoom_record_init failed!!!\n");
	}
	

	record_video_param.resolution.un32_width = 1920;
	record_video_param.resolution.un32_height = 1080;
	record_video_param.video_framerate = 24;
	record_video_param.rect.un32_hposition = 0;
	record_video_param.rect.un32_hsize = 1920;
	record_video_param.rect.un32_vposition = 0;
	record_video_param.rect.un32_vsize = 1080;

	printf("[%s]:%d,fpp_zoom_set_record_param...\n",__funtion__,__LINE__);
	err = fpp_zoom_set_record_param(255,capture_type,record_video_param);
	if(err != FPI_ERROR_SUCCESS)
	{
		printf("--ERROR:fpp_zoom_set_record_param failed!!!\n");
	}
	
	printf("[%s]:%d,fpp_zoom_record_control...\n",__funtion__,__LINE__);
	err = fpp_zoom_record_control(EN_CONTROL_TYPE_START);
	if(err != FPI_ERROR_SUCCESS)
	{
		printf("--ERROR:fpp_zoom_record_control start failed!!!\n");
	}

	printf("[%s]:%d,fpp_zoom_get_buffer_real_size...\n",__funtion__,__LINE__);
	err = fpp_zoom_get_buffer_real_size(&realsize);
	printf("[%s]:%d,realsize = %d\n",__funtion__,__LINE__,realsize);
	if(err != FPI_ERROR_SUCCESS)
	{
		printf("--ERROR:fpp_zoom_get_buffer_real_size failed!!!\n");
	}

	read_addr = NULL;
	printf("[%s]:%d,&read_addr = %#x\n",__funtion__,__LINE__,(uint32_t)&read_addr);
	printf("[%s]:%d,read_addr = %#x\n",__funtion__,__LINE__,(uint32_t)read_addr);

	printf("[%s]:%d,fpp_zoom_get_read_buffer_address...\n",__funtion__,__LINE__);
	err = fpp_zoom_get_read_buffer_address(&read_addr,&read_size);
	if(err != FPI_ERROR_SUCCESS)
	{
		printf("--ERROR:fpp_zoom_get_read_buffer_address failed!!!\n");
	}
	
	printf("[%s]:%d,read_addr = %#x , read_size = %d\n",__funtion__,__LINE__,(int)read_addr,read_size);
	printf("[%s]:%d,read_addr = %s\n",__funtion__,__LINE__,(char *)read_addr);
	if(read_addr == NULL)
	{
		printf("--ERROR:read_addr is NULL\n");
	}
	
	printf("[%s]:%d,fpp_zoom_confirm_data...\n",__funtion__,__LINE__);
	err = fpp_zoom_confirm_data((uint32_t)read_addr,read_size);
	if(err != FPI_ERROR_SUCCESS)
	{
		printf("--ERROR:fpp_zoom_confirm_data failed!!!\n");
	}

	printf("[%s]:%d,fpp_zoom_record_control...\n",__funtion__,__LINE__);
	err = fpp_zoom_record_control(EN_CONTROL_TYPE_STOP);
	if(err != FPI_ERROR_SUCCESS)
	{
		printf("--ERROR:fpp_zoom_record_control stop failed!!!\n");
	}
	
	printf("[%s]:%d,End...\n",__funtion__,__LINE__);
	
}
int main(int argc,char *argv[])
{
	fpi_error err = FPI_ERROR_FAIL;
	EN_FPP_ZOOM_CAPTURE_TYPE_T capture_type = EN_FPP_ZOOM_CAPTURE_ONLY_VIDEO;
	ST_RECORD_VIDEO_PARAM_T record_video_param;
	uint32_t realsize = 0;
	uint32_t *read_addr = NULL;
	uint32_t read_size = 0;
			
			
	sbinder_start () ;
	
	printf("\n\n\n\n\n\n\n");
	printf("\033[1;32;40m*******************************************\n\033[0m");
	printf("\033[1;32;40mThis is a sbinder test case\n");
	while(1)
	{
		printf("\n\n\n\n\n\n\n");
		printf("\033[1;32;40m*******************************************\n\033[0m");
		printf("\033[1;32;40m 1.fpp_zoom_record_init()\n\033[0m");
		printf("\033[1;32;40m 2.fpp_zoom_set_record_param()\n\033[0m");
		printf("\033[1;32;40m 3.fpp_zoom_record_control()\n\033[0m");
		printf("\033[1;32;40m 4.fpp_zoom_get_buffer_real_size()\n\033[0m");
		printf("\033[1;32;40m 5.fpp_zoom_get_read_buffer_address()\n\033[0m");
		printf("\033[1;32;40m 6.fpp_zoom_confirm_data()\n\033[0m");
		printf("\033[1;32;40m 7.fpp_zoom_record_control()\n\033[0m");
		printf("\033[1;32;40m 9.record_test()\n\033[0m");
		char key;
		key = getchar();
		if(key == -1)
		{
			return 0;
		}
		switch(key)
		{
		case '1':
			err = fpp_zoom_record_init(1024*8);
			if(err != FPI_ERROR_SUCCESS)
			{
				printf("--ERROR:fpp_zoom_record_init failed!!!\n");
			}
			break;
			
		case '2':
			record_video_param.resolution.un32_width = 1920;
			record_video_param.resolution.un32_height = 1080;
			record_video_param.video_framerate = 24;
			record_video_param.rect.un32_hposition = 0;
			record_video_param.rect.un32_hsize = 1920;
			record_video_param.rect.un32_vposition = 0;
			record_video_param.rect.un32_vsize = 1080;			

			err = fpp_zoom_set_record_param(255,capture_type,record_video_param);
			if(err != FPI_ERROR_SUCCESS)
			{
				printf("--ERROR:fpp_zoom_set_record_param failed!!!\n");
			}
			break;
			
		case '3':
			err = fpp_zoom_record_control(EN_CONTROL_TYPE_START);
			if(err != FPI_ERROR_SUCCESS)
			{
				printf("--ERROR:fpp_zoom_record_control start failed!!!\n");
			}
			break;
			
		case '4':
			err = fpp_zoom_get_buffer_real_size(&realsize);
			printf("realsize = %d\n",realsize);
			if(err != FPI_ERROR_SUCCESS)
			{
				printf("--ERROR:fpp_zoom_get_buffer_real_size failed!!!\n");
			}
			break;
			
		case '5':
			printf("&read_addr = %#x\n",(uint32_t)&read_addr);
			printf("read_addr = %#x\n",(uint32_t)read_addr);

			err = fpp_zoom_get_read_buffer_address(&read_addr,&read_size);
			if(err != FPI_ERROR_SUCCESS)
			{
				printf("--ERROR:fpp_zoom_get_read_buffer_address failed!!!\n");
			}

			printf("&read_addr = %#x\n",(uint32_t)&read_addr);
			printf("read_addr = %#x\n",(uint32_t)read_addr);
			break;
			
		case '6':
			err = fpp_zoom_confirm_data((uint32_t)read_addr,read_size);
			if(err != FPI_ERROR_SUCCESS)
			{
				printf("--ERROR:fpp_zoom_confirm_data failed!!!\n");
			}
			break;
			
		case '7':
			err = fpp_zoom_record_control(EN_CONTROL_TYPE_STOP);
			if(err != FPI_ERROR_SUCCESS)
			{
				printf("--ERROR:fpp_zoom_record_control stop failed!!!\n");
			}
			break;
			
		case '9':
			record_test();
			break;
			
		default:	
			break;
		}
		printf("\033[1;32;40m*******************************************\n\033[0m");
		getchar();
	}
	return 1;
}
