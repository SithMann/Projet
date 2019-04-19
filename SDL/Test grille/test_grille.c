#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>


void afficher_image(SDL_Renderer *renderer, SDL_Texture *image_tex, SDL_Rect imgDestRect){
	SDL_QueryTexture(image_tex, NULL, NULL, &(imgDestRect.w), &(imgDestRect.h));
	SDL_RenderCopy(renderer, image_tex, NULL, &imgDestRect);
}

void afficher_texte(SDL_Rect *ptxtDestRect, SDL_Renderer *renderer, SDL_Color couleurTitre, SDL_Surface *texte, int taille, char *chaine){
	SDL_Rect txtDestRect = *ptxtDestRect;
	TTF_Font *police = TTF_OpenFont("Sketch 3D.otf", taille);	

	texte = TTF_RenderUTF8_Blended(police, chaine, couleurTitre);
	SDL_Texture *texte_tex = SDL_CreateTextureFromSurface(renderer, texte);  
	SDL_QueryTexture(texte_tex, NULL, NULL, &(txtDestRect.w), &(txtDestRect.h));
	fprintf(stderr, "%s ,coord w : %d, h : %d\n", chaine, txtDestRect.w, txtDestRect.h);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderCopy(renderer, texte_tex, NULL, &txtDestRect);

	TTF_CloseFont(police);
}

#define NB_BOUTON 3 //Menu principal

/*Faire une fonction qui fait une colonne en fonction du nombre de ligne choisies*/
void creer_grille(int nb_ligne, int nb_colonne, SDL_Renderer *renderer, SDL_Texture *image_tex){
	SDL_Rect imgDestRect = {200,100,100,100}; //{point de départ en x, point de départ en y, largeur image, longueur image}
	for(int i = 0; i < nb_colonne; i++){
		for(int j = 1; j <= nb_ligne; j++){
			imgDestRect.y += imgDestRect.h;
			SDL_RenderCopy(renderer, image_tex, NULL, &imgDestRect);
		}
		imgDestRect.x += imgDestRect.h;
		imgDestRect.y = 100;
	}
}
	
void choseConstantes(SDL_Renderer *renderer, SDL_Texture *image_tex){
	SDL_Color couleurTitre = {44, 117, 255};
	SDL_Rect txtDestRect, imgDestRect;
	
	txtDestRect.x = 545;
	txtDestRect.y = 100;

	imgDestRect.x = 10;
	imgDestRect.y = 50;
	
	SDL_SetRenderDrawColor(renderer, 44, 75, 111, 255);
	SDL_RenderClear(renderer);

	afficher_image(renderer, image_tex, imgDestRect);
	afficher_texte(&txtDestRect,renderer, couleurTitre, NULL, 50, "PUISSANCE 4++");

}

/*Créer une structure pour le bouton avec ses tailles et une autre pour le menu où on utilise un tableau de bouton*/

static char* NOM_BOUTON_MENU_PRINC[NB_BOUTON] = {"JoueurVsOrdi", "JoueurVsJoueur", "Quitter"};

void creer_bouton_menu_princ(int x, int y, SDL_Surface *bouton, SDL_Renderer *renderer){
	int i;
	TTF_Font *police = TTF_OpenFont("Sketch 3D.otf", 50); //ouverture de la police
	SDL_Surface *texte;
	SDL_Texture *texte_tex;
	SDL_Rect txtDestRect;
	SDL_Color couleurNom = {255, 255, 255};

	txtDestRect.x = x - 200;
	txtDestRect.y = y - 100;
	bouton = SDL_CreateRGBSurface(0, txtDestRect.y, txtDestRect.x, 32, 0, 0, 0, 255);

	for(i = 0; i < NB_BOUTON; i++){
		texte = TTF_RenderUTF8_Blended(police, NOM_BOUTON_MENU_PRINC[i], couleurNom);
		texte_tex = SDL_CreateTextureFromSurface(renderer, texte); 
		SDL_QueryTexture(texte_tex, NULL, NULL, &(txtDestRect.w), &(txtDestRect.h)); //met la width et la height dans txtDestRect
		SDL_RenderCopy(renderer, texte_tex, NULL, &txtDestRect);
		txtDestRect.y += 100;
	}
	TTF_CloseFont(police);
}




