
#include "PlayerMovement.h"
#include "Textures.h"
#include "Inventory.h"
#include <iostream>
#include <SDL.h>
#include "Scene1.h"
#include "ObjectPositions.h"

using namespace brightland;
using namespace std;

static int position; //Used to update current position variable.
float PlayerMovement::hspeed = 2.5;
float PlayerMovement::vspeed = 2.5;

bool PlayerMovement::blink;

int PlayerMovement::doXWalkRight(int gd, int screenWidth) {
    //Scene1::playerIsMoving = 1;
    Textures tex;
    ObjectPositions op;
 

    blink = false;
    if (position == 0) {
        tex.TextureUpdater(Textures::spriteRight1a, "Movement");
        gd += hspeed; //Speed of sprite movement.
    }
    if (position == 1) {
        tex.TextureUpdater(Textures::spriteRight2a, "Movement");
        gd += hspeed;
      
    }
    if (position == 2) {
        tex.TextureUpdater(Textures::spriteRight3a, "Movement");
        gd += hspeed;
        position = 0; //This achieves the animation effect.

    }
    if (position == 3) {
        tex.TextureUpdater(Textures::spriteRight4a, "Movement");
        gd += hspeed;
        position = 0; //This achieves the animation effect.
    }
    //Prevent walking off the screen.
    if (gd == screenWidth - 50) {
        tex.TextureUpdater(Textures::spriteLeft1a, "Movement");
        gd += hspeed;
    }


    return gd;
}

int PlayerMovement::doXWalkLeft(int gd, int screenWidth) {
    //Scene1::playerIsMoving = 1;
    Textures tex;
    ObjectPositions op;


    blink = false;
    if (position == 0) {
        tex.TextureUpdater(Textures::spriteLeft1a, "Movement");
        gd -= hspeed;

    }
    if (position == 1) {
        tex.TextureUpdater(Textures::spriteLeft2a, "Movement");
        gd -= hspeed;
     
    }
    if (position == 2) {
        tex.TextureUpdater(Textures::spriteLeft3a, "Movement");
        gd -= hspeed;
        position = 0; //This achieves the animation effect.
    }
    if (position == 3) {
        tex.TextureUpdater(Textures::spriteLeft4a, "Movement");
        gd -= hspeed;
        position = 0; //This achieves the animation effect.
    }

    //Prevent walking off the screen.
   // if (gd == 0) {
     //   tex.TextureUpdater(Textures::spriteRight1a, "Movement");
      //  gd += hspeed;
    //}

    return gd;
}


int PlayerMovement::doYWalkUp(int gy) {
  //  Scene1::playerIsMoving = 1;
    Textures tex;
    ObjectPositions op;
 
    blink = false;
    if (position == 0) {
        tex.TextureUpdater(Textures::spriteBack1a, "Movement");
        gy -= vspeed; //Speed of sprite movement.
    }
    if (position == 1) {
        tex.TextureUpdater(Textures::spriteBack2a, "Movement");
        gy -= vspeed;
    }
    if (position == 2) {
        tex.TextureUpdater(Textures::spriteBack3a, "Movement");
        gy -= vspeed;
        // position = 0; //This achieves the animation effect.
    }
    if (position == 3) {
        tex.TextureUpdater(Textures::spriteBack3a, "Movement");
        gy += vspeed;
        position = 0; //This achieves the animation effect.
    }

    return gy;

}

int PlayerMovement::doYWalkDown(int gy) {

   // Scene1::playerIsMoving = 1;
    Textures tex;
    ObjectPositions op;
    blink = true;
    if (position == 0) {
        tex.TextureUpdater(Textures::spriteDown3a, "Movement");
        gy += vspeed; //Speed of sprite movement.
    }
    if (position == 1) {
        tex.TextureUpdater(Textures::spriteDown1a, "Movement");
        gy += vspeed;
    }
    if (position == 2) {
        tex.TextureUpdater(Textures::spriteDown2a, "Movement");
        gy += vspeed;
    }
    if (position == 3) {
        tex.TextureUpdater(Textures::spriteDown2a, "Movement");
        gy += vspeed;
        position = 0; //This achieves the animation effect.
    }

    return gy;

}



