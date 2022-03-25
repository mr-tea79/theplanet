#include <SDL.h>
#include "Scene1.h"
#include "SDL_mixer.h"


namespace brightland {

	class Sound {

	public:
		Mix_Music* mus, * mus2;  // Background Music
		Mix_Chunk* walk;
		Mix_Chunk* click;
		Mix_Chunk* hover;
		static bool soundOn;

	public:
		bool checkHoverLocation(int x, int y);
		void loadSounds(std::string sceneBackground);
		void loadMovementSounds();
		void playSounds();
		void loadClickSound();
		void loadHoverSound();
		void playHoverSound();
		void playClickSound();
		void playMovementSounds();
		void freeMusic();

	};


}