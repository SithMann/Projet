#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "place.h"


/* Fonction qui affiche la couleur et le type de pièce d'un joueur
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
}

/* Fonction qui crée(alloue la mémoire) un slot dans une case de la grille de jeu 
 * Renvoie un pointeur sur un slot
 */
extern
t_place * creer_place(){
    t_place * place = malloc(sizeof(t_place));
    place->joueur = NULL;
    place->piece = VIDE;

    place->p_affiche = (void (*) (t_objet *))afficher_place;

    return (place);
}