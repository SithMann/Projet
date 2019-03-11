#ifndef __GRILLE_H__
#define __GRILLE_H__

#include <stdio.h>
#include <stdlib.h>
#include "objet.h"
#include "case.h"

typedef struct s_grille{
    #include <attributs_objet.h>
    int longueur;
    int largeur;
    t_case ** laGrille;
}t_grille;


//void ajouter_piece(int x, int y, t_case **grille, t_piece piece);
t_grille * creer_grille(int longueur, int largeur, void * typeGrille);
void detruire_grille(t_grille grille);

#endif 