# Michael Walton : mwwalton@ucsc.edu
# Makefile for Linked list module and driver program
# It compiles the module and creates the decToBinary executable

Store : Store.o List.o
	gcc -ansi -Wall -Wextra -pedantic -o store Store.o List.o

Listdr : Listdr.o List.o
	gcc -ansi -Wall -Wextra -pedantic -o listdr Listdr.o List.o

List.o : List.c List.h
	gcc -c -ansi -Wall -Wextra -pedantic List.c

Listdr.o : Listdr.c
	gcc -c -ansi -Wall -Wextra -pedantic Listdr.c

Store.o : Store.c
	gcc -c -ansi -Wall -Wextra -pedantic Store.c

clean :
	rm listdr store List.o Listdr.o Store.o
