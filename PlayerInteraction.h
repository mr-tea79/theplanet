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
		std::string PlayerMessage(int msgNumber);
		void InteractionControllerHover(std::string interactionMessage);
		void InteractionControllerObject(std::string interactionMessage,std::string gameObject);
		void InteractionControllerUse(std::string useMessage,std::string gameObject);
		void InteractionControllerOpen(std::string openMessage,std::string gameObject);
		void InteractionControllerLook(std::string lookMessage, std::string gameObject);
		void InteractionControllerPull(std::string lookMessage, std::string gameObject);
		void InteractionControllerAction(std::string actionMessage, std::string gameObject);
		std::string DisplayPlayerMessages();	
	};

}
#endif