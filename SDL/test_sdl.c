#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

#define NB_RUBRIQUE 4

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
	SDL_Color couleurNom = {255, 255, 255};

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

void afficher_image(SDL_Renderer *renderer, SDL_Texture *image_tex, SDL_Rect imgDestRect){
	SDL_QueryTexture(image_tex, NULL, NULL, &(imgDestRect.w), &(imgDestRect.h));
	SDL_RenderCopy(renderer, image_tex, NULL, &imgDestRect);
}

void afficher_fond(SDL_Renderer *renderer, SDL_Texture *image_tex, SDL_Rect imgDestRect){
	SDL_SetRenderDrawColor(renderer,44,75,111,255);
	SDL_RenderFillRect(renderer ,&imgDestRect);
	SDL_SetRenderDrawColor(renderer,0,0,0,0);
	SDL_RenderCopy(renderer, image_tex, NULL, &imgDestRect);
}

void afficher_texte(SDL_Rect *ptxtDestRect, SDL_Renderer *renderer, SDL_Color couleurTitre, SDL_Surface *texte, int taille, char *chaine){
	SDL_Rect txtDestRect = *ptxtDestRect;
	//printf("txtDestRect.x fonction affiche texte : %d\n", txtDestRect.x);
	//printf("Adresse txtDestRect fonctiooooooooon: %d\n", &txtDestRect);
	TTF_Font *police = TTF_OpenFont("Sketch 3D.otf", taille);	

	texte = TTF_RenderUTF8_Blended(police, chaine, couleurTitre);
	SDL_Texture *texte_tex = SDL_CreateTextureFromSurface(renderer, texte);  
	SDL_QueryTexture(texte_tex, NULL, NULL, &(txtDestRect.w), &(txtDestRect.h));
	fprintf(stderr, "%s ,coord w : %d, h : %d\n", chaine, txtDestRect.w, txtDestRect.h);
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

#define ECART 150 //Ecart entre les propositions

void menuJoueurVsIA(SDL_Color couleurNom, SDL_Renderer *renderer, SDL_Rect txtDestRect, int rubrique, int w_pWindow, SDL_Rect **mat_texte){
	//Affichage des boutons 
	int i;
	SDL_Surface *texte = NULL;
	//Grosse Rubrique
	afficher_texte(&txtDestRect,renderer, couleurNom, texte, 50, NOM_BOUTON_MENU_JvsIA[rubrique]);

	if(rubrique == 0) //joueur
		rubrique = 0;
	else if(rubrique == 1) // ordi
		rubrique = 2;
	else if(rubrique == 2) //pions
		rubrique = 4;
	else //difficulté
		rubrique = 5;

	//printf("Adresse txtDestRect menu : %d\n", &txtDestRect);

	txtDestRect.x = 500;
	txtDestRect.y = 385;
						 
	//propositions
	for(i = 0; i <= NB_PROPOSITION; i++){
		//printf("coord x : %d, coord y : %d, w_pWindow : %d", txtDestRect.x, txtDestRect.y, w_pWindow);
		if(txtDestRect.y < w_pWindow + 75){
			switch(rubrique){
				case 0 : txtDestRect.y = 385;
						 if(i == 0){
							txtDestRect.x = 600;
							afficher_texte(&txtDestRect,renderer, couleurNom, texte, 30, PROPOSITION[i]);
							// txtDestRect contient la position/taille de la texture
							// il faudrait sauver le rectangle dans la matrice tab_texte[0][0]
							printf("COORD DE textDestRect : x = : %d, y = %d, w = %d, h = %d\n", txtDestRect.x, txtDestRect.y, txtDestRect.w, txtDestRect.h);
							mat_texte[rubrique][i] = txtDestRect;
	
							txtDestRect.x += (ECART+75);
							printf("proposition de param vaut 0 et i 0: %s\n", PROPOSITION[i]);
							break;
						 }
						 else if(i == 1){
							//printf("txtDestRect avant fonction affiche texte : %d\n", txtDestRect.x);
							afficher_texte(&txtDestRect,renderer, couleurNom, texte, 30, PROPOSITION[i]);
							mat_texte[rubrique][i] = txtDestRect;
							txtDestRect.x += (ECART+75);
							printf("proposition de param vaut 0 et i 1: %s\n", PROPOSITION[i]);
							break;
						 } 
						 else if(i == 2){
							afficher_texte(&txtDestRect,renderer, couleurNom, texte, 30, PROPOSITION[i-1]);
							mat_texte[rubrique][i] = txtDestRect;
							txtDestRect.x += (ECART+75);
							printf("proposition de param vaut 0 et i 2: %s\n", PROPOSITION[i-1]);
							break;
						 }
						 break;
				case 2 : txtDestRect.y = 485;
						 if(i == 0){
							txtDestRect.x = 600;
							afficher_texte(&txtDestRect,renderer, couleurNom, texte, 30, PROPOSITION[i + rubrique]);
							mat_texte[rubrique][i] = txtDestRect;
							txtDestRect.x += (ECART+100);
							printf("proposition de rubrique vaut 2 et i 0 : %s\n", PROPOSITION[i +rubrique]);
							break;
						 }
						else if(i == 1){
							afficher_texte(&txtDestRect,renderer, couleurNom, texte, 30, PROPOSITION[i+rubrique]);
							mat_texte[rubrique][i] = txtDestRect;
							txtDestRect.x += (ECART+100);
							printf("proposition de rubrique vaut 2 et i 1: %s\n", PROPOSITION[i+rubrique]);
							break;
						 } 
						 else if(i == 2){
							afficher_texte(&txtDestRect,renderer, couleurNom, texte, 30, PROPOSITION[i-1+rubrique]);
							mat_texte[rubrique][i] = txtDestRect;
							txtDestRect.x += (ECART+100);
							printf("proposition de rubrique vaut 2 et i 2: %s\n", PROPOSITION[i-1+rubrique]);	
							break;			
						 }
						 break;
				case 4 : txtDestRect.y = 585;
				fprintf(stderr, "zrgvzrz\n");
						 if(i == 0) txtDestRect.x = 600;
						 fprintf(stderr, "zrgvzrz\n");
						 if(i < 3){
							 fprintf(stderr, "zrgvzrz\n");
							afficher_texte(&txtDestRect,renderer, couleurNom, texte, 30, PROPOSITION[rubrique]);
							fprintf(stderr, "zrgvzrz\n");
							mat_texte[rubrique-1][i] = txtDestRect;
							fprintf(stderr, "zrgvzrz\n");
							txtDestRect.x += ECART;
							printf("proposition de rubrique vaut 4 : %s\n", PROPOSITION[rubrique]);
							break;
						 }
						 break;
				case 5 : txtDestRect.y = 685;
						 if(i == 0){
							txtDestRect.x = 600;
							afficher_texte(&txtDestRect,renderer, couleurNom, texte, 30, PROPOSITION[rubrique]);
							mat_texte[rubrique-2][i] = txtDestRect;
							txtDestRect.x += ECART;
							printf("proposition de rubrique vaut 5 et i 0 : %s\n", PROPOSITION[rubrique]);
						 }
						 else if(i == 1){
							afficher_texte(&txtDestRect,renderer, couleurNom, texte, 30, PROPOSITION[i + rubrique]);
							mat_texte[rubrique-2][i] = txtDestRect;
							txtDestRect.x += ECART;
							printf("proposition de rubrique vaut 5 et i 1 : %s\n", PROPOSITION[i+rubrique]);
						 } 
						 else if(i == 2){
							afficher_texte(&txtDestRect,renderer, couleurNom, texte, 30, PROPOSITION[i + rubrique]);
							mat_texte[rubrique-2][i] = txtDestRect;
							txtDestRect.x += ECART;
							printf("proposition de rubrique vaut 5 et i 2 : %s\n", PROPOSITION[i+rubrique]);
						 }
						 break;
				default : printf("Ça ne marche pas !");
			}
		}
	}
}

void joueurVsIA(SDL_Renderer *renderer, SDL_Texture *image_tex, SDL_Color couleurTitre, int w_pWindow, SDL_Rect **mat_texte){
	SDL_Rect txtDestRect, imgDestRect;
	int rubrique;
	SDL_Color couleurNom = {255, 255, 255};
	
	txtDestRect.x = 545;
	txtDestRect.y = 100;

	imgDestRect.x = 10;
	imgDestRect.y = 50;
	
	SDL_SetRenderDrawColor(renderer, 44, 75, 111, 255);
	SDL_RenderClear(renderer);

	afficher_image(renderer, image_tex, imgDestRect);
	afficher_texte(&txtDestRect,renderer, couleurTitre, NULL, 50, "PUISSANCE 4++");

	//affichage d'une partie du menu de joueur VS IA
	txtDestRect.x = 10;
	txtDestRect.y = 375;

	for(rubrique = 0; rubrique < 4; rubrique++){
		
		menuJoueurVsIA(couleurNom, renderer, txtDestRect, rubrique, w_pWindow, mat_texte);
		
		txtDestRect.y += 100;
	}
}

#define coordYbtnJoueurMini 390
#define coordYbtnJoueurMaxi 420
#define TAILLE_COORD_BOUTON 6
static int coord_bouton_joueur[TAILLE_COORD_BOUTON] = {610, 710, 825, 960, 1050, 1190};

int boutonJoueurValide(int x, int y){
	int i, compt = 1;
	for(i = 0; i < TAILLE_COORD_BOUTON; i++){
		if(x > coord_bouton_joueur[i] && x < coord_bouton_joueur[i+1] && y > coordYbtnJoueurMini && y < coordYbtnJoueurMaxi){
			return compt;
		}
		i+=1;
		compt++;
	}
	return 0;
}

#define coordYbtnOrdiMini 485
#define coordYbtnOrdiMaxi 520
static int coord_bouton_ordi[TAILLE_COORD_BOUTON] = {600, 780, 845, 1050, 1100, 1300};

int boutonOrdiValide(int x, int y){
	int i, compt = 1;
	for(i = 0; i < TAILLE_COORD_BOUTON; i++){
		if(x > coord_bouton_ordi[i] && x < coord_bouton_ordi[i+1] && y > coordYbtnOrdiMini && y < coordYbtnOrdiMaxi){
			return compt;
		}
		i+=1;
		compt++;
	}
	return 0;
}

#define coordYbtnPionsMini 585
#define coordYbtnPionsMaxi 625
static int coord_bouton_pion[TAILLE_COORD_BOUTON] = {600, 690, 750, 840, 900, 990};

int boutonPionsValide(int x, int y){
	int i, compt = 1;
	for(i = 0; i < TAILLE_COORD_BOUTON; i++){
		if(x > coord_bouton_pion[i] && x < coord_bouton_pion[i+1] && y > coordYbtnPionsMini && y < coordYbtnPionsMaxi){
			return compt;
		}
		i+=1;
		compt++;
	}
	return 0;
}

#define coordYbtnDifficulteMini 685
#define coordYbtnDifficulteMaxi 725
static int coord_bouton_difficulte[TAILLE_COORD_BOUTON] = {600, 700, 750, 860, 900, 1030};

int boutonDifficulteValide(int x, int y){
	int i, compt = 1;
	for(i = 0; i < TAILLE_COORD_BOUTON; i++){
		if(x > coord_bouton_difficulte[i] && x < coord_bouton_difficulte[i+1] && y > coordYbtnDifficulteMini && y < coordYbtnDifficulteMaxi){
			return compt;
		}
		i+=1;
		compt++;
	}
	return 0;
}

int coord_boutons_width[TAILLE_COORD_BOUTON * 4] = {100, 140, 140, 180, 200, 200, 190, 190, 190, 100, 110, 130};

void boutonProposition(int x, int y, SDL_Renderer *renderer, SDL_Texture *encoche_tex, SDL_Texture *fond_tex, SDL_Rect **tab_texte){

	SDL_Rect tab_encoche[NB_RUBRIQUE];
	int etat_joueur = 0, etat_ordi = 0, etat_pions = 0, etat_difficulte = 0, temp, temp2 = 1;
	int i, j = 1;
	int bouton_joueur = boutonJoueurValide(x,y) ;
	int bouton_ordi = boutonOrdiValide(x,y);
	int bouton_pion = boutonPionsValide(x, y);
	int bouton_difficulte = boutonDifficulteValide(x,y);
	
	//Remplissage du tableau encoche
	tab_encoche[0].x = coord_bouton_joueur[temp2];
	tab_encoche[0].y = coordYbtnJoueurMini ;
	for(i = 0; i<NB_RUBRIQUE; i++){
		tab_encoche[i].w = 30;
		tab_encoche[i].h = 35;
	}
	
	//Affichage du fond de l'endroit où sera l'encoche
	for(i = 0; i < NB_RUBRIQUE; i++){
		for(j = 0; j < NB_PROPOSITION; j++){
			printf("x : %d, y : %d, w : %d, h : %d\n", tab_texte[i][j].x, tab_texte[i][j].y, tab_texte[i][j].w, tab_texte[i][j].h);
			SDL_Rect tr = tab_texte[i][j];
			SDL_Rect rect = {tr.x+tr.w+20, tr.y, 35, 30};
			afficher_fond(renderer, fond_tex, rect);
		}
	}

	j = 0;
	for(i = 0; i < NB_RUBRIQUE; i++){
		SDL_Rect tr = tab_texte[i][j];
		SDL_Rect rect = {tr.x+tr.w+1, tr.y, 35, 30};
		afficher_image(renderer, encoche_tex, rect);
	}
	



	while(etat_joueur != 1 && etat_pions != 1 && etat_ordi != 1 && etat_difficulte != 1){
		if(bouton_joueur){
			printf("Bouton joueur : %d\n", bouton_joueur);
			switch(bouton_joueur){
				case 1 : temp = 1;
						break;
				case 2 : temp = 3;
						break;
				case 3 : temp = 5;
						break;
				default : printf("Erreur");
			}
			tab_encoche[0].x = coord_bouton_joueur[temp];
			tab_encoche[0].y = coordYbtnJoueurMini ;
			printf("Coordonnées encoche x : %d, y : %d\n", tab_encoche[0].x, tab_encoche[0].y);
			afficher_image(renderer, encoche_tex, tab_encoche[0]);
			printf("test après affichage\n");
			etat_joueur = 1;
		}

		//Partie sur les ordis
		tab_encoche[1].x = coord_bouton_ordi[temp2];
		tab_encoche[1].y = coordYbtnOrdiMini;
		temp2 = 1;
		j = 1;

		if(bouton_ordi){
			printf("Bouton ordi : %d\n", bouton_ordi);
			switch(bouton_ordi){
				case 1 : temp = 1;
						break;
				case 2 : temp = 3;
						break;
				case 3 : temp = 5;
						break;
				default : printf("Erreur");
			}
			tab_encoche[1].x = coord_bouton_ordi[temp];
			tab_encoche[1].y = coordYbtnOrdiMini ;
			printf("Coordonnées encoche x : %d, y : %d\n", tab_encoche[1].x, tab_encoche[1].y);
			afficher_image(renderer, encoche_tex, tab_encoche[1]);
			printf("test après affichage\n");
			etat_ordi = 1;
		}

		//Partie sur les pions
		tab_encoche[2].x = coord_bouton_pion[temp2];
		tab_encoche[2].y = coordYbtnPionsMini;
		temp2 = 1;
		j = 1;

		if(bouton_pion){
			printf("Bouton pion : %d\n", bouton_pion);
			switch(bouton_pion){
				case 1 : temp = 1;
						break;
				case 2 : temp = 3;
						break;
				case 3 : temp = 5;
						break;
				default : printf("Erreur");
			}
			tab_encoche[2].x = coord_bouton_pion[temp];
			tab_encoche[2].y = coordYbtnPionsMini ;
			printf("Coordonnées encoche x : %d, y : %d\n", tab_encoche[2].x, tab_encoche[2].y);
			afficher_image(renderer, encoche_tex, tab_encoche[2]);
			printf("test après affichage\n");
			etat_ordi = 1;
		}

		//Partie sur la difficulté
		tab_encoche[3].x = coord_bouton_difficulte[temp2];
		tab_encoche[3].y = coordYbtnDifficulteMini;
		temp2 = 1;
		j = 1;

		if(bouton_difficulte){
			printf("Bouton difficulte : %d\n", bouton_difficulte);
			switch(bouton_difficulte){
				case 1 : temp = 1;
						break;
				case 2 : temp = 3;
						break;
				case 3 : temp = 5;
						break;
				default : printf("Erreur");
			}
			tab_encoche[3].x = coord_bouton_difficulte[temp];
			tab_encoche[3].y = coordYbtnDifficulteMini ;
			printf("Coordonnées encoche x : %d, y : %d\n", tab_encoche[3].x, tab_encoche[3].y);
			afficher_image(renderer, encoche_tex, tab_encoche[3]);
			printf("test après affichage\n");
			etat_difficulte = 1;
		}
	}
}





int main(int argc, char** argv){
	int nb_ligne = 5;
	int nb_colonne = 7; 

    //Le pointeur vers la fenetre
	SDL_Window* pWindow = NULL;
	int w_pWindow, h_pWindow;
	//Le pointeur vers la surface incluse dans la fenetre
    SDL_Surface *texte=NULL, *image=NULL, *image2 = NULL, *encoche = NULL, *fond = NULL;
	SDL_Surface *bouton = NULL;
	SDL_Renderer *renderer=NULL;
	SDL_Rect txtDestRect,imgDestRect, coordsouris;

	SDL_Rect **tab_texte = malloc(sizeof(SDL_Rect*) * NB_RUBRIQUE);
		for(int l = 0; l < NB_RUBRIQUE; l++)
			tab_texte[l] = malloc(sizeof(SDL_Rect) * NB_PROPOSITION);

	fprintf(stderr, "eafaefaefe");
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
	SDL_Texture *encoche_tex;
	SDL_Texture *fond_tex;
	// load sample.png into image
	image2 = IMG_Load("case.png");
	image=IMG_Load("transparent.gif");
	encoche = IMG_Load("encoche.png");
	fond = IMG_Load("fond.png");

	/*Test si l'image a bien été get*/
	if(!image) {
		printf("IMG_LoadPNG_RW: %s\n", IMG_GetError());
	}

	image_tex = SDL_CreateTextureFromSurface(renderer, image);
	image2_tex = SDL_CreateTextureFromSurface(renderer, image2);//pingouin transparent siur les bords
	encoche_tex = SDL_CreateTextureFromSurface(renderer, encoche);//encoche de validation des proposistions
	fond_tex = SDL_CreateTextureFromSurface(renderer, fond);//fonc pour enlever une encoche
	
	if(!image_tex){
		fprintf(stderr, "Erreur à la création du rendu de l'image : %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}
			
	SDL_FreeSurface(image); /* on a la texture, plus besoin de l'image */
	SDL_FreeSurface(image2);
	SDL_FreeSurface(encoche);
	SDL_FreeSurface(fond);

	int etat = 1;
	int compt = 0;
	if( pWindow ){
		int running = 1; 
		while(running) { 
			SDL_Event e; 
			while(SDL_PollEvent(&e)) { 
				switch(e.type) { 
					case SDL_QUIT: running = 0; 
					break; 
					case SDL_MOUSEBUTTONUP:

        				if (e.button.button == SDL_BUTTON_LEFT){ /*Si clic gauche alors*/
							coordsouris.x = e.button.x;
							coordsouris.y = e.button.y;
						}

						switch(etat) {
							case 1 : if(coordsouris.x > 520 && coordsouris.x < 910 && coordsouris.y > 300 && coordsouris.y < 340){//coord des boutons en plein écran
										printf("Menu joueur contre ia\n");
										SDL_RenderClear(renderer);
										joueurVsIA(renderer, image_tex, couleurTitre, w_pWindow, tab_texte);//fonction d'appel des graphismes de ce menu
									 	
									 	SDL_RenderPresent(renderer);
										etat = 2;
									 }
									 else if(coordsouris.x > 520 && coordsouris.x < 980 && coordsouris.y > 430 && coordsouris.y < 480){//coord des boutons en plein écran
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

							case 2 : //printf("coord bouton dans l'ordre x : %d, y : %d\n", coordsouris.x, coordsouris.y);//Dans le menu joueur VS IA
									 
									 if(compt == 0){
										SDL_RenderClear(renderer);
									 	joueurVsIA(renderer, image_tex, couleurTitre, w_pWindow, tab_texte);//fonction d'appel des graphismes de ce menu
										 compt = 1;
									 }
									 boutonProposition(coordsouris.x, coordsouris.y, renderer, encoche_tex, fond_tex, tab_texte);
									 SDL_RenderPresent(renderer);

							case 3 : printf("\n");//Dans le menu joueur VS joueur
						}
					break;

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