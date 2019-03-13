#include <stdlib.h>
#include <stdio.h> 
#include "joueur.h"


t_joueur creer_joueur(int nJoueur, int nb_piece_b_f, int nb_piece_p_f, int nb_piece_c_f){
    t_joueur * joueur = malloc(sizeof(t_joueur));

    joueur->piece = malloc(sizeof(t_piece)*3);
    joueur->piece[0] = creerPiece(1, nb_piece_p_f);
    joueur->piece[1] = creerPiece(2, nb_piece_c_f);
    joueur->piece[2] = creerPiece(3, nb_piece_b_f);

    joueur->nJoueur = nJoueur;
    joueur->couleur = NULL;
    
    return joueur;
}