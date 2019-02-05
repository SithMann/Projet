#include <stdio.h>
#include <stdlib.h>
#include "grille.h"

#define L 7 // nombre de lignes
#define C 7 // nombre de colonnes

int main(){

    // Grille du puissance 4 sous forme de matrice :
    int mat[L][C];
    grille_t unTest = creerGrille(mat);
    unTest->initGrille(unTest);
    unTest->affGrille(unTest);

    return 0;

}