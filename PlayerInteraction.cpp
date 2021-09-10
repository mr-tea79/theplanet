#include "PlayerInteraction.h"
#include <SDL.h>
#include <iostream>
#include "Scene1.h"
#include "Textures.h"

using namespace brightland;

int PlayerInteraction::playerMessage = 10000;

//This will determine where the text box appears on the screen. For example if the player is on the far right hand side
//then the text box will move left to prevent the text going off the screen. Bit fidly but just needs tweaking sometimes.

void PlayerInteraction::textDimensions(int messageLength) {


  //  if (Scene1::gdSprite.x > 130 && Scene1::gdSprite.x < 600 && Scene1::gdSprite.y >100) {
    //    Scene1::textRect = { Scene1::gdSprite.x - 60,  Scene1::gdSprite.y - 100, messageLength * 10, 20 };
        
 //   }
   // else if (Scene1::gdSprite.x > 600 && Scene1::gdSprite.x < 700 && Scene1::gdSprite.y >100) {
  //      Scene1::textRect = { Scene1::gdSprite.x - 400,  Scene1::gdSprite.y - 100, messageLength * 10, 20 };

  //  }
    if (Scene1::gdSprite.x > 550 && Scene1::gdSprite.y >100 && messageLength > 40 ) {
        Scene1::textRect = { Scene1::gdSprite.x - 600,  Scene1::gdSprite.y - 100, messageLength * 10, 20 };

    }
    else if (Scene1::gdSprite.y < 100) {
        Scene1::textRect = { Scene1::gdSprite.x -300 ,  Scene1::gdSprite.y + 100, messageLength * 10, 20 };
    }
    else {
        Scene1::textRect = { Scene1::gdSprite.x - 60,  Scene1::gdSprite.y - 100, messageLength * 10, 20 };

    }
    
   // else if (Scene1::gdSprite.x > 680 && Scene1::gdSprite.y > 100) {
  //      Scene1::textRect = { Scene1::gdSprite.x - 160 ,  Scene1::gdSprite.y - 80, messageLength * 10, 20 };       
 //   }
 ///   else if (Scene1::gdSprite.y < 100) {
  //      Scene1::textRect = { Scene1::gdSprite.x -300 ,  Scene1::gdSprite.y + 100, messageLength * 10, 20 };
 //   }
   
}

//Small memory leak here. Need to figure this out.
void PlayerInteraction::InteractionControllerHover(std::string interactionMessage) {
    const char* im = interactionMessage.c_str();
    if (interactionMessage != "" ) {
        int interactionMessagelength = interactionMessage.length();
        Scene1::textRect = { 500, 610, interactionMessagelength * 10, 20 };   // The * 10, 20 is a mathematical way of setting the text width depending on the length of the text.
        Scene1::fsurface = TTF_RenderText_Solid(Scene1::font, im, Scene1::fcolor);
        Textures::ftexture = SDL_CreateTextureFromSurface(Scene1::renderer, Scene1::fsurface);     
        SDL_FreeSurface(Scene1::fsurface);
      
    }
}

void PlayerInteraction::InteractionControllerUse(std::string useMessage,std::string gameObject) {
    
    const char* imu = useMessage.c_str();;
    int useMessageLength = useMessage.length();  
    textDimensions(useMessageLength);
    Scene1::fsurface = TTF_RenderText_Shaded(Scene1::font, imu, Scene1::fcolor, Scene1::bcolor);
    Textures::ftexture = SDL_CreateTextureFromSurface(Scene1::renderer, Scene1::fsurface);
    SDL_FreeSurface(Scene1::fsurface);
}

void PlayerInteraction::InteractionControllerOpen(std::string openMessage, std::string gameObject) {
 
    const char* imu = openMessage.c_str();;
    int openMessageLength = openMessage.length();   
    textDimensions(openMessageLength);
    Scene1::fsurface = TTF_RenderText_Shaded(Scene1::font, imu, Scene1::fcolor, Scene1::bcolor);
    Textures::ftexture = SDL_CreateTextureFromSurface(Scene1::renderer, Scene1::fsurface);
    SDL_FreeSurface(Scene1::fsurface);

}

void PlayerInteraction::InteractionControllerLook(std::string lookMessage, std::string gameObject) {
    
    const char* imu = lookMessage.c_str();;
    int lookMessageLength = lookMessage.length();
    textDimensions(lookMessageLength);
    Scene1::fsurface = TTF_RenderText_Shaded(Scene1::font, imu, Scene1::fcolor,Scene1::bcolor);
    Textures::ftexture = SDL_CreateTextureFromSurface(Scene1::renderer, Scene1::fsurface);
    SDL_FreeSurface(Scene1::fsurface);
}

