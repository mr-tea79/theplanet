#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>


namespace brightland {


	class Textures {
	public:
	
		//Texture used for menu dialog.
		static SDL_Texture* starsTexture;
		static SDL_Texture* texture;
		static SDL_Texture* rocks;
		static SDL_Texture* rocks2;
		static SDL_Texture* computerScene1;
		static SDL_Texture* computerScene2;
		
		static SDL_Texture* Textures::objectTexture;
		static SDL_Texture* Textures::objectTexture2;
		static SDL_Texture* Textures::objectTexture3;
		static SDL_Texture* Textures::objectTexture4;
		static SDL_Texture* Textures::objectTexture5;
		static SDL_Texture* Textures::objectTexture6;
		static SDL_Texture* Textures::objectTexture7;
		static SDL_Texture* Textures::objectTextureAirBox;
		static SDL_Texture* Textures::objectTexturePipe;
		static SDL_Texture* Textures::objectTexturePipeAction;
		static SDL_Texture* Textures::objectTextureLantern;

		static SDL_Texture* wreakageScene;
		static SDL_Texture* scene1e;
		static SDL_Texture* scene1f;
		static SDL_Texture* scene1fa;
		static SDL_Texture* scene1fb;
		static SDL_Texture* scene1d;
		static SDL_Texture* scene1d2;
		static SDL_Texture* scene3a;
		static SDL_Texture* scene3b;
		static SDL_Texture* caveScene1;

		static SDL_Texture* invTexture1;
		static SDL_Texture* invTexture2;
		static SDL_Texture* invTexture3;
		static SDL_Texture* invTexture4;
		static SDL_Texture* invTexture5;
		static SDL_Texture* invTexture6;

		static SDL_Texture* menuTexture;
		static SDL_Texture* spriteTexture;

		static SDL_Surface* spriteAction;

		static SDL_Surface* spriteDown1;
		//static SDL_Surface* spriteDownp;
		//static SDL_Surface* spriteBack1a;
		static SDL_Surface* spritePick;
		static SDL_Surface* spritePickp;

		static SDL_Surface* spriteDownTape;
		static SDL_Surface* spriteDown1a;
		static SDL_Surface* spriteDown2a;
		static SDL_Surface* spriteDown3a;

		static SDL_Surface* spriteDownp;
		static SDL_Surface* spriteDown2p;
		static SDL_Surface* spriteDown3p;

		static SDL_Surface* spriteRight1a;
		static SDL_Surface* spriteRight2a;
		static SDL_Surface* spriteRight3a;
		static SDL_Surface* spriteRight4a;

		static SDL_Surface* spriteLeft1a;
		static SDL_Surface* spriteLeft2a;
		static SDL_Surface* spriteLeft3a;
		static SDL_Surface* spriteLeft4a;

		static SDL_Surface* spriteBack1a;
		static SDL_Surface* spriteBack2a;
		static SDL_Surface* spriteBack3a;


		SDL_Surface* menuSurface;

		//Scene Surfaces.
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
		SDL_Surface* imageSurface13;
		SDL_Surface* imageSurface14;
		SDL_Surface* imageSurface15;
		
		SDL_Surface* lantern;
		SDL_Surface* pipe;
		SDL_Surface* airBox;
		SDL_Surface* boxClosed;
		SDL_Surface* boxOpened;
		SDL_Surface* boxEmpty;
		SDL_Surface* pda;
		SDL_Surface* flag;
		SDL_Surface* stars;
		SDL_Surface* tape;
		SDL_Surface* tent;
		SDL_Surface* pipeBox;
		SDL_Surface* pipeAction;

	public:
		void Scene1Textures();
		void Scene2Textures();
		void Scene3Textures();
		void MovementTextures();
		void LoadActionTextures();

	};





}