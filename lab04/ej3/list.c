#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

#include "list.h"


struct _list {
    list_elem elem;
    struct _list* next;
};

typedef struct _list* node;

list empty() {
    list new = NULL;
    return new;
}

list addl(list_elem e, list l) {
    node new_element = malloc(sizeof(node));
    new_element->elem = e;
    new_element->next = l;
    l = new_element;
    return l;
}

bool is_empty(list l) {
    return (l == NULL);
}

list_elem head(list l) {
    assert(!is_empty(l));
    return l->elem;
}

list tail(list l) {
    assert(!is_empty(l));
    node first = l;
    l = l->next;
    free(first);
    return l;
}

list addr(list l, list_elem e) {
    node last = l;
    node new = malloc(sizeof(struct _list));
    new->elem = e;
    new->next = NULL;
    while (last != NULL) {
        last = last->next;
    }
    last->next = new;
    return l;
}

unsigned int length(list l) {
    unsigned int len = 0;
    node i = l;
    while (i != NULL) {
        len++;
    }
    return len;
}

list concat(list l1, list l2) {
    node last = l1;
    while (last != NULL) {
        last = last->next;
    }
    last->next = l2;
    return l1;
}

list_elem index(list l, unsigned int n) {
    assert(length(l) > n);
    node index = l;
    for (unsigned int i = 0; i < n; i++) {
        index = index->next;
    }
    return index->elem;
    
}

list take(list l, unsigned int n) {
    node last = l;
    if (n < length(l)) {
        for (unsigned int i = 0; i < n; i++) {
            last = last->next;
        }
        destroy(last->next);
        last->next = NULL;
    }
    return l;
}

list drop(list l, unsigned int n) {
    node first = l;
    node elem_n = l;
    if (n >= length(l)) {
        destroy(l);
    } else {
        for (unsigned int i = 0; i < n; i++) {
            elem_n = elem_n->next;
        }
        l = elem_n->next;
        elem_n->next = NULL;
        destroy(first);
    }
    return l;
}

list copy(list l) {
    list copy = empty();
    node i = l;
    while (i != NULL) {
        addl(i->elem, copy);
        i = i->next;
    }
    return copy;
}

list destroy(list l) {
    if (l->next != NULL) {
        destroy(l->next);
    }
    free(l);
    l = NULL;
    return l;
}