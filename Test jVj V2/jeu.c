#include <stdlib.h>
#include <stdio.h>
#include "objet.h"
#include "grille.h"
#include "direction.h"

/**
* \file jeu.c
* \author Mathis Despres et Clement Dubois 
* \date 15 mars 2019
* \version 3
*/

/**
* \fn gagnant
* \param un pointeur sur grille, un entier pour le nombre de jetons, un pointeur sur un joueur 
* \return la fonction retourn eun entier 
*/
int gagnant(t_grille * grille, int nbJetons, t_joueur *joueur){
    int i, j, k, count = 0;
    int ni, nj; //nouveau i et j
    t_direction direc = direction_debut();
    for(i = 0; i < grille->longueur; i++){
        for(j = 0; j < grille->largeur; j++){
            while(direc < NB_DIRECTION){
                count = 0;
                ni = i;
                nj = j;
                for(k = 0; k < nbJetons; k++){
                    fprintf(stderr, "Direction : %d\n", direc);
                    if(est_valide(ni,nj,grille) && ((joueur->couleur == lire_couleur_joueur_slot(ni, nj, 1, grille)) || (joueur->couleur == lire_couleur_joueur_slot(ni, nj, 2, grille)))){
                        count++;
                    }
                    if(count >= nbJetons) return 1;
                    direction_avancer( i, j, direc, &ni, &nj, grille);
                }
                direction_suivante(direc);
            }
        }
    }
    return 0;
}

int un_gagnant(t_grille * grille, int nJetons, t_joueur * joueur, int nbJoueurs){
    for(int i = 0; i < nbJoueurs; i++){
        if(gagnant(grille, nJetons, joueur+i)) return 1;
    }
    return 0;
}

/**
* \fn nonPleine
* \param une piece, uhn entier pour le nombre de colonnes,un pointeur sur une grille, un pointeur sur un joueur
* \return la fonction retourne un entier
* \brief cette fonction teste si il reste de la place dans une colonne donnee, si il en reste elle renvoie 1 sinon 0. elle affecte grace a un pointeur la position de la premiere case vide de la colonne
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


/**
* \fn tour_joueur
* \param un pointeur sur un joueur,un pointeur sur une grille
* \return la fonction ne retourne rien 
* \brief cette fonction fait jouer un joueur. elle demande de saisir la colonne et la piece. elle met a jour la grille.
*/
void tour_joueur(t_joueur* joueur, t_grille * grille){
    int type = saisir_type(joueur);
    int col;
    
    
    /* Demande de saisie de la colonne. Penser à vérifier que col est un entier plus tard. */
    do{
        printf("Veuillez hoisir le numéro de la colonne pour jouer (entier entre 1 et %d): ", grille->largeur);
        scanf("%d", &col);
    }while(!nonPleine(type-1, col-1, grille, joueur) && col <= 0 && col >= grille->largeur);
}

/**
* \fn joueurVsjoueur 
* \param un pointeur sur une grille, un pointeur sur un joueur, un entier pour le nombre de joueur
* \return la fonction ne retourne rien 
* \brief cette fonction contient la boucle principale du mode de jeu joueur contre joueur
*/
void joueurVSjoueur(t_grille * grille, t_joueur * joueur, int nb_joueur){ 
    int i;
    char color;
    int test_color;
    char *couleur = malloc(sizeof(char)*nb_joueur);

    for(int i = 0; couleur[i]; i++) couleur[i] = 0;

    /*Saisie des pseudos en fonctions du nombre de joueurs*/
    for(i = 0; i < nb_joueur; i++){
        printf("\nPseudo joueur %d : ", i+1);
        scanf("%s", joueur[i].pseudo);
        joueur[i].nJoueur = i+1;
        do{
            test_color = 0;
            printf("\n Choisis ta couleur parmi celles disponibles : Red (R), Green (G), Blue (B), Yellow (Y), White (W), Pink (P)) : ");
            scanf(" %c", &color);
            if(color != 'R' && color != 'G' && color != 'B' && color != 'Y' && color != 'W' && color != 'P')
                printf("\nVeuillez choisir l'initiale des couleurs proposées.");
            for(int j = 0; couleur[j]; j++){
                if(couleur[j] == color){
                    printf("\nCette couleur a déjà été sélectionnée par un autre joueur !");
                    test_color = 1;
                }
            }
        }while((color != 'R' && color != 'G' && color != 'B' && color != 'Y' && color != 'W' && color != 'P') || test_color == 1);
        

        switch(color){
            case 'R' : joueur[i].couleur = RED;
                       couleur[i] = 'R';
                       break;
            case 'G' : joueur[i].couleur = GREEN;
                       couleur[i] = 'G';
                       break;
            case 'Y' : joueur[i].couleur = YELLOW;
                       couleur[i] = 'Y';
                       break;
            case 'B' : joueur[i].couleur = BLUE;
                       couleur[i] = 'B';
                       break;
            case 'W' : joueur[i].couleur = WHITE;
                       couleur[i] = 'W';
                       break;
            case 'P' : joueur[i].couleur = PINK;
                       couleur[i] = 'P';
                       break;
        }
    }

    int fin = 0;
    while(/*!un_gagnant(grille, 4, joueur, nb_joueur)*/!fin){
        //system("clear");
        grille->p_affiche((t_objet * )grille);
        for( i = 0; i < nb_joueur; i++){
            printf("Au tour de J%d %s : \n", joueur[i].nJoueur ,joueur[i].pseudo);
            tour_joueur(joueur+i, grille);
            //system("clear");
            grille->p_affiche((t_objet * )grille);
            if(/*gagnant(grille, 4, joueur+i)*/!fin){
                printf("%s a gagné !! \n", joueur[i].pseudo);
                /*Appel de la save des scores à faire quand la fonction sera fini*/
            }
        }
    }
}
