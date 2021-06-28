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
		static int secretTrigger; 
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
		static SDL_Color bcolor;
		SDL_Rect pipeAction;


		//static SDL_Rect dTexture;
		SDL_Rect menu;
		static SDL_Rect gdSprite;
		static SDL_Rect textRect;
		SDL_Rect menuTextRect;
		SDL_Rect windowRect;
	
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
