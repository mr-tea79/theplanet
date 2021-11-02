#include <iostream>
#include <tuple>
#include "PlayerObjects.h"
#include "PlayerInteraction.h"
#include "Scene1.h"
#include <tuple>
#include <string>
#include "Inventory.h"
#include "Scene1.h"
#include "Textures.h"
#include "PlayerMovement.h"
#include "SDL_mixer.h"
#include "Sound.h"


using namespace brightland;

//Global
static std::string sceneBackground;
static int SPRITE_SIZE;
static int xPosition;
static int yPosition;
static int playerMessage;
//static int inv3Used;  //Duct Tape
int PlayerObjects::boxOpened;

SDL_Rect PlayerObjects::srcrect;
SDL_Rect PlayerObjects::dstrect;
SDL_Rect PlayerObjects::srcrect2;
SDL_Rect PlayerObjects::dstrect2;
SDL_Rect PlayerObjects::srcrect3;
SDL_Rect PlayerObjects::dstrect3;
SDL_Rect PlayerObjects::srcrect4;
SDL_Rect PlayerObjects::dstrect4;
SDL_Rect PlayerObjects::srcrect5;
SDL_Rect PlayerObjects::dstrect5;
SDL_Rect PlayerObjects::srcrect6;
SDL_Rect PlayerObjects::dstrect6;
SDL_Rect PlayerObjects::srcrect7;
SDL_Rect PlayerObjects::dstrect7;
SDL_Rect PlayerObjects::srcrect8;
SDL_Rect PlayerObjects::dstrect8;
SDL_Rect PlayerObjects::srcrect9;
SDL_Rect PlayerObjects::dstrect9;


void PlayerObjects::SetSpritePosition(int x, int y) {
   
    Scene1::gdSprite.x = x;
    Scene1::gdSprite.y = y;
   // SDL_WarpMouseInWindow(Scene1::window, 400, 400);

}

