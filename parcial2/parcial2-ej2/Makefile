#Here we set the flags we want to apply
CFLAGS = -Wall -Wextra -Werror -pedantic -std=c99

#Here we specify the files that will be compiled (appart from main.c)
SRC = truco.c

#Specify the compiler
CC = gcc

#If only "make" is typed in the console, Makefile will compile this:
all: programm

#compiles all files without linking them
objects:
	$(CC) $(CFLAGS) -c $(SRC)
#Use the $() to specify that the value of a variable is required

#output programm
programm: objects
	$(CC) $(CFLAGS) -o $@ *.o main.c
#The $@ symbol means "the name of the rule"

#To delete binary and exacutable files
clean:
	rm -f programm truco.o

run: programm
	./programm

#Compile even if the file (exists and) is compiled (clean in this case)
PHONY: clean
