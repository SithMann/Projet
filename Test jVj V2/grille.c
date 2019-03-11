#include <stdio.h>
#include <stdlib.h>
#include "grille.h"

/* Fonction d'affichage de la grille de jeu
 * parcours les cases et appelle la fonction d'affichage des cases
 */
static
void afficher_grille(int longueur, int largeur, t_grille grille){
    int i, j;
    for(i=0; i<longueur; i++){
        for(j=0; j<largeur; j++){
            printf("|");
            if(grille.laGrille[i][j]!=NULL){
                afficher_case(grille.laGrille[i][j]);
            }
            printf("\t");
        }
        printf("\n");
    }
}

/* Fonction qui crée une matrice qui sera la grille de jeu (alloue la mémoire)
 * Renvoie un pointeur sur la grille
 */
extern
t_grille * creer_grille(int longueur, int largeur, void * typeGrille){
    t_grille * grille = malloc(sizeof(t_grille));
    grille->laGrille = malloc(sizeof(typeGrille)*longueur);
    for (int i = 0; i < nbl; i++) {
        grille->laGrille[i]=malloc(sizeof(typeGrille)*largeur);
    }
    grille->longueur = longueur;
    grille->largeur = largeur;
    grille->p_affiche = (void (*) (objet_t *))afficher_grille;
    return (grille);
}

/* Libère l'espace alloué à la grille
 *
 */
extern
void detruire_grille(t_grille grille){
      free(grille->laGrille);
      free(grille);
      grille = NULL;
}