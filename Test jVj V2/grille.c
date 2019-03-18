#include <stdio.h>
#include <stdlib.h>
#include "grille.h"

/**
* \file grille.c
* \author Noemie Farizon et Mathis Despres
* \date 15 mars 2019
* \version 2
*/

/**
* \fn lire_piece_slot
* \param trois entiers x, y (indicage) et le numero du slot, un pointeur sur grille
* \return la fonction retourne une piece
*/
t_piece lire_piece_slot(int x, int y, int nSlot, t_grille * grille){
    if(nSlot == 1)
        return (grille->laGrille[x][y]->slot1->piece);
    if(nSlot == 2)
        return (grille->laGrille[x][y]->slot2->piece);

    return VIDE;
}

/**
* \fn lire_couleur_joueur_slot
* \param trois entiers x, y (indicage) et le numero du slot, un pointeur sur grille
* \return la fonction retourne une couleur 
*/
t_couleur lire_couleur_joueur_slot(int x, int y, int nSlot, t_grille * grille){

    fprintf(stderr, "cPremier : \n");

    if(nSlot == 1 && grille->laGrille[x][y]->slot1->joueur != NULL){
        fprintf(stderr, "couleur 1 : ");
        fprintf(stderr, "%d \n", grille->laGrille[x][y]->slot1->joueur->couleur);
        return (grille->laGrille[x][y]->slot1->joueur->couleur);
    if(nSlot == 2)
        return (grille->laGrille[x][y]->slot2->joueur->couleur);

    return NOCOLOR;
}

/**
* \fn afficher_grille 
* \param un poinrteur sur grille 
* \return la fonction ne retourne rien 
* \brief cette fonction affiche la grille de jeu,n parcours les cases et appelle la fonction d'affichage des cases
*/
static
void afficher_grille(t_grille * grille){
    int i, j;
    for(i=0; i< grille->longueur; i++){
        for(j=0; j< grille->largeur; j++){
            printf("|");
            if(grille->laGrille[i][j]->slot1->joueur != NULL){
                grille->laGrille[i][j]->p_affiche((t_objet *)(grille->laGrille[i][j]));
            }
            printf("\t");
        }
        printf("\n");
    }
}

/**
* \fn ajouter_piece 
* \param deux entier x et y (indicage), un pointeur sur grille, une piece, un pointeur sur un joueur
* \return la fonction ne retourne rien 
*/
extern
void ajouter_piece(int x, int y, t_grille * grille, t_piece piece, t_joueur* pjoueur){
    char c;
    if(grille->laGrille[x][y]->slot1->joueur == NULL){
        grille->laGrille[x][y]->slot1->piece = piece;
        grille->laGrille[x][y]->slot1->joueur = pjoueur;
        fprintf(stderr, "Pièce ajoutée en slot1\n");
    }
    else{
        grille->laGrille[x][y]->slot2->piece = piece;
        grille->laGrille[x][y]->slot2->joueur = pjoueur;
        fprintf(stderr, "Pièce ajoutée en slot2\n");
    }
}

/**
* \fn creer_grille 
* \param trois entiers longueur,largeur et taille
* \return la fonction retourne un pointeur sur une grille 
* \brief cette fonction creer une matrice qui sera la grille de jeu (alloue la memoire)
*/
extern
t_grille * creer_grille(int longueur, int largeur, int taille){
    t_grille * grille = malloc(sizeof(t_grille));
    grille->laGrille = malloc(sizeof(*(grille->laGrille))*longueur);
    for (int i = 0; i < longueur; i++) {
        grille->laGrille[i]=malloc(sizeof(*(grille->laGrille[i]))*largeur);
    }
    for(int i = 0; i < longueur; i++){
        for(int j = 0; j < largeur; j++){
            grille->laGrille[i][j] = creer_case();
        }
    }
    grille->longueur = longueur;
    grille->largeur = largeur;
    grille->p_affiche = (void (*) (t_objet *))afficher_grille;
    return (grille);
}

/**
* \fn detruire_grille
* \param un pointeur sur grille
* \return la fonction ne retourne rien
* \brief cette fonction libere l'espace alloue a la grille 
*/
extern
void detruire_grille(t_grille * grille){
      free(grille->laGrille);
      free(grille);
      grille = NULL;
}
