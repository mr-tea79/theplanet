
#include "PlayerMovement.h"
#include "Textures.h"
#include <iostream>
#include <SDL.h>
#include "Scene1.h"

using namespace brightland;
using namespace std;

static int position; //Used to update current position variable.


int PlayerMovement::doXWalkRight(int gd, SDL_Texture* spriteTexture, int screenWidth) {
  
    if (position == 0) {
        SDL_DestroyTexture(spriteTexture);
        spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, Textures::spriteRight1a);
        gd += 3.5; //Speed of sprite movement.
    }
    if (position == 1) {
        SDL_DestroyTexture(spriteTexture);
        spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, Textures::spriteRight2a);
        gd += 3.5;
    }
    if (position == 2) {
        SDL_DestroyTexture(spriteTexture);
        spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, Textures::spriteRight3a);
        gd += 3.5;
    }
    if (position == 3) {
        SDL_DestroyTexture(spriteTexture);
        spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, Textures::spriteRight4a);
        gd += 3.5;
        position = 0; //This achieves the animation effect.
    }
    //Prevent walking off the screen.
    if (gd == screenWidth - 50) {
        SDL_DestroyTexture(spriteTexture);
        spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, Textures::spriteLeft1a);
        gd += 3.5;
    }

    return gd;
}

int PlayerMovement::doXWalkLeft(int gd, SDL_Texture* spriteTexture, int screenWidth) {

    if (position == 0) {
        SDL_DestroyTexture(spriteTexture);
        spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, Textures::spriteLeft1a);
        gd -= 3.5;
    }
    if (position == 1) {
        SDL_DestroyTexture(spriteTexture);
        spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, Textures::spriteLeft2a);
        gd -= 3.5;
    }
    if (position == 2) {
        SDL_DestroyTexture(spriteTexture);
        spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, Textures::spriteLeft3a);
        gd -= 3.5;
    }
    if (position == 3) {
        SDL_DestroyTexture(spriteTexture);
        spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, Textures::spriteLeft4a);
        gd -= 3.5;
        position = 0; //This achieves the animation effect.
    }

    //Prevent walking off the screen.
    if (gd == 0) {
        SDL_DestroyTexture(spriteTexture);
        spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, Textures::spriteRight1a);
        gd += 3.5;
    }

    return gd;
}


int PlayerMovement::doYWalkUp(int gy, SDL_Texture* spriteTexture) {

    if (position == 0) {
        SDL_DestroyTexture(spriteTexture);
        spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, Textures::spriteBack1a);
        gy -= 2.5; //Speed of sprite movement.
    }
    if (position == 1) {
        SDL_DestroyTexture(spriteTexture);
        spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, Textures::spriteBack2a);
        gy -= 2.5;
    }
    if (position == 2) {
        SDL_DestroyTexture(spriteTexture);
        spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, Textures::spriteBack3a);
        gy -= 2.5;
        // position = 0; //This achieves the animation effect.
    }
    if (position == 3) {
        SDL_DestroyTexture(spriteTexture);
        spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, Textures::spriteBack3a);
        gy += 2.5;
        position = 0; //This achieves the animation effect.
    }

    return gy;

}

int PlayerMovement::doYWalkDown(int gy, SDL_Texture* spriteTexture) {
    if (position == 0) {
        SDL_DestroyTexture(spriteTexture);
        spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, Textures::spriteDown3a);
        gy += 2.5; //Speed of sprite movement.
    }
    if (position == 1) {
        SDL_DestroyTexture(spriteTexture);
        spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, Textures::spriteDown1a);
        gy += 2.5;
    }
    if (position == 2) {
        SDL_DestroyTexture(spriteTexture);
        spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, Textures::spriteDown2a);
        gy += 2.5;
    }
    if (position == 3) {
        SDL_DestroyTexture(spriteTexture);
        spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, Textures::spriteDown2a);
        gy += 2.5;
        position = 0; //This achieves the animation effect.
    }

    return gy;

}



