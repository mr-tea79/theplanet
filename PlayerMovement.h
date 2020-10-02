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

	void LoadMovementTextures();
		
	int PlayerMovement::walk(int x, int y, int gd, int gy, int screenWidth, int screenHeight, SDL_Texture* spriteTexture, SDL_Texture* ftexture, 
		SDL_Texture* dialogmTexture);

	int PlayerMovement::walky(int x, int y, int gd, int gy, int screenWidth, int screenHeight, SDL_Texture* spriteTexture, SDL_Texture* ftexture,
		SDL_Texture* dialogmTexture);


};
}
#endif