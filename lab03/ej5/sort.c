/*
  @file sort.c
  @brief sort functions implementation
*/

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "helpers.h"
#include "sort.h"
#include "player.h"

void swap(player_t *p, unsigned int i, unsigned int j) {
    player_t aux = *(p+i);
    *(p+i) = *(p+j);
    *(p+j) = aux;
}

static unsigned int partition(player_t a[], unsigned int izq, unsigned int der) {
    unsigned int ppiv = izq;
    unsigned int indice_izq = izq + 1;
    unsigned int indice_der = der;
    player_t *p = NULL;
    p = &a[0];   
    while (indice_izq <= indice_der) {
        if (goes_before(*(p+indice_izq), *(p+ppiv))) {
            ++indice_izq;
        } else if (goes_before(*(p+ppiv), *(p+indice_der))) {
            --indice_der;
        } else if (goes_before(*(p+ppiv), *(p+indice_izq)) && goes_before(*(p+indice_der), *(p+ppiv))) {
            swap(p, indice_izq, indice_der);
        }
    }
    swap(p, ppiv, indice_der);
    return indice_der;
}

static void quick_sort_rec(player_t a[], unsigned int izq, unsigned int der) {
    unsigned int ppiv = 0u;
    if(izq < der) {
    
        ppiv = partition(a, izq, der);
        
        if (ppiv > 0) {
            quick_sort_rec(a, izq, ppiv-1);
        }
        quick_sort_rec(a, ppiv+1, der);
    }
}

bool goes_before(player_t x, player_t y){
    bool goes_before = (x->rank <= y->rank);
    return goes_before;
}

bool array_is_sorted(player_t atp[], unsigned int length) {
    unsigned int i = 1u;
    while (i < length && goes_before(atp[i - 1u], atp[i])) {
        i++;
    }
    return (i == length);
}

void sort(player_t a[], unsigned int length) {
    if (length > 0) {
        quick_sort_rec(a, 0, length - 1);
    }
}

