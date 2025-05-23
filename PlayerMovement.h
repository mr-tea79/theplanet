#include "Scene1.h"
#include "PlayerObjects.h"
#include "MenuInteraction.h"

#pragma once
#ifndef PLAYERMOVEMENT_H_
#define PLAYERMOVEMENT_H_

namespace brightland{
class PlayerMovement
{

private:
	
public:
	static float hspeed;
	static float vspeed;
	static bool blink;
	int move;
	static int minPlayerSizeCounter;
	static int maxPlayerSizeCounter;

	//Scene Surfaces.
	SDL_Surface* imageSurface;

	//void LoadMovementTextures();

	void checkPlayerSize();
		
	int walk(int x, int y, int gd, int gy, int screenWidth, int screenHeight);

	int walky(int x, int y, int gd, int gy, int screenWidth, int screenHeight);

	int doXWalkRight(int gd, int screenWidth);

	int doXWalkLeft(int gd, int screenWidth);

	int doYWalkUp(int gy);

	int doYWalkDown(int gy);

	void setSpriteSize(int increase, int decrease);
	

};
}
#endif