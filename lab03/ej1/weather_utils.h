/*
  @file weather_utils.h
  @brief Defines weather_util methods
*/

#ifndef _WEATHER_UTILS_
#define _WEATHER_UTILS_

/**
 * @brief obtains the lowest historic temperature
 * @details
 * Obteins the lowest minimum temperature ever registered in Córdoba city according to array data
 *
 * @param[in] WeatherTable array wich contains the data
 * @return The lowest minimum temperature ever registered
 */
 int lowest_min_temp(WeatherTable array);
 
 /**
 * @brief fill the given array with the highest temperature by year
 * @details
 * For each year of the multidimencional array gets the highest
 * temperature registered and stored it in an other array
 *
 * @param WeatherTable array wich contains the data
 * @param int[] array wich will contain the highest temperatures
 */
 void high_temp_years(WeatherTable a, int output[YEARS]);
 
 /**
 * @brief fill the given array with the most rainfall month by year
 * @details
 * For each year of the multidimencional array gets the most
 * rainfall month and stored it in an other array
 *
 * @param WeatherTable array wich contains the data
 * @param int[] array wich will contain the most rainfall months
 */
 void most_rainfall_months(WeatherTable a, t_month output[MONTHS]);
 
 
 #endif //_WEATHER_UTILS_
