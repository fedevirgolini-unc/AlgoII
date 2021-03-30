/* First, the standard lib includes, alphabetically ordered */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "array_helpers.h"


/* Maximum allowed length of the array */
#define MAX_SIZE 100000

int main(int argc, char *argv[]) {
    char *filepath = NULL;

    /* parse the filepath given in command line arguments */
    filepath = parse_filepath(argc, argv);
    
    /* create an array of MAX_SIZE elements */
    int array[MAX_SIZE];
    
    /* parse the file to fill the array and obtain the actual length */
    unsigned int length = array_from_file(array, MAX_SIZE, filepath);
    
    /*invertir posiciones del array */
    for (unsigned int i=0; i<(length/2); i++) {
        array_swap(array, i, (length-1-i));
    }    
    
    /*dumping the array*/
    array_dump(array, length);
    
    if (array_is_sorted(array, length)) {
        printf("El arreglo está ordenado\n");
    }else{
        printf("El arreglo no está ordenado\n");
    }
    
    return (EXIT_SUCCESS);
}
