#include "Sound.h"
#include "Scene1.h"
#include "ObjectPositions.h"


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

	if (Scene1::mouseMoveYPercent >= 62 && Scene1::mouseMoveYPercent <= 71 && Scene1::mouseMoveXPercent >= 15 && Scene1::mouseMoveXPercent <= 36 && Scene1::SceneBackground == "0") {
		return false;
	}
	else if (Scene1::mouseMoveYPercent >= 48 && Scene1::mouseMoveYPercent <= 56 && Scene1::mouseMoveXPercent >= 15 && Scene1::mouseMoveXPercent <= 36 && Scene1::SceneBackground == "0") {
		return false;
	}
	else if (Scene1::mouseMoveYPercent >= 75 && Scene1::mouseMoveYPercent <= 83 && Scene1::mouseMoveXPercent >= 15 && Scene1::mouseMoveXPercent <= 36 && Scene1::SceneBackground == "0") {
		return false;
	}

	else if (x > 27 && x < 77 && y > 28 && y < 77 && Scene1::SceneBackground == "0") {
		return false;
	}

	else if (x > 927 && x < 951 && y > 62 && y < 87 && Scene1::SceneBackground == "0") {
		return false;
	}
	else if (x > 927 && x < 951 && y > 62 && y < 87 && Scene1::SceneBackground == "0") {
		return false;
	}
	//Exit game hover button
	else if (x > 17 && x < 47 && y > 704 && y < 742 && Scene1::SceneBackground == "0") {
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

	if (Scene1::SceneBackground == "0") {
	//	mus2 = Mix_LoadMUS("Development Kits/Music/Game_Music.mp3"); //Add your MP3 here for the background music.
	//	playSounds();
	}

	if (sceneBackground == "X") {
		Mix_HaltMusic;
	}

}

void Sound::freeMusic() {
	//Mix_FreeMusic(mus2);

}