//HoverObjects will display information about objects of interest when the user hovers over them.
std::string PlayerObjects::HoverObjects(int x, int y, int scene,int gd, int gy) {

    std::string gameObject;

    //Check database if item has been picked up.
    Inventory inv;
   // PlayerObjects pob;
   
    //  int scene = 1; //Need to pass scene number in.
    int i = 0;
    int items = 0;


   // std::string menuMessages = pob.ObjectInteractionM1(gd, gy);
  //  gameObject = menuMessages;


    std::string message;

    //Menu Hover Messages

    if (x > 190 && x < 227 && y > 676 && y < 690 && Scene1::SceneBackground != "0") {       
        message = "Use";
    }


    if (x > 61 && x < 146 && y > 643 && y < 690 && Scene1::SceneBackground != "0") {
        message = "Pick up";
    }

    if (x > 178 && x < 232 && y > 723 && y < 744 && Scene1::SceneBackground != "0") {
        message = "Open";
    }

    if (x > 57 && x < 145 && y > 621 && y < 647 && Scene1::SceneBackground != "0") {
        message = "Look";
    }
    if (x > 59 && x < 114 && y > 723 && y < 744 && Scene1::SceneBackground != "0") {
        message = "Pull";
    }

    //Inventory Hover Messages 
   
    if (x >= 696 && x <= 736 && y >= 653 && y <= 687) {
        if(inv.checkItem("PDA") != 0)
            message = Scene1::actionStatement + " PDA";
    }

    if (x >= 764 && x <= 817 && y >= 695 && y <= 755) {
        if(inv.checkItem("Tent") != 0)
            message = Scene1::actionStatement + " Self Inflating Tent";
    }

    if (x >= 771 && x <= 821 && y >= 796 && y <= 798) {
        if(inv.checkItem("Flag") != 0)
            message = "Flag";
    }

    if (x >= 888 && x <= 915 && y >= 653 && y <= 684) {
        if(inv.checkItem("Tape") != 0)
            message = Scene1::actionStatement + " Ape Tape";
    }
    if (x >= 764 && x <= 815 && y >= 695 && y <= 753) {
        if (inv.checkItem("Battery Lantern") != 0)
            message = Scene1::actionStatement + " Battery Lantern";
    }


    if (x >= 888 && x <= 915 && y >= 653 && y <= 684) {
        if(inv.checkItem("Pipe") != 0)
            message = Scene1::actionStatement + " Pipe";
    }

 
    //Scene Hover Messages
    if (Scene1::SceneBackground == "1da" && x <= 971 && x >= 843 && y < 231 && y > 142) {
        message = Scene1::actionStatement + " Spaceflix";
    }

    if (Scene1::SceneBackground == "1da" && x <= 411 && x >= 364 && y < 402 && y > 396) {
        message = Scene1::actionStatement + " Pot plant";
    }

    if (Scene1::SceneBackground == "3f" && x <= 510 && x >= 490 && y < 262 && y > 247 && Scene1::secretTrigger == 2 && inv.checkItem("Disc") != 1) {
        message = Scene1::actionStatement + " Sparkling object";
    }
    if (Scene1::SceneBackground == "3f" && x <= 560 && x >=483 && y < 262 && y > 202 && Scene1::secretTrigger <2) {
        message = Scene1::actionStatement + " Loose rocks";
    }

    if (Scene1::SceneBackground == "3f" && x <= 20 && y < 414 && y > 250 ) {
        message = Scene1::actionStatement + " Leave crator";
    }

    if (Scene1::SceneBackground == "3a" && x >= 878 && x <= 919 && y < 148 && y > 121 && Scene1::secretTrigger > 0) {
        message = Scene1::actionStatement + " Point of interest";
    }

    if (Scene1::SceneBackground == "3e" && x >= 183 && x <= 236 && y < 429 && y > 382) {
        message = Scene1::actionStatement + " Big X";
    }

    if (Scene1::SceneBackground == "3e" && x >= 753 && x <= 904 && y < 341 && y > 230) {
        message = Scene1::actionStatement + " Location of interest";
    }

    if (Scene1::SceneBackground == "3e" && x >= 548 && x <= 716 && y < 306 && y > 213) {
        message = Scene1::actionStatement + " Odd formation";
    }

    if (Scene1::SceneBackground == "3d" && x >= 561 && x <=627 && y < 512 && y > 496) {
        message = Scene1::actionStatement + " Marks in dirt";
    }

    if (Scene1::SceneBackground == "3b" && x >= 860 && y < 500 && y > 400) {
        message = "Leave Rocky Cliff";
    }
    if (Scene1::SceneBackground == "3d" && x <= 37 && y >= 376 && y <= 432) {
        message = "Exit Cave";
    }

    if (Scene1::SceneBackground == "3c" && x <= 37 && y >= 376 && y <= 432) {
        message = "Exit Cave";
    }

    if (Scene1::SceneBackground == "3d" && x <= 37 && y >= 376 && y <= 432) {
        message = "Exit Cave";
    }
    if (Scene1::SceneBackground == "3d" && x >= 557 && x <= 618 && y >= 404 && y <= 476) {
        message = Scene1::actionStatement + " Human remains";
    }
    if (Scene1::SceneBackground == "3d" && x >= 431 && x <= 527 && y >= 102 && y <= 125) {
        message = Scene1::actionStatement + " Flying saucer drawing";
    }
    if (Scene1::SceneBackground == "3d" && x >= 579 && x <= 619 && y >= 96 && y <= 133) {
        message = Scene1::actionStatement + " Planet drawing";
    }
    if (Scene1::SceneBackground == "3d" && x >= 677 && x <= 738 && y >= 78 && y <= 192) {
        message = Scene1::actionStatement + " Large Alien drawing";
    }
    if (Scene1::SceneBackground == "3d" && x >= 768 && x <= 810 && y >= 154 && y <= 212) {
        message = Scene1::actionStatement + " Human drawing";
    }
    if (Scene1::SceneBackground == "3d" && x >= 722 && x <= 942 && y >= 25 && y <= 83) {
        message = Scene1::actionStatement + " Alien solar system drawing";
    }
    if (Scene1::SceneBackground == "3d" && x >= 788 && x <= 820 && y >= 258 && y <= 285) {
        message = Scene1::actionStatement + " Artifact drawing";
    }
    if (Scene1::SceneBackground == "3d" && x >= 837 && x <= 910 && y >= 179 && y <= 254) {
        message = Scene1::actionStatement + " Cave door drawing";
    }


    if (Scene1::SceneBackground == "3c" && x >= 107 && x <= 201 && y >= 400 && y <= 473) {
        message = Scene1::actionStatement + " Smooth surface";
    }

    if (Scene1::SceneBackground == "1da" && x >= 421 && x < 437 && y >= 373 && y <= 410 && inv.checkItem("Battery Lantern") != 1) {
        message = Scene1::actionStatement + " Battery Lantern";
    }

    if (Scene1::SceneBackground == "1da" && x >= 554 && x < 591 && y >= 515 && y <= 572 && inv.checkItem("Pipe") != 1 && boxOpened ==1) {
        message = Scene1::actionStatement + " Plastic Pipe";
    }

    if (Scene1::SceneBackground == "3b" && x >= 756 && x < 830 && y >= 28 && y <= 92) {
        message = "Enter cave";
    }

    if (Scene1::SceneBackground == "3a" && x <= 268 && y >= 347) {
        message = "Rock face";
    }

    if (Scene1::SceneBackground == "3a" && x >= 952 && x < 968 && y >= 353 && y <= 369) {
        message = "Camp";
    }
    
    if (Scene1::SceneBackground == "3a" && x >= 433 && x < 463 && y >= 158 && y <= 174) {
        message = Scene1::actionStatement + " Crash site";
    }


    if (Scene1::SceneBackground == "1fb" && x >= 1000 && y >= 390 && y <= 586) {
        message = "Head East";
    }

    if (Scene1::SceneBackground == "1da" && x >= 0 && x <= 100 && y >= 390 && y <= 586) {
        message = "Leave camp";
    }

    if (Scene1::SceneBackground == "1da" && x >= 613 && x <= 640 && y >= 335 && y <= 378) {
        message = Scene1::actionStatement + " Stuffed toy";
    }

    if (Scene1::SceneBackground == "1da" && x >= 523 && x <= 616 && y >= 502 && y <= 586 && boxOpened !=1) {
        message = Scene1::actionStatement + " Cardboard box";
    }

    if (Scene1::SceneBackground == "1da" && x >= 850 && x <= 958 && y >= 391 && y <= 482) {
        message = Scene1::actionStatement + " Oxygenator 5000";
    }

    if (Scene1::SceneBackground == "1db" && x >= 0 && x <= 800 && y >= 459 && y <= 570) {
        message = "Leave Sofa";
    }

    if (Scene1::SceneBackground == "1da" && x >= 245 && x <= 295 && y >= 353 && y <= 414) {
        message = "Sofa";
    }

    if (Scene1::SceneBackground == "1f" && x >= 370 && x <= 916 && y >= 220 && y <= 283) {
        message = Scene1::actionStatement + " Sandy clearing";
    }

    if (Scene1::SceneBackground == "1fb" && x >= 581 && x <= 860 && y >= 117 && y <= 248) {
        message = "Enter Tent";
    }

    if (Scene1::SceneBackground == "1f" && x >= 0 && x <= 6 && y >= 139 && y <= 582) {
        message = "Go west";
    }

    if (Scene1::SceneBackground == "1e" && x >= 9 && x <= 51 && y >= 311 && y <= 482) {
        message = "Go back to wreckage";
    }

    if (Scene1::SceneBackground == "1e" && x >= 661 && x <= 742 && y >= 365 && y <= 409) {
        message = Scene1::actionStatement + " Rocks";
        
    }

    if (Scene1::SceneBackground == "1e" && x >= 994  && y >= 0 && y <= 570) {
        message = "Head east";        
    }

    if (Scene1::SceneBackground == "1" && x >= 52 && x <= 148 && y >= 14 && y <= 111) {
        message = Scene1::actionStatement + " The moon";
        
    }

    if (Scene1::SceneBackground == "1" && x >= 759 && x <= 771 && y >= 325 && y <= 375) {
        message = "Enter Wreckage";
        Scene1::SceneTransitionStatement = "Wreckage";
        
    }

    if (Scene1::SceneBackground == "1" && x >= 560 && x <= 612 && y >= 288 && y <= 350) {
        message = Scene1::actionStatement + " Wreckage";
           
    }

    if (Scene1::SceneBackground == "1" && x >= 609 && x <= 719 && y >= 515 && y <= 542 && inv.checkItem("PDA") != 1) {
        message = Scene1::actionStatement + " White plastic thingy";             
    }


    if (Scene1::SceneBackground == "1b" && x >= 696 && x <= 763 && y >= 324 && y <= 525 && inv.checkItem("Flag") != 1) {
        message = Scene1::actionStatement + " Flag";
    }

    if (Scene1::SceneBackground == "1b" && x >= 538 && x <= 580 && y >= 313 && y <= 441 && inv.checkItem("Tent") != 1) {
        message = Scene1::actionStatement +  " Self Inflating Tent";
    }



    if (Scene1::SceneBackground == "1" && x > 0 && x <= 552 && y > 204 && y < 235 && gy <360 ) {
        message = "Head North";
    }

    if (Scene1::SceneBackground == "1b" && x > 0 && x <= 771 && y >= 560 && y <= 595) {
        message = "Exit Wreckage";
        Scene1::SceneTransitionStatement = "Exit Wreckage";
    }

    if (Scene1::SceneBackground == "1b" && x > 126 && x <= 238 && y >= 306 && y <= 391) {
        message = "Computer Screen";
    }

    if (Scene1::SceneBackground == "1b" && x > 323 && x <= 360 && y >= 433 && y <= 474 && inv.checkItem("Tape") != 1 && Inventory::inv.find("3") == std::string::npos){
        message = Scene1::actionStatement + " Ape Tape";
    }
   
    if (Scene1::SceneBackground == "3a" && x > 662 && x <= 812 && y <= 71){
        message = Scene1::actionStatement + " Crators";
    }


    return message;
}

