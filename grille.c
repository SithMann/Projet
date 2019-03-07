#include <stdio.h>
#include <stdlib.h>
#include "piece.h"

/**
* \file grille.c
* \author Noemie Farizon
* \date 5 mars 2019
*/

/**
* \typedef structure
* \struct s_case
* \brief structure qui permet de stocker le contenue d'une case de la grille(nombre de pieces, type...)
*/
typedef struct s_case{
    t_piece *piece1; //pointeur sur la premiere piece presente dans la case 
    t_piece *piece2; //vide si la première pièce est de type bloquante 
}t_case;

/**
* \fn afficher_grille
* \param entier longueur, entier largeur, matrice grille de type t_case
* \return la fonction ne retourne rien
* */
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

/**
* \fn ajouter_piece
* \param entier x, entier y, matrice grille de type t_case, piece de type t_piece
* \return la fonction ne retourne rien
* */
void ajouter_piece(int x, int y, t_case **grille, t_piece piece){
    //on verrifi si la piece est bloquante avant 
    if(grille[x][y]->piece1==NULL)
        grille[x][y]->piece1 = piece;
    else
        grille[x][y]->piece2 = piece;
}

int main(){
    //demander la taille de la grille 
    t_case grille[longueur][largeur];

}