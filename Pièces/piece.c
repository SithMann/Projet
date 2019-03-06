#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "piece.h"



/* affichage d'un objet de type t_piece*/
void afficherPiece(t_piece * piece){

    switch(piece->joueur.couleur){         // Pour afficher la couleur de la pièce
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

/* creation d'un objet de type t_piece */
t_piece creerPiece(int type, int nb, t_joueur joueur){

    t_piece *piece = NULL;
    piece = malloc(sizeof(t_piece));
    piece->type = type;
    piece->nbpieces = nb;
    piece->joueur = joueur;
    return *piece;
}

/*destruction d'un objet piece (à revoir) */
void detruirePiece(t_piece *piece){
    piece->type = NULL;
    piece->nbpieces = NULL;
    //piece->joueur = NULL;
    free(piece);
}