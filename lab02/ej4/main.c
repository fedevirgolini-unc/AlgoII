/* First, the standard lib includes, alphabetically ordered */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/* Then, this project's includes, alphabetically ordered */
#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"

/* Maximum allowed length of the array */
static const unsigned int MAX_SIZE = 100000u;

void print_help(char *program_name) {
    /* Print the usage help of this program. */
    printf("Usage: %s <input file path>\n\n"
           "Sort an array given in a file in disk.\n"
           "\n"
           "The input file must have the following format:\n"
           " * The first line must contain only a positive integer,"
           " which is the length of the array.\n"
           " * The second line must contain the members of the array"
           " separated by one or more spaces. Each member must be an integer."
           "\n\n"
           "In other words, the file format is:\n"
           "<amount of array elements>\n"
           "<array elem 1> <array elem 2> ... <array elem N>\n\n",
           program_name);
}

char *parse_filepath(int argc, char *argv[]) {
    /* Parse the filepath given by command line argument. */
    char *result = NULL;

    if (argc < 2) {
        print_help(argv[0]);
        exit(EXIT_FAILURE);
    }

    result = argv[1];

    return (result);
}

int main(int argc, char *argv[]) {
    char *filepath = NULL;

    /* parse the filepath given in command line arguments */
    filepath = parse_filepath(argc, argv);
    
    /* create an array of MAX_SIZE elements */
    int array[MAX_SIZE];
    
    /* parse the file to fill the array and obtain the actual length */
    unsigned int length = array_from_file(array, MAX_SIZE, filepath);

/* SELECTION SORT */

    /* create a copy of the array, to do some checks later */
    int copy[MAX_SIZE];
    array_copy(copy, array, length);

    /* reset counters and set time */
    reset_comparisons_counter();
    reset_swaps_counter();
    set_current_time();
    
    /* do the actual sorting */
    selection_sort(copy, length);

    /* show statistics for selection_sort */
    printf("statistics for selection_sort\n");
    printf("time elapsed=%g,    comparisons: %10u,    swaps: %10u\n", calculate_elapsed_time(), comparisons_number(), swaps_number());
    
/* INSERTION SORT */

    /* create a copy of the array, to do some checks later */
    int copy_2[MAX_SIZE];
    array_copy(copy_2, array, length);
    
    /* reset counters and set time */
    reset_comparisons_counter();
    reset_swaps_counter();
    set_current_time();
    
    /* do the actual sorting */
    insertion_sort(copy_2, length);
    
    /* show statistics for insertion_sort */
    printf("\n");
    printf("statistics for insertion_sort\n");
    printf("time elapsed=%g,    comparisons: %10u,    swaps: %10u\n", calculate_elapsed_time(), comparisons_number(), swaps_number());
    
/* QUICK SORT */

    /* create a copy of the array, to do some checks later */
    int copy_3[MAX_SIZE];
    array_copy(copy_3, array, length);
    
    /* reset counters and set time */
    reset_comparisons_counter();
    reset_swaps_counter();
    set_current_time();
    
    /* do the actual sorting */
    quick_sort(copy_3, length);
    
    /* show statistics for quick_sort */
    printf("\n");
    printf("statistics for quick_sort\n");
    printf("time elapsed=%g,    comparisons: %10u,    swaps: %10u\n", calculate_elapsed_time(), comparisons_number(), swaps_number());

/*  checks */
  
    /* check if it is sorted */
    assert(array_is_sorted(copy, length));
    assert(array_is_sorted(copy_2, length));
    assert(array_is_sorted(copy_3, length));

    /* check if it is a permutation of original */
    assert(array_is_permutation_of(array, copy, length));
    assert(array_is_permutation_of(array, copy_2, length));
    assert(array_is_permutation_of(array, copy_3, length));
    
    return (EXIT_SUCCESS);
}