int PlayerMovement::walk(int x, int y, int gd, int gy, int screenWidth, int screenHeight) {

    //Ternary operator
    //(expr) ? <true logic> : <false logic>  (IF TRUE ? DO THIS : ELSE DO THIS)
    //Used to reduce lots of IF statements.
    ObjectPositions op;
   
    Scene1::xp = op.CalcObjectXPositionPercentage(Scene1::gdSprite.x, "X");
    int mouseClickYPercent = op.CalcObjectYPositionPercentage(y, "Y"); //To stop player moving if you click in the menu area.
    Scene1::playerIsMoving = 1;
  //  std::cout << Scene1::xp << std::endl;
 

    ///////////////////// PLAYER OPTIONS ///////////////////////////////////////////////
    if (Scene1::SceneBackground == "01") {
        gd <= x - 20 && y > 102 && y < 579 ? gd = doXWalkRight(gd, screenWidth), position++ : move = 0;
        gd >= x - 10 && y > 102 && y < 579 ? gd = doXWalkLeft(gd, screenWidth), position++ : move = 0;
    }

    ///////////////////////// SCENE 4A SECRET ENTRANCE //////////////////////////////////////
    if (Scene1::SceneBackground == "4a") {
        gd <= x - 60 && y < 576 && x > 10 && x < 850 ? gd = doXWalkRight(gd, screenWidth), position++ : move = 0;
        gd >= x - 15 && y < 576 && x < 850 && x > 10 ? gd = doXWalkLeft(gd, screenWidth), position++ : move = 0;

    }

   ///////////////////////// SCENE 3F CRATOR //////////////////////////////////////
    if (Scene1::SceneBackground == "3f") {
        gd <= x - 60 && y > 200 && y < 482 ? gd = doXWalkRight(gd, screenWidth), position++ : move = 0;
        gd >= x - 15 && y > 200 && y < 482 ? gd = doXWalkLeft(gd, screenWidth), position++ : move = 0;
   
    }

    ///////////////////////// SCENE 3E CAVE DRAWING IN DIRT //////////////////////////////////////
    if (Scene1::SceneBackground == "3e") {
        gd <= x - 60 && y > 320 && y < 575 ? gd = doXWalkRight(gd, screenWidth), position++ : move = 0;
        gd >= x - 15 && y > 320 && y < 575 ? gd = doXWalkLeft(gd, screenWidth), position++ : move = 0;

    }

    ///////////////////////// SCENE 3D CAVE SCENE //////////////////////////////////////
    if (Scene1::SceneBackground == "3d") {
        gd <= x - 60 && y > 320 && y < 575 ? gd = doXWalkRight(gd, screenWidth), position++ : move = 0;
        gd >= x - 15 && y > 320 && y < 575 ? gd = doXWalkLeft(gd, screenWidth), position++ : move = 0;
    }

    ///////////////////////// SCENE 3C DARK ROOM //////////////////////////////////////
    if (Scene1::SceneBackground == "3c") {
        gd <= x - 60 && y > 320 && y < 575 ? gd = doXWalkRight(gd, screenWidth), position++ : move = 0;
        gd >= x - 15 && y > 320 && y < 575 ? gd = doXWalkLeft(gd, screenWidth), position++ : move = 0;
    }

    ///////////////////////// SCENE 3B //////////////////////////////////////
    if (Scene1::SceneBackground == "3b") {
        gd <= x - 60 && y < 575 ? gd = doXWalkRight(gd, screenWidth), position++ : move = 0;
        gd >= x && y < 575 ? gd = doXWalkLeft(gd, screenWidth), position++ : move = 0;
        
        //Custom boundry
        gd < 750 && gy < 270 ? Scene1::sceneHalt = 1 : move = 0;
    }

    ///////////////////////// SCENE 3A //////////////////////////////////////
    if (Scene1::SceneBackground == "3a") {
        gd <= x - 25 && y > 10 && y < 575 ? gd = doXWalkRight(gd, screenWidth), position++ : move = 0;
        gd >= x && y > 10 && y < 575 ? gd = doXWalkLeft(gd, screenWidth), position++ : move = 0;
    }

    ///////////////////////// SCENE 1DA  INSIDE TENT //////////////////////////////////////
    if (Scene1::SceneBackground == "1da") {
        gd <= x - 60 && y > 170 && y < 575 && gd < 739 ? gd = doXWalkRight(gd, screenWidth), position++ : move = 0;
        gd >= x && y > 120 && y < 575 ? gd = doXWalkLeft(gd, screenWidth), position++ : move = 0;
   
    }

    ///////////////////////// SCENE 1F  SANDY CLEARING //////////////////////////////////////
    if (Scene1::SceneBackground == "1f") {
        gd <= x - 60 && y > 120 && y < 575 ? gd = doXWalkRight(gd, screenWidth), position++ : move = 0;
        gd >= x && y > 120 && y < 575 ? gd = doXWalkLeft(gd, screenWidth), position++ : move = 0;
    }

    ///////////////////////// SCENE 1FB SANDY CLAERING WITH TENT //////////////////////////////////////
    if (Scene1::SceneBackground == "1fb") {
        gd <= x - 60 && y > 120 && y < 575 ? gd = doXWalkRight(gd, screenWidth), position++ : move = 0;
        gd >= x && y > 120 && y < 575 ? gd = doXWalkLeft(gd, screenWidth), position++ : move = 0;
      
    }

    ///////////////////////// SCENE 1E ROCKY SCENE //////////////////////////////////////////////////////
    if (Scene1::SceneBackground == "1e") {
        gd <= x - 20 && y > 272 && y < 579 ? gd = doXWalkRight(gd, screenWidth), position++ : move = 0;
        gd >= x - 10 && y > 272 && y < 579 ? gd = doXWalkLeft(gd, screenWidth), position++ : move = 0;
    }

    ///////////////////////// SCENE 1B INSIDE SHIP WRECKAGE //////////////////////////////////////////
    if (Scene1::SceneBackground == "1b") {
        gd <= x - 40 && y > 320 && y < 575 ? gd = doXWalkRight(gd, screenWidth), position++ : move = 0;
        gd >= x - 15 && y > 300 && y < 575 ? gd = doXWalkLeft(gd, screenWidth), position++ : move = 0;
        
        //Custom boundries
        gd < 200 ? Scene1::sceneHalt = 1 : move = 0;
        gd > 560 ? Scene1::sceneHalt = 1 : move = 0;     

    }

    ///////////////////////// SCENE 1 STARTING SCENE //////////////////////////////////////
    if (Scene1::SceneBackground == "1" && mouseClickYPercent <75) {

        gd <= x -60 && Scene1::xp <= 90 &&  Scene1::xp >= 2 ? gd = doXWalkRight(gd, screenWidth), position++ : move = 0;
        gd >= x - 10 && Scene1::xp <= 90 && Scene1::xp >= 2 ? gd = doXWalkLeft(gd, screenWidth), position++ : move = 0;
       // gy <= y && Scene1::yp < 68 && Scene1::yp < 60 ? gy = doYWalkDown(gy), position++ : move = 0;

       // gd <= x - 60 && y > 320 && y < 575 ? gd = doXWalkRight(gd, screenWidth), position++ : move = 0;
    //    gd >= x - 10 && y > 320 && y < 575 ? gd = doXWalkLeft(gd, screenWidth), position++ : move = 0;
    }

    return gd;
}


