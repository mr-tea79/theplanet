<<<<<<< HEAD
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



using namespace brightland;

//Global
static std::string sceneBackground;
static int SPRITE_SIZE;
static int xPosition;
static int yPosition;
static int playerMessage;
static int inv3Used;  //Duct Tape
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



//HoverObjects will display information about objects of interest when the user hovers over them.
std::string PlayerObjects::HoverObjects(int x, int y, int scene,int gd, int gy) {

  
    std::string gameObject;

    //std::string pickUp;
    //Check database if item has been picked up.
    Inventory inv;
    PlayerObjects pob;
   
    

    //  int scene = 1; //Need to pass scene number in.
    int i = 0;
    int items = 0;


    std::string menuMessages = pob.ObjectInteractionM1(gd, gy);
    gameObject = menuMessages;


    std::string message;

    //Menu Hover Messages

    if (x > 190 && x < 227 && y > 676 && y < 690) {
        
        message = "Use";
    }


    if (x > 61 && x < 146 && y > 643 && y < 690) {
        if (inv.checkItem(gameObject) != 1) //Prevents invisible pickup objects.
            message = "Pick up " + gameObject;
        else
            message = "Pick up";
        
    }

    if (x > 178 && x < 232 && y > 723 && y < 744) {
        message = "Open";
    }

    //Inventory Hover Messages 
   
    if (x >= 696 && x <= 736 && y >= 653 && y <= 687) {
        if(inv.checkItem("PDA") != 0)
            message = "PDA";
    }

    if (x >= 764 && x <= 817 && y >= 695 && y <= 755) {
        if(inv.checkItem("Tent") != 0)
            message = "Self Inflating Tent";
    }

    if (x >= 771 && x <= 821 && y >= 796 && y <= 798) {
        if(inv.checkItem("Flag") != 0)
            message = "Flag";
    }

    if (x >= 888 && x <= 915 && y >= 653 && y <= 684) {
        if(inv.checkItem("Tape") != 0)
            message = "Ape Tape";
    }
    if (x >= 888 && x <= 915 && y >= 653 && y <= 684) {
        if(inv.checkItem("Pipe") != 0)
            message = "Pipe";
    }

 
    //Scene Hover Messages

    if (Scene1::SceneBackground == "3b" && x >= 756 && x < 830 && y >= 28 && y <= 92) {
        message = "Enter cave";
    }

    if (Scene1::SceneBackground == "3a" && x >= 150 && x < 209 && y >= 341 && y <= 374) {
        message = "Rock face";
    }

    if (Scene1::SceneBackground == "3a" && x >= 952 && x < 968 && y >= 353 && y <= 369) {
        message = "Camp";
    }
    
    if (Scene1::SceneBackground == "3a" && x >= 433 && x < 463 && y >= 158 && y <= 174) {
        message = "Crash site";
    }


    if (Scene1::SceneBackground == "1fb" && x >= 1000 && y >= 390 && y <= 586) {
        message = "Head East";
    }

    if (Scene1::SceneBackground == "1da" && x >= 0 && x <= 100 && y >= 390 && y <= 586) {
        message = "Leave camp";
    }

    if (Scene1::SceneBackground == "1da" && x >= 613 && x <= 640 && y >= 335 && y <= 378) {
            message = "Stuffed toy";
    }

    if (Scene1::SceneBackground == "1da" && x >= 523 && x <= 616 && y >= 502 && y <= 586 && boxOpened !=1) {
        message = "Carboard box";
    }

    if (Scene1::SceneBackground == "1da" && x >= 850 && x <= 958 && y >= 391 && y <= 482) {
        message = "Oxygenator 5000";
    }

    if (Scene1::SceneBackground == "1db" && x >= 0 && x <= 800 && y >= 459 && y <= 570) {
        message = "Leave Sofa";
    }

    if (Scene1::SceneBackground == "1da" && x >= 245 && x <= 295 && y >= 353 && y <= 414) {
        message = "Sofa";
    }

    if (Scene1::SceneBackground == "1f" && x >= 370 && x <= 916 && y >= 220 && y <= 283) {
        message = "Sandy clearing";
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
        message = "Rocks";
        
    }

    if (Scene1::SceneBackground == "1e" && x >= 994  && y >= 0 && y <= 570) {
        message = "Head east";        
    }

    if (Scene1::SceneBackground == "1" && x >= 52 && x <= 148 && y >= 14 && y <= 111) {
        message = "The moon";
        
    }

    if (Scene1::SceneBackground == "1" && x >= 759 && x <= 771 && y >= 325 && y <= 375) {
        message = "Enter Wreckage";
        
    }

    if (Scene1::SceneBackground == "1" && x >= 560 && x <= 612 && y >= 288 && y <= 350) {
        message = "Wreckage";
        
    }

    if (Scene1::SceneBackground == "1" && x >= 609 && x <= 719 && y >= 515 && y <= 542 && inv.checkItem("PDA") != 1) {
        message = "White plastic thingy";
             
    }


    if (Scene1::SceneBackground == "1b" && x >= 696 && x <= 763 && y >= 324 && y <= 525 && inv.checkItem("Flag") != 1) {
        message = "Flag";
    }

    if (Scene1::SceneBackground == "1b" && x >= 538 && x <= 580 && y >= 313 && y <= 441 && inv.checkItem("Tent") != 1) {
        message = "Self Inflating Tent";
    }



    if (Scene1::SceneBackground == "1" && x > 0 && x <= 552 && y > 204 && y < 235 && gy <360 ) {
        message = "Head North";
    }

    if (Scene1::SceneBackground == "1b" && x > 0 && x <= 771 && y >= 560 && y <= 595) {
        message = "Exit Wreckage";
    }

    if (Scene1::SceneBackground == "1b" && x > 126 && x <= 238 && y >= 306 && y <= 391) {
        message = "Computer Screen";
    }

    if (Scene1::SceneBackground == "1b" && x > 323 && x <= 360 && y >= 433 && y <= 474 && inv.checkItem("Tape") != 1 && Scene1::inv3Used !=1) {
        message = "Ape Tape";
    }

    if (Scene1::SceneBackground == "3a" && x > 682 && x <= 800 && y >= 25 && y <= 71){
        message = "Crators";
    }


    return message;
}

