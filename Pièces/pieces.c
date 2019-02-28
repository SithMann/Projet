#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "piece.h"



/* affichage d'un objet de type pieces_t*/
void afficherPiece(pieces_t piece){
    printf("Nothing atm\n");
}

/* creation d'un objet de type pieces_t */
pieces_t creerPiece(int type, int nb, char *couleur){

    pieces_t *piece = NULL;
    piece = malloc(sizeof(piece_t));
    piece->type = type;
    piece->nb = nb;
    strcpy(piece->couleur, couleur);

    return piece;
}