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

    //Ternary operator
    //(expr) ? <true logic> : <false logic>  (IF TRUE ? DO THIS : ELSE DO THIS)
    //Used to reduce lots of IF statements.
    //IF                                                                       //TRUE THEN ?                                                                                             //ELSE :
    Scene1::gdSprite.x > 550 && Scene1::gdSprite.y > 100 && messageLength > 40 ? Scene1::textRect = { Scene1::gdSprite.x - 300,  Scene1::gdSprite.y - 100, messageLength * 10, 20 } : Scene1::textRect = { Scene1::gdSprite.x - 60,  Scene1::gdSprite.y - 100, messageLength * 10, 20 };
    Scene1::gdSprite.y < 100 ? Scene1::textRect = { Scene1::gdSprite.x - 300 ,  Scene1::gdSprite.y + 100, messageLength * 10, 20 } : Scene1::textRect = { Scene1::gdSprite.x - 60,  Scene1::gdSprite.y - 100, messageLength * 10, 20 };
    Scene1::gdSprite.x > 550 && messageLength > 14 ? Scene1::textRect = { Scene1::gdSprite.x - 300,  Scene1::gdSprite.y - 100, messageLength * 10, 20 } : Scene1::textRect = { Scene1::gdSprite.x - 60,  Scene1::gdSprite.y - 100, messageLength * 10, 20 };
    Scene1::gdSprite.x < 90 && messageLength > 14 ? Scene1::textRect = { Scene1::gdSprite.x + 300,  Scene1::gdSprite.y - 100, messageLength * 10, 20 } : Scene1::textRect = { Scene1::gdSprite.x - 60,  Scene1::gdSprite.y - 100, messageLength * 10, 20 };
    Scene1::gdSprite.x < 90 ? Scene1::textRect = { Scene1::gdSprite.x + 50,  Scene1::gdSprite.y - 100, messageLength * 10, 20 } : Scene1::textRect = Scene1::textRect = { Scene1::gdSprite.x - 60,  Scene1::gdSprite.y - 100, messageLength * 10, 20 };
}


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


void PlayerInteraction::InteractionControllerObject(std::string interactionMessage,std::string gameObject) {   
    
    const char* im = interactionMessage.c_str();
    const char* imenu = gameObject.c_str();                 
    int interactionMessagelength = interactionMessage.length();
    textDimensions(interactionMessagelength);
    Scene1::fsurface = TTF_RenderText_Shaded(Scene1::font, im, Scene1::fcolor, Scene1::bcolor);
    Textures::ftexture = SDL_CreateTextureFromSurface(Scene1::renderer, Scene1::fsurface);
    SDL_FreeSurface(Scene1::fsurface);
  
}
 

std::string PlayerInteraction::DisplayPlayerMessages() {
 
    std::string interactionMessage;
    
    //Ternary operator
   //(expr) ? <true logic> : <false logic>  (IF TRUE ? DO THIS : ELSE DO THIS)
   //Used to reduce lots of IF statements.

    //This will show the scene player messages in sequence.
    playerMessage == 1 ? interactionMessage = "I need to be able to set up camp" : "";
    playerMessage == 2 ? interactionMessage = "if I'm going to venture out into the wilderness..!" : "";
    playerMessage == 3 ? interactionMessage = "If I go out there without my computer" : "";
    playerMessage == 4 ? interactionMessage = "I will probably regret it!" : "";
    playerMessage == 5 ? interactionMessage = "My suit is leaking oxygen and if I" : "";
    playerMessage == 6 ? interactionMessage = "am stupid enough to go for a walk, I will die!" : "";
    playerMessage == 7 ? interactionMessage = "This is one of the ION engines" : "";
    playerMessage == 8 ? interactionMessage = "It has seen better days, I'm not going anywhere." : "";
    playerMessage == 9 ? interactionMessage = "Ok, well this ship is somewhat wrecked!" : "";
    playerMessage == 10 ? interactionMessage = "But I can't complain, I'm still alive." : "";
    playerMessage == 11 ? interactionMessage = "No job is too big for APE TAPE! I could" : "";
    playerMessage == 12 ? interactionMessage = "seal an air leak on my ship with this stuff!" : "";
    playerMessage == 13 ? interactionMessage = "That's my PDA, doesn't look damaged!!" : "";
    playerMessage == 14 ? interactionMessage = "" : "";
    playerMessage == 15 ? interactionMessage = "I wonder what mysteries there are on that moon" : "";
  //  playerMessage == 16 ? interactionMessage = "BEEEP" : "";
   // playerMessage == 17 ? interactionMessage = "BEEEEEEP" : "";
    playerMessage == 18 ? interactionMessage = "TOAD1000: Bonita your oxygen is very low" : "";
    playerMessage == 19 ? interactionMessage = "Wow, this planet is very..erm.. Purple." : "";
    playerMessage == 20 ? interactionMessage = "This is a self inflatable habitat." : "";
    playerMessage == 20 ? interactionMessage = "This is the mission flag. But I am surprised" : "";
    playerMessage == 21 ? interactionMessage = "This is the mission flag. But I am surprised" : "";
    playerMessage == 22 ? interactionMessage = "it is still standing up after the crash." : "";
    playerMessage == 23 ? interactionMessage = "Aha! That should plug the air leak." : "";
    playerMessage == 24 ? interactionMessage = "It's a meteorite!" : "";
    playerMessage == 25 ? interactionMessage = "It's half the size of me and made of rock!" : "";
    playerMessage == 26 ? interactionMessage = "This area would be ideal for setting up camp." : "";
    playerMessage == 27 ? interactionMessage = "Well, it's a wigwam!." : "";
    playerMessage == 28 ? interactionMessage = "Well, the inflatable tents have certainly improved." : "";
    playerMessage == 29 ? interactionMessage = "Apparently this little thing has 5000 lumens!" : "";
    playerMessage == 30 ? interactionMessage = "It's made of plastic." : "";
    playerMessage == 31 ? interactionMessage = "It's a box made of cardboard and unopened." : "";
    playerMessage == 32 ? interactionMessage = "Hmmm, it's very flat here.." : "";

    return interactionMessage;

}
	