int PlayerMovement::walk(int x, int y, int gd, int gy, int screenWidth, int screenHeight, SDL_Texture* spriteTexture, SDL_Texture* ftexture,
    SDL_Texture* dialogmTexture) {

//Player Movement
   
    //Set the coordinates for walking left or right in the scene.

    ///////////////////////// SCENE 3B //////////////////////////////////////
    if (Scene1::SceneBackground == "3b") {

        if (gy <300 && gd <500) {
            SDL_DestroyTexture(spriteTexture);
            spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, Textures::spriteRight1a);
            gd += 3.5; //Speed of sprite movement.
        }
        //GOING RIGHT
        else if (gd <= x - 60 && y > 120 && y < 575) {
            gd = doXWalkRight(gd, spriteTexture, screenWidth);
            position++;
        }
        //GOING LEFT
        else if (gd >= x && y > 120 && y < 575) {
            gd = doXWalkLeft(gd, spriteTexture, screenWidth);

            position++;
        }
        else {}

        return gd;
    }

    ///////////////////////// SCENE 3A //////////////////////////////////////

    //GOING RIGHT
    if (Scene1::SceneBackground == "3a") {

        if (gd <= x - 60 && y > 120 && y < 575) {
            gd = doXWalkRight(gd, spriteTexture, screenWidth);
            position++;
        }

        //GOING LEFT
        else if (gd >= x && y > 120 && y < 575) {
            gd = doXWalkLeft(gd, spriteTexture, screenWidth);
            position++;
        }
        else {}

        return gd;
    }

    ///////////////////////// SCENE 1DA  INSIDE TENT //////////////////////////////////////
    if (Scene1::SceneBackground == "1da") {

        //Custom Boundries (Chairs etc) very tricky.
        if (gd == 541 && gy <360) {    
            SDL_DestroyTexture(spriteTexture);
            spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, Textures::spriteLeft1a);
            gd -= 3.5;
        }

        if (gd == 244 && y <= 500) {
            SDL_DestroyTexture(spriteTexture);
            spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, Textures::spriteDownp);
            gd += 3.5;
        }
     
        //GOING RIGHT
        else if (gd <= x - 60 && y > 120 && y < 575 && gd <739) {
            gd = doXWalkRight(gd, spriteTexture, screenWidth);
            position++;
        }

        //GOING LEFT
        else if (gd >= x && y > 120 && y < 575) {
            gd = doXWalkLeft(gd, spriteTexture, screenWidth);
            position++;
        }
      
        else {}

        return gd;
    }

    ///////////////////////// SCENE 1F  SANDY CLEARING //////////////////////////////////////
    if (Scene1::SceneBackground == "1f") {

        //GOING RIGHT
        if (gd <= x - 60 && y > 120 && y < 575) {
            gd = doXWalkRight(gd, spriteTexture, screenWidth);
            position++;
        }

        //GOING LEFT
        else if (gd >= x && y > 120 && y < 575) {
            gd = doXWalkLeft(gd, spriteTexture, screenWidth);
            position++;
        }
        else {}

        return gd;
    }

    ///////////////////////// SCENE 1FB SANDY CLAERING WITH TENT //////////////////////////////////////
    if (Scene1::SceneBackground == "1fb") {

        //GOING RIGHT
        if (gd <= x - 60 && y > 120 && y < 575) {
            gd = doXWalkRight(gd, spriteTexture, screenWidth);
            position++;
        }

        //GOING LEFT
        else if (gd >= x && y > 120 && y < 575) {
            gd = doXWalkLeft(gd, spriteTexture, screenWidth);
            position++;
        }
        else {}

        return gd;
    }

    ///////////////////////// SCENE 1E ROCKY SCENE //////////////////////////////////////

    //GOING RIGHT
    if (Scene1::SceneBackground == "1e") {

        if (gd <= x  && y > 272 && y < 579) {
            gd = doXWalkRight(gd, spriteTexture, screenWidth);
            position++;
        }

        //GOING LEFT
        else if (gd >= x  && y > 272 && y < 579) {
            gd = doXWalkLeft(gd, spriteTexture, screenWidth);
            position++;
        }

        else {}

        return gd;
    }

    ///////////////////////// SCENE 1B INSIDE SHIP WRECKAGE //////////////////////////////////////
    if (Scene1::SceneBackground == "1b") {

        //Set boundries where player can walk (To prevent walking too far)
        if (gd < 200) {
            SDL_DestroyTexture(spriteTexture);
            spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, Textures::spriteDown1a);
            Scene1::sceneHalt = 1;
            gd += 9.5; //Speed of sprite movement.
        }
       
        if (gd > 560) {
            SDL_DestroyTexture(spriteTexture);
            spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, Textures::spriteDown1a);
            Scene1::sceneHalt = 1;
            gd -= 9.5; //Speed of sprite movement.
        }

        //GO RIGHT
        if (gd <= x -40 && y > 320 && y < 575) {
            gd = doXWalkRight(gd, spriteTexture, screenWidth);
            position++;
        }

        //GO LEFT
        else if (gd >= x +40 && y > 300 && y < 575) {
            gd = doXWalkLeft(gd, spriteTexture, screenWidth);
            position++;
        }

        return gd;
    }


    ///////////////////////// SCENE 1 STARTING SCENE //////////////////////////////////////
    if (Scene1::SceneBackground == "1") {
        
        //GO RIGHT
        if (gd <= x - 60 && y > 320 && y < 575) {    
            gd = doXWalkRight(gd, spriteTexture, screenWidth);
            position++;
        }

        //GO LEFT
        else if (gd >= x  && y > 320 && y < 575) {
            gd = doXWalkLeft(gd, spriteTexture, screenWidth);
            position++;
        }
        else {}

        return gd;
    }
}//END OF WALK METHOD


/////////////////////////////// WALKY IS FOR MOVING THE CHARACTER UP AND DOWN  ////////////////////////////////////////////////////////////////


