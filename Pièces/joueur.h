#include <stdlib.h>
#include <stdio.h>

/**
* \file joueur.h
* \author Mathis Despres
* \date 7 mars 2019
*/

/**
* \typedef enum
* \enum e_couleur
* \brief structure qui regroupe l'ensemble des couleurs possible que le joueur peut choisir pour ses pieces
* */
typedef enum e_couleur{RED,BLUE,GREEN,YELLOW,WHITE,PINK}t_couleur;

/**
* \typedef struct
* \struct s_joueur
* \brief structure qui permet de sauvegarder les informations relatives au joueur tel que le score...
* */
typedef struct s_joueur{
    char * pseudo;
    int nbWin;
    int nJoueur;
    t_couleur couleur;
}t_joueur;
