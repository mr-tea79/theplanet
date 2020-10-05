#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>


namespace brightland {


	class Textures {
	public:
	
		//Texture used for menu dialog.
		static SDL_Texture* sceneTexture;
		static SDL_Texture* texture;
		static SDL_Texture* rocks;
		static SDL_Texture* rocks2;
		static SDL_Texture* computerScene1;
		static SDL_Texture* computerScene2;
	

		static SDL_Texture* wreakageScene;
		static SDL_Texture* scene1e;
		static SDL_Texture* scene1f;
		static SDL_Texture* scene1fa;
		static SDL_Texture* scene1fb;
		static SDL_Texture* scene1d;
		static SDL_Texture* scene1d2;

		static SDL_Texture* invTexture1;
		static SDL_Texture* invTexture2;
		static SDL_Texture* invTexture3;
		static SDL_Texture* invTexture4;
		static SDL_Texture* invTexture5;

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
		
		SDL_Surface* boxClosed;
		SDL_Surface* boxOpened;
		SDL_Surface* pda;
		SDL_Surface* flag;
		SDL_Surface* stars;
		SDL_Surface* tape;
		SDL_Surface* tent;

	public:
		void Scene1Textures();
		void Scene2Textures();


	};





}