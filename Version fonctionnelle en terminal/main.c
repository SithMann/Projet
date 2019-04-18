#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

/**
* \file main.c
* \author Mathis Despres
* \date 17 avril 2019
* \version à rendre
*/

int main(){

    int choix; /*Choix du joueur pour le début du jeu*/
    int nb_ligne = 0;
    int nb_colonne = 0;

    while(choix != 3){
        printf("\n\n");
        printf("Selectionnez le mode de jeu : \n");
        printf("1- Joueur vs IA \n");
        printf("2- Joueur vs Joueur \n");
        printf("3- Quitter \n");

        printf("\n\n Choix : ");
        scanf("%d", &choix);

        switch(choix){
            case 1 : menu_joueur_ia(&nb_ligne, &nb_colonne);
                    break;
            case 2 : menu_joueur(&nb_ligne, &nb_colonne);
                    break;
            default : printf("Aurevoir ! \n");
                    break;
        }
    }
    return 0;
}