int PlayerMovement::walky(int x, int y, int gd, int gy, int screenWidth, int screenHeight, SDL_Texture* spriteTexture, SDL_Texture* ftexture,
    SDL_Texture* dialogmTexture) {

    //Check if player has put patch on their suit.
    if (Scene1::inv3Used == 1) {
       Textures::spriteDown1a = Textures::spriteDownp;
       Textures::spriteDown2a = Textures::spriteDown2p;
       Textures::spriteDown3a = Textures::spriteDown3p;
    }

    ///////////////////////// SCENE 3A //////////////////////////////////////
    if (Scene1::SceneBackground == "3a") {
        
        //GOING UP
        if (gy >= y && y < 570 && y >0) {
            gy = doYWalkUp(gy, spriteTexture);
            position++;
        }

        //GOING DOWN
        else if (gy <= y && y < 590 && gy > 0) {
            gy = doYWalkDown(gy, spriteTexture);
            position++;
        }

        return gy;
    }

    ///////////////////////// SCENE 1E ROCKY SCENE//////////////////////////////////////
    if (Scene1::SceneBackground == "1e") {

        //GOING UP
        if (gy >= y && y < 570 && y >330) {
            gy = doYWalkUp(gy, spriteTexture);
            position++;
        }

        //GOING DOWN
        else if (gy <= y && y < 580 && gy < 386) {
            gy = doYWalkDown(gy, spriteTexture);
            position++;
        }

        return gy;
    }

    ///////////////////////// SCENE 1B INSIDE SPACE SHIP WRECKAGE //////////////////////////////////////
    if (Scene1::SceneBackground == "1b") {

        //GOING UP
        if (gy >= y && y < 570 && y >330 ) {
            gy = doYWalkUp(gy, spriteTexture);
            position++;
        }
        
        //GOING DOWN
        else if (gy <= y && y < 575 && y > gd && gy > 250 && gy < 445) {
            gy = doYWalkDown(gy, spriteTexture);
            position++;
        }

        return gy;
    }

    ///////////////////////// SCENE 1F SANDY CLEARING //////////////////////////////////////
    if (Scene1::SceneBackground == "1f") {

        //Make the character appaer smaller as they move up and down.
        if (gy < 290) {
            Scene1::SPRITE_SIZE = 70;
        }
        if (gy < 310) {
            Scene1::SPRITE_SIZE = 100;
        }
        if (gy < 355) {
            Scene1::SPRITE_SIZE = 110;
        }

        if (gy > 355) {
            Scene1::SPRITE_SIZE = 120;
        }

        //GOING UP
        if (gy >= y && y < 575 && y >158) {
            gy = doYWalkUp(gy, spriteTexture);
            position++;
        }

        //GOING DOWN
        else if (gy <= y - 100 && y < 575) {
            gy = doYWalkDown(gy, spriteTexture);
            position++;
        }

        return gy;
    }
    
    ///////////////////////// SCENE 1FB SANDY CLEARING WITH TENT //////////////////////////////////////
    if (Scene1::SceneBackground == "1fb") {

        //Make character smaller and bigger depending on distance.
        if (gy < 290) {
            Scene1::SPRITE_SIZE = 70;
        }
        if (gy < 310) {
            Scene1::SPRITE_SIZE = 100;
        }
        if (gy < 355) {
            Scene1::SPRITE_SIZE = 110;
        }

        if (gy > 355) {
            Scene1::SPRITE_SIZE = 120;
        }

        //GOING UP
        if (gy >= y && y < 575 && y >158) {
            gy = doYWalkUp(gy, spriteTexture);
            position++;
        }

        //GOING DOWN
        else if (gy <= y - 100 && y < 575) {    
            gy = doYWalkDown(gy, spriteTexture);
            position++;
        }

        return gy;
    }

    ///////////////////////// SCENE 1DA INSIDE TENT //////////////////////////////////////
    if (Scene1::SceneBackground == "1da") {

        //GOING UP
        if (gy >= y && y < 575 && y >290 && x > 300) {
            gy = doYWalkUp(gy, spriteTexture);
            position++;
        }

        //GOING DOWN
        else if (gy <= y - 100 && y < 565 && x > 300 && gy <410 ) {
            gy = doYWalkDown(gy, spriteTexture);
            position++;
        }

        return gy;
    }


    ///////////////////////// SCENE 1 FIRST SCENE //////////////////////////////////////
    if (Scene1::SceneBackground == "1") {

        //Make character bigger or smaller depending on distance.
        if (gy < 390) {
            Scene1::SPRITE_SIZE = 90;
        }
        if (gy < 400) {
            Scene1::SPRITE_SIZE = 110;
        }

        if (gy > 440) {
            Scene1::SPRITE_SIZE = 120;
        }

        //GOING UP
        if (gy >= y && y < 575 && y >258) {
            gy = doYWalkUp(gy, spriteTexture);
            position++;
        }

        //GOING DOWN
        else if (gy <= y - 100 && y < 575) {
            gy = doYWalkDown(gy, spriteTexture);
            position++;
        }

        return gy;
    }
}//END OF WALKY METHOD



