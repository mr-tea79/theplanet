
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
	
	void LoadActionTextures();
	std::string MenuInteraction::PickUp(int x, int y, int gd, int gy, int mInteraction, SDL_Texture* spriteTexture, SDL_Renderer* renderer, SDL_Surface* spriteDown1, SDL_Surface* spriteBack,std::string menuMessage);
	std::string MenuInteraction::MenuSelect(int x, int y, int gd, int gy, int mInteraction, SDL_Texture* spriteTexture, SDL_Renderer* renderer, SDL_Surface* spriteDown1, std::string menuMessage, std::string interactionMessage);
	std::string MenuInteraction::Use(int x, int y, int gd, int gy, int mInteraction, SDL_Texture* spriteTexture, SDL_Renderer* renderer, SDL_Surface* spriteDown1, SDL_Surface* spriteBack, std::string menuMessage);
	std::string MenuInteraction::Open(int x, int y, int gd, int gy, int mInteraction, SDL_Texture* spriteTexture, SDL_Renderer* renderer, SDL_Surface* spriteDown1, std::string menuMessage);
	std::string MenuInteraction::Look(int x, int y, int gd, int gy, int mInteraction, SDL_Texture* spriteTexture, SDL_Renderer* renderer, SDL_Surface* spriteDown1, SDL_Surface* spriteBack,std::string menuMessage);
	std::string MenuInteraction::MenuAction(int x, int y, int gd, int gy, int mInteraction, SDL_Texture* spriteTexture, SDL_Renderer* renderer, SDL_Surface* spriteDown1,std::string menuMessage);


	
};

}
#endif