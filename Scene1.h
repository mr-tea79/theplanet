<<<<<<< HEAD
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
		static std::string SceneBackground;
		static int mouseHold;
		static int tLoader;
		static int messageHolder;
		
		//Inventory used variables. To check if the item has been used and shouldn't remain in the inventory.
		static int inv3Used;
		static int inv4Used;
		static int inv5Used;
		static int inv6Used;
		static int inv7Used;
		static int action;

		int colorkey;
		int count;
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

		//Texture used for menu dialog.
		SDL_Texture* sceneTexture;
		SDL_Texture* texture;
		SDL_Texture* rocks;
		SDL_Texture* rocks2;
		SDL_Texture* airBoxT;
		SDL_Texture* computerScene1;
		SDL_Texture* computerScene2;
		SDL_Texture* wreakageScene;
		SDL_Texture* scene1e;
		SDL_Texture* scene1f;
		SDL_Texture* scene1fa;
		SDL_Texture* scene1fb;
		SDL_Texture* scene1d;
		SDL_Texture* scene1d2;

		SDL_Texture* spriteTexture;
		SDL_Texture* dialogTexture;
		SDL_Texture* dialogmTexture;


		//Scene Background Surfaces
		SDL_Surface* imageSurface2;
		SDL_Surface* imageSurface;
		SDL_Surface* imageSurface3;
		SDL_Surface* imageSurface4;
		SDL_Surface* imageSurface5;
		SDL_Surface* imageSurface6;
		SDL_Surface* imageSurface7;
		SDL_Surface* imageSurface8;
		SDL_Surface* imageSurface9;
		SDL_Surface* imageSurface10;
		SDL_Surface* imageSurface11;
		SDL_Surface* imageSurface12;

		SDL_Surface* windowSurface;
		//SDL_Surface* menuSurface;
		SDL_Surface* purpleSurface;

		//Scene Dialog
		SDL_Surface* dialog;
		SDL_Surface* dialogm;
		static SDL_Surface* fsurface;
		static SDL_Renderer* renderer;

		static SDL_Window* window;

		static TTF_Font* font;

		SDL_Event windowEvent;
		SDL_Event   event;

	public: 
		int scene1();
		static void renderSprite();
		void DoAction();

		private:
			


	};


}

=======
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
		static std::string SceneBackground;
		static int mouseHold;
		static int tLoader;
		static int messageHolder;
		
		//Inventory used variables. To check if the item has been used and shouldn't remain in the inventory.
		static int inv3Used;
		static int inv4Used;
		static int inv5Used;
		static int inv6Used;
		static int inv7Used;
		static int action;

		int colorkey;
		int count;
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

		//Texture used for menu dialog.
		SDL_Texture* sceneTexture;
		SDL_Texture* texture;
		SDL_Texture* rocks;
		SDL_Texture* rocks2;
		SDL_Texture* airBoxT;
		SDL_Texture* computerScene1;
		SDL_Texture* computerScene2;
		SDL_Texture* wreakageScene;
		SDL_Texture* scene1e;
		SDL_Texture* scene1f;
		SDL_Texture* scene1fa;
		SDL_Texture* scene1fb;
		SDL_Texture* scene1d;
		SDL_Texture* scene1d2;

		SDL_Texture* spriteTexture;
		SDL_Texture* dialogTexture;
		SDL_Texture* dialogmTexture;


		//Scene Background Surfaces
		SDL_Surface* imageSurface2;
		SDL_Surface* imageSurface;
		SDL_Surface* imageSurface3;
		SDL_Surface* imageSurface4;
		SDL_Surface* imageSurface5;
		SDL_Surface* imageSurface6;
		SDL_Surface* imageSurface7;
		SDL_Surface* imageSurface8;
		SDL_Surface* imageSurface9;
		SDL_Surface* imageSurface10;
		SDL_Surface* imageSurface11;
		SDL_Surface* imageSurface12;

		SDL_Surface* windowSurface;
		//SDL_Surface* menuSurface;
		SDL_Surface* purpleSurface;

		//Scene Dialog
		SDL_Surface* dialog;
		SDL_Surface* dialogm;
		static SDL_Surface* fsurface;
		static SDL_Renderer* renderer;

		static SDL_Window* window;

		static TTF_Font* font;

		SDL_Event windowEvent;
		SDL_Event   event;

	public: 
		int scene1();
		static void renderSprite();
		void DoAction();

		private:
			


	};


}

>>>>>>> 01962e3eb7b8f6018a747a0bbe910f189b40286d
