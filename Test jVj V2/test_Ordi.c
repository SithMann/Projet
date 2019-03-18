#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include "objet.h"
#include "grille.h"

/**
* \file test_Ordi.c
* \author Mathis Despres et Clement Dubois 
* \date 15 mars 2019
* \version 1
* \brief fichier de teste pas a pas pour la simulation
*/

int gagnant(t_grille * grille, int nbJetons, t_joueur *joueur){
   int i, j, k, count = 0;
    int ni, nj; //nouveau i et j
    
    for(i = 0; i < grille->longueur; i++){
        for(j = 0; j < grille->largeur; j++){
            t_direction direc = direction_debut();
            fprintf(stderr, "Direction : %d\n", direc);
            for(int m=0; m < NB_DIRECTION;m++){
                count = 0;
                ni = i;
                nj = j;
                for(k = 0; k < nbJetons && est_valide(ni,nj,grille) ; k++){
                    
                    if(est_valide(ni,nj,grille) && ((joueur->couleur == lire_couleur_joueur_slot(ni, nj, 1, grille)) || (joueur->couleur == lire_couleur_joueur_slot(ni, nj, 2, grille)))){
                        count++;
                    }
                    if(count >= nbJetons) return 1;
                    direction_avancer( ni, nj, direc, &ni, &nj, grille);
                }
                direc = direction_suivante(direc);
            }
        }
    }
    return 0;
}

int un_gagnant(t_grille * grille, int nJetons, t_joueur * joueur, int nbJoueurs){
    for(int i = 0; i < nbJoueurs; i++){
        fprintf(stderr, "Test boucle for un_gagnant\n");
        if(gagnant(grille, nJetons, joueur+i)) return 1;
    }
    return 0;
}

/* Fonction pour tester qu'il reste de la place dans une colonne
 * Renvoie 1 s'il y a de la place, 0 sinon. Affecte par pointeur la position de la première case vide de la colonne
 * Attention, à reprendre avec les différents types de pieces.
 */

int nonPleine(t_piece piece, int nbCol, t_grille * grille, t_joueur* joueur){
    int i;
    fprintf(stderr, "NON PLEINE colonne=%d\n", nbCol);
    switch(piece){
        /* Cas 1 et 2 à ajuster en fonctions des règles 
        * Cas 1 : Creuses : Si il y a une pleine la creuse va directement dans la pleine
        * Elle descend le plus bas si il n'y a que des pleines jusqu'à une bloquante ou une creuse
        * Cas 2 : Pleines : Si il y a une creuse la pleine va directement dans la creuse
        * Elle descend le plus bas si il n'y a que des creuses jusqu'à une bloquante ou une pleine
        */
        case PLEINE :
                fprintf(stderr, "PIECE PLEINE colonne=%d\n", nbCol);
                    
                    for( i = 0; i < grille->longueur; i++){
                        fprintf(stderr, "CASE (%d,%d) \n", i, nbCol);
                        //grille->laGrille[i][nbCol]->p_affiche((t_objet*)grille->laGrille[i][nbCol]);
                        if((lire_piece_slot(i,nbCol,1,grille) == BLOQUANTE) || ((lire_piece_slot(i,nbCol,1,grille) == PLEINE)||(lire_piece_slot(i,nbCol,2,grille) != VIDE))){// la case est bloquante
                                break;
                                
                        }
                    }
                    if(i==0) {
                         fprintf(stderr, "LA COLONNE EST PLEINE colonne=%d\n", nbCol);
                         return 0;
                    }
                    fprintf(stderr, "AJOUT PIECE PLEINE en (%d,%d)\n", i-1, nbCol);
                    ajouter_piece(i-1, nbCol, grille, piece, joueur);
                    return 1;
                
                break;
        case CREUSE :
                fprintf(stderr, "PIECE CREUSE colonne=%d\n", nbCol);
                    for( i = 0; i < grille->longueur; i++){
                        fprintf(stderr, "CASE (%d,%d) \n", i, nbCol);
                        //grille->laGrille[i][nbCol]->p_affiche((t_objet*)grille->laGrille[i][nbCol]);
                        if((lire_piece_slot(i,nbCol,1,grille) == BLOQUANTE) || ((lire_piece_slot(i,nbCol,1,grille) == CREUSE)||(lire_piece_slot(i,nbCol,2,grille) != VIDE))){// la case est bloquante
                                break;
                                
                        }
                    }
                    if(i==0) {
                         fprintf(stderr, "LA COLONNE EST PLEINE colonne=%d\n", nbCol);
                         return 0;
                    }
                    fprintf(stderr, "AJOUT PIECE CREUSE en (%d,%d)\n", i-1, nbCol);
                    ajouter_piece(i-1, nbCol, grille, piece, joueur);
                    return 1;
                break;
        /* Cas 3 : BLOQUANTES OK */
        case BLOQUANTE : 
                fprintf(stderr, "PIECE CREUSE colonne=%d\n", nbCol);
                    for( i = 0; i < grille->longueur; i++){
                        fprintf(stderr, "CASE (%d,%d) \n", i, nbCol);
                        if((lire_piece_slot(i,nbCol,1,grille) == BLOQUANTE) || (lire_piece_slot(i,nbCol,1,grille) == PLEINE) || (lire_piece_slot(i,nbCol,1,grille) == CREUSE)){// la case est bloquante
                                break;
                                
                        }
                    }
                    if(i==0) {
                         fprintf(stderr, "LA COLONNE EST PLEINE colonne=%d\n", nbCol);
                         return 0;
                    }
                    fprintf(stderr, "AJOUT PIECE BLOQUANTE en (%d,%d)\n", i-1, nbCol);
                    ajouter_piece(i-1, nbCol, grille, piece, joueur);
                    return 1;
                break;
        default :   printf("Erreur\n");
                    char c;
                    do{
                        scanf("%c", &c);
                    }while(c != 'a');
    }
    return 0;
}



