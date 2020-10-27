#include "PlayerInteraction.h"
#include "Scene1.h"
#include <SDL.h>
#include <iostream>
#include "Scene1.h"
#include "Textures.h"

using namespace brightland;

static int playerMessage;

void PlayerInteraction::InteractionControllerHover(std::string interactionMessage) {
    // Textures tex;
    const char* im = NULL;
    SDL_DestroyTexture(Scene1::ftexture);
//	Scene1::fsurface = NULL;

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

void PlayerInteraction::InteractionControllerUse(std::string useMessage, std::string openMessage, std::string gameObject) {
    const char* imu = useMessage.c_str();;
    int useMessageLength = useMessage.length();
    Scene1::dTexture.x = Scene1::gdSprite.x - 100;  //Set position of text.
  //  SDL_DestroyTexture(Scene1::ftexture);
   
        //The following 2 if statements will ensure the dialog text doesn't go off the screen. Needs tweaking a little bit.
        if (Scene1::gdSprite.x > 130 && WIDTH - 400) {
            Scene1::textRect = { Scene1::gdSprite.x - 60,  Scene1::gdSprite.y - 100, useMessageLength * 10, 20 };
        }
        if (Scene1::gdSprite.x < 130) {
            Scene1::textRect = { Scene1::gdSprite.x - 60,  Scene1::gdSprite.y - 100, useMessageLength * 10, 20 };
        }

   
        Scene1::fsurface = TTF_RenderText_Solid(Scene1::font, imu, Scene1::fcolor);
        Scene1::ftexture = SDL_CreateTextureFromSurface(Scene1::renderer, Scene1::fsurface);
        _sleep(300); // pauses briefly to allow text to show.
       
   //     delete(imu);
    
}

void PlayerInteraction::InteractionControllerObject(std::string interactionMessage,std::string gameObject) {
    //Handles all object interaction messages on the game window.    
  //  SDL_DestroyTexture(Scene1::ftexture);
    Textures tex;
    Scene1::dTexture.x = Scene1::gdSprite.x - 100;  //Set position of text.
    const char* im = interactionMessage.c_str();
    const char* imenu = gameObject.c_str();                 
    int interactionMessagelength = interactionMessage.length();

            //Set Scene Background Player Positions. An example would be if you entered a building but you wanted the player to start in the middle of the scene.
            if (interactionMessage == "Scene1b") {
                interactionMessage = "";
                Scene1::xPosition = 400;
                Scene1::gdSprite.x = Scene1::xPosition;
            }

            if (interactionMessage == "Scene1") {
                interactionMessage = "";
                Scene1::xPosition = 600;
                Scene1::gdSprite.x = Scene1::xPosition;
                Scene1::background2 = { 0, 200, 1500, 400 };
            }

            if (interactionMessage == "Scene1e") {

                interactionMessage = "";
                Scene1::xPosition = 100;
                Scene1::gdSprite.x = Scene1::xPosition;
                Scene1::gdSprite.y = Scene1::yPosition;
                //      SDL_WarpMouseInWindow(window, WIDTH, HEIGHT); //This is to try and prevent a crash.
            }

            if (interactionMessage == "Scene1f") {
                if (Scene1::tLoader == 0) {
                    tex.Scene2Textures();
                    Scene1::tLoader = 1;
                }

                interactionMessage = "";
                Scene1::xPosition = 10;
                Scene1::gdSprite.x = Scene1::xPosition;
                Scene1::gdSprite.y = Scene1::yPosition;

            }

            if (interactionMessage == "Scene1fb") {


                interactionMessage = "";
                Scene1::xPosition = 10;
                Scene1::gdSprite.x = Scene1::xPosition;
                Scene1::gdSprite.y = Scene1::yPosition;



            }

            if (interactionMessage == "Scene1fa") {

                interactionMessage = "";
                Scene1::xPosition = 200;
                Scene1::gdSprite.x = Scene1::xPosition;
                Scene1::gdSprite.y = Scene1::yPosition;

            }

            if (interactionMessage == "Scene1d") {
                interactionMessage = "";
                // xPosition = 10;
                Scene1::gdSprite.x = Scene1::xPosition;
                Scene1::gdSprite.y = Scene1::yPosition;

            }

            if (interactionMessage == "Scene1d2") {
                interactionMessage = "";


            }

            //The following 2 if statements will ensure the dialog text doesn't go off the screen. Needs tweaking a little bit.
            if (Scene1::gdSprite.x > 130 && Scene1::gdSprite.x > WIDTH - 100) {
                Scene1::textRect = { Scene1::gdSprite.x - 300,  Scene1::gdSprite.y - 80, interactionMessagelength * 10, 20 };

            }
            else if (Scene1::gdSprite.x > 130 && Scene1::gdSprite.x < WIDTH - 100) {
                Scene1::textRect = { Scene1::gdSprite.x - 100 ,  Scene1::gdSprite.y - 80, interactionMessagelength * 10, 20 };

            }

            else if (Scene1::gdSprite.x < 130) {
                Scene1::textRect = { Scene1::gdSprite.x - 60 ,  Scene1::gdSprite.y - 80, interactionMessagelength * 10, 20 };

            }

                Scene1::fsurface = TTF_RenderText_Solid(Scene1::font, im, Scene1::fcolor);

           

            //Render the text on the screen.

            Scene1::ftexture = SDL_CreateTextureFromSurface(Scene1::renderer, Scene1::fsurface);
            _sleep(300); // pauses briefly to allow text to show.
        
          
            //delete(im);
           
           
          

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
		std::string PlayerMessage = "TOAD 1000: Bonita, you need to find a suitable area for base camp. Your Oxygen is limited.";
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