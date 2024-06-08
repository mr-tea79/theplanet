/*
PLEASE READ THE ADDING OBJECTS INSTRUCTIONS THAT I HAVE INCLUDED 
Creating a sprite object in ThePlanet step by step.pdf

This document will help you get started in adding objects to the game.

*/


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
#include "AI.h"
#include "ObjectPositions.h"


using namespace brightland;

//Global
static std::string sceneBackground;
static int SPRITE_SIZE;
static int xPosition;
static int yPosition;
static int playerMessage;

std::string PlayerObjects::items = "";
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

//Player Blinking
SDL_Rect PlayerObjects::srcrect10;
SDL_Rect PlayerObjects::dstrect10;

ObjectPositions op;  


void PlayerObjects::SetSpritePosition(int x, int y) {
   
    Scene1::gdSprite.x = x;
    Scene1::gdSprite.y = y;
  

}

//HoverObjects will display information about objects of interest when the user hovers over them.
std::string PlayerObjects::HoverObjects(int x, int y, int scene,int gd, int gy) {

    std::string gameObject;
    Inventory inv;
    int i = 0;
    int items = 0;

    std::string message;

    //Menu Hover Messages
 
    if (Scene1::mouseMoveYPercent >= 86 && Scene1::mouseMoveYPercent <= 90 && Scene1::mouseMoveXPercent >= 18 && Scene1::mouseMoveXPercent <= 24) {
        message = "Use";
    }


    if (Scene1::mouseMoveYPercent >= 86 && Scene1::mouseMoveYPercent <= 89 && Scene1::mouseMoveXPercent >= 6 && Scene1::mouseMoveXPercent <= 16) {
        Scene1::hoverSound = 1;
        message = "Pick up";
    }
  
    if (Scene1::mouseMoveYPercent >= 94 && Scene1::mouseMoveYPercent <= 98 && Scene1::mouseMoveXPercent >= 17 && Scene1::mouseMoveXPercent <= 23) {
        message = "Open";
    }


    if (Scene1::mouseMoveYPercent >= 80 && Scene1::mouseMoveYPercent <= 83 && Scene1::mouseMoveXPercent >= 5 && Scene1::mouseMoveXPercent <= 14) {
        message = "Look";
    }

    if (Scene1::mouseMoveYPercent >= 94 && Scene1::mouseMoveYPercent <= 97 && Scene1::mouseMoveXPercent >= 6 && Scene1::mouseMoveXPercent <= 16) {
        message = "Pull";
    }

    //Inventory Hover Messages 
    if(Scene1::SceneBackground !="0") {
        if (Scene1::mouseMoveYPercent >= 86 && Scene1::mouseMoveYPercent <= 88 && Scene1::mouseMoveXPercent >= 68 && Scene1::mouseMoveXPercent <=70) {
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

        if (x >= 753 && x <= 827 && y >= 699 && y <= 788) {
            if (inv.checkItem("Disc") != 0)
                message = Scene1::actionStatement + " Disc";
        }



       //////////////////////////////////// Scene 1 Outside Wreakage ////////////////////////////////////////////////////////////////////////
       
        Scene1::SceneBackground == "1" && Scene1::mouseMoveYPercent >= 1 && Scene1::mouseMoveYPercent <= 16 && Scene1::mouseMoveXPercent >= 5 && Scene1::mouseMoveXPercent <= 14 ? message = Scene1::actionStatement + " The moon" : "";
        Scene1::SceneBackground == "1" && Scene1::mouseMoveYPercent >= 37 && Scene1::mouseMoveYPercent <= 48 && Scene1::mouseMoveXPercent >= 55 && Scene1::mouseMoveXPercent <= 68 ? message = Scene1::actionStatement + " Wreckage" : "";
   
        Scene1::SceneBackground == "1" && (Scene1::mouseMoveYPercent >= 64 && Scene1::mouseMoveYPercent <= 69 && Scene1::mouseMoveXPercent >= 54 && Scene1::mouseMoveXPercent <= 58) && inv.checkItem("PDA") != 1 ? message = Scene1::actionStatement + " White plastic thingy" : "";
        
        ////////////////////////////////////// Scene 1 Transitions  ///////////////////////////////////////////////////////////////////////////////
        if (Scene1::SceneBackground == "1" && Scene1::mouseMoveYPercent >= 42 && Scene1::mouseMoveYPercent <= 50 && Scene1::mouseMoveXPercent >= 73 && Scene1::mouseMoveXPercent <= 75) {
            message = "Enter Wreckage";
            Scene1::SceneTransitionStatement = "Wreckage";
        }

        if (Scene1::SceneBackground == "1" && Scene1::mouseMoveXPercent < 42 && Scene1::mouseMoveYPercent <37 && Scene1::mouseMoveYPercent > 28) {
            message = "Head North";
            Scene1::SceneTransitionStatement = "Head North";
            
        }
        else {
            //This is important because otherwise it will override any look at actions.
          //  Scene1::SceneTransitionStatement = "";
            //JUNE 2023 I removed this because it was causing issues, keep an eye on this.
        }
 


        ////////////////////////////////// Scene 1b Inside Wreakage //////////////////////////////////////////////////////////////////////////////////////////
        Scene1::SceneBackground == "1b" && (Scene1::mouseMoveYPercent >= 36 && Scene1::mouseMoveYPercent <= 72 && Scene1::mouseMoveXPercent >= 64 && Scene1::mouseMoveXPercent <= 72) && inv.checkItem("Flag") != 1 ? message = Scene1::actionStatement + " Flag" : "";
        Scene1::SceneBackground == "1b" && (x >= ObjectPositions::TENT_X && x<= ObjectPositions::TENT_X + 40 && y >= ObjectPositions::TENT_Y - 50 && y<= ObjectPositions::TENT_Y + 50) && inv.checkItem("Tent") != 1 ? message = Scene1::actionStatement + " Self Inflating Tent" : "";
        Scene1::SceneBackground == "1b" && x > 126 && x <= 238 && y >= 306 && y <= 391 ? message = "Computer Screen" : "";
        Scene1::SceneBackground == "1b" && (x >= ObjectPositions::ATAPE_X && x <= ObjectPositions::ATAPE_X + 40 && y >= ObjectPositions::ATAPE_Y - 50 && y <= ObjectPositions::ATAPE_Y + 50) && inv.checkItem("Tape") != 1  ? message = Scene1::actionStatement + " Ape Tape" : "";

        /////////////////////////////////////////// Scene 1b Transitions  ///////////////////////////////////////////////////////////////////
        if (Scene1::SceneBackground == "1b" && x > 0 && x <= 771 && y >= 560 && y <= 595) {
            message = "Exit Wreckage";
            Scene1::SceneTransitionStatement = "Exit Wreckage";
        }

        ///////////////////////////////////// Scene 1e Rocky Path ///////////////////////////////////////////////////////////////////////////////////
        Scene1::SceneBackground == "1e" && x >= 661 && x <= 742 && y >= 365 && y <= 409 ? message = Scene1::actionStatement + " Rocks" : "";
  
        ////////////////////////////////////////// Scene 1e Transitions  //////////////////////////////////////////////////////////////
        if (Scene1::SceneBackground == "1e" && x >= 9 && x <= 51 && y >= 311 && y <= 482) {
            message = "Go back to wreckage";
            Scene1::SceneTransitionStatement = "Wreckage";
        }
           
        if (Scene1::SceneBackground == "1e" && x >= 994 && y >= 0 && y <= 570) {
            message = "Head east";
            Scene1::SceneTransitionStatement = "East";
        }

        /////////////////////////////////////// Scene 1f Sandy Clearing //////////////////////////////////////////////////////////////////
        Scene1::SceneBackground == "1f" && x >= 370 && x <= 916 && y >= 220 && y <= 283 ? message = Scene1::actionStatement + " Sandy clearing" : "";
        Scene1::SceneBackground == "1fb" && x >= 581 && x <= 860 && y >= 117 && y <= 248 ? message = "Enter Tent" : "";
        Scene1::SceneBackground == "1fb" && x >= 1000 && y >= 390 && y <= 586 ? message = "Head East" : "";

        ////////////////////////////////////////// Scene 1f Transitions  //////////////////////////////////////////////////////////////
        if (Scene1::SceneBackground == "1f" && x >= 0 && x <= 6 && y >= 139 && y <= 582) {
            message = "Go west";
            Scene1::SceneTransitionStatement = "West";
        }

        ////////////////////////////////////////////// Scene 1da Inside Tent ////////////////////////////////////////////////////////////////////
        Scene1::SceneBackground == "1da" && x >= 0 && x <= 100 && y >= 390 && y <= 586 ? message = "Leave camp" : "";
        Scene1::SceneBackground == "1da" && x >= 613 && x <= 640 && y >= 335 && y <= 378 ? message = Scene1::actionStatement + " Stuffed toy" : "";
        Scene1::SceneBackground == "1da" && x >= 523 && x <= 616 && y >= 502 && y <= 586 && boxOpened != 1 ? message = Scene1::actionStatement + " Cardboard box" : "";
        Scene1::SceneBackground == "1da" && x >= 850 && x <= 958 && y >= 391 && y <= 482 ? message = Scene1::actionStatement + " Oxygenator 5000" : "";
        Scene1::SceneBackground == "1db" && x >= 0 && x <= 800 && y >= 459 && y <= 570 ? message = "Leave Sofa" : "";
        Scene1::SceneBackground == "1da" && x >= 245 && x <= 295 && y >= 353 && y <= 414 ? message = "Sofa" : "";
        Scene1::SceneBackground == "1da" && x <= 971 && x >= 843 && y < 231 && y > 142 ? message = Scene1::actionStatement + " Spaceflix" : "";
        Scene1::SceneBackground == "1da" && x <= 411 && x >= 364 && y < 402 && y > 396 ? message = Scene1::actionStatement + " Pot plant" : "";
        Scene1::SceneBackground == "1da" && x >= 421 && x < 437 && y >= 373 && y <= 410 && inv.checkItem("Battery Lantern") != 1 ? message = Scene1::actionStatement + " Battery Lantern" : "";
        Scene1::SceneBackground == "1da" && x >= 554 && x < 591 && y >= 515 && y <= 572 && inv.checkItem("Pipe") != 1 && boxOpened == 1 ? message = Scene1::actionStatement + " Plastic Pipe" : "";

        ////////////////////////////////////////// Scene 3a Birdseye view of planet //////////////////////////////////////////////////////////////////////////////////
        Scene1::SceneBackground == "3a" && x <= 268 && y >= 347 ? message = "Rock face" : "";
        Scene1::SceneBackground == "3a" && x >= 952 && x < 968 && y >= 353 && y <= 369 ? message = "Camp" : "";
        Scene1::SceneBackground == "3a" && x >= 433 && x < 463 && y >= 158 && y <= 174 ? message = Scene1::actionStatement + " Crash site" : "";
        Scene1::SceneBackground == "3a" && x >= 878 && x <= 919 && y < 148 && y > 121 && Scene1::secretTrigger > 0 ? message = Scene1::actionStatement + " Point of interest" : "";
        Scene1::SceneBackground == "3a" && x > 662 && x <= 812 && y <= 71 ? message = Scene1::actionStatement + " Crators" : "";
      
        /////////////////////////////////////////// Scene 3b Rock Face //////////////////////////////////////////////////////
        Scene1::SceneBackground == "3b" && x >= 756 && x < 830 && y >= 28 && y <= 92 ? message = "Enter cave" : "";
        Scene1::SceneBackground == "3b" && x >= 860 && y < 500 && y > 400 ? message = "Leave Rocky Cliff" : "";

        /////////////////////////////////////// Scene 3c Inside Cave DARK ///////////////////////////////////////////////////////////////////////////
        Scene1::SceneBackground == "3c" && x >= 107 && x <= 201 && y >= 400 && y <= 473 ? message = Scene1::actionStatement + " Smooth surface" : "";
        Scene1::SceneBackground == "3c" && x <= 37 && y >= 376 && y <= 432 ? message = "Exit Cave" : "";

        ////////////////////////////////////////// Scene 3d Inside Cave with Light On ///////////////////////////////////////////////////////////
        Scene1::SceneBackground == "3d" && x >= 561 && x <= 627 && y < 512 && y > 496 ? message = Scene1::actionStatement + " Marks in dirt" : "";

        Scene1::SceneBackground == "3d" && x <= 37 && y >= 376 && y <= 432 ? message = "Exit Cave" : "";

        Scene1::SceneBackground == "3d" && x <= 37 && y >= 376 && y <= 432 ? message = "Exit Cave" : "";
        Scene1::SceneBackground == "3d" && x >= 557 && x <= 618 && y >= 404 && y <= 476 ? message = Scene1::actionStatement + " Human remains" : "";
        Scene1::SceneBackground == "3d" && x >= 431 && x <= 527 && y >= 102 && y <= 125 ? message = Scene1::actionStatement + " Flying saucer drawing" : "";
        Scene1::SceneBackground == "3d" && x >= 579 && x <= 619 && y >= 96 && y <= 133 ? message = Scene1::actionStatement + " Planet drawing" : "";
        Scene1::SceneBackground == "3d" && x >= 677 && x <= 738 && y >= 78 && y <= 192 ? message = Scene1::actionStatement + " Large Alien drawing" : "";
        Scene1::SceneBackground == "3d" && x >= 768 && x <= 810 && y >= 154 && y <= 212 ? message = Scene1::actionStatement + " Human drawing" : "";
        Scene1::SceneBackground == "3d" && x >= 722 && x <= 942 && y >= 25 && y <= 83 ? message = Scene1::actionStatement + " Alien solar system drawing" : "";
        Scene1::SceneBackground == "3d" && x >= 788 && x <= 820 && y >= 258 && y <= 285 ? message = Scene1::actionStatement + " Artifact drawing" : "";
        Scene1::SceneBackground == "3d" && x >= 837 && x <= 910 && y >= 179 && y <= 254 ? message = Scene1::actionStatement + " Cave door drawing" : "";
        Scene1::SceneBackground == "3d" && Scene1::secretTrigger > 2 && x <= 1000 && x >= 959 && y < 402 && y > 292 ? message = Scene1::actionStatement + " Drawing" : "";
        Scene1::SceneBackground == "3d" && x <= 1009 && x >= 948 && y < 457 && y > 409 ? message = Scene1::actionStatement + " Strange peg" : "";
       

        /////////////////////////////////////// Scene 3e Looking at Map ///////////////////////////////////////////////////////////////////////////
        Scene1::SceneBackground == "3e" && x >= 183 && x <= 236 && y < 429 && y > 382 ? message = Scene1::actionStatement + " Big X" : "";
        Scene1::SceneBackground == "3e" && x >= 753 && x <= 904 && y < 341 && y > 230 ? message = Scene1::actionStatement + " Location of interest" : "";
        Scene1::SceneBackground == "3e" && x >= 548 && x <= 716 && y < 306 && y > 213 ? message = Scene1::actionStatement + " Odd formation" : "";


        //////////////////////////////////////// Scene 3f Secret Crator ///////////////////////////////////////////////////////////////////////////////////////
        Scene1::SceneBackground == "4a" && x <= 442 && x >= 319 && y < 198 && y > 127 ? message = Scene1::actionStatement + " Mound" : "";
        Scene1::SceneBackground == "4a" && x <= 837 && x >= 699 && y < 504 && y > 483 && Scene1::secretTrigger < 5 ? message = Scene1::actionStatement + " Markings" : "";
        Scene1::SceneBackground == "4a" && x <= 851 && x >= 729 && y < 470 && y > 406 ? message = Scene1::actionStatement + " Entrance" : "";
        
     
        /////////////////////////////////////// Scene 3f Outside Alien structure /////////////////////////////////////////////////////////////////////////////////////////////////
        Scene1::SceneBackground == "3f" && x <= 510 && x >= 490 && y < 262 && y > 247 && Scene1::secretTrigger == 2 && inv.checkItem("Disc") != 1 ? message = Scene1::actionStatement + " Sparkling object" : "";
        Scene1::SceneBackground == "3f" && x <= 560 && x >= 483 && y < 262 && y > 202 && Scene1::secretTrigger < 2 ? message = Scene1::actionStatement + " Loose rocks" : "";
        Scene1::SceneBackground == "3f" && x <= 20 && y < 414 && y > 250 ? message = Scene1::actionStatement + " Leave crator" : "";
  
  
}

    return message;
}

/* Make objects disappear when picked up. */
std::string PlayerObjects::DestroyObjects(std::string gameObject) {

    std::string objectToDestroy;

    if (gameObject == "PDA") {
        SDL_DestroyTexture(Textures::PDATexture);
        objectToDestroy = "1";
    }

    if (gameObject == "Tape") {
        SDL_DestroyTexture(Textures::objectTexture4);
        objectToDestroy = "3";
    }

    if (gameObject == "Flag") {
        SDL_DestroyTexture(Textures::FlagTexture);
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


//This is used for menu object interaction (Picking up).
//1.Check which scene 
//2.Check player current location is nearby object 
//3.Check item hasn't already been picked up.
//4. If item hasn't been already picked up, set message to the item.
std::string PlayerObjects::ObjectInteractionM1(int playerCurrentLocationX, int playerCurrentLocationY) {

    std::string message;
  

    if (Scene1::SceneBackground == "1" && playerCurrentLocationX >= ObjectPositions::PDA_X - 70 && items.find("PDA") == std::string::npos){
        message = "PDA";
    }
    else if (Scene1::SceneBackground == "1b" && playerCurrentLocationX >= ObjectPositions::FLAG_X - 190 && items.find("Flag") == std::string::npos) {
        message = "Flag";
        
    }
    else if (Scene1::SceneBackground == "1b" && playerCurrentLocationX >= ObjectPositions::ATAPE_X - 70 && items.find("Tape") == std::string::npos) {
        message = "Tape";
       
    }
    else if (Scene1::SceneBackground == "1b" && playerCurrentLocationX >= ObjectPositions::TENT_X - 70 ) {
        message = "Tent";
    }

    else if (Scene1::SceneBackground == "1da" && playerCurrentLocationX >= 437 && playerCurrentLocationX <= 530) {
        message = "Pipe";
    }

    else if (Scene1::SceneBackground == "1da" && playerCurrentLocationX >= 300 && playerCurrentLocationX <= 411) {
        message = "Battery Lantern";
    }
    else if (Scene1::SceneBackground == "3f" && playerCurrentLocationX >= 300 && playerCurrentLocationX <= 511) {
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
        //Disc
        return  std::make_tuple(NULL, 5, NULL, 20, 41);
    }
    if (scene == 1 && objectID == 10) {
        //Blinking eyes
        return  std::make_tuple(NULL, 122, NULL, 140, 500);
    }

    return  std::make_tuple(scene, objectID, b, c, d);
}

/* 
Here is where you actually specify where you want to place the object and how big you want that object to be.
The returned values are: (Number of sprites in the iamge, x position of the object, y postion of the object, desired width of the object, desired height of the object)
If you set number of sprites to 1, that means its not animated. If you increase the number of sprites value it will assume there are multiple sprites in the image.

*/


std::tuple<int, int, int, int, int> PlayerObjects::placeObject(int scene, int objectID, int b, int c, int d) {
    
    //EXAMPLE:
    //Return std::make_tuple(Number of animation sprites (1) means no animation, Location X, Location Y, Image width, Image Height)

    if (scene == 1 && objectID == 1) {
        //PDA
       // return  std::make_tuple(1, 685, 523, 20, 14);
      
        return  std::make_tuple(1, ObjectPositions::PDA_X, ObjectPositions::PDA_Y, ObjectPositions::PDA_SX, ObjectPositions::PDA_SY);
    }
    if (scene == 1 && objectID == 2) {
        //Flag Rolled up   
        return  std::make_tuple(1, ObjectPositions::FLAG_X, ObjectPositions::FLAG_Y, ObjectPositions::FLAG_SX, ObjectPositions::FLAG_SY);
    }
    if (scene == 1 && objectID == 3) {
        //Star
        return  std::make_tuple(3, 400, 30, 8, 40);
    }
    if (scene == 1 && objectID == 4) {
        //return  std::make_tuple(1, 300, 430, 60, 60);
        return  std::make_tuple(1, op.CalcObjectXAbsolutePosition(35, "ATAPE_X"), op.CalcObjectYAbsolutePosition(62, "ATAPE_Y"),60, 60);
    }
    if (scene == 1 && objectID == 5) {     
        return  std::make_tuple(1, op.CalcObjectXAbsolutePosition(54, "TENT_X"), op.CalcObjectYAbsolutePosition(41, "TENT_Y"), 97, 149);
       // return  std::make_tuple(1, 300, 97, 149);
    }
    if (scene == 1 && objectID == 6) {
        //Closed Box
        return  std::make_tuple(1, 520, 500, 100, 96);
    }
    if (scene == 1 && objectID == 7) {
        //Air Box
        return  std::make_tuple(1, 838, 380, 140, 118);
    }
    if (scene == 1 && objectID == 8) {
        //Lantern
        return  std::make_tuple(1, 419, 372, 20, 41);  //HERE IS WHERE YOU SET DIMENSIONS AND POSITION OF THE OBJECT.
    }
    if (scene == 1 && objectID == 9) {
        //Sparkly object        (Number of frames, x,y,w,h)
        return  std::make_tuple(33, 499, 252, 8, 8);  //HERE IS WHERE YOU SET DIMENSIONS AND POSITION OF THE OBJECT.
    }
    if (scene == 1 && objectID == 10) {
       //Blinking eyes.
        if (Scene1::SPRITE_SIZE >= 160 && Scene1::SPRITE_SIZE <170 && Scene1::SceneBackground !="01" && Scene1::SceneBackground !="0"  ) {
            return  std::make_tuple(40, Scene1::gdSprite.x + 90, Scene1::gdSprite.y + 44, 49, 25);  
        }
        else if (Scene1::SPRITE_SIZE >= 170 && Scene1::SPRITE_SIZE <=240 && Scene1::SceneBackground != "01" && Scene1::SceneBackground != "0") {
            return  std::make_tuple(40, Scene1::gdSprite.x + 70, Scene1::gdSprite.y + 56, 48, 25);  
        }
        else if (Scene1::SPRITE_SIZE > 240 && Scene1::SceneBackground != "01" && Scene1::SceneBackground != "0") {
            std::cout << "YES" << std::endl; 
            //                      delay                                           // y   w  d
            return  std::make_tuple(40, Scene1::gdSprite.x + 75, Scene1::gdSprite.y + 71, 71, 38);
        }
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

    int object1 = (ticks / 100) % numberSprites; 
    PlayerObjects::srcrect = { object1 * objectP1, objectP2, objectHeight, objectWidth };
    PlayerObjects::dstrect = { objectP3, objectP4, objectP5, objectP6 };

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    //Build object parameters.                                                                //2 means object 2  and so on...
    std::tie(numberSprites, objectP1, objectP2, objectHeight, objectWidth) = pob.ObjectSettings(1, 2, NULL, NULL, NULL);
    std::tie(numberSprites, objectP3, objectP4, objectP5, objectP6) = pob.placeObject(1, 2, NULL, NULL, NULL);

    int object2 = (ticks / 100) % numberSprites;
    PlayerObjects::srcrect2 = { object2 * objectP1, objectP2, objectHeight, objectWidth };
    PlayerObjects::dstrect2 = { objectP3, objectP4, objectP5, objectP6 };

    //Scene Object 3 (Flashing lights)
    std::tie(numberSprites, objectP1, objectP2, objectHeight, objectWidth) = pob.ObjectSettings(1, 3, NULL, NULL, NULL);
    std::tie(numberSprites, objectP3, objectP4, objectP5, objectP6) = pob.placeObject(1, 3, NULL, NULL, NULL);

    int object3 = (ticks / 100) % numberSprites;
    PlayerObjects::srcrect3 = { object3 * objectP1, objectP2, objectHeight, objectWidth };
    PlayerObjects::dstrect3 = { objectP3, objectP4, objectP5, objectP6 };

    //Scene Object 4.......
    std::tie(numberSprites, objectP1, objectP2, objectHeight, objectWidth) = pob.ObjectSettings(1, 4, NULL, NULL, NULL);
    std::tie(numberSprites, objectP3, objectP4, objectP5, objectP6) = pob.placeObject(1, 4, NULL, NULL, NULL);

    //Set it to 1 for no animation.
    int object4 = (ticks / 100) % numberSprites;
    PlayerObjects::srcrect4 = { object3 * objectP1, objectP2, objectHeight, objectWidth };
    PlayerObjects::dstrect4 = { objectP3, objectP4, objectP5, objectP6 };

    //Scene Object 5.......
    std::tie(numberSprites, objectP1, objectP2, objectHeight, objectWidth) = pob.ObjectSettings(1, 5, NULL, NULL, NULL);
    std::tie(numberSprites, objectP3, objectP4, objectP5, objectP6) = pob.placeObject(1, 5, NULL, NULL, NULL);

    int object5 = (ticks / 100) % numberSprites;
    PlayerObjects::srcrect5 = { object3 * objectP1, objectP2, objectHeight, objectWidth };
    PlayerObjects::dstrect5 = { objectP3, objectP4, objectP5, objectP6 };

    //Scene Object 6.......
    std::tie(numberSprites, objectP1, objectP2, objectHeight, objectWidth) = pob.ObjectSettings(1, 6, NULL, NULL, NULL);
    std::tie(numberSprites, objectP3, objectP4, objectP5, objectP6) = pob.placeObject(1, 6, NULL, NULL, NULL);

    int object6 = (ticks / 100) % numberSprites;
    PlayerObjects::srcrect6 = { object3 * objectP1, objectP2, objectHeight, objectWidth };
    PlayerObjects::dstrect6 = { objectP3, objectP4, objectP5, objectP6 };

    //Scene Object 7 Air Box
    std::tie(numberSprites, objectP1, objectP2, objectHeight, objectWidth) = pob.ObjectSettings(1, 7, NULL, NULL, NULL);
    std::tie(numberSprites, objectP3, objectP4, objectP5, objectP6) = pob.placeObject(1, 7, NULL, NULL, NULL);

    int object7 = (ticks / 100) % numberSprites;
    PlayerObjects::srcrect7 = { object3 * objectP1, objectP2, objectHeight, objectWidth };
    PlayerObjects::dstrect7 = { objectP3, objectP4, objectP5, objectP6 };

    //Scene Object 8 Lantern
    std::tie(numberSprites, objectP1, objectP2, objectHeight, objectWidth) = pob.ObjectSettings(1, 8, NULL, NULL, NULL);
    std::tie(numberSprites, objectP3, objectP4, objectP5, objectP6) = pob.placeObject(1, 8, NULL, NULL, NULL);

    int object8 = (ticks / 100) % numberSprites;
    PlayerObjects::srcrect8 = { object3 * objectP1, objectP2, objectHeight, objectWidth };
    PlayerObjects::dstrect8 = { objectP3, objectP4, objectP5, objectP6 };

    //Scene Object 9 (Sparkly thing)
    std::tie(numberSprites, objectP1, objectP2, objectHeight, objectWidth) = pob.ObjectSettings(1, 9, NULL, NULL, NULL);
    std::tie(numberSprites, objectP3, objectP4, objectP5, objectP6) = pob.placeObject(1, 9, NULL, NULL, NULL);

    int object9 = (ticks / 100) % numberSprites;
    PlayerObjects::srcrect9 = { object9 * objectP1, objectP2, objectHeight, objectWidth };
    PlayerObjects::dstrect9 = { objectP3, objectP4, objectP5, objectP6 };

    //Scene Object 10 (Blinking eyes)
    std::tie(numberSprites, objectP1, objectP2, objectHeight, objectWidth) = pob.ObjectSettings(1, 10, NULL, NULL, NULL);
    std::tie(numberSprites, objectP3, objectP4, objectP5, objectP6) = pob.placeObject(1, 10, NULL, NULL, NULL);

    int object10 = (ticks / 100) % numberSprites;
    //Set objectSprite Parameters size, height, width, position etc.
    PlayerObjects::srcrect10 = { object10 * objectP1, objectP2, objectHeight, objectWidth };
    PlayerObjects::dstrect10 = { objectP3, objectP4, objectP5, objectP6 };


}



