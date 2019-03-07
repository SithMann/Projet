#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "piece.h"

/* creation d'un objet de type t_piece */
t_piece creerPiece(int type, int nb){

    t_piece *piece = NULL;
    piece = malloc(sizeof(t_piece));
    piece->type = type;
    piece->nbpieces = nb;
    return *piece;
}

/*destruction d'un objet piece (à revoir) */
void detruirePiece(t_piece *piece){
    piece->type = NULL;
    piece->nbpieces = NULL;
    free(piece);
}