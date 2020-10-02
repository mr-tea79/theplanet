#include "MenuInteraction.h"
#include <SDL.h>
#include <iostream>
#include "Scene1.h"


using namespace brightland;

SDL_Surface* spriteAction = NULL;
SDL_Surface* spriteAction2 = NULL;
SDL_Surface* spriteAction3 = NULL;
static std::string useStatement;
static std::string sceneBackground;
static int inv3used;
static int inv4used;
static int playerMessage;


//std::string Initialize::useStatement;

void MenuInteraction::LoadActionTextures() {
  
  //  spriteAction2 = IMG_Load("PlayerMovement/spriteCoins.png");
    spriteAction = IMG_Load("PlayerMovement/ThePlanet/spriteAction1.png");
   // spriteAction3 = IMG_Load("PlayerMovement/spriteThrow.png");
}



std::string MenuInteraction::MenuSelect(int x, int y, int gd, int gy, int mInteraction, SDL_Texture* spriteTexture, SDL_Renderer* renderer, SDL_Surface* spriteDown1, std::string menuMessage, std::string interactionMessage) {
    
    std::string returnMessage = "";
    
   
   
    std::cout << Scene1::useStatement << std::endl;

    if (x > 61 && x < 146 && y > 643 && y < 690) {

        SDL_DestroyTexture(spriteTexture);
        SDL_CreateTextureFromSurface(renderer, spriteDown1);
        //Access static string from another class.
        useStatement = Scene1::useStatement = "Pick up";
        std::cout << Scene1::useStatement << std::endl;

        returnMessage = "Pick up";

    }

    if (x > 190 && x < 227 && y > 676 && y < 690) {

       //  SDL_DestroyTexture(spriteTexture);
        // SDL_CreateTextureFromSurface(renderer, spriteDown1);
         //Access static string from another class.
        useStatement = Scene1::useStatement = "Use";
        std::cout << Scene1::useStatement << std::endl;
        returnMessage = "Use what?";
    }

    return returnMessage;
   
}

std::string MenuInteraction::Use(int x, int y, int gd, int gy, int mInteraction, SDL_Texture* spriteTexture, SDL_Renderer* renderer, SDL_Surface* spriteDown1, std::string menuMessage) {

  
    std::string useMessage;
    //std::string pickUp;

    PlayerObjects pob;
    Inventory inv;

     if (x > 190 && x < 227 && y > 676 && y < 690) {

    // SDL_DestroyTexture(spriteTexture);
     //SDL_CreateTextureFromSurface(renderer, spriteDown1);
     //Access static string from another class.
     useStatement = Scene1::useStatement = "Use";
     std::cout << Scene1::useStatement << std::endl;
     useMessage = "Use what?";
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

  

      else if (x > 889 && x < 920 && y > 647 && y < 687 && useStatement == "Use" ) {

         Scene1::useStatement = "";
         std::cout << Scene1::useStatement << std::endl;

         SDL_DestroyTexture(spriteTexture);
         SDL_CreateTextureFromSurface(renderer, spriteAction);

         inv.useItem("Tape");
         Scene1::inv3Used = 1;
         useMessage = "That should plug the leak!";
        // Scene1::playerMessage = 4;
     }

     else {
         useMessage = "";
         useStatement = Scene1::useStatement = "";

     }


     return useMessage;


}

std::string MenuInteraction::PickUp(int x, int y,int gd, int gy, int mInteraction, SDL_Texture* spriteTexture, SDL_Renderer* renderer, SDL_Surface* spriteDown1,std::string menuMessage) {


    std::string gameObject;
	//std::string pickUp;
   
    PlayerObjects pob;
  
  //  int scene = 1; //Need to pass scene number in.
    int i = 0;
    int items = 0;
   
    //Get object name to pickup. So for example it will say "Pick up Tape".
    std::string menuMessages = pob.ObjectInteractionM1(gd, gy);
    gameObject = menuMessages;

    Inventory inv;
  
    //If user clicks on the location of the pickup button.
    if (x > 61 && x < 146 && y > 643 && y < 690) {
       
      //  std::cout << "You clicked Pick up!" << std::endl;
        items = inv.checkItem(gameObject);
        SDL_DestroyTexture(spriteTexture);
        SDL_CreateTextureFromSurface(renderer, spriteDown1);

       
        if(items < 1 ){
           
        //If object picked up is..
            if (menuMessages == "PDA") {
              
                inv.SQLInsertInventory(gameObject, 0);

        
            }

            if (menuMessages == "Flag") {
       
                inv.SQLInsertInventory(gameObject, 0);
                             
            }
            if (menuMessages == "Tape") {

                inv.SQLInsertInventory(gameObject, 0);

            }

            if (menuMessages == "Tent") {

                inv.SQLInsertInventory(gameObject, 0);

            }
           
        }    
       
    }

    
   // else if (x > 190 && x < 682 && y > 676 && y < 690) {

     //   std::cout << "You clicked use." << std::endl;
  //  }

    else {
        gameObject = "";
  

    }
    
    
	return gameObject;
}

