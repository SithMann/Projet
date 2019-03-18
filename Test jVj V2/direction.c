#include <stdio.h>
#include <stdlib.h>
#include "jeu.h"
#include "direction.h"

const int NB_DIRECTION=8;
//modifie les valeurs de l'appelant pour *ni, *nj
int direction_avancer(int i, int j, t_direction dir, int nb_pas/*, int *ni, int*nj*/, t_grille * grille){
    int k, l;
    int count = 0;
    dir = direction_debut();
    t_couleur couleur1 = lire_couleur_joueur_slot(i, j, 1, grille);
    t_couleur couleur2 = lire_couleur_joueur_slot(i, j, 2, grille);
    //traitement si même couleur et pas hors matrice on continue
    for(k = 0; k < NB_DIRECTION; k++){
        for(l = 1; l <= nb_pas; l++){
            switch(k){
                case 0 : if(est_valide(i-l,j,grille) && (couleur1 == lire_couleur_joueur_slot(i-l, j, 1, grille) || couleur2 == lire_couleur_joueur_slot(i-l, j, 2, grille))){
                            count++;
                            if(count == nb_pas) return 1;
                         }
                         break;
                case 1 : if(est_valide(i-l,j+l,grille) && (couleur1 == lire_couleur_joueur_slot(i-l, j+l, 1, grille) || couleur2 == lire_couleur_joueur_slot(i-l, j+l, 2, grille))){
                            count++;
                            if(count == nb_pas) return 1;
                         }
                         break;
                case 2 : if(est_valide(i,j,grille) && (couleur1 == lire_couleur_joueur_slot(i, j, 1, grille) || couleur2 == lire_couleur_joueur_slot(i, j, 2, grille))){
                            count++;
                            if(count == nb_pas) return 1;
                        }
                         break;
                case 3 : if(est_valide(i+l,j-l,grille) && (couleur1 == lire_couleur_joueur_slot(i+l, j-l, 1, grille) || couleur2 == lire_couleur_joueur_slot(i+l, j, 2, grille))){
                            count++;
                            if(count == nb_pas) return 1;
                         }
                         break;
                case 4 : if(est_valide(i+l,j,grille) && (couleur1 == lire_couleur_joueur_slot(i+l, j, 1, grille) || couleur2 == lire_couleur_joueur_slot(i+l, j, 2, grille))){
                            count++;
                            if(count == nb_pas) return 1;
                         }
                         break;
                case 5 : if(est_valide(i+l,j-l,grille) && (couleur1 == lire_couleur_joueur_slot(i+l, j-l, 1, grille) || couleur2 == lire_couleur_joueur_slot(i+l, j, 2, grille))){
                            count++;
                            if(count == nb_pas) return 1;
                         }
                         break;
                case 6 : if(est_valide(i,j-l,grille) && (couleur1 == lire_couleur_joueur_slot(i, j-l, 1, grille) || couleur2 == lire_couleur_joueur_slot(i, j-l, 2, grille))){
                            count++;
                            if(count == nb_pas) return 1;
                         }
                         break;
                case 7 : if(est_valide(i-l,j-l,grille) && (couleur1 == lire_couleur_joueur_slot(i-l, j-l, 1, grille) || couleur2 == lire_couleur_joueur_slot(i-l, j, 2, grille))){
                            count++;
                            if(count == nb_pas) return 1;
                         }
                         break;
            }
        }
        dir = direction_suivante(dir);
    }
    return 0;
}

t_direction direction_suivante(t_direction dir){
    return dir + 1;
}

t_direction direction_debut(){
    return NORD;
}