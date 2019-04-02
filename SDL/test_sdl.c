#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

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

/*Créer une structure pour le bouton avec ses tailles et une autre pour le menu où on utilise un tableau de bouton*/
#define NB_BOUTON 3
static char* NOM_BOUTON_MENU_PRINC[NB_BOUTON] = {"JoueurVsOrdi", "JoueurVsJoueur", "Quitter"};

void creer_bouton_menu_princ(int x, int y, SDL_Surface *bouton, SDL_Renderer *renderer){
	int i;
	TTF_Font *police = TTF_OpenFont("Sketch 3D.otf", 50);
	SDL_Surface *texte;
	SDL_Rect txtDestRect /*,button*/;
	SDL_Color couleurNom = {0, 0, 0};

	txtDestRect.x = x - 200;
	txtDestRect.y = y - 100;
	bouton = SDL_CreateRGBSurface(0, txtDestRect.y, txtDestRect.x, 32, 0, 0, 0, 255);
	for(i = 0; i < NB_BOUTON; i++){
		texte = TTF_RenderUTF8_Blended(police, NOM_BOUTON_MENU_PRINC[i], couleurNom);
		SDL_Texture *texte_tex = SDL_CreateTextureFromSurface(renderer, texte); 
		SDL_QueryTexture(texte_tex, NULL, NULL, &(txtDestRect.w), &(txtDestRect.h));
		SDL_RenderCopy(renderer, texte_tex, NULL, &txtDestRect);
		txtDestRect.y += 100;
	}
	TTF_CloseFont(police);
}

void afficher_image(SDL_Renderer *renderer, SDL_Texture *image_tex){
	SDL_Rect imgDestRect;
	imgDestRect.x = 10;
	imgDestRect.y = 50;
	SDL_QueryTexture(image_tex, NULL, NULL, &(imgDestRect.w), &(imgDestRect.h));
	SDL_RenderCopy(renderer, image_tex, NULL, &imgDestRect);
}

void afficher_texte(SDL_Rect txtDestRect, SDL_Renderer *renderer, SDL_Color couleurTitre, SDL_Surface *texte, int taille, char *chaine){
	
	TTF_Font *police = TTF_OpenFont("Sketch 3D.otf", taille);	

	texte = TTF_RenderUTF8_Blended(police, chaine, couleurTitre);
	SDL_Texture *texte_tex = SDL_CreateTextureFromSurface(renderer, texte);  
	SDL_QueryTexture(texte_tex, NULL, NULL, &(txtDestRect.w), &(txtDestRect.h));
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderCopy(renderer, texte_tex, NULL, &txtDestRect);

	TTF_CloseFont(police);
}

/*Créer une structure pour le bouton avec ses tailles et une autre pour le menu où on utilise un tableau de bouton*/
#define NB_BOUTON_MENU_JvsIA 5
static char* NOM_BOUTON_MENU_JvsIA[NB_BOUTON_MENU_JvsIA] = {"Nombre de joueur", "Nombre d'ordinateur", "Pions à aligner", "Difficulté"};

/*Créer une structure pour le bouton avec ses tailles et une autre pour le menu où on utilise un tableau de bouton*/
#define NB_PROPOSITION 3
#define TAILLE_PROPOSITION 8
static char* PROPOSITION[TAILLE_PROPOSITION] = {"joueur", "joueurs", "ordinateur", "ordinateurs", "pions", "facile", "moyen", "difficile"};

void menuJoueurVsIA(SDL_Color couleurNom, SDL_Renderer *renderer, SDL_Rect txtDestRect, int choix, int w_pWindow){
	//Affichage des boutons 
	int i, param = 0;
	SDL_Surface *texte = NULL;
	//Grosse Rubrique
	afficher_texte(txtDestRect,renderer, couleurNom, texte, 50, NOM_BOUTON_MENU_JvsIA[choix]);

	if(choix == 0)
		param = 0;
	else if(choix == 1)
		param = 2;
	else if(choix == 2)
		param = 4;
	else
		param = 5;

	txtDestRect.x = 500;
	txtDestRect.y = 385;
						 
	//propositions
	for(i = 0; i <= NB_PROPOSITION; i++){
		//printf("coord x : %d, coord y : %d, w_pWindow : %d", txtDestRect.x, txtDestRect.y, w_pWindow);
		if(txtDestRect.y < w_pWindow + 75){
			switch(param){
				case 0 : if(i == 0){
							txtDestRect.x += 100;
							afficher_texte(txtDestRect,renderer, couleurNom, texte, 30, PROPOSITION[i]);
						 }
						 else if(i == 1){
							txtDestRect.x += 100;
							afficher_texte(txtDestRect,renderer, couleurNom, texte, 30, PROPOSITION[i]);
							
						 } 
						 else if(i == 2){
							txtDestRect.x += 100;
							afficher_texte(txtDestRect,renderer, couleurNom, texte, 30, PROPOSITION[i-1]);
											
						 }
						 break;
				case 2 : if(i == 0){
							txtDestRect.x += 100;
							afficher_texte(txtDestRect,renderer, couleurNom, texte, 30, PROPOSITION[i + param]);
							
						 }
						else if(i == 1){
							txtDestRect.x += 100;
							afficher_texte(txtDestRect,renderer, couleurNom, texte, 30, PROPOSITION[i+param]);
							
						 } 
						 else if(i == 2){
							txtDestRect.x += 100;
							afficher_texte(txtDestRect,renderer, couleurNom, texte, 30, PROPOSITION[i]);
											
						 }
						 break;
				case 4 : txtDestRect.x += 100;
						 afficher_texte(txtDestRect,renderer, couleurNom, texte, 30, PROPOSITION[param]);
						 
						 break;
				case 5 : if(i == 0){
							txtDestRect.x += 100;
							afficher_texte(txtDestRect,renderer, couleurNom, texte, 30, PROPOSITION[param]);
							
						 }
						 else if(i == 1){
							txtDestRect.x += 100;
							afficher_texte(txtDestRect,renderer, couleurNom, texte, 30, PROPOSITION[i+1 + param]);
							
						 } 
						 else if(i == 2){
							txtDestRect.x += 100;
							afficher_texte(txtDestRect,renderer, couleurNom, texte, 30, PROPOSITION[i + param]);
							
						 }
						 break;
				default : printf("Ça ne marche pas !");
			}
		}
		txtDestRect.y += 100;
	}
}

