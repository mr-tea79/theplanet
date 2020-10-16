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
		//const int SPRITE_SIZE = 120;

		const Uint8* keystate;
		int gameover = 0;

		//Used for setting text box size (Not used).
		int texW;
		int texH;
	public:
		static int SPRITE_SIZE;
		static std::string useStatement;
		static std::string SceneBackground;
		static int playerMessage;

		
		//Inventory used variables. To check if the item has been used and shouldn't remain in the inventory.
		static int inv3Used;
		static int inv4Used;
		static int inv5Used;

		int colorkey;
		int count;
		int scene;
		//Set start position of main character.
		static int xPosition;
		static int yPosition;

		SDL_Color fcolor;
		SDL_Rect background;
		SDL_Rect background2;
		SDL_Rect background3;
		SDL_Rect background4;

		SDL_Rect inv1;
		SDL_Rect inv2;
		SDL_Rect inv3;
		SDL_Rect inv4;
		SDL_Rect inv5;
		

	
		SDL_Rect dTexture;
		SDL_Rect menu;
		static SDL_Rect gdSprite;
		SDL_Rect textRect;
		SDL_Rect menuTextRect;
		SDL_Rect windowRect;
		//Player position on start.
		static SDL_Texture* objectTexture;
		static SDL_Texture* objectTexture2;	
		static SDL_Texture* objectTexture3;
		static SDL_Texture* objectTexture4;
		static SDL_Texture* objectTexture5;
		static SDL_Texture* objectTexture6;
		static SDL_Texture* objectTexture7;
		static SDL_Texture* objectTextureAirBox;
		static SDL_Texture* objectTexturePipe;

		SDL_Texture* invTexture1;
		SDL_Texture* invTexture2;
		SDL_Texture* invTexture3;
		SDL_Texture* invTexture4;
		SDL_Texture* invTexture5;


		//Texture used for displaying text.
		SDL_Texture* ftexture = NULL;

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

		SDL_Texture* menuTexture;

		//Player movement animations
		SDL_Surface* spriteFlat;
		SDL_Surface* spriteDown1;
		SDL_Surface* spriteDownp;
	

		//Use action Surfaces
		SDL_Surface* spriteMask;

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
		SDL_Surface* menuSurface;
		SDL_Surface* purpleSurface;

		//Scene Objects
		SDL_Surface* pda;
		SDL_Surface* flag;
		SDL_Surface* stars;
		SDL_Surface* tape;
		SDL_Surface* tent;



		//Scene Dialog
		SDL_Surface* dialog;
		SDL_Surface* dialogm;
		SDL_Surface* fsurface;

		static SDL_Renderer* renderer;

		SDL_Window* window;

		TTF_Font* font;

		SDL_Event windowEvent;
		SDL_Event   event;

	public: 
		int scene1();
	//	void Scene1Textures();
		//void Scene2Textures();

		private:
			


	};


}

