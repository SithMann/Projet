#include <stdio.h>
#include <stdlib.h>
#include "case.h"

void afficher_case(t_case * laCase){
    if(laCase->slot1 != NULL)
        laCase->slot1->piece->p_affiche()
}

t_case * creer_case(){
    t_case * lacase = malloc(sizeof(t_case));
    lacase->slot1 = NULL;
    lacase->slot2 = NULL;

    return (lacase);
}