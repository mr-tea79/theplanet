#include "PlayerInteraction.h"
#include "Scene1.h"
#include <SDL.h>
#include <iostream>
#include "Scene1.h"


using namespace brightland;

static int playerMessage;

std::string PlayerInteraction::PlayerMessage(int scene, int msgNumber) {

	if (msgNumber == 1) {
		std::string PlayerMessage = "Bonita Gonzalez finds herself stranded on an Alien planet.";
		return PlayerMessage;
	}
	
	else if (msgNumber == 2) {
		std::string PlayerMessage = "TOAD 1000: Bonita WAKE UP!";
		return PlayerMessage;
	}

	else if (msgNumber == 3) {
		std::string PlayerMessage = "TOAD 1000: Bonita.... Your Oxygen Level is critical! BEEP BEEP";
		return PlayerMessage;
	}

	else if (msgNumber == 4) {
		std::string PlayerMessage = "TOAD 1000: Suit pressure rising";
		return PlayerMessage;
	}

	else if (msgNumber == 5) {
		std::string PlayerMessage = "TOAD 1000: Bonita, you need to find a suitable area for base camp. Your Oxygen is limited.";
		return PlayerMessage;
	}

	else if (msgNumber == 6) {
		std::string PlayerMessage = "Wow, these self inflatable tents are pretty nice.";
		return PlayerMessage;
	}



	
	
}