void PlayerInteraction::InteractionControllerPull(std::string lookMessage, std::string gameObject) {

    const char* imu = lookMessage.c_str();;
    int pullMessageLength = lookMessage.length();
    textDimensions(pullMessageLength);
    Scene1::fsurface = TTF_RenderText_Shaded(Scene1::font, imu, Scene1::fcolor, Scene1::bcolor);
    Textures::ftexture = SDL_CreateTextureFromSurface(Scene1::renderer, Scene1::fsurface);
    SDL_FreeSurface(Scene1::fsurface);
}


void PlayerInteraction::InteractionControllerAction(std::string actionMessage, std::string gameObject) {
    
    const char* imu = actionMessage.c_str();;
    int actionMessageLength = actionMessage.length();
    textDimensions(actionMessageLength);
    Scene1::fsurface = TTF_RenderText_Solid(Scene1::font, imu, Scene1::fcolor);
    Textures::ftexture = SDL_CreateTextureFromSurface(Scene1::renderer, Scene1::fsurface);
    SDL_FreeSurface(Scene1::fsurface);
}

void PlayerInteraction::InteractionControllerObject(std::string interactionMessage,std::string gameObject) {   
    
    const char* im = interactionMessage.c_str();
    const char* imenu = gameObject.c_str();                 
    int interactionMessagelength = interactionMessage.length();
    textDimensions(interactionMessagelength);
    Scene1::fsurface = TTF_RenderText_Shaded(Scene1::font, im, Scene1::fcolor, Scene1::bcolor);
    Textures::ftexture = SDL_CreateTextureFromSurface(Scene1::renderer, Scene1::fsurface);
    SDL_FreeSurface(Scene1::fsurface);
}
 

std::string PlayerInteraction::PlayerMessage(int scene, int msgNumber) {
    std::string PlayerMessage = "";

    if (msgNumber == 1) {
        PlayerMessage = "Bonita Gonzalez finds herself stranded on an Alien planet.";      
    }

    else if (msgNumber == 2) {
        PlayerMessage = "TOAD 1000: Bonita WAKE UP!";
    }

    else if (msgNumber == 3) {
        PlayerMessage = "TOAD 1000: Bonita.... Your Oxygen Level is critical! BEEP BEEP";
    }

    else if (msgNumber == 4) {
        PlayerMessage = "TOAD 1000: Suit pressure rising";
    }

    else if (msgNumber == 5) {    
        PlayerMessage = "TOAD 1000: Bonita, your Oxygen is very low.";
    }

    else if (msgNumber == 6) {
        PlayerMessage = "These self inflatable tents seem to have improved over the years!";
    }
    else if (msgNumber == 7) {
        PlayerMessage = "Well, it's a Wigwam!";
    }
    else if (msgNumber == 8) {
        PlayerMessage = "I'm leaking Oxygen and need to sort that out first.";
    }
    else if (msgNumber == 9) {
        PlayerMessage = "I need to be able to set up camp if I'm going to venture out into the wilderness.";
    }
    else if (msgNumber == 10) {
        PlayerMessage = "I need to take my computer with me.";
    }
    else if (msgNumber == 11) {
        PlayerMessage = "Hmmm.... Well, it's a bit dark in here!";
    }
    else if (msgNumber == 12) {
        PlayerMessage = "Looks like a map!";
    }

    return PlayerMessage;
}





std::string PlayerInteraction::DisplayPlayerMessages() {
 
    std::string interactionMessage;

    //This will show the scene player messages in sequence.
    if (playerMessage == 1) {
        interactionMessage = PlayerMessage(1, 1);   
        playerMessage = 2;
       
    }
    else if (playerMessage == 2) {
        interactionMessage = PlayerMessage(1, 2);     
        playerMessage = 3;     
    }
    else if (playerMessage == 3) {
        interactionMessage = PlayerMessage(1, 3);                 
        playerMessage = 6;     
   
    }
    else if (playerMessage == 4) {
        interactionMessage = PlayerMessage(1, 4);                
        playerMessage = 5;      
    }
    else if (playerMessage == 5) {
        interactionMessage = PlayerMessage(1, 5);
        playerMessage = 6;
    }
    else if (playerMessage == 6) {
        interactionMessage = PlayerMessage(1, 6);     
        playerMessage = 7;
    }
    else if (playerMessage == 7) {
        interactionMessage = PlayerMessage(1, 7);
        playerMessage = 8;
    }
    else if (playerMessage == 8) {
        interactionMessage = PlayerMessage(1, 8);
        playerMessage = 9;
    }
    else if (playerMessage == 9) {
        interactionMessage = PlayerMessage(1, 9);
        playerMessage = 10;
    }
    else if (playerMessage == 10) {
        interactionMessage = PlayerMessage(1, 10);
        playerMessage = 11;
    }
    else if (playerMessage == 11) {
        interactionMessage = PlayerMessage(1, 11);
        playerMessage = 12;
    }
    else if (playerMessage == 12) {
        interactionMessage = PlayerMessage(1, 12);
        playerMessage = 13;
    }
    //This is important to allow the last message in the player interaction to be shown.
    else if (playerMessage == 13) {
        playerMessage = 14;   
    }

    else {

    }

    return interactionMessage;

}
	
