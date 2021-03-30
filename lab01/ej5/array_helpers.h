#include "boolean.h"

#ifndef PRINT_HELP
#define PRINT_HELP
void print_help(char *program_name);
#endif

#ifndef PARSE_FILEPATH
#define PARSE_FILEPATH
char *parse_filepath(int argc, char *argv[]);
#endif

#ifndef ARRAY_FROM_FILE
#define ARRAY_FROM_FILE
unsigned int array_from_file(int array[], unsigned int max_size, const char *filepath);
#endif

#ifndef ARRAY_DUMP
#define ARRAY_DUMP
void array_dump(int a[], unsigned int length);
#endif

#ifndef ARRAY_IS_SORTED
#define ARRAY_IS_SORTED
boolean array_is_sorted(int a[], unsigned int max_size);
#endif
