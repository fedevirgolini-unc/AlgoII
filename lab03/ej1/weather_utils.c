/*
  @file weather_utils.c
  @brief Implements weather_utils methods
*/
#include "array_helpers.h"

int lowest_min_temp(WeatherTable array) {

    int lowest_temp = array[0][0][0]._min_temp;

    for (unsigned int year = 0u; year < YEARS; ++year) {
        for (t_month month = january; month <= december; ++month) {
            for (unsigned int day = 0u; day < DAYS; ++day) {
                if (array[year][month][day]._min_temp < lowest_temp) {
                    lowest_temp = array[year][month][day]._min_temp;
                }
            }
        }
    }

    return lowest_temp;

}


void high_temp_years(WeatherTable a, int output[YEARS]) {
    
    int max_temp_year = 0u;
   
    for (unsigned int year = 0u; year < YEARS; ++year) {
        
        max_temp_year = a[year][0][0]._max_temp;
        
        for (t_month month = january; month <= december; ++month) {
            for (unsigned int day = 0u; day < DAYS; ++day) {
                if (a[year][month][day]._max_temp > max_temp_year) {
                    max_temp_year = a[year][month][day]._max_temp;
                }
            }
        }
        
        output[year] = max_temp_year;
    }
}


void most_rainfall_months(WeatherTable a, t_month output[MONTHS]) {
    
    t_month most_rained_month_of_year = january;
    unsigned int monthly_rainfall[MONTHS] = { 0 };          //this array will contain the total pecipitation of each month in a year
    unsigned int rainfall_of_month = 0u;
    
    for (unsigned int year = 0u; year < YEARS; ++year) {
        
        most_rained_month_of_year = january;
        
        for (t_month month = january; month <= december; ++month) {
            
            rainfall_of_month = 0u;
            
            for (unsigned int day = 0u; day < DAYS; ++day) {
                
                rainfall_of_month += a[year][month][day]._rainfall;
            }
            
            monthly_rainfall[month] = rainfall_of_month;
            
            if (monthly_rainfall[month] > monthly_rainfall[most_rained_month_of_year]) {
                most_rained_month_of_year = month;
            }
        }
        
        output[year] = most_rained_month_of_year;
    
    }
}