/* Fonction qui fait jouer un joueur. Demande la saisie de la colonne et de la piece.
 * Met à jour la grille et ne renvoie rien.
*/
void tour_ordi(t_joueur* joueur, t_grille * grille){
    int type = 0;
    int col;
    
    /* Demande de saisie de la piece.
     * plus la vérif entier 
     * Il faudrat aussi prendre en compte le nombre disponible de chaque piece pour la suite.
    */
    

   type = rand()%3+1;
    
    /* Demande de saisie de la colonne. Penser à vérifier que col est un entier plus tard. */
    do{
        col = rand()%grille->largeur+1;
    }while(!nonPleine(type-1, col-1, grille, joueur));
}

int main(){

    srand(time(NULL));
    int i;
    int nb_joueur = 4;

    int nb_ligne = 15, nb_colonne = 18, nb_piece_b = 10, nb_piece_p = 10, nb_piece_c = 10;
    t_grille * grille = creer_grille(nb_ligne, nb_colonne, sizeof(t_case*));
    t_joueur * joueur = malloc(sizeof(t_joueur)*nb_joueur);
    for(int i = 0; i < nb_joueur; i++){
        joueur[i] = creer_joueur(i+1, nb_piece_b, nb_piece_p, nb_piece_c);
    }

    /*Saisie des pseudos en fonctions du nombre de joueurs*/
    for(i = 0; i < nb_joueur; i++){
        fprintf(stderr,"Pseudo joueur %d : ", i+1);
        strcpy(joueur[i].pseudo , "Bot_test");
        fprintf(stderr," %s \n", joueur[i].pseudo);
        joueur[i].nJoueur = i+1;
        joueur[i].couleur = RED + i;
    }


    int fin =0;
    while(!fin){
        system("clear");
        grille->p_affiche((t_objet * )grille);
        for( i = 0; i < nb_joueur; i++){
            printf("Au tour de J%d %s : \n", joueur[i].nJoueur ,joueur[i].pseudo);
            tour_ordi(joueur+i, grille);
            system("clear");
            grille->p_affiche((t_objet * )grille);
            if(/*gagnant(grille)*/fin){
                printf("%s a gagné !! \n", joueur[i].pseudo);
                /*Appel de la save des scores à faire quand la fonction sera fini*/
            }
        }
    }
}
