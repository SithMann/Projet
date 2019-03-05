#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "piece.h"



/* affichage d'un objet de type t_piece*/
void afficherPiece(t_piece * piece){

    switch(piece->couleur){         // Pour afficher la couleur de la pièce
        case 'R': printf("\033[41m");
                 break;
        case 'Y': printf("\033[43m");
                 break;
        case 'B': printf("\033[44m");
                 break;
        case 'G': printf("\033[42m");
                 break;
        case 'W': printf("\033[47m");
                 break;
        case 'P': printf("\033[45m");
                 break;
    }
    printf("%c", piece->joueur);    // Pour préciser à qui appartient la pièce
    printf("\033[0m"); //Reset de la couleur
}

/* creation d'un objet de type t_piece */
t_piece creerPiece(int type, int nb, char couleur, char joueur){

    t_piece *piece = NULL;
    piece = malloc(sizeof(t_piece));
    piece->type = type;
    piece->nbpieces = nb;
    piece->couleur = couleur;
    piece->joueur = joueur;
    return *piece;
}

void detruirePiece(t_piece piece){

}