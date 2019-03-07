#include <stdlib.h>
#include <stdio.h>

/**
* \file joueur.h
* \author Mathis Despres
* \date 7 mars 2019
*
* 
*/

typedef enum e_couleur{RED,BLUE,GREEN,YELLOW,WHITE,PINK}t_couleur;

typedef struct s_joueur{
    char * pseudo;
    int nbWin;
    int nJoueur;
    t_couleur couleur;
}t_joueur;
