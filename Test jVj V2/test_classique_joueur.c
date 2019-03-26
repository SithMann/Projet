#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "objet.h"
#include "grille.h"
#include "direction.h"


/**
* \fn gagnant
* \param un pointeur sur grille, un entier pour le nombre de jetons, un pointeur sur un joueur 
* \return la fonction retourn eun entier 
*/
int gagnant(t_grille * grille, int nbJetons, t_joueur *joueur){
   int i, j, k, count = 0;
    int ni, nj; //nouveau i et j
    t_direction direc;
    for(i = 0; i < grille->longueur; i++){
        for(j = 0; j < grille->largeur; j++){
            direc = direction_debut();
            //fprintf(stderr, "Direction : %d\n", direc);
            for(int m=0; m < NB_DIRECTION; m++){
                count = 0;
                ni = i;
                nj = j;
                for(k = 0; k < nbJetons && est_valide(ni,nj,grille) ; k++){
                    
                    if(est_valide(ni,nj,grille) && ((joueur->couleur == lire_couleur_joueur_slot(ni, nj, 1, grille)) || (joueur->couleur == lire_couleur_joueur_slot(ni, nj, 2, grille)))){
                        count++;
                    }
                    if(count >= nbJetons){
                        printf("%s a gagné !! \n", joueur->pseudo);
                        //Save win 
                        return 1;
                    } 
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
        //fprintf(stderr, "Test boucle for un_gagnant\n");
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
}



/* Fonction qui fait jouer un joueur. Demande la saisie de la colonne et de la piece.
 * Met à jour la grille et ne renvoie rien.
*/
void tour_joueur(t_joueur* joueur, t_grille * grille){
    int col;

    
    /* Demande de saisie de la colonne. Penser à vérifier que col est un entier plus tard. */
    do{
        printf("Veuillez hoisir le numéro de la colonne pour jouer (entier entre 1 et %d): ", grille->largeur);
        scanf("%d", &col);
    }while((col <= 0 || col >= grille->largeur) || !nonPleine(BLOQUANTE, col-1, grille, joueur));
}

int main(){
    int i;
    int nb_joueur = 2;

    int nb_ligne = 15, nb_colonne = 18, nb_piece_b = 10, nb_piece_p = 0, nb_piece_c = 0;

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


        while(!un_gagnant(grille, 4, joueur, nb_joueur)){
        system("clear");
        grille->p_affiche((t_objet * )grille);
        for( i = 0; i < nb_joueur; i++){
            printf("Au tour de J%d %s : \n", joueur[i].nJoueur ,joueur[i].pseudo);
            tour_joueur(joueur+i, grille);
            system("clear");
            grille->p_affiche((t_objet * )grille);
            if(gagnant(grille, 4, joueur+i)){
                // printf("%s a gagné !! \n", joueur[i].pseudo);
                return 1;
                /*Appel de la save des scores à faire quand la fonction sera fini*/
            }
        }
    }
    return 0;
}
