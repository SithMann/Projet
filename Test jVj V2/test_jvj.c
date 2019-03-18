#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "objet.h"
#include "grille.h"



int est_valide(int ligne, int colonne, t_grille * grille){
    return ((ligne >= 0 && ligne <= grille->longueur - 1) && (colonne >= 0 && colonne <= grille->largeur - 1));
}

int gagnant(t_grille * grille, int nbJetons, t_joueur joueur){
    int count = 0;
    // Test victoire vertical
    for(int i = 0; i < grille->longueur; i++){
        for(int j = 0; j< grille->largeur; j++){
            if(est_valide(i,j,grille)){
                if(grille->laGrille[i][j]->slot1->joueur->nJoueur == joueur.nJoueur ||  grille->laGrille[i][j]->slot2->joueur->nJoueur == joueur.nJoueur)
                    count++;
                else count = 0;
                if(count == nbJetons) return 1;
            }
        }
    }

    // Test victoire horizontal
    for(int i = 0; i < grille->longueur; i++){
        for(int j = 0; j< grille->largeur; j++){
            if(est_valide(i,j,grille)){
                if(grille->laGrille[j][i]->slot1->joueur->nJoueur == joueur.nJoueur ||  grille->laGrille[j][i]->slot2->joueur->nJoueur == joueur.nJoueur)
                    count++;
                else count = 0;
                if(count == nbJetons) return 1;
            }
        }
    }

    // Test diagonale gauche
    for(int i = 0; i < grille->longueur; i++){
        for(int j = 0; j< grille->largeur; j++){
            if(est_valide(i,j,grille)){
                if(grille->laGrille[i+1][j+1]->slot1->joueur->nJoueur == joueur.nJoueur ||  grille->laGrille[i+1][j+1]->slot2->joueur->nJoueur == joueur.nJoueur)
                    count++;
                else count = 0;
                if(count == nbJetons) return 1;

                if(grille->laGrille[i-1][j+1]->slot1->joueur->nJoueur == joueur.nJoueur ||  grille->laGrille[i-1][j+1]->slot2->joueur->nJoueur == joueur.nJoueur)
                    count++;
                else count = 0;
                if(count == nbJetons) return 1;   
            }
        }
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
void tour_joueur(t_joueur* joueur, t_grille * grille){
    int type = 0;
    int col;
    
    /* Demande de saisie de la piece.
     * plus la vérif entier 
     * Il faudrat aussi prendre en compte le nombre disponible de chaque piece pour la suite.
    */
    

    printf("Choix du type de pièce à jouer : \n");
    printf("1- Pleine \n");
    printf("2- Creuse \n");
    printf("3- Bloquante \n");
    do{
        printf("Choix : ");
        scanf("%d", &type);
        //saisir_type(&type)

        if(!joueur->piece[type-1])
            printf("Plus de pieces de ce type disponible !\n");
    }while((type <= 0 || type >= 4) || !joueur->piece[type-1]);
    
    /* Demande de saisie de la colonne. Penser à vérifier que col est un entier plus tard. */
    do{
        printf("Veuillez hoisir le numéro de la colonne pour jouer (entier entre 1 et %d): ", grille->largeur);
        scanf("%d", &col);
    }while((col <= 0 || col >= grille->largeur) || !nonPleine(type-1, col-1, grille, joueur));
}

int main(){
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
            tour_joueur(joueur+i, grille);
            system("clear");
            grille->p_affiche((t_objet * )grille);
            if(/*gagnant(grille)*/fin){
                printf("%s a gagné !! \n", joueur[i].pseudo);
                /*Appel de la save des scores à faire quand la fonction sera fini*/
            }
        }
    }
}