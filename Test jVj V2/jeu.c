#include <stdlib.h>
#include <stdio.h>
#include "objet.h"
#include "grille.h"

int gagnant(t_grille * grille, int nbJetons, t_joueur joueur){
    int count = 0;
    // Test victoire vertical
    for(int i = 0; i < grille->longueur; i++){
        for(int j = 0; j< grille->largeur; j++){
            if(grille->laGrille[i][j]->slot1->joueur->nJoueur == joueur.nJoueur ||  grille->laGrille[i][j]->slot2->joueur->nJoueur == joueur.nJoueur)
                count++;
            else count = 0;
            if(count == nbJetons) return 1;
        }
    }

    // Test victoire horizontal
    for(int i = 0; i < grille->longueur; i++){
        for(int j = 0; j< grille->largeur; j++){
            if(grille->laGrille[j][i]->slot1->joueur->nJoueur == joueur.nJoueur ||  grille->laGrille[j][i]->slot2->joueur->nJoueur == joueur.nJoueur)
                count++;
            else count = 0;
            if(count == nbJetons) return 1;
        }
    }

    // Test diagonale gauche

    return 0;
}

/* Fonction pour tester qu'il reste de la place dans une colonne
 * Renvoie 1 s'il y a de la place, 0 sinon. Affecte par pointeur la position de la première case vide de la colonne
 * Attention, à reprendre avec les différents types de pieces.
 */

int nonPleine(t_piece piece, int nbCol, t_grille * grille, t_joueur joueur){

    switch(piece){
        /* Cas 1 et 2 à ajuster en fonctions des règles 
        * Cas 1 : Creuses : Si il y a une pleine la creuse va directement dans la pleine
        * Elle descend le plus bas si il n'y a que des pleines jusqu'à une bloquante ou une creuse
        * Cas 2 : Pleines : Si il y a une creuse la pleine va directement dans la creuse
        * Elle descend le plus bas si il n'y a que des creuses jusqu'à une bloquante ou une pleine
        */
        case PLEINE :if((grille->laGrille[grille->longueur-1][nbCol]->slot1 == NULL) || ((grille->laGrille[grille->longueur-1][nbCol]->slot1->piece == CREUSE) && (grille->laGrille[grille->longueur-1][nbCol]->slot2 == NULL))){
                    ajouter_piece(grille->longueur-1, nbCol, grille, piece, joueur);
                    return 1;
                }else{
                    for(int i = 1; i < grille->longueur; i++){
                        if(grille->laGrille[i][nbCol]->slot1 == NULL){
                            if((grille->laGrille[i + 1][nbCol]->slot1->piece == BLOQUANTE) || (grille->laGrille[i + 1][nbCol]->slot1->piece == PLEINE)){
                                ajouter_piece(i, nbCol, grille, piece, joueur);
                                return 1;
                            }
                            else if((grille->laGrille[i+1][nbCol]->slot1->piece == CREUSE) && (grille->laGrille[i+1][nbCol]->slot2 == NULL)){
                                ajouter_piece(i, nbCol, grille, piece, joueur);
                                return 1;
                            }
                        }
                        else if((grille->laGrille[i][nbCol]->slot1->piece == CREUSE) && (grille->laGrille[i][nbCol]->slot2 == NULL)){
                            ajouter_piece(i, nbCol, grille, piece, joueur);
                            return 1;
                        }
                    }
                }
                break;
        case CREUSE :if((grille->laGrille[grille->longueur-1][nbCol]->slot1 == NULL) || ((grille->laGrille[grille->longueur-1][nbCol]->slot1->piece == PLEINE) && (grille->laGrille[grille->longueur-1][nbCol]->slot2 == NULL))){
                    ajouter_piece(grille->longueur-1, nbCol, grille, piece, joueur);
                    return 1;
                }else{
                    for(int i = 1; i < grille->longueur; i++){
                        if(grille->laGrille[i][nbCol]->slot1 == NULL){
                            if((grille->laGrille[i + 1][nbCol]->slot1->piece == BLOQUANTE) || (grille->laGrille[i + 1][nbCol]->slot1->piece == CREUSE)){
                                ajouter_piece(i, nbCol, grille, piece, joueur);
                                return 1;
                            }
                            else if((grille->laGrille[i+1][nbCol]->slot1->piece == PLEINE) && (grille->laGrille[i+1][nbCol]->slot2 == NULL)){
                                ajouter_piece(i, nbCol, grille, piece, joueur);
                                return 1;
                            }
                        }
                        else if((grille->laGrille[i][nbCol]->slot1->piece == PLEINE) && (grille->laGrille[i][nbCol]->slot2 == NULL)){
                            ajouter_piece(i, nbCol, grille, piece, joueur);
                            return 1;
                        }
                    }
                }
                break;
        /* Cas 3 : BLOQUANTES OK */
        case BLOQUANTE : 
                for(int i = grille->longueur-1; i > 0; i--){
                    if(grille->laGrille[i][nbCol]->slot1 == NULL){
                        ajouter_piece(i, nbCol, grille, piece, joueur);
                        return 1;
                    }
                }
                break;
        default :     printf("Erreur\n");
    }
    return -1;
}



