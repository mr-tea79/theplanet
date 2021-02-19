#include "MenuInteraction.h"
#include <SDL.h>
#include <iostream>
#include "Scene1.h"
#include "Textures.h"


using namespace brightland;

//Sprite Action Texturess
SDL_Surface* spriteAction = NULL;
SDL_Surface* spriteAction2 = NULL;
SDL_Surface* spriteAction3 = NULL;


static std::string useStatement;
static std::string openStatement;
static std::string lookStatement;
static std::string pickUpStatement;
static std::string actionStatement;
static std::string sceneBackground;
static int inv3used;
static int inv4used;

static int playerMessage;



void MenuInteraction::LoadActionTextures() {
  
    spriteAction = IMG_Load("PlayerMovement/ThePlanet/spriteAction1.png");
    spriteAction2 = IMG_Load("PlayerMovement/ThePlanet/spritePipe.png");
 
}


std::string MenuInteraction::MenuAction(int x, int y, int gd, int gy, int mInteraction, SDL_Texture* spriteTexture, SDL_Renderer* renderer, SDL_Surface* spriteDown1, std::string menuMessage) {

    std::string actionMessage;

    PlayerObjects pob;
    Inventory inv;

    if (x > 57 && x < 145 && y > 621 && y < 647) {
        actionStatement = Scene1::actionStatement = "Look at";
        actionMessage = "Look at what?";
        lookStatement = "";

    }

    if (x > 61 && x < 146 && y > 643 && y < 690) {
        actionStatement = Scene1::actionStatement = "Pick up";
        actionMessage = "Pick up what?";
        pickUpStatement = "";

    }

    if (x > 190 && x < 227 && y > 676 && y < 690) {
        actionStatement = Scene1::actionStatement = "Use";
        actionMessage = "Use what?";
        useStatement = "";
    }

    return actionMessage;
}



std::string MenuInteraction::Look(int x, int y, int gd, int gy, int mInteraction, SDL_Texture* spriteTexture, SDL_Renderer* renderer, SDL_Surface* spriteDown1, SDL_Surface* spriteBack, std::string menuMessage) {  
    std::string lookMessage;

    PlayerObjects pob;
    Inventory inv;
    int n = lookStatement.length();

    if (n < 8) //Don't override hover if a pick up statement has been selected. This is important, otherwise player will pick up anything within range no matter what you chose to pick up.
        lookStatement = pob.HoverObjects(x, y, 1, gd, gy);
   
        if (gy > 300 && gy < 340 && lookStatement== "Look at Wreckage") {
            lookMessage = "That's one of the engines.";
            SDL_DestroyTexture(spriteTexture);
            SDL_CreateTextureFromSurface(renderer, spriteBack);
            Scene1::action = 1;
            Scene1::actionStatement = "";
            lookStatement = "";
            Scene1::sceneHalt = 1;
        }

        if (gd >= 622 && gd <= 651 && gy > 425 && inv.checkItem("PDA") != 1 && lookStatement == "Look at White plastic thingy") {

            lookMessage = "That's my PDA";
            Scene1::actionStatement = "";
            lookStatement = "";
            Scene1::sceneHalt = 1;
        }
    
       
        if (lookStatement == "Look at The moon") {
           
            lookMessage = "Very Earthlike";
            SDL_DestroyTexture(spriteTexture);
            SDL_CreateTextureFromSurface(renderer, spriteBack);
            Scene1::action = 1;
            Scene1::actionStatement = "";
            lookStatement = "";
            Scene1::sceneHalt = 1;
        }


        else {
         
        }
   
    return lookMessage;
}


std::string MenuInteraction::Open(int x, int y, int gd, int gy, int mInteraction, SDL_Texture* spriteTexture, SDL_Renderer* renderer, SDL_Surface* spriteDown1, std::string menuMessage) {

    std::string openMessage;

    PlayerObjects pob;
    Inventory inv;

    if (x > 178 && x < 232 && y > 723 && y < 744 ) {
        openStatement = Scene1::openStatement = "Open";
        std::cout << Scene1::openStatement << std::endl;
        openMessage = "Open what?";
        SDL_DestroyTexture(spriteTexture);
        SDL_CreateTextureFromSurface(renderer, spriteDown1);
    }

    else if (Scene1::SceneBackground == "1da" && x >= 523 && x <= 616 && y >= 502 && y <= 586 && gd > 408 && gd <500 && openStatement == "Open") {    
        Textures::objectTexture6 = Textures::objectTexture5;
        PlayerObjects::boxOpened = 1;
        openMessage = "Oh, what's that?";
    }
  
    else {
        openMessage = "";
        openStatement = Scene1::openStatement = "";
    }

    return openMessage;
}

