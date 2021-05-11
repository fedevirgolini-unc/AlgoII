#include <stdio.h>
#include <stdbool.h>
#include "odd.h"

int main(void) {
    
    bool result = false;
    int array[6] = {5, 1, 8, 2, 3,-1};
    
    result = is_odd_sorted(array, 6);
    printf("%d\n", result);
}
