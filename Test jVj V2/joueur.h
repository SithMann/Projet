#ifndef __JOUEUR_H__
#define __JOUEUR_H__

#include <stdlib.h>
#include <stdio.h> 


typedef enum e_couleur{RED,BLUE,GREEN,YELLOW,WHITE,PINK}t_couleur;
typedef enum {PLEINE, CREUSE, BLOQUANTE } t_piece;

typedef struct s_joueur{
    char pseudo[15];//temporaire
    //int nbWin;
    int nJoueur;
    t_couleur couleur;
    int * piece;
}t_joueur;

t_joueur creer_joueur(int nbJ, int nb_piece_b, int nb_piece_p, int nb_piece_c);

#endif