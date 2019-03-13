#include <stdio.h>
#include <stdlib.h>
#include "piece.h"


/*
*Fonction qui crée une pièce (son type et le nombre) et qui retourne la pièce complétée
*/ 
t_piece * creerPiece(int type, int nbpieces){
    t_piece * piece = malloc(sizeof(piece));
    t_piece->type = type;
    t_piece->nbpieces = nbpieces;

    return (piece);
}