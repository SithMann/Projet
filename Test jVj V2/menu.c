#include <stdio.h>
#include <stdlib.h>
#include "jeu.h"
#include "grille.h"


/*Fonction affichant le menu de sélection du début*/
void menu_joueur(int * nb_ligne, int * nb_colonne){
    int niveau;/*Choix du niveau*/
    int nb_pion;/*Nombre de pions à aligner qui influence sur la taille de la grille*/
    int nb_joueur;/*Nombres de joueurs qui influence aussi la taille de la grille*/
    float nb_case = 0;
    float nb_piece_b; // Pièces bloquantes
    float nb_piece_p; // Pièces pleines
    float nb_piece_c; // Pièces creuses

    do{
        printf("Nombres de joueurs : ");
        printf("\n\t1- 4 joueurs");
        printf("\n\t2- 5 joueurs");
        printf("\n\t3- 6 joueurs");

        printf("\nChoix du nombre de joueurs : ");
        scanf("%d", &nb_joueur);
        if(nb_joueur < 1 || nb_joueur > 3) printf("Le choix doit être compris entre 1 et 3\n");
    }while(nb_joueur < 1 || nb_joueur > 3);
        
    /*
    *Réattribution des valeurs à nb_joueur pour le nb_joueur en jeu, en 
    *du nombre de lignes et de colonnes
    */
    if(nb_joueur == 1) nb_joueur = 4; 
    if(nb_joueur == 2) nb_joueur = 5;
    if(nb_joueur == 3) nb_joueur = 6;
    

    do{
        printf("Nombres de pions à aligner : ");
        printf("\n\t1- 4 pions");
        printf("\n\t2- 5 pions");
        printf("\n\t3- 6 pions");

        printf("\nChoix du nombres de pions : \n");
        scanf("%d",&nb_pion);
        if(nb_pion < 1 || nb_pion > 3) printf("Le choix doit être compris entre 1 et 3\n");
    }while(nb_pion < 1 || nb_pion > 3);

     /*
    *Réattribution des valeurs à nb_pions pour le nb_pions à aligner en vue des calculs 
    *du nombre de lignes et de colonnes
    */
    if(nb_pion == 1) nb_pion = 4; 
    if(nb_pion == 2) nb_pion = 5;
    if(nb_pion == 3) nb_pion = 6;

    do{ 
        printf("\nNiveau de difficulté : ");
        printf("\n\t1- Facile");
        printf("\n\t2- Moyen");
        printf("\n\t3- Difficile");

        printf("\nChoix du niveau : ");
        scanf("%d",&niveau);
        if(niveau < 1 || niveau > 3) printf("Le choix doit être compris entre 1 et 3\n");
    }while(niveau < 1 || niveau > 3);

    *nb_ligne = nb_joueur + nb_pion * ++niveau;
    *nb_colonne = nb_joueur + nb_pion * ++niveau;

    nb_case = (*nb_ligne) * (*nb_colonne);

    nb_piece_c = (nb_case / nb_joueur) * 1.75 ;
    nb_piece_p = (nb_case / nb_joueur) * 1.75 ; 
    nb_piece_b = nb_case - (nb_piece_c + nb_piece_p);

<<<<<<< HEAD
    int res;
printf("ICI\n");
    /*Comme c'est un calcul de float, j'ajoute un si c'est arrondi en dessous*/
    if((res = ((int)nb_piece_c + (int)nb_piece_p, (int)nb_piece_b)) != (int)nb_case)
        nb_piece_b++;
printf("ICI\n");

    /*Comme c'est un calcul de float, j'ajoute un si c'est arrondi en dessous*/
    if((nb_piece_b + nb_piece_c + nb_piece_p) != (int)nb_case)
        nb_piece_b++;

=======
    int nb_piece_b_f = (int)nb_piece_b; // Pièces bloquantes
    int nb_piece_p_f = (int)nb_piece_p; // Pièces pleines
    int nb_piece_c_f = (int)nb_piece_c; // Pièces creuses

    /*Comme c'est un calcul de float, j'ajoute un si c'est arrondi en dessous*/
    if(((int)nb_piece_b_f + (int)nb_piece_c_f + (int)nb_piece_p_f) != (int)nb_case)
        (nb_piece_b_f)++;
>>>>>>> c9a4a9c41d4e8f580573b73431f61e1225913cb1


    /*Création de la grille avec le nb de lignes et colonnes  calculées*/
    t_grille * grille = creer_grille(*nb_ligne, *nb_colonne, sizeof(t_case*));

    /*Boucle qui crée les joueurs avec leur numéro et le nb de pièces de chaque type*/
    t_joueur *joueur = malloc(sizeof(t_joueur)*nb_joueur);

    for(int i = 0; i < nb_joueur; i++){
<<<<<<< HEAD
        joueur[i] = creer_joueur(i+1, nb_piece_b, nb_piece_p, nb_piece_c);
=======
        joueur[i] = creer_joueur(i+1, nb_piece_b_f, nb_piece_p_f, nb_piece_c_f);
>>>>>>> c9a4a9c41d4e8f580573b73431f61e1225913cb1
    }

    joueurVSjoueur(grille, joueur, nb_joueur);
}