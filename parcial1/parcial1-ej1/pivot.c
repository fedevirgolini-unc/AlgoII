#include <stdbool.h>

#include "pivot.h"

bool is_pivot(int array[], unsigned int length, unsigned int piv) {
    
    bool is_pivot = true;
    
    for (unsigned int j=0; j<piv; ++j){
        if (array[j] > array[piv]){
            is_pivot = false;
        }
    }
    
    for (unsigned int k=(piv+1); k<length; ++k){
        if (array[k] <= array[piv]){
            is_pivot = false;
        }
    }
    
    return is_pivot;
}