/////////////////////////////// WALKY IS FOR MOVING THE CHARACTER UP AND DOWN  ////////////////////////////////////////////////////////////////

int PlayerMovement::walky(int x, int y, int gd, int gy, int screenWidth, int screenHeight) {
    //Ternary operator
    //(expr) ? <true logic> : <false logic>  (IF TRUE ? DO THIS : ELSE DO THIS)
    //Used to reduce lots of IF statements.
    ObjectPositions op;
    Scene1::yp = op.CalcObjectYPositionPercentage(Scene1::gdSprite.y, "Y");
    Scene1::playerIsMoving = 1;
  //  std::cout << Scene1::yp << std::endl;

    //Check if player has put patch on their suit.
    if (Inventory::inv.find("3") != std::string::npos){
       Textures::spriteDown1a = Textures::spriteDownp;
       Textures::spriteDown2a = Textures::spriteDown2p;
       Textures::spriteDown3a = Textures::spriteDown3p;
    }

    ///////////////////////// SCENE 4A SECRET ENTRANCE //////////////////////////////////////
    if (Scene1::SceneBackground == "4a") {

        //Make character smaller and bigger depending on distance.
        gy > 455 ? Scene1::SPRITE_SIZE = 65 : Scene1::SPRITE_SIZE = 60;
       
        gy >= y && y < 575 && y >367 ? gy = doYWalkUp(gy), position++ : move = 0;
        gy <= y - 100 && y < 585 ? gy = doYWalkDown(gy), position++ : move = 0;

    }


    ///////////////////////// SCENE 3F CRATOR //////////////////////////////////////
    if (Scene1::SceneBackground == "3f") {

        gy < 355 ? Scene1::SPRITE_SIZE = 50 : move = 0;
        gy > 355 ? Scene1::SPRITE_SIZE = 50 : move = 0;

        gy >= y && y < 580 && y >200 ? gy = doYWalkUp(gy), position++ : move = 0;
        gy <= y - 100 && y < 582 ? gy = doYWalkDown(gy), position++ : move = 0;

    }


    ///////////////////////// SCENE 3D CAVE SCENE //////////////////////////////////////
    if (Scene1::SceneBackground == "3d") {
        gy < 390 ? Scene1::SPRITE_SIZE = 90 : move = 0;
        gy < 400 ? Scene1::SPRITE_SIZE = 110 : move = 0;
        gy > 440 ? Scene1::SPRITE_SIZE = 120 : move = 0;

        gy >= y && y < 575 && y >390 ? gy = doYWalkUp(gy), position++ : move = 0;
        gy <= y - 100 && y < 575 ? gy = doYWalkDown(gy), position++ : move = 0;

    }

    ///////////////////////// SCENE 3A DARK ROOM //////////////////////////////////////
    if (Scene1::SceneBackground == "3c") {
        gy < 390 ? Scene1::SPRITE_SIZE = 90 : move = 0;
        gy < 400 ? Scene1::SPRITE_SIZE = 110 : move = 0;
        gy > 440 ? Scene1::SPRITE_SIZE = 120 : move = 0;


        gy >= y && y < 575 && y >238 ? gy = doYWalkUp(gy), position++ : move = 0;
        gy <= y - 100 && y < 575 ? gy = doYWalkDown(gy), position++ : move = 0;

    }


    ///////////////////////// SCENE 3B ROCK FACE //////////////////////////////////////
    if (Scene1::SceneBackground == "3b") {

        //Custom boundry
        gd < 750 && gy < 370 ? gy = doYWalkDown(gy), position++, Scene1::sceneHalt = 1 : move = 0;

        gy >= y ? gy = doYWalkUp(gy), position++ : move = 0;
        gy <= y && y < 590 && gy > 0 ? gy = doYWalkDown(gy), position++ : move = 0;

    }

    ///////////////////////// SCENE 3A //////////////////////////////////////
    if (Scene1::SceneBackground == "3a") {
        gy >= y ? gy = doYWalkUp(gy), position++ : move = 0;
        gy <= y && y < 590 && gy > 0 ? gy = doYWalkDown(gy), position++ : move = 0;

    }

    ///////////////////////// SCENE 1E ROCKY SCENE//////////////////////////////////////
    if (Scene1::SceneBackground == "1e") {
        gy >= y && y < 570 && y >330 ? gy = doYWalkUp(gy), position++ : move = 0;
        gy <= y && y < 580 && gy < 386 ? gy = doYWalkDown(gy), position++ : move = 0;

    }

    ///////////////////////// SCENE 1B INSIDE SPACE SHIP WRECKAGE //////////////////////////////////////
    if (Scene1::SceneBackground == "1b") {
        gy >= y && y < 570 && y >330 ? gy = doYWalkUp(gy), position++ : move = 0;
        gy <= y - 100 && y < 575 && y > gd && gy > 250 && gy < 445 ? gy = doYWalkDown(gy), position++ : move = 0;

    }

    ///////////////////////// SCENE 1F SANDY CLEARING //////////////////////////////////////
    if (Scene1::SceneBackground == "1f") {
        gy < 290 ? Scene1::SPRITE_SIZE = 70 : move = 0;
        gy < 310 ? Scene1::SPRITE_SIZE = 100 : move = 0;
        gy < 355 ? Scene1::SPRITE_SIZE = 110 : move = 0;
        gy > 355 ? Scene1::SPRITE_SIZE = 120 : move = 0;

        gy >= y && y < 575 && y >158 ? gy = doYWalkUp(gy), position++ : move = 0;
        gy <= y - 100 && y < 575 ? gy = doYWalkDown(gy), position++ : move = 0;

    }
    
    ///////////////////////// SCENE 1FB SANDY CLEARING WITH TENT //////////////////////////////////////
    if (Scene1::SceneBackground == "1fb") {

        gy < 290 ? Scene1::SPRITE_SIZE = 70 : move = 0;
        gy < 310 ? Scene1::SPRITE_SIZE = 100 : move = 0;
        gy < 355 ? Scene1::SPRITE_SIZE = 110 : move = 0;
        gy > 355 ? Scene1::SPRITE_SIZE = 120 : move = 0;

        gy >= y && y < 575 && y >158 ? gy = doYWalkUp(gy), position++ : move = 0;
        gy <= y - 100 && y < 575 ? gy = doYWalkDown(gy), position++ : move = 0;

    }

    ///////////////////////// SCENE 1DA INSIDE TENT //////////////////////////////////////
    if (Scene1::SceneBackground == "1da") {
        gy >= y && y < 575 && y >376 && x > 300 ? gy = doYWalkUp(gy), position++ : move = 0;
        gy <= y - 100 && y < 565 && x > 300 && gy < 410 ? gy = doYWalkDown(gy), position++ : move = 0;

    }


    ///////////////////////// SCENE 1 FIRST SCENE //////////////////////////////////////
    if (Scene1::SceneBackground == "1") {
        Scene1::yp < 50 ? Scene1::SPRITE_SIZE = 90 : move = 0;
        Scene1::yp > 53 ? Scene1::SPRITE_SIZE = 100 : move = 0;
        Scene1::yp > 55 ? Scene1::SPRITE_SIZE = 120 : move = 0;
        gy >= y -10 && Scene1::yp < 68 && Scene1::yp > 48 ? gy = doYWalkUp(gy), position++ : move = 0;
        gy <= y -50 && Scene1::yp < 68 && Scene1::yp < 60 ? gy = doYWalkDown(gy), position++ : move = 0;
    

    }


    return gy;

}//END OF WALKY METHOD