/* Make objects disappear when picked up. */
std::string PlayerObjects::DestroyObjects(std::string gameObject) {

    std::string objectToDestroy;

    if (gameObject == "PDA") {
        SDL_DestroyTexture(Textures::objectTexture);
        objectToDestroy = "1";
    }

    if (gameObject == "Tape") {
        SDL_DestroyTexture(Textures::objectTexture4);
        objectToDestroy = "3";
    }

    if (gameObject == "Flag") {
        SDL_DestroyTexture(Textures::objectTexture2);
        objectToDestroy = "2";
    }

    if (gameObject == "Tent") {
        SDL_DestroyTexture(Textures::objectTexture5);
        objectToDestroy = "4";
    }

    if (gameObject == "Pipe") {
       
        objectToDestroy = "5";
    }

    if (gameObject == "Battery Lantern") {

        objectToDestroy = "6";
    }
    if (gameObject == "Disc") {
        objectToDestroy = "7";
    }


    return objectToDestroy;
}

/*
ObjectInteraction

Here is where the interaction with objects and scenes takes place. This is where the player is placed in correct place when transitioning scenes and also the interaction when using objects.

*/
std::string PlayerObjects::ObjectInteraction(int x, int y, int playerCurrentLocationX, int playerCurrentLocationY) {
   
    //Check database if item has been picked up.
    Inventory inv;
    Sound s;

    std::string message;

    //Menu Hover buttons //////////////////////////////////////////////////////////////////
    if (Scene1::SceneBackground == "0" && x >= 159 && x <= 376 && y >= 480 && y <= 546) {
        Scene1::SceneBackground = "1";
        Scene1::SPRITE_SIZE = 128;
        Scene1::yPosition = 400;
        Scene1::xPosition = 65;
        SetSpritePosition(Scene1::xPosition, Scene1::yPosition);
        Scene1::sceneHalt = 1;
        Scene1::newGame = true;      
        s.loadSounds(sceneBackground);
    }

    if (Scene1::SceneBackground == "0" && x >= 163 && x <= 376 && y >= 378 && y <= 438) {
      
        SetSpritePosition(Scene1::xPosition, Scene1::yPosition);
        Scene1::sceneHalt = 1;
        Scene1::newGame = false;
        Scene1::continueGame = true;
        s.loadSounds(sceneBackground);
    }
    if (Scene1::SceneBackground == "0" && x >= 163 && x <= 376 && y >= 573 && y <= 644) {
        Scene1::SceneBackground = "01";
        //Scene1::inGame = 1;
        Scene1::SPRITE_SIZE = 50;
        Scene1::yPosition = 400;
        Scene1::xPosition = 65;
        SetSpritePosition(Scene1::xPosition, Scene1::yPosition);
        Scene1::sceneHalt = 1;
        s.loadSounds(sceneBackground);

    }
    // + Speed of player (Needs attention)
    if (Scene1::SceneBackground == "01" && x >= 620 && x <= 691 && y >= 148 && y <= 179 ) {
        if (PlayerMovement::vspeed < 5 && PlayerMovement::hspeed < 5) {
            PlayerMovement::vspeed = PlayerMovement::vspeed + 0.01;
            PlayerMovement::hspeed = PlayerMovement::hspeed + 0.01;
            std::cout << "Vspeed = " << PlayerMovement::vspeed << std::endl;
            std::cout << "hspeed = " << PlayerMovement::hspeed << std::endl;
            inv.gameSpeedSave();
            s.loadSounds(sceneBackground);
        }
    
    }

    // - Speed of player  (Needs attention)
    if (Scene1::SceneBackground == "01" && x >= 282 && x <= 353 && y >= 148 && y <= 179 ) {
        if (PlayerMovement::vspeed > 1 && PlayerMovement::hspeed > 1) {
            PlayerMovement::vspeed = PlayerMovement::vspeed - 0.01;
            PlayerMovement::hspeed = PlayerMovement::hspeed - 0.01;
            std::cout << "Vspeed = " << PlayerMovement::vspeed << std::endl;
            std::cout << "hspeed = " << PlayerMovement::hspeed << std::endl;
            inv.gameSpeedSave();
            s.loadSounds(sceneBackground);
        }
      

    }

    /////////////////////////////////////////////////////////////////////////////////////////


    if (Scene1::SceneBackground == "3f" && playerCurrentLocationX <= 34 ) {
        Scene1::SceneBackground = "3a";
        Scene1::SPRITE_SIZE = 10;
        Scene1::yPosition = 120;
        Scene1::xPosition = 860;
        SetSpritePosition(Scene1::xPosition, Scene1::yPosition);
        Scene1::sceneHalt = 1;
        Scene1::SceneTransitionStatement = "";
        s.loadSounds(sceneBackground);
        //Bug here! Sometimes you transition to scene 3b.. bit odd.
    }

    if (Scene1::SceneBackground == "3a" && playerCurrentLocationX >= 862 && playerCurrentLocationX <=918 && playerCurrentLocationY < 159 && playerCurrentLocationY > 107 && Scene1::secretTrigger > 0) {
        Scene1::SceneBackground = "3f";
        Scene1::SPRITE_SIZE = 50;
        Scene1::yPosition = 400;
        Scene1::xPosition = 65;
        SetSpritePosition(Scene1::xPosition, Scene1::yPosition);
        Scene1::sceneHalt = 1;
        Scene1::SceneTransitionStatement = "";
        s.loadSounds(sceneBackground);
    }

   

    if (Scene1::SceneBackground == "3e" && x >= 866 && x <=987 && y >= 536 && y <=575) {
        Scene1::SceneBackground = "3d";
        Scene1::SPRITE_SIZE = 128;
        Scene1::yPosition = 400;
        Scene1::xPosition = 65;
        SetSpritePosition(Scene1::xPosition, Scene1::yPosition);
        Scene1::sceneHalt = 1;
        Scene1::SceneTransitionStatement = "";
        s.loadSounds(sceneBackground);
    }

    if (Scene1::SceneBackground == "3b" && playerCurrentLocationX >= 900 && playerCurrentLocationY < 500 && playerCurrentLocationY > 400) {
        Scene1::SceneBackground = "3a";
        Scene1::SPRITE_SIZE = 10;
        Scene1::yPosition = 400;
        Scene1::xPosition = 300;
        SetSpritePosition(Scene1::xPosition, Scene1::yPosition);
        Scene1::sceneHalt = 1;
        Scene1::SceneTransitionStatement = "";
        s.loadSounds(sceneBackground);

    }


    if (Scene1::SceneBackground == "3b" && playerCurrentLocationX >= 750 && playerCurrentLocationY <= 120 && Inventory::inv.find("7") != std::string::npos) {
        Scene1::SceneBackground = "3d";
        Scene1::SPRITE_SIZE = 120;
        Scene1::yPosition = 400;
        Scene1::xPosition = 65;
        SetSpritePosition(Scene1::xPosition, Scene1::yPosition);
        Scene1::sceneHalt = 1;
        Scene1::SceneTransitionStatement = "";
        s.loadSounds(sceneBackground);
         
    }


    if (Scene1::SceneBackground == "3d" && playerCurrentLocationX < 37 && playerCurrentLocationY >346) {
        Scene1::SceneBackground = "3b";
        Scene1::SPRITE_SIZE = 50;
        Scene1::xPosition = 945;
        Scene1::yPosition = 387;
        SetSpritePosition(Scene1::xPosition, Scene1::yPosition);
        Scene1::sceneHalt = 1;
        Scene1::SceneTransitionStatement = "";
        s.loadSounds(sceneBackground);
    }

    if (Scene1::SceneBackground == "3c" && playerCurrentLocationX <37 && playerCurrentLocationY >346) {
        Scene1::SceneBackground = "3b";
        Scene1::SPRITE_SIZE = 50;
        Scene1::xPosition = 945;
        Scene1::yPosition = 387;
        SetSpritePosition(Scene1::xPosition, Scene1::yPosition);
        Scene1::sceneHalt = 1;
        Scene1::SceneTransitionStatement = "";
        s.loadSounds(sceneBackground);
    }

    if (Scene1::SceneBackground == "3a" && playerCurrentLocationX < 268 && playerCurrentLocationY > 347) {
        Scene1::SceneBackground = "3b";
        Scene1::SPRITE_SIZE = 50;
        Scene1::xPosition = 945;
        Scene1::yPosition = 387;
        SetSpritePosition(Scene1::xPosition, Scene1::yPosition);
        Scene1::sceneHalt = 1;
        Scene1::SceneTransitionStatement = "";
        s.loadSounds(sceneBackground);
      
    }

  
    if (Scene1::SceneBackground == "1da" && x >= 421 && x < 437 && y >= 373 && y <= 410 && playerCurrentLocationX > 300 && playerCurrentLocationX < 411 && playerCurrentLocationY <394) {
        message = "Hyper Lithium Battery Lantern";
    }

    if (Scene1::SceneBackground == "3a" && x >= 952 && x < 968 && y >= 353 && y <= 369 && playerCurrentLocationX > 900) {
        Scene1::SceneBackground = "1fb";
        Scene1::SPRITE_SIZE = 180;
        Scene1::xPosition = 945;
        Scene1::yPosition = 387;
        s.loadSounds(sceneBackground);
    }

    /*Leaving sandy clearing and going to map */
    if (Scene1::SceneBackground == "1fb" && x >= 994 && y >= 0 && y <= 570 &&playerCurrentLocationX > 900) {
        Scene1::SceneBackground = "3a";
        Scene1::SPRITE_SIZE = 10;
        Scene1::xPosition = 945;
        Scene1::yPosition = 387;
        s.loadSounds(sceneBackground);
    }
    

    /* Looking inside opened box */
    if (Scene1::SceneBackground == "1da" && x >= 523 && x <= 616 && y >= 502 && y <= 586 && playerCurrentLocationX >= 435 && boxOpened == 1) {

        message = "Ooh an air pressure pipe";
        if (Scene1::useStatement == "Use")
            message = "Might be worth picking it up first.";

    }  
    /* Leave sofa */
    if (Scene1::SceneBackground == "1db" && x >= 0 && x <= 800 && y >= 459 && y <= 570) {     
        Scene1::SceneBackground = "1da";
        Scene1::SPRITE_SIZE = 180;
        Scene1::xPosition = 280;
        Scene1::yPosition = 410;
        s.loadSounds(sceneBackground);
    
    }
    /* Entering tent from sandy clearing */
    if (Scene1::SceneBackground == "1fb" && x >= 581 && x <= 860 && y >= 117 && y <= 248 && playerCurrentLocationX >= 440 && playerCurrentLocationY <=308) {
        Scene1::SceneBackground = "1da";
        Scene1::SPRITE_SIZE = 170;
        Scene1::yPosition = 360;
        Scene1::xPosition = 106;
        SetSpritePosition(Scene1::xPosition, Scene1::yPosition);  
        Scene1::sceneHalt = 1;
        Scene1::SceneTransitionStatement = "";
        PlayerInteraction::playerMessage = 6;
        s.loadSounds(sceneBackground);
      
    }

    if (Scene1::SceneBackground == "3b" && playerCurrentLocationX >=750 && playerCurrentLocationY <=120) {
        Scene1::SceneBackground = "3c";
        Scene1::SPRITE_SIZE = 170;
        Scene1::yPosition = 360;
        Scene1::xPosition = 206;
        SetSpritePosition(Scene1::xPosition, Scene1::yPosition);
        Scene1::sceneHalt = 1;
        Scene1::SceneTransitionStatement = "";
        PlayerInteraction::playerMessage = 11;
        s.loadSounds(sceneBackground);
    }



    /* Inside Tent */
    if (Scene1::SceneBackground == "1da" && x >= 0 && x <100 && y >= 390  && playerCurrentLocationX <= 10 && playerCurrentLocationY >= 308) {     
        if (Inventory::inv.find("5") == std::string::npos) {
            message = "My suit hasn't got enough oxygen";
        }
        else {
            Scene1::SceneBackground = "1fb";
            Scene1::SPRITE_SIZE = 120;
            Scene1::yPosition = 390;
            Scene1::xPosition = 106;
            s.loadSounds(sceneBackground);
            SetSpritePosition(Scene1::xPosition, Scene1::yPosition);
        }
       
       
    }
    /* Outside tent */
    if (Scene1::SceneBackground == "1fa" && x >= 793 && x <= 959 && y >= 474 && y <= 535) {
        Textures tex;
        Scene1::SceneBackground = "1fb";
        Scene1::SPRITE_SIZE = 120;
        //Prevents Textures being loaded more than once.
        if (Scene1::tLoader == 1) {
            tex.Scene3Textures();
            Scene1::tLoader = 2;
        }
        Scene1::yPosition = 376;
        Scene1::xPosition = 106;
        SetSpritePosition(Scene1::xPosition, Scene1::yPosition);
        Scene1::sceneHalt = 1;
        PlayerInteraction::playerMessage = 7;
        s.loadSounds(sceneBackground);
       
    }
    /* Outside wreckage */
    if (Scene1::SceneBackground == "1" && playerCurrentLocationX >=665 && playerCurrentLocationX < 771 && playerCurrentLocationY <=365 && Scene1::SceneTransitionStatement == "Wreckage" ) {
        std::cout << "Entering Wreckage" << std::endl;
        Scene1::SceneBackground = "1b";
        Scene1::SPRITE_SIZE = 160;
        Scene1::xPosition = 400;
        Scene1::yPosition = 400;
        SetSpritePosition(Scene1::xPosition, Scene1::yPosition);
        Scene1::sceneHalt = 1;
        Scene1::SceneTransitionStatement = "";
        Scene1::mouseClick = false;     
        s.loadSounds(sceneBackground);
    }
    /* Sandy clearing */
    if (Scene1::SceneBackground == "1f" && x >= 0 && x <= 6 && y >= 139 && y <= 582 && playerCurrentLocationX <6) {
        std::cout << "Going West" << std::endl;
        Scene1::SceneBackground = "1e";
        Scene1::SPRITE_SIZE = 50;
        Scene1::yPosition = 380;
        Scene1::xPosition = 350;
        SetSpritePosition(Scene1::xPosition, Scene1::yPosition);
        s.loadSounds(sceneBackground);
    }
    /* Inside wreakage */
    if (Scene1::SceneBackground == "1b" && Scene1::SceneTransitionStatement == "Exit Wreckage") {
        Scene1::sceneHalt = 1;
        Scene1::SceneTransitionStatement = "";
        Scene1::SceneBackground = "1";
        Scene1::SPRITE_SIZE = 110;
        s.loadSounds(sceneBackground);
    }

    /* Looking at computer screen */
    if (Scene1::SceneBackground == "1b" && x > 126 && x <= 238 && y >= 306 && y <= 391 &&playerCurrentLocationX < 300) {      
        Scene1::SceneBackground = "1c";
    }
    /* Looking at computer screen */
    if (Scene1::SceneBackground == "1d" && x > 126 && x <= 238 && y >= 306 && y <= 391) {
        Scene1::SceneBackground = "1c";
    }
    /* Looking at computer screen */
    if (Scene1::SceneBackground == "1c" && x > 345 && x <= 488 && y >= 541 && y <= 585) {
        Scene1::SceneBackground = "1d";
    }
    /* Leave computer screen, inside wreakage */
    if (Scene1::SceneBackground == "1c"  && x > 36 && x <= 172 && y >= 544 && y <= 582) {
        Scene1::SceneBackground = "1b";
        Scene1::SPRITE_SIZE = 160;
        Scene1::xPosition = 400;
        Scene1::yPosition = 400;
        SetSpritePosition(Scene1::xPosition, Scene1::yPosition);
        Scene1::sceneHalt = 1;     
        s.loadSounds(sceneBackground);
    }
    /* Leave computer screen, inside wreakage */
    if (Scene1::SceneBackground == "1d" && x > 36 && x <= 172 && y >= 544 && y <= 582) {
        Scene1::SceneBackground = "1b";
        Scene1::SPRITE_SIZE = 160;
        Scene1::xPosition = 400;
        Scene1::yPosition = 400;
        SetSpritePosition(Scene1::xPosition, Scene1::yPosition);
        Scene1::sceneHalt = 1;
        s.loadSounds(sceneBackground);
    }
 
    /* Leaving rocky path and going back to wreakage */
    if (Scene1::SceneBackground == "1e" && x >= 9 && x <= 51 && y >= 311 && y <= 482 && playerCurrentLocationX <=13) {
        Scene1::SceneBackground = "1";
        Scene1::SPRITE_SIZE = 120;
        Scene1::yPosition = 10;      
    }

    /* Entering sandy clearing from rocky path, load scene 2 textures */
    if (Scene1::SceneBackground == "1e" && x >= 994 && y >= 0 && y <= 570 && playerCurrentLocationX >=994) {
        Textures tex;
        Scene1::SPRITE_SIZE = 120;
        Scene1::SceneBackground = "1f";
        //Load in the new textures for scene2
        if (Scene1::tLoader == 0) {
            tex.Scene2Textures();
            Scene1::tLoader = 1;
        }

        Scene1::xPosition = 10;
        SetSpritePosition(Scene1::xPosition, Scene1::yPosition);
        Scene1::sceneHalt = 1;
        s.loadSounds(sceneBackground);
    }


    //Check if PDA is picked up and Oxygen is fixed.
    /* Leave wreakage scene and head to rocky path */
    if (Scene1::SceneBackground == "1" && x > 0 && x <= 771 && y > 204 && y < 259 && playerCurrentLocationY <360 ) {
        
        if (Inventory::inv.find("3") == std::string::npos) {
            Scene1::sceneHalt = 1;
            PlayerInteraction::playerMessage = 8;
        }
        else if (inv.checkItem("Tent") != 1) {
            Scene1::sceneHalt = 1;
            PlayerInteraction::playerMessage = 9;
        }
        else if (inv.checkItem("PDA") != 1) {
            Scene1::sceneHalt = 1;
            PlayerInteraction::playerMessage = 10;
        }
        else {          
            Scene1::SceneBackground = "1e";
            Scene1::SPRITE_SIZE = 50;
            Scene1::yPosition = 376;
            Scene1::xPosition = 106;
            SetSpritePosition(Scene1::xPosition, Scene1::yPosition);
            Scene1::sceneHalt = 1;
            PlayerInteraction::playerMessage = 5;
            s.loadSounds(sceneBackground);
        }       
           
    }

    return message;
}


