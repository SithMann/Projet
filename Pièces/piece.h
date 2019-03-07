#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "joueur.h"

/**
* \file piece.h
* \author Mathis Despres
* \date 5 mars 2019
* 
* 
*/

/**
* \typedef structure
* \struct s_piece
* \brief structure qui permet de garder en memoire les caracteristiques sur toutes les pieces existantes
*/
/* Structure d'une pièce */
typedef struct s_piece{
    int nbpieces; // Le nombre
    int type; // 1, 2, 3 pour (pleine, creuse, bloquante)
    t_joueur joueur;
}t_piece;

void afficherPiece(t_piece *piece);
t_piece creerPiece(int type, int nb, t_joueur joueur);
void detruirePiece(t_piece *piece);