/* Fonction qui fait jouer un joueur. Demande la saisie de la colonne et de la piece.
 * Met à jour la grille et ne renvoie rien.
*/
void tour_joueur(t_joueur joueur, t_grille * grille){
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
        if(!joueur.piece[type-1])
            printf("Plus de pieces de ce type disponible !\n");
    }while((type <= 0 && type >= 4) || !joueur.piece[type-1]);
    
    /* Demande de saisie de la colonne. Penser à vérifier que col est un entier plus tard. */
    do{
        printf("Veuillez hoisir le numéro de la colonne pour jouer (entier entre 1 et %d): ", grille->largeur);
        scanf("%d", &col);
    }while(!nonPleine(joueur.piece[type-1], col-1, grille, joueur) && col <= 0 && col >= grille->largeur);
}

/* Fonction contenant la boucle principale du mode de jeu jVj.*/
void joueurVSjoueur(t_grille * grille, t_joueur * joueur, int nb_joueur){ 
    int i;
    char color;

    /*Saisie des pseudos en fonctions du nombre de joueurs*/
    for(i = 0; i < nb_joueur; i++){
        printf("Pseudo joueur %d : ", i+1);
        scanf("%s", joueur[i].pseudo);
        joueur[i].nJoueur = i+1;
        printf("Choisis ta couleur parmi celles disponibles : Rouge (R), Vert (G), Bleue (B), Jaune (Y), Blanc (W), Rose (P)) : ");
        scanf(" %c", &color);

        switch(color){
            case 'R' : joueur[i].couleur = RED;
                       break;
            case 'G' : joueur[i].couleur = GREEN;
                       break;
            case 'Y' : joueur[i].couleur = YELLOW;
                       break;
            case 'B' : joueur[i].couleur = BLUE;
                       break;
            case 'W' : joueur[i].couleur = WHITE;
                       break;
            case 'P' : joueur[i].couleur = PINK;
                       break;
        }
    }


    int fin =0;
    while(!fin){
        system("clear");
       /*afficher_grille(nb_ligne, nb_colonne, grille);*/
        for( i = 0; i < nb_joueur; i++){
            printf("Au tour de J%d %s : \n", joueur[i].nJoueur ,joueur[i].pseudo);
            tour_joueur(joueur[i], grille);
            system("clear");
            grille->p_affiche((t_objet * )grille);
            if(/*gagnant(grille)*/fin){
                printf("%s a gagné !! \n", joueur[i].pseudo);
                /*Appel de la save des scores à faire quand la fonction sera fini*/
            }
        }
    }
}