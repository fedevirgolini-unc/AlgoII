/*
  @file array_helpers.c
  @brief Array Helpers method implementation
*/
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "array_helpers.h"


/**
 * @brief returns true when reach last line in weather file
 * @param[in] year Year array position (start in 0 ends with YEARS - 1)
 * @param[in] month Month of the year (december is last month 11u)
 * @param[in] day Day of the month. We assume all month have 28 days.
 * @return True when is the last line of the file, False otherwise
 */
static bool is_last_line(unsigned int year, unsigned int month, unsigned int day)
{
    return  year == YEARS - 1u && month == december && day == DAYS - 1u;
}


void array_dump(WeatherTable a) {
    for (unsigned int year = 0u; year < YEARS; ++year) {
        for (t_month month = january; month <= december; ++month) {
            for (unsigned int day = 0u; day < DAYS; ++day) {
                fprintf(stdout, "%u %u %u ", year + FST_YEAR, month + 1, day + 1);
                weather_to_file(stdout, a[year][month][day]);
                if (!is_last_line(year, month, day))
                {
                    fprintf(stdout, "\n");
                }
            }
        }
    }
}


void array_from_file(WeatherTable array, const char *filepath) {
    FILE *file = NULL;

    file = fopen(filepath, "r");
    if (file == NULL) {
        fprintf(stderr, "File does not exist.\n");
        exit(EXIT_FAILURE);
    }

    unsigned int k_year = 0u;
    unsigned int k_month = 0u;
    unsigned int k_day = 0u;
    while (!feof(file)) {
        int res = fscanf(file, " %u %u %u ", &k_year, &k_month, &k_day);
        if (res != 3) {
            fprintf(stderr, "Invalid array.\n");
            exit(EXIT_FAILURE);
        }
        
        Weather weather = weather_from_file(file);
        
        if ((unsigned int)(k_year - FST_YEAR) > YEARS) {
            fprintf(stderr, "Invalid year in array.\n");
            exit(EXIT_FAILURE);
        }
        if ((unsigned int)(k_month - 1) > MONTHS) {
            fprintf(stderr, "Invalid month in array.\n");
            exit(EXIT_FAILURE);
        }
        if ((unsigned int)(k_day - 1) > DAYS) {
            fprintf(stderr, "Invalid day in array.\n");
            exit(EXIT_FAILURE);
        }
        
        array[k_year - FST_YEAR][k_month - 1][k_day - 1]._average_temp = weather._average_temp;
        array[k_year - FST_YEAR][k_month - 1][k_day - 1]._max_temp = weather._max_temp;
        array[k_year - FST_YEAR][k_month - 1][k_day - 1]._min_temp = weather._min_temp;
        array[k_year - FST_YEAR][k_month - 1][k_day - 1]._pressure = weather._pressure;
        array[k_year - FST_YEAR][k_month - 1][k_day - 1]._moisture = weather._moisture;
        array[k_year - FST_YEAR][k_month - 1][k_day - 1]._rainfall = weather._rainfall;
            
        
    }
    fclose(file);
}

void print_array(int a[], unsigned int length) {
    for (unsigned int i = 0u; i < length; ++i) {
        fprintf(stdout, "%i", a[i]);
        if (i < length - 1) {
            fprintf(stdout, " ");
        } else {
            fprintf(stdout, "\n");
        }
    }
}

void print_array_month(t_month a[], unsigned int length) {
    for (unsigned int i = 0u; i < length; ++i) {
        fprintf(stdout, "%i", a[i]);
        if (i < length - 1) {
            fprintf(stdout, " ");
        } else {
            fprintf(stdout, "\n");
        }
    }
}
