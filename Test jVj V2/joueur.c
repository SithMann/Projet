#include <stdlib.h>
#include <stdio.h> 
#include "joueur.h"

/**
* \file joueur.c 
* \author Mathis Despres
* \date 6 mars 2019
* \version 2
*/

/**
* \fn saisir_type 
* \param un pointeur sur un joueur 
* \return la focntion retourn un entier
* \brief cette fonction demande de saisir une piece et elle verrifie qu'on lui rentre bien un entier et pas autre chose 
*/
int saisir_type(t_joueur * joueur){
    int type = -1;
    do{
        printf("Choix du type de pièce à jouer : \n");
        printf("1- Pleine \n");
        printf("2- Creuse \n");
        printf("3- Bloquante \n");
        printf("Choix : ");
        scanf("%d", &type);
        if(!joueur->piece[type-1])
            printf("Plus de pieces de ce type disponible !\n");
    }while((type <= 0 && type >= 4) || !joueur->piece[type-1]);
    return type-1;
}

/**
* \fn creer_joueur 
* \param quatre entiers pour le nombre de joueurs, le nombre de pieces bloquantes finales, le nombre de pieces pleines finales et le nombre de pieces creuses finales
* \return la fonction retourn un joueur 
*/
t_joueur creer_joueur(int nJoueur, int nb_piece_b_f, int nb_piece_p_f, int nb_piece_c_f){
    t_joueur joueur;

    joueur.piece = malloc(sizeof(t_piece)*3);
    joueur.piece[PLEINE] = nb_piece_p_f;
    joueur.piece[CREUSE] = nb_piece_c_f;
    joueur.piece[BLOQUANTE] = nb_piece_b_f;


    joueur.nJoueur = nJoueur;
    joueur.couleur = NOCOLOR; // TODO peut être à changer
    
    return joueur;
}
