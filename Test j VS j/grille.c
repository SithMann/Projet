#include <stdio.h>
#include <stdlib.h>
#include "grille.h"

void afficher_grille(int longueur, int largeur, t_case **grille){
    int i, j;
    for(i=0; i<longueur; i++){
        for(j=0; j<largeur; j++){
            if(grille[i][j]->piece1!=NULL){
                afficherPiece(grille[i][j]->piece1);
                if(grille[i][j]->piece2!=NULL)
                    afficherPiece(grille[i][j]->piece2);
            }
            printf("\t");
        }
        printf("\n");
    }
}

void ajouter_piece(int x, int y, t_case **grille, t_piece piece){
    //on verrifie si la piece est bloquante avant 
    if(grille[x][y]->piece1==NULL)
        grille[x][y]->piece1 = piece;
    else
        grille[x][y]->piece2 = piece;
}
