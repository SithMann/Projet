#ifndef __GRILLE_H__
#define __GRILLE_H__

#include <stdio.h>
#include <stdlib.h>
#include "piece.h"

typedef struct s_contenu_case{
    
}t_contenu_case;

typedef struct s_case{
    t_piece *piece1; //pointeur sur la premiere piece presente dans la case 
    t_piece *piece2; //vide si la première pièce est de type bloquante 
}t_case;

void afficher_grille();
void ajouter_piece();
t_case **init_grille();
#endif 
