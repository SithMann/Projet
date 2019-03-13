#ifndef __PIECE_H__
#define __PIECE_H__

#include <stdlib.h>
#include <stdio.h>

typedef enum { PLEINE, CREUSE, BLOQUANTE } t_piece;

/* Structure d'une pièce */
typedef struct s_piece{
    int nbpieces; // Le nombre
    int type; // 1, 2, 3 pour (pleine, creuse, bloquante)
}t_piece;

t_piece * creerPiece(int type, int nb);

#endif