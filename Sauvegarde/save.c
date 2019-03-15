#include <stdio.h>
#include <stdlib.h>
#include "save.h"

void save(t_joueur joueur){
    
    char* name = joueur.pseudo;
    char* data = malloc(sizeof(char));
    FILE * score=fopen("score.txt","r");
    if( score == NULL )
        return 0;
    else{

        if(strcmp(name, fscanf(score,"%s",name))){ //Regarde si le joueur a déjà gagner une partie dans le fichier .txt et en ajoute une de plus
            fclose(score);
            score = fopen("score.txt","w");
            fprintf(score," %s a : %d victoire(s)", joueur.pseudo, joueur.nbWin + 1);
        }
        else{ //Sinon l'inscrit dans le fichier .txt
            fprintf(score, "%s a : %d victoire(s)", joueur.pseudo, joueur.nbWin);
        }
    }
    
}