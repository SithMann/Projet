#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

/* Structure d'une pièce */
typedef struct pieces_s{
    int nbpieces; // Le nombre
    int type; // 1, 2, 3 pour (pleine, creuse, bloquante)
    char *couleur;
}pieces_t;

void afficherPiece(pieces_t piece);
pieces_t creerPiece(int type, int nb, char *couleur);
void detruirePiece(pieces_t piece);