#include "Inventory.h"
#include "Scene1.h"
#include "PlayerMovement.h"
#include <iostream>
#include <sstream>

using namespace brightland;

std::string Inventory::inv;

SDL_Rect Inventory::inv1 = { 700, 650, 40, 40 };
SDL_Rect Inventory::inv2 = { 760, 610, 60, 60 };
SDL_Rect Inventory::inv3 = { 880, 650, 40, 40 };
SDL_Rect Inventory::inv4 = { 760, 700, 60, 60 };
SDL_Rect Inventory::inv7 = { 760, 700, 60, 60 };

//Clears the game progress.
int Inventory::purgeDatabase() {

	sqlite3* db;
	char* zErrMsg = 0;
	int rc;
	const char* sql;
	const char* data = "";
	sqlite3_stmt* stmt = NULL;
	int i = 0;
	
	/* Open database */
	rc = sqlite3_open("Inventory.db", &db);

	if (rc) {
		return(0);
	}
	else {
	}

	/* Create SQL statement */
	sql = "DELETE FROM tblInventory";	

	/* Execute SQL statement */
	rc = sqlite3_exec(db, sql, NULL, NULL, NULL);

	//Clean up.
	sqlite3_finalize(stmt);

	sqlite3_close(db);
	
	return 0;
}

//Save the speed of the character movement.
int Inventory::gameSpeedSave() {

	sqlite3* db;
	char* zErrMsg = 0;
	int rc;
	const char* sql;
	const char* data = "";
	sqlite3_stmt* stmt = NULL;
	int i = 0;
	
	float vs = PlayerMovement::vspeed;
	float hs = PlayerMovement::hspeed;

	//Convert player movement speed float to string to insert into database.
	std::ostringstream ss;
	ss << vs;
	std::string vspeed(ss.str());
	std::string hspeed(ss.str());

	rc = sqlite3_open("Inventory.db", &db);

	if (rc) {

		return(0);
	}
	else {
	}

	/* Create SQL statement */
	sql = "UPDATE tblProgress SET vspeed=?,hspeed=? WHERE id=1";

	//sqlite using variables in statement.
	sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL);

	sqlite3_bind_text(stmt, 1, vspeed.c_str(), strlen(vspeed.c_str()), 0);
	sqlite3_bind_text(stmt, 2, hspeed.c_str(), strlen(hspeed.c_str()), 0);


	//Execute parameter statement.
	sqlite3_step(stmt);
	i++;
	//Clean up.
	sqlite3_finalize(stmt);

	sqlite3_close(db);

	return 0;
}

//Save player progress.
int Inventory::gameSave(std::string currentScene) {

	sqlite3* db;
	char* zErrMsg = 0;
	int rc;
	const char* sql;
	const char* data = "";
	sqlite3_stmt* stmt = NULL;
	int i = 0;
	int size = Scene1::SPRITE_SIZE;
	int y = Scene1::yPosition;
	int x = Scene1::xPosition;
	std::string invItems = inv;
	std::string objectToDestroy = Scene1::objectToDestroy;
	
	rc = sqlite3_open("Inventory.db", &db);

	if (rc) {		
		return(0);
	}
	else {
	}

	/* Create SQL statement */
	sql = "UPDATE tblProgress SET scene=?,x=?,y=?,size=?,objectToDestroy=?,inv=?,secretCounter=? WHERE id=1";

	//sqlite using variables in statement.
	sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL);

	sqlite3_bind_text(stmt, 1, currentScene.c_str(), strlen(currentScene.c_str()), 0);
	sqlite3_bind_int(stmt, 2, x);
	sqlite3_bind_int(stmt, 3, y);
	sqlite3_bind_int(stmt, 4, size);
	sqlite3_bind_text(stmt, 5, objectToDestroy.c_str(), strlen(objectToDestroy.c_str()), 0);
	sqlite3_bind_text(stmt, 6, invItems.c_str(), strlen(invItems.c_str()), 0);
	sqlite3_bind_int(stmt, 7, Scene1::secretTrigger);

	//Execute parameter statement.
	sqlite3_step(stmt);
	i++;
	//Clean up.
	sqlite3_finalize(stmt);

	sqlite3_close(db);

	return 0;

}

