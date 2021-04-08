#include "PlayerInteraction.h"
#include <SDL.h>
#include <iostream>
#include "Scene1.h"
#include "Textures.h"

using namespace brightland;

int PlayerInteraction::playerMessage = 10000;

//Needs some tweaking
void PlayerInteraction::textDimensions(int messageLength) {
    if (Scene1::gdSprite.x > 130 && Scene1::gdSprite.x < 700) {
        Scene1::textRect = { Scene1::gdSprite.x - 60,  Scene1::gdSprite.y - 100, messageLength * 10, 20 };
    }
    else if (Scene1::gdSprite.x < 130) {
        Scene1::textRect = { Scene1::gdSprite.x - 60,  Scene1::gdSprite.y - 100, messageLength * 10, 20 };
    }
    else if (Scene1::gdSprite.x > 680) {
        Scene1::textRect = { Scene1::gdSprite.x - 160 ,  Scene1::gdSprite.y - 80, messageLength * 10, 20 };
    }
    Scene1::dTexture.x = Scene1::gdSprite.x - 100;  //Set position of text.
}

void PlayerInteraction::InteractionControllerHover(std::string interactionMessage) {
    // Textures tex;
    const char* im = NULL;
    SDL_DestroyTexture(Scene1::ftexture);

    if (interactionMessage != "" ) {

        int interactionMessagelength = interactionMessage.length();
        im = interactionMessage.c_str();

        Scene1::textRect = { 500, 610, interactionMessagelength * 10, 20 };   // The * 10, 20 is a mathematical way of setting the text width depending on the length of the text.
        Scene1::fsurface = TTF_RenderText_Solid(Scene1::font, im, Scene1::fcolor);
        Scene1::ftexture = SDL_CreateTextureFromSurface(Scene1::renderer, Scene1::fsurface);
 
    }

    else {
        SDL_DestroyTexture(Scene1::ftexture);
    }

}

void PlayerInteraction::InteractionControllerUse(std::string useMessage,std::string gameObject) {
    const char* imu = useMessage.c_str();;
    int useMessageLength = useMessage.length();  
    textDimensions(useMessageLength);
    Scene1::fsurface = TTF_RenderText_Solid(Scene1::font, imu, Scene1::fcolor);
    Scene1::ftexture = SDL_CreateTextureFromSurface(Scene1::renderer, Scene1::fsurface);  
}

void PlayerInteraction::InteractionControllerOpen(std::string openMessage, std::string gameObject) {
    const char* imu = openMessage.c_str();;
    int openMessageLength = openMessage.length();   
    textDimensions(openMessageLength);
    Scene1::fsurface = TTF_RenderText_Solid(Scene1::font, imu, Scene1::fcolor);
    Scene1::ftexture = SDL_CreateTextureFromSurface(Scene1::renderer, Scene1::fsurface);
}

void PlayerInteraction::InteractionControllerLook(std::string lookMessage, std::string gameObject) {
    const char* imu = lookMessage.c_str();;
    int lookMessageLength = lookMessage.length();
    textDimensions(lookMessageLength);
    Scene1::fsurface = TTF_RenderText_Solid(Scene1::font, imu, Scene1::fcolor);
    Scene1::ftexture = SDL_CreateTextureFromSurface(Scene1::renderer, Scene1::fsurface);
}

void PlayerInteraction::InteractionControllerAction(std::string actionMessage, std::string gameObject) {
    const char* imu = actionMessage.c_str();;
    int actionMessageLength = actionMessage.length();
    textDimensions(actionMessageLength);
    Scene1::fsurface = TTF_RenderText_Solid(Scene1::font, imu, Scene1::fcolor);
    Scene1::ftexture = SDL_CreateTextureFromSurface(Scene1::renderer, Scene1::fsurface);
}

void PlayerInteraction::InteractionControllerObject(std::string interactionMessage,std::string gameObject) {   
    const char* im = interactionMessage.c_str();
    const char* imenu = gameObject.c_str();                 
    int interactionMessagelength = interactionMessage.length();
    textDimensions(interactionMessagelength);
    Scene1::fsurface = TTF_RenderText_Solid(Scene1::font, im, Scene1::fcolor);        
    Scene1::ftexture = SDL_CreateTextureFromSurface(Scene1::renderer, Scene1::fsurface);   
}
 


std::string PlayerInteraction::PlayerMessage(int scene, int msgNumber) {

    if (msgNumber == 1) {
        std::string PlayerMessage = "Bonita Gonzalez finds herself stranded on an Alien planet.";
        return PlayerMessage;
    }

    else if (msgNumber == 2) {
        std::string PlayerMessage = "TOAD 1000: Bonita WAKE UP!";
        return PlayerMessage;
    }

    else if (msgNumber == 3) {
        std::string PlayerMessage = "TOAD 1000: Bonita.... Your Oxygen Level is critical! BEEP BEEP";
        return PlayerMessage;
    }

    else if (msgNumber == 4) {
        std::string PlayerMessage = "TOAD 1000: Suit pressure rising";
        return PlayerMessage;
    }

    else if (msgNumber == 5) {
      
        std::string PlayerMessage = "TOAD 1000: Bonita, your Oxygen is very low.";
        return PlayerMessage;
    }

    else if (msgNumber == 6) {
        std::string PlayerMessage = "Wow, these self inflatable tents are pretty nice.";
        return PlayerMessage;
    }
    else if (msgNumber == 7) {
        std::string PlayerMessage = "Well, it's a Wigwam!";
        return PlayerMessage;
    }

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
        playerMessage = 7;
    }

    //This is important to allow the last message in the player interaction to be shown.
    else if (playerMessage == 7) {
        playerMessage = 8;   
    }

    else {

    }

    return interactionMessage;

}
	
