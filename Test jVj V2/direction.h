#ifndef __DIRECTION_H__
#define __DIRECTION_H__

#include <stdio.h>
#include <stdlib.h>
#include "jeu.h"

/**
* \file direction.h
* \author Clement Dubois
* \date 16 mars 2019
* \version 1
*/

/**
* \typedef enumeration
* \enum t_direction
* \brief contient l'ensemble des directions possibles 
*/
typedef enum { NORD, NORDEST, EST, SUDEST, SUD, SUDOUEST, OUEST, NORDOUEST } t_direction;
const int NB_DIRECTION=8;

int direction_avancer(int i, int j, t_direction dir, int nb_pas/*, int *ni, int*nj*/, t_grille * grille);
t_direction direction_suivante(t_direction dir);
t_direction direction_debut();

#endif
