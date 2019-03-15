#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

int main(){

    int choix; /*Choix du joueur pour le début du jeu*/
    int nb_ligne = 0;
    int nb_colonne = 0;

    while(1){
        printf("Selectionnez le mode de jeu : \n");
        printf("1- Joueur vs IA \n");
        printf("2- Joueur vs Joueur \n");
        printf("3- Quitter \n");

        printf("\n\n Choix : ");
        scanf("%d", &choix);

        switch(choix){
            case 1 : /*joueurVSia(grille);*/
                    printf("En dev !");
                    break;
            case 2 : menu_joueur(&nb_ligne, &nb_colonne);
                    break;
            case 3 : exit(1);
                    break;
        }
    }
    return 0;
}

