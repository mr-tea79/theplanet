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




void SceneInteraction::SetSpritePosition(int x, int y) {

    Scene1::gdSprite.x = x;
    Scene1::gdSprite.y = y;
    // SDL_WarpMouseInWindow(Scene1::window, 400, 400);

}

std::string SceneInteraction::sceneTransitions(int x, int y, int playerCurrentLocationX, int playerCurrentLocationY) {

    //Check database if item has been picked up.
    Inventory inv;
    Sound s;

    std::string message;

    //Menu Hover buttons //////////////////////////////////////////////////////////////////
    bool sound = s.checkSoundStatus(Sound::soundOn);
    s.updateSoundStatus(Sound::soundOn);

    if (sound == true && Scene1::SceneBackground == "0" && x > 27 && x < 77 && y > 28 && y < 77) {
        Scene1::menuSound = 1;
        Scene1::sceneHalt = 1; //Important so it only registers one click!
        Sound::soundOn = false;
        s.updateSoundStatus(Sound::soundOn);
    }
    if (sound == false && Scene1::SceneBackground == "0" && x > 27 && x < 77 && y > 28 && y < 77) {
        Scene1::menuSound = 1;
        Scene1::sceneHalt = 1; //Important so it only registers one click!
        Sound::soundOn = true;
        s.updateSoundStatus(Sound::soundOn);
    }


    if (Scene1::SceneBackground == "0" && x >= 159 && x <= 376 && y >= 480 && y <= 546) {
        Scene1::menuSound = 1;
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
        Scene1::menuSound = 1;
        SetSpritePosition(Scene1::xPosition, Scene1::yPosition);
        Scene1::sceneHalt = 1;
        Scene1::newGame = false;
        Scene1::continueGame = true;
        s.loadSounds(sceneBackground);
    }
    if (Scene1::SceneBackground == "0" && x >= 163 && x <= 376 && y >= 573 && y <= 644) {
        Scene1::menuSound = 1;
        Scene1::SceneBackground = "01";
        Scene1::SPRITE_SIZE = 50;
        Scene1::yPosition = 400;
        Scene1::xPosition = 65;
        SetSpritePosition(Scene1::xPosition, Scene1::yPosition);
        Scene1::sceneHalt = 1;
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
        Scene1::SPRITE_SIZE = 120;
        Scene1::yPosition = 450;
        Scene1::xPosition = 360;
        SetSpritePosition(Scene1::xPosition, Scene1::yPosition);
        Scene1::sceneHalt = 1;
        Scene1::SceneTransitionStatement = "";
        s.loadSounds(sceneBackground);
        //Load in the new textures for scene4
        tex.Scene4Textures();

    }
    /*
    if (playerCurrentLocationX > 700 && Scene1::SceneBackground == "4a") {
        Textures tex;
        Scene1::SceneBackground = "4b";
        Scene1::SPRITE_SIZE = 120;
        Scene1::yPosition = 450;
        Scene1::xPosition = 360;
        SetSpritePosition(Scene1::xPosition, Scene1::yPosition);
        Scene1::sceneHalt = 1;
        Scene1::SceneTransitionStatement = "";
        s.loadSounds(sceneBackground);
        PlayerInteraction::playerMessage = 13;
        //Load in the new textures for scene4
        tex.Scene4Textures();

    }
    */

    if (Scene1::SceneBackground == "3f" && playerCurrentLocationX <= 34) {
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

    if (Scene1::SceneBackground == "3a" && playerCurrentLocationX >= 862 && playerCurrentLocationX <= 918 && playerCurrentLocationY < 159 && playerCurrentLocationY > 107 && Scene1::secretTrigger > 0) {
        Scene1::SceneBackground = "3f";
        Scene1::SPRITE_SIZE = 50;
        Scene1::yPosition = 400;
        Scene1::xPosition = 65;
        SetSpritePosition(Scene1::xPosition, Scene1::yPosition);
        Scene1::sceneHalt = 1;
        Scene1::SceneTransitionStatement = "";
        s.loadSounds(sceneBackground);
    }



    if (Scene1::SceneBackground == "3e" && x >= 866 && x <= 987 && y >= 536 && y <= 575) {
        Scene1::SceneBackground = "3d";
        Scene1::SPRITE_SIZE = 128;
        Scene1::xPosition = 645;
        Scene1::yPosition = 448;
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

    if (Scene1::SceneBackground == "3c" && playerCurrentLocationX < 37 && playerCurrentLocationY >346) {
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


    if (Scene1::SceneBackground == "1da" && x >= 421 && x < 437 && y >= 373 && y <= 410 && playerCurrentLocationX > 300 && playerCurrentLocationX < 411 && playerCurrentLocationY < 394) {
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
    if (Scene1::SceneBackground == "1fb" && x >= 994 && y >= 0 && y <= 570 && playerCurrentLocationX > 900) {
        Scene1::SceneBackground = "3a";
        Scene1::SPRITE_SIZE = 10;
        Scene1::xPosition = 945;
        Scene1::yPosition = 387;
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
        Scene1::SPRITE_SIZE = 180;
        Scene1::xPosition = 280;
        Scene1::yPosition = 410;
        s.loadSounds(sceneBackground);

    }
    /* Entering tent from sandy clearing */
    if (Scene1::SceneBackground == "1fb" && x >= 581 && x <= 860 && y >= 117 && y <= 248 && playerCurrentLocationX >= 440 && playerCurrentLocationY <= 308) {
        Scene1::SceneBackground = "1da";
        Scene1::SPRITE_SIZE = 170;
        Scene1::yPosition = 360;
        Scene1::xPosition = 106;
        SetSpritePosition(Scene1::xPosition, Scene1::yPosition);
        Scene1::sceneHalt = 1;
        Scene1::SceneTransitionStatement = "";
        s.loadSounds(sceneBackground);
        AI::aiPlayMessages = true;
        AI::dialogNumber = 16;
        AI::playerTalk = true;

    }

    if (Scene1::SceneBackground == "3b" && playerCurrentLocationX >= 750 && playerCurrentLocationY <= 120) {
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
    if (Scene1::SceneBackground == "1da" && x >= 0 && x < 100 && y >= 390 && playerCurrentLocationX <= 10 && playerCurrentLocationY >= 308) {
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
        if (Scene1::tLoader == 1 || Scene1::SceneBackground == "1fb") {
            tex.Scene3Textures();
            Scene1::tLoader = 2;
        }
        Scene1::yPosition = 376;
        Scene1::xPosition = 106;
        SetSpritePosition(Scene1::xPosition, Scene1::yPosition);
        Scene1::sceneHalt = 1;
        Scene1::SceneTransitionStatement = "";
        Scene1::mouseClick = false;
        s.loadSounds(sceneBackground);
        AI::aiPlayMessages = true;
        AI::dialogNumber = 15;
        AI::playerTalk = true;

    }
    /* Outside wreckage */
    if (Scene1::SceneBackground == "1" && playerCurrentLocationX >= 665 && playerCurrentLocationX < 771 && playerCurrentLocationY <= 365 && Scene1::SceneTransitionStatement == "Wreckage") {
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
        AI::aiPlayMessages = true;
        AI::dialogNumber = 5;
        AI::playerTalk = true;
    }
    /* Sandy clearing */
    if (Scene1::SceneBackground == "1f" && x >= 0 && x <= 6 && y >= 139 && y <= 582 && playerCurrentLocationX < 6) {
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
    if (Scene1::SceneBackground == "1e" && x >= 9 && x <= 51 && y >= 311 && y <= 482 && playerCurrentLocationX <= 13) {
        Scene1::SceneBackground = "1";
        Scene1::SPRITE_SIZE = 120;
        Scene1::yPosition = 10;
    }

    /* Heading North */
    if (Scene1::SceneBackground == "1" && Scene1::SceneTransitionStatement == "Head North") {
        if (Scene1::objectToDestroy.find("3") == std::string::npos) {
            Scene1::sceneHalt = 1;
            AI::aiPlayMessages = true;
            AI::dialogNumber = 3;
            AI::playerTalk = true;
        }
        else if (Scene1::objectToDestroy.find("1") == std::string::npos) {
            Scene1::sceneHalt = 1;
            AI::aiPlayMessages = true;
            AI::dialogNumber = 2;
            AI::playerTalk = true;
        }
      
        else {
            Scene1::SceneBackground = "1e";
            Scene1::SPRITE_SIZE = 50;
            Scene1::xPosition = 10;
            Scene1::yPosition = 400;
            SetSpritePosition(Scene1::xPosition, Scene1::yPosition);
            Scene1::sceneHalt = 1;
            Scene1::SceneTransitionStatement = "";
            Scene1::mouseClick = false;
            s.loadSounds(sceneBackground);
        }
     
       
    }
    

    /* Entering sandy clearing from rocky path, load scene 2 textures */
    if (Scene1::SceneBackground == "1e" && x >= 994 && y >= 0 && y <= 570 && playerCurrentLocationX >= 994) {
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

    return message;
}