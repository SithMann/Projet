#ifndef __JEU_H__
#define __JEU_H__

#include <stdio.h>
#include <stdlib.h>
#include "grille.h"
#include "objet.h"

int gagnant(t_grille * grille, int nbJetons, t_joueur joueur);
int nonPleine(t_piece piece, int nbCol, t_grille grille, t_joueur joueur);
void tour_joueur(t_joueur joueur, t_grille * grille);
void joueurVSjoueur(t_grille * grille, t_joueur * joueur, int nb_joueur, int nb_ligne, int nb_colonne);

#endif