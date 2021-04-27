#Here we set the flags we want to apply
CFLAGS = -Wall -Wextra -Werror -pedantic -std=c99

#Here we specify the files that will be compiled (appart from main.c)
SRC = array_helpers.c weather.c weather_utils.c

#Specify the compiler
CC = gcc

#If only "make" is typed in the console, Makefile will compile this:
all: weather

#compiles all files without linking them
objects:
	$(CC) $(CFLAGS) -c $(SRC)
#Use the $() to specify that the value of a variable is required

#output programm
weather: objects
	$(CC) $(CFLAGS) -o $@ *.o main.c
#The $@ symbol means "the name of the rule"

#To delete binary and exacutable files
clean:
	rm -f weather array_helpers.o weather.o weather_utils.o

run: weather
	./weather ../input/weather_cordoba.in

#Compile even if the file (exists and) is compiled (clean in this case)
PHONY: clean
