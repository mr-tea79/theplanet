#ifndef PLAYERINTERACTION_H_
#define PLAYERINTERACTION_H_

#pragma once

#include "Scene1.h"

namespace brightland {


	class PlayerInteraction
	{
	private:
		const int WIDTH = 1024;
		const int HEIGHT = 768;
	public:
		static int playerMessage;

	public:
		void textDimensions(int messageLength);
		std::string PlayerInteraction::PlayerMessage(int scene, int msgNumber);
		void PlayerInteraction::InteractionControllerHover(std::string interactionMessage);
		void PlayerInteraction::InteractionControllerObject(std::string interactionMessage,std::string gameObject);
		void PlayerInteraction::InteractionControllerUse(std::string useMessage,std::string gameObject);
		void PlayerInteraction::InteractionControllerOpen(std::string openMessage,std::string gameObject);
		void PlayerInteraction::InteractionControllerLook(std::string lookMessage, std::string gameObject);
		void PlayerInteraction::InteractionControllerPull(std::string lookMessage, std::string gameObject);
		void PlayerInteraction::InteractionControllerAction(std::string actionMessage, std::string gameObject);
		std::string PlayerInteraction::DisplayPlayerMessages();	
	};

}
#endif