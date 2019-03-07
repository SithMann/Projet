#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include "grille.h"

#define M 20 /* Taille max pour le pseudo */

/* A coder */
int gagnant(t_case ** grille){
    return 0;
}

/* Fonction pour tester qu'il reste de la place dans une colonne
 * Renvoie 1 s'il y a de la place, 0 sinon. Affecte par pointeur la position de la première case vide de la colonne
 * Attention, à reprendre avec les différents types de pieces.
 */

int nonPleine(t_piece piece, int nbCol, int nbLig, t_case ** grille){

    switch(piece.type){
        /* Cas 1 et 2 à ajuster en fonctions des règles 
        * Cas 1 : Creuses : Si il y a une pleine la creuse va directement dans la pleine
        * Elle descend le plus bas si il n'y a que des pleines jusqu'à une bloquante ou une creuse
        * Cas 2 : Pleines : Si il y a une creuse la pleine va directement dans la creuse
        * Elle descend le plus bas si il n'y a que des creuses jusqu'à une bloquante ou une pleine
        */
        case 1 : //Pièces creuses
                if((grille[0][nbCol].piece1 == NULL) || ((grille[0][nbCol].piece1->type == 2) && (grille[0][nbCol].piece2 == NULL))){
                    printf("COUCOU\n");
                    ajouter_piece(0, nbCol, grille, piece);
                    return 1;
                }else{
                    for(int i = 1; i < nbLig; i++){
                        if(grille[i][nbCol].piece1 == NULL){
                            if((grille[i + 1][nbCol].piece1->type == 3) || (grille[i + 1][nbCol].piece1->type == 1)){
                                ajouter_piece(i, nbCol, grille, piece);
                                return 1;
                            }
                            else if((grille[i+1][nbCol].piece1->type == 2) && (grille[i+1][nbCol].piece2->type == 1)){
                                ajouter_piece(i, nbCol, grille, piece);
                                return 1;
                            }
                        }
                        else if((grille[i][nbCol].piece1->type == 2) && (grille[i][nbCol].piece2 == NULL)){
                            ajouter_piece(i, nbCol, grille, piece);
                            return 1;
                        }
                    }
                }
                break;
        case 2 :
                for(int i = 1; i < nbLig; i++){
                    if(grille[i][nbCol].piece1 == NULL){
                        if((grille[i + 1][nbCol].piece1->type == 3) || (grille[i + 1][nbCol].piece1->type == 2)){
                            ajouter_piece(i, nbCol, grille, piece);
                            return 1;
                        }
                        else if((grille[i+1][nbCol].piece1->type == 1) && (grille[i+1][nbCol].piece2->type == 2)){
                            ajouter_piece(i, nbCol, grille, piece);
                            return 1;
                        }
                    }
                    else if((grille[i][nbCol].piece1->type == 1) && (grille[i][nbCol].piece2 == NULL)){
                        ajouter_piece(i, nbCol, grille, piece);
                        return 1;
                    }
                }
                break;
        /* Cas 3 : BLOQUANTES OK */
        case 3 : 
                for(int i = nbLig-1; i > 0; i--){
                    if(grille[i][nbCol].piece1 == NULL){
                        ajouter_piece(i, nbCol, grille, piece);
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
void tour_joueur(t_joueur joueur, t_case ** grille, int nb_ligne, int nb_colonne){
    
    t_piece piece;
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
        scanf("%d", &piece.type);
    }while(piece.type <= 0 && piece.type >= 4);

    /* Demande de saisie de la colonne. Penser à vérifier que col est un entier plus tard. */
    do{
        printf("Veuillez hoisir le numéro de la colonne pour jouer (entier entre 1 et %d): ", nb_colonne);
        scanf("%d", &col);
    }while(!nonPleine(piece, col-1, nb_ligne, grille) && col <= 0 && col >= nb_colonne);
}


/*Save des scores
*  \/\
* \/| \   A FINIR
*\/ °  \
*--------
*//*
void save(t_joueur winner){
    
    char* name = winner.pseudo;
    FILE * score=fopen("score.txt","r");
    if( score == NULL )
        return 0;

    if(name == fscanf(score,"",))
    fprintf(f,"Le joueur %s a %d victoires", joueur[i].pseudo, joueur[i].nbWin);
}*/

/* Fonction contenant la boucle principale du mode de jeu jVj.*/
void joueurVSjoueur(t_case **grille, t_joueur *joueur, int nb_joueur, int nb_ligne, int nb_colonne){ 
    int i;
    char color = RED;

    /*Saisie des pseudos en fonctions du nombre de joueurs*/
    for(i = 0; i < nb_joueur; i++){
        printf("Pseudo joueur %d : ", i+1);
        scanf("%s", joueur[i].pseudo);
        //problème ici, il skip le scanf
        printf("Choisis ta couleur parmi celles disponibles : Rouge (R), Vert (G), Bleue (B), Jaune (Y), Blanc (W), Rose (P)) : ");
        scanf("%c", &color);

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
    /*Check si le pseudo existe déjà et augmenter son nombre de win en fonction du précédent*/
    //segmentation fault dans cette boucle => ok mais mnt le programme s'arrete après le premier coup
    int k =0;
    while(!k){
        system("clear");
        afficher_grille(nb_ligne, nb_colonne, grille);
        for( i = 0; i < (sizeof(t_joueur) * nb_joueur); i++){
            printf("Au tour de J%d %s : \n", joueur[i].nJoueur ,joueur[i].pseudo);
            tour_joueur(joueur[i], grille, nb_ligne, nb_colonne);
            system("clear");
            afficher_grille(nb_ligne, nb_colonne, grille);
            if(/*gagnant(grille)*/k){
                printf("%s à gagné !! \n", joueur[i].pseudo);
                /*Appel de la save des scores à faire quand la fonction sera fini*/
            }
        }
    }
}

/*Fonction affichant le menu de sélection du début*/
void menu_joueur(t_case **grille, int * nb_ligne, int * nb_colonne){
    int niveau;/*Choix du niveau*/
    int nb_pion;/*Nombre de pions à aligner qui influence sur la taille de la grille*/
    int nb_joueur;/*Nombres de joueurs qui influence aussi la taille de la grille*/
    int nb_case = 0;
    int nb_piece_b; // Pièces bloquantes
    int nb_piece_p; // Pièces pleines
    int nb_piece_c; // Pièces creuses

    do{
        printf("Nombres de joueurs : ");
        printf("\n\t1- 4 joueurs");
        printf("\n\t2- 5 joueurs");
        printf("\n\t3- 6 joueurs");

        printf("\nChoix du nombre de joueurs : ");
        scanf("%d", &nb_joueur);
        if(nb_joueur < 1 || nb_joueur > 3) printf("Le choix doit être compris entre 1 et 3\n");
    }while(nb_joueur < 1 || nb_joueur > 3);
        
    /*
    *Réattribution des valeurs à nb_joueur pour le nb_joueur en jeu, en 
    *du nombre de lignes et de colonnes
    */
    if(nb_joueur == 1) nb_joueur = 4; 
    if(nb_joueur == 2) nb_joueur = 5;
    if(nb_joueur == 3) nb_joueur = 6;
    
    t_joueur* joueur = malloc(sizeof(t_joueur) * nb_joueur);

    do{
        printf("Nombres de pions à aligner : ");
        printf("\n\t1- 4 pions");
        printf("\n\t2- 5 pions");
        printf("\n\t3- 6 pions");

        printf("\nChoix du nombres de pions : \n");
        scanf("%d",&nb_pion);
        if(nb_pion < 1 || nb_pion > 3) printf("Le choix doit être compris entre 1 et 3\n");
    }while(nb_pion < 1 || nb_pion > 3);

     /*
    *Réattribution des valeurs à nb_pions pour le nb_pions à aligner en vue des calculs 
    *du nombre de lignes et de colonnes
    */
    if(nb_pion == 1) nb_pion = 4; 
    if(nb_pion == 2) nb_pion = 5;
    if(nb_pion == 3) nb_pion = 6;

    do{ 
        printf("\nNiveau de difficulté : ");
        printf("\n\t1- Facile");
        printf("\n\t2- Moyen");
        printf("\n\t3- Difficile");

        printf("\nChoix du niveau : ");
        scanf("%d",&niveau);
        if(niveau < 1 || niveau > 3) printf("Le choix doit être compris entre 1 et 3\n");
    }while(niveau < 1 || niveau > 3);

    *nb_ligne = nb_joueur + nb_pion * ++niveau;
    *nb_colonne = nb_joueur + nb_pion * ++niveau;

    nb_case = (*nb_ligne) * (*nb_colonne);

    nb_piece_c = (nb_case / nb_joueur) * 1.75 ;
    nb_piece_p = (nb_case / nb_joueur) * 1.75 ;
    nb_piece_b = nb_case - (nb_piece_c + nb_piece_p);

    int nb_piece_b_f = (int)nb_piece_b; // Pièces bloquantes
    int nb_piece_p_f = (int)nb_piece_p; // Pièces pleines
    int nb_piece_c_f = (int)nb_piece_c; // Pièces creuses

    if(nb_piece_b_f + nb_piece_c_f + nb_piece_p_f != (int)nb_case)
        nb_piece_b_f++;

    for(int i = 0; i < nb_joueur; i++){
        creerPiece(1, nb_piece_p_f, joueur[i]);
        creerPiece(2, nb_piece_c_f, joueur[i]);
        creerPiece(3, nb_piece_b_f, joueur[i]);
    }
    
    /*Appel de la fonction joueur VS joueur*/
    joueurVSjoueur(grille, joueur, nb_joueur, *nb_ligne, *nb_colonne); /*Nombres de joueurs à faire*/

}

/*
void joueurVSia(int *niveau, int *nb_joueur){

}*/

int main(){

    int choix; /*Choix du joueur pour le début du jeu*/
    int nb_ligne = 0;
    int nb_colonne = 0;
    t_case **grille = init_grille(12,12,grille);
    
    while(1){
        printf("Selectionnez le mode de jeu : \n");
        printf("1- Joueur vs IA \n");
        printf("2- Joueur vs Joueur \n");
        printf("3- Quitter \n");

        printf("\n\n Choix : ");
        scanf("%d", &choix);

        switch(choix){
            case 1 : /*joueurVSia(grille);*/
                    printf("En dev !");
                    break;
            case 2 : menu_joueur(grille, &nb_ligne, &nb_colonne);
                    break;
            case 3 : exit(1);
                    break;
        }
    }
    return 0;
}

