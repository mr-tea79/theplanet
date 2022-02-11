
#include "PlayerMovement.h"
#include "Textures.h"
#include "Inventory.h"
#include <iostream>
#include <SDL.h>
#include "Scene1.h"

using namespace brightland;
using namespace std;

static int position; //Used to update current position variable.

//Customize your speed to your liking.
float PlayerMovement::hspeed = 2.5;  //Left to Right.
float PlayerMovement::vspeed = 2.5;  //Up and Down.


int PlayerMovement::doXWalkRight(int gd, int screenWidth) {
  
    if (position == 0) {
        SDL_DestroyTexture(Textures::spriteTexture);
        Textures::spriteTexture = nullptr;
        Textures::spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, Textures::spriteRight1a);
        gd += hspeed; //Speed of sprite movement.
    }
    if (position == 1) {
        SDL_DestroyTexture(Textures::spriteTexture);
        Textures::spriteTexture = nullptr;
        Textures::spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, Textures::spriteRight2a);
        gd += hspeed;
    }
    if (position == 2) {
        SDL_DestroyTexture(Textures::spriteTexture);
        Textures::spriteTexture = nullptr;
        Textures::spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, Textures::spriteRight3a);
        gd += hspeed;
    }
    if (position == 3) {
        SDL_DestroyTexture(Textures::spriteTexture);
        Textures::spriteTexture = nullptr;
        Textures::spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, Textures::spriteRight4a);
        gd += hspeed;
        position = 0; //This achieves the animation effect.
    }
    //Prevent walking off the screen.
    if (gd == screenWidth - 50) {
        SDL_DestroyTexture(Textures::spriteTexture);
        Textures::spriteTexture = nullptr;
        Textures::spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, Textures::spriteLeft1a);
        gd += hspeed;
    }

    return gd;
}

int PlayerMovement::doXWalkLeft(int gd, int screenWidth) {

    if (position == 0) {
        SDL_DestroyTexture(Textures::spriteTexture);
        Textures::spriteTexture = nullptr;
        Textures::spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, Textures::spriteLeft1a);
        gd -= hspeed;
    }
    if (position == 1) {
        SDL_DestroyTexture(Textures::spriteTexture);
        Textures::spriteTexture = nullptr;
        Textures::spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, Textures::spriteLeft2a);
        gd -= hspeed;
    }
    if (position == 2) {
        SDL_DestroyTexture(Textures::spriteTexture);
        Textures::spriteTexture = nullptr;
        Textures::spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, Textures::spriteLeft3a);
        gd -= hspeed;
    }
    if (position == 3) {
        SDL_DestroyTexture(Textures::spriteTexture);
        Textures::spriteTexture = nullptr;
        Textures::spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, Textures::spriteLeft4a);
        gd -= hspeed;
        position = 0; //This achieves the animation effect.
    }

    //Prevent walking off the screen.
    if (gd == 0) {
        SDL_DestroyTexture(Textures::spriteTexture);
        Textures::spriteTexture = nullptr;
        Textures::spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, Textures::spriteRight1a);
        gd += hspeed;
    }

    return gd;
}


int PlayerMovement::doYWalkUp(int gy) {

    if (position == 0) {
        SDL_DestroyTexture(Textures::spriteTexture);
        Textures::spriteTexture = nullptr;
        Textures::spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, Textures::spriteBack1a);
        gy -= vspeed; //Speed of sprite movement.
    }
    if (position == 1) {
        SDL_DestroyTexture(Textures::spriteTexture);
        Textures::spriteTexture = nullptr;
        Textures::spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, Textures::spriteBack2a);
        gy -= vspeed;
    }
    if (position == 2) {
        SDL_DestroyTexture(Textures::spriteTexture);
        Textures::spriteTexture = nullptr;
        Textures::spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, Textures::spriteBack3a);
        gy -= vspeed;
        // position = 0; //This achieves the animation effect.
    }
    if (position == 3) {
        SDL_DestroyTexture(Textures::spriteTexture);
        Textures::spriteTexture = nullptr;
        Textures::spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, Textures::spriteBack3a);
        gy += vspeed;
        position = 0; //This achieves the animation effect.
    }

    return gy;

}

