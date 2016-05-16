#include <stdio.h>
#include <sbinder/sbinderServ.h>

#if defined(BINDER_CLIENT)
#include <pthread.h>
#include <unistd.h>
#include "os.h"
#include "fpi_debug_helper.h"
#include "tos_satellite.h"

SET_MODEL_ID(SITA_MODULE_PLAY);

int main(int arg, char** argv) {

	if (arg <2){
		printf("must set param one: ./xxxx  x\n");
		return 0;
	}
	
    sbinder_start( );
	{
		fpi_error ret = FPI_ERROR_SUCCESS;
		int32_t count = 0;
		fpi_trace("Start test booking module \n");
		fpi_trace("test tos_satellite_get_operator_count \n");
		ret = tos_satellite_get_operator_count(&count);
		if (count > 0 && ret == FPI_ERROR_SUCCESS)
		{
			tos_operator_info_t *operator_list = NULL;

			operator_list = malloc(count*sizeof(tos_operator_info_t));
			if (NULL != operator_list)
			{
				fpi_trace("test tos_satellite_get_operator_list \n");
				ret = tos_satellite_get_operator_list(count, operator_list);
				if (ret != FPI_ERROR_SUCCESS)
				{
					fpi_err("tos_satellite_get_operator_list failed ____ \n");
					goto END_SATELLITE_TEST;
				}
				
				int32_t operator_id = 0;
				tos_operator_info_t info = {0};

				memcpy(&info, operator_list, sizeof(tos_operator_info_t));
				free(operator_list);
				operator_id = info.operator_id;

				int32_t satellite_count = 0;
				fpi_trace("test tos_satellite_get_satellite_count_by_operator \n");
				ret = tos_satellite_get_satellite_count_by_operator(operator_id, &satellite_count);
				if (satellite_count > 0 && ret == FPI_ERROR_SUCCESS)
				{
					tos_satellite_info_t *satellite_list = NULL;

					satellite_list = malloc(satellite_count*sizeof(tos_satellite_info_t));
					if (NULL != satellite_list)
					{
						fpi_trace("test tos_satellite_get_satellite_count_by_operator \n");
						ret = tos_satellite_get_satellite_list_by_operator(operator_id, satellite_count, satellite_list);
						if (ret != FPI_ERROR_SUCCESS)
						{
							fpi_err("tos_satellite_get_satellite_list_by_operator failed ____ \n");
							goto END_SATELLITE_TEST;
						}

						tos_satellite_info_t satellite_info = {0};
						int32_t satellite_id = 0;

						memcpy(&satellite_info, satellite_list, sizeof(tos_satellite_info_t));
						free(satellite_list);
						satellite_id = satellite_info.satellite_id;

						//print satellite info 
						fpi_trace("print some info of satellite \n");
						fpi_trace("satellite name %s lnb freq type %d main freq %dMHZ \n", satellite_info.satellite_name, 
							satellite_info.lnb_freq, satellite_info.scan_frequency);

						//lock freq
						fpi_trace("test tos_satellite_lock_freqency \n");
						ret = tos_satellite_lock_freqency(satellite_id);
						if (ret != FPI_ERROR_SUCCESS)
						{
							fpi_err("tos_satellite_lock_freqency failed ____ \n");
						}
					}

					fpi_satellite_antenna_info_t antenna_info = {0};
					fpi_trace("test tos_satellite_get_antenna_info \n");
					ret = tos_satellite_get_antenna_info(&antenna_info);
					if (ret != FPI_ERROR_SUCCESS)
					{
						fpi_err("tos_satellite_get_antenna_info failed ____ \n");
					}
					antenna_info.cur_band_index = 1;
					fpi_trace("test tos_satellite_set_antenna_info \n");
					ret = tos_satellite_set_antenna_info(antenna_info);
					if (ret != FPI_ERROR_SUCCESS)
					{
						fpi_err("tos_satellite_set_antenna_info failed ____ \n");
					}

					int32_t band_freq_count = 0;
					fpi_trace("test tos_satellite_get_band_freq_count \n");
					ret = tos_satellite_get_band_freq_count(&band_freq_count);
					if (band_freq_count > 0 && ret == FPI_ERROR_SUCCESS)
					{
						uint32_t *freq_list = NULL;
						uint32_t band_freq = 0;

						freq_list = malloc(band_freq_count*sizeof(uint32_t));
						if (NULL != freq_list)
						{
							fpi_trace("test tos_satellite_get_band_freq_list \n");
							ret = tos_satellite_get_band_freq_list(band_freq_count, freq_list);
							if (ret != FPI_ERROR_SUCCESS)
							{
								fpi_err("tos_satellite_get_band_freq_list failed ____ \n");
							}
							band_freq = *freq_list;
							fpi_trace("band freq =%d khz \n", band_freq);
							free(freq_list);
						}

						fpi_trace("test tos_satellite_set_band_freq \n");
						ret = tos_satellite_set_band_freq(0, 1500);
						if (ret != FPI_ERROR_SUCCESS)
						{
							fpi_err("tos_satellite_set_band_freq failed ____ \n");
						}
					}
					else
					{
						fpi_err("tos_satellite_get_band_freq_count failed ____ \n");
					}
				}
				else
				{
					fpi_err("tos_satellite_get_satellite_count_by_operator failed ____ \n");
					goto END_SATELLITE_TEST;
				}

				int32_t searched_satellite_count = 0;
				fpi_trace("test tos_satellite_get_searched_satellite_count \n");
				ret = tos_satellite_get_searched_satellite_count(&searched_satellite_count);
				if (searched_satellite_count > 0 && ret != FPI_ERROR_SUCCESS)
				{
					tos_satellite_id_info_t *satellite_id_list = NULL;

					satellite_id_list = malloc(searched_satellite_count*sizeof(tos_satellite_id_info_t));
					if (NULL != satellite_id_list)
					{
						tos_satellite_id_info_t satellite_id_info = {0};
						fpi_trace("test tos_satellite_get_satellite_id_info_list \n");
						ret = tos_satellite_get_satellite_id_info_list(searched_satellite_count, satellite_id_list);
						if (ret != FPI_ERROR_SUCCESS)
						{
							fpi_err("tos_satellite_get_satellite_id_info_list failed ____ \n");
						} 
						memcpy(&satellite_id_info, satellite_id_list, sizeof(tos_satellite_id_info_t));
						free(satellite_id_list);

						uint32_t satellite_id = 0;
						ret = tos_satellite_set_user_select_satellite_id(satellite_id_info.satellite_id);
						if (ret != FPI_ERROR_SUCCESS)
						{
							fpi_err("tos_satellite_set_user_select_satellite_id failed ____ \n");
						} 
						ret = tos_satellite_get_user_select_satellite_id(&satellite_id);
						if (ret != FPI_ERROR_SUCCESS)
						{
							fpi_err("tos_satellite_get_user_select_satellite_id failed ____ \n");
						} 
					}
				}
				else
				{
					fpi_err("tos_satellite_get_searched_satellite_count failed ____ \n");
				}
			}
		}
		else
		{
			fpi_err("tos_satellite_get_operator_count failed ____ \n");
		}

		END_SATELLITE_TEST:
		fpi_trace("End test satellite module \n");
    }
	
    //return sbinder_serv();
    return 0;
}

#else
 #error Must define BINDER_CLIENT
#endif
