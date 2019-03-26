#include <stdio.h>
#include <stdlib.h>
#include "grille.h"
//#include "joueur.h" il est deja include dans grille 
#define NB_TYPE 3
#define MAX_SCORE 
#define NB_JOUEUR 4 //sera mis en parametre car variable (en fonction du niveau)
/**
* \file strat_g.c
* \author Noémie Farizon
* \date 20 mars 2019
* \version 1
*/

/**
* \fn dejouer
* \param  
* \return 
* \brief fait l'inverse de jouer_le_coup (retire la piece de la grille)
*/
truc dejouer(){
    
}

/**
* \fn coup_possible
* \param un pointeur sur une grille, un entier pour le nombre de colonne de la grille
* \return la fonction revoie une valeur qui permet de savoir si le coup est realisable (0-1)
* \brief verifie que la case dans laquelle on veut jouer n'est pas pleine, sinon on test si la piece est bloquante (sinon on augmentera le compteur pour la ligne) et que le type est disponible (...) ?
*/
//stocke tous les coup que l'on peut jouer --> pas besoin car juste un if dans adv/ordi qui ne jourra le coup que s'il est possible
truc coup_possible(t_grille * grille, int nb_piece_dispo, int nb_piece_uti, int nb_colonne){
    int i;
    
}

/**
* \fn evaluation
* \param
* \return 
* \brief si le score du min max ne permet pas de determiner une strategie gagant on evalue si c'est plus ou moins en notre faveur de faire un coup en particulier
*/
int evaluation(){

}

/**
* \fn adversaire
* \param un pointeur sur la grille de jeu
* \return la fonction renvoie le min des scores pour savoir si on va plutot gagner ou plutot perdre
* \brief attention, pour ne pas impacter le jeu il faut penser a retirer le coup une fois qu'il a ete joue
*/
int adversaire(t_grille * grille, int largeur, int num_joueur, int profondeur){
    int i, nb_type = 3, score;
    
    if(coup_gagnant || (profondeur == MAX_PROF))
        return - MAX_SCORE;
    else{
        if((num_joueur % NB_JOUEUR) == 0){
            for(i = 0; i < largeur; i++){
                for(type){
                    if(jouer_le_coup()){
                        score = ordi(grille, largeur, num_joueur++, profondeur++);
                        dejouer;
                        if(score > MAX_SCORE) 
                            MAX_SCORE = score;
                    }
                } 
            }
        }
        else{
            for(i = 0; i < largeur; i++){
                for(type){
                    if(jouer_le_coup()){
                        score = adversaire(grille, largeur, num_joueur++, profondeur++);
                        dejouer;
                        if(score > MAX_SCORE) 
                            MAX_SCORE = score;
                    }
                } 
            }
        }
        return - MAX_SCORE;
    }
}

/**
* \fn ordi
* \param un pointeur sur la grille de jeu
* \return la fonction renvoie le max des scores pour savoir si on va plutot gagner ou plutot perdre
* \brief attention, pour ne pas impacter le jeu il faut penser a retirer le coup une fois qu'il a ete joue
*/
int ordi(t_grille * grille, int largeur, int num_joueur, int profondeur){ // lien avec la table joueur pour avoir la couleur ? ou juste actionner par un compteur en fonction du nombre d'appels de la fonction
    int i, j, nb_type = 3, score;

    if(coup_gagnant || (profondeur == MAX_PROF))
        return MAX_SCORE;
    else{
        for(i = 0; i < largeur; i++){
            for(type){
                if(jouer_le_coup()){
                    score = adversaire(grille, largeur, num_joueur++, profondeur++);
                    dejouer;
                    if(score > MAX_SCORE) 
                        MAX_SCORE = score;
                }
            } 
        }
    }
    return MAX_SCORE;
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