std::string MenuInteraction::Use(int x, int y, int gd, int gy, int mInteraction, SDL_Texture* spriteTexture, SDL_Renderer* renderer, SDL_Surface* spriteDown1, std::string menuMessage) {
   std::string useMessage;

    PlayerObjects pob;
    Inventory inv;

    int n = useStatement.length();

    if (n < 8) //Don't override hover if a pick up statement has been selected. This is important, otherwise player will pick up anything within range no matter what you chose to pick up.
        useStatement = pob.HoverObjects(x, y, 1, gd, gy);

    if (useStatement == "Use Ape Tape") {
        SDL_DestroyTexture(spriteTexture);
        SDL_CreateTextureFromSurface(renderer, spriteAction);
        inv.useItem("Tape");
        Scene1::inv3Used = 1;
        useMessage = "That should plug the leak!";
        useStatement = "";
        Scene1::action = 1;
        Scene1::sceneHalt = 1;
     }
   

    return useMessage;

    /*


     if (x > 190 && x < 227 && y > 676 && y < 690) {
        useStatement = Scene1::useStatement = "Use";
        std::cout << Scene1::useStatement << std::endl;
        useMessage = "Use what?";
        SDL_DestroyTexture(spriteTexture);
        SDL_CreateTextureFromSurface(renderer, spriteDown1);
        Scene1::useStatement = "Use What?";
     }


     else if (x >= 560 && x <= 612 && y >= 288 && y <= 350 && useStatement == "Use" && Scene1::SceneBackground == "1" ) {
         
         SDL_DestroyTexture(spriteTexture);
         SDL_CreateTextureFromSurface(renderer, spriteDown1);
           useMessage = "It's broken, what am I supposed to use it for?";   
     }


     else if (x > 879 && x < 921 && y > 648 && y < 689 && useStatement == "Use" && Scene1::SceneBackground == "1da") {
         Scene1::useStatement = "Pipe with";
         std::cout << Scene1::useStatement << std::endl;

         SDL_DestroyTexture(spriteTexture);
         SDL_CreateTextureFromSurface(renderer, spriteDown1);

         useMessage = "Ok, where do I connect this pipe?";
     }

     else if (x >= 850 && x <= 958 && y >= 391 && y <= 482 && gd > 712 && Scene1::useStatement == "Pipe with" && Scene1::SceneBackground == "1da") {
         inv.useItem("Pipe");
         Scene1::inv5Used = 1;
         Textures::objectTextureAirBox = Textures::objectTexturePipe;

         SDL_DestroyTexture(spriteTexture);
         SDL_CreateTextureFromSurface(renderer, spriteDown1);
         useMessage = "Ok, connected!";
         Scene1::useStatement = "";
       
     }
     //This is used to tell the player they are too far away.
     else if (Scene1::useStatement == "Pipe with" && Scene1::SceneBackground == "1da") {
        
         SDL_DestroyTexture(spriteTexture);
         SDL_CreateTextureFromSurface(renderer, spriteDown1);
         useMessage = "I need to be closer to where I need to connect this pipe.";
         Scene1::useStatement = "";

     }


     else if (x > 758 && x < 819 && y > 689 && y < 757 && useStatement == "Use") {
         Scene1::useStatement = "Tent with";
         std::cout << Scene1::useStatement << std::endl;

         SDL_DestroyTexture(spriteTexture);
         SDL_CreateTextureFromSurface(renderer, spriteDown1);

         useMessage = "Ok, where shall I put this tent?";
     }
    
     else if (x > 370 && x < 916 && y > 220 && y < 283 && Scene1::useStatement == "Tent with" && Scene1::SceneBackground =="1f") {
         Scene1::useStatement = "Tent with";
         std::cout << Scene1::useStatement << std::endl;
      
         SDL_DestroyTexture(spriteTexture);
         SDL_CreateTextureFromSurface(renderer, spriteAction3);

         inv.useItem("Tent");
     
         Scene1::inv4Used = 1;
         //Change scene.
         Scene1::SceneBackground = "1fa";

         useMessage = "";
     }

      else if (x > 889 && x < 920 && y > 647 && y < 687 && useStatement == "Use") {
         Scene1::useStatement = "";
         std::cout << Scene1::useStatement << std::endl;

         SDL_DestroyTexture(spriteTexture);
         SDL_CreateTextureFromSurface(renderer, spriteAction);

         inv.useItem("Tape");
         Scene1::inv3Used = 1;
         useMessage = "That should plug the leak!";
         Scene1::action = 1;
         Scene1::sceneHalt = 1;
     }

      else if (x >= 850 && x <= 958 && y >= 391 && y <= 482 && gd > 731 && gy > 330 && useStatement == "Use" && Scene1::SceneBackground == "1da" &&Scene1::inv5Used == 1) {
         Scene1::useStatement = "";
         std::cout << Scene1::useStatement << std::endl;

         SDL_DestroyTexture(spriteTexture);
         SDL_CreateTextureFromSurface(renderer, spriteAction2);

         Scene1::inv6Used = 1;
         useMessage = "TOAD 1000: Suit has been pressurized!";
     }

     else if ( Scene1::SceneBackground == "1da" && useStatement == "Use" && x >= 245 && x <= 295 && y >= 353 && y <= 414) {
         Scene1::useStatement = "";
         Scene1::SceneBackground = "1db";
         Scene1::SPRITE_SIZE = 0;

     }
     

     else {
         useMessage = "";
         useStatement = Scene1::useStatement = "";
     }

     return useMessage;
     */
}

