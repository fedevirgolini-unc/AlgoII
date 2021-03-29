/* First, the standard lib includes, alphabetically ordered */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>


/* Maximum allowed length of the array */
#define MAX_SIZE 100000

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

unsigned int array_from_file(int array[],
           unsigned int max_size,
           const char *filepath) {

    FILE * archivo;
    unsigned int length;

    archivo = fopen(filepath, "r");
    fscanf(archivo, "%u", &length);

    if(length>max_size){
        printf("El arreglo es demasiado grande, solo se tomarán los primeros %d valores\n", max_size);
        length = max_size;
    }

    for(unsigned int i=0; i<length ;i++){
        fscanf(archivo, "%d", array+i);
    }
    fclose(archivo);

    return length;

}

void array_dump(int a[], unsigned int length) {
    
    //Checkear si no se puede optimizar más
    printf("[");
    for(unsigned int i=0; i<length; i++){
        if(i != 0){
            printf(",");
        }
        printf(" %d", a[i]);
    }
    printf("]\n");

}

unsigned int get_length(unsigned int max_size){

    unsigned int length;

    printf("Ingrese el tamaño del arreglo:\n(debe ser un número positivo menor o igual a %d)\n", max_size);
    int scanf_result = scanf("%u", &length);

    if (scanf_result <= 0) {
            printf("Error al leer un número desde teclado\n");
            exit(EXIT_FAILURE);
        }

    while(length>max_size){
        printf("El valor ingresado es incorrecto, intente nuevamente\n");
        scanf_result = scanf("%u", &length);
    }

    return length;
}

void pedir_arreglo(int a[], unsigned int length){

    printf("Ahora debe ingresar los elementos del arreglo\n(deben ser números enteros)\n");

    for(unsigned int i=0; i<length; i++){
        printf("- Ingrese el elemento %u: ", i);
        int scanf_result = scanf("%d", a+i);

        if (scanf_result <= 0) {
            printf("Error al leer un número desde teclado\n");
            exit(EXIT_FAILURE);
        }
    }

}

int main() {
 
    /* create an array of MAX_SIZE elements */
    int array[MAX_SIZE];
    unsigned int length;

    
    length = get_length(MAX_SIZE);

    pedir_arreglo(array, length);
    
    /*dumping the array*/
    array_dump(array, length);
    
    return (EXIT_SUCCESS);
}
