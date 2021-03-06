#include <stdlib.h>
#include <assert.h>
#include "stack.h"

struct _s_stack {
    stack_elem *elems;      // Arreglo de elementos
    unsigned int size;      // Cantidad de elementos en la pila
    unsigned int capacity;  // Capacidad actual del arreglo elems
};

static bool invrep(stack s) {
    bool crit1 = s != NULL;
    bool crit2 = s->elems != NULL;
    bool crit3 = s->size <= s->capacity;
    return crit1 && crit2 && crit3;
}

stack stack_empty() {
    stack new = malloc(sizeof(struct _s_stack));
    stack_elem *array = calloc(2, sizeof(stack_elem));
    new->elems = array;
    new->size = 0u;
    new->capacity = 2u;
    assert(invrep(new));
    return new;
}

stack stack_push(stack s, stack_elem e) {
    assert(invrep(s));
    if (s->size == s->capacity) {
        s->elems = realloc(s->elems, sizeof(s->elems) * 2u);
        s->capacity = s->capacity * 2u;
    }
    (s->elems)[s->size] = e;
    s->size += 1u;
    assert(invrep(s));
    return s;
}

stack stack_pop(stack s) {
    assert(invrep(s));
    assert(!stack_is_empty(s));
    s->size -= 1u;
    assert(invrep(s));
    return s;
}

unsigned int stack_size(stack s) {
    assert(invrep(s));
    return s->size;
}

stack_elem stack_top(stack s) {
    assert(invrep(s));
    assert(!stack_is_empty(s));
    return (s->elems)[s->size - 1u];
}

bool stack_is_empty(stack s) {
    assert(invrep(s));
    return s->size == 0u;
}

stack_elem *stack_to_array(stack s) {
    assert(invrep(s));
    stack_elem *array = calloc(s->size, sizeof(stack_elem));
    if (stack_is_empty(s)) {
        free(array);
        array = NULL;
    } else {
        for (unsigned int i = 0u; i < s->size; ++i) {
            array[i] = (s->elems)[i];
        }
    }
    assert(invrep(s));
    return array;
}

stack stack_destroy(stack s) {
    assert(invrep(s));
    free(s->elems);
    s->elems = NULL;
    free(s);
    s = NULL;
    return s;
}