#include "Inventory.h"
#include "Scene1.h"
#include <iostream>

using namespace brightland;


int Inventory::inv3Used;
int Inventory::inv4Used;
int Inventory::inv5Used;
int Inventory::inv6Used;
int Inventory::inv7Used;

SDL_Rect Inventory::inv1 = { 700, 650, 40, 40 };
SDL_Rect Inventory::inv2 = { 760, 610, 60, 60 };
SDL_Rect Inventory::inv3 = { 880, 650, 40, 40 };
SDL_Rect Inventory::inv4 = { 760, 700, 60, 60 };
SDL_Rect Inventory::inv7 = { 760, 700, 60, 60 };


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

	rc = sqlite3_open("Inventory.db", &db);

	if (rc) {
		
		return(0);
	}
	else {
	}

	/* Create SQL statement */
	sql = "UPDATE tblProgress SET scene=?,x=?,y=?,size=? WHERE id=1";

	//sqlite using variables in statement.
	sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL);

	sqlite3_bind_text(stmt, 1, currentScene.c_str(), strlen(currentScene.c_str()), 0);
	sqlite3_bind_int(stmt, 2, x);
	sqlite3_bind_int(stmt, 3, y);
	sqlite3_bind_int(stmt, 4, size);


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

std::string Inventory::ContinueGame() {

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
		return scene;
	}
	else {
	}

	/* Create SQL statement */
	sql = "SELECT scene FROM tblProgress WHERE id=1";
	//sqlite using variables in statement.
	sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL);
	sqlite3_bind_text(stmt, 1, scene.c_str(), strlen(scene.c_str()), 0);
	//	sqlite3_bind_int(stmt, 2, pin);


	while (sqlite3_step(stmt) != SQLITE_DONE) {

		int i;
		int num_cols = sqlite3_column_count(stmt);


		for (i = 0; i < 2; i++)
		{
			switch (sqlite3_column_type(stmt, i))
			{
			case (SQLITE3_TEXT):
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
	}
	//Clean up.
	sqlite3_finalize(stmt);
	sqlite3_close(db);



	return scene;
}


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