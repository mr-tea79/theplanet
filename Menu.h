#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "MenuInteraction.h"

namespace brightland {

	class Menu
	{
	private:
		const int WIDTH = 1024;
		const int HEIGHT = 768;
		int gameover = 0;

		//Used for setting text box size (Not used).
		int texW;
		int texH;

	public:

		
		
		SDL_Color fcolor;
		SDL_Rect background;
		SDL_Rect windowRect;
		SDL_Window* window;
		TTF_Font* font;
		SDL_Event   event;
		SDL_Surface* fsurface;

		SDL_Renderer* renderer;


		SDL_Event windowEvent;
		

		SDL_Surface* imageSurface2;
		SDL_Surface* imageSurface;
		SDL_Surface* windowSurface;


		//Texture used for displaying text.
		SDL_Texture* ftexture = NULL;

		//Texture used for menu dialog.
		SDL_Texture* texture;
	



	public:
		int menu();

	};


}