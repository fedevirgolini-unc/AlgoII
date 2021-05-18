#include <stdio.h>
#include <stdlib.h>
#include "pair.h"

struct s_pair_t {
    elem fst;
    elem snd;
};

pair_t pair_new(elem x, elem y) {
    
    pair_t new_pair;
    
    new_pair = malloc(sizeof(struct s_pair_t));
    
    new_pair->fst = x;
    new_pair->snd = y;
    
    return new_pair;
}

int pair_first(pair_t p) {
    return p->fst;
}

int pair_second(pair_t p) {
    return p->snd;
}

pair_t pair_swapped(pair_t p) {

return pair_new(p->snd, p->fst);

/*
    pair_t swapped;
    
    swapped = malloc(sizeof(struct s_pair_t));
    
    swapped->fst = p->snd;
    swapped->snd = p->fst;
    
    return swapped;
*/
}

pair_t pair_destroy(pair_t p) {
    free(p);
    p = NULL;
    return p;
}
