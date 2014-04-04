#Michael Walton : mwwalton@ucsc.edu
# Makefile for intstack module and decToBinary converter
# It compiles the module and creates the decToBinary executable

decToBinary : decToBinary.o intstack.o
	gcc -ansi -Wall -Wextra -pedantic -o decToBinary decToBinary.o intstack.o

intstack.o : intstack.h intstack.c
	gcc -c -ansi -Wall -Wextra -pedantic intstack.c

decToBinary.o : intstack.h decToBinary.c
	gcc -c -ansi -Wall -Wextra -pedantic decToBinary.c

clean :
	rm decToBinary decToBinary.o intstack.o
