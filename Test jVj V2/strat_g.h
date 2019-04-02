#include <stdio.h>
#include <stdlib.h>
#include "grille.h"

void dejouer(t_piece piece, int nbCol, t_grille * grille, t_joueur* joueur);
int adversaire(t_grille * grille, t_joueur * joueur, int num_joueur, int profondeur, int prof_max, int nb_joueur);
int ordi(t_grille * grille, t_joueur * joueur, int num_joueur, int profondeur, int prof_max, int nb_joueur);
void tour_ordi(t_grille * grille, t_joueur * joueur, int num_joueur, int profondeur, int prof_max, int nb_joueur);