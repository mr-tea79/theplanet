
#ifndef MENUINTERACTION_H_
#define MENUINTERACTION_H_

#pragma once
#include <string>
#include <SDL.h>
#include "PlayerObjects.h"
#include "Inventory.h"
#include "Scene1.h"


namespace brightland{


class MenuInteraction
{


public:
	
	static int wrongAction;
	static std::string wrongActionMessage;
	

	void doAction();
	void useChecker(int gd, int gy);
	void clearMessages();
	
	std::string PickUp(int x, int y, int gd, int gy, int mInteraction);
	std::string Pull(int x, int y, int gd, int gy, int mInteraction);
	std::string MenuSelect(int x, int y, int gd, int gy, int mInteraction);
	std::string Use(int x, int y, int gd, int gy, int mInteraction);
	std::string Open(int x, int y, int gd, int gy, int mInteraction);
	std::string Look(int x, int y, int gd, int gy, int mInteraction);
	std::string MenuAction(int x, int y, int gd, int gy, int mInteraction);



	
};

}
#endif