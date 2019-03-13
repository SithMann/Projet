#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "piece.h"

/**
* \file piece.c
* \author Mathis Despres
* \date 5 mars 2019
*/

int main(){

    t_joueur joueur;
    joueur.pseudo = "test";
    joueur.nbWin = 0;
    joueur.nJoueur = 1;
    joueur.couleur = RED;

    t_piece piece = creerPiece(1,10, joueur);

    printf("Une piece : ");
    afficherPiece(&piece);
    printf("\n");

    return 0;
}