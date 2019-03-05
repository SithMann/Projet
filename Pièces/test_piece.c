#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "piece.h"

int main(){
    t_piece piece = creerPiece(1,10, 'R', 'A');
    printf("Une piece : ");
    afficherPiece(&piece);
    printf("\n");
    return 0;
}