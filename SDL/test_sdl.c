#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

int main(int argc, char** argv){
	
	int nb_ligne = 5;
	int nb_colonne = 7; 

    //Le pointeur vers la fenetre
	SDL_Window* pWindow = NULL;
	//Le pointeur vers la surface incluse dans la fenetre
    SDL_Surface *texte=NULL, *image=NULL; 
	SDL_Surface *optimizedImage=NULL;
	SDL_Renderer *renderer=NULL;
	SDL_Rect txtDestRect,imgDestRect;

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
	if(!texte){
		fprintf(stderr, "Erreur à la création du texte : %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
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

	//SDL_RWops *rwop=SDL_RWFromFile("case.png", "rb");
	SDL_Texture *image_tex; 
	// load sample.png into image
	
	image=IMG_Load("case.png");
	if(!image) {
		printf("IMG_LoadPNG_RW: %s\n", IMG_GetError());
	}
	/*if( image != NULL ){
        //Création de l'image optimisée
        optimizedImage = SDL_DisplayFormat( image );
	}*/
	
	image_tex = SDL_CreateTextureFromSurface(renderer, image);
	if(!image_tex){
		fprintf(stderr, "Erreur à la création du rendu de l'image : %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}
			
	SDL_FreeSurface(image); /* on a la texture, plus besoin de l'image */
	int i = 0;
	if( pWindow ){
		int running = 1; 
		while(running) { 
			SDL_Event e; 
			while(SDL_PollEvent(&e)) { 
				switch(e.type) { 
					case SDL_QUIT: running = 0; 
					break; 
					case SDL_WINDOWEVENT:
						switch(e.window.event){
							case SDL_WINDOWEVENT_EXPOSED:
							case SDL_WINDOWEVENT_SIZE_CHANGED:
							case SDL_WINDOWEVENT_RESIZED:
							case SDL_WINDOWEVENT_SHOWN:
								/* Le fond de la fenêtre sera blanc */
                                SDL_SetRenderDrawColor(renderer, 44, 75, 111, 255);
								SDL_RenderClear(renderer);
                                
                                /* Ajout du texte en noir */
                                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
                                SDL_RenderCopy(renderer, texte_tex, NULL, &txtDestRect);
								
                                /* Ajout de la seconde image à une certaine position */
                                imgDestRect.x = 10;
								imgDestRect.y = 110;
								SDL_QueryTexture(image_tex, NULL, NULL, &(imgDestRect.w), &(imgDestRect.h));
								//SDL_RenderCopy(renderer, image_tex, NULL, &imgDestRect);
								
                                /* Ajout de la seconde image à une autre position */
								for(int i = 0; i < nb_colonne; i++){
									imgDestRect.x += 75;
									imgDestRect.y = 110;
									for(int j = 0; j < nb_ligne; j++){
										imgDestRect.y += 75;
										SDL_RenderCopy(renderer, image_tex, NULL, &imgDestRect);
									}
								}
								
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