#include <stdio.h>
#include <sbinder/sbinderServ.h>

#if defined(BINDER_CLIENT)
#include <pthread.h>
#include <unistd.h>
#include "os.h"

#include "tos_function_power.h"

#define fpi_trace printf
#define fpi_err printf



int main(int arg, char** argv) {

	printf("Start test function power module \n");

	printf("sbinder_start is called by proxy_init\n");
	
	//while (1)
	{
		EN_SETTING_POWER_CTRL type = EN_SETTING_POWER_ON;
		EN_POWER_TIMER_MODE mode = EN_POWER_TIMER_OFF;
		EN_POWEROFF_TYPE power_off_type = EN_PRE_POWEROFF;
		int32_t ret = FPI_ERROR_SUCCESS;

		printf("Test power on timer \n");
		printf("EN_POWER_TIMER_OFF \n");
		ret = tos_power_set_mode(type, mode);
		if (ret != FPI_ERROR_SUCCESS)
		{
			printf("tos_power_set_mode failed ____\n");
		}
		ret = tos_power_get_mode(type, &mode);
		if (ret != FPI_ERROR_SUCCESS)
		{
			printf("tos_power_get_mode failed ____\n");
		}
		if (mode != EN_POWER_TIMER_OFF)
		{
			printf("tos_power_get_mode error and mode = %d ____\n", mode);
		}

		printf("EN_POWER_TIMER_EVERYDAY \n");
		mode = EN_POWER_TIMER_EVERYDAY;
		ret = tos_power_set_mode(type, mode);
		if (ret != FPI_ERROR_SUCCESS)
		{
			printf("tos_power_set_mode failed ____\n");
		}
		ret = tos_power_get_mode(type, &mode);
		if (ret != FPI_ERROR_SUCCESS)
		{
			printf("tos_power_get_mode failed ____\n");
		}
		if (mode != EN_POWER_TIMER_EVERYDAY)
		{
			printf("tos_power_get_mode error and mode = %d ____\n", mode);
		}

		printf("EN_POWER_TIMER_ONCE \n");
		mode = EN_POWER_TIMER_ONCE;
		ret = tos_power_set_mode(type, mode);
		if (ret != FPI_ERROR_SUCCESS)
		{
			printf("tos_power_set_mode failed ____\n");
		}
		ret = tos_power_get_mode(type, &mode);
		if (ret != FPI_ERROR_SUCCESS)
		{
			printf("tos_power_get_mode failed ____\n");
		}
		if (mode != EN_POWER_TIMER_ONCE)
		{
			printf("tos_power_get_mode error and mode = %d ____\n", mode);
		}


		type = EN_SETTING_POWER_OFF;
		mode = EN_POWER_TIMER_OFF;
		printf("Test power off timer \n");
		printf("EN_POWER_TIMER_OFF \n");
		ret = tos_power_set_mode(type, mode);
		if (ret != FPI_ERROR_SUCCESS)
		{
			printf("tos_power_set_mode failed ____\n");
		}
		ret = tos_power_get_mode(type, &mode);
		if (ret != FPI_ERROR_SUCCESS)
		{
			printf("tos_power_get_mode failed ____\n");
		}
		if (mode != EN_POWER_TIMER_OFF)
		{
			printf("tos_power_get_mode error and mode = %d ____\n", mode);
		}

		printf("EN_POWER_TIMER_EVERYDAY \n");
		mode = EN_POWER_TIMER_EVERYDAY;
		ret = tos_power_set_mode(type, mode);
		if (ret != FPI_ERROR_SUCCESS)
		{
			printf("tos_power_set_mode failed ____\n");
		}
		ret = tos_power_get_mode(type, &mode);
		if (ret != FPI_ERROR_SUCCESS)
		{
			printf("tos_power_get_mode failed ____\n");
		}
		if (mode != EN_POWER_TIMER_EVERYDAY)
		{
			printf("tos_power_get_mode error and mode = %d ____\n", mode);
		}

		printf("EN_POWER_TIMER_ONCE \n");
		mode = EN_POWER_TIMER_ONCE;
		ret = tos_power_set_mode(type, mode);
		if (ret != FPI_ERROR_SUCCESS)
		{
			printf("tos_power_set_mode failed ____\n");
		}
		ret = tos_power_get_mode(type, &mode);
		if (ret != FPI_ERROR_SUCCESS)
		{
			printf("tos_power_get_mode failed ____\n");
		}
		if (mode != EN_POWER_TIMER_ONCE)
		{
			printf("tos_power_get_mode error and mode = %d ____\n", mode);
		}


		printf("Test tos_cancel_power_off \n");
		ret = tos_cancel_power_off();
		if (ret != FPI_ERROR_SUCCESS)
		{
			printf("tos_cancel_power_off failed \n");
		}


		printf("Test tos_power_off \n");
		printf("ready to terminate MW \n");
		ret = tos_power_off(power_off_type);
		if (ret != FPI_ERROR_SUCCESS)
		{
			printf("tos_power_off failed \n");
		}

		printf("End test function power module \n");
		//usleep(10000*1000);
    }
	


	
    //return sbinder_serv();
    return 0;
}

#else
 #error Must define BINDER_CLIENT
#endif
