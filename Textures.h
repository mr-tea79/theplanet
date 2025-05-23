#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>


namespace brightland {


	class Textures {
	public:
	
		static SDL_Texture* ftexture;

		static SDL_Texture* Textures::cursor;

		//Hover Buttons
		static SDL_Texture* hoverNewGame;
		static SDL_Texture* hoverContinueGame;
		static SDL_Texture* hoverOptions;
		static SDL_Texture* hoverMinus;
		static SDL_Texture* hoverPlus;
		static SDL_Texture* hoverPickup;
		static SDL_Texture* hoverPull;
		static SDL_Texture* hoverLook;
		static SDL_Texture* hoverOpen;
		static SDL_Texture* hoverUse;
		static SDL_Texture* hoverLog;
		static SDL_Texture* hoverExit;
		static SDL_Texture* hoverNoSound;
		static SDL_Texture* HoverContinue1;
		static SDL_Texture* hoverFScreen;
		static SDL_Texture* hoverExitGame;

		//Texture used for menu dialog.
		static SDL_Texture* starsTexture;
		static SDL_Texture* texture;
		static SDL_Texture* rocks;
		static SDL_Texture* rocks2;
		static SDL_Texture* rocks3;
		static SDL_Texture* rocks4;
		static SDL_Texture* computerScene1;
		static SDL_Texture* computerScene2;
		static SDL_Texture* blink;
		static SDL_Texture* secretDrawing;
		
		static SDL_Texture* PDATexture;
		static SDL_Texture* FlagTexture;
		static SDL_Texture* objectTexture3;
		static SDL_Texture* objectTexture4;
		static SDL_Texture* objectTexture5;
		static SDL_Texture* objectTexture6;
		static SDL_Texture* objectTexture7;
		static SDL_Texture* objectTextureAirBox;
		static SDL_Texture* objectTexturePipe;
		static SDL_Texture* objectTexturePipeAction;
		static SDL_Texture* objectTextureLantern;
		static SDL_Texture* objectTextureSparkle;

		static SDL_Texture* wreakageScene;
		static SDL_Texture* scene1e;
		static SDL_Texture* scene1f;
		static SDL_Texture* scene1fa;
		static SDL_Texture* scene1fb;
		static SDL_Texture* scene1d;
		static SDL_Texture* scene1d2;
		static SDL_Texture* scene3a;
		static SDL_Texture* scene3b;
		static SDL_Texture* scene3e;
		static SDL_Texture* scene4a;
		static SDL_Texture* scene4b;
		static SDL_Texture* caveScene1;
		static SDL_Texture* caveScene2;
		static SDL_Texture* mainMenu;
		static SDL_Texture* scene3f;
		static SDL_Texture* poptions;

		static SDL_Texture* invTexture1;
		static SDL_Texture* invTexture2;
		static SDL_Texture* invTexture3;
		static SDL_Texture* invTexture4;
		static SDL_Texture* invTexture5;
		static SDL_Texture* invTexture6;
		static SDL_Texture* invTexture7;

		static SDL_Texture* menuTexture;
		static SDL_Texture* spriteTexture;

		static SDL_Surface* spriteAction;

		static SDL_Surface* spriteDown1;
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


		static SDL_Rect background;
		static SDL_Rect background2;
		static SDL_Rect background3;
		static SDL_Rect background4;
		static SDL_Rect background5;
		static SDL_Rect menuBackground;
		static SDL_Rect rSecretDrawing;

		static SDL_Rect RCursor;

		//Hover Button Rect
		static SDL_Rect RHoverNewGame;
		static SDL_Rect RHoverConinueGame;
		static SDL_Rect RHoverOptions;
		static SDL_Rect RHoverPlus;
		static SDL_Rect RHoverMinus;
		static SDL_Rect RHoverPickup;
		static SDL_Rect RHoverLook;
		static SDL_Rect RHoverUse;
		static SDL_Rect RHoverPull;
		static SDL_Rect RHoverOpen;
		static SDL_Rect RHoverLog;
		static SDL_Rect RHoverExit;
		static SDL_Rect RHoverNoSound;
		static SDL_Rect RHoverContinue1;
		static SDL_Rect RHoverFScreen;
		static SDL_Rect RHoverExitGame;

		SDL_Surface* menuSurface;
		SDL_Surface* Scursor;

	
		//Scene Surfaces.
		SDL_Surface* imageSurface;
		static SDL_Surface* spriteSurface;

	private:


	public:
		void Scene1Textures();
		void Scene2Textures();
		void Scene3Textures();
		void Scene4Textures();
		void MovementTextures();
		void LoadActionTextures();
		void TextureUpdater(SDL_Surface* texture, std::string action);
		int AssetSizeCalc(std::string texture);
		int AssetPosCalc(std::string texture);
	};





}