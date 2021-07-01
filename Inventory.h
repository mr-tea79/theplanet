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
	static int inv3Used;
	static int inv4Used;
	static int inv5Used;
	static int inv6Used;
	static int inv7Used;

	static SDL_Rect inv1;
	static SDL_Rect inv2;
	static SDL_Rect inv3;
	static SDL_Rect inv4;
	static SDL_Rect inv5;
	static SDL_Rect inv7;


	int Inventory::SQLInsertInventory(std::string itemName, int itemUsed);

	int Inventory::checkItem(std::string itemName);

	int Inventory::useItem(std::string itemName);

	int Inventory::gameSave(std::string currentScene);

	int Inventory::purgeDatabase();
};


}
#endif