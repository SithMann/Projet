#include <stdlib.h>
#include <stdio.h> 
#include "joueur.h"


t_joueur creer_joueur(int nJoueur, int nb_piece_b_f, int nb_piece_p_f, int nb_piece_c_f){
    t_joueur joueur;

    joueur.piece = malloc(sizeof(t_piece)*3);
    joueur.piece[PLEINE] = nb_piece_p_f;
    joueur.piece[CREUSE] = nb_piece_c_f;
    joueur.piece[BLOQUANTE] = nb_piece_b_f;

    joueur.nJoueur = nJoueur;
    joueur.couleur = 0; // peut être à changer
    
    return joueur;
}