#Here we set the flags we want to apply
CFLAGS = -Wall -Wextra -Werror -pedantic -std=c99 -g

#Here we specify the files that will be compiled (appart from main.c)
SRC = array_helpers.c list.c

#Specify the compiler
CC = gcc

#If only "make" is typed in the console, Makefile will compile this:
all: average

#compiles all files without linking them
objects:
	$(CC) $(CFLAGS) -c $(SRC)
#Use the $() to specify that the value of a variable is required

#output programm
average: objects
	$(CC) $(CFLAGS) -o $@ *.o main.c
#The $@ symbol means "the name of the rule"

#To delete binary and exacutable files
clean:
	rm -f average array_helpers.o list.o

run1: average
	./average input/all-negative-100.in
run2: average
	./average input/all-positive-100.in
run3: average
	./average input/empty.in
run4: average
	./average input/example-sorted.in
run5: average
	./average input/example-unsorted.in

valgrind: average
	valgrind ./average input/all-negative-100.in

#Compile even if the file (exists and) is compiled (clean in this case)
PHONY: clean