int Inventory::SQLCreateGameSave(std::string scene) {

	sqlite3* db;
	char* zErrMsg = 0;
	int rc;
	const char* sql;
	const char* data = "";
	sqlite3_stmt* stmt = NULL;
	int i = 0;
	int id = 1;



	rc = sqlite3_open("Inventory.db", &db);

	if (rc) {
		return(0);
	}
	else {
	}

	/* Create SQL statement */
	sql = "INSERT into tblProgress (scene,id,x,y,size) VALUES(?,?)";

	//sqlite using variables in statement.
	sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL);

	sqlite3_bind_text(stmt, 1, scene.c_str(), strlen(scene.c_str()), 0);
	sqlite3_bind_int(stmt, 2, id);
	

	//Execute parameter statement.
	sqlite3_step(stmt);
	i++;
	//Clean up.
	sqlite3_finalize(stmt);

	sqlite3_close(db);

	return 0;
}

//Update the database if item is used by the player.
int Inventory::useItem(std::string itemName) {

	sqlite3* db;
	char* zErrMsg = 0;
	int rc;
	const char* sql;
	const char* data = "";
	sqlite3_stmt* stmt = NULL;
	int i = 0;

	rc = sqlite3_open("Inventory.db", &db);

	if (rc) {
		
		return(0);
	}
	else {
	}

	/* Create SQL statement */
	sql = "UPDATE tblInventory SET itemUsed=1 WHERE item=?";

	//sqlite using variables in statement.
	sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL);

	sqlite3_bind_text(stmt, 1, itemName.c_str(), strlen(itemName.c_str()), 0);
	//sqlite3_bind_int(stmt, 2, 1);

	//Execute parameter statement.
	sqlite3_step(stmt);
	i++;
	//Clean up.
	sqlite3_finalize(stmt);

	sqlite3_close(db);

	return 0;
}

//Load in player progress.
void Inventory::ContinueGame() {

	sqlite3* db;
	char* zErrMsg = 0;
	int rc;
	const char* sql;
	const char* data = "";
	sqlite3_stmt* stmt = NULL;
	int i = 0;
	std::string scene = "1";


	/* Open database */
	rc = sqlite3_open("Inventory.db", &db);

	if (rc) {
		scene = "1";
		
	}
	else {
	}

	/* Create SQL statement */
	sql = "SELECT * FROM tblProgress WHERE id=1";
	//sqlite using variables in statement.
	sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL);
	sqlite3_bind_text(stmt, 1, scene.c_str(), strlen(scene.c_str()), 0);
	//	sqlite3_bind_int(stmt, 2, pin);


	while (sqlite3_step(stmt) != SQLITE_DONE) {

		int i;
		int num_cols = sqlite3_column_count(stmt);


		for (i = 0; i < num_cols; i++)
		{
			std::string columnName;

			switch (sqlite3_column_type(stmt, i))
			{
			case (SQLITE3_TEXT):
				columnName = sqlite3_column_name(stmt, i);
				if (columnName == "scene") {
					std::cout << "SCENE: " << sqlite3_column_text(stmt, i) << std::endl;
					Scene1::SceneBackground = std::string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, i)));
				}
				if (columnName == "inv") {
					std::cout << "INV: " << sqlite3_column_text(stmt, i) << std::endl;
					Inventory::inv = std::string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, i)));
				}

				if (columnName == "objectToDestroy") {
					Scene1::objectToDestroy = std::string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, i)));
					std::cout << "OBJECT TO DESTROY: " << Scene1::objectToDestroy;
				}
				if (columnName == "vspeed") {
					std::string vspeed = std::string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, i)));
					PlayerMovement::vspeed = std::stof(vspeed);
				}
				if (columnName == "hspeed") {
					std::string hspeed = std::string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, i)));
					PlayerMovement::hspeed = std::stof(hspeed);
				}

				break;
			
			case (SQLITE_INTEGER):
				columnName = sqlite3_column_name(stmt, i);
				if (columnName == "size") {
					std::cout << "size: " << sqlite3_column_int(stmt, i) << std::endl;
					Scene1::SPRITE_SIZE = sqlite3_column_int(stmt, i);
				}
				if (columnName == "x") {					
					std::cout << "x: " << sqlite3_column_int(stmt, i) << std::endl;
					Scene1::xPosition = sqlite3_column_int(stmt, i);
				}
				if (columnName == "y") {
					std::cout << "y: " << sqlite3_column_int(stmt, i) << std::endl;
					Scene1::yPosition = sqlite3_column_int(stmt, i);
				}
				if (columnName == "secretCounter") {
					std::cout << "secretCounter: " << sqlite3_column_int(stmt, i) << std::endl;
					Scene1::secretTrigger = sqlite3_column_int(stmt, i);
				}
		
				break;
			case (SQLITE_FLOAT):

				break;
			default:
				break;
			}
		}
		;
	}
	//Clean up.
	sqlite3_finalize(stmt);
	sqlite3_close(db);


}