//This is used for menu object interaction (Picking up).
std::string PlayerObjects::ObjectInteractionM1(int playerCurrentLocationX, int playerCurrentLocationY) {

    std::string message;

    if (Scene1::SceneBackground == "1" && playerCurrentLocationX >= 609 && playerCurrentLocationX <= 719) {
        message = "PDA";
    }

    if (Scene1::SceneBackground == "1b" && playerCurrentLocationX >= 503 && playerCurrentLocationX <= 719) {
        message = "Flag";
    }
    if (Scene1::SceneBackground == "1b" && playerCurrentLocationX >= 310 && playerCurrentLocationX <= 394) {
        message = "Tape";
    }

    if (Scene1::SceneBackground == "1b" && playerCurrentLocationX >= 406 && playerCurrentLocationX <= 500) {
        message = "Tent";
    }

    if (Scene1::SceneBackground == "1da" && playerCurrentLocationX >= 437 && playerCurrentLocationX <= 530) {
        message = "Pipe";
    }

    if (Scene1::SceneBackground == "1da" && playerCurrentLocationX >= 300 && playerCurrentLocationX <= 411) {
        message = "Battery Lantern";
    }
    if (Scene1::SceneBackground == "3f" && playerCurrentLocationX >= 300 && playerCurrentLocationX <= 511) {
        message = "Disc";
    }

    return message;
}


