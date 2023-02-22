#include "ObjectPositions.h"
#include "Scene1.h"

using namespace brightland;

//Pick up objects
int ObjectPositions::PDA_X;
int ObjectPositions::PDA_Y;
int ObjectPositions::ATAPE_X;
int ObjectPositions::ATAPE_Y;
int ObjectPositions::TENT_X;
int ObjectPositions::TENT_Y;

//Hover interactions
int ObjectPositions::MOON_X;
int ObjectPositions::MOON_Y;

//Menu 
int ObjectPositions::USE_X;
int ObjectPositions::USE_Y;


//The following 2 functions are used to place the objects that a player can interact with or pick up. This is new and will be done on percentages so the screen resolution changes would 
//make the objects still be in the correct positions and not hard coded for each different resoluion.

float ObjectPositions::CalcObjectYPosition(float position, std::string objectName) {
    int result;
    result = position * Scene1::HEIGHT;
    objectName == "PDA_Y" ? ObjectPositions::PDA_Y = result : 0;
    objectName == "ATAPE_Y" ? ObjectPositions::ATAPE_Y = result : 0;
    objectName == "TENT_Y" ? ObjectPositions::TENT_Y = result : 0;
    objectName == "MOON_Y" ? ObjectPositions::MOON_Y = result : 0;
    objectName == "USE_Y" ? ObjectPositions::USE_Y = result : 0;

    return result;
}

float ObjectPositions::CalcObjectXPosition(float position, std::string objectName) {
    int result;
    result = position * Scene1::WIDTH;
    objectName == "PDA_X" ? ObjectPositions::PDA_X = result : 0;
    objectName == "ATAPE_X" ? ObjectPositions::ATAPE_X = result : 0;
    objectName == "TENT_X" ? ObjectPositions::TENT_X = result : 0;
    objectName == "MOON_X" ? ObjectPositions::MOON_X = result : 0;
    objectName == "USE_X" ? ObjectPositions::USE_Y = result : 0;

    return result;
}