//Check if item has been picked up.
int Inventory::checkItem(std::string itemName) {

	sqlite3* db;
	char* zErrMsg = 0;
	int rc;
	const char* sql;
	const char* data = "";
	sqlite3_stmt* stmt = NULL;
	int i = 0;
	int numberOfItems = 0;

	/* Open database */
	rc = sqlite3_open("Inventory.db", &db);

	if (rc) {
		
		return(0);
	}
	else {
	}

	/* Create SQL statement */
	sql = "SELECT item,itemUsed FROM tblInventory WHERE item=? AND itemUsed=0";
	//sqlite using variables in statement.
	sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL);
	sqlite3_bind_text(stmt, 1, itemName.c_str(), strlen(itemName.c_str()), 0);
//	sqlite3_bind_int(stmt, 2, pin);


	while (sqlite3_step(stmt) != SQLITE_DONE) {
	
		int i;
		int num_cols = sqlite3_column_count(stmt);


		for (i = 0; i < 2; i++)
		{
			switch (sqlite3_column_type(stmt, i))
			{
			case (SQLITE3_TEXT):
				//std::cout << "FOUND MATCHING ITEM" << std::endl;
				numberOfItems = 1;
				break;
			case (SQLITE_INTEGER):
			//	record = 1;
				break;
			case (SQLITE_FLOAT):

				break;
			default:
				break;
			}
		}
		;
	//	break;
	}
	//Clean up.
	sqlite3_finalize(stmt);
	sqlite3_close(db);



	return numberOfItems;
}

//Add item to player inventory.
int Inventory::SQLInsertInventory(std::string itemName, int itemUsed) {

	sqlite3* db;
	char* zErrMsg = 0;
	int rc;
	const char* sql;
	const char* data = "";
	sqlite3_stmt* stmt = NULL;
	int i = 0;


	rc = sqlite3_open("Inventory.db", &db);

	if (rc) {
		return(0);
	}
	else {
	}

	/* Create SQL statement */
	sql = "INSERT into tblInventory (item,itemUsed) VALUES(?,?)";

	//sqlite using variables in statement.
	sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL);

	sqlite3_bind_text(stmt, 1, itemName.c_str(), strlen(itemName.c_str()), 0);
	sqlite3_bind_int(stmt, 2, itemUsed);

	//Execute parameter statement.
	sqlite3_step(stmt);
	i++;
	//Clean up.
	sqlite3_finalize(stmt);

	sqlite3_close(db);

	return 0;
}