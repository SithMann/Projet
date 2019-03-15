#include <stdlib.h>
#include <stdio.h> 
#include "joueur.h"


t_joueur creer_joueur(int nJoueur, int nb_piece_b, int nb_piece_p, int nb_piece_c){
    t_joueur * joueur = malloc(sizeof(t_joueur));

    joueur->piece = malloc(sizeof(t_piece)*3);
    joueur->piece[PLEINE] = nb_piece_p;
    joueur->piece[CREUSE] = nb_piece_c;
    joueur->piece[BLOQUANTE] = nb_piece_b;

    joueur->nJoueur = nJoueur;
    joueur->couleur = 0; // peut être à changer
    
    return *joueur;
}