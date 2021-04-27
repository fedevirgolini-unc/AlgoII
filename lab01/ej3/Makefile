#Here we set the flags we want to apply
CFLAGS = -Wall -Wextra -Werror -pedantic -std=c99

#Here we specify the files that will be compiled (appart from main.c)
SRC = array_helpers.c

#Specify the compiler
CC = gcc

#If only "make" is typed in the console, Makefile will compile this:
all: get_array

#compiles all files without linking them
objects:
	$(CC) $(CFLAGS) -c $(SRC)
	#Use the $() to specify that the value of a variable is required

#output programm
get_array: objects
	$(CC) $(CFLAGS) -o $@ *.o main.c
	#The $@ symbol means "the name of the rule"

#To delete binary and exacutable files
clean:
	rm -f get_array array_helpers.o

run: get_array
	#Here we can make a rule to run an especific example of our programm

#Compile even if the file (exists and) is compiled (clean in this case)
PHONY: clean
