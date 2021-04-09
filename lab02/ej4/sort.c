#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"

static unsigned int min_pos_from(int a[], unsigned int i, unsigned int length) {
    unsigned int min_pos = i;
    for (unsigned int j = i + 1; j < length; ++j) {
        if (!goes_before(a[min_pos],a[j])) {
            min_pos = j;
        }
    }
    return (min_pos);
}

void selection_sort(int a[], unsigned int length) {
    for (unsigned int i = 0u; i < length; ++i) {
        unsigned int min_pos = min_pos_from(a, i, length);
        swap(a, i, min_pos);
    }
}


static void insert(int a[], unsigned int i) {
    
    unsigned int j = i;
    
    while (j>0 && goes_before(a[j], a[j-1])){
        swap(a, j-1, j);
        --j;
    }
}

void insertion_sort(int a[], unsigned int length) {
    for (unsigned int i = 1u; i < length; ++i) {
        insert(a, i);
    }
}


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
        quick_sort_rec(a, izq, ppiv);
        quick_sort_rec(a, ppiv+1, der);
    }
}

void quick_sort(int a[], unsigned int length) {
    quick_sort_rec(a, 0u, (length == 0u) ? 0u : length - 1u);
}
