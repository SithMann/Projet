#ifndef __DIRECTION_H__
#define __DIRECTION_H__

#include <stdio.h>
#include <stdlib.h>
#include "grille.h"

typedef enum { NORD, NORDEST, EST, SUDEST, SUD, SUDOUEST, OUEST, NORDOUEST } t_direction;

int direction_avancer(int i, int j, t_direction dir, int nb_pas/*, int *ni, int*nj*/, t_grille * grille);
t_direction direction_suivante(t_direction dir);
t_direction direction_debut();

#endif