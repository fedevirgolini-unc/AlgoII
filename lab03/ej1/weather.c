/*
  @file weather.c
  @brief Implements weather mesuarement structure and methods
*/
#include <stdlib.h>
#include "weather.h"

static const int AMOUNT_OF_WEATHER_VARS = 6 ;

Weather weather_from_file(FILE* file)
{
    Weather weather;
    
    int average_temp;
    int max_temp;
    int min_temp;
    unsigned int pressure;
    unsigned int moisture;
    unsigned int rainfall;
    
    int res = fscanf(file, " %d %d %d %u %u %u ",
                     &average_temp, &max_temp, &min_temp, &pressure, &moisture, &rainfall);
    
    if (res != AMOUNT_OF_WEATHER_VARS) {
        fprintf(stderr, "Invalid array.\n");
        exit(EXIT_FAILURE);
    }
    
    weather._average_temp = average_temp;
    weather._max_temp = max_temp;
    weather._min_temp = min_temp;
    weather._pressure = pressure;
    weather._moisture = moisture;
    weather._rainfall = rainfall;
    
    return weather;
}

void weather_to_file(FILE* file, Weather weather)
{
    fprintf(file, EXPECTED_WEATHER_FILE_FORMAT, weather._average_temp, 
            weather._max_temp, weather._min_temp, weather._pressure, weather._moisture, weather._rainfall);
}
