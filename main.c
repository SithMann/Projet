<<<<<<< HEAD
#include <stdlib.h>
#include <stdio.h>

#define L 7
#define C 7

/* Initialisation de la grille
*/
void init_grille(char grille[L][C]){
    for(int i = 0; i < L; i++){
        for(int j = 0; j < C; j++)
            grille[i][j] = ' ';
    }
}

/*Affichage de la grille 
*/
void afficher_grille(char grille[L][C]){
    for(int i = 0; i < L; i++){
        for(int j = 0; j < C; j++)
            printf("%c |", grille[i][j]);
        printf("\n");            
    }
}

/* Fonction qui fait jouer un joueur. Demande la saisie de la colonne et de la piece.
 * Met à jour la grille et ne renvoie rien.
*/
void tour_joueur(int nJoueur, char grille[L][C]){
    int col, piece;

    /* Demande de saisie de la colonne. Penser à vérifier que col est un entier plus tard. */
    do{
        printf("Veuillez hoisir le numéro de la colonne pour jouer (entier entre 1 et 7): ");
        scanf("%d", &col);
    }while(nonPleine(col) && col > 0 && col < 8);

    /* Demande de saisie de la piece. Penser à vérifier que piece est un entier plus tard.
     * Il faudrat aussi prendre en compte le nombre disponible de chaque piece pour la suite.
    */
    do{
        printf("Choix : ");
        scanf("%d", &piece);
    }while(piece > 0 && piece < 4);
}
 
void joueurVSjoueur(char grille[L][C]){

}
/*
void joueurVSia(char grille[L][C]){

}*/

int main(){

    char grille[L][C];
    int choix;
    
    printf("Selectionnez le mode de jeu : \n");
    printf("1- Joueur vs IA \n");
    printf("2- Joueur vs Joueur \n");
    printf("3- Quitter \n");

    printf("\n\n Choix : ");
    scanf("%d", &choix);

    /*
    switch(choix){
        case 1 : joueurVSia(grille);
                break;
        case 2 : joueurVSjoueur(grille);
                break;
        case 3 :
                break;
    }*/

    return 0;
}
=======
 
>>>>>>> 57581ec736f0dc7dde8e9afdd9fd0b09e2fc4a1d
