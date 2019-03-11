#ifndef __GRILLE_H__
#define __GRILLE_H__

#include <stdio.h>
#include <stdlib.h>
#include "piece.h"

typedef struct s_grille{
    int longueur;
    int largeur;
    t_case ** laCase;
}t_grille;

/*
void afficher_grille(int longueur, int largeur, t_case **grille);
void ajouter_piece(int x, int y, t_case **grille, t_piece piece);
t_case **init_grille(int x, int y, t_case **grille);
*/
#endif 