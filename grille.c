#include <stdio.h>
#include <stdlib.h>
#include "piece.h"

typedef struct s_case{
    t_piece *piece1; //pointeur sur la premiere piece presente dans la case 
    t_piece *piece2; //vide si la première pièce est de type bloquante 
}t_case;

void afficher_grille(int longueur, int largeur, t_case grille[longueur][largeur]){
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

int main(){
    //demander la taille de la grille 
    t_case grille[longueur][largeur];

}