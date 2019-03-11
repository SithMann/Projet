#ifndef __CASE_H__
#define __CASE_H__

#include <stdio.h>
#include <stdlib.h>

typedef struct s_case{
    t_piece *piece1; //pointeur sur la premiere piece presente dans la case 
    t_piece *piece2; //vide si la première pièce est de type bloquante 
}t_case;

#endif