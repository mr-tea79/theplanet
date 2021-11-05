
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
	void useChecker();
	
	std::string MenuInteraction::PickUp(int x, int y, int gd, int gy, int mInteraction);
	std::string MenuInteraction::Pull(int x, int y, int gd, int gy, int mInteraction);
	std::string MenuInteraction::MenuSelect(int x, int y, int gd, int gy, int mInteraction);
	std::string MenuInteraction::Use(int x, int y, int gd, int gy, int mInteraction);
	std::string MenuInteraction::Open(int x, int y, int gd, int gy, int mInteraction);
	std::string MenuInteraction::Look(int x, int y, int gd, int gy, int mInteraction);
	std::string MenuInteraction::MenuAction(int x, int y, int gd, int gy, int mInteraction);



	
};

}
#endif