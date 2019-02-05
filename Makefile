projet : main.o grille.o
	gcc -o projet main.o grille.o
grille.o : grille.c
	gcc -o grille.o -c grille.c
main.o : main.c grille.h
	gcc -o main.o -c main.c