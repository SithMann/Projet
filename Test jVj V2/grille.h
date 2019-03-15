#ifndef __GRILLE_H__
#define __GRILLE_H__

#include <stdio.h>
#include <stdlib.h>
#include "objet.h"
#include "case.h"

typedef struct s_grille{
    #include "attributs_objet.h"
    int longueur;
    int largeur;
    t_case *** laGrille;
}t_grille;


//void ajouter_piece(int x, int y, t_case **grille, t_piece piece);
t_grille * creer_grille(int longueur, int largeur, int taille);
<<<<<<< HEAD
void detruire_grille(t_grille grille);
=======
void detruire_grille(t_grille * grille);
void ajouter_piece(int x, int y, t_grille * grille, t_piece piece, t_joueur joueur);
>>>>>>> c9a4a9c41d4e8f580573b73431f61e1225913cb1

#endif 