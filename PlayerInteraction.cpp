#include "PlayerInteraction.h"
#include <SDL.h>
#include <iostream>
#include "Scene1.h"
#include "Textures.h"

using namespace brightland;

int PlayerInteraction::playerMessage = 100;

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
        Scene1::textRect = { Scene1::gdSprite.x - 300,  Scene1::gdSprite.y - 100, messageLength * 10, 20 };

    }
    else if (Scene1::gdSprite.y < 100) {
        Scene1::textRect = { Scene1::gdSprite.x -300 ,  Scene1::gdSprite.y + 100, messageLength * 10, 20 };
    }
    else if (Scene1::gdSprite.x > 550 && messageLength > 14) {
        Scene1::textRect = { Scene1::gdSprite.x - 300,  Scene1::gdSprite.y - 100, messageLength * 10, 20 };

    }
    else if (Scene1::gdSprite.x < 90 && messageLength > 14) {
        Scene1::textRect = { Scene1::gdSprite.x + 300,  Scene1::gdSprite.y - 100, messageLength * 10, 20 };

    }
    else if (Scene1::gdSprite.x < 90 ) {
        Scene1::textRect = { Scene1::gdSprite.x + 50,  Scene1::gdSprite.y - 100, messageLength * 10, 20 };

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
        PlayerMessage = "I need to be able to set up camp ";      
    }

    else if (msgNumber == 2) {
        PlayerMessage = "if I'm going to venture out into the wilderness..!";
    }

    else if (msgNumber == 3) {
        PlayerMessage = "If I go out there without my computer";
    }

    else if (msgNumber == 4) {
        PlayerMessage = "I will probably regret it!";
    }

    else if (msgNumber == 5) {    
        PlayerMessage = "My suit is leaking oxygen and if I";
    }

    else if (msgNumber == 6) {
        PlayerMessage = "am stupid enough to go for a walk, I will die!";
    }
    else if (msgNumber == 7) {
        PlayerMessage = "This is one of the ION engines, I think that";
    }
    else if (msgNumber == 8) {
        PlayerMessage = "It has seen better days, I'm not going anywhere.";
    }
    else if (msgNumber == 9) {
        PlayerMessage = "Ok, well this ship is somewhat wrecked!";
    }
    else if (msgNumber == 10) {
        PlayerMessage = "But I can't complain, I'm still alive.";
    }
    else if (msgNumber == 11) {
        PlayerMessage = "No job is too big for APE TAPE! I could";
    }
    else if (msgNumber == 12) {
        PlayerMessage = "seal an air leak on my ship with this stuff!";
    }
    else if (msgNumber == 13) {
        PlayerMessage = "That's my PDA, doesn't look damaged!!";
    }
    else if (msgNumber == 15) {
        PlayerMessage = "I wonder what mysteries there are on that moon";
    }
    else if (msgNumber == 16) {
        PlayerMessage = "BEEEP";
    }
    else if (msgNumber == 17) {
        PlayerMessage = "BEEEEEEP";
    }
    else if (msgNumber == 18) {
        PlayerMessage = "TOAD1000: Bonita your oxygen is very low";
    }
    else if (msgNumber == 19) {
        PlayerMessage = "This planet is very.... Purple.";
    }
    else if (msgNumber == 20) {
        PlayerMessage = "This is a self inflatable habitat.";
    }
    else if (msgNumber == 21) {
        PlayerMessage = "This is the mission flag. But I am surprised";
    }
    else if (msgNumber == 22) {
        PlayerMessage = "it is still standing up after the crash.";
    }
    else if (msgNumber == 23) {
        PlayerMessage = "Aha! That should plug the air leak.";
    }
    else if (msgNumber == 24) {
        PlayerMessage = "It's a meteorite!";
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
        interactionMessage = PlayerMessage(1, 13);
        playerMessage = 14;   
    }
    //This is important to allow the last message in the player interaction to be shown.
    else if (playerMessage == 15) {
        std::cout << playerMessage << std::endl;
        interactionMessage = PlayerMessage(1, 15);
    
    }
    else if (playerMessage == 16) {
        std::cout << playerMessage << std::endl;
        interactionMessage = PlayerMessage(1, 16);

    }
    else if (playerMessage == 17) {
        std::cout << playerMessage << std::endl;
        interactionMessage = PlayerMessage(1, 17);

    }
    else if (playerMessage == 18) {
        std::cout << playerMessage << std::endl;
        interactionMessage = PlayerMessage(1, 18);

    }
    else if (playerMessage == 19) {
        std::cout << playerMessage << std::endl;
        interactionMessage = PlayerMessage(1, 19);

    }
    else if (playerMessage == 20) {
        std::cout << playerMessage << std::endl;
        interactionMessage = PlayerMessage(1, 20);

    }
    else if (playerMessage == 21) {
        std::cout << playerMessage << std::endl;
        interactionMessage = PlayerMessage(1, 21);

    }
    else if (playerMessage == 22) {
        std::cout << playerMessage << std::endl;
        interactionMessage = PlayerMessage(1, 22);

    }
    else if (playerMessage == 23) {
        std::cout << playerMessage << std::endl;
        interactionMessage = PlayerMessage(1, 23);

    }
    else if (playerMessage == 24) {
    std::cout << playerMessage << std::endl;
    interactionMessage = PlayerMessage(1, 24);

    }


    else {

    }

    return interactionMessage;

}
	
