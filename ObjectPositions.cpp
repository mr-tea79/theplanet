#include "ObjectPositions.h"
#include "Scene1.h"


using namespace brightland;
using namespace std;
// X and Y
int ObjectPositions::x;
int ObjectPositions::y;

int ObjectPositions::PlayerLocationX;
int ObjectPositions::PlayerLocationY;

//Scene Areas
int ObjectPositions::WREAKAGEDOOR_X;
int ObjectPositions::WREAKAGEDOOR_Y;
int ObjectPositions::ENGINE_X;
int ObjectPositions::ENGINE_Y;
int ObjectPositions::ROCKS_X;
int ObjectPositions::ROCKS_Y;
int ObjectPositions::ROCKS_SX; //SX = WIDTH X
int ObjectPositions::ROCKS_SY; //SY = HEIGHT Y

//Inventory
int ObjectPositions::INV1_X;
int ObjectPositions::INV1_Y;
int ObjectPositions::INV1_SX;
int ObjectPositions::INV1_SY;

//Pick up objects
int ObjectPositions::PDA_X;
int ObjectPositions::PDA_Y;
int ObjectPositions::PDA_SX;
int ObjectPositions::PDA_SY;
int ObjectPositions::ATAPE_X;
int ObjectPositions::ATAPE_Y;
int ObjectPositions::TENT_X;
int ObjectPositions::TENT_Y;
int ObjectPositions::FLAG_X;
int ObjectPositions::FLAG_Y;
int ObjectPositions::FLAG_SX;
int ObjectPositions::FLAG_SY;

//Hover interactions
int ObjectPositions::MOON_X;
int ObjectPositions::MOON_Y;

//Menu 
int ObjectPositions::USE_X;
int ObjectPositions::USE_Y;
int ObjectPositions::OPEN_X;
int ObjectPositions::OPEN_Y;
int ObjectPositions::LOOK_Y;
int ObjectPositions::LOOK_X;
int ObjectPositions::PICKUP_X;
int ObjectPositions::PICKUP_Y;
int ObjectPositions::PULL_X;
int ObjectPositions::PULL_Y;
int ObjectPositions::MENU_Y;
int ObjectPositions::MENU_HY;
int ObjectPositions::HOVERTEXT_X;
int ObjectPositions::HOVERTEXT_Y;

//Main Menu buttons. They are referred to in: Textures.cpp,ObjectPositions.h
int ObjectPositions::NEWGAME_X;
int ObjectPositions::NEWGAME_Y;
int ObjectPositions::CONTINUE_X;
int ObjectPositions::CONTINUE_Y;
int ObjectPositions::OPTIONS_X;
int ObjectPositions::OPTIONS_Y;

//Offset boundires
int ObjectPositions::OFFSET_X;
int ObjectPositions::OFFSET_Y;

//Background
int ObjectPositions::BACKGROUND_H;


//The following 2 functions are used to place the objects that a player can interact with or pick up. This is new and will be done on percentages so the screen resolution changes would 
//make the objects still be in the correct positions and not hard coded for each different resoluion.


//Place scene objects like rocks as an example.
//USED WHERE: in Textures.cpp.
void ObjectPositions::PlaceSceneObjects() {
    CalcObjectXAbsolutePosition(0, "ROCKS_X"), CalcObjectYAbsolutePosition(38, "ROCKS_Y"); //Set rocks position.
    CalcObjectXAbsolutePosition(80, "ROCKS_SX"), CalcObjectYAbsolutePosition(40, "ROCKS_SY"); //Set rocks size.
    CalcObjectXAbsolutePosition(54, "PDA_X"), CalcObjectYAbsolutePosition(65, "PDA_Y"); //Set PDA position.
    CalcObjectXAbsolutePosition(3, "PDA_SX"), CalcObjectYAbsolutePosition(3, "PDA_SY"); //Set PDA size.
    CalcObjectXAbsolutePosition(64, "FLAG_X"), CalcObjectYAbsolutePosition(35, "FLAG_Y"); 
    CalcObjectXAbsolutePosition(9, "FLAG_SX"), CalcObjectYAbsolutePosition(25, "FLAG_SY"); 
  
}

void ObjectPositions::PlaceInventoryObjects() {
    CalcObjectXAbsolutePosition(68, "INV1_X"), CalcObjectYAbsolutePosition(86, "INV1_Y"); //Set Inventory 1 position.
    CalcObjectXAbsolutePosition(5, "INV1_SX"), CalcObjectYAbsolutePosition(5, "INV1_SY"); //Set Inventory 1 size.
}

//Place the Y position of the Menu
//USED WHERE: Scene1.cpp just before setting up the player interaction menu rect.
void ObjectPositions::PlaceMenuYPosition() {
    CalcObjectYAbsolutePosition(78, "MENU_Y");
    CalcObjectYAbsolutePosition(75, "MENU_HY");
    

}

void ObjectPositions::SetHoverTextPosition() {
    CalcObjectYAbsolutePosition(79, "HOVERTEXT_Y");
    CalcObjectXAbsolutePosition(40, "HOVERTEXT_X");
}

//Set height of background image rect (Scene image)
//USED WHERE: Textures.cpp
void ObjectPositions::SetBackgroundHeight() {
    CalcObjectYAbsolutePosition(78, "BACKGROUND_H");
}

float ObjectPositions::CalcObjectYPositionPercentage(float position, std::string objectName) {
    int result;
    result = position / Scene1::HEIGHT * 100;
     

    return result;
}

float ObjectPositions::CalcObjectXPositionPercentage(float position, std::string objectName) {
    int result;
    result = position / Scene1::WIDTH * 100;
  
    return result;
}

