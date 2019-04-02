#include <stdio.h>
#include <stdlib.h>
#include "grille.h"
#include "strat_g.h"
//#include "joueur.h" il est deja include dans grille 

/**
* \file strat_g.c
* \author Noémie Farizon et Mathis Despres
* \date 20 mars 2019
* \version 1
*/

/**
* \fn dejouer
* \param  une piece, un entier pour le nombre de colonnes, une pointeur sur une grille, un pointeur sur joueur
* \return la fonction ne retourne rien
* \brief fait l'inverse de jouer_le_coup (retire la piece de la grille)
*/
void dejouer(t_piece piece, int nbCol, t_grille * grille, t_joueur* joueur){
    int max_score;
    for( int i = 0; i < grille->longueur; i++){  
        if((lire_piece_slot(i,nbCol,1,grille) == piece)){
            grille->laGrille[i][nbCol]->slot1->piece = VIDE;
            grille->laGrille[i][nbCol]->slot1->joueur = NULL;
            return;
        }
        if((lire_piece_slot(i,nbCol,2,grille) == piece)){
            grille->laGrille[i][nbCol]->slot2->piece = VIDE;
            grille->laGrille[i][nbCol]->slot2->joueur = NULL;
            return;
        }
    }
}

/**
* \fn evaluation
* \param
* \return 
* \brief si le score du min max ne permet pas de determiner une strategie gagant on evalue si c'est plus ou moins en notre faveur de faire un coup en particulier
*/
// int evaluation(){

// }

/**
* \fn adversaire
* \param un pointeur sur la grille de jeu
* \return la fonction renvoie le min des scores pour savoir si on va plutot gagner ou plutot perdre
* \brief attention, pour ne pas impacter le jeu il faut penser a retirer le coup une fois qu'il a ete joue
*/
int adversaire(t_grille * grille, t_joueur * joueur, int num_joueur, int profondeur, int prof_max, int nb_joueur){
    int i, score;
    if(num_joueur >= nb_joueur)
        num_joueur = 0;
    
    if(coup_gagnant || (profondeur == prof_max))
        return - max_score;
    else{
        if(num_joueur == nb_joueur-1){
            for(i = 0; i < grille->largeur; i++){
                for(t_piece type = PLEINE; type != VIDE; type++){
                    if(nonPleine(type, i, grille, joueur[num_joueur])){
                        score = ordi(grille, grille->largeur, num_joueur++, profondeur++, prof_max, nb_joueur);
                        dejouer(type, i, grille, joueur);
                        if(score > max_score) 
                            max_score = score;
                    }
                } 
            }
        }
        else{
            for(i = 0; i < grille->largeur; i++){
                for(t_piece type = PLEINE; type != VIDE; type++){
                    if(nonPleine(type, i, grille, joueur)){
                        score = adversaire(grille, grille->largeur, num_joueur++, profondeur++, prof_max, nb_joueur);
                        dejouer(type, i, grille, joueur);
                        if(score > max_score) 
                            max_score = score;
                    }
                } 
            }
        }
        return - max_score;
    }
}

/**
* \fn ordi
* \param un pointeur sur la grille de jeu
* \return la fonction renvoie le max des scores pour savoir si on va plutot gagner ou plutot perdre
* \brief attention, pour ne pas impacter le jeu il faut penser a retirer le coup une fois qu'il a ete joue
*/
int ordi(t_grille * grille, t_joueur * joueur, int num_joueur, int profondeur, int prof_max, int nb_joueur){ // lien avec la table joueur pour avoir la couleur ? ou juste actionner par un compteur en fonction du nombre d'appels de la fonction
    int i, j, score;

    if(coup_gagnant || (profondeur == prof_max))
        return max_score;
    else{
        for(i = 0; i < grille->largeur; i++){
            for(t_piece type = PLEINE; type != VIDE; type++){
                if(nonPleine(type, i, grille, joueur)){
                    score = adversaire(grille, grille->largeur, num_joueur++, profondeur++, prof_max, nb_joueur);
                    dejouer(type, i, grille, joueur);
                    if(score > max_score) 
                        max_score = score;
                }
            } 
        }
    }
    return max_score;
}

/**
* \fn tour_ordi
* \param entier pour la profondeur maximum (prof_max)
* \return 
* \brief 
*/
void tour_ordi(t_grille * grille, t_joueur * joueur, int num_joueur, int profondeur, int prof_max, int nb_joueur){
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
