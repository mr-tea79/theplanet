#include "Sound.h"
#include "Scene1.h"



using namespace brightland;

void Sound::playSounds() {
	
	Mix_PlayMusic(mus2, -1);
	Mix_Volume(1, MIX_MAX_VOLUME * 0.50);

}

void Sound::playMovementSounds() {
	
	Mix_PlayChannel(2, walk, 0);
	Mix_Volume(2, MIX_MAX_VOLUME * 0.02676767);

}

void Sound::playClickSound() {
	
	Mix_PlayChannel(3, click, 0);
	Mix_Volume(3, MIX_MAX_VOLUME * 0.02676767);
	
}

void Sound::playHoverSound() {

	Mix_PlayChannel(4, hover, 0);
	Mix_Volume(3, MIX_MAX_VOLUME * 0.02676767);

}

void Sound::loadHoverSound() {
	//mus = Mix_LoadMUS("Development Kits/Music/crunch-snow-sound-effect.mp3"); //Add your MP3 here for the background music.
	hover = Mix_LoadWAV("Development Kits/Music/338229__fachii__button-hover.wav");
}


void Sound::loadClickSound() {
	//mus = Mix_LoadMUS("Development Kits/Music/crunch-snow-sound-effect.mp3"); //Add your MP3 here for the background music.
	click = Mix_LoadWAV("Development Kits/Music/computer-mouse-click-sound.wav");
}


void Sound::loadMovementSounds() {
	//mus = Mix_LoadMUS("Development Kits/Music/crunch-snow-sound-effect.mp3"); //Add your MP3 here for the background music.
	walk = Mix_LoadWAV("Development Kits/Music/421128__giocosound__footstep-grass-4.wav");
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