#ifndef _list_
#define _list_

#include <stdbool.h>

typedef struct _list * list;
typedef int list_elem;

//constructors:

list empty();
/*
creates a new empty list
*/

list addl(list_elem e, list l);
/*
adds the element e at the beggining of the list
*/

//operators:
bool is_empty(list l);
/*
Return True if l is empty
*/

list_elem head(list l);
/*
Return the first element of the list l
PRE: not is_empty(l)
*/

list tail(list l);
/*
Delete the first element of the list l
PRE: not is_empty(l)
*/

list addr(list l, list_elem e);
/*
Adds the element e as the last element of the list l
*/

unsigned int length(list l);
/*
Return how many elements the list l has
*/

list concat(list l1, list l2);
/*
Adds all elements of l2 in the end of l1
*/

list_elem list_index(list l, unsigned int n);
/*
Return the element located in n of the list l
PRE: length(l) > n
*/

list take(list l, unsigned int n);
/*
Leaves only the first n elements of the list l,
deleting the others
*/

list drop(list l, unsigned int n);
/*
Deletes the firsts n elements of the list l
*/

//copy;
list copy(list l);
/*
Copies all the elements of the list l1 in a new list l2
*/

//destroy:
list destroy(list l);
/*
Frees memory in case is needed
*/

#endif //_list_
