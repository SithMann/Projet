#include <stdio.h>
#include <stdlib.h>
#include "grille.h"
//#include "joueur.h" il est deja include dans grille 
#define NB_TYPE 3
#define MAX_SCORE 
#define NB_JOUEUR 4 //sera mis en parametre car variable
/**
* \file strat_g.c
* \author Noémie Farizon
* \date 20 mars 2019
* \version 1
* \brief attention on ne fait pas l'arbre ! il se fait tout seul grace a la recussivite
*/

/**
* \fn choix_piece
* \param un joueur 
* \return la fonction revoie la piece que l'on veut jouer
* \brief cette fonction sera utilisee dans coup_possible, il faut tenir compte du nombre de type de pieces et du nombre de pieces dispo pour chaque type (etat qui change au cours du jeu).
*/
// t_piece choix_piece(t_piece piece){
//     return (piece + 1) % NB_TYPE;
// }

/**
* \fn coup_possible
* \param un pointeur sur une grille, un entier pour le nombre de colonne de la grille
* \return la fonction revoie une valeur qui permet de savoir si le coup est realisable 
* \brief cherche ou on peut mettre la piece en tennant en compte le nombre de piece disponible pour un type donne et si la colonne est vide (...), que l'on soit bien dans la limite de la grille
*/
int coup_possible(t_grille * grille, int nb_piece_dispo, int nb_piece_uti, int nb_colonne){
    int i;
    if(nb_piece_uti<nb_piece_dispo){
        for(i=0; i<nb_colonne; i++){

        }
    }
}

/**
* \fn evaluation
* \param
* \return 
* \brief 
*/
int evaluation(){

}

/**
* \fn adversaire
* \param un pointeur sur la grille de jeu
* \return la fonction renvoie le min des scores pour savoir si on va plutot gagner ou plutot perdre
* \brief attention, pour ne pas impacter le jeu il faut penser a retirer le coup une fois qu'il a ete joue
*/
int adversaire(t_grille * grille, int largeur, int num_joueur){
    int i, nb_type = 3;
    
    if(coup_gagnant)
        return - MAX_SCORE;
    else{
        if((num_joueur%(NB_JOUEUR-1)) == (NB_JOUEUR-1)){
            if(bloquante == 0)
                nb_type--;
            if(pleine == 0)
                nb_type--;
            if(creuse == 0)
                nb_type--;
            for(i = 0; i < (nb_type * largeur); i++){ 
                // jouer le(s) coup(s)
                adversaire(grille, largeur, num_joueur++);// peut etre en dehors 
            }
        }
        else{
            if(bloquante == 0)
                nb_type--;
            if(pleine == 0)
                nb_type--;
            if(creuse == 0)
                nb_type--;
            for(i = 0; i < (nb_type * largeur)/* faire le bon nombre de noeuds en fonction du nombre de pieces disponibles*/; i++){
                ordi(grille, largeur, num_joueur++);
        }
        
        //pour tous les coups possibles 
            //nouvel etat = jouer le coup 
            //C[i] = joueur(nouvel etat)
        //return min des C[i]
    }
}

/**
* \fn ordi
* \param un pointeur sur la grille de jeu
* \return la fonction renvoie le max des scores pour savoir si on va plutot gagner ou plutot perdre
* \brief attention, pour ne pas impacter le jeu il faut penser a retirer le coup une fois qu'il a ete joue
*/
int ordi(t_grille * grille, int largeur, int num_joueur){ // lien avec la table joueur pour avoir la couleur ? ou juste actionner par un compteur en fonction du nombre d'appels de la fonction
    int i, j, nb_type = 3;

    if(coup_gagnant)
        return MAX_SCORE;
    else{
        if(bloquante == 0)
            nb_type--;
        if(pleine == 0)
            nb_type--;
        if(creuse == 0)
            nb_type--;
        for(i = 0; i < (nb_type * largeur); i++){
            // jouer le(s) coup(s)
            adversaire(grille, largeur, num_joueur++);
        }
            // for(int i = 0; i < nb_pieces_dispo //24//; i++)
            // si type de piece = bloquante : si le nombre de pieces dispo > 0, jouer le coup
            // sinon juste jouer le coup
            // grille[i][j] = coup (1,2 ou 3) -> lien avec la table joueur pour avoir la couleur ?//nouvel etat = jouer le coup 
            //C[i] = adversaire(nouvel etat)
        
        //return max des C[i]
    }
}

/**
* \fn tour_ordi
* \param entier pour la profondeur maximum (prof_max)
* \return 
* \brief 
*/
void tour_ordi(int prof_max, int nb_joueur){
    if(coup_gagnant)
        // jouer coup_gagnant
    else{
        int nb_piece_uti=0;
        do{
            // nouvel_etat =jouer le coup
            nb_piece_uti++;
        }while(coup_possible(grille, nb_piece_dispo, nb_piece_uti, nb_colonne));
        // s'il existe un C[i]=+1 alors
            // jouer le coup correspondant
        else   
            // coup au hasard
    }
}


// pb : comment faire pour retirer le coup qui vient d'être joueur pour continuer a faire la recurtion ?
// a quel moment on le retire ?