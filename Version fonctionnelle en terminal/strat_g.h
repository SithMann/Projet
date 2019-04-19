#ifndef __STRAT_H__
#define __STRAT_H__

#include <stdio.h>
#include <stdlib.h>
#include "grille.h"

/**
* \file strat_g.h
* \author Noémie Farizon et Mathis Despres
* \date 20 mars 2019
* \version finale
*/
int coup_gagnant(t_grille * grille, t_joueur *joueur, int nJetons);
int jouer_coup_gagnant(t_grille * grille, t_joueur *joueur, int nJetons);
void dejouer(t_piece piece, int nbCol, t_grille * grille, t_joueur* joueur);
int adversaire(t_grille * grille, t_joueur * joueur, int num_joueur, int profondeur, int prof_max, int nb_joueur, int num_ordi, int nJetons, int alpha);
int ordi(t_grille * grille, t_joueur * joueur, int num_joueur, int profondeur, int prof_max, int nb_joueur, int num_ordi, int nJetons, int beta);
void tour_ordi(t_grille * grille, t_joueur * joueur, int num_joueur, int prof_max, int nb_joueur, int nJetons);
int evaluation(t_grille *grille, t_joueur * joueur, int num_joueur, int nb_joueur, int nJetons);

#endif
