#include "Scene1.h"
#include "PlayerObjects.h"
#include "MenuInteraction.h"

#pragma once
#ifndef PLAYERMOVEMENT_H_
#define PLAYERMOVEMENT_H_

namespace brightland{
class PlayerMovement
{
public:
	static float hspeed;
	static float vspeed;
	static bool blink;

	//Scene Surfaces.
	SDL_Surface* imageSurface;

	void LoadMovementTextures();
		
	int PlayerMovement::walk(int x, int y, int gd, int gy, int screenWidth, int screenHeight);

	int PlayerMovement::walky(int x, int y, int gd, int gy, int screenWidth, int screenHeight);

	int doXWalkRight(int gd, int screenWidth);

	int doXWalkLeft(int gd, int screenWidth);

	int doYWalkUp(int gy);

	int doYWalkDown(int gy);


};
}
#endif