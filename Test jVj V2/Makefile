CFLAGS = -g -Wall
CC = gcc

PROG = puissance4++
PROG2 = test_jvj


$(PROG) : menu.o case.o jeu.o place.o grille.o joueur.o main.o
	$(CC) $^ -o $@ $(CFLAGS) 

$(PROG2) : menu.o case.o place.o grille.o joueur.o test_jvj.o
	$(CC) $^ -o $@ $(CFLAGS)

%.o:%.c %.h
	$(CC) -c $< $(CFLAGS) 

clean : 
	rm -rf *.o
	rm -rf *.h.gch
	rm -rf $(PROG)