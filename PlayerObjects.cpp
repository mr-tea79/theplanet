#include <iostream>
#include "PlayerObjects.h"
#include "Scene1.h"
#include <tuple>
#include <string>
#include "Inventory.h"
#include "Scene1.h"


using namespace brightland;

//Global
static std::string sceneBackground;
static int SPRITE_SIZE;
static int xPosition;
static int yPosition;
static int playerMessage;
static int inv3Used;  //Duct Tape


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

    //Inventory Hover Messages (Too much overhead on performance. Needs looking at.)
    /*

    if (inv.checkItem("PDA") !=0 && x >= 696 && x <=736 && y >=653 && y <=687  ) {
        message = "PDA";
    }

    if (inv.checkItem("Tent") != 0 && x >= 764 && x <= 817 && y >= 695 && y <= 755) {
        message = "Self Inflating Tent";
    }

    if (inv.checkItem("Flag") != 0 && x >= 771 && x <= 821 && y >= 796 && y <= 798) {
        message = "Flag";
    }

    if (inv.checkItem("Tape") != 0 && x >= 888 && x <= 915 && y >= 653 && y <= 684) {
        message = "Duct Tape";
    }

    */


    //Scene Hover Messages

    if (Scene1::SceneBackground == "1da" && x >= 523 && x <= 616 && y >= 502 && y <= 586) {
        message = "Carboard box";
    }

    if (Scene1::SceneBackground == "1da" && x >= 850 && x <= 958 && y >= 391 && y <= 482) {
        message = "Oxygenator 5000";
    }

    if (Scene1::SceneBackground == "1db" && x >= 0 && x <= 800 && y >= 459 && y <= 570) {
        message = "Leave Sofa";
    }

    if (Scene1::SceneBackground == "1da" && x >= 245 && x <= 295 && y >= 353 && y <= 414) {
        message = "Sit on the sofa";
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



    if (Scene1::SceneBackground == "1" && x > 0 && x <= 552 && y > 204 && y < 235 && gy <360) {
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





    return message;
}

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



    return objectToDestroy;
}

