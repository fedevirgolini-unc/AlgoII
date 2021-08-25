#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include "abb.h"

struct _s_abb {
    abb_elem elem;
    struct _s_abb *left;
    struct _s_abb *right;
};

static bool elem_eq(abb_elem a, abb_elem b) {
    return a == b;
}

static bool elem_less(abb_elem a, abb_elem b) {
    return a < b;
}

static bool check_grater(abb_elem e, abb tree) {
    bool grater = true;
    if (tree != NULL) {
        grater = elem_less(tree->elem, e) && check_grater(e, tree->left)
                                          && check_grater(e, tree->right);
    }
    return grater;
}

static bool check_smaller(abb_elem e, abb tree) {
    bool smaller = true;
    if (tree != NULL) {
        smaller = elem_less(e, tree->elem) && check_smaller(e, tree->left)
                                          && check_smaller(e, tree->right);
    }
    return smaller;
}

static bool invrep(abb tree) {
    bool valid = true;
    if (tree != NULL) {
        valid =  check_grater(tree->elem, tree->left) &&
                 check_smaller(tree->elem, tree->right) &&
                 invrep(tree->left) && invrep(tree->right);
    }
    return valid;
}

abb abb_empty(void) {
    abb tree = NULL;
    assert(invrep(tree) && abb_is_empty(tree));
    return tree;
}

abb abb_add(abb tree, abb_elem e) {
    assert(invrep(tree));
    abb new = malloc(sizeof(struct _s_abb));
    new->elem = e;
    new -> left = NULL;
    new->right = NULL;
    if (abb_is_empty(tree)) {
        tree = new;
    } else if (tree->elem == e) {
        free(new);
        new = NULL;
    } else if (elem_less(e, tree->elem)) {
        abb_add(tree->left, e);
    } else if (elem_less(tree->elem, e)) {
        abb_add(tree->right, e);
    }
    vrep(tree) && abb_exists(tree, e);
    return tree;
}

bool abb_is_empty(abb tree) {
    assert(vrep(tree));
    return tree == NULL;
}

bool abb_exists(abb tree, abb_elem e) {
    bool exists=false;
    assert(invrep(tree));
    if (!abb_is_empty(tree)) {
        if (e == tree->elem) {
            exists = true;
        } else if (elem_less(e, tree->elem)) {
            exists = abb_exists(tree->left, e);
        } else if (elem_less(tree->elem, e)) {
            exists = abb_exists(tree->right, e);
        }
    }
    assert(invrep(tree));
    return exists;
}

unsigned int abb_length(abb tree) {
    unsigned int length=0;
    assert(invrep(tree));
    if (!abb_is_empty(tree)) {
        if (tree->left != NULL) {
            length = length + 1u + abb_length(tree->left);
        }
        if (tree->right != NULL) {
            length = length + 1u + abb_length(tree->right);
        }
    }
    assert(invrep(tree) && (abb_is_empty(tree) ||  length > 0));
    return length;
}

abb abb_remove(abb tree, abb_elem e) {
    assert(invrep(tree));
    abb remove = tree;
    abb father = tree;
    //find the element and its father
    while (remove != NULL && remove->elem != e) {
        if (elem_less(e, remove->elem)) {
            father = remove;
            remove = tree->left;
        } else if (elem_less(remove->elem, e)) {
            father = remove;
            remove = tree->right;
        }
    }
    //replace it or delete it
    if (remove->elem == e) {
        if (remove->left == NULL && remove->right == NULL) {
            /*
            free(remove);
            remove = NULL;
            if (elem_less(e, father->elem)) {
                father->left = NULL;
            } else if (elem_less(father->elem, e)) {
                father->right = NULL;
            }
            */
        } else if (remove->left != NULL) {
            remove->elem = abb_max(remove->left);
            remove->left = abb_remove(remove->left, abb_max(remove->left));
        } else if (remove->right != NULL) {
            remove->elem = abb_min(remove->right);
            remove->right = abb_remove(remove->right, abb_min(remove->right));
        }
    }
    assert(invrep(tree) && !abb_exists(tree, e));
    return tree;
}


abb_elem abb_root(abb tree) {
    abb_elem root;
    assert(invrep(tree) && !abb_is_empty(tree));
    root = tree->elem;
    assert(abb_exists(tree, root));
    return root;
}

abb_elem abb_max(abb tree) {
    abb_elem max_e;
    assert(invrep(tree) && !abb_is_empty(tree));
    if (tree->right != NULL) {
        max_e = abb_max(tree->right);
    } else {
        max_e = tree->elem;
    }
    assert(invrep(tree) && abb_exists(tree, max_e));
    return max_e;
}

abb_elem abb_min(abb tree) {
    abb_elem min_e;
    assert(invrep(tree) && !abb_is_empty(tree));
    if (tree->left != NULL) {
        min_e = abb_min(tree->left);
    } else {
        min_e = tree->elem;
    }
    assert(invrep(tree) && abb_exists(tree, min_e));
    return min_e;
}

void abb_dump(abb tree) {
    assert(invrep(tree));
    if (tree != NULL) {
        abb_dump(tree->left);
        printf("%d ", tree->elem);
        abb_dump(tree->right);
    }
}

abb abb_destroy(abb tree) {
    assert(invrep(tree));
    if (tree->left != NULL) {
        abb_destroy(tree->left);
    }
    if (tree->right != NULL) {
        abb_destroy(tree->right);
    }
    free(tree);
    tree = NULL;
    assert(tree == NULL);
    return tree;
}

