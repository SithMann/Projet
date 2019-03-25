#ifndef __JOUEUR_H__
#define __JOUEUR_H__

#include <stdlib.h>
#include <stdio.h> 

/**
* \file joueur.h 
* \author Mathis Despres 
* \date 6 mars 2019
* \version 2
*/

/**
* \typedef enumeration
* \enum t_couleur
* \brief reunie l'ensemble des couleurs possibles 
*/
typedef enum e_couleur{NOCOLOR, RED,BLUE,GREEN,YELLOW,WHITE,PINK}t_couleur;
/**
* \typedef enumeration 
* \enum t_piece
* \brief reunie l'ensemble des types de pieces possibles 
*/
typedef enum {PLEINE, CREUSE, BLOQUANTE, VIDE } t_piece;

/**
* \typedef structure
* \struct t_joueur 
* \brief permet de stocker l'ensemble des informations relatives a un joueur
*/
typedef struct s_joueur{
    char pseudo[15];//temporaire
    //int nbWin;
    int estHumain;
    int nJoueur;
    t_couleur couleur;
    int * piece;
}t_joueur;

int saisir_type(t_joueur * joueur);
t_joueur creer_joueur(int nbJ, int nb_piece_b, int nb_piece_p, int nb_piece_c);

#endif
