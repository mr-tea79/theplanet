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


	int SQLInsertInventory(std::string itemName, int itemUsed);

	int SQLCreateGameSave(std::string scene);

	int checkItem(std::string itemName);

	void ContinueGame();

	void CalcInventoryPositions();

	int useItem(std::string itemName);

	int gameSave(std::string currentScene);

	int gameSpeedSave();

	int purgeDatabase();

	void continueGameCheck();
};


}
#endif