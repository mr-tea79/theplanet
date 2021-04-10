#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "MenuInteraction.h"


namespace brightland {
	
	class Scene1
	{
	private:
		const int WIDTH = 1024;
		const int HEIGHT = 768;

		const Uint8* keystate;
		int gameover = 0;

		//Used for setting text box size (Not used).
		int texW;
		int texH;
	public:
		static int SPRITE_SIZE;
		static std::string useStatement;
		static std::string openStatement;
		static std::string lookStatement;
		static std::string actionStatement;
		static std::string SceneBackground;
		static std::string objectToDestroy;
		static std::string SceneTransitionStatement;

		static int tLoader;
		static bool mouseClick;
		static int action;
		static int sceneHalt;

		int scene;
		
		//Set start position of main character.
		static int xPosition;
		static int yPosition;

		static SDL_Color fcolor;
		SDL_Rect background;
		SDL_Rect background2;
		SDL_Rect background3;
		SDL_Rect background4;
		SDL_Rect pipeAction;

		SDL_Rect inv1;
		SDL_Rect inv2;
		SDL_Rect inv3;
		SDL_Rect inv4;
		SDL_Rect inv5;
		SDL_Rect inv7;


		static SDL_Rect dTexture;
		SDL_Rect menu;
		static SDL_Rect gdSprite;
		static SDL_Rect textRect;
		SDL_Rect menuTextRect;
		SDL_Rect windowRect;
		//Player position on start.

		//Texture used for displaying text.
		static SDL_Texture* ftexture;

		SDL_Texture* dialogTexture;
		SDL_Texture* dialogmTexture;

		SDL_Surface* windowSurface;
	
		//Scene Dialog
		SDL_Surface* dialog;
		static SDL_Surface* fsurface;
		static SDL_Renderer* renderer;

		static SDL_Window* window;

		static TTF_Font* font;

		SDL_Event windowEvent;
		SDL_Event   event;

	public: 
		int scene1();
		void DoAction();

	};


}
