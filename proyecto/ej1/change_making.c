#include <assert.h>
#include "change_making.h"
#include "amount.h"
#include "set.h"
#include "currency.h"

static amount_t min(amount_t a1, amount_t a2){
    amount_t min = a1;
    if (amount_lt(a2, a1)){
        min = a2;
    }
    return min;
}

/** Change-Making Algorithm
@param charge    A given price money to pay with coins
@param coins     A set of coin denominations

@return The minimun amount of coins needed for pay the charge
*/
amount_t change_making(currency_t charge, set coins) {
    amount_t numb;
    coin_t c;
    set coin_aux = set_clone(coins);
    if (charge == 0) {
        numb = 0;
    } else if (set_is_empty(coins)) {
        numb = amount_inf();
    } else {
        c = set_get(coins);
        coin_aux = set_elim(coin_aux, c);
        if (c <= charge && c != 0) {
            numb = min(amount_sum(1, change_making(charge-c, coins)), change_making(charge, coin_aux));
        } else {
            numb = change_making(charge, coin_aux);
        }
    }
    set_destroy(coin_aux);
    return numb;
}

