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

int coup_gagnant(t_grille * grille, t_joueur *joueur){
    for(int i = 0; i < grille->largeur; i++){
        for(t_piece type = PLEINE; type != VIDE; type++){
            if(nonPleine(type, i, grille, joueur)){
                if(gagnant(grille, nJetons, joueur)){
                    return 1;
                }
                dejouer(type, i, grille, joueur);
            }
        }
    }
    return 0;
}

/**
* \fn evaluation
* \param
* \return 
* \brief si le score du min max ne permet pas de determiner une strategie gagante on evalue si c'est plus ou moins en notre faveur de faire un coup en particulier
*/
// int evaluation(){

// }

/**
* \fn adversaire
* \param un pointeur sur la grille de jeu
* \return la fonction renvoie le min des scores pour savoir si on va plutot gagner ou plutot perdre
* \brief attention, pour ne pas impacter le jeu il faut penser a retirer le coup une fois qu'il a ete joue
*/
int adversaire(t_grille * grille, t_joueur * joueur, int num_joueur, int profondeur, int prof_max, int nb_joueur, int num_ordi){
    int i, score, max_score;
    
    if(coup_gagnant || (profondeur == prof_max))
        return evaluation(grille);
    else{
        if(num_joueur == num_ordi){
            for(i = 0; i < grille->largeur; i++){
                for(t_piece type = PLEINE; type != VIDE; type++){
                    if(nonPleine(type, i, grille, joueur[num_joueur])){
                        score = ordi(grille, joueur, (num_joueur+1)%nb_joueur, ++profondeur, prof_max, nb_joueur, num_ordi);
                        dejouer(type, i, grille, joueur[num_joueur]);
                        if(score > max_score) 
                            max_score = score;
                    }
                } 
            }
        }
        else{
            for(i = 0; i < grille->largeur; i++){
                for(t_piece type = PLEINE; type != VIDE; type++){
                    if(nonPleine(type, i, grille, joueur[num_joueur])){
                        score = adversaire(grille, joueur, (num_joueur+1)%nb_joueur, ++profondeur, prof_max, nb_joueur, num_ordi);
                        dejouer(type, i, grille, joueur[num_joueur]);
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
int ordi(t_grille * grille, t_joueur * joueur, int num_joueur, int profondeur, int prof_max, int nb_joueur, int num_ordi){ // lien avec la table joueur pour avoir la couleur ? ou juste actionner par un compteur en fonction du nombre d'appels de la fonction
    int i, score, max_score;

    if(coup_gagnant() || (profondeur == prof_max))
        return evaluation(grille);
    else{
        for(i = 0; i < grille->largeur; i++){
            for(t_piece type = PLEINE; type != VIDE; type++){
                if(nonPleine(type, i, grille, joueur[num_joueur])){
                    score = adversaire(grille, joueur, (num_joueur+1)%nb_joueur, ++profondeur, prof_max, nb_joueur, num_ordi);
                    dejouer(type, i, grille, joueur[num_joueur]);
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
void tour_ordi(t_grille * grille, t_joueur * joueur, int num_ordi, int profondeur, int prof_max, int nb_joueur){
    int i, score, max_score, save_colonne = 0, num_joueur = num_ordi;
    t_piece save_piece = VIDE;
    if(!coup_gagnant()){ // coup_gagnant joue le coup et l'annule si non gagnant
                // si score de ordi est mieux que score_max, on save score, type, colonne
        // jouer le coup    
        for(i = 0; i < grille->largeur; i++)// Pour toute colonne
            for(t_piece type = PLEINE; type != VIDE; type++){// pour tout type
                if(nonPleine(type, i, grille, joueur[num_joueur])){
                    score = adversaire(grille, joueur, num_joueur+1, ++profondeur, prof_max, nb_joueur, num_ordi);
                    dejouer(type, i, grille, joueur[num_joueur]);
                if(score > max_score){
                    save_piece = type;
                    save_colonne = i;
                    max_score = score;
                }  
            }
            nonPleine(save_piece, save_colonne, grille, joueur);
    }
}
