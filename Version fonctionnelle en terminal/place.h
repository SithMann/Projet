#ifndef __PLACE_H__
#define __PLACE_H__

#include <stdio.h>
#include <stdlib.h>
#include "objet.h"
#include "joueur.h"

/**
* \file place.h
* \author Mathis Despres
* \date 17 avril 2019
* \version à rendre
*/

/**
* \typedef structure
* \struct t_place 
* \brief represente une place dans une case de la grille, car il y a plusieurs pieces qui peuvent se trouver dans la meme case. elle sauvegarde le joueur et la piece pour avoir acces a la couleur et au type de la piece.
*/
typedef struct s_place{
    #include "attributs_objet.h"
    t_joueur * joueur;
    t_piece piece;
}t_place;

t_place * creer_place();

#endif