/*Here is where you set the size of the object and you set the speed of the sprite scroller (to achieve animation effect it scrolls from the LEFT to the RIGHT)

*/
std::tuple<int, int, int, int, int> PlayerObjects::ObjectSettings(int scene, int objectID, int b, int c, int d) {

    if (scene == 1 && objectID == 1) {
        //PDA
        //Put "actual" image size here (NULL, Speed of Animation, NULL, Width, Height) Make sure that use use the real dimensiosn of the image eg: image.jpg is 200x300
        return  std::make_tuple(NULL, NULL, NULL, 40, 40);
    }

    if (scene == 1 && objectID == 2) {
        //Flag Rolled up
        return  std::make_tuple(NULL, NULL, NULL, 80, 218);
    }

    if (scene == 1 && objectID == 3) {
        //Stars
        return  std::make_tuple(NULL, 15, NULL, 183, 347); //You can see here that I set the scroll speed to 15 because the star is animated. This will scroll the RECT at a speed of 15 from left to right.
    }

    if (scene == 1 && objectID == 4) {
        //Tape
        return  std::make_tuple(NULL, NULL, NULL, 100, 100);
    }

    if (scene == 1 && objectID == 5) {
        //Tent
        return  std::make_tuple(NULL, NULL, NULL, 100, 149);
    }
    if (scene == 1 && objectID == 6) {
        //Tent
        return  std::make_tuple(NULL, NULL, NULL, 100, 149);
    }
    if (scene == 1 && objectID == 7) {
        //Tent
        return  std::make_tuple(NULL, NULL, NULL, 186, 138);
    }
    if (scene == 1 && objectID == 8) {
        //Tent
        return  std::make_tuple(NULL, NULL, NULL, 30, 81);
    }
    if (scene == 1 && objectID == 9) {
        //Tent
        return  std::make_tuple(NULL, 5, NULL, 20, 41);
    }


    return  std::make_tuple(scene, objectID, b, c, d);
}

