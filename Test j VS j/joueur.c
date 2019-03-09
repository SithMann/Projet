#include <stdlib.h>
#include <stdio.h>
#include "joueur.h"

/* affichage d'un objet de type t_piece*/
void afficherPiece(t_piece * piece, t_joueur joueur){

    switch(joueur.couleur){         // Pour afficher la couleur de la pièce
        case RED: printf("\033[41m");
                 break;
        case YELLOW: printf("\033[43m");
                 break;
        case BLUE: printf("\033[44m");
                 break;
        case GREEN: printf("\033[42m");
                 break;
        case WHITE: printf("\033[47m");
                 break;
        case PINK: printf("\033[45m");
                 break;
    }
    printf("%d", piece->type);    // Pour préciser à qui appartient la pièce
    printf("\033[0m"); //Reset de la couleur
}

t_joueur *creer_joueurs(int nbJ, t_joueur * joueur, int nb_piece_b_f, int nb_piece_p_f, int nb_piece_c_f){
    joueur = malloc(sizeof(t_joueur)*nbJ);

    for(int i = 0; i < nbJ; i++){
        joueur[i].piece = malloc(sizeof(t_piece)*3);
        joueur[i].piece[0] = creerPiece(1, nb_piece_p_f);
        joueur[i].piece[1] = creerPiece(2, nb_piece_c_f);
        joueur[i].piece[2] = creerPiece(3, nb_piece_b_f);
    }
    return joueur;
}