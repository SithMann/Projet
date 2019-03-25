CFLAGS = -g -Wall
CC = gcc

PROG = puissance4++
PROG2 = test_jvj
PROG3 = test_Ordi
PROG4 = test_classique_joueur

all : $(PROG) $(PROG2) $(PROG3) $(PROG4)

$(PROG) : menu.o case.o jeu.o place.o grille.o direction.o joueur.o main.o
	$(CC) $^ -o $@ $(CFLAGS) 

$(PROG2) : case.o place.o grille.o joueur.o test_jvj.o direction.o
	$(CC) $^ -o $@ $(CFLAGS)

$(PROG3) : case.o place.o grille.o joueur.o test_Ordi.o direction.o
	$(CC) $^ -o $@ $(CFLAGS)

$(PROG4) : case.o place.o grille.o joueur.o test_classique_joueur.o direction.o
	$(CC) $^ -o $@ $(CFLAGS)

$(PROG4) : case.o place.o grille.o joueur.o test_classique_joueur.o
	$(CC) $^ -o $@ $(CFLAGS)

%.o:%.c %.h
	$(CC) -c $< $(CFLAGS) 

clean : 
	rm -rf *.o
	rm -rf *.h.gch
	rm -rf $(PROG)
	rm -rf $(PROG2)
	rm -rf $(PROG3)
<<<<<<< HEAD
	rm -rf $(PROG4)
=======
	rm -rf $(PROG4)
>>>>>>> c7fef9e62b03e8bc69c41e951b07181b3d08bd61
