#include <stdio.h>
#include <stdlib.h>

#define L 7 // nombre de lignes
#define C 7 // nombre de colonnes

/* creation d une structure pour la grille */
typedef struct grille_s{
    int matrice[L][C];
    void * initGrille;
    void * affGrille;
}grille_t;

// definitions des prototypes des fonctions de la grille
extern void initialiserGrille(grille_t * laMap);
extern void afficherGrille(grille_t * laMap);
extern grille_t * creerGrille(int mat[L][C]);