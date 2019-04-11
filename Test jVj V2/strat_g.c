#include <stdio.h>
#include <stdlib.h>
#include "grille.h"
#include "strat_g.h"
#include "jeu.h"
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
    //fprintf(stderr,"DEJOUE \n");
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

int jouer_coup_gagnant(t_grille * grille, t_joueur *joueur, int nJetons){
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

int coup_gagnant(t_grille * grille, t_joueur *joueur, int nJetons){
    int gg = 0;
    for(int i = 0; i < grille->largeur; i++){
        for(t_piece type = PLEINE; type != VIDE; type++){
            if(nonPleine(type, i, grille, joueur)){
                if(gagnant(grille, nJetons, joueur)){
                    gg = 1;
                }
                dejouer(type, i, grille, joueur);
            }
        }
    }
    return gg;
}

/**
* \fn evaluation
* \param
* \return 
* \brief 
*/
int evaluation(t_grille * grille, t_joueur * joueur, int num_joueur, int nb_joueur, int nJetons){
/* Comment j'évalue : 
* Je commence à 0 
* Un adversaire a plus de possibilités que de joueurs = -100
* Un adversaire a 3 possibilités =-50
* Un adversaire a 2 possibilités =-25
* Un adversaire a 1 possibilité =+25
* Un adversaire a 0 possibilité =+50
* J'ai 0 possibilité = -50
* J'ai 1 possibilité = -25
* J'ai 2 possibilités = +25
* J'ai 3 possibilités = +50
* J'ai plus possibilités que de joueurs = +100
*/
    int count, score = 0;
    for(int i = 0; i < nb_joueur; i++){
        count = 0;
        for(t_piece type = PLEINE; type != VIDE; type++){
            for(int j = 0; j < grille->largeur; j++){
                if(nonPleine(type, j, grille, &joueur[i])){
                    if(gagnant(grille,nJetons, &joueur[i]))
                        count++;
                    dejouer(type, j, grille, &joueur[i]);
                }
            }
        }
        if(i == num_joueur)
            switch(count){
                case 0: score -= 50; break;
                case 1: score -= 25; break;
                case 2: score += 25; break;
                case 3: score += 50; break;
                default : if(count >= nb_joueur) score += 100;
                          else printf("erreur dans la fonction d'evaluation\n");
            }
        else
            switch(count){
                case 0: score += 50; break;
                case 1: score += 25; break;
                case 2: score -= 25; break;
                case 3: score -= 50; break;
                default : if(count >= nb_joueur) score -= 100;
                          else printf("erreur dans la fonction d'evaluation\n");
            }
    }
    return score;
}

/**
* \fn adversaire
* \param un pointeur sur la grille de jeu
* \return la fonction renvoie le min des scores pour savoir si on va plutot gagner ou plutot perdre
* \brief attention, pour ne pas impacter le jeu il faut penser a retirer le coup une fois qu'il a ete joue
*/
int adversaire(t_grille * grille, t_joueur * joueur, int num_joueur, int profondeur, int prof_max, int nb_joueur, int num_ordi, int nJetons){
    int i, score, min_score = 5000; //TODO: mettre la bonne valeur (borne supérieure du score)
    int num_coup = 0;
    /*for(i = 0; i < profondeur; i++)
        fprintf(stderr,"\t");
    fprintf(stderr,"Profondeur Adv : %d\n", profondeur);*/
    if(coup_gagnant(grille, &joueur[num_joueur], nJetons) || (profondeur >= prof_max))
        return evaluation(grille, joueur, num_joueur, nb_joueur, nJetons);
    else{
        if((num_joueur+1)%nb_joueur == num_ordi){ // si le suivant est l'ordi 
            for(i = 0; i < grille->largeur; i++){
                for(t_piece type = PLEINE; type != VIDE; type++){
                    if(nonPleine(type, i, grille, &joueur[num_joueur])){
                        
                        /*for(int j = 0; j < profondeur; j++)
                            fprintf(stderr,"\t");
                        fprintf(stderr,"Profondeur Adv : %d - %d : %d, %s\n", profondeur, num_coup++, i, t_piece_str(type));*/
                        
                        score = ordi(grille, joueur, (num_joueur+1)%nb_joueur, profondeur+1, prof_max, nb_joueur, num_ordi, nJetons);
                        dejouer(type, i, grille, &joueur[num_joueur]);
                        if(score < min_score) 
                            min_score = score;
                    }
                } 
            }
        }
        else{
            for(i = 0; i < grille->largeur; i++){
                for(t_piece type = PLEINE; type != VIDE; type++){
                    if(nonPleine(type, i, grille, &joueur[num_joueur])){
                        /*
                        for(int j = 0; j < profondeur; j++)
                            fprintf(stderr,"\t");
                        fprintf(stderr,"Profondeur Adv : %d - %d\n", profondeur, num_coup++);*/

                        score = adversaire(grille, joueur, (num_joueur+1)%nb_joueur, profondeur+1, prof_max, nb_joueur, num_ordi, nJetons);
                        dejouer(type, i, grille, &joueur[num_joueur]);
                        if(score < min_score) 
                            min_score = score;
                    }
                } 
            }
        }
        return  min_score;
    }
}

/**
* \fn ordi
* \param un pointeur sur la grille de jeu
* \return la fonction renvoie le max des scores pour savoir si on va plutot gagner ou plutot perdre
* \brief attention, pour ne pas impacter le jeu il faut penser a retirer le coup une fois qu'il a ete joue
*/
int ordi(t_grille * grille, t_joueur * joueur, int num_joueur, int profondeur, int prof_max, int nb_joueur, int num_ordi, int nJetons){ // lien avec la table joueur pour avoir la couleur ? ou juste actionner par un compteur en fonction du nombre d'appels de la fonction
    int i, score, max_score = -5000; //TODO: mettre la bonne valeur (borne inférieure du score)
    int num_coup = 0;
    if(coup_gagnant(grille, &joueur[num_joueur], nJetons) || (profondeur >= prof_max)){
        //fprintf(stderr,"- Ordi RETURN -");
        return evaluation(grille, joueur, num_joueur, nb_joueur, nJetons);
    }
    else{
        for(i = 0; i < grille->largeur; i++){
            for(t_piece type = PLEINE; type != VIDE; type++){
                if(nonPleine(type, i, grille, &joueur[num_joueur])){
                    /*
                    for(int j = 0; j < profondeur; j++)
                        fprintf(stderr,"\t");
                    fprintf(stderr,"Profondeur Ordi : %d - %d\n", profondeur, num_coup++);*/
                    
                    score = adversaire(grille, joueur, (num_joueur+1)%nb_joueur, profondeur+1, prof_max, nb_joueur, num_ordi, nJetons);
                    dejouer(type, i, grille, &joueur[num_joueur]);
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
void tour_ordi(t_grille * grille, t_joueur * joueur, int num_ordi, int prof_max, int nb_joueur, int nJetons){
    int i, score, max_score  = -5000, save_colonne = 0, num_joueur = num_ordi, profondeur = 1;
    t_piece save_piece = VIDE;
    int num_coup = 0;
    if(!jouer_coup_gagnant(grille, &joueur[num_joueur], nJetons)){ // coup_gagnant joue le coup et l'annule si non gagnant
                // si score de ordi est mieux que score_max, on save score, type, colonne
        // jouer le coup    
        for(i = 0; i < grille->largeur; i++){// Pour toute colonne
            //fprintf(stderr,"Dans tour_ordi : %d\n", i);
            for(t_piece type = PLEINE; type != VIDE; type++){// pour tout type
                if(nonPleine(type, i, grille, &joueur[num_joueur])){
                    /*
                    for(int j = 0; j < profondeur; j++)
                        fprintf(stderr,"\t");
                    fprintf(stderr,"Profondeur Ordi : %d - %d\n", profondeur, num_coup++);*/
                    
                    score = adversaire(grille, joueur, num_joueur+1, profondeur, prof_max, nb_joueur, num_ordi, nJetons);
                    dejouer(type, i, grille, &joueur[num_joueur]);
                    if(score > max_score){
                        save_piece = type;
                        save_colonne = i;
                        max_score = score;
                    }
                }  
            }
        }
        fprintf(stderr,"Joue le coup \n");
        nonPleine(save_piece, save_colonne, grille, &joueur[num_joueur]);
    }
}