int main(int argc, char** argv){
	//Nombres de ligne et colonne temporaire
	int nb_ligne, nb_colonne; 
    int nb_joueurs_jVj = 4;//J vs J
    int difficulte = 1; //1 = facile, 2 = moyen, 3 = difficile
    int nb_ordi = 3; //Nombre d'ordi dans le mode joueur vs IA
    int nb_joueur_jVia = 1; // nombre de joueur dans le mode joueur vs IA
    int nb_pions = 4;//nombre de pions à aligner

    //Le pointeur vers la fenetre
	SDL_Window* pWindow = NULL; //crée une variable qui prend les coordonnées de la fenêtre 
	int w_pWindow, h_pWindow;
	//Le pointeur vers la surface incluse dans la fenetre
    SDL_Surface *texte = NULL, *image = NULL;
	SDL_Surface *bouton = NULL;
	SDL_Renderer *renderer = NULL;//Fais office d'écran, un seul par programme, c'est ce que l'on met à jour
	SDL_Rect txtDestRect,imgDestRect, coordsouris;//rectangle imaginaire pour placer mes textures et pour les utiliser

	SDL_Surface *caseGrille = NULL;
	SDL_Surface *pleineR = NULL, *creuseR = NULL, *bloquanteR = NULL;
	SDL_Surface *pleineB = NULL, *creuseB = NULL, *bloquanteB = NULL;

	// Le pointeur vers notre police
	TTF_Font *police = NULL;
	// Une variable de couleur bleue
	SDL_Color couleurTitre = {44, 117, 255};

    /* Initialisation simple */
    if (SDL_Init(SDL_INIT_VIDEO) != 0 ) {
        fprintf(stdout,"Échec de l'initialisation de la SDL (%s)\n",SDL_GetError());
        return -1;
    } 

	/* Initialisation TTF */
	if(TTF_Init() == -1) {
		fprintf(stderr, "Erreur d'initialisation de TTF_Init : %s\n", TTF_GetError());
		exit(EXIT_FAILURE);
	}

	/* Création de la fenêtre */
	pWindow = SDL_CreateWindow("Puissance 4++",SDL_WINDOWPOS_UNDEFINED,
												  SDL_WINDOWPOS_UNDEFINED,
												  1920,
												  1080,
												  SDL_WINDOW_SHOWN|SDL_WINDOW_RESIZABLE);

	SDL_GetWindowSize(pWindow, &w_pWindow, &h_pWindow);
	printf("x main : %d, y main : %d\n", w_pWindow, h_pWindow);

	if(!pWindow){
		fprintf(stderr, "Erreur à la création de la fenetre : %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	renderer = SDL_CreateRenderer(pWindow, -1, SDL_RENDERER_ACCELERATED);
	if(renderer == NULL){
		fprintf(stderr, "Erreur à la création du renderer\n");
		exit(EXIT_FAILURE);
	}

	if( (police = TTF_OpenFont("Sketch 3D.otf", 50)) == NULL){
		fprintf(stderr, "erreur chargement font\n");
		exit(EXIT_FAILURE);
	}
	texte = TTF_RenderUTF8_Blended(police, "PUISSANCE 4++", couleurTitre);

	/*Test si erreur sur la création du texte*/
	if(!texte){
		fprintf(stderr, "Erreur à la création du texte : %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	SDL_Texture *texte_tex = SDL_CreateTextureFromSurface(renderer, texte); 
	if(!texte_tex){
		fprintf(stderr, "Erreur à la création du rendu du texte : %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}
	SDL_FreeSurface(texte); /* on a la texture, plus besoin du texte */
	/* Position ou sera mis le texte dans la fenêtre */
    txtDestRect.x = 545;
	txtDestRect.y = 100;
	SDL_QueryTexture(texte_tex, NULL, NULL, &(txtDestRect.w), &(txtDestRect.h));

	//Initialisation des textures pour chaque image que je charge
	SDL_Texture *caseGrille_tex, *image_tex;
	SDL_Texture *bloquanteR_tex, *pleineR_tex, *creuseR_tex; 
	SDL_Texture *bloquanteB_tex, *pleineB_tex, *creuseB_tex;

	typedef struct { SDL_Texture *tex; SDL_Rect pos;} t_texture;

	//Chargement, importation des images

	image = IMG_Load("transparent.gif");
	caseGrille = IMG_Load("case.png");

	bloquanteR = IMG_Load("bloquanteRouge.png");
	pleineR = IMG_Load("pleineRouge.png");
	creuseR = IMG_Load("creuseRouge.png");

	bloquanteB = IMG_Load("bloquanteBleue.png");
	pleineB = IMG_Load("pleineBleue.png");
	creuseB = IMG_Load("creuseBleue.png");

	/*Test si l'image a bien été get*/
	if(!bloquanteR) {
		printf("IMG_LoadPNG_RW: %s\n", IMG_GetError());
	}

	//Création des textures à partir de la surface de toutes mes textures
	caseGrille_tex = SDL_CreateTextureFromSurface(renderer, caseGrille);
	image_tex = SDL_CreateTextureFromSurface(renderer, image);

	bloquanteR_tex = SDL_CreateTextureFromSurface(renderer, bloquanteR);
	creuseR_tex = SDL_CreateTextureFromSurface(renderer, creuseR); 
	pleineR_tex = SDL_CreateTextureFromSurface(renderer, pleineR); 

	bloquanteB_tex = SDL_CreateTextureFromSurface(renderer, bloquanteB);
	creuseB_tex = SDL_CreateTextureFromSurface(renderer, creuseB); 
	pleineB_tex = SDL_CreateTextureFromSurface(renderer, pleineB); 

	if(!bloquanteR_tex){
		fprintf(stderr, "Erreur à la création du rendu de l'image : %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}
			
	SDL_FreeSurface(bloquanteR); /* on a la texture, plus besoin de l'image */
	SDL_FreeSurface(pleineR);
	SDL_FreeSurface(creuseR);

	SDL_FreeSurface(bloquanteB); /* on a la texture, plus besoin de l'image */
	SDL_FreeSurface(pleineB);
	SDL_FreeSurface(creuseB);

	int etat = 1;
	int compt = 0;
	if( pWindow ){
		int running = 1; 
		while(running) { //cas d'arrêt (bouton quitter)
			SDL_Event e; 
			while(SDL_PollEvent(&e)) { //attente d'un événement
				switch(e.type) { //Quel événement ?
					case SDL_QUIT: running = 0; //croix pour fermer la fenêtre
					break; 
					case SDL_MOUSEBUTTONUP: //cas d'un clic

        				if (e.button.button == SDL_BUTTON_LEFT){ /*Si clic gauche alors*/
							//récupération des coordonnées du clic
							coordsouris.x = e.button.x; 
							coordsouris.y = e.button.y;
                        }	

						switch(etat) {
							case 1 : if(coordsouris.x > 520 && coordsouris.x < 910 && coordsouris.y > 300 && coordsouris.y < 340){//coord des boutons en plein écran
										printf("Menu joueur contre ia\n");
										SDL_RenderClear(renderer);
										choseConstantes(renderer, image_tex);
										nb_ligne = nb_ordi + nb_joueur_jVia * difficulte;
										nb_colonne = nb_ordi + nb_joueur_jVia * difficulte + difficulte;
									 	
									 	SDL_RenderPresent(renderer);//affiche le renderer nue fois toute les modifs exécutées
										etat = 2;
									 }
									 else if(coordsouris.x > 520 && coordsouris.x < 980 && coordsouris.y > 430 && coordsouris.y < 480){//coord des boutons en plein écran
										printf("Menu joueur contre joueur\n");
										SDL_RenderClear(renderer);
										choseConstantes(renderer, image_tex);
										nb_ligne = nb_joueurs_jVj * nb_joueurs_jVj * difficulte;
										nb_colonne = nb_joueurs_jVj * nb_joueurs_jVj * difficulte + difficulte;

										SDL_RenderPresent(renderer);
										etat = 3;
									 }
									 else if(coordsouris.x > 520 && coordsouris.x < 730 && coordsouris.y > 500 && coordsouris.y < 540)//coord des boutons en plein écran
										running = 0;
									 printf("x : %d, y : %d \n", coordsouris.x, coordsouris.y);
									 break;

							case 2 : //printf("coord bouton dans l'ordre x : %d, y : %d\n", coordsouris.x, coordsouris.y);//Dans le menu joueur VS IA
									choseConstantes(renderer, image_tex);
									//Création de la grille
									creer_grille(nb_ligne, nb_colonne, renderer, caseGrille_tex);
		
									SDL_RenderPresent(renderer);

							case 3 : printf("\n");//Dans le menu joueur VS joueur
						}
					    break;

						/*Ce que je n'ai pas eu le temps de faire : 
						-Mettre chaque case de ma grille dans ma structure de texture avec leur coord (SDL_Rect)
						-Lier les programmes du terminal et ceux de la SDL pour avoir les algo de win etc
						-Gérer l'affichage des pièces
						*/



					case SDL_WINDOWEVENT:
						switch(e.window.event){
							case SDL_WINDOWEVENT_EXPOSED:
							case SDL_WINDOWEVENT_SIZE_CHANGED:
							case SDL_WINDOWEVENT_RESIZED:
							case SDL_WINDOWEVENT_SHOWN:
								/* Le fond de la fenêtre sera bleu */
								SDL_RenderClear(renderer);
                                SDL_SetRenderDrawColor(renderer, 44, 75, 111, 255);
								//SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
								SDL_RenderClear(renderer);
                                
                                /* Ajout du titre */
								
                                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
                                SDL_RenderCopy(renderer, texte_tex, NULL, &txtDestRect);
								
                                /* Ajout de l'image du pingouin transparent */
                                imgDestRect.x = 10;
								imgDestRect.y = 110;									
								SDL_QueryTexture(image_tex, NULL, NULL, &(imgDestRect.w), &(imgDestRect.h));
								SDL_RenderCopy(renderer, image_tex, NULL, &imgDestRect);
								
                               //test affichage image
							   /*imgDestRect.x = 100;
							   imgDestRect.y = 50;
							   afficher_image(renderer, encoche_tex, imgDestRect);*/
		
								//création des boutons du premier menu
								creer_bouton_menu_princ(w_pWindow / 2, h_pWindow / 2, bouton, renderer);

                                /* On fait le rendu ! */
							
                                SDL_RenderPresent(renderer);
								
							break;
						}
					break;
				} 
			} 
		}
	} else {
		fprintf(stderr,"Erreur de création de la fenêtre: %s\n",SDL_GetError());
	}

	//Destruction de la fenetre
	SDL_DestroyWindow(pWindow);

	TTF_CloseFont(police); /* Doit être avant TTF_Quit() */
	TTF_Quit();
    SDL_Quit();

    return 0;
}