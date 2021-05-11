#include <stdbool.h>

#include "odd.h"

static bool is_odd(int num){
    bool is_odd = false;
    if (num%2 == 1) {
        is_odd = true;
    }
    return is_odd;
}

bool is_odd_sorted(int array[], unsigned int length) {
    
    bool odd_sorted = true;

    for (unsigned int i=3; i<length; ++i) {
        
        if (is_odd(i)) {
            if (array[i-2] > array[i]) {
                odd_sorted = false;
            }
        }
    }
    
    return odd_sorted;
}

