#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

/* structure de données relatives à une piece */
typedef struct piece_s {
    int nb_piece; /*Compteur*/
    char * couleur; /*Jaune, rouge etc...*/
    int type; /*Pleine,creuse,bloquantes*/
}piece_t;

/* Fonction pour tester qu'il reste de la place dans une colonne
 * Renvoie 1 s'il y a de la place, 0 sinon. Affecte par pointeur la position de la première case vide de la colonne
 * Attention, à reprendre avec les différents types de pieces.
*/
int nonPleine(piece_t piece, int nbCol, int * pos, char grille[L][C]){

    switch(piece.valeur){
        /* Cas 1 et 2 à ajuster en fonctions des règles (j'ai oublié entre creuses et pleines, qui bloque qui) */
        case 1 :
                for(int i = L-1; i >= 0; i--){
                    if(grille[i][nbCol] == ' '){
                        *pos = i;
                        return 1;
                    }
                }
                break;
        case 2 :
                for(int i = L-1; i >= 0; i--){
                    if(grille[i][nbCol] == ' '){
                        *pos = i;
                        return 1;
                    }
                }
                break;
        /* Cas 3 OK */
        case 3 :
                for(int i = L-1; i >= 0; i--){
                    if(grille[i][nbCol] == ' '){
                        *pos = i;
                        return 1;
                    }
                }
                break;
    }
    return -1;
}