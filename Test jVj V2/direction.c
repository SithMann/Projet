#include <stdio.h>
#include <stdlib.h>
#include "direction.h"

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

t_direction direction_suivante(t_direction dir){
    return (dir + 1) % NB_DIRECTION;
}

t_direction direction_debut(){
    return NORD;
}