std::string MenuInteraction::PickUp(int x, int y,int gd, int gy, int mInteraction, SDL_Texture* spriteTexture, SDL_Renderer* renderer, SDL_Surface* spritePick,std::string menuMessage) {


    std::string gameObject;
	//std::string pickUp;
   
    PlayerObjects pob;
  
  //  int scene = 1; //Need to pass scene number in.
    int i = 0;
    int items = 0;
   
    //Get object name to pickup. So for example it will say "Pick up Tape".

    Inventory inv;

    int n = pickUpStatement.length();
    if(n < 8) //Don't override hover if a pick up statement has been selected. This is important, otherwise player will pick up anything within range no matter what you chose to pick up.
        pickUpStatement = pob.HoverObjects(x, y, 1, gd, gy);
   

    std::string menuMessages = pob.ObjectInteractionM1(gd, gy);
    gameObject = menuMessages;
    items = inv.checkItem(gameObject);
  
    //If user clicks on the location of the pickup button.
    if (Scene1::actionStatement == "Pick up") {
        std::cout << pickUpStatement << std::endl;
     
        if(items < 1 ){
         
        //If object picked up is..
            if (menuMessages == "PDA" && pickUpStatement == "Pick up White plastic thingy") {
                SDL_DestroyTexture(spriteTexture);
                SDL_CreateTextureFromSurface(renderer, spritePick); //Shows a different player movement when picking up things.
                Scene1::actionStatement = "";
                pickUpStatement = "";
                inv.SQLInsertInventory(gameObject, 0);
                Scene1::action = 1;
                Scene1::sceneHalt = 1;
                std::string object = pob.DestroyObjects(gameObject);
                Scene1::objectToDestroy.append(object);
               
            }

            if (menuMessages == "Flag" && pickUpStatement == "Pick up Flag") {
                Scene1::actionStatement = "";
                pickUpStatement = "";
                inv.SQLInsertInventory(gameObject, 0);
                Scene1::action = 1;
                Scene1::sceneHalt = 1;
                std::string object = pob.DestroyObjects(gameObject);
                Scene1::objectToDestroy.append(object);
                             
            }
            if (menuMessages == "Tape" && pickUpStatement == "Pick up Ape Tape") {
                Scene1::actionStatement = "";
                pickUpStatement = "";
                inv.SQLInsertInventory(gameObject, 0);
                Scene1::action = 1;
                Scene1::sceneHalt = 1;
                std::string object = pob.DestroyObjects(gameObject);
                Scene1::objectToDestroy.append(object);

            }

            if (menuMessages == "Tent" && pickUpStatement == "Pick up Self Inflating Tent") {
                Scene1::actionStatement = "";
                pickUpStatement = "";
                inv.SQLInsertInventory(gameObject, 0);
                Scene1::action = 1;
                Scene1::sceneHalt = 1;
                std::string object = pob.DestroyObjects(gameObject);
                Scene1::objectToDestroy.append(object);

            }

            if (menuMessages == "Battery Lantern") {
                Scene1::actionStatement = "";
                pickUpStatement = "";
                inv.SQLInsertInventory(gameObject, 0);
                Scene1::action = 1;
                Scene1::sceneHalt = 1;
                std::string object = pob.DestroyObjects(gameObject);
                Scene1::objectToDestroy.append(object);

            }

            if (menuMessages == "Pipe") {
                Scene1::actionStatement = "";
                pickUpStatement = "";
                inv.SQLInsertInventory(gameObject, 0);
                Scene1::action = 1;
                Scene1::sceneHalt = 1;
                std::string object = pob.DestroyObjects(gameObject);
                Scene1::objectToDestroy.append(object);

                Textures::objectTexture6 = Textures::objectTexture7;
             
                PlayerObjects::boxOpened = 2;

            }
       
    }

    else {
        gameObject = "";

    }
    
    }
	return gameObject;
}