void joueurVsIA(SDL_Renderer *renderer, SDL_Texture *image_tex, SDL_Color couleurTitre, int w_pWindow){
	SDL_Rect txtDestRect;
	int i;
	SDL_Color couleurNom = {0, 0, 0};
	
	txtDestRect.x = 545;
	txtDestRect.y = 100;

	SDL_SetRenderDrawColor(renderer, 44, 75, 111, 255);
	SDL_RenderClear(renderer);

	afficher_image(renderer, image_tex);
	afficher_texte(txtDestRect,renderer, couleurTitre, NULL, 50, "PUISSANCE 4++");

	//affichage d'une partie du menu de joueur VS IA
	txtDestRect.x = 10;
	txtDestRect.y = 375;
	for(i = 0; i < 4; i++){
		menuJoueurVsIA(couleurNom, renderer, txtDestRect, i, w_pWindow);
		txtDestRect.y += 100;
	}
}

int main(int argc, char** argv){
	int nb_ligne = 5;
	int nb_colonne = 7; 

    //Le pointeur vers la fenetre
	SDL_Window* pWindow = NULL;
	int w_pWindow, h_pWindow;
	//Le pointeur vers la surface incluse dans la fenetre
    SDL_Surface *texte=NULL, *image=NULL, *image2 = NULL;
	SDL_Surface *bouton = NULL;
	SDL_Renderer *renderer=NULL;
	SDL_Rect txtDestRect,imgDestRect, coordsouris;

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

	
	SDL_Texture *image_tex; 
	SDL_Texture *image2_tex;
	// load sample.png into image
	image2 = IMG_Load("case.png");
	image=IMG_Load("transparent.gif");

	/*Test si l'image a bien été get*/
	if(!image) {
		printf("IMG_LoadPNG_RW: %s\n", IMG_GetError());
	}

	image_tex = SDL_CreateTextureFromSurface(renderer, image);
	image2_tex = SDL_CreateTextureFromSurface(renderer, image2);//pingouin transparent siur les bords
	
	if(!image_tex){
		fprintf(stderr, "Erreur à la création du rendu de l'image : %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}
			
	SDL_FreeSurface(image); /* on a la texture, plus besoin de l'image */
	int etat = 1;
	if( pWindow ){
		int running = 1; 
		while(running) { 
			SDL_Event e; 
			while(SDL_PollEvent(&e)) { 
				switch(e.type) { 
					case SDL_QUIT: running = 0; 
					break; 
					case SDL_MOUSEBUTTONUP:

        				if (e.button.button == SDL_BUTTON_LEFT){ /* On arrête le programme si on a fait un clic gauche */
							coordsouris.x = e.button.x;
							coordsouris.y = e.button.y;
						}

						switch(etat) {
							case 1 : if(coordsouris.x > 520 && coordsouris.x < 910 && coordsouris.y > 300 && coordsouris.y < 340){//coord des boutons en plein écran
										printf("Menu joueur contre ia\n");
										SDL_RenderClear(renderer);
										
										joueurVsIA(renderer, image_tex, couleurTitre, w_pWindow);//fonction d'appel des graphismes de ce menu
										etat = 2;
										SDL_RenderPresent(renderer);
									 }
									 else if(coordsouris.x > 520 && coordsouris.x < 980 && coordsouris.y > 300 && coordsouris.y < 340){//coord des boutons en plein écran
										printf("Menu joueur contre joueur\n");
										SDL_RenderClear(renderer);
										//joueurvsJoueur();//fonction d'appel des graphismes de ce menu
										SDL_RenderPresent(renderer);
										etat = 3;
									 }
									 else if(coordsouris.x > 520 && coordsouris.x < 730 && coordsouris.y > 500 && coordsouris.y < 540)//coord des boutons en plein écran
										running = 0;
									 printf("x : %i, y : %i \n", coordsouris.x, coordsouris.y);
									 break;

							case 2 : printf("qqchose");//Menu joueur VS IA

							case 3 : printf("qqchose");//Menu joueur VS joueur
						}
					break;

					case SDL_WINDOWEVENT:
						switch(e.window.event){
							case SDL_WINDOWEVENT_EXPOSED:
							case SDL_WINDOWEVENT_SIZE_CHANGED:
							case SDL_WINDOWEVENT_RESIZED:
							case SDL_WINDOWEVENT_SHOWN:
								/* Le fond de la fenêtre sera blanc */
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
								
                                //Création de la grille

								//creer_grille(nb_ligne, nb_colonne, renderer, image_tex);
		
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