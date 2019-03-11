#ifndef __PLACE_H__
#define __PLACE_H__

#include <stdio.h>
#include <stdlib.h>

/* Structure représentant une place dans une case de la grille (car plusiseurs pièces peuvent se situées sur la même case)
 * Sauvegarde du joueur et de la piece pour avoir accès à la couleur et au type.
 */
typedef struct s_place{
    t_joueur * joueur;
    t_piece * piece;
}t_place;

t_place * creer_place();

#endif