#ifndef __GRILLE_H__
#define __GRILLE_H__

#include <stdio.h>
#include <stdlib.h>
#include "objet.h"
#include "case.h"

/**
* \file grille.c
* \author Noemie Farizon et Mathis Despres
* \date 1 mars 2019
* \version 2
*/

/**
* \typedef structure
* \struc s_case
* \brief structure qui permet de stocker les informations relatives a la grille
*/
typedef struct s_grille{
    #include "attributs_objet.h"
    int longueur;
    int largeur;
    t_case *** laGrille;
}t_grille;

//void ajouter_piece(int x, int y, t_case **grille, t_piece piece);
t_grille * creer_grille(int longueur, int largeur, int taille);
void detruire_grille(t_grille * grille);
void ajouter_piece(int x, int y, t_grille * grille, t_piece piece, t_joueur* joueur);
int est_valide(int ligne, int colonne, t_grille * grille);

#endif 
