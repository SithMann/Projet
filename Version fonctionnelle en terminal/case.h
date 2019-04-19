#ifndef __CASE_H__
#define __CASE_H__

#include <stdio.h>
#include <stdlib.h>
#include "objet.h"
#include "place.h"

/**
* \file case.h
* \author Mathis Despres et Noémie Farizon
* \date 15 mars 2019
* \version finale
*/

/* Structure représentant une case dans la grille, elle contient deux slots pour des pieces
 * Chaque slot stock un joueur et un type de piece.
 */
typedef struct s_case{
    #include "attributs_objet.h"
    t_place *slot1;
    t_place *slot2; 
}t_case;

t_case * creer_case();

#endif
