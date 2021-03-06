#include <stdio.h>
#include <stdlib.h>
#include "jeu.h"
#include "grille.h"

/**
* \file menu.c 
* \author Clement Dubois 
* \date 5 mars 2019
* \version finale
*/

/**
* \fn menu_joueur 
* \param deux pointeurs sur des entiers, pour le nombre de ligne et le nombre de colonnes 
* \return la fonction ne retourne rien 
* \brief cette fonction affiche le menu de selection du debut du jeu
*/
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

    /*
    *Réattribution des valeurs à niveau en vue des calculs 
    *du nombre de lignes et de colonnes
    */
    if(niveau == 1) niveau = 10; 
    if(niveau == 2) niveau = 8;
    if(niveau == 3) niveau = 6;

    *nb_ligne = nb_joueur * (nb_pion / 2) + niveau;
    *nb_colonne = nb_joueur * (nb_pion / 2) + niveau;

    fprintf(stderr,"nb ligne %d,nb colonne %d", *nb_ligne, *nb_colonne);

    nb_case = (*nb_ligne) * (*nb_colonne);

    nb_piece_c = (nb_case / nb_joueur) * 1.75 ;
    nb_piece_p = (nb_case / nb_joueur) * 1.75 ; 
    nb_piece_b = nb_case - (nb_piece_c + nb_piece_p);

    int res;
    /*Comme c'est un calcul de float, j'ajoute un si c'est arrondi en dessous*/
    if((res = ((int)nb_piece_c + (int)nb_piece_p + (int)nb_piece_b)) != (int)nb_case)
        nb_piece_b++;

    /*Création de la grille avec le nb de lignes et colonnes  calculées*/
    t_grille * grille = creer_grille(/**nb_ligne*/6, /**nb_colonne*/7, sizeof(t_case*));

    /*Boucle qui crée les joueurs avec leur numéro et le nb de pièces de chaque type*/
    t_joueur * joueur = malloc(sizeof(t_joueur)*nb_joueur);

    for(int i = 0; i < nb_joueur; i++){
        joueur[i] = creer_joueur(i+1, nb_piece_b, nb_piece_p, nb_piece_c);
    }

    joueurVSjoueur(grille, joueur, nb_joueur, nb_pion);
}

/**
* \fn menu_joueur 
* \param deux pointeurs sur des entiers, pour le nombre de ligne et le nombre de colonnes 
* \return la fonction ne retourne rien 
* \brief cette fonction affiche le menu de selection du debut du jeu
*/
void menu_joueur_ia(int * nb_ligne, int * nb_colonne){
    int niveau;/*Choix du niveau*/
    int nb_pion;/*Nombre de pions à aligner qui influence sur la taille de la grille*/
    int nb_joueur;/*Nombres de joueurs qui influence aussi la taille de la grille*/
    int nb_bots;
    float nb_case = 0;
    float nb_piece_b; // Pièces bloquantes
    float nb_piece_p; // Pièces pleines
    float nb_piece_c; // Pièces creuses

    do{
        printf("Nombres de joueurs : ");
        printf("\n\t1- 1 joueurs");
        printf("\n\t2- 2 joueurs");
        printf("\n\t3- 3 joueurs");

        printf("\nChoix du nombre de joueurs : ");
        scanf("%d", &nb_joueur);
        if(nb_joueur < 1 || nb_joueur > 3) printf("Le choix doit être compris entre 1 et 3\n");
    }while(nb_joueur < 1 || nb_joueur > 3);
        
    do{
        printf("Nombres de bots : ");
        printf("\n\t1- %d bots", 4-nb_joueur);
        printf("\n\t2- %d bots", 5-nb_joueur);
        printf("\n\t3- %d bots", 6-nb_joueur);

        printf("\nChoix du nombre de bots : ");
        scanf("%d", &nb_bots);
        if(nb_bots < 1 || nb_bots > 3) printf("Le choix doit être compris entre 1 et 3\n");
    }while(nb_bots < 1 || nb_bots > 3);
    
    switch(nb_bots){
        case 1 : nb_bots = 4-nb_joueur;
                 break;
        case 2 : nb_bots = 5-nb_joueur;
                 break;
        case 3 : nb_bots = 6-nb_joueur;
                 break;
        default : fprintf(stderr,"Erreur\n");break;
    }

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

    /*
    *Réattribution des valeurs à niveau en vue des calculs 
    *du nombre de lignes et de colonnes
    */
    if(niveau == 1) niveau = 10; 
    if(niveau == 2) niveau = 8;
    if(niveau == 3) niveau = 6;

    *nb_ligne = nb_joueur * (nb_pion / 2) + niveau;
    *nb_colonne = nb_joueur * (nb_pion / 2) + niveau;

    fprintf(stderr,"nb ligne %d,nb colonne %d", *nb_ligne, *nb_colonne);

    nb_case = (*nb_ligne) * (*nb_colonne);

    nb_piece_c = (nb_case / nb_joueur) * 1.75 ;
    nb_piece_p = (nb_case / nb_joueur) * 1.75 ; 
    nb_piece_b = nb_case - (nb_piece_c + nb_piece_p);

    int res;
    /*Comme c'est un calcul de float, j'ajoute un si c'est arrondi en dessous*/
    if((res = ((int)nb_piece_c + (int)nb_piece_p + (int)nb_piece_b)) != (int)nb_case)
        nb_piece_b++;

    /*Création de la grille avec le nb de lignes et colonnes  calculées*/
    t_grille * grille = creer_grille(/**nb_ligne*/6, /**nb_colonne*/7, sizeof(t_case*));

    /*Boucle qui crée les joueurs avec leur numéro et le nb de pièces de chaque type*/
    t_joueur * joueur = malloc(sizeof(t_joueur)*nb_joueur);
    int i;
    for(i = 0; i < nb_bots+nb_joueur; i++){
        joueur[i] = creer_joueur(i+1, nb_piece_b, nb_piece_p, nb_piece_c);
    }
    for(i = 0; i < nb_bots; i++){
        joueur[i].estHumain = 0;
    }
    fprintf(stderr,"ICI\n");
    joueurVSia(grille, joueur, nb_joueur, nb_bots, nb_pion);
}

