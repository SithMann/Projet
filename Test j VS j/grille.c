#include <stdio.h>
#include <stdlib.h>
#include "grille.h"
#include "joueur.h"

void afficher_grille(int longueur, int largeur, t_case **grille, t_joueur joueur){
    int i, j;
    for(i=0; i<longueur; i++){
        for(j=0; j<largeur; j++){
<<<<<<< HEAD
            if(grille[i][j].piece1!=NULL){
                afficherPiece(grille[i][j].piece1);
                if(grille[i][j].piece2!=NULL)
                    afficherPiece(grille[i][j].piece2);
=======
            printf("|");
            if(grille[i][j].piece1!=NULL){
                afficherPiece(grille[i][j].piece1, joueur);
                if(grille[i][j].piece2!=NULL)
                    afficherPiece(grille[i][j].piece2, joueur);
>>>>>>> 6da620fbb9d95f48a44abfc4768c7e8dfe6f7b63
            }
            printf("\t");
        }
        printf("\n");
    }
}


void ajouter_piece(int x, int y, t_case **grille, t_piece piece){
    //on verrifie si la piece est bloquante avant 
    if(grille[x][y].piece1==NULL)
        grille[x][y].piece1 = &piece;
    else
        grille[x][y].piece2 = &piece;
}

t_case **init_grille(int x, int y, t_case **grille){
    grille=(t_case **) malloc(x*sizeof(t_case*)); 

    for (int i=0; i<y; i++) 
        grille[i]=(t_case *) malloc(y*sizeof(t_case)); 

    for(int i=0; i<x; i++){
        for(int j=0; j<y; j++){
            grille[i][j].piece1 = NULL;
            grille[i][j].piece2 = NULL;
        }
    }
    return grille;
}