#include <stdio.h>
#include <stdlib.h>
#include "case.h"

static
void afficher_case(t_case * laCase){
    if(laCase->slot1->joueur != NULL){

        laCase->slot1->p_affiche((t_objet *)laCase->slot1);

    } //else { printf("SLOT1 VIDE");}
    if(laCase->slot2->joueur != NULL)
        laCase->slot2->p_affiche((t_objet *)laCase->slot2);
    //else {        printf("SLOT2 VIDE");    }
    //printf("\n");
}

extern
t_case * creer_case(){
    t_case * lacase = malloc(sizeof(t_case));
    lacase->slot1 = creer_place();
    lacase->slot2 = creer_place();

    lacase->p_affiche = (void (*) (t_objet *))afficher_case;

    return (lacase);
}
