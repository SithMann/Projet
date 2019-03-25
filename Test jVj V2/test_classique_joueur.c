#include <stdlib.h>
#include <stdio.h>
<<<<<<< HEAD
=======
#include <string.h>
>>>>>>> c7fef9e62b03e8bc69c41e951b07181b3d08bd61
#include "objet.h"
#include "grille.h"

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


    int fin =0;
    while(!fin){
        system("clear");
        grille->p_affiche((t_objet * )grille);
        for( i = 0; i < nb_joueur; i++){
            printf("Au tour de J%d %s : \n", joueur[i].nJoueur ,joueur[i].pseudo);
            tour_joueur(joueur+i, grille);
            system("clear");
            grille->p_affiche((t_objet * )grille);
            if(/*gagnant(grille)*/fin){
                printf("%s a gagné !! \n", joueur[i].pseudo);
                /*Appel de la save des scores à faire quand la fonction sera fini*/
            }
        }
    }
<<<<<<< HEAD
}
=======
}
>>>>>>> c7fef9e62b03e8bc69c41e951b07181b3d08bd61
