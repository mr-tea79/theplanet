#include <SDL.h>
#include "Scene1.h"
#include "SDL_mixer.h"


namespace brightland {

	class Sound {

	public:
		Mix_Music* mus, * mus2;  // Background Music

	public:
		void loadSounds(std::string sceneBackground);
		void playSounds();
		void freeMusic();

	};


}