int PlayerMovement::doYWalkDown(int gy) {
    if (position == 0) {
        SDL_DestroyTexture(Textures::spriteTexture);
        Textures::spriteTexture = nullptr;
        Textures::spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, Textures::spriteDown3a);
        gy += vspeed; //Speed of sprite movement.
    }
    if (position == 1) {
        SDL_DestroyTexture(Textures::spriteTexture);
        Textures::spriteTexture = nullptr;
        Textures::spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, Textures::spriteDown1a);
        gy += vspeed;
    }
    if (position == 2) {
        SDL_DestroyTexture(Textures::spriteTexture);
        Textures::spriteTexture = nullptr;
        Textures::spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, Textures::spriteDown2a);
        gy += vspeed;
    }
    if (position == 3) {
        SDL_DestroyTexture(Textures::spriteTexture);
        Textures::spriteTexture = nullptr;
        Textures::spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, Textures::spriteDown2a);
        gy += vspeed;
        position = 0; //This achieves the animation effect.
    }

    return gy;

}



int PlayerMovement::walk(int x, int y, int gd, int gy, int screenWidth, int screenHeight) {

//Player Movement
   
    //Set the coordinates for walking left or right in the scene.

    ///////////////////// PLAYER OPTIONS ///////////////////////////////////////////////
       //GOING RIGHT
    if (Scene1::SceneBackground == "01") {

        if (gd <= x - 20 && y > 102 && y < 579) {
            gd = doXWalkRight(gd, screenWidth);
            position++;
        }

        //GOING LEFT
        else if (gd >= x - 10 && y > 102 && y < 579) {
            gd = doXWalkLeft(gd, screenWidth);
            position++;
        }

    }

    ///////////////////////// SCENE 4A SECRET ENTRANCE //////////////////////////////////////
    if (Scene1::SceneBackground == "4a") {

        //GO RIGHT   The " x -60 " prevents the player from walkig diagonally which looks wrong.
        if (gd <= x - 60 && y < 576 && x > 10 && x < 850) {
            gd = doXWalkRight(gd, screenWidth);
            position++;
        }

        //GO LEFT    The " x -15  " is required to allow the 'playerIsMoving' variable in Scene1 class to trigger when the player stops. If you don't have this, then the game wont know when the player stops and hover objects might not work.
        else if (gd >= x - 15 && y < 576 && x < 850 && x > 10) {
            gd = doXWalkLeft(gd, screenWidth);
            position++;
        }
    }


   ///////////////////////// SCENE 3F CRATOR //////////////////////////////////////
    if (Scene1::SceneBackground == "3f") {

        //GO RIGHT   The " x -60 " prevents the player from walkig diagonally which looks wrong.
        if (gd <= x - 60 && y > 200 && y < 482) {
            gd = doXWalkRight(gd, screenWidth);
            position++;
        }

        //GO LEFT    The " x -15  " is required to allow the 'playerIsMoving' variable in Scene1 class to trigger when the player stops. If you don't have this, then the game wont know when the player stops and hover objects might not work.
        else if (gd >= x - 15 && y > 200 && y < 482) {
            gd = doXWalkLeft(gd, screenWidth);
            position++;
        }
    }


          ///////////////////////// SCENE 3E CAVE DRAWING IN DIRT //////////////////////////////////////
    if (Scene1::SceneBackground == "3e") {

        //GO RIGHT   The " x -60 " prevents the player from walkig diagonally which looks wrong.
        if (gd <= x - 60 && y > 320 && y < 575) {
            gd = doXWalkRight(gd, screenWidth);
            position++;
        }

        //GO LEFT    The " x -15  " is required to allow the 'playerIsMoving' variable in Scene1 class to trigger when the player stops. If you don't have this, then the game wont know when the player stops and hover objects might not work.
        else if (gd >= x - 15 && y > 320 && y < 575) {
            gd = doXWalkLeft(gd, screenWidth);
            position++;
        }
    }

        ///////////////////////// SCENE 3D CAVE SCENE //////////////////////////////////////
    if (Scene1::SceneBackground == "3d") {

        //GO RIGHT   The " x -60 " prevents the player from walkig diagonally which looks wrong.
        if (gd <= x - 60 && y > 320 && y < 575) {
            gd = doXWalkRight(gd, screenWidth);
            position++;
        }

        //GO LEFT    The " x -15  " is required to allow the 'playerIsMoving' variable in Scene1 class to trigger when the player stops. If you don't have this, then the game wont know when the player stops and hover objects might not work.
        else if (gd >= x - 15 && y > 320 && y < 575) {
            gd = doXWalkLeft(gd,  screenWidth);
            position++;
        }
    }

        ///////////////////////// SCENE 3C DARK ROOM //////////////////////////////////////
    if (Scene1::SceneBackground == "3c") {

        //GO RIGHT   The " x -60 " prevents the player from walkig diagonally which looks wrong.
        if (gd <= x - 60 && y > 320 && y < 575) {
            gd = doXWalkRight(gd, screenWidth);
            position++;
        }

        //GO LEFT    The " x -15  " is required to allow the 'playerIsMoving' variable in Scene1 class to trigger when the player stops. If you don't have this, then the game wont know when the player stops and hover objects might not work.
        else if (gd >= x - 15 && y > 320 && y < 575) {
            gd = doXWalkLeft(gd, screenWidth);
            position++;
        }
    }

    ///////////////////////// SCENE 3B //////////////////////////////////////
    if (Scene1::SceneBackground == "3b") {
       
        if (gd < 750 && gy < 270) {
            gd = gd + 1;
            gd = doXWalkRight(gd, screenWidth);
            position++;
            Scene1::sceneHalt = 1;
        }


        //GOING RIGHT
        else if (gd <= x - 60 && y < 575) {
            gd = doXWalkRight(gd, screenWidth);
            position++;
        }
        //GOING LEFT
        else if (gd >= x && y < 575) {
            gd = doXWalkLeft(gd, screenWidth);

            position++;
        }
    }

    ///////////////////////// SCENE 3A //////////////////////////////////////

    //GOING RIGHT
    if (Scene1::SceneBackground == "3a") {

        if (gd <= x - 25 && y > 10 && y < 575) {
            gd = doXWalkRight(gd, screenWidth);
            position++;
        }

        //GOING LEFT
        else if (gd >= x && y > 10 && y < 575) {
            gd = doXWalkLeft(gd, screenWidth);
            position++;
        }
    }

    ///////////////////////// SCENE 1DA  INSIDE TENT //////////////////////////////////////
    if (Scene1::SceneBackground == "1da") {

        //Custom Boundries (Chairs etc) very tricky.
        if (gd == 541 && gy <360) {    
            SDL_DestroyTexture(Textures::spriteTexture);
            Textures::spriteTexture = nullptr;
            Textures::spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, Textures::spriteLeft1a);
            gd -= 3.5;
        }

        if (gd == 244 && y <= 500) {
            SDL_DestroyTexture(Textures::spriteTexture);
            Textures::spriteTexture = nullptr;
            Textures::spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, Textures::spriteDownp);
            gd += 3.5;
        }
     
        //GOING RIGHT
        else if (gd <= x - 60 && y > 120 && y < 575 && gd <739) {
            gd = doXWalkRight(gd, screenWidth);
            position++;
        }

        //GOING LEFT
        else if (gd >= x && y > 120 && y < 575) {
            gd = doXWalkLeft(gd, screenWidth);
            position++;
        }
    }

    ///////////////////////// SCENE 1F  SANDY CLEARING //////////////////////////////////////
    if (Scene1::SceneBackground == "1f") {

        //GOING RIGHT
        if (gd <= x - 60 && y > 120 && y < 575) {
            gd = doXWalkRight(gd, screenWidth);
            position++;
        }

        //GOING LEFT
        else if (gd >= x && y > 120 && y < 575) {
            gd = doXWalkLeft(gd, screenWidth);
            position++;
        }
    }

    ///////////////////////// SCENE 1FB SANDY CLAERING WITH TENT //////////////////////////////////////
    if (Scene1::SceneBackground == "1fb") {

        //GOING RIGHT
        if (gd <= x - 60 && y > 120 && y < 575) {
            gd = doXWalkRight(gd, screenWidth);
            position++;
        }

        //GOING LEFT
        else if (gd >= x && y > 120 && y < 575) {
            gd = doXWalkLeft(gd, screenWidth);
            position++;
        }
      
    }

    ///////////////////////// SCENE 1E ROCKY SCENE //////////////////////////////////////

    //GOING RIGHT
    if (Scene1::SceneBackground == "1e") {

        if (gd <= x -20  && y > 272 && y < 579) {
            gd = doXWalkRight(gd, screenWidth);
            position++;
        }

        //GOING LEFT
        else if (gd >= x -10 && y > 272 && y < 579) {
            gd = doXWalkLeft(gd, screenWidth);
            position++;
        }

    }

    ///////////////////////// SCENE 1B INSIDE SHIP WRECKAGE //////////////////////////////////////
    if (Scene1::SceneBackground == "1b") {

        //Set boundries where player can walk (To prevent walking too far)
        if (gd < 200) {
            SDL_DestroyTexture(Textures::spriteTexture);
            Textures::spriteTexture = nullptr;
            Textures::spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, Textures::spriteDown1a);
            Scene1::sceneHalt = 1;
            gd += 9.5; //Speed of sprite movement.
        }
       
        if (gd > 560) {
            SDL_DestroyTexture(Textures::spriteTexture);
            Textures::spriteTexture = nullptr;
            Textures::spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, Textures::spriteDown1a);
            Scene1::sceneHalt = 1;
            gd -= 9.5; //Speed of sprite movement.
        }

        //GO RIGHT
        if (gd <= x -40 && y > 320 && y < 575) {
            gd = doXWalkRight(gd, screenWidth);
            position++;
        }

        //GO LEFT
        else if (gd >= x -15 && y > 300 && y < 575) {
            gd = doXWalkLeft(gd, screenWidth);
            position++;
        }
    }


    ///////////////////////// SCENE 1 STARTING SCENE //////////////////////////////////////
    if (Scene1::SceneBackground == "1") {
        
        //GO RIGHT   The " x -60 " prevents the player from walkig diagonally which looks wrong.
        if (gd <= x -60  && y > 320 && y < 575) {     
            gd = doXWalkRight(gd, screenWidth);
            position++;
        }

        //GO LEFT    The " x -15  " is required to allow the 'playerIsMoving' variable in Scene1 class to trigger when the player stops. If you don't have this, then the game wont know when the player stops and hover objects might not work.
        else if (gd >= x -15 && y > 320 && y < 575) {
            gd = doXWalkLeft(gd, screenWidth);
            position++;
        }
    }

    return gd;
}//END OF WALK METHOD


