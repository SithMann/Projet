#include <stdio.h>
#include <stdlib.h>
#include "direction.h"

/**
* \file direction.c
* \author Mathis Despres
* \date 17 avril 2019
* \version à rendre
*/

/**
* \fn direction_avancer
* \param deux entiers i et j (indicage), une direction dir, un entier pour le nombre de pas, un pointeur sur une grille
* \return la fonction retourne un entier  
*/

//modifie les valeurs de l'appelant pour *ni, *nj
int direction_avancer(int i, int j, t_direction dir, int *ni, int*nj, t_grille * grille){ // enlever grille useless
    //Déplacement des coords de la case
    switch(dir){
        case NORD : *ni = i - 1;
                    *nj = j;
                    break;
        case NORDEST : *ni = i - 1;
                        *nj = j + 1;
                    break;
        case EST : *ni  = i;
                    *nj = j + 1;
                    break;
        case SUDEST : *ni = i + 1;
                        *nj = j + 1;
                    break;
        case SUD : *ni = i + 1;
                    *nj = j;
                    break;
        case SUDOUEST : *ni = i + 1;
                        *nj = j + 1;
                    break;
        case OUEST : *ni = i;
                        *nj = j - 1;
                    break;
        case NORDOUEST : *ni = i - 1;
                            *nj = j - 1;
                    break;
        default : 
            fprintf(stderr, "Erreur");
            break;
    }

    return 0;
}

/**
* \fn direction_suivante
* \param une direction dir 
* \return la fonction retourne une direction
*/
t_direction direction_suivante(t_direction dir){
    return (dir + 1) % NB_DIRECTION;
}

/**
* \fn direction_debut
* \param la fonction ne prend pas de parametres
* \return la fonction retourne une direction 
*/
t_direction direction_debut(){
    return NORD;
}
