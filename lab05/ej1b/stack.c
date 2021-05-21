#include <stdlib.h>
#include <assert.h>
#include "stack.h"

struct _s_node {
    stack_elem elem;
    struct _s_node *next;
};

struct _s_stack {
    struct _s_node *first;
    unsigned int size;
};

struct _s_node *node_destroy(struct _s_node *pnode) {
    if (pnode->next != NULL) {
        node_destroy(pnode->next);
    }
    free(pnode);
    pnode = NULL;
    return pnode;
}

static bool invrep(stack s) {
    bool crit1 = s != NULL;
    bool crit2 = (s->first == NULL) && (s->size == 0u);
    bool crit3 = (s->first != NULL) && (s->size > 0u);
    return crit1 && (crit2 || crit3);
}

stack stack_empty() {
    stack new = malloc(sizeof(struct _s_stack));
    new->first = NULL;
    new->size = 0u;
    assert(invrep(new));
    return new;
}

stack stack_push(stack s, stack_elem e) {
    assert(invrep(s));
    struct _s_node *new_element = malloc(sizeof(struct _s_node));
    new_element->elem = e;
    new_element->next = s->first;
    s->first = new_element;
    s->size += 1u;
    assert(invrep(s));
    return s;
}

stack stack_pop(stack s) {
    assert(invrep(s));
    assert(!stack_is_empty(s));
    struct _s_node *top = s->first;
    s->first = top->next;
    s->size -= 1u;
    free(top);
    top = NULL;
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
    return (s->first)->elem;
}

bool stack_is_empty(stack s) {
    assert(invrep(s));
    return s->size == 0u;
}

stack_elem *stack_to_array(stack s) {
    assert(invrep(s));
    struct _s_node *id = (s->first);
    stack_elem *array = calloc(s->size, sizeof(stack_elem));
    if (stack_is_empty(s)) {
        free(array);
        array = NULL;
    } else {
        for (int i = s->size; i > 0; --i) {
            array[i - 1u] = id->elem;
            id = id->next;
        }
    }
    assert(invrep(s));
    return array;
}

stack stack_destroy(stack s) {
    assert(invrep(s));
    if (!stack_is_empty(s)) {
        node_destroy(s->first);
    }
    free(s);
    s = NULL;
    return s;
}