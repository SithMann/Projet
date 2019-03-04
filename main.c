/* Notes à moi même (et autre chieuse ou rouquin du groupe) :
 * Peut-être faire une structure pièce pour décompter le nombre de pièces utilisées, afficher une pièce, connaitre la valeur numérique de la piece.
 */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
 
#define L 7 /*Lignes*/
#define C 7 /*Colonnes*/
#define N 7 /* Nombre dsiponible de chaque type de pièce */
#define M 20 /* Taille max pour le pseudo */

/* structure de données relatives à une piece */
typedef struct piece_s {
    int nb_piece; /*Compteur*/
    char * couleur; /*Jaune ou rouge*/
    int valeur; /*Pleine,creuse,bloquantes*/
}piece_t;

/* structure de données relatives à un joueur */
typedef struct joueur_s {
    int nJoueur;
    char * pseudo;
}joueur_t;

/* fonction de création d'un joueur */
void creer_joueur(joueur_t * joueur, int n){
    joueur->nJoueur = n;
    joueur->pseudo = malloc(sizeof(char)*M);
}

/* fonction de création d'une piece */
void creer_piece(piece_t * piece, int n){
    piece->nb_piece = N;
    piece->valeur = n;
    piece->couleur = malloc(sizeof(char)*M);
}

/* Initialisation de la grille */
void init_grille(char grille[L][C]){ 
    for(int i = 0; i < L; i++){
        for(int j = 0; j < C; j++)
            grille[i][j] = ' ';
    }
}

/*Affichage de la grille */
void afficher_grille(char grille[L][C]){
    for(int i = 0; i < L; i++){
        for(int j = 0; j < C; j++)
            printf("%c |", grille[i][j]);
        printf("\n");            
    }
}

/* A coder */
int gagnant(char grille[C][L]){
    return 0;
}

/* Fonction pour tester qu'il reste de la place dans une colonne
 * Renvoie 1 s'il y a de la place, 0 sinon. Affecte par pointeur la position de la première case vide de la colonne
 * Attention, à reprendre avec les différents types de pieces.
*/
int nonPleine(piece_t piece, int nbCol, int * pos, char grille[L][C]){

    switch(piece.valeur){
        /* Cas 1 et 2 à ajuster en fonctions des règles (j'ai oublié entre creuses et pleines, qui bloque qui) */
        case 1 :
                for(int i = L-1; i >= 0; i--){
                    if(grille[i][nbCol] == ' '){
                        *pos = i;
                        return 1;
                    }
                }
                break;
        case 2 :
                for(int i = L-1; i >= 0; i--){
                    if(grille[i][nbCol] == ' '){
                        *pos = i;
                        return 1;
                    }
                }
                break;
        /* Cas 3 OK */
        case 3 :
                for(int i = L-1; i >= 0; i--){
                    if(grille[i][nbCol] == ' '){
                        *pos = i;
                        return 1;
                    }
                }
                break;
    }
    return -1;
}

/* Fonction qui fait jouer un joueur. Demande la saisie de la colonne et de la piece.
 * Met à jour la grille et ne renvoie rien.
*/
int tour_joueur(int nJoueur, char grille[L][C]){
    int col, pos;

    piece_t piece;
    creer_piece(&piece,0);
    if(nJoueur) piece.couleur = "jaune";
    else piece.couleur = "rouge";
     

    /* Demande de saisie de la piece. Penser à vérifier que piece est un entier plus tard.
     * Il faudrat aussi prendre en compte le nombre disponible de chaque piece pour la suite.
    */
    printf("Choix du type de pièce à jouer : \n");
    printf("1- Pleine \n");
    printf("2- Creuse \n");
    printf("3- Bloquante \n");
    do{
        printf("Choix : ");
        scanf("%d", &piece.valeur);
    }while(piece.valeur <= 0 && piece.valeur >= 4);

    /* Demande de saisie de la colonne. Penser à vérifier que col est un entier plus tard. */
    do{
        printf("Veuillez hoisir le numéro de la colonne pour jouer (entier entre 1 et 7): ");
        scanf("%d", &col);
    }while(!nonPleine(piece, col, &pos, grille) && col <= 0 && col >= 8);

    /* Ajout de la piece */
    switch(piece.valeur){
        case 1: if(nJoueur == 1) grille[pos][col] = 'P';
                else grille[pos][col] = 'p';

                break;
        case 2: if(nJoueur == 1) grille[pos][col] = 'C';
                else grille[pos][col] = 'c';
                break;
        case 3: if(nJoueur == 1) grille[pos][col] = 'B';
                else grille[pos][col] = 'b';
                break;
    }
/*<<<<<<< HEAD
=======
    if(gagnant(grille)) return nJoueur;
    return 0; 
>>>>>>> e97989755d70383f0b6334f8299111514e97efa8*/
}

