#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "MenuInteraction.h"
#include "Thread"


namespace brightland {

	class Scene1
	{
	private:
		

		const Uint8* keystate;
		int gameover = 0;

		//Used for setting text box size (Not used).
		int texW;
		int texH;
	public:
		static int mouseMoveXPercent;
		static int mouseMoveYPercent;
		static int WIDTH;
		static int HEIGHT;
		static int secretTrigger;
		static int SPRITE_SIZE;
		static int SPRITE_MIN_SIZE;
		static int SPRITE_MAX_SIZE;
		
		static int xp; // x position in percentage %
		static int yp; // y position in percentage %
		static int yMousePositionPercent; // Mouse y position in percentage %
		static int xMousePositionPercent; // Mouse x position in percentage %

		static std::string useStatement;
		static std::string openStatement;
		static std::string lookStatement;
		static std::string pickUpStatement;
		static std::string actionStatement;
		static std::string SceneBackground;
		static std::string objectToDestroy;
		static std::string SceneTransitionStatement;

		static int tLoader;
		static bool mouseClick;
		static int action;
		static int sceneHalt;
		static int inGame;
		static int soundCount;
		static int menuSound; //For menu clicking noises.
		static int hoverSound; //For hover menu noises.
		static int hoverHold;
		static int playerIsMoving;
		static int threadRipper;
		static bool fullScreenTrigger;
		static bool doPerfCheck;
		static bool quitGame;


		int scene;

		static bool continueGame;
		static bool newGame;

		//Set start position of main character.
		//static int xPosition;
		//static int yPosition;

		static SDL_Color fcolor;
		static SDL_Color bcolor;
		SDL_Rect pipeAction;


		//static SDL_Rect dTexture;
		SDL_Rect menu;
		static SDL_Rect gdSprite;
		static SDL_Rect textRect;
		//SDL_Rect menuTextRect;
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
		bool checkFScreenStatus(bool status);
		void setSceneSpriteSize(int size);
		void DoAction();

	};
};