/* 
Here is where you actually specify where you want to place the object and how big you want that object to be.
The returned values are: (Number of sprites in the iamge, x position of the object, y postion of the object, desired width of the object, desired height of the object)
If you set number of sprites to 1, that means its not animated. If you increase the number of sprites value it will assume there are multiple sprites in the image.

*/
std::tuple<int, int, int, int, int> PlayerObjects::placeObject(int scene, int objectID, int b, int c, int d) {

    if (scene == 1 && objectID == 1) {
        //PDA
       // Object position and size of object (x,y,width,height)
        return  std::make_tuple(3, 685, 523, 20, 14);
    }
    if (scene == 1 && objectID == 2) {
        //Flag Rolled up
        // Object position and size of object (number of sprites,x,y, DESIRED DISPLAY WIDTH, DESIRED DISPLAY HEIGHT)
        return  std::make_tuple(1, 685, 323, 80, 218);
    }
    if (scene == 1 && objectID == 3) {
        // Object position and size of object (number of sprites,x,y, DESIRED DISPLAY WIDTH, DESIRED DISPLAY HEIGHT)
        return  std::make_tuple(3, 400, 30, 8, 40);
    }
    if (scene == 1 && objectID == 4) {
        // Object position and size of object (number of sprites,x,y, DESIRED DISPLAY WIDTH, DESIRED DISPLAY HEIGHT)
        return  std::make_tuple(1, 300, 430, 60, 60);
    }
    if (scene == 1 && objectID == 5) {     
        // Object position and size of object (number of sprites,x,y, DESIRED DISPLAY WIDTH, DESIRED DISPLAY HEIGHT)
        return  std::make_tuple(1, 520, 300, 97, 149);
    }
    if (scene == 1 && objectID == 6) {
        //Closed Box
        // Object position and size of object (number of sprites,x,y, DESIRED DISPLAY WIDTH, DESIRED DISPLAY HEIGHT)
        return  std::make_tuple(1, 520, 500, 100, 96);
    }
    if (scene == 1 && objectID == 7) {
        //Air Box
        // Object position and size of object (number of sprites,x,y, DESIRED DISPLAY WIDTH, DESIRED DISPLAY HEIGHT)
        return  std::make_tuple(1, 838, 380, 140, 118);
    }
    if (scene == 1 && objectID == 8) {
        //Lantern
        // Object position and size of object (number of sprites,x,y, DESIRED DISPLAY WIDTH, DESIRED DISPLAY HEIGHT)
        return  std::make_tuple(1, 419, 372, 20, 41);  //HERE IS WHERE YOU SET DIMENSIONS AND POSITION OF THE OBJECT.
    }
    if (scene == 1 && objectID == 9) {
        //Sparkly object
        // Object position and size of object (number of sprites,x,y, DESIRED DISPLAY WIDTH, DESIRED DISPLAY HEIGHT)
        return  std::make_tuple(3, 499, 252, 8, 8);  //HERE IS WHERE YOU SET DIMENSIONS AND POSITION OF THE OBJECT.
    }


    return  std::make_tuple(scene, objectID, b, c, d);
}

