#include <stdlib.h>
#include <stdio.h> 
#include "joueur.h"


<<<<<<< HEAD
t_joueur creer_joueur(int nJoueur, int nb_piece_b, int nb_piece_p, int nb_piece_c){
    t_joueur * joueur = malloc(sizeof(t_joueur));

    joueur->piece = malloc(sizeof(t_piece)*3);
    joueur->piece[PLEINE] = nb_piece_p;
    joueur->piece[CREUSE] = nb_piece_c;
    joueur->piece[BLOQUANTE] = nb_piece_b;
=======
t_joueur creer_joueur(int nJoueur, int nb_piece_b_f, int nb_piece_p_f, int nb_piece_c_f){
    t_joueur joueur;

    joueur.piece = malloc(sizeof(t_piece)*3);
    joueur.piece[PLEINE] = nb_piece_p_f;
    joueur.piece[CREUSE] = nb_piece_c_f;
    joueur.piece[BLOQUANTE] = nb_piece_b_f;
>>>>>>> c9a4a9c41d4e8f580573b73431f61e1225913cb1

    joueur.nJoueur = nJoueur;
    joueur.couleur = 0; // peut être à changer
    
    return joueur;
}