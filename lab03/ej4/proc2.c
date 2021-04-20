#include <stdio.h>

void absolute(int x, int *y) {
    if (x >= 0) {
        *y = x;
    } else {
        *y = -x;
    }
}

int main(void) {
    int a, res;
    int *p = NULL;
    
    res = 0;
    a = -98;
    p = &res;
    
    absolute(a, p);
    
    printf("%d\n", res);
    
    return 0;
    return 0;
}