//Increase or Decrease asset size by a percentage. This could be the player or items in the game.
//USE CASE: This is used to deal with a change in the display resolution of the game.

int ObjectPositions::CalcAssetSize(int size,float percentIncrease) {
   //Increased value = base + base * % increase / 100
    int result;
    result = size + size * percentIncrease / 100;
    return result;
}

//Decrease asset size by a percentage.
int ObjectPositions::CalcAssetDecreaseSize(int size, int percentDecrease) {
    //Percent Decrease = [(Old Value - New Value) / Old Value] × 100]
   // number - (10 / 100) * number
    int result;
    result = size - size * percentDecrease / 100;
    return result;
}

float ObjectPositions::CalcObjectXAbsolutePosition(float position,std::string objectName) {
    int result;

    result = position * Scene1::WIDTH / 100;
    objectName == "WREACKDOOR_X" ? ObjectPositions::WREAKAGEDOOR_X = result : 0;
    objectName == "TENT_X" ? ObjectPositions::TENT_X = result : 0;
    objectName == "ATAPE_X" ? ObjectPositions::ATAPE_X = result : 0;
    objectName == "PDA_X" ? ObjectPositions::PDA_X = result : 0;
    objectName == "PDA_SX" ? ObjectPositions::PDA_SX = result : 0;
    objectName == "FLAG_X" ? ObjectPositions::FLAG_X = result : 0;
    objectName == "FLAG_SX" ? ObjectPositions::FLAG_SX = result : 0;
    objectName == "INV1_X" ? ObjectPositions::INV1_X = result : 0;
    objectName == "INV1_SX" ? ObjectPositions::INV1_SX = result : 0;
    objectName == "XPC" ? ObjectPositions::x = result : 0;
    objectName == "MOON_X" ? ObjectPositions::MOON_X = result : 0;
    objectName == "ENGINE_X" ? ObjectPositions::ENGINE_X = result : 0;
    objectName == "ROCKS_X" ? ObjectPositions::ROCKS_X = result : 0;
    objectName == "ROCKS_SX" ? ObjectPositions::ROCKS_SX = result : 0;
    objectName == "HOVERTEXT_X" ? ObjectPositions::HOVERTEXT_X = result : 0;
    objectName == "USE_X" ? ObjectPositions::USE_X = result : 0;
    objectName == "OPEN_X" ? ObjectPositions::OPEN_X = result : 0;
    objectName == "LOOK_X" ? ObjectPositions::LOOK_X = result : 0;
    objectName == "PICKUP_X" ? ObjectPositions::PICKUP_X = result : 0;
    objectName == "PULL_X" ? ObjectPositions::PULL_X = result : 0;
    objectName == "NEWGAME_X" ? ObjectPositions::NEWGAME_X = result : 0;
    objectName == "CONTINUE_X" ? ObjectPositions::CONTINUE_X = result : 0;
    objectName == "OPTIONS_X" ? ObjectPositions::OPTIONS_X = result : 0;
   

    return result;
}

float ObjectPositions::CalcObjectYAbsolutePosition(float position,std::string objectName) {
    int result;

    result = position * Scene1::HEIGHT / 100;
    objectName == "WREACKDOOR_Y" ? ObjectPositions::WREAKAGEDOOR_Y = result : 0;
    objectName == "TENT_Y" ? ObjectPositions::TENT_Y = result : 0;
    objectName == "ATAPE_Y" ? ObjectPositions::ATAPE_Y = result : 0;
    objectName == "PDA_Y" ? ObjectPositions::PDA_Y = result : 0;
    objectName == "PDA_SY" ? ObjectPositions::PDA_SY = result : 0;
    objectName == "FLAG_Y" ? ObjectPositions::FLAG_Y = result : 0;
    objectName == "FLAG_SY" ? ObjectPositions::FLAG_SY = result : 0;
    objectName == "INV1_Y" ? ObjectPositions::INV1_Y = result : 0;
    objectName == "INV1_SY" ? ObjectPositions::INV1_SY = result : 0;
    objectName == "YPC" ? ObjectPositions::y = result : 0;
    objectName == "MOON_Y" ? ObjectPositions::MOON_Y = result : 0;
    objectName == "ENGINE_Y" ? ObjectPositions::ENGINE_Y = result : 0;
    objectName == "MENU_Y" ? ObjectPositions::MENU_Y = result : 0;
    objectName == "MENU_HY" ? ObjectPositions::MENU_HY = result : 0;
    objectName == "BACKGROUND_H" ? ObjectPositions::BACKGROUND_H = result : 0;
    objectName == "ROCKS_Y" ? ObjectPositions::ROCKS_Y = result : 0;
    objectName == "ROCKS_SY" ? ObjectPositions::ROCKS_SY = result : 0;
    objectName == "HOVERTEXT_Y" ? ObjectPositions::HOVERTEXT_Y = result : 0;
    objectName == "USE_Y" ? ObjectPositions::USE_Y = result : 0;
    objectName == "OPEN_Y" ? ObjectPositions::OPEN_Y = result : 0;
    objectName == "LOOK_Y" ? ObjectPositions::LOOK_Y = result : 0;
    objectName == "PICKUP_Y" ? ObjectPositions::PICKUP_Y = result : 0;
    objectName == "PULL_Y" ? ObjectPositions::PULL_Y = result : 0;
    objectName == "NEWGAME_Y" ? ObjectPositions::NEWGAME_Y = result : 0;
    objectName == "CONTINUE_Y" ? ObjectPositions::CONTINUE_Y = result : 0;
    objectName == "OPTIONS_Y" ? ObjectPositions::OPTIONS_Y = result : 0;

    return result;
}