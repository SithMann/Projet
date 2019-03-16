#ifndef __JOUEUR_H__
#define __JOUEUR_H__

#include <stdlib.h>
#include <stdio.h> 


typedef enum e_couleur{NOCOLOR, RED,BLUE,GREEN,YELLOW,WHITE,PINK}t_couleur;
typedef enum {PLEINE, CREUSE, BLOQUANTE, VIDE } t_piece;

typedef struct s_joueur{
    char pseudo[15];//temporaire
    //int nbWin;
    int nJoueur;
    t_couleur couleur;
    int * piece;
}t_joueur;

int saisir_type(t_joueur * joueur);
t_joueur creer_joueur(int nbJ, int nb_piece_b, int nb_piece_p, int nb_piece_c);

#endif