/* Make objects disappear when picked up. */
std::string PlayerObjects::DestroyObjects(std::string gameObject) {

    std::string objectToDestroy;

    if (gameObject == "PDA") {
        SDL_DestroyTexture(Scene1::objectTexture);
        objectToDestroy = "1";
    }

    if (gameObject == "Tape") {
        SDL_DestroyTexture(Scene1::objectTexture4);
        objectToDestroy = "3";
    }

    if (gameObject == "Flag") {
        SDL_DestroyTexture(Scene1::objectTexture2);
        objectToDestroy = "2";
    }

    if (gameObject == "Tent") {
        SDL_DestroyTexture(Scene1::objectTexture5);
        objectToDestroy = "4";
    }

    if (gameObject == "Pipe") {
       
        objectToDestroy = "5";
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

    std::string message;

    if (Scene1::SceneBackground == "3a" && x >= 150 && x < 209 && y >= 341 && y <= 374 && playerCurrentLocationX > 160 && playerCurrentLocationX < 199 && playerCurrentLocationY > 360 && playerCurrentLocationY < 383) {
        Scene1::SceneBackground = "3b";
        Scene1::SPRITE_SIZE = 50;
        Scene1::xPosition = 945;
        Scene1::yPosition = 387;
    }

    if (Scene1::SceneBackground == "3a" && x >= 433 && x < 463 && y >= 158 && y <= 174 && playerCurrentLocationX > 400 && playerCurrentLocationX < 529 ) {
        message = "My crashed ship, no chance of repairing.";
    }

    if (Scene1::SceneBackground == "3a" && x > 682 && x <= 800 && y >= 25 && y <= 71 && playerCurrentLocationX > 670 && playerCurrentLocationY < 126) {
        message = "These crators are lined up in a row, very strange.";
    }

    if (Scene1::SceneBackground == "3a" && x >= 952 && x < 968 && y >= 353 && y <= 369 && playerCurrentLocationX > 900) {
        Scene1::SceneBackground = "1fb";
        Scene1::SPRITE_SIZE = 180;
        Scene1::xPosition = 945;
        Scene1::yPosition = 387;
    }

    /*Leaving sandy clearing and going to map */
    if (Scene1::SceneBackground == "1fb" && x >= 994 && y >= 0 && y <= 570 &&playerCurrentLocationX > 900) {
        Scene1::SceneBackground = "3a";
        Scene1::SPRITE_SIZE = 10;
        Scene1::xPosition = 945;
        Scene1::yPosition = 387;
    }
    /* Looking at teddy bear */
    if (Scene1::SceneBackground == "1da" && x >= 613 && x <= 640 && y >= 335 && y <= 378) {
        message = "That's George";
        if (Scene1::useStatement == "Use")
            message = "I'll have a cuddle later.";
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
    
    }
    /* Entering tent from sandy clearing */
    if (Scene1::SceneBackground == "1fb" && x >= 581 && x <= 860 && y >= 117 && y <= 248 && playerCurrentLocationX >= 440 && playerCurrentLocationY <=308) {
        Scene1::SceneBackground = "1da";
        Scene1::SPRITE_SIZE = 180;
        Scene1::yPosition = 390;
        Scene1::xPosition = 106;
        Scene1::gdSprite.x = Scene1::xPosition;
        Scene1::gdSprite.y = Scene1::yPosition;    
        PlayerInteraction::playerMessage = 6;
    }
    /* Inside Tent */
    if (Scene1::SceneBackground == "1da" && x >= 0 && x <100 && y >= 390  && playerCurrentLocationX <= 10 && playerCurrentLocationY >= 308) {     
        if (Scene1::inv6Used != 1) {
            message = "My suit hasn't got enough oxygen";
        }
        else {
            Scene1::SceneBackground = "1fb";
            Scene1::SPRITE_SIZE = 120;
            Scene1::yPosition = 390;
            Scene1::xPosition = 106;
            Scene1::gdSprite.x = Scene1::xPosition;
            Scene1::gdSprite.y = Scene1::yPosition;
        }
       
       
    }
    /* Outside tent */
    if (Scene1::SceneBackground == "1fa" && x >= 793 && x <= 959 && y >= 474 && y <= 535) {
        Textures tex;
        Scene1::SceneBackground = "1fb";
        Scene1::SPRITE_SIZE = 120;
        Scene1::yPosition = 376;
        Scene1::xPosition = 106;
        Scene1::gdSprite.x = Scene1::xPosition;
        Scene1::gdSprite.y = Scene1::yPosition;
        if (Scene1::tLoader == 1) {
            tex.Scene3Textures();
            Scene1::tLoader = 2;
        }

        PlayerInteraction::playerMessage = 7;
       
    }
    /* Outside wrekage */
    if (Scene1::SceneBackground == "1" && x >= 759 && x <= 771 && y >= 325 && y <= 375 && playerCurrentLocationX >= 700 ) {
        std::cout << "Entering Wreckage" << std::endl;
        Scene1::SceneBackground = "1b";
        Scene1::SPRITE_SIZE = 200;
        Scene1::xPosition = 400;
        Scene1::gdSprite.x = Scene1::xPosition;
  
    }
    /* Sandy clearing */
    if (Scene1::SceneBackground == "1f" && x >= 0 && x <= 6 && y >= 139 && y <= 582 && playerCurrentLocationX <6) {
        std::cout << "Going West" << std::endl;
        Scene1::SceneBackground = "1e";
        Scene1::SPRITE_SIZE = 50;
        Scene1::yPosition = 380;
        Scene1::xPosition = 350;
        Scene1::gdSprite.x = Scene1::xPosition;
        Scene1::gdSprite.y = Scene1::yPosition;
    }
    /* Inside wreakage */
    if (Scene1::SceneBackground == "1b" && x > 0 && x <= 771 && y >= 570 && y <= 595) {
        Scene1::SceneBackground = "1";
        Scene1::SPRITE_SIZE = 110;
       // message = "Scene1";
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
        Scene1::SPRITE_SIZE = 200;
      
    }

    if (Scene1::SceneBackground == "1d" && x > 36 && x <= 172 && y >= 544 && y <= 582) {

        Scene1::SceneBackground = "1b";
        Scene1::SPRITE_SIZE = 200;
        message = "Scene1b";

    }
    /* Sandy clearing */
    if (Scene1::SceneBackground == "1f" && x >= 370 && x <= 916 && y >= 220 && y <= 283 && playerCurrentLocationX <=900 && playerCurrentLocationX >300  && playerCurrentLocationY <= 360) {
        message = "It's very flat here.";
        if (Scene1::useStatement == "Use")
            message = "It's a good idea";
    }

    /* Outside wreakage, first scene of the game */
    if (Scene1::SceneBackground == "1" && x >= 52 && x <= 148 && y >= 14 && y <= 111 && playerCurrentLocationX <= 800) {

        message = "This is one strange looking Place.";
        if (Scene1::useStatement == "Use")
            message = "For what am I going to use the moon for?";
    }
    /* Rocky path */
    if (Scene1::SceneBackground == "1e" && x >= 661 && x <= 742 && y >= 365 && y <= 409 && playerCurrentLocationX >= 640) {

        message = "Some rocks, nothing interesting.";
        if (Scene1::useStatement == "Use")
            message = "I'm not a geologist.";
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
        Scene1::gdSprite.x = Scene1::xPosition;
        Scene1::gdSprite.y = Scene1::yPosition;
    }


    //Check if PDA is picked up and Oxygen is fixed.
    /* Leave wreakage scene and head to rocky path */
    if (Scene1::SceneBackground == "1" && x > 0 && x <= 771 && y > 204 && y < 259 && playerCurrentLocationY <360 ) {
        
        if (Scene1::inv3Used != 1) {
            message = "I'm leaking Oxygen, are you crazy!?";
        }
        else if (inv.checkItem("Tent") != 1) {
            message = "I need to be able to set up camp if I'm going to venture out into the wilderness.";
        }
        else if (inv.checkItem("PDA") != 1) {
            message = "I need to take my computer with me.";
        }
        else {          
            Scene1::SceneBackground = "1e";
            Scene1::SPRITE_SIZE = 50;
            Scene1::yPosition = 376;
            Scene1::xPosition = 106;
            Scene1::gdSprite.x = Scene1::xPosition;
            Scene1::gdSprite.y = Scene1::yPosition;
            PlayerInteraction::playerMessage = 5;
        }       
           
    }

    /* Looking at broken engine */
    if (Scene1::SceneBackground == "1" && x >= 560 && x <= 612 && y >= 288 && y <= 350 && playerCurrentLocationX >= 300 && playerCurrentLocationX <= 600) {
        message = "Anti matter engine. This ship isn't going nowhere!";
        if (Scene1::useStatement == "Use")
            message= "It's broken, what am I supposed to use it for?";
    }

    /* Trying to use PDA which is still on the ground */
    if (Scene1::SceneBackground == "1" && x >= 681 && x <= 700 && y >= 515 && y <= 542 && playerCurrentLocationX >= 622 && playerCurrentLocationX <= 736 && inv.checkItem("PDA") != 1) {

        message = "That's my PDA";
        if (Scene1::useStatement == "Use")
            message = "I need to pick it up first!";
    }

    /* Looking at Ape Tape */
    if (Scene1::SceneBackground == "1b" && x >= 320 && x <= 390 && y >= 433 && y <= 474 && playerCurrentLocationX >= 310 && playerCurrentLocationX <= 394 && inv.checkItem("Tape") != 1) {

        message = "Oooh Ape Tape!";
        if (Scene1::useStatement == "Use")
            message = "I need to pick it up first!";
    }
    /* Looking at tent inside wreakage */
    if (Scene1::SceneBackground == "1b" && x >= 538 && x <= 580 && y >= 313 && y <= 441 && playerCurrentLocationX >= 406 && playerCurrentLocationX <= 496 && inv.checkItem("Tent") != 1) {

        message = "Does exactly what it says on the tin";
        if (Scene1::useStatement == "Use")
            message = "Not in here! That won't end well.";
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

    return message;
}


/*Here is where you place game objects. You specify coordinates and dimensions of the object */
std::tuple<int, int, int, int, int> PlayerObjects::placeObject(int scene, int objectID, int b, int c, int d) {

    if (scene == 1 && objectID == 1) {
        //PDA
        //Put "actual" image size here (sprites,NULL,WIDTH,HEIGHT)
        return  std::make_tuple(3, 15, NULL, 50, 50);
    }

    if (scene == 1 && objectID == 2) {
        //Flag Rolled up

        return  std::make_tuple(3, 15, NULL, 80, 218);
    }

    if (scene == 1 && objectID == 3) {
        //Stars

        return  std::make_tuple(3, 15, NULL, 283, 347);
    }

    if (scene == 1 && objectID == 4) {
        //Tape

        //The second value is set to 0 to prevent the animation by setting the speed to 0.
        return  std::make_tuple(1, 0, NULL, 100, 100);
    }

    if (scene == 1 && objectID == 5) {
        //Tent

        //The second value is set to 0 to prevent the animation by setting the speed to 0.
        return  std::make_tuple(1, 0, NULL, 100, 149);
    }
    if (scene == 1 && objectID == 6) {
        //Tent

        //The second value is set to 0 to prevent the animation by setting the speed to 0.
        return  std::make_tuple(1, 0, NULL, 100, 149);
    }
    if (scene == 1 && objectID == 7) {
        //Tent

        //The second value is set to 0 to prevent the animation by setting the speed to 0.
        return  std::make_tuple(1, 0, NULL, 186, 138);
    }



    return  std::make_tuple(scene, objectID, b, c, d);
}

/* Here is where you set animations of the objects and also hadd coordinates and dimensions */
std::tuple<int, int, int, int, int> PlayerObjects::placeObjectA(int scene, int objectID, int b, int c, int d) {

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
        return  std::make_tuple(9, 400, 30, 15, 40);
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

    return  std::make_tuple(scene, objectID, b, c, d);
}

void PlayerObjects::PlaceObjects() {

    Uint32 ticks = SDL_GetTicks();
    PlayerObjects pob;
    /*Scene Objects
    Below you can add all the objects you want to appear on the scene and then you copy them to the renderer at the bottom of the game loop.*/
    //Add Scene Objects.
     //Scene Object variables.
    int sceneobject = 1, objectP1, objectP2, objectHeight, objectWidth, numberSprites;
    int objectP3, objectP4, objectP5, objectP6;

    //Scene Object 1 (PDA)
    //Build object parameters.                                                            //1 means object 1
    std::tie(numberSprites, objectP1, objectP2, objectHeight, objectWidth) = pob.placeObject(1, 1, NULL, NULL, NULL);
    std::tie(numberSprites, objectP3, objectP4, objectP5, objectP6) = pob.placeObjectA(1, 1, NULL, NULL, NULL);

    int object1 = (ticks / 100) % 1;
    //Set objectSprite Parameters size, height, width, position etc.
    PlayerObjects::srcrect = { object1 * objectP1, objectP2, objectHeight, objectWidth };
    PlayerObjects::dstrect = { objectP3, objectP4, objectP5, objectP6 };

    //Scene Object 2
    //Build object parameters.                                                                //2 means object 2
    std::tie(numberSprites, objectP1, objectP2, objectHeight, objectWidth) = pob.placeObject(1, 2, NULL, NULL, NULL);
    std::tie(numberSprites, objectP3, objectP4, objectP5, objectP6) = pob.placeObjectA(1, 2, NULL, NULL, NULL);

    int object2 = (ticks / 100) % 1;
    //Set objectSprite Parameters size, height, width, position etc.
    PlayerObjects::srcrect2 = { object2 * objectP1, objectP2, objectHeight, objectWidth };
    PlayerObjects::dstrect2 = { objectP3, objectP4, objectP5, objectP6 };

    //Scene Object 3 (Flashing lights)
    std::tie(numberSprites, objectP1, objectP2, objectHeight, objectWidth) = pob.placeObject(1, 3, NULL, NULL, NULL);
    std::tie(numberSprites, objectP3, objectP4, objectP5, objectP6) = pob.placeObjectA(1, 3, NULL, NULL, NULL);

    //% numberSprites is set to the value specified in PlaceObjectA. Here it is set to 3.
    int object3 = (ticks / 100) % numberSprites;
    //Set objectSprite Parameters size, height, width, position etc.
    PlayerObjects::srcrect3 = { object3 * objectP1, objectP2, objectHeight, objectWidth };
    PlayerObjects::dstrect3 = { objectP3, objectP4, objectP5, objectP6 };

    //Scene Object 4.......
    std::tie(numberSprites, objectP1, objectP2, objectHeight, objectWidth) = pob.placeObject(1, 4, NULL, NULL, NULL);
    std::tie(numberSprites, objectP3, objectP4, objectP5, objectP6) = pob.placeObjectA(1, 4, NULL, NULL, NULL);

    //Set it to 1 for no animation.
    int object4 = (ticks / 100) % 1;
    //Set objectSprite Parameters size, height, width, position etc.
    PlayerObjects::srcrect4 = { object3 * objectP1, objectP2, objectHeight, objectWidth };
    PlayerObjects::dstrect4 = { objectP3, objectP4, objectP5, objectP6 };

    //Scene Object 5.......
    std::tie(numberSprites, objectP1, objectP2, objectHeight, objectWidth) = pob.placeObject(1, 5, NULL, NULL, NULL);
    std::tie(numberSprites, objectP3, objectP4, objectP5, objectP6) = pob.placeObjectA(1, 5, NULL, NULL, NULL);

    int object5 = (ticks / 100) % 1;
    //Set objectSprite Parameters size, height, width, position etc.
    PlayerObjects::srcrect5 = { object3 * objectP1, objectP2, objectHeight, objectWidth };
    PlayerObjects::dstrect5 = { objectP3, objectP4, objectP5, objectP6 };

    //Scene Object 6.......
    std::tie(numberSprites, objectP1, objectP2, objectHeight, objectWidth) = pob.placeObject(1, 6, NULL, NULL, NULL);
    std::tie(numberSprites, objectP3, objectP4, objectP5, objectP6) = pob.placeObjectA(1, 6, NULL, NULL, NULL);

    int object6 = (ticks / 100) % 1;
    //Set objectSprite Parameters size, height, width, position etc.
    PlayerObjects::srcrect6 = { object3 * objectP1, objectP2, objectHeight, objectWidth };
    PlayerObjects::dstrect6 = { objectP3, objectP4, objectP5, objectP6 };

    //Scene Object 7 Air Box
    std::tie(numberSprites, objectP1, objectP2, objectHeight, objectWidth) = pob.placeObject(1, 7, NULL, NULL, NULL);
    std::tie(numberSprites, objectP3, objectP4, objectP5, objectP6) = pob.placeObjectA(1, 7, NULL, NULL, NULL);

    int object7 = (ticks / 100) % 1;
    //Set objectSprite Parameters size, height, width, position etc.
    PlayerObjects::srcrect7 = { object3 * objectP1, objectP2, objectHeight, objectWidth };
    PlayerObjects::dstrect7 = { objectP3, objectP4, objectP5, objectP6 };
}

=======
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



using namespace brightland;

//Global
static std::string sceneBackground;
static int SPRITE_SIZE;
static int xPosition;
static int yPosition;
static int playerMessage;
static int inv3Used;  //Duct Tape
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



//HoverObjects will display information about objects of interest when the user hovers over them.
std::string PlayerObjects::HoverObjects(int x, int y, int scene,int gd, int gy) {

  
    std::string gameObject;

    //std::string pickUp;
    //Check database if item has been picked up.
    Inventory inv;
    PlayerObjects pob;
   
    

    //  int scene = 1; //Need to pass scene number in.
    int i = 0;
    int items = 0;


    std::string menuMessages = pob.ObjectInteractionM1(gd, gy);
    gameObject = menuMessages;


    std::string message;

    //Menu Hover Messages

    if (x > 190 && x < 227 && y > 676 && y < 690) {
        
        message = "Use";
    }


    if (x > 61 && x < 146 && y > 643 && y < 690) {
        if (inv.checkItem(gameObject) != 1) //Prevents invisible pickup objects.
            message = "Pick up " + gameObject;
        else
            message = "Pick up";
        
    }

    if (x > 178 && x < 232 && y > 723 && y < 744) {
        message = "Open";
    }

    //Inventory Hover Messages 
   
    if (x >= 696 && x <= 736 && y >= 653 && y <= 687) {
        if(inv.checkItem("PDA") != 0)
            message = "PDA";
    }

    if (x >= 764 && x <= 817 && y >= 695 && y <= 755) {
        if(inv.checkItem("Tent") != 0)
            message = "Self Inflating Tent";
    }

    if (x >= 771 && x <= 821 && y >= 796 && y <= 798) {
        if(inv.checkItem("Flag") != 0)
            message = "Flag";
    }

    if (x >= 888 && x <= 915 && y >= 653 && y <= 684) {
        if(inv.checkItem("Tape") != 0)
            message = "Ape Tape";
    }
    if (x >= 888 && x <= 915 && y >= 653 && y <= 684) {
        if(inv.checkItem("Pipe") != 0)
            message = "Pipe";
    }

 
    //Scene Hover Messages

    if (Scene1::SceneBackground == "3b" && x >= 756 && x < 830 && y >= 28 && y <= 92) {
        message = "Enter cave";
    }

    if (Scene1::SceneBackground == "3a" && x >= 150 && x < 209 && y >= 341 && y <= 374) {
        message = "Rock face";
    }

    if (Scene1::SceneBackground == "3a" && x >= 952 && x < 968 && y >= 353 && y <= 369) {
        message = "Camp";
    }
    
    if (Scene1::SceneBackground == "3a" && x >= 433 && x < 463 && y >= 158 && y <= 174) {
        message = "Crash site";
    }


    if (Scene1::SceneBackground == "1fb" && x >= 1000 && y >= 390 && y <= 586) {
        message = "Head East";
    }

    if (Scene1::SceneBackground == "1da" && x >= 0 && x <= 100 && y >= 390 && y <= 586) {
        message = "Leave camp";
    }

    if (Scene1::SceneBackground == "1da" && x >= 613 && x <= 640 && y >= 335 && y <= 378) {
            message = "Stuffed toy";
    }

    if (Scene1::SceneBackground == "1da" && x >= 523 && x <= 616 && y >= 502 && y <= 586 && boxOpened !=1) {
        message = "Carboard box";
    }

    if (Scene1::SceneBackground == "1da" && x >= 850 && x <= 958 && y >= 391 && y <= 482) {
        message = "Oxygenator 5000";
    }

    if (Scene1::SceneBackground == "1db" && x >= 0 && x <= 800 && y >= 459 && y <= 570) {
        message = "Leave Sofa";
    }

    if (Scene1::SceneBackground == "1da" && x >= 245 && x <= 295 && y >= 353 && y <= 414) {
        message = "Sofa";
    }

    if (Scene1::SceneBackground == "1f" && x >= 370 && x <= 916 && y >= 220 && y <= 283) {
        message = "Sandy clearing";
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
        message = "Rocks";
        
    }

    if (Scene1::SceneBackground == "1e" && x >= 994  && y >= 0 && y <= 570) {
        message = "Head east";        
    }

    if (Scene1::SceneBackground == "1" && x >= 52 && x <= 148 && y >= 14 && y <= 111) {
        message = "The moon";
        
    }

    if (Scene1::SceneBackground == "1" && x >= 759 && x <= 771 && y >= 325 && y <= 375) {
        message = "Enter Wreckage";
        
    }

    if (Scene1::SceneBackground == "1" && x >= 560 && x <= 612 && y >= 288 && y <= 350) {
        message = "Wreckage";
        
    }

    if (Scene1::SceneBackground == "1" && x >= 609 && x <= 719 && y >= 515 && y <= 542 && inv.checkItem("PDA") != 1) {
        message = "White plastic thingy";
             
    }


    if (Scene1::SceneBackground == "1b" && x >= 696 && x <= 763 && y >= 324 && y <= 525 && inv.checkItem("Flag") != 1) {
        message = "Flag";
    }

    if (Scene1::SceneBackground == "1b" && x >= 538 && x <= 580 && y >= 313 && y <= 441 && inv.checkItem("Tent") != 1) {
        message = "Self Inflating Tent";
    }



    if (Scene1::SceneBackground == "1" && x > 0 && x <= 552 && y > 204 && y < 235 && gy <360 ) {
        message = "Head North";
    }

    if (Scene1::SceneBackground == "1b" && x > 0 && x <= 771 && y >= 560 && y <= 595) {
        message = "Exit Wreckage";
    }

    if (Scene1::SceneBackground == "1b" && x > 126 && x <= 238 && y >= 306 && y <= 391) {
        message = "Computer Screen";
    }

    if (Scene1::SceneBackground == "1b" && x > 323 && x <= 360 && y >= 433 && y <= 474 && inv.checkItem("Tape") != 1 && Scene1::inv3Used !=1) {
        message = "Ape Tape";
    }

    if (Scene1::SceneBackground == "3a" && x > 682 && x <= 800 && y >= 25 && y <= 71){
        message = "Crators";
    }


    return message;
}

/* Make objects disappear when picked up. */
std::string PlayerObjects::DestroyObjects(std::string gameObject) {

    std::string objectToDestroy;

    if (gameObject == "PDA") {
        SDL_DestroyTexture(Scene1::objectTexture);
        objectToDestroy = "1";
    }

    if (gameObject == "Tape") {
        SDL_DestroyTexture(Scene1::objectTexture4);
        objectToDestroy = "3";
    }

    if (gameObject == "Flag") {
        SDL_DestroyTexture(Scene1::objectTexture2);
        objectToDestroy = "2";
    }

    if (gameObject == "Tent") {
        SDL_DestroyTexture(Scene1::objectTexture5);
        objectToDestroy = "4";
    }

    if (gameObject == "Pipe") {
       
        objectToDestroy = "5";
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

    std::string message;

    if (Scene1::SceneBackground == "3a" && x >= 150 && x < 209 && y >= 341 && y <= 374 && playerCurrentLocationX > 160 && playerCurrentLocationX < 199 && playerCurrentLocationY > 360 && playerCurrentLocationY < 383) {
        Scene1::SceneBackground = "3b";
        Scene1::SPRITE_SIZE = 50;
        Scene1::xPosition = 945;
        Scene1::yPosition = 387;
    }

    if (Scene1::SceneBackground == "3a" && x >= 433 && x < 463 && y >= 158 && y <= 174 && playerCurrentLocationX > 400 && playerCurrentLocationX < 529 ) {
        message = "My crashed ship, no chance of repairing.";
    }

    if (Scene1::SceneBackground == "3a" && x > 682 && x <= 800 && y >= 25 && y <= 71 && playerCurrentLocationX > 670 && playerCurrentLocationY < 126) {
        message = "These crators are lined up in a row, very strange.";
    }

    if (Scene1::SceneBackground == "3a" && x >= 952 && x < 968 && y >= 353 && y <= 369 && playerCurrentLocationX > 900) {
        Scene1::SceneBackground = "1fb";
        Scene1::SPRITE_SIZE = 180;
        Scene1::xPosition = 945;
        Scene1::yPosition = 387;
    }

    /*Leaving sandy clearing and going to map */
    if (Scene1::SceneBackground == "1fb" && x >= 994 && y >= 0 && y <= 570 &&playerCurrentLocationX > 900) {
        Scene1::SceneBackground = "3a";
        Scene1::SPRITE_SIZE = 10;
        Scene1::xPosition = 945;
        Scene1::yPosition = 387;
    }
    /* Looking at teddy bear */
    if (Scene1::SceneBackground == "1da" && x >= 613 && x <= 640 && y >= 335 && y <= 378) {
        message = "That's George";
        if (Scene1::useStatement == "Use")
            message = "I'll have a cuddle later.";
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
    
    }
    /* Entering tent from sandy clearing */
    if (Scene1::SceneBackground == "1fb" && x >= 581 && x <= 860 && y >= 117 && y <= 248 && playerCurrentLocationX >= 440 && playerCurrentLocationY <=308) {
        Scene1::SceneBackground = "1da";
        Scene1::SPRITE_SIZE = 180;
        Scene1::yPosition = 390;
        Scene1::xPosition = 106;
        Scene1::gdSprite.x = Scene1::xPosition;
        Scene1::gdSprite.y = Scene1::yPosition;    
        PlayerInteraction::playerMessage = 6;
    }
    /* Inside Tent */
    if (Scene1::SceneBackground == "1da" && x >= 0 && x <100 && y >= 390  && playerCurrentLocationX <= 10 && playerCurrentLocationY >= 308) {     
        if (Scene1::inv6Used != 1) {
            message = "My suit hasn't got enough oxygen";
        }
        else {
            Scene1::SceneBackground = "1fb";
            Scene1::SPRITE_SIZE = 120;
            Scene1::yPosition = 390;
            Scene1::xPosition = 106;
            Scene1::gdSprite.x = Scene1::xPosition;
            Scene1::gdSprite.y = Scene1::yPosition;
        }
       
       
    }
    /* Outside tent */
    if (Scene1::SceneBackground == "1fa" && x >= 793 && x <= 959 && y >= 474 && y <= 535) {
        Textures tex;
        Scene1::SceneBackground = "1fb";
        Scene1::SPRITE_SIZE = 120;
        Scene1::yPosition = 376;
        Scene1::xPosition = 106;
        Scene1::gdSprite.x = Scene1::xPosition;
        Scene1::gdSprite.y = Scene1::yPosition;
        if (Scene1::tLoader == 1) {
            tex.Scene3Textures();
            Scene1::tLoader = 2;
        }

        PlayerInteraction::playerMessage = 7;
       
    }
    /* Outside wrekage */
    if (Scene1::SceneBackground == "1" && x >= 759 && x <= 771 && y >= 325 && y <= 375 && playerCurrentLocationX >= 700 ) {
        std::cout << "Entering Wreckage" << std::endl;
        Scene1::SceneBackground = "1b";
        Scene1::SPRITE_SIZE = 200;
        Scene1::xPosition = 400;
        Scene1::gdSprite.x = Scene1::xPosition;
  
    }
    /* Sandy clearing */
    if (Scene1::SceneBackground == "1f" && x >= 0 && x <= 6 && y >= 139 && y <= 582 && playerCurrentLocationX <6) {
        std::cout << "Going West" << std::endl;
        Scene1::SceneBackground = "1e";
        Scene1::SPRITE_SIZE = 50;
        Scene1::yPosition = 380;
        Scene1::xPosition = 350;
        Scene1::gdSprite.x = Scene1::xPosition;
        Scene1::gdSprite.y = Scene1::yPosition;
    }
    /* Inside wreakage */
    if (Scene1::SceneBackground == "1b" && x > 0 && x <= 771 && y >= 570 && y <= 595) {
        Scene1::SceneBackground = "1";
        Scene1::SPRITE_SIZE = 110;
       // message = "Scene1";
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
        Scene1::SPRITE_SIZE = 200;
      
    }

    if (Scene1::SceneBackground == "1d" && x > 36 && x <= 172 && y >= 544 && y <= 582) {

        Scene1::SceneBackground = "1b";
        Scene1::SPRITE_SIZE = 200;
        message = "Scene1b";

    }
    /* Sandy clearing */
    if (Scene1::SceneBackground == "1f" && x >= 370 && x <= 916 && y >= 220 && y <= 283 && playerCurrentLocationX <=900 && playerCurrentLocationX >300  && playerCurrentLocationY <= 360) {
        message = "It's very flat here.";
        if (Scene1::useStatement == "Use")
            message = "It's a good idea";
    }

    /* Outside wreakage, first scene of the game */
    if (Scene1::SceneBackground == "1" && x >= 52 && x <= 148 && y >= 14 && y <= 111 && playerCurrentLocationX <= 800) {

        message = "This is one strange looking Place.";
        if (Scene1::useStatement == "Use")
            message = "For what am I going to use the moon for?";
    }
    /* Rocky path */
    if (Scene1::SceneBackground == "1e" && x >= 661 && x <= 742 && y >= 365 && y <= 409 && playerCurrentLocationX >= 640) {

        message = "Some rocks, nothing interesting.";
        if (Scene1::useStatement == "Use")
            message = "I'm not a geologist.";
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
        Scene1::gdSprite.x = Scene1::xPosition;
        Scene1::gdSprite.y = Scene1::yPosition;
    }


    //Check if PDA is picked up and Oxygen is fixed.
    /* Leave wreakage scene and head to rocky path */
    if (Scene1::SceneBackground == "1" && x > 0 && x <= 771 && y > 204 && y < 259 && playerCurrentLocationY <360 ) {
        
        if (Scene1::inv3Used != 1) {
            message = "I'm leaking Oxygen, are you crazy!?";
        }
        else if (inv.checkItem("Tent") != 1) {
            message = "I need to be able to set up camp if I'm going to venture out into the wilderness.";
        }
        else if (inv.checkItem("PDA") != 1) {
            message = "I need to take my computer with me.";
        }
        else {          
            Scene1::SceneBackground = "1e";
            Scene1::SPRITE_SIZE = 50;
            Scene1::yPosition = 376;
            Scene1::xPosition = 106;
            Scene1::gdSprite.x = Scene1::xPosition;
            Scene1::gdSprite.y = Scene1::yPosition;
            PlayerInteraction::playerMessage = 5;
        }       
           
    }

    /* Looking at broken engine */
    if (Scene1::SceneBackground == "1" && x >= 560 && x <= 612 && y >= 288 && y <= 350 && playerCurrentLocationX >= 300 && playerCurrentLocationX <= 600) {
        message = "Anti matter engine. This ship isn't going nowhere!";
        if (Scene1::useStatement == "Use")
            message= "It's broken, what am I supposed to use it for?";
    }

    /* Trying to use PDA which is still on the ground */
    if (Scene1::SceneBackground == "1" && x >= 681 && x <= 700 && y >= 515 && y <= 542 && playerCurrentLocationX >= 622 && playerCurrentLocationX <= 736 && inv.checkItem("PDA") != 1) {

        message = "That's my PDA";
        if (Scene1::useStatement == "Use")
            message = "I need to pick it up first!";
    }

    /* Looking at Ape Tape */
    if (Scene1::SceneBackground == "1b" && x >= 320 && x <= 390 && y >= 433 && y <= 474 && playerCurrentLocationX >= 310 && playerCurrentLocationX <= 394 && inv.checkItem("Tape") != 1) {

        message = "Oooh Ape Tape!";
        if (Scene1::useStatement == "Use")
            message = "I need to pick it up first!";
    }
    /* Looking at tent inside wreakage */
    if (Scene1::SceneBackground == "1b" && x >= 538 && x <= 580 && y >= 313 && y <= 441 && playerCurrentLocationX >= 406 && playerCurrentLocationX <= 496 && inv.checkItem("Tent") != 1) {

        message = "Does exactly what it says on the tin";
        if (Scene1::useStatement == "Use")
            message = "Not in here! That won't end well.";
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

    return message;
}


/*Here is where you place game objects. You specify coordinates and dimensions of the object */
std::tuple<int, int, int, int, int> PlayerObjects::placeObject(int scene, int objectID, int b, int c, int d) {

    if (scene == 1 && objectID == 1) {
        //PDA
        //Put "actual" image size here (sprites,NULL,WIDTH,HEIGHT)
        return  std::make_tuple(3, 15, NULL, 50, 50);
    }

    if (scene == 1 && objectID == 2) {
        //Flag Rolled up

        return  std::make_tuple(3, 15, NULL, 80, 218);
    }

    if (scene == 1 && objectID == 3) {
        //Stars

        return  std::make_tuple(3, 15, NULL, 283, 347);
    }

    if (scene == 1 && objectID == 4) {
        //Tape

        //The second value is set to 0 to prevent the animation by setting the speed to 0.
        return  std::make_tuple(1, 0, NULL, 100, 100);
    }

    if (scene == 1 && objectID == 5) {
        //Tent

        //The second value is set to 0 to prevent the animation by setting the speed to 0.
        return  std::make_tuple(1, 0, NULL, 100, 149);
    }
    if (scene == 1 && objectID == 6) {
        //Tent

        //The second value is set to 0 to prevent the animation by setting the speed to 0.
        return  std::make_tuple(1, 0, NULL, 100, 149);
    }
    if (scene == 1 && objectID == 7) {
        //Tent

        //The second value is set to 0 to prevent the animation by setting the speed to 0.
        return  std::make_tuple(1, 0, NULL, 186, 138);
    }



    return  std::make_tuple(scene, objectID, b, c, d);
}

/* Here is where you set animations of the objects and also hadd coordinates and dimensions */
std::tuple<int, int, int, int, int> PlayerObjects::placeObjectA(int scene, int objectID, int b, int c, int d) {

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
        return  std::make_tuple(9, 400, 30, 15, 40);
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

    return  std::make_tuple(scene, objectID, b, c, d);
}

void PlayerObjects::PlaceObjects() {

    Uint32 ticks = SDL_GetTicks();
    PlayerObjects pob;
    /*Scene Objects
    Below you can add all the objects you want to appear on the scene and then you copy them to the renderer at the bottom of the game loop.*/
    //Add Scene Objects.
     //Scene Object variables.
    int sceneobject = 1, objectP1, objectP2, objectHeight, objectWidth, numberSprites;
    int objectP3, objectP4, objectP5, objectP6;

    //Scene Object 1 (PDA)
    //Build object parameters.                                                            //1 means object 1
    std::tie(numberSprites, objectP1, objectP2, objectHeight, objectWidth) = pob.placeObject(1, 1, NULL, NULL, NULL);
    std::tie(numberSprites, objectP3, objectP4, objectP5, objectP6) = pob.placeObjectA(1, 1, NULL, NULL, NULL);

    int object1 = (ticks / 100) % 1;
    //Set objectSprite Parameters size, height, width, position etc.
    PlayerObjects::srcrect = { object1 * objectP1, objectP2, objectHeight, objectWidth };
    PlayerObjects::dstrect = { objectP3, objectP4, objectP5, objectP6 };

    //Scene Object 2
    //Build object parameters.                                                                //2 means object 2
    std::tie(numberSprites, objectP1, objectP2, objectHeight, objectWidth) = pob.placeObject(1, 2, NULL, NULL, NULL);
    std::tie(numberSprites, objectP3, objectP4, objectP5, objectP6) = pob.placeObjectA(1, 2, NULL, NULL, NULL);

    int object2 = (ticks / 100) % 1;
    //Set objectSprite Parameters size, height, width, position etc.
    PlayerObjects::srcrect2 = { object2 * objectP1, objectP2, objectHeight, objectWidth };
    PlayerObjects::dstrect2 = { objectP3, objectP4, objectP5, objectP6 };

    //Scene Object 3 (Flashing lights)
    std::tie(numberSprites, objectP1, objectP2, objectHeight, objectWidth) = pob.placeObject(1, 3, NULL, NULL, NULL);
    std::tie(numberSprites, objectP3, objectP4, objectP5, objectP6) = pob.placeObjectA(1, 3, NULL, NULL, NULL);

    //% numberSprites is set to the value specified in PlaceObjectA. Here it is set to 3.
    int object3 = (ticks / 100) % numberSprites;
    //Set objectSprite Parameters size, height, width, position etc.
    PlayerObjects::srcrect3 = { object3 * objectP1, objectP2, objectHeight, objectWidth };
    PlayerObjects::dstrect3 = { objectP3, objectP4, objectP5, objectP6 };

    //Scene Object 4.......
    std::tie(numberSprites, objectP1, objectP2, objectHeight, objectWidth) = pob.placeObject(1, 4, NULL, NULL, NULL);
    std::tie(numberSprites, objectP3, objectP4, objectP5, objectP6) = pob.placeObjectA(1, 4, NULL, NULL, NULL);

    //Set it to 1 for no animation.
    int object4 = (ticks / 100) % 1;
    //Set objectSprite Parameters size, height, width, position etc.
    PlayerObjects::srcrect4 = { object3 * objectP1, objectP2, objectHeight, objectWidth };
    PlayerObjects::dstrect4 = { objectP3, objectP4, objectP5, objectP6 };

    //Scene Object 5.......
    std::tie(numberSprites, objectP1, objectP2, objectHeight, objectWidth) = pob.placeObject(1, 5, NULL, NULL, NULL);
    std::tie(numberSprites, objectP3, objectP4, objectP5, objectP6) = pob.placeObjectA(1, 5, NULL, NULL, NULL);

    int object5 = (ticks / 100) % 1;
    //Set objectSprite Parameters size, height, width, position etc.
    PlayerObjects::srcrect5 = { object3 * objectP1, objectP2, objectHeight, objectWidth };
    PlayerObjects::dstrect5 = { objectP3, objectP4, objectP5, objectP6 };

    //Scene Object 6.......
    std::tie(numberSprites, objectP1, objectP2, objectHeight, objectWidth) = pob.placeObject(1, 6, NULL, NULL, NULL);
    std::tie(numberSprites, objectP3, objectP4, objectP5, objectP6) = pob.placeObjectA(1, 6, NULL, NULL, NULL);

    int object6 = (ticks / 100) % 1;
    //Set objectSprite Parameters size, height, width, position etc.
    PlayerObjects::srcrect6 = { object3 * objectP1, objectP2, objectHeight, objectWidth };
    PlayerObjects::dstrect6 = { objectP3, objectP4, objectP5, objectP6 };

    //Scene Object 7 Air Box
    std::tie(numberSprites, objectP1, objectP2, objectHeight, objectWidth) = pob.placeObject(1, 7, NULL, NULL, NULL);
    std::tie(numberSprites, objectP3, objectP4, objectP5, objectP6) = pob.placeObjectA(1, 7, NULL, NULL, NULL);

    int object7 = (ticks / 100) % 1;
    //Set objectSprite Parameters size, height, width, position etc.
    PlayerObjects::srcrect7 = { object3 * objectP1, objectP2, objectHeight, objectWidth };
    PlayerObjects::dstrect7 = { objectP3, objectP4, objectP5, objectP6 };
}

>>>>>>> f7761ba1e1b7e59876c961ce44ead324b20db46f
