#include <stdlib.h>
#include <stdio.h>
#include "currency.h"
#include "amount.h"

static amount_t **create_table(unsigned int y, currency_t x) {
    amount_t ** table;
    table = calloc(y, sizeof(amount_t*)); 
    for (unsigned int i=0; i<y; ++i) {
        table[i] = calloc(x, sizeof(amount_t));
    }
    return table;
}

static void destroy_table(amount_t **table, unsigned int y) {
    for (unsigned int i=0; i<y; ++i) {
        free(table[i]);
    }
    free(table);
}

static amount_t min(amount_t a1, amount_t a2){
    amount_t min = a1;
    if (amount_lt(a2, a1)){
        min = a2;
    }
    return min;
}

/** Change-Making Dynamic
@param charge    A given price money to pay with coins
@param coins     An array of coin denominations

@return The minimun amount of coins needed for pay the charge
*/
amount_t change_making_dyn(currency_t charge, coin_t *coins, unsigned int n_coins) {
    amount_t numb = 0;
    amount_t **table = create_table(n_coins+1, charge+1);
    for (unsigned int i =0; i < n_coins+1; ++i) {
        table[i][0] = 0;
    }
    for (unsigned int i = 1; i<charge+1; ++i) {
        table[0][i] = amount_inf();
    }
    for (unsigned int i=1; i<n_coins+1; ++i) {
        for (unsigned int j=1; j<charge+1; ++j) {
            if (coins[i-1] > j || coins[i-1] == 0) {
                table[i][j] = table[i-1][j];
            } else {
                table[i][j] = min(table[i-1][j], amount_sum(1, table[i][j-coins[i-1]]));
            }   
        }
    }
    numb = table[n_coins][charge];
    destroy_table(table, n_coins+1);
    return numb;
}

