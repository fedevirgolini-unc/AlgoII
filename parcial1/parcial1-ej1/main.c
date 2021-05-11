#include <stdio.h>
#include <stdbool.h>
#include "pivot.h"

int main(void) {
    
    bool result = false;
    int array[4] = {1, 1, 1, 5};
    
    result = is_pivot(array, 4, 1);
    printf("%d\n", result);
}
