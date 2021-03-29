#include "assert.h"
#include "stdbool.h"
#include "stdio.h"
#include "stdlib.h"

#define ARRAY_SIZE 10

struct max_min_result {
    int max_value;
    int min_value;
    unsigned int max_position;
    unsigned int min_position;
};

struct max_min_result compute_max_min(int array[], unsigned int length)
{
    assert(length > 0);
    struct max_min_result result = { 0, 0, 0, 0 };

    result.max_value = array[0];
    result.min_value = array[0];
    result.max_position = 0;
    result.max_position = 0;
    
    for(unsigned int i=1; i < length; i++){
        if(array[i] > result.max_value){
            result.max_value = array[i];
            result.max_position = i;
        }
        if(array[i] < result.min_value){
            result.min_value = array[i];
            result.min_position = i;
        }
    }

    return result;
}

void ingresar_arreglo(int array[], unsigned int length)
{
    printf("Ingrese los valores del arreglo:\n");
    for(unsigned int i=0; i < length; i++){
        printf("ingrese un valor para la posición %d\n", i);
        scanf("%d", &array[i]);
    }
}

int main()
{
    int array[ARRAY_SIZE];

    ingresar_arreglo(array, ARRAY_SIZE);

    struct max_min_result result = compute_max_min(array, ARRAY_SIZE);
    printf("Máximo: %d\n", result.max_value);
    printf("Posición del máximo: %u\n", result.max_position);
    printf("Mínimo: %d\n", result.min_value);
    printf("Posición del mínimo: %u\n", result.min_position);
    return 0;
}
