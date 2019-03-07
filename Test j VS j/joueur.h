#ifndef __JOUEUR_H__
#define __JOUEUR_H__

#include <stdlib.h>
#include <stdio.h>

typedef enum e_couleur{RED,BLUE,GREEN,YELLOW,WHITE,PINK}t_couleur;

typedef struct s_joueur{
    //char * pseudo;
    char pseudo[15];//temporaire
    int nbWin;
    int nJoueur;
    t_couleur couleur;
}t_joueur;

#endif