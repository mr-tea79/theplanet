#include "Sound.h"
#include "Scene1.h"

using namespace brightland;

void Sound::playSounds() {
	
	Mix_PlayMusic(mus2, -1);
	Mix_Volume(1, MIX_MAX_VOLUME * 0.50);

}

void Sound::loadSounds(std::string sceneBackground) {

	if(Scene1::SceneBackground == "1"){
		
		mus2 = Mix_LoadMUS("Development Kits/Music/wind01.mp3"); //Add your MP3 here for the background music.
		playSounds();
	}
	if (Scene1::SceneBackground == "1b") {
	
		mus2 = Mix_LoadMUS("Development Kits/Music/esparks.mp3"); //Add your MP3 here for the background music.
		playSounds();
	}


}