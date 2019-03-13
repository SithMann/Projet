CFLAGS = -g -Wall
CC = gcc

PROG = puissance4++


all: $(PROG)

$(PROG) : menu.o piece.o case.o jeu.o place.o grille.o joueur.o main.o
	$(CC) $^ -o $@ $(CFLAGS) 

%.o:%.c %.h
	$(CC) -c $< $(CFLAGS) 

clean : 
	rm -rf *.o
	rm -rf *.h.gch