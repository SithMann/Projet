#include <stdio.h>
#include <stdlib.h>
#include "case.h"

static
void afficher_case(t_case * laCase){
    printf("ICI\n");
    if(laCase->slot1->joueur != NULL){
        printf("LA\n");
        laCase->slot1->p_affiche((t_objet *)laCase->slot1);
        printf("ICI\n");
    }
    if(laCase->slot2->joueur != NULL)
        laCase->slot2->p_affiche((t_objet *)laCase->slot2);
}

extern
t_case * creer_case(){
    t_case * lacase = malloc(sizeof(t_case));
    lacase->slot1 = NULL;
    lacase->slot2 = NULL;

    lacase->p_affiche = (void (*) (t_objet *))afficher_case;

    return (lacase);
}
