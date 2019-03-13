#ifndef __JOUEUR_H__
#define __JOUEUR_H__

#include <stdlib.h>
#include <stdio.h> 
#include "piece.h"

typedef enum e_couleur{RED,BLUE,GREEN,YELLOW,WHITE,PINK}t_couleur;

typedef struct s_joueur{
    char pseudo[15];//temporaire
    //int nbWin;
    int nJoueur;
    t_couleur couleur;
    t_piece * piece;
}t_joueur;

t_joueur creer_joueur(int nbJ, int nb_piece_b_f, int nb_piece_p_f, int nb_piece_c_f);

#endif