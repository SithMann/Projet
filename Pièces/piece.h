#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

/* Structure d'une pièce */
typedef struct s_piece{
    int nbpieces; // Le nombre
    int type; // 1, 2, 3 pour (pleine, creuse, bloquante)
    char couleur;// dans le pt sur joueur char couleur; // R,Y,B,G,W,P 
    char joueur;// pt sur joueur; // A,B,C,D etc...
}t_piece;

void afficherPiece(t_piece *piece);
t_piece creerPiece(int type, int nb, char couleur, char joueur);
void detruirePiece(t_piece *piece);