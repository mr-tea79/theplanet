#ifndef INVENTORY_H_
#define INVENTORY_H_
#include "sqlite3.h"
#include <string>

#pragma once

namespace brightland{
class Inventory
{
public:
	int Inventory::SQLInsertInventory(std::string itemName, int itemUsed);

	int Inventory::checkItem(std::string itemName);

	int Inventory::useItem(std::string itemName);

	int Inventory::purgeDatabase();
};


}
#endif