/* Fonction contenant la boucle principale du mode de jeu jVj.*/
void joueurVSjoueur(char *grille, joueur_t joueur[], int nb_joueur){ 
    int i;

    for(i = 0; joueur[i].nJoueur; i++){
        printf("\nPseudo joueur %d : ", ++i);
        scanf("%s", joueur[i].pseudo);
    }

    while(!gagnant(grille)){
        system("clear");
        afficher_grille(grille);
        for( i = 0; i < (sizeof(joueur_t) * nb_joueur); i++){
            printf("Au tour de J%d %s : \n", joueur[i].nJoueur ,joueur[i].pseudo);
            tour_joueur(joueur[i].nJoueur, grille);
            system("clear");
            afficher_grille(grille);
            if(gagnant(grille)) 
                printf("%s à gagné !! \n", joueur[i].pseudo);
        }
    }
}

/*Fonction affichant le menu de sélection du début*/
void menu_joueur(){
    int niveau;/*Choix du niveau*/
    int nb_pion;/*Nombre de pions à aligner qui influence sur la taille de la grille*/
    int nb_joueur;/*Nombres de joueurs qui influebnce aussi la taille de la grille*/
    int nb_ligne = 0; /*Nombre de lignes avant le choix de la difficulté*/
    int nb_colonne = 0; /*Nombre de colonnes avant le choix de la difficulté*/
    
    do{
        printf("Nombres de joueurs :");
        printf("\n\t1- 4 joueurs");
        printf("\n\t2- 5 joueurs");
        printf("\n\t3- 6 joueurs");

        printf("Choix du nombre de joueurs : ");
        scanf("%d", &nb_joueur);
        if(nb_joueur < 1 || nb_joueur > 3) printf("Le choix doit être compris entre 1 et 3");
    }while(nb_joueur < 1 || nb_joueur > 3);
        
    /*Réattribution des valeurs à nb_joueur pour le nb_joueur en jeu, en vue des calculs 
    *du nombre de lignes et de colonnes
    */
    if(nb_joueur == 1) nb_joueur = 4; 
    if(nb_joueur == 2) nb_joueur = 5;
    if(nb_joueur == 3) nb_joueur = 6;
    
    joueur_t joueur[] = malloc(sizeof(joueur_t) * nb_joueur);

    do{
        printf("Nombres de pions à aligner : ");
        printf("\n\t1- 4 pions");
        printf("\n\t2- 5 pions");
        printf("\n\t3- 6 pions");

        printf("Choix du nombre de pions à aligner : ");
        scanf("%d", &nb_pion);
        if(nb_pion < 1 || nb_pion > 3) printf("Le choix doit être compris entre 1 et 3");
    }while(nb_pion < 1 || nb_pion > 3);
    
    /*Réattribution des valeurs à nb_pions pour le nb_pions à aligner en vue des calculs 
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

        printf("Choix du niveau : \n");
        scanf("%d",&niveau);
        if(niveau < 1 || niveau > 3) printf("Le choix doit être compris entre 1 et 3");
    }while(niveau < 1 || niveau > 3);

    nb_ligne = nb_joueur + nb_pion * ++niveau;
    nb_colonne = nb_joueur + nb_pion * ++niveau;

    /*Appel de la fonction joueur VS joueur*/
    joueurVSjoueur(grille[nb_ligne][nb_colonne], joueur, nb_joueur); /*Nombres de joueurs à faire*/

}

/*
void joueurVSia(int *niveau, int *nb_joueur){

}*/

int main(){

    char grille[L][C];
    int choix, niveau, ligne, colonne, nb_joueur;
    joueur_t j1, j2;
    creer_joueur(&j1, 1);
    creer_joueur(&j2, 2);
    
    printf("Selectionnez le mode de jeu : \n");
    printf("1- Joueur vs IA \n");
    printf("2- Joueur vs Joueur \n");
    printf("3- Quitter \n");

    printf("\n\n Choix : ");
    scanf("%d", &choix);

    init_grille(grille);

    switch(choix){
        case 1 : /*joueurVSia(grille);*/
                printf("En dev !");
                break;
        case 2 : joueurVSjoueur(grille, &j1, &j2);/*Appel de menu_joueurvsjoueur plutôt que joueurvsjoueur*/
                break;
        case 3 : exit(1);
                break;
    }

    return 0;
}

