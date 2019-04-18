#ifndef __DIRECTION_H__
#define __DIRECTION_H__

#include <stdio.h>
#include <stdlib.h>
#include "jeu.h"

/**
* \file direction.h
* \author Mathis Despres
* \date 17 avril 2019
* \version à rendre
*/

/**
* \typedef enumeration
* \enum t_direction
* \brief contient l'ensemble des directions possibles 
*/
#define NB_DIRECTION 8

typedef enum { NORD=0, NORDEST, EST, SUDEST, SUD, SUDOUEST, OUEST, NORDOUEST } t_direction;

int direction_avancer(int i, int j, t_direction dir, int *ni, int*nj, t_grille * grille);
t_direction direction_suivante(t_direction dir);
t_direction direction_debut();

#endif
