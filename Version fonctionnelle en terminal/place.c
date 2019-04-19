#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "place.h"

/**
* \file place.c
* \author Mathis Despres
* \date 9 mars 2019
* \version finale
*/

/**
* \fn afficher_place 
* \param un pointeur sur une place 
* \return la fonction ne retourne rien 
* \brief cette fonction affiche la couleur et le type de piece d'un joueur 
*/
static
void afficher_place(t_place * espace){
    switch(espace->joueur->couleur){
        case RED: printf("\033[41m");
                 break;
        case YELLOW: printf("\033[43m");
                 break;
        case BLUE: printf("\033[44m");
                 break;
        case GREEN: printf("\033[42m");
                 break;
        case WHITE: printf("\033[47m");
                 break;
        case PINK: printf("\033[45m");
                 break;
        default:
                printf("\033[40m"); 
                break;
    }
    printf("%d", espace->piece);
    printf("\033[0m"); // Reset de la couleur par defaut
}

/**
* \fn creer_place 
* \param la focntion ne prend rien en parametres
* \return la fonction retourne un pointeur sur un slot
* \brief cette fonction alloue de la memoire pour un slot dans une case de la grille de jeu.
*/
extern
t_place * creer_place(){
    t_place * place = malloc(sizeof(t_place));
    place->joueur = NULL;
    place->piece = VIDE;

    place->p_affiche = (void (*) (t_objet *))afficher_place;

    return (place);
}
