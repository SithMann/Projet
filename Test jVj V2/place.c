#include <stdio.h>
#include <stdlib.h>
#include "place.h"


/* Fonction qui affiche la couleur et le type de pièce d'un joueur
*/
static
void afficher_place(t_place * espace){
    printf("%s", espace->joueur->couleur);
    printf("%d", espace->piece->type);
}

/* Fonction qui crée(alloue la mémoire) un slot dans une case de la grille de jeu 
 * Renvoie un pointeur sur un slot
 */
extern
t_place * creer_place(){
    t_place * place = malloc(sizeof(t_place));
    place->joueur = NULL;
    place->piece = NULL;

    place->p_affiche = (void (*) (t_objet *))afficher_place;

    return (place);
}