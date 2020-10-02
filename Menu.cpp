#include "Menu.h"

using namespace brightland;

int Menu::menu() {


	//Allow usage of .png images.
	int imgFlags = IMG_INIT_PNG;

	//Initialize SDL components.
	imageSurface = NULL;
	imageSurface2 = NULL;
	windowSurface = NULL;
	//Text Dialog.
	fsurface = NULL;
	renderer = NULL;

	background = { 0, 0, 1024, 768 };
	windowRect = { 0 ,0,1024,768 };

	SDL_Surface* SDL_DisplayFormat(SDL_Surface * surface);

	SDL_Init(SDL_INIT_EVERYTHING);
	TTF_Init();

	window = SDL_CreateWindow("Brightland Adventure Game Studio", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI);
	windowSurface = SDL_GetWindowSurface(window);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	font = TTF_OpenFont("arial.ttf", 25);
	fcolor = { 255, 255, 255 };

	//Load in all Scene textures here. Only do this once as it uses RAM to do this.
	imageSurface = IMG_Load("mainmenu.png");

	//Assign the images to the textures.
	ftexture = SDL_CreateTextureFromSurface(renderer, fsurface);
	texture = SDL_CreateTextureFromSurface(renderer, imageSurface);

	SDL_QueryTexture(ftexture, NULL, NULL, &texW, &texH);
	SDL_FreeSurface(imageSurface);
	
	//Game loop.
	while (!gameover)
	{
		SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
		SDL_RenderClear(renderer);

		if (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_QUIT:
				gameover = 1;
				break;

			case SDL_KEYDOWN:
				switch (event.key.keysym.sym)
				{
				case SDLK_ESCAPE:
				case SDLK_q:
					gameover = 1;
					break;
				}
				break;
			}
		}

		if (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_LEFT)) {


		}

		//Render the window
		SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer, texture, NULL, &background);
	//	SDL_RenderCopy(renderer, menuTexture, NULL, &menu);
		//SDL_RenderCopy(renderer, ftexture, NULL, &textRect);
	//	SDL_RenderCopy(renderer, dialogmTexture, NULL, &menuTextRect);
	//	SDL_RenderCopy(renderer, sceneTexture, &srcrect3, &dstrect3);



		SDL_RenderPresent(renderer);
	}



	//Clean up after yourself!
	SDL_DestroyRenderer(renderer);
	SDL_DestroyTexture(ftexture);
	SDL_DestroyTexture(texture);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	TTF_CloseFont(font);

	return 0;

	TTF_Quit();
	SDL_Quit();
}

