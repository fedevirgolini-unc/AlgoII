#include <stdlib.h>
#include <assert.h>
#include "stack.h"
 

 struct _s_stack {
     stack_elem elem;
     struct _s_stack *next;
 };

stack stack_empty() {
    stack new = NULL;
    return new;
}

stack stack_push(stack s, stack_elem e) {
    stack new_elem = malloc(sizeof(struct _s_stack));
    new_elem->elem = e;
    new_elem->next = s;
    s = new_elem;
    return s;
}

stack stack_pop(stack s) {
    assert(!stack_is_empty(s));
    stack top = s;
    s = s->next;
    free(top);
    return s;
}

unsigned int stack_size(stack s) {
    unsigned int size = 0u;
    stack i = s;
    while (i != NULL) {
        size++;
        i = i->next;
    }
    return size;
}

stack_elem stack_top(stack s) {
    assert(!stack_is_empty(s));
    return s->elem;
}

bool stack_is_empty(stack s) {
    return (s == NULL);
}

stack_elem *stack_to_array(stack s) {
    stack id = s;
    unsigned int size = stack_size(s);
    stack_elem *array = calloc(size, sizeof(stack_elem));
    if (stack_is_empty(s)) {
        free(array);
        array = NULL;
    } else {
        for (int i = size; i > 0; --i) {
            array[i - 1u] = id->elem;
            id = id->next;
        }
    }
    return array;
}

stack stack_destroy(stack s) {
    if (!stack_is_empty(s)){
        stack_destroy(s->next);
    }
    free(s);
    s = NULL;
    return s;
}