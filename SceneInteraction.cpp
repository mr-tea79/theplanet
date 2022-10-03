#include <iostream>
#include <string>
#include "sceneInteraction.h"
#include "Inventory.h"
#include "Sound.h"
#include "Scene1.h"
#include "PlayerMovement.h"
#include "Textures.h"
#include "AI.h"
#include "PlayerObjects.h"
#include "PlayerInteraction.h"

using namespace brightland;
using namespace std;

//Global
static std::string sceneBackground;




void SceneInteraction::SetSpritePosition(int x, int y, int s) {

    Scene1::gdSprite.x = x;
    Scene1::gdSprite.y = y;
    Scene1::SPRITE_SIZE = s;
    Scene1::sceneHalt = 1;
    // SDL_WarpMouseInWindow(Scene1::window, 400, 400);

}

std::string SceneInteraction::sceneTransitions(int x, int y, int playerCurrentLocationX, int playerCurrentLocationY) {

    //Check database if item has been picked up.
    Inventory inv;
    Sound s;
    Textures tex;
   

    std::string message;

    //Menu Hover buttons //////////////////////////////////////////////////////////////////
    bool sound = s.checkSoundStatus(Sound::soundOn);

    /// SOUND SWITCHING ON AND OFF /////////////////////////////////////////////////////////////////
    if (sound == true && Scene1::SceneBackground == "0" && x > 27 && x < 77 && y > 28 && y < 77) {
        Scene1::menuSound = 1;
        Scene1::sceneHalt = 1; //Important so it only registers one click!
        Sound::soundOn = false;
        s.loadSounds("X"); 
    }
    if (sound == false && Scene1::SceneBackground == "0" && x > 27 && x < 77 && y > 28 && y < 77) {
        Scene1::menuSound = 1;
        Scene1::sceneHalt = 1; //Important so it only registers one click!
        Sound::soundOn = true;
        s.loadSounds(Scene1::SceneBackground);
       
    }

    if (Scene1::SceneBackground == "0" && x > 17 && x < 47 && y > 704 && y < 742) {
        Scene1::quitGame = true;
    }

    //////////////////////////////////////////////////////////////////////////////

    //Switching between FULL screen //////////////////////////////////////////////////////////////
    if (Scene1::fullScreenTrigger == false && Scene1::SceneBackground == "0" && x > 927 && x < 951 && y > 62 && y < 87) {
        Scene1::sceneHalt = 1; //Important so it only registers one click!
        Scene1::fullScreenTrigger = true;
    }
    else if (Scene1::fullScreenTrigger == true && Scene1::SceneBackground == "0" && x > 927 && x < 951 && y > 62 && y < 87) {
        Scene1::sceneHalt = 1; //Important so it only registers one click!
        Scene1::fullScreenTrigger = false;
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////
  

    if (Scene1::SceneBackground == "0" && x >= 159 && x <= 376 && y >= 480 && y <= 546) {
        Scene1::menuSound = 1;
        Scene1::SceneBackground = "1";
        SetSpritePosition(65,400,128);
        Scene1::newGame = true;
        s.loadSounds(sceneBackground);
    }

    if (Scene1::SceneBackground == "0" && x >= 163 && x <= 376 && y >= 378 && y <= 438) {
        Scene1::menuSound = 1;
        Scene1::newGame = false;
        Scene1::continueGame = true;
        s.loadSounds(sceneBackground);
    }
    if (Scene1::SceneBackground == "0" && x >= 163 && x <= 376 && y >= 573 && y <= 644) {
        Scene1::menuSound = 1;
        Scene1::SceneBackground = "01";
        SetSpritePosition(65,400,50);
        s.loadSounds(sceneBackground);

    }
    // + Speed of player (Needs attention)
    if (Scene1::SceneBackground == "01" && x >= 620 && x <= 691 && y >= 148 && y <= 179) {
        Scene1::menuSound = 1;
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
    if (Scene1::SceneBackground == "01" && x >= 282 && x <= 353 && y >= 148 && y <= 179) {
        Scene1::menuSound = 1;
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

    if (playerCurrentLocationY < 90 && playerCurrentLocationX > 670 && Scene1::secretTrigger == 4 && Scene1::SceneBackground == "3a") {
        Textures tex;
        Scene1::SceneBackground = "4a";
        SetSpritePosition(360,450,120);
        Scene1::SceneTransitionStatement = "";
        s.loadSounds(sceneBackground);
        //Load in the new textures for scene4
        tex.Scene4Textures();

    }


    if (Scene1::SceneBackground == "3f" && playerCurrentLocationX <= 34) {
        Scene1::SceneBackground = "3a";
        SetSpritePosition(860,120,10);
        Scene1::SceneTransitionStatement = "";
        s.loadSounds(sceneBackground);
       
    }

    if (Scene1::SceneBackground == "3a" && playerCurrentLocationX >= 862 && playerCurrentLocationX <= 918 && playerCurrentLocationY < 159 && playerCurrentLocationY > 107 && Scene1::secretTrigger > 0) {
        Scene1::SceneBackground = "3f";
        SetSpritePosition(65,400,50);
        Scene1::SceneTransitionStatement = "";
        s.loadSounds(sceneBackground);
    }



    if (Scene1::SceneBackground == "3e" && x >= 866 && x <= 987 && y >= 536 && y <= 575) {
        Scene1::SceneBackground = "3d";
        SetSpritePosition(645,448,128);
        Scene1::SceneTransitionStatement = "";
        s.loadSounds(sceneBackground);
    }

    if (Scene1::SceneBackground == "3b" && playerCurrentLocationX >= 900 && playerCurrentLocationY < 500 && playerCurrentLocationY > 400) {
        Scene1::SceneBackground = "3a";
        SetSpritePosition(300,400,10);
        Scene1::SceneTransitionStatement = "";
        s.loadSounds(sceneBackground);

    }


    if (Scene1::SceneBackground == "3b" && playerCurrentLocationX >= 750 && playerCurrentLocationY <= 120 && Inventory::inv.find("7") != std::string::npos) {
        Scene1::SceneBackground = "3d";
        SetSpritePosition(65,400,120);
        Scene1::SceneTransitionStatement = "";
        s.loadSounds(sceneBackground);

    }


    if (Scene1::SceneBackground == "3d" && playerCurrentLocationX < 37 && playerCurrentLocationY >346) {
        Scene1::SceneBackground = "3b";
        SetSpritePosition(945,387,50);
        Scene1::SceneTransitionStatement = "";
        s.loadSounds(sceneBackground);
    }

    if (Scene1::SceneBackground == "3c" && playerCurrentLocationX < 37 && playerCurrentLocationY >346) {
        Scene1::SceneBackground = "3b";
        SetSpritePosition(945,387,50);
        Scene1::SceneTransitionStatement = "";
        s.loadSounds(sceneBackground);
    }

    if (Scene1::SceneBackground == "3a" && playerCurrentLocationX < 268 && playerCurrentLocationY > 347) {
        Scene1::SceneBackground = "3b";
        SetSpritePosition(945,387,50);
        Scene1::SceneTransitionStatement = "";
        s.loadSounds(sceneBackground);

    }


    if (Scene1::SceneBackground == "1da" && x >= 421 && x < 437 && y >= 373 && y <= 410 && playerCurrentLocationX > 300 && playerCurrentLocationX < 411 && playerCurrentLocationY < 394) {
        message = "Hyper Lithium Battery Lantern";
    }

    if (Scene1::SceneBackground == "3a" && x >= 952 && x < 968 && y >= 353 && y <= 369 && playerCurrentLocationX > 900) {
        Scene1::SceneBackground = "1fb";
        SetSpritePosition(945,387, 180);
        s.loadSounds(sceneBackground);
    }

    /*Leaving sandy clearing and going to map */
    if (Scene1::SceneBackground == "1fb" && x >= 994 && y >= 0 && y <= 570 && playerCurrentLocationX > 900) {
        Scene1::SceneBackground = "3a";
        SetSpritePosition(945,387, 10);
        s.loadSounds(sceneBackground);
    }


    /* Looking inside opened box */
    if (Scene1::SceneBackground == "1da" && x >= 523 && x <= 616 && y >= 502 && y <= 586 && playerCurrentLocationX >= 435 && PlayerObjects::boxOpened == 1) {

        message = "Ooh an air pressure pipe";
        if (Scene1::useStatement == "Use")
            message = "Might be worth picking it up first.";

    }
    /* Leave sofa */
    if (Scene1::SceneBackground == "1db" && x >= 0 && x <= 800 && y >= 459 && y <= 570) {
        Scene1::SceneBackground = "1da";
        SetSpritePosition(280,410, 180);
        s.loadSounds(sceneBackground);

    }
    /* Entering tent from sandy clearing */
    if (Scene1::SceneBackground == "1fb" && x >= 581 && x <= 860 && y >= 117 && y <= 248 && playerCurrentLocationX >= 440 && playerCurrentLocationY <= 308) {
        Scene1::SceneBackground = "1da";
        SetSpritePosition(106,360,170);
        Scene1::SceneTransitionStatement = "";
        s.loadSounds(sceneBackground);
        AI::aiPlayMessages = true;
        AI::dialogNumber = 16;
        AI::playerTalk = true;

    }

    if (Scene1::SceneBackground == "3b" && playerCurrentLocationX >= 750 && playerCurrentLocationY <= 120) {
        Scene1::SceneBackground = "3c";
        SetSpritePosition(206,360,170);
        Scene1::SceneTransitionStatement = "";
        PlayerInteraction::playerMessage = 11;
        s.loadSounds(sceneBackground);
    }



    /* Inside Tent */
    if (Scene1::SceneBackground == "1da" && x >= 0 && x < 100 && y >= 390 && playerCurrentLocationX <= 10 && playerCurrentLocationY >= 308) {
        if (Inventory::inv.find("5") == std::string::npos) {
            message = "My suit hasn't got enough oxygen";
        }
        else {
            Scene1::SceneBackground = "1fb";
            s.loadSounds(sceneBackground);
            SetSpritePosition(106,390,120);

        }

          
    }
    /* Outside tent */
    if (Scene1::SceneBackground == "1fa" && x >= 793 && x <= 959 && y >= 474 && y <= 535) {
        Textures tex;
        Scene1::SceneBackground = "1fb";
        //Prevents Textures being loaded more than once.
        if (Scene1::tLoader == 1 || Scene1::SceneBackground == "1fb") {
            tex.Scene3Textures();
            Scene1::tLoader = 2;
        }
   
        SetSpritePosition(106,376,120);
        Scene1::SceneTransitionStatement = "";
      //  Scene1::mouseClick = false;
        s.loadSounds(sceneBackground);
        AI::aiPlayMessages = true;

    }
    /* Outside wreckage */
    if (Scene1::SceneBackground == "1" && playerCurrentLocationX >= 665 && playerCurrentLocationX < 771 && playerCurrentLocationY <= 365 && Scene1::SceneTransitionStatement == "Wreckage") {
        std::cout << "Entering Wreckage" << std::endl;
        Scene1::SceneBackground = "1b";
        SetSpritePosition(400,400,160);
        tex.TextureUpdater(Textures::spriteBack1a, "Action");
        Scene1::SceneTransitionStatement = "";
     //   Scene1::mouseClick = false;
        s.loadSounds(sceneBackground);
        AI::aiPlayMessages = true;
        AI::dialogNumber = 5;
        AI::playerTalk = true;
    }
    /* Sandy clearing returning to rocky path */
    if (Scene1::SceneBackground == "1f" && playerCurrentLocationX < 100 && Scene1::SceneTransitionStatement == "West") {
        std::cout << "Going West" << std::endl;
        Scene1::SceneBackground = "1e";
        Scene1::SceneTransitionStatement = "";
        SetSpritePosition(600,380,50);
        s.loadSounds(sceneBackground);
    }
    /* Inside wreakage */
    if (Scene1::SceneBackground == "1b" && Scene1::SceneTransitionStatement == "Exit Wreckage") {
        Scene1::SceneTransitionStatement = "";
        Scene1::SceneBackground = "1";
        SetSpritePosition(Scene1::xPosition, Scene1::yPosition,110);
        s.loadSounds(sceneBackground);

    }

    /* Looking at computer screen */
    if (Scene1::SceneBackground == "1b" && x > 126 && x <= 238 && y >= 306 && y <= 391 && playerCurrentLocationX < 300) {
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
    if (Scene1::SceneBackground == "1c" && x > 36 && x <= 172 && y >= 544 && y <= 582) {
        Scene1::SceneBackground = "1b";
        SetSpritePosition(400,400,160);
        s.loadSounds(sceneBackground);
    }
    /* Leave computer screen, inside wreakage */
    if (Scene1::SceneBackground == "1d" && x > 36 && x <= 172 && y >= 544 && y <= 582) {
        Scene1::SceneBackground = "1b";
        SetSpritePosition(400,400,160);
        s.loadSounds(sceneBackground);
    }

    /* Leaving rocky path and going back to wreakage */
    if (Scene1::SceneBackground == "1e" && playerCurrentLocationX <= 150 && Scene1::SceneTransitionStatement == "Wreckage") {
        Scene1::SceneBackground = "1";
        SetSpritePosition(400,400,120);
        Scene1::SceneTransitionStatement = "";
      
    }

    /* Heading North */
    if (Scene1::SceneBackground == "1" && Scene1::SceneTransitionStatement == "Head North") {
        if (Inventory::inv.find("3") == std::string::npos) {
            tex.TextureUpdater(Textures::spriteDown1, "Action");
            Scene1::sceneHalt = 1;
            AI::aiPlayMessages = true;
            AI::dialogNumber = 3;
            AI::playerTalk = true;
        }

        else if (Scene1::objectToDestroy.find("1") == std::string::npos) {
            tex.TextureUpdater(Textures::spriteDown1, "Action");
            Scene1::sceneHalt = 1;
            AI::aiPlayMessages = true;
            AI::dialogNumber = 2;
            AI::playerTalk = true;
        }
        else {
            Scene1::SceneBackground = "1e";
            SetSpritePosition(10,400,50);
            Scene1::SceneTransitionStatement = "";
     //       Scene1::mouseClick = false;
            s.loadSounds(sceneBackground);
            AI::aiPlayMessages = true;
   
           
        }
        
       
    }
    

    /* Entering sandy clearing from rocky path, load scene 2 textures */
    if (Scene1::SceneBackground == "1e" && playerCurrentLocationX >= 800 && Scene1::SceneTransitionStatement == "East") {
        Textures tex;
        Scene1::SceneBackground = "1f";
        //Load in the new textures for scene2
        if (Scene1::tLoader == 0) {
            tex.Scene2Textures();
            Scene1::tLoader = 1;
        }

        SetSpritePosition(10, Scene1::yPosition,120);
        Scene1::SceneTransitionStatement = "";
        s.loadSounds(sceneBackground);
    }

    return message;
}