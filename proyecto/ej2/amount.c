#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "amount.h"

amount_t amount_inf() {
    return INT_MAX;
}

bool amount_is_inf(amount_t a) {
    return a == INT_MAX;
}

bool amount_le(amount_t a1, amount_t a2) {
    return a1 <= a2;
}

bool amount_lt(amount_t a1, amount_t a2) {
    return a1 < a2;
}

amount_t amount_sum(amount_t a1, amount_t a2) {
    amount_t sum = INT_MAX;
    if (a1 < INT_MAX - a2) {
        sum = a1 + a2;
    }
    return sum;
}

void amount_dump(amount_t a)
{
    if (amount_is_inf(a)) {
        printf("#");
    } else {
        printf("%d", a);
    }
}
