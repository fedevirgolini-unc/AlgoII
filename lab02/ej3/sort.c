#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"


static unsigned int partition(int a[], unsigned int izq, unsigned int der) {

    unsigned int ppiv = izq;
    unsigned int indice_izq = izq + 1;
    unsigned int indice_der = der;
    
    while (indice_izq <= indice_der) {
        
        if (goes_before(a[indice_izq], a[ppiv])) {
            ++indice_izq;
        }
        else if (goes_before(a[ppiv], a[indice_der])) {
            --indice_der;
        }
        else if (goes_before(a[ppiv], a[indice_izq]) && goes_before(a[indice_der], a[ppiv])) {
            swap(a, indice_izq, indice_der);
        }
        
    }
    
    swap(a, ppiv, indice_der);
    
    return indice_der;
}

static void quick_sort_rec(int a[], unsigned int izq, unsigned int der) {
    
    unsigned int ppiv = 0u;
    
    if(izq < der) {
        ppiv = partition(a, izq, der);
    if (ppiv > 0) {
            quick_sort_rec(a, izq, ppiv-1);
        }
        quick_sort_rec(a, ppiv+1, der);
    }

}

void quick_sort(int a[], unsigned int length) {
    quick_sort_rec(a, 0, (length == 0) ? 0 : length - 1);
}

