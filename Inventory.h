#ifndef INVENTORY_H_
#define INVENTORY_H_
#include "sqlite3.h"
#include <string>
#include <SDL.h>

#pragma once

namespace brightland{
class Inventory
{
public:

	static std::string inv;

	static SDL_Rect inv1;
	static SDL_Rect inv2;
	static SDL_Rect inv3;
	static SDL_Rect inv4;
	static SDL_Rect inv5;
	static SDL_Rect inv7;


	int Inventory::SQLInsertInventory(std::string itemName, int itemUsed);

	int Inventory::SQLCreateGameSave(std::string scene);

	int Inventory::checkItem(std::string itemName);

	void Inventory::ContinueGame();

	int Inventory::useItem(std::string itemName);

	int Inventory::gameSave(std::string currentScene);

	int Inventory::gameSpeedSave(float hspeed);

	int Inventory::purgeDatabase();
};


}
#endif