std::string PlayerObjects::ObjectInteraction(int x, int y, int playerCurrentLocationX, int playerCurrentLocationY) {

    //Check database if item has been picked up.
    Inventory inv;

    std::string message;

    if(Scene1::SceneBackground == "1da" && x >= 523 && x <= 616 && y >= 502 && y <= 586 && playerCurrentLocationX >= 435) {

        message = "It's a closed cardboard box.";

    }

    if (Scene1::SceneBackground == "1da" && x >= 850 && x <= 958 && y >= 391 && y <= 482 && playerCurrentLocationX >=600) {
        message = "This is what I need to top up my suit, but the pipe is missing.";
    }

    if (Scene1::SceneBackground == "1db" && x >= 0 && x <= 800 && y >= 459 && y <= 570) {
        
        Scene1::SceneBackground = "1da";
        Scene1::SPRITE_SIZE = 180;
        Scene1::xPosition = 280;
        Scene1::yPosition = 410;
        message = "Scene1d";
    }


    if (Scene1::SceneBackground == "1da" && x >= 245 && x <= 295 && y >= 353 && y <= 414 && playerCurrentLocationX <= 260) {
        Scene1::SceneBackground = "1db";
        Scene1::SPRITE_SIZE = 0;
      

        message = "Scene1d2";
    }

    if (Scene1::SceneBackground == "1fb" && x >= 581 && x <= 860 && y >= 117 && y <= 248 && playerCurrentLocationX >= 440 && playerCurrentLocationY <=308) {
        Scene1::SceneBackground = "1da";
        Scene1::SPRITE_SIZE = 180;
        Scene1::xPosition = 600;
        Scene1::playerMessage = 6;

        message = "Scene1d";
    }

    if (Scene1::SceneBackground == "1fa" && x >= 793 && x <= 959 && y >= 474 && y <= 535) {
       
        Scene1::SceneBackground = "1fb";
        Scene1::SPRITE_SIZE = 120;
        Scene1::xPosition = 400;

        message = "Scene1fb";
    }

    if (Scene1::SceneBackground == "1" && x >= 759 && x <= 771 && y >= 325 && y <= 375 && playerCurrentLocationX >= 700 ) {
        std::cout << "Entering Wreckage" << std::endl;
        Scene1::SceneBackground = "1b";
        Scene1::SPRITE_SIZE = 200;
        Scene1::xPosition = 400;

        message = "Scene1b";
    }

    if (Scene1::SceneBackground == "1f" && x >= 0 && x <= 6 && y >= 139 && y <= 582 && playerCurrentLocationX <6) {
        std::cout << "Going West" << std::endl;
        Scene1::SceneBackground = "1e";
        Scene1::SPRITE_SIZE = 50;
        Scene1::yPosition = 376;
        Scene1::xPosition = 400;

        message = "Scene1e";
    }



    if (Scene1::SceneBackground == "1b" && x > 0 && x <= 771 && y >= 570 && y <= 595) {
        message = "Exit Wreckage";
        Scene1::SceneBackground = "1";
        Scene1::SPRITE_SIZE = 110;
        message = "Scene1";
    }


    if (Scene1::SceneBackground == "1b" && x > 126 && x <= 238 && y >= 306 && y <= 391 &&playerCurrentLocationX < 300) {
       
        Scene1::SceneBackground = "1c";
        message = "Computer Screen";
    }

    if (Scene1::SceneBackground == "1d" && x > 126 && x <= 238 && y >= 306 && y <= 391) {

        Scene1::SceneBackground = "1c";
        message = "Computer Screen";
    }

    if (Scene1::SceneBackground == "1c" && x > 345 && x <= 488 && y >= 541 && y <= 585) {

        Scene1::SceneBackground = "1d";
        message = "Computer Screen";
    }

    if (Scene1::SceneBackground == "1c"  && x > 36 && x <= 172 && y >= 544 && y <= 582) {

        Scene1::SceneBackground = "1b";
        Scene1::SPRITE_SIZE = 200;
        message = "Scene1b";
      
    }

    if (Scene1::SceneBackground == "1d" && x > 36 && x <= 172 && y >= 544 && y <= 582) {

        Scene1::SceneBackground = "1b";
        Scene1::SPRITE_SIZE = 200;
        message = "Scene1b";

    }

    if (Scene1::SceneBackground == "1f" && x >= 370 && x <= 916 && y >= 220 && y <= 283 && playerCurrentLocationX <=900 && playerCurrentLocationX >300  && playerCurrentLocationY <= 360) {
        message = "It's very flat here.";
    }



    if (Scene1::SceneBackground == "1" && x >= 52 && x <= 148 && y >= 14 && y <= 111 && playerCurrentLocationX <= 800) {

        message = "This is one strange looking Place.";
    }

    if (Scene1::SceneBackground == "1e" && x >= 661 && x <= 742 && y >= 365 && y <= 409 && playerCurrentLocationX >= 640) {

        message = "Some rocks, nothing interesting.";
    }

    if (Scene1::SceneBackground == "1e" && x >= 9 && x <= 51 && y >= 311 && y <= 482 && playerCurrentLocationX <=13) {
        Scene1::SceneBackground = "1";
        Scene1::SPRITE_SIZE = 120;
        Scene1::yPosition = 10;
        message = "Scene1";
        
    }

    if (Scene1::SceneBackground == "1e" && x >= 994 && y >= 0 && y <= 570 && playerCurrentLocationX >=994) {
       

        Scene1::SceneBackground = "1f";
        Scene1::SPRITE_SIZE = 120;
        Scene1::yPosition = 376;
      
        message = "Scene1f";
    }


    //Check if PDA is picked up and Oxygen is fixed.
    if (Scene1::SceneBackground == "1" && x > 0 && x <= 771 && y > 204 && y < 259 && playerCurrentLocationY <360 ) {
        if (inv.checkItem("PDA") && Scene1::inv3Used == 1) {
            Scene1::SceneBackground = "1e";
            Scene1::SPRITE_SIZE = 50;
            Scene1::yPosition = 376;
            message = "Scene1e";
            Scene1::playerMessage = 5;
        }
            
        else
            message = "I'm leaking Oxygen, are you crazy!?";
    }


    if (Scene1::SceneBackground == "1" && x >= 560 && x <= 612 && y >= 288 && y <= 350 && playerCurrentLocationX >= 300 && playerCurrentLocationX <= 600) {
        message = "Anti matter engine. This ship isn't going nowhere!";
    }

    if (Scene1::SceneBackground == "1" && x >= 681 && x <= 700 && y >= 515 && y <= 542 && playerCurrentLocationX >= 622 && playerCurrentLocationX <= 736 && inv.checkItem("PDA") != 1) {

        message = "That's my PDA";
    }


    if (Scene1::SceneBackground == "1b" && x >= 320 && x <= 390 && y >= 433 && y <= 474 && playerCurrentLocationX >= 310 && playerCurrentLocationX <= 394 && inv.checkItem("Tape") != 1) {

        message = "Oooh Ape Tape!";
    }

    if (Scene1::SceneBackground == "1b" && x >= 538 && x <= 580 && y >= 313 && y <= 441 && playerCurrentLocationX >= 406 && playerCurrentLocationX <= 496 && inv.checkItem("Tent") != 1) {

        message = "Does exactly what it says on the tin";

    }

   


    return message;
}

//This is used for menu object interaction.
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

    /*
    if (scene == 1 && playerCurrentLocationX >= 936 && playerCurrentLocationX <= 998) {
        message = "Halloween Mask";
    }

    if (scene == 1 && playerCurrentLocationX >= 78 && playerCurrentLocationX <= 112) {
        message = "Rope";
    }
    */
    return message;
}



std::tuple<int, int, int, int, int> PlayerObjects::placeObject(int scene, int objectID, int b, int c, int d) {
    /**/

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



    return  std::make_tuple(scene, objectID, b, c, d);
}

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
        //Coins
        // Object position and size of object (number of sprites,x,y, DESIRED DISPLAY WIDTH, DESIRED DISPLAY HEIGHT)
        return  std::make_tuple(9, 400, 30, 15, 40);
    }


    if (scene == 1 && objectID == 4) {
        //Coins
        // Object position and size of object (number of sprites,x,y, DESIRED DISPLAY WIDTH, DESIRED DISPLAY HEIGHT)
        return  std::make_tuple(1, 300, 430, 60, 60);
    }
    if (scene == 1 && objectID == 5) {
        //Coins
        // Object position and size of object (number of sprites,x,y, DESIRED DISPLAY WIDTH, DESIRED DISPLAY HEIGHT)
        return  std::make_tuple(1, 520, 300, 97, 149);
    }
    if (scene == 1 && objectID == 6) {
        //Closed Box
        // Object position and size of object (number of sprites,x,y, DESIRED DISPLAY WIDTH, DESIRED DISPLAY HEIGHT)
        return  std::make_tuple(1, 520, 500, 100, 96);
    }

    return  std::make_tuple(scene, objectID, b, c, d);
}

/*
int PlayerObjects::PlayerObject(int x, int y, int scene) {
    int objectID;

    if (scene == 1) {

        if (x < 200 && y < 200) {
            return objectID = 1;
        }

    }
   


    return 0;

}
 */