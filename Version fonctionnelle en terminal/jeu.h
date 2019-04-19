#ifndef __JEU_H__
#define __JEU_H__

#include <stdio.h>
#include <stdlib.h>
#include "grille.h"
#include "objet.h"

/**
* \file jeu.h
* \author Mathis Despres
* \date 17 avril 2019
* \version à rendre
*/

int gagnant(t_grille * grille, int nbJetons, t_joueur * joueur);
int nonPleine(t_piece piece, int nbCol, t_grille * grille, t_joueur* joueur);
void tour_joueur(t_joueur * joueur, t_grille * grille);
void joueurVSjoueur(t_grille * grille, t_joueur * joueur, int nb_joueur, int nb_pion);
int joueurVSia(t_grille * grille, t_joueur * joueur, int nb_joueur, int nb_bots, int nb_pion);

#endif