void PlayerObjects::ObjectController() {

    Uint32 ticks = SDL_GetTicks();
    PlayerObjects pob;
    /*Scene Objects
    Below you can add all the objects you want in your game. srcect is the image window and dstrect is the scroller window that is used to animate objects when needed.
    This does look quite complicated but once you get the hang of it, it's not too hard to add objects and you can just copy and paste each object but change the ID each time.
        
    */
    //Add Scene Objects.
     //Scene Object variables.
    int sceneobject = 1, objectP1, objectP2, objectHeight, objectWidth, numberSprites;
    int objectP3, objectP4, objectP5, objectP6;

    //Scene Object 1 (PDA) /////////////////////////////////////////////////////////////////////////////////////////////////
                                                                                              //1 means object 1
    std::tie(numberSprites, objectP1, objectP2, objectHeight, objectWidth) = pob.ObjectSettings(1, 1, NULL, NULL, NULL);
    std::tie(numberSprites, objectP3, objectP4, objectP5, objectP6) = pob.placeObject(1, 1, NULL, NULL, NULL);

    int object1 = (ticks / 100) % numberSprites; //1 means its not going to move (animate).
    //Set objectSprite Parameters size, height, width, position etc.
    PlayerObjects::srcrect = { object1 * objectP1, objectP2, objectHeight, objectWidth };
    PlayerObjects::dstrect = { objectP3, objectP4, objectP5, objectP6 };

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    //Scene Object 2
    //Build object parameters.                                                                //2 means object 2  and so on...
    std::tie(numberSprites, objectP1, objectP2, objectHeight, objectWidth) = pob.ObjectSettings(1, 2, NULL, NULL, NULL);
    std::tie(numberSprites, objectP3, objectP4, objectP5, objectP6) = pob.placeObject(1, 2, NULL, NULL, NULL);

    int object2 = (ticks / 100) % numberSprites;
    //Set objectSprite Parameters size, height, width, position etc.
    PlayerObjects::srcrect2 = { object2 * objectP1, objectP2, objectHeight, objectWidth };
    PlayerObjects::dstrect2 = { objectP3, objectP4, objectP5, objectP6 };

    //Scene Object 3 (Flashing lights)
    std::tie(numberSprites, objectP1, objectP2, objectHeight, objectWidth) = pob.ObjectSettings(1, 3, NULL, NULL, NULL);
    std::tie(numberSprites, objectP3, objectP4, objectP5, objectP6) = pob.placeObject(1, 3, NULL, NULL, NULL);

    //% numberSprites is set to the value specified in PlaceObjectA. Here it is set to 3.
    int object3 = (ticks / 100) % numberSprites;
    //Set objectSprite Parameters size, height, width, position etc.
    PlayerObjects::srcrect3 = { object3 * objectP1, objectP2, objectHeight, objectWidth };
    PlayerObjects::dstrect3 = { objectP3, objectP4, objectP5, objectP6 };

    //Scene Object 4.......
    std::tie(numberSprites, objectP1, objectP2, objectHeight, objectWidth) = pob.ObjectSettings(1, 4, NULL, NULL, NULL);
    std::tie(numberSprites, objectP3, objectP4, objectP5, objectP6) = pob.placeObject(1, 4, NULL, NULL, NULL);

    //Set it to 1 for no animation.
    int object4 = (ticks / 100) % numberSprites;
    //Set objectSprite Parameters size, height, width, position etc.
    PlayerObjects::srcrect4 = { object3 * objectP1, objectP2, objectHeight, objectWidth };
    PlayerObjects::dstrect4 = { objectP3, objectP4, objectP5, objectP6 };

    //Scene Object 5.......
    std::tie(numberSprites, objectP1, objectP2, objectHeight, objectWidth) = pob.ObjectSettings(1, 5, NULL, NULL, NULL);
    std::tie(numberSprites, objectP3, objectP4, objectP5, objectP6) = pob.placeObject(1, 5, NULL, NULL, NULL);

    int object5 = (ticks / 100) % numberSprites;
    //Set objectSprite Parameters size, height, width, position etc.
    PlayerObjects::srcrect5 = { object3 * objectP1, objectP2, objectHeight, objectWidth };
    PlayerObjects::dstrect5 = { objectP3, objectP4, objectP5, objectP6 };

    //Scene Object 6.......
    std::tie(numberSprites, objectP1, objectP2, objectHeight, objectWidth) = pob.ObjectSettings(1, 6, NULL, NULL, NULL);
    std::tie(numberSprites, objectP3, objectP4, objectP5, objectP6) = pob.placeObject(1, 6, NULL, NULL, NULL);

    int object6 = (ticks / 100) % numberSprites;
    //Set objectSprite Parameters size, height, width, position etc.
    PlayerObjects::srcrect6 = { object3 * objectP1, objectP2, objectHeight, objectWidth };
    PlayerObjects::dstrect6 = { objectP3, objectP4, objectP5, objectP6 };

    //Scene Object 7 Air Box
    std::tie(numberSprites, objectP1, objectP2, objectHeight, objectWidth) = pob.ObjectSettings(1, 7, NULL, NULL, NULL);
    std::tie(numberSprites, objectP3, objectP4, objectP5, objectP6) = pob.placeObject(1, 7, NULL, NULL, NULL);

    int object7 = (ticks / 100) % numberSprites;
    //Set objectSprite Parameters size, height, width, position etc.
    PlayerObjects::srcrect7 = { object3 * objectP1, objectP2, objectHeight, objectWidth };
    PlayerObjects::dstrect7 = { objectP3, objectP4, objectP5, objectP6 };

    //Scene Object 8 Lantern
    std::tie(numberSprites, objectP1, objectP2, objectHeight, objectWidth) = pob.ObjectSettings(1, 8, NULL, NULL, NULL);
    std::tie(numberSprites, objectP3, objectP4, objectP5, objectP6) = pob.placeObject(1, 8, NULL, NULL, NULL);

    int object8 = (ticks / 100) % numberSprites;
    //Set objectSprite Parameters size, height, width, position etc.
    PlayerObjects::srcrect8 = { object3 * objectP1, objectP2, objectHeight, objectWidth };
    PlayerObjects::dstrect8 = { objectP3, objectP4, objectP5, objectP6 };

    //Scene Object 9 (Sparkly thing)
    std::tie(numberSprites, objectP1, objectP2, objectHeight, objectWidth) = pob.ObjectSettings(1, 9, NULL, NULL, NULL);
    std::tie(numberSprites, objectP3, objectP4, objectP5, objectP6) = pob.placeObject(1, 9, NULL, NULL, NULL);

    //% numberSprites is set to the value specified in PlaceObjectA. Here it is set to 3.
    int object9 = (ticks / 100) % numberSprites;
    //Set objectSprite Parameters size, height, width, position etc.
    PlayerObjects::srcrect9 = { object9 * objectP1, objectP2, objectHeight, objectWidth };
    PlayerObjects::dstrect9 = { objectP3, objectP4, objectP5, objectP6 };


}



