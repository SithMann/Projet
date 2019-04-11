CFLAGS = -g -Wall
CC = gcc

PROG = puissance4++
PROG2 = test_jvj
PROG3 = test_Ordi
PROG4 = test_classique_joueur
PROG5 = test_classique_ordi

all : $(PROG) $(PROG2) $(PROG3) $(PROG4) $(PROG5)

$(PROG) : menu.o case.o jeu.o place.o grille.o direction.o joueur.o strat_g.o main.o
	$(CC) $^ -o $@ $(CFLAGS) 

$(PROG2) : case.o place.o grille.o joueur.o test_jvj.o direction.o
	$(CC) $^ -o $@ $(CFLAGS)

$(PROG3) : case.o place.o grille.o joueur.o test_Ordi.o direction.o strat_g.o
	$(CC) $^ -o $@ $(CFLAGS)

$(PROG4) : case.o place.o grille.o joueur.o test_classique_joueur.o direction.o strat_g.o
	$(CC) $^ -o $@ $(CFLAGS)

$(PROG5) : case.o place.o grille.o joueur.o test_classique_ordi.o direction.o strat_g_classique.o
	$(CC) $^ -o $@ $(CFLAGS)


%.o:%.c %.h
	$(CC) -c $< $(CFLAGS) 

clean : 
	rm -rf *.o
	rm -rf *.h.gch
	rm -rf $(PROG)
	rm -rf $(PROG2)
	rm -rf $(PROG3)
	rm -rf $(PROG4)
	rm -rf $(PROG5)

