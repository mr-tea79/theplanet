#include "Sound.h"
#include "Scene1.h"

using namespace brightland;

void Sound::playSounds() {
	
	Mix_PlayMusic(mus2, -1);
	Mix_Volume(1, MIX_MAX_VOLUME * 0.50);

}

void Sound::loadSounds(std::string sceneBackground) {

	if(Scene1::SceneBackground == "1" || Scene1::SceneBackground == "1fb" || Scene1::SceneBackground == "3b"){
		
		mus2 = Mix_LoadMUS("Development Kits/Music/wind01.mp3"); //Add your MP3 here for the background music.
		playSounds();
	}

	if (Scene1::SceneBackground == "3a") {

		mus2 = Mix_LoadMUS("Development Kits/Music/sound-of-wind-blowing.mp3"); //Add your MP3 here for the background music.
		playSounds();
	}

	if (Scene1::SceneBackground == "3c" || Scene1::SceneBackground == "3d") {

		mus2 = Mix_LoadMUS("Development Kits/Music/Water-dripping.mp3"); //Add your MP3 here for the background music.
		playSounds();
	}


	if (Scene1::SceneBackground == "1b") {
	
		mus2 = Mix_LoadMUS("Development Kits/Music/Electricity-sound-effect.mp3"); //Add your MP3 here for the background music.
		playSounds();
	}
	if (Scene1::SceneBackground == "1da") {

		mus2 = Mix_LoadMUS("Development Kits/Music/modular-ambient-04-792.mp3"); //Add your MP3 here for the background music.
		playSounds();
	}



}

void Sound::freeMusic() {
	//Mix_FreeMusic(mus2);

}