#include <stdlib.h>
#include <assert.h>
#include "item.h"
#include "knapsack.h"
#include "set.h"

struct _s_knap {
    set packed_items;
    unsigned int capacity;
    value_t items_value;
    weight_t items_weight;
};

static bool invrep(knapsack k) {
    bool crit1 = k != NULL;
    bool crit2 = k->capacity >= k->items_weight;
    return crit1 && crit2;
}

knapsack knapsack_empty(unsigned int capacity) {
    knapsack k = malloc(sizeof(struct _s_knap));
    k->packed_items = set_empty();
    k->capacity = capacity;
    k->items_value = 0u;
    k->items_weight = 0u;
    assert(invrep(k));
    return k;
}

knapsack knapsack_clone(knapsack k) {
    knapsack k_copy = knapsack_empty(k->capacity);
    k_copy->packed_items = set_clone(k->packed_items);
    k_copy->items_value = k->items_value;
    k_copy->items_weight = k->items_weight;
    assert(invrep(k_copy));
    return k_copy;
}

knapsack knapsack_pack(knapsack k, item_t item) {
    assert(invrep(k));
    k->packed_items = set_add(k->packed_items, item);
    k->items_value += item_value(item);
    k->items_weight += item_weight(item);
    assert(invrep(k));
    return k;
}

bool knapsack_greater_value(knapsack k1, knapsack k2) {
    assert(invrep(k1) && invrep(k2));
    return k1->items_value > k2->items_value;
}

bool knapsack_is_full(knapsack k) {
    assert(invrep(k));
    return k->capacity == k->items_weight;
}

bool knapsack_can_hold(knapsack k, item_t item) {
    assert(invrep(k));
    return k->capacity >= k->items_weight + item_weight(item);
}

weight_t knapsack_capacity(knapsack k) {
    assert(invrep(k));
    return k->capacity;
}

weight_t knapsack_weight(knapsack k) {
    assert(invrep(k));
    return k->items_weight;
}

value_t knapsack_value(knapsack k) {
    assert(invrep(k));
    return k->items_value;
}

void knapsack_dump(knapsack k) {
    weight_t capacity, remind;
    assert(invrep(k));
    capacity = knapsack_capacity(k);
    remind = capacity - knapsack_weight(k);
    printf("knapsack value   : $%u\n", knapsack_value(k));
    printf("knapsack capacity: %u\n", capacity);
    printf("knapsack remind  : %u\n", remind);
    printf("**** packed items ****\n");
    set_dump(k->packed_items);
}

knapsack knapsack_destroy(knapsack k) {
    assert(invrep(k));
    set_destroy(k->packed_items);
    free(k);
    return k;
}

