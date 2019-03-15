#include <stdlib.h>
#include <stdio.h> 
#include "joueur.h"


<<<<<<< HEAD

t_joueur creer_joueur(int nJoueur, int nb_piece_b_f, int nb_piece_p_f, int nb_piece_c_f){
    t_joueur joueur;

    joueur.piece = malloc(sizeof(t_piece)*3);
    joueur.piece[PLEINE] = nb_piece_p_f;
    joueur.piece[CREUSE] = nb_piece_c_f;
    joueur.piece[BLOQUANTE] = nb_piece_b_f;


    joueur.nJoueur = nJoueur;
    joueur.couleur = NOCOLOR; // TODO peut être à changer
=======
t_joueur creer_joueur(int nJoueur, int nb_piece_b, int nb_piece_p, int nb_piece_c){
    t_joueur * joueur = malloc(sizeof(t_joueur));

    joueur->piece = malloc(sizeof(t_piece)*3);
    joueur->piece[PLEINE] = nb_piece_p;
    joueur->piece[CREUSE] = nb_piece_c;
    joueur->piece[BLOQUANTE] = nb_piece_b;

    joueur->nJoueur = nJoueur;
    joueur->couleur = 0; // peut être à changer
>>>>>>> f7f17ebe0b0871578498c10f70e02666f47ca9d0
    
    return *joueur;
}