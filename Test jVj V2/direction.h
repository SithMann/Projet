#include <stdio.h>
#include <stdlib.h>

typedef enum { NORD, NORDEST, EST, SUDEST, SUD, SUDOUEST, OUEST, NORDOUEST } t_direction;
const int NB_DIRECTION=8;

int direction_avancer(int i, int j, t_direction dir, int nb_pas, int *ni, int*nj){ //modifier les valeurs de l'appelant pour *ni, *nj
    int i;
    dir = direction_debut();
    for(i = 0; i < NB_DIRECTION; i++){
        //traitement si même couleur et pas hors matrice on continue
        dir = direction_suivante(dir);
    }
}

t_direction direction_suivante(t_direction dir);

t_direction direction_debut(){
    return NORD;
}

