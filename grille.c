#include <stdio.h>
#include <stdlib.h>
#include "grille.h"

#define L 7 // nombre de lignes
#define C 7 // nombre de colonnes

/* fonction pour creer / initialiser la grille de jeu */
static
void initialiserGrille(grille_t * laMap){
    for(int i = 0; i < L; i++){
        for(int j = 0; j < C; j++)
        {
            laMap->matrice[i][j] = 0;
        }
    }
}

/* fonction pour creer / initialiser la grille de jeu */
static 
void afficherGrille(grille_t * laMap){
    for(int i = 0; i < L; i++){
        for(int j = 0; j < C; j++)
        {
            printf(" %d /",laMap->matrice[i][j]);
        }
        printf("\n");
    }
}

extern
grille_t * creerGrille(int mat[L][C]){
    grille_t * grille = NULL;
    grille.matrice = mat;
    grille->initGrille = initialiserGrille;
    grille->affGrille = afficherGrille;
}