/////////////////////////////// WALKY IS FOR MOVING THE CHARACTER UP AND DOWN  ////////////////////////////////////////////////////////////////

int PlayerMovement::walky(int x, int y, int gd, int gy, int screenWidth, int screenHeight) {

    //Check if player has put patch on their suit.
    if (Inventory::inv.find("3") != std::string::npos){
       Textures::spriteDown1a = Textures::spriteDownp;
       Textures::spriteDown2a = Textures::spriteDown2p;
       Textures::spriteDown3a = Textures::spriteDown3p;
    }

    ///////////////////////// SCENE 4A SECRET ENTRANCE //////////////////////////////////////
    if (Scene1::SceneBackground == "4a") {

        //Make character smaller and bigger depending on distance.
   
        if (gy > 455) {
            Scene1::SPRITE_SIZE = 65;
        }
        else {
            Scene1::SPRITE_SIZE = 60;
        }

        //GOING UP
        if (gy >= y && y < 575 && y >367) {
            gy = doYWalkUp(gy);
            position++;
        }

        //GOING DOWN
        else if (gy <= y - 100 && y < 585) {
            gy = doYWalkDown(gy);
            position++;
        }
    }


    ///////////////////////// SCENE 3F CRATOR //////////////////////////////////////
    if (Scene1::SceneBackground == "3f") {

        //Make character smaller and bigger depending on distance.
        if (gy < 290) {
            Scene1::SPRITE_SIZE = 50;
        }
        if (gy < 310) {
            Scene1::SPRITE_SIZE = 50;
        }
        if (gy < 355) {
            Scene1::SPRITE_SIZE = 50;
        }

        if (gy > 355) {
            Scene1::SPRITE_SIZE = 50;
        }

        //GOING UP
        if (gy >= y && y < 580 && y >200) {
            gy = doYWalkUp(gy);
            position++;
        }

        //GOING DOWN
        else if (gy <= y - 100 && y < 582) {
            gy = doYWalkDown(gy);
            position++;
        }
    }


    ///////////////////////// SCENE 3D CAVE SCENE //////////////////////////////////////
    if (Scene1::SceneBackground == "3d") {

        //Make character bigger or smaller depending on distance.
        if (gy < 390) {
            Scene1::SPRITE_SIZE = 90;
        }
        if (gy < 400) {
            Scene1::SPRITE_SIZE = 110;
        }

        if (gy > 440) {
            Scene1::SPRITE_SIZE = 120;
        }

        //GOING UP
        if (gy >= y && y < 575 && y >390) {
            gy = doYWalkUp(gy);
            position++;
        }

        //GOING DOWN
        else if (gy <= y - 100 && y < 575) {
            gy = doYWalkDown(gy);
            position++;
        }
    }

    ///////////////////////// SCENE 3A DARK ROOM //////////////////////////////////////
    if (Scene1::SceneBackground == "3c") {

        //Make character bigger or smaller depending on distance.
        if (gy < 390) {
            Scene1::SPRITE_SIZE = 90;
        }
        if (gy < 400) {
            Scene1::SPRITE_SIZE = 110;
        }

        if (gy > 440) {
            Scene1::SPRITE_SIZE = 120;
        }

        //GOING UP
        if (gy >= y && y < 575 && y >238) {
            gy = doYWalkUp(gy);
            position++;
        }

        //GOING DOWN
        else if (gy <= y - 100 && y < 575) {
            gy = doYWalkDown(gy);
            position++;
        }
    }


    ///////////////////////// SCENE 3B ROCK FACE //////////////////////////////////////
    if (Scene1::SceneBackground == "3b") {

        if (gd < 750 && gy < 370) {        
            gy = gy + 1;
            gy = doYWalkDown(gy);
            position++;     
            Scene1::sceneHalt = 1;
        }

        //GOING UP
        else if (gy >= y) {
            gy = doYWalkUp(gy);
            position++;
        }

        //GOING DOWN
        else if (gy <= y && y < 590 && gy > 0) {
            gy = doYWalkDown(gy);
            position++;
        }
    }

    ///////////////////////// SCENE 3A //////////////////////////////////////
    if (Scene1::SceneBackground == "3a") {
        
        //GOING UP
        if (gy >= y) {
            gy = doYWalkUp(gy);
            position++;
        }

        //GOING DOWN
        else if (gy <= y && y < 590 && gy > 0) {
            gy = doYWalkDown(gy);
            position++;
        }
    }

    ///////////////////////// SCENE 1E ROCKY SCENE//////////////////////////////////////
    if (Scene1::SceneBackground == "1e") {

        //GOING UP
        if (gy >= y && y < 570 && y >330) {
            gy = doYWalkUp(gy);
            position++;
        }

        //GOING DOWN
        else if (gy <= y && y < 580 && gy < 386) {
            gy = doYWalkDown(gy);
            position++;
        }
    }

    ///////////////////////// SCENE 1B INSIDE SPACE SHIP WRECKAGE //////////////////////////////////////
    if (Scene1::SceneBackground == "1b") {

        //GOING UP
        if (gy >= y && y < 570 && y >330 ) {
            gy = doYWalkUp(gy);
            position++;
        }
        
        //GOING DOWN
        else if (gy <= y -100 && y < 575 && y > gd && gy > 250 && gy < 445) {
            gy = doYWalkDown(gy);
            position++;
        }
    }

    ///////////////////////// SCENE 1F SANDY CLEARING //////////////////////////////////////
    if (Scene1::SceneBackground == "1f") {

        //Make the character appaer smaller as they move up and down.
        if (gy < 290) {
            Scene1::SPRITE_SIZE = 70;
        }
        if (gy < 310) {
            Scene1::SPRITE_SIZE = 100;
        }
        if (gy < 355) {
            Scene1::SPRITE_SIZE = 110;
        }

        if (gy > 355) {
            Scene1::SPRITE_SIZE = 120;
        }

        //GOING UP
        if (gy >= y && y < 575 && y >158) {
            gy = doYWalkUp(gy);
            position++;
        }

        //GOING DOWN
        else if (gy <= y - 100 && y < 575) {
            gy = doYWalkDown(gy);
            position++;
        }
    }
    
    ///////////////////////// SCENE 1FB SANDY CLEARING WITH TENT //////////////////////////////////////
    if (Scene1::SceneBackground == "1fb") {

        //Make character smaller and bigger depending on distance.
        if (gy < 290) {
            Scene1::SPRITE_SIZE = 70;
        }
        if (gy < 310) {
            Scene1::SPRITE_SIZE = 100;
        }
        if (gy < 355) {
            Scene1::SPRITE_SIZE = 110;
        }

        if (gy > 355) {
            Scene1::SPRITE_SIZE = 120;
        }

        //GOING UP
        if (gy >= y && y < 575 && y >158) {
            gy = doYWalkUp(gy);
            position++;
        }

        //GOING DOWN
        else if (gy <= y - 100 && y < 575) {    
            gy = doYWalkDown(gy);
            position++;
        }
    }

    ///////////////////////// SCENE 1DA INSIDE TENT //////////////////////////////////////
    if (Scene1::SceneBackground == "1da") {

        //GOING UP
        if (gy >= y && y < 575 && y >376 && x > 300) {
            gy = doYWalkUp(gy);
            position++;
        }

        //GOING DOWN
        else if (gy <= y - 100 && y < 565 && x > 300 && gy <410 ) {
            gy = doYWalkDown(gy);
            position++;
        }
    }


    ///////////////////////// SCENE 1 FIRST SCENE //////////////////////////////////////
    if (Scene1::SceneBackground == "1") {

        //Make character bigger or smaller depending on distance.
        if (gy < 390) {
            Scene1::SPRITE_SIZE = 90;
        }
        if (gy < 400) {
            Scene1::SPRITE_SIZE = 110;
        }

        if (gy > 440) {
            Scene1::SPRITE_SIZE = 120;
        }

        //GOING UP
        if (gy >= y  && y < 575 && y >238) {
            gy = doYWalkUp(gy);
            position++;
        }

        //GOING DOWN
        else if (gy <= y - 100 && y < 575) {
            gy = doYWalkDown(gy);
            position++;
        }
    }


    return gy;

}//END OF WALKY METHOD



