#include "Sound.h"
#include "Scene1.h"



using namespace brightland;


bool Sound::soundOn = true;


bool Sound::checkSoundStatus(bool status) {
	Sound::soundOn = status;
	if (Sound::soundOn == false) {
		Mix_HaltMusic;
		
	
	}
	return status;
}
/*
void Sound::updateSoundStatus(bool status) {
	Sound::soundOn = status;
	

}
*/

bool Sound::checkHoverLocation(int x, int y) {

	if (x >= 159 && x <= 376 && y >= 480 && y <= 546 && Scene1::SceneBackground == "0") {
		return false;
	}
		
	else if (x >= 159 && x <= 376 && y >= 378 && y <= 438 && Scene1::SceneBackground == "0") {
		return false;
	}		
	//Player Options hover button (main menu)
	else if (x >= 159 && x <= 376 && y >= 573 && y <= 644 && Scene1::SceneBackground == "0") {
		return false;
	}
	else if (x > 27 && x < 77 && y > 28 && y < 77 && Scene1::SceneBackground == "0") {
		return false;
	}
	else
		return true;
	
}


void Sound::playSounds() {
	if (Sound::soundOn == true) {
		Mix_PlayMusic(mus2, -1);
		Mix_Volume(1, MIX_MAX_VOLUME * 0.20);
	}
	else {
		Mix_HaltMusic();
	}
}

void Sound::playMovementSounds() {
	if (Sound::soundOn == true) {
		Mix_PlayChannel(2, walk, 0);
		Mix_Volume(2, MIX_MAX_VOLUME * 0.02676767);
	}
}

void Sound::playClickSound() {
	if (Sound::soundOn == true) {
		Mix_PlayChannel(3, click, 0);
		Mix_Volume(3, MIX_MAX_VOLUME * 0.02676767);
	}
}

void Sound::playHoverSound() {
	if (Sound::soundOn == true) {
		Mix_PlayChannel(4, hover, 0);
		Mix_Volume(3, MIX_MAX_VOLUME * 0.02676767);
	}
}

void Sound::loadHoverSound() {
	//mus = Mix_LoadMUS("Development Kits/Music/crunch-snow-sound-effect.mp3"); //Add your MP3 here for the background music.
	hover = Mix_LoadWAV("Development Kits/Music/button1.wav");
}


void Sound::loadClickSound() {
	//mus = Mix_LoadMUS("Development Kits/Music/crunch-snow-sound-effect.mp3"); //Add your MP3 here for the background music.
	click = Mix_LoadWAV("Development Kits/Music/computer-mouse-click-sound.wav");
}


void Sound::loadMovementSounds() {
	//mus = Mix_LoadMUS("Development Kits/Music/crunch-snow-sound-effect.mp3"); //Add your MP3 here for the background music.
	walk = Mix_LoadWAV("Development Kits/Music/footstepsOut.mp3");
}

void Sound::loadSounds(std::string sceneBackground) {
	//if(Scene1::SceneBackground == "1" || Scene1::SceneBackground == "1fb" || Scene1::SceneBackground == "3b" || Scene1::SceneBackground == "1e"
	//	|| Scene1::SceneBackground == "1f"){

	//	mus2 = Mix_LoadMUS("Development Kits/Music/wind01.mp3"); //Add your MP3 here for the background music.
		//playSounds();
	//}

//	if (Scene1::SceneBackground == "3a") {
		//mus2 = Mix_LoadMUS("Development Kits/Music/sound-of-wind-blowing.mp3"); //Add your MP3 here for the background music.
		//playSounds();
	//}

	//if (Scene1::SceneBackground == "3c" || Scene1::SceneBackground == "3d") {
		//mus2 = Mix_LoadMUS("Development Kits/Music/Water-dripping.mp3"); //Add your MP3 here for the background music.
		//playSounds();
	//}
//	if (Scene1::SceneBackground == "1b") {
	//	mus2 = Mix_LoadMUS("Development Kits/Music/Wreckage.mp3"); //Add your MP3 here for the background music.
	//	playSounds();
	//}
//	if (Scene1::SceneBackground == "1da") {
		//mus2 = Mix_LoadMUS("Development Kits/Music/modular-ambient-04-792.mp3"); //Add your MP3 here for the background music.
		//playSounds();
	//}
	if (Scene1::SceneBackground == "0") {
		mus2 = Mix_LoadMUS("Development Kits/Music/Game_Music.mp3"); //Add your MP3 here for the background music.
		playSounds();
	}

	if (sceneBackground == "X") {
		Mix_HaltMusic;
	}

}

void Sound::freeMusic() {
	//Mix_FreeMusic(mus2);

}