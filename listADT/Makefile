# Michael Walton : mwwalton@ucsc.edu
# Makefile for Linked list module and driver program
# It compiles the module and creates the decToBinary executable

Listdr : Listdr.o List.o
	gcc -ansi -Wall -Wextra -pedantic -o listdr Listdr.o List.o

List.o : List.c List.h
	gcc -c -ansi -Wall -Wextra -pedantic List.c

Listdr.o : Listdr.c
	gcc -c -ansi -Wall -Wextra -pedantic Listdr.c

clean :
	rm listdr List.o Listdr.o
