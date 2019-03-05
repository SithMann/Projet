#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "piece.h"

int main(){
    t_piece piece = creerPiece(1,10, 'R', 'A');
    afficherPiece(&piece);
    return 0;
}