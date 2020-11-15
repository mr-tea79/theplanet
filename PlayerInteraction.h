#ifndef PLAYERINTERACTION_H_
#define PLAYERINTERACTION_H_

#pragma once
#include <string>
#include <SDL.h>
#include "PlayerObjects.h"
#include "Inventory.h"
#include "Scene1.h"
#include <SDL_ttf.h>





namespace brightland {


	class PlayerInteraction
	{
	private:
		//TTF_Font* font;
		//SDL_Surface* fsurface;
		//SDL_Color fcolor;
		//SDL_Texture* ftexture;
		const int WIDTH = 1024;
		const int HEIGHT = 768;
	public:
		static int playerMessage;

	public:
		std::string PlayerInteraction::PlayerMessage(int scene, int msgNumber);
		void PlayerInteraction::InteractionControllerHover(std::string interactionMessage);
		void PlayerInteraction::InteractionControllerObject(std::string interactionMessage,std::string gameObject);
		void PlayerInteraction::InteractionControllerUse(std::string useMessage, std::string openMessage, std::string gameObject);
		std::string PlayerInteraction::DisplayPlayerMessages();

		
	};

}
#endif