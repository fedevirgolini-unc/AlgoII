#Here we set the flags we want to apply
CFLAGS = -Wall -Wextra -Werror -pedantic -std=c99

#Here we specify the files that will be compiled (appart from main.c)
SRC = counter.c

#Specify the compiler
CC = gcc

#If only "make" is typed in the console, Makefile will compile this:
all: executable

#compiles all files without linking them
objects:
	$(CC) $(CFLAGS) -c $(SRC)
#Use the $() to specify that the value of a variable is required

#output programm
executable: objects
	$(CC) $(CFLAGS) -o $@ *.o main.c
#The $@ symbol means "the name of the rule"

#To delete binary and exacutable files
clean:
	rm -f executable counter.o

run1: executable
	./executable input/balanced.in
run2: executable
	./executable input/moreopen.in
run3: executable
	./executable input/onlyopen.in

#Compile even if the file (exists and) is compiled (clean in this case)
PHONY: clean
