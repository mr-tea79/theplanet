#ifndef PLAYERINTERACTION_H_
#define PLAYERINTERACTION_H_

#pragma once
#include <string>
#include <SDL.h>
#include "PlayerObjects.h"
#include "Inventory.h"
#include "Scene1.h"


namespace brightland {


	class PlayerInteraction
	{


	public:
		std::string PlayerInteraction::PlayerMessage(int scene, int msgNumber);
		
	};

}
#endif