<<<<<<< HEAD
 #include "PlayerMovement.h"
#include <iostream>
#include <SDL.h>
#include "Scene1.h"

using namespace brightland;
using namespace std;

static int position;

//Global
static int SPRITE_SIZE;
static std::string sceneBackground;
static int inv3Used; //This is to check if the player has used the duct tape.

SDL_Surface* spriteDownTape = NULL;
SDL_Surface* spriteDown1a = NULL;
SDL_Surface* spriteDown2a = NULL;
SDL_Surface* spriteDown3a = NULL;

SDL_Surface* spriteDownp = NULL;
SDL_Surface* spriteDown2p = NULL;
SDL_Surface* spriteDown3p = NULL;

SDL_Surface* spriteRight1a = NULL;
SDL_Surface* spriteRight2a = NULL;
SDL_Surface* spriteRight3a = NULL;
SDL_Surface* spriteRight4a = NULL;

SDL_Surface* spriteLeft1a = NULL;
SDL_Surface* spriteLeft2a = NULL;
SDL_Surface* spriteLeft3a = NULL;
SDL_Surface* spriteLeft4a = NULL;

SDL_Surface* spriteBack1a = NULL;
SDL_Surface* spriteBack2a = NULL;
SDL_Surface* spriteBack3a = NULL;

void PlayerMovement::LoadMovementTextures() {

    spriteDownTape = IMG_Load("PlayerMovement/ThePlanet/spriteAction1.png");
    spriteDown1a = IMG_Load("PlayerMovement/ThePlanet/sprite.png");
    spriteDown2a = IMG_Load("PlayerMovement/ThePlanet/sprite2.png");
    spriteDown3a = IMG_Load("PlayerMovement/ThePlanet/sprite3.png");

    spriteDownp = IMG_Load("PlayerMovement/ThePlanet/spritep.png");
    spriteDown2p = IMG_Load("PlayerMovement/ThePlanet/sprite2p.png");
    spriteDown3p = IMG_Load("PlayerMovement/ThePlanet/sprite3p.png");

    spriteRight1a = IMG_Load("PlayerMovement/ThePlanet/spriter1.png");
    spriteRight2a = IMG_Load("PlayerMovement/ThePlanet/spriter2.png");
    spriteRight3a = IMG_Load("PlayerMovement/ThePlanet/spriter3.png");
    spriteRight4a = IMG_Load("PlayerMovement/ThePlanet/spriter4.png");

    spriteLeft1a = IMG_Load("PlayerMovement/ThePlanet/spriteL1.png");
    spriteLeft2a = IMG_Load("PlayerMovement/ThePlanet/spriteL2.png");
    spriteLeft3a = IMG_Load("PlayerMovement/ThePlanet/spriteL3.png");
    spriteLeft4a = IMG_Load("PlayerMovement/ThePlanet/spriteL4.png");

    spriteBack1a = IMG_Load("PlayerMovement/ThePlanet/spriteback1.png");
    spriteBack2a = IMG_Load("PlayerMovement/ThePlanet/spriteback2.png");
    spriteBack3a = IMG_Load("PlayerMovement/ThePlanet/spriteback3.png");
}

int PlayerMovement::walk(int x, int y, int gd, int gy, int screenWidth, int screenHeight, SDL_Texture* spriteTexture, SDL_Texture* ftexture,
    SDL_Texture* dialogmTexture) {

//Player Movement

    SDL_DestroyTexture(spriteTexture);
    spriteTexture = SDL_CreateTextureFromSurface(Scene1::Scene1::renderer, spriteDown1a);

    //Set the coordinates for walking on the given Scene background.

    if (Scene1::SceneBackground == "3b") {

        if (gy <300 && gd <500) {
            SDL_DestroyTexture(spriteTexture);
            spriteTexture = SDL_CreateTextureFromSurface(Scene1::Scene1::renderer, spriteRight1a);
            gd += 3.5; //Speed of sprite movement.
        }

        else if (gd <= x - 60 && y > 120 && y < 575) {

            if (position == 0) {

                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::Scene1::renderer, spriteRight1a);
                gd += 3.5; //Speed of sprite movement.
            }
            if (position == 1) {

                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::Scene1::renderer, spriteRight2a);
                gd += 3.5;
            }
            if (position == 2) {

                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::Scene1::renderer, spriteRight3a);
                gd += 3.5;
            }
            if (position == 3) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteRight4a);
                gy += 1;
                position = 0; //This achieves the animation effect.
            }

            if (gd == screenWidth - 50) {

                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::Scene1::renderer, spriteLeft1a);
                gd -= 3.5;
            }

            position++;

        }

        else if (gd >= x && y > 120 && y < 575) {
            if (position == 0) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::Scene1::renderer, spriteLeft1a);
                gd -= 3.5;
            }
            if (position == 1) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::Scene1::renderer, spriteLeft2a);
                gd -= 3.5;
            }
            if (position == 2) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::Scene1::renderer, spriteLeft3a);
                //  position = 0;
                gd -= 3.5;
            }
            if (position == 3) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteLeft4a);
                gy += 1;
                position = 0; //This achieves the animation effect.
            }

            if (gd == 0) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::Scene1::renderer, spriteRight1a);
                gd += 3.5;
            }

            position++;
        }
        else {}

        return gd;
    }

    if (Scene1::SceneBackground == "3a") {

        if (gd <= x - 60 && y > 120 && y < 575) {

            if (position == 0) {

                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::Scene1::renderer, spriteRight1a);
                gd += 3.5; //Speed of sprite movement.
            }
            if (position == 1) {

                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::Scene1::renderer, spriteRight2a);
                gd += 3.5;
            }
            if (position == 2) {

                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::Scene1::renderer, spriteRight3a);
                gd += 3.5;
            }
            if (position == 3) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteRight4a);
                gy += 1;
                position = 0; //This achieves the animation effect.
            }

            if (gd == screenWidth - 50) {

                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::Scene1::renderer, spriteLeft1a);
                gd -= 3.5;
            }

            position++;

        }

        else if (gd >= x && y > 120 && y < 575) {
            if (position == 0) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::Scene1::renderer, spriteLeft1a);
                gd -= 3.5;
            }
            if (position == 1) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::Scene1::renderer, spriteLeft2a);
                gd -= 3.5;
            }
            if (position == 2) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::Scene1::renderer, spriteLeft3a);
                //  position = 0;
                gd -= 3.5;
            }
            if (position == 3) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteLeft4a);
                gy += 1;
                position = 0; //This achieves the animation effect.
            }

            if (gd == 0) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::Scene1::renderer, spriteRight1a);
                gd += 3.5;
            }

            position++;
        }
        else {}

        return gd;
    }

    if (Scene1::SceneBackground == "1da") {

        //Custom Boundries (Chairs etc).
        if (gd == 541 && gy <360) {
      
            SDL_DestroyTexture(spriteTexture);
            spriteTexture = SDL_CreateTextureFromSurface(Scene1::Scene1::renderer, spriteLeft1a);
            gd -= 3.5;
        }

        if (gd == 244 && y <= 500) {
            SDL_DestroyTexture(spriteTexture);
            spriteTexture = SDL_CreateTextureFromSurface(Scene1::Scene1::renderer, spriteDownp);
            gd += 3.5;
        }
     

        else if (gd <= x - 60 && y > 120 && y < 575 && gd <739) {

            if (position == 0) {

                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::Scene1::renderer, spriteRight1a);
                gd += 3.5; //Speed of sprite movement.
            }
            if (position == 1) {

                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::Scene1::renderer, spriteRight2a);
                gd += 3.5;
            }
            if (position == 2) {

                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::Scene1::renderer, spriteRight3a);
                gd += 3.5;
               // position = 0; //This achieves the animation effect.
            }
            if (position == 3) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteRight4a);
                gy += 1;
                position = 0; //This achieves the animation effect.
            }

            if (gd == screenWidth - 50) {

                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::Scene1::renderer, spriteLeft1a);
                gd -= 3.5;
            }

            position++;

        }

        else if (gd >= x && y > 120 && y < 575) {
            if (position == 0) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::Scene1::renderer, spriteLeft1a);
                gd -= 3.5;
            }
            if (position == 1) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::Scene1::renderer, spriteLeft2a);
                gd -= 3.5;
            }
            if (position == 2) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::Scene1::renderer, spriteLeft3a);
                gd -= 3.5;
            }
            if (position == 3) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteLeft4a);
                gy += 1;
                position = 0; //This achieves the animation effect.
            }

            if (gd == 0) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::Scene1::renderer, spriteRight1a);
                gd += 3.5;
            }

            position++;
        }

       
        else {}

        return gd;
    }

    if (Scene1::SceneBackground == "1f") {

        if (gd <= x - 60 && y > 120 && y < 575) {

            if (position == 0) {

                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::Scene1::renderer, spriteRight1a);
                gd += 3.5; //Speed of sprite movement.
            }
            if (position == 1) {

                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::Scene1::renderer, spriteRight2a);
                gd += 3.5;
            }
            if (position == 2) {

                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::Scene1::renderer, spriteRight3a);
                gd += 3.5;
            }
            if (position == 3) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteRight4a);
                gy += 1;
                position = 0; //This achieves the animation effect.
            }

            if (gd == screenWidth - 50) {

                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::Scene1::renderer, spriteLeft1a);
                gd -= 3.5;
            }

            position++;

        }

        else if (gd >= x && y > 120 && y < 575) {
            if (position == 0) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::Scene1::renderer, spriteLeft1a);
                gd -= 3.5;
            }
            if (position == 1) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::Scene1::renderer, spriteLeft2a);
                gd -= 3.5;
            }
            if (position == 2) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::Scene1::renderer, spriteLeft3a);
                gd -= 3.5;
            }
            if (position == 3) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteLeft4a);
                gy += 1;
                position = 0; //This achieves the animation effect.
            }

            if (gd == 0) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::Scene1::renderer, spriteRight1a);
                gd += 3.5;
            }

            position++;
        }
        else {}

        return gd;
    }

    if (Scene1::SceneBackground == "1fb") {

        if (gd <= x - 60 && y > 120 && y < 575) {

            if (position == 0) {

                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::Scene1::renderer, spriteRight1a);
                gd += 3.5; //Speed of sprite movement.
            }
            if (position == 1) {

                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::Scene1::renderer, spriteRight2a);
                gd += 3.5;
            }
            if (position == 2) {

                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::Scene1::renderer, spriteRight3a);
                gd += 3.5;
            }
            if (position == 3) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteRight4a);
                gy += 1;
                position = 0; //This achieves the animation effect.
            }

            if (gd == screenWidth - 50) {

                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::Scene1::renderer, spriteLeft1a);
                gd -= 3.5;
            }

            position++;

        }

        else if (gd >= x && y > 120 && y < 575) {
            if (position == 0) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::Scene1::renderer, spriteLeft1a);
                gd -= 3.5;
            }
            if (position == 1) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::Scene1::renderer, spriteLeft2a);
                gd -= 3.5;
            }
            if (position == 2) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::Scene1::renderer, spriteLeft3a);
              //  position = 0;
                gd -= 3.5;
            }
            if (position == 3) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteLeft4a);
                gy += 1;
                position = 0; //This achieves the animation effect.
            }

            if (gd == 0) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::Scene1::renderer, spriteRight1a);
                gd += 3.5;
            }

            position++;
        }
        else {}

        return gd;
    }



    if (Scene1::SceneBackground == "1e") {



        if (gd <= x  && y > 272 && y < 579) {

            if (position == 0) {

                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::Scene1::renderer, spriteRight1a);
                gd += 3.5; //Speed of sprite movement.
            }
            if (position == 1) {

                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::Scene1::renderer, spriteRight2a);
                gd += 3.5;
            }
            if (position == 2) {

                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::Scene1::renderer, spriteRight3a);
                gd += 3.5;
            //    position = 0; //This achieves the animation effect.
            }
            if (position == 3) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteRight4a);
                gy += 1;
                position = 0; //This achieves the animation effect.
            }

            //Set boundries where player can walk
            if (gd == 1000) {

                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::Scene1::renderer, spriteLeft1a);
                gd -= 3.5;
            }

            position++;

        }

        else if (gd >= x  && y > 272 && y < 579) {
            if (position == 0) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::Scene1::renderer, spriteLeft1a);
                gd -= 3.5;
            }
            if (position == 1) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::Scene1::renderer, spriteLeft2a);
                gd -= 3.5;
            }
            if (position == 2) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::Scene1::renderer, spriteLeft3a);
              //  position = 0;
                gd -= 3.5;
            }
            if (position == 3) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteLeft4a);
                gy += 1;
                position = 0; //This achieves the animation effect.
            }

            //Set boundries where player can walk
            if (gd == 0) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::Scene1::renderer, spriteRight1a);
                gd += 3.5;
            }

            position++;
        }

        else {
         //   std::cout << "SCENE 1B!!!!!!" << std::endl;
         //   SDL_DestroyTexture(spriteTexture);
           // spriteTexture = SDL_CreateTextureFromSurface(Scene1::Scene1::renderer, spriteDown1a);
        }

        return gd;
    }


    if (Scene1::SceneBackground == "1b") {



        if (gd <= x - 40 && y > 272 && y < 579) {

            if (position == 0) {

                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteRight1a);
                gd += 3.5; //Speed of sprite movement.
            }
            if (position == 1) {

                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteRight2a);
                gd += 3.5;
            }
            if (position == 2) {

                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteRight3a);
                gd += 3.5;
             //   position = 0; //This achieves the animation effect.
            }
            if (position == 3) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteRight4a);
                gy += 2.5;
                position = 0; //This achieves the animation effect.
            }

            //Set boundries where player can walk
            if (gd == screenWidth - 380) {

                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteLeft1a);
                gd -= 3.5;
            }

            position++;

        }

        else if (gd >= x + 40 && y > 272 && y < 579) {
            if (position == 0) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteLeft1a);
                gd -= 3.5;
            }
            if (position == 1) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteLeft2a);
                gd -= 3.5;
            }
            if (position == 2) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteLeft3a);
              //  position = 0;
                gd -= 3.5;
            }
            if (position == 3) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteLeft4a);
                gy += 2.5;
                position = 0; //This achieves the animation effect.
            }

            //Set boundries where player can walk
            if (gd == 268) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteRight1a);
                gd += 3.5;
            }

            position++;
        }

        else {
       //     std::cout << "SCENE 1B!!!!!!" << std::endl;
          //  SDL_DestroyTexture(spriteTexture);
            //spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteDown1a);
        }

        return gd;
    }


    //Set the coordinates for walking on the given Scene background.
    if (Scene1::SceneBackground == "1") {

        if (gd <= x - 60 && y > 320 && y < 575) {

            if (position == 0) {

                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteRight1a);
                gd += 3.5; //Speed of sprite movement.
            }
            if (position == 1) {

                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteRight2a);
                gd += 3.5;
            }
            if (position == 2) {

                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteRight3a);
                gd += 3.5;
                //position = 0; //This achieves the animation effect.
            }
            if (position == 3) {

                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteRight4a);
                gd += 3.5;
                position = 0; //This achieves the animation effect.
            }

            if (gd == screenWidth - 50) {

                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteLeft1a);
                gd -= 3.5;
            }

            position++;

        }

        else if (gd >= x  && y > 320 && y < 575) {
            if (position == 0) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteLeft1a);
                gd -= 3.5;
            }
            if (position == 1) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteLeft2a);
                gd -= 3.5;
            }
            if (position == 2) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteLeft3a);
              //  position = 0;
                gd -= 3.5;
            }
            if (position == 3) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteLeft4a);
                position = 0;
                gd -= 3.5;
            }

            if (gd == 0) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteRight1a);
                gd += 3.5;
            }

            position++;
        }
        else {}

        return gd;
    }
}//END OF WALK METHOD

int PlayerMovement::walky(int x, int y, int gd, int gy, int screenWidth, int screenHeight, SDL_Texture* spriteTexture, SDL_Texture* ftexture,
    SDL_Texture* dialogmTexture) {

    if (Scene1::inv3Used == 1) {

       spriteDown1a = spriteDownp;
       spriteDown2a = spriteDown2p;
       spriteDown3a = spriteDown3p;
    }

    if (Scene1::SceneBackground == "3b") {
        if (gy < 378 && gd < 626) {
            SDL_DestroyTexture(spriteTexture);
            spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteDown1a);
            _sleep(100);
            gy += 1.5;
            
        }

        else if (gd > 800 && gy < 300) {
            SDL_DestroyTexture(spriteTexture);
            spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteDown1a);
            _sleep(100);
            gy += 2.5;
        }

        
   
        //UP
        else if (gy >= y && y < 570 && y > 0) {

            if (gy < 390) {
                Scene1::SPRITE_SIZE = 70;
            }
            if (gy < 290) {
                Scene1::SPRITE_SIZE = 60;
            }

          

            std::cout << gy << std::endl;
            if (position == 0) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteBack1a);
                gy -= 2.5; //Speed of sprite movement.
            }
            if (position == 1) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteBack2a);
                gy -= 2.5;
            }
            if (position == 2) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteBack3a);
                gy -= 2.5;
                // position = 0; //This achieves the animation effect.
            }
            if (position == 3) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteBack3a);
                gy += 2.5;
                position = 0; //This achieves the animation effect.
            }


            position++;


        }

        else if (gy <= y && gy < 525 && gy > 0) {
         
            if (gy > 390) {
                Scene1::SPRITE_SIZE = 80;
            }

          
            std::cout << "gy is: " << gy << std::endl;
            std::cout << "Down" << std::endl;


            if (position == 0) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteDown3a);
                gy += 2.5; //Speed of sprite movement.
            }
            if (position == 1) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteDown1a);
                gy += 2.5;
            }
            if (position == 2) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteDown2a);
                gy += 2.5;
                // position = 0; //This achieves the animation effect.
            }
            if (position == 3) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteDown2a);
                gy += 2.5;
                position = 0; //This achieves the animation effect.
            }



            position++;


        }


        return gy;
    }

    if (Scene1::SceneBackground == "3a") {


        //UP
        if (gy >= y && y < 570 && y >0) {


            std::cout << gy << std::endl;
            if (position == 0) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteBack1a);
                gy -= 2.5; //Speed of sprite movement.
            }
            if (position == 1) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteBack2a);
                gy -= 2.5;
            }
            if (position == 2) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteBack3a);
                gy -= 2.5;
                // position = 0; //This achieves the animation effect.
            }
            if (position == 3) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteBack3a);
                gy += 2.5;
                position = 0; //This achieves the animation effect.
            }


            position++;


        }

        else if (gy <= y && y < 590 && gy > 0) {


            std::cout << "gy is: " << gy << std::endl;
            std::cout << "Down" << std::endl;


            if (position == 0) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteDown3a);
                gy += 2.5; //Speed of sprite movement.
            }
            if (position == 1) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteDown1a);
                gy += 2.5;
            }
            if (position == 2) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteDown2a);
                gy += 2.5;
                // position = 0; //This achieves the animation effect.
            }
            if (position == 3) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteDown2a);
                gy += 2.5;
                position = 0; //This achieves the animation effect.
            }



            position++;


        }


        return gy;
    }


    if (Scene1::SceneBackground == "1e") {


        //UP
        if (gy >= y && y < 570 && y >330) {


            std::cout << gy << std::endl;
            if (position == 0) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteBack1a);
                gy -= 2.5; //Speed of sprite movement.
            }
            if (position == 1) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteBack2a);
                gy -= 2.5;
            }
            if (position == 2) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteBack3a);
                gy -= 2.5;
               // position = 0; //This achieves the animation effect.
            }
            if (position == 3) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteBack3a);
                gy += 2.5;
                position = 0; //This achieves the animation effect.
            }


            position++;


        }

        else if (gy <= y && y < 580 && gy < 386) {


            std::cout << "gy is: " << gy << std::endl;
            std::cout << "Down" << std::endl;


            if (position == 0) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteDown3a);
                gy += 2.5; //Speed of sprite movement.
            }
            if (position == 1) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteDown1a);
                gy += 2.5;
            }
            if (position == 2) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteDown2a);
                gy += 2.5;
               // position = 0; //This achieves the animation effect.
            }
            if (position == 3) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteDown2a);
                gy += 2.5;
                position = 0; //This achieves the animation effect.
            }



            position++;


        }


        return gy;
    }


    if (Scene1::SceneBackground == "1b") {


        //UP
        if (gy >= y && y < 570 && y >330 ) {


            std::cout << gy << std::endl;
            if (position == 0) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteBack1a);
                gy -= 2.5; //Speed of sprite movement.
            }
            if (position == 1) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteBack2a);
                gy -= 2.5;
            }
            if (position == 2) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteBack3a);
                gy -= 2.5;
              //  position = 0; //This achieves the animation effect.
            }
            if (position == 3) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteBack3a);
                gy += 2.5;
                position = 0; //This achieves the animation effect.
            }

          

            position++;


        }

        else if (gy <= y && y < 580 && gy < 200) {


            std::cout << "gy is: " << gy << std::endl;
            std::cout << "Down" << std::endl;


            if (position == 0) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteDown3a);
                gy += 2.5; //Speed of sprite movement.
            }
            if (position == 1) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteDown1a);
                gy += 2.5;
            }
            if (position == 2) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteDown2a);
                gy += 2.5;
              //  position = 0; //This achieves the animation effect.
            }
            if (position == 3) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteDown2a);
                gy += 2.5;
                position = 0; //This achieves the animation effect.
            }


            position++;


        }


        return gy;
    }


    if (Scene1::SceneBackground == "1f") {


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

        if (gy >= y && y < 575 && y >158) {


            std::cout << gy << std::endl;
            if (position == 0) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteBack1a);
                gy -= 2.5; //Speed of sprite movement.
            }
            if (position == 1) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteBack2a);
                gy -= 2.5;
            }
            if (position == 2) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteBack3a);
                gy -= 2.5;
              //  position = 0; //This achieves the animation effect.
            }
            if (position == 3) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteBack3a);
                gy += 2.5;
                position = 0; //This achieves the animation effect.
            }

            position++;


        }

        else if (gy <= y - 100 && y < 575) {

          //  Scene1::SPRITE_SIZE = 120;

            std::cout << "gy is: " << gy << std::endl;
            std::cout << "Down" << std::endl;


            if (position == 0) {
                SDL_DestroyTexture(spriteTexture);

                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteDown3a);
                gy += 2.5; //Speed of sprite movement.
            }
            if (position == 1) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteDown1a);
                gy += 2.5;
            }
            if (position == 2) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteDown2a);
                gy += 2.5;
              //  position = 0; //This achieves the animation effect.
            }
            if (position == 3) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteDown2a);
                gy += 2.5;
                position = 0; //This achieves the animation effect.
            }


            position++;


        }


        return gy;
    }

    if (Scene1::SceneBackground == "1fb") {


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

        if (gy >= y && y < 575 && y >158) {


            std::cout << gy << std::endl;
            if (position == 0) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteBack1a);
                gy -= 2.5; //Speed of sprite movement.
            }
            if (position == 1) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteBack2a);
                gy -= 2.5;
            }
            if (position == 2) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteBack3a);
                gy -= 2.5;
               // position = 0; //This achieves the animation effect.
            }
            if (position == 3) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteBack3a);
                gy += 2.5;
                position = 0; //This achieves the animation effect.
            }


            position++;


        }

        else if (gy <= y - 100 && y < 575) {

            //  Scene1::SPRITE_SIZE = 120;

            std::cout << "gy is: " << gy << std::endl;
            std::cout << "Down" << std::endl;

          
            if (position == 0) {
                SDL_DestroyTexture(spriteTexture);

                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteDown3a);
                gy += 2.5; //Speed of sprite movement.
            }
            if (position == 1) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteDown1a);
                gy += 2.5;
            }
            if (position == 2) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteDown2a);
                gy += 2.5;
             //   position = 0; //This achieves the animation effect.
            }
            if (position == 3) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteDown2a);
                gy += 2.5;
                position = 0; //This achieves the animation effect.
            }



            position++;


        }


        return gy;
    }

    if (Scene1::SceneBackground == "1da") {

        

        if (gy >= y && y < 575 && y >290 && x > 300) {


            std::cout << gy << std::endl;
            if (position == 0) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteBack1a);
                gy -= 2.5; //Speed of sprite movement.
            }
            if (position == 1) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteBack2a);
                gy -= 2.5;
            }
            if (position == 2) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteBack3a);
                gy -= 2.5;
             //   position = 0; //This achieves the animation effect.
            }
            if (position == 3) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteBack3a);
                gy += 2.5;
                position = 0; //This achieves the animation effect.
            }


            position++;


        }

        else if (gy <= y - 100 && y < 565 && x > 300) {

            //  Scene1::SPRITE_SIZE = 120;

            std::cout << "gy is: " << gy << std::endl;
            std::cout << "Down" << std::endl;


            if (position == 0) {
                SDL_DestroyTexture(spriteTexture);

                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteDown3a);
                gy += 2.5; //Speed of sprite movement.
            }
            if (position == 1) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteDown1a);
                gy += 2.5;
            }
            if (position == 2) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteDown2a);
                gy += 2.5;
                //position = 0; //This achieves the animation effect.
            }
            if (position == 3) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteDown2a);
                gy += 2.5;
                position = 0; //This achieves the animation effect.
            }


            position++;


        }


        return gy;
    }



    if (Scene1::SceneBackground == "1") {

        if (gy < 390) {
            Scene1::SPRITE_SIZE = 90;
        }
        if (gy < 400) {
            Scene1::SPRITE_SIZE = 110;
        }

        if (gy > 440) {
            Scene1::SPRITE_SIZE = 120;
        }

        if (gy >= y && y < 575 && y >258) {


            std::cout << gy << std::endl;
            if (position == 0) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteBack1a);
                gy -= 2.5; //Speed of sprite movement.
            }
            if (position == 1) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteBack2a);
                gy -= 2.5;
            }
            if (position == 2) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteBack3a);
                gy -= 2.5;
              //  position = 0; //This achieves the animation effect.
            }
            if (position == 3) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteBack3a);
                gy -= 2.5;
                position = 0; //This achieves the animation effect.
            }


            position++;


        }

        else if (gy <= y - 100 && y < 575) {

            Scene1::SPRITE_SIZE = 120;

            std::cout << "gy is: " << gy << std::endl;
            std::cout << "Down" << std::endl;


            if (position == 0) {
                SDL_DestroyTexture(spriteTexture);

                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteDown3a);
                gy += 2.5; //Speed of sprite movement.
            }
            if (position == 1) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteDown1a);
                gy += 2.5;
            }
            if (position == 2) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteDown2a);
                gy += 2.5;
             //   position = 0; //This achieves the animation effect.
            }
            if (position == 3) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteDown2a);
                gy += 2.5;
                position = 0; //This achieves the animation effect.
            }



            position++;


        }


        return gy;
    }
}//END OF WALKY METHOD

=======
 #include "PlayerMovement.h"
#include <iostream>
#include <SDL.h>
#include "Scene1.h"

using namespace brightland;
using namespace std;

static int position;

//Global
static int SPRITE_SIZE;
static std::string sceneBackground;
static int inv3Used; //This is to check if the player has used the duct tape.

SDL_Surface* spriteDownTape = NULL;
SDL_Surface* spriteDown1a = NULL;
SDL_Surface* spriteDown2a = NULL;
SDL_Surface* spriteDown3a = NULL;

SDL_Surface* spriteDownp = NULL;
SDL_Surface* spriteDown2p = NULL;
SDL_Surface* spriteDown3p = NULL;

SDL_Surface* spriteRight1a = NULL;
SDL_Surface* spriteRight2a = NULL;
SDL_Surface* spriteRight3a = NULL;
SDL_Surface* spriteRight4a = NULL;

SDL_Surface* spriteLeft1a = NULL;
SDL_Surface* spriteLeft2a = NULL;
SDL_Surface* spriteLeft3a = NULL;
SDL_Surface* spriteLeft4a = NULL;

SDL_Surface* spriteBack1a = NULL;
SDL_Surface* spriteBack2a = NULL;
SDL_Surface* spriteBack3a = NULL;

void PlayerMovement::LoadMovementTextures() {

    spriteDownTape = IMG_Load("PlayerMovement/ThePlanet/spriteAction1.png");
    spriteDown1a = IMG_Load("PlayerMovement/ThePlanet/sprite.png");
    spriteDown2a = IMG_Load("PlayerMovement/ThePlanet/sprite2.png");
    spriteDown3a = IMG_Load("PlayerMovement/ThePlanet/sprite3.png");

    spriteDownp = IMG_Load("PlayerMovement/ThePlanet/spritep.png");
    spriteDown2p = IMG_Load("PlayerMovement/ThePlanet/sprite2p.png");
    spriteDown3p = IMG_Load("PlayerMovement/ThePlanet/sprite3p.png");

    spriteRight1a = IMG_Load("PlayerMovement/ThePlanet/spriter1.png");
    spriteRight2a = IMG_Load("PlayerMovement/ThePlanet/spriter2.png");
    spriteRight3a = IMG_Load("PlayerMovement/ThePlanet/spriter3.png");
    spriteRight4a = IMG_Load("PlayerMovement/ThePlanet/spriter4.png");

    spriteLeft1a = IMG_Load("PlayerMovement/ThePlanet/spriteL1.png");
    spriteLeft2a = IMG_Load("PlayerMovement/ThePlanet/spriteL2.png");
    spriteLeft3a = IMG_Load("PlayerMovement/ThePlanet/spriteL3.png");
    spriteLeft4a = IMG_Load("PlayerMovement/ThePlanet/spriteL4.png");

    spriteBack1a = IMG_Load("PlayerMovement/ThePlanet/spriteback1.png");
    spriteBack2a = IMG_Load("PlayerMovement/ThePlanet/spriteback2.png");
    spriteBack3a = IMG_Load("PlayerMovement/ThePlanet/spriteback3.png");
}

int PlayerMovement::walk(int x, int y, int gd, int gy, int screenWidth, int screenHeight, SDL_Texture* spriteTexture, SDL_Texture* ftexture,
    SDL_Texture* dialogmTexture) {

//Player Movement

    SDL_DestroyTexture(spriteTexture);
    spriteTexture = SDL_CreateTextureFromSurface(Scene1::Scene1::renderer, spriteDown1a);

    //Set the coordinates for walking on the given Scene background.

    if (Scene1::SceneBackground == "3b") {

        if (gy <300 && gd <500) {
            SDL_DestroyTexture(spriteTexture);
            spriteTexture = SDL_CreateTextureFromSurface(Scene1::Scene1::renderer, spriteRight1a);
            gd += 3.5; //Speed of sprite movement.
        }

        else if (gd <= x - 60 && y > 120 && y < 575) {

            if (position == 0) {

                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::Scene1::renderer, spriteRight1a);
                gd += 3.5; //Speed of sprite movement.
            }
            if (position == 1) {

                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::Scene1::renderer, spriteRight2a);
                gd += 3.5;
            }
            if (position == 2) {

                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::Scene1::renderer, spriteRight3a);
                gd += 3.5;
            }
            if (position == 3) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteRight4a);
                gy += 1;
                position = 0; //This achieves the animation effect.
            }

            if (gd == screenWidth - 50) {

                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::Scene1::renderer, spriteLeft1a);
                gd -= 3.5;
            }

            position++;

        }

        else if (gd >= x && y > 120 && y < 575) {
            if (position == 0) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::Scene1::renderer, spriteLeft1a);
                gd -= 3.5;
            }
            if (position == 1) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::Scene1::renderer, spriteLeft2a);
                gd -= 3.5;
            }
            if (position == 2) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::Scene1::renderer, spriteLeft3a);
                //  position = 0;
                gd -= 3.5;
            }
            if (position == 3) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteLeft4a);
                gy += 1;
                position = 0; //This achieves the animation effect.
            }

            if (gd == 0) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::Scene1::renderer, spriteRight1a);
                gd += 3.5;
            }

            position++;
        }
        else {}

        return gd;
    }

    if (Scene1::SceneBackground == "3a") {

        if (gd <= x - 60 && y > 120 && y < 575) {

            if (position == 0) {

                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::Scene1::renderer, spriteRight1a);
                gd += 3.5; //Speed of sprite movement.
            }
            if (position == 1) {

                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::Scene1::renderer, spriteRight2a);
                gd += 3.5;
            }
            if (position == 2) {

                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::Scene1::renderer, spriteRight3a);
                gd += 3.5;
            }
            if (position == 3) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteRight4a);
                gy += 1;
                position = 0; //This achieves the animation effect.
            }

            if (gd == screenWidth - 50) {

                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::Scene1::renderer, spriteLeft1a);
                gd -= 3.5;
            }

            position++;

        }

        else if (gd >= x && y > 120 && y < 575) {
            if (position == 0) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::Scene1::renderer, spriteLeft1a);
                gd -= 3.5;
            }
            if (position == 1) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::Scene1::renderer, spriteLeft2a);
                gd -= 3.5;
            }
            if (position == 2) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::Scene1::renderer, spriteLeft3a);
                //  position = 0;
                gd -= 3.5;
            }
            if (position == 3) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteLeft4a);
                gy += 1;
                position = 0; //This achieves the animation effect.
            }

            if (gd == 0) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::Scene1::renderer, spriteRight1a);
                gd += 3.5;
            }

            position++;
        }
        else {}

        return gd;
    }

    if (Scene1::SceneBackground == "1da") {

        //Custom Boundries (Chairs etc).
        if (gd == 541 && gy <360) {
      
            SDL_DestroyTexture(spriteTexture);
            spriteTexture = SDL_CreateTextureFromSurface(Scene1::Scene1::renderer, spriteLeft1a);
            gd -= 3.5;
        }

        if (gd == 244 && y <= 500) {
            SDL_DestroyTexture(spriteTexture);
            spriteTexture = SDL_CreateTextureFromSurface(Scene1::Scene1::renderer, spriteDownp);
            gd += 3.5;
        }
     

        else if (gd <= x - 60 && y > 120 && y < 575 && gd <739) {

            if (position == 0) {

                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::Scene1::renderer, spriteRight1a);
                gd += 3.5; //Speed of sprite movement.
            }
            if (position == 1) {

                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::Scene1::renderer, spriteRight2a);
                gd += 3.5;
            }
            if (position == 2) {

                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::Scene1::renderer, spriteRight3a);
                gd += 3.5;
               // position = 0; //This achieves the animation effect.
            }
            if (position == 3) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteRight4a);
                gy += 1;
                position = 0; //This achieves the animation effect.
            }

            if (gd == screenWidth - 50) {

                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::Scene1::renderer, spriteLeft1a);
                gd -= 3.5;
            }

            position++;

        }

        else if (gd >= x && y > 120 && y < 575) {
            if (position == 0) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::Scene1::renderer, spriteLeft1a);
                gd -= 3.5;
            }
            if (position == 1) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::Scene1::renderer, spriteLeft2a);
                gd -= 3.5;
            }
            if (position == 2) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::Scene1::renderer, spriteLeft3a);
                gd -= 3.5;
            }
            if (position == 3) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteLeft4a);
                gy += 1;
                position = 0; //This achieves the animation effect.
            }

            if (gd == 0) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::Scene1::renderer, spriteRight1a);
                gd += 3.5;
            }

            position++;
        }

       
        else {}

        return gd;
    }

    if (Scene1::SceneBackground == "1f") {

        if (gd <= x - 60 && y > 120 && y < 575) {

            if (position == 0) {

                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::Scene1::renderer, spriteRight1a);
                gd += 3.5; //Speed of sprite movement.
            }
            if (position == 1) {

                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::Scene1::renderer, spriteRight2a);
                gd += 3.5;
            }
            if (position == 2) {

                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::Scene1::renderer, spriteRight3a);
                gd += 3.5;
            }
            if (position == 3) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteRight4a);
                gy += 1;
                position = 0; //This achieves the animation effect.
            }

            if (gd == screenWidth - 50) {

                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::Scene1::renderer, spriteLeft1a);
                gd -= 3.5;
            }

            position++;

        }

        else if (gd >= x && y > 120 && y < 575) {
            if (position == 0) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::Scene1::renderer, spriteLeft1a);
                gd -= 3.5;
            }
            if (position == 1) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::Scene1::renderer, spriteLeft2a);
                gd -= 3.5;
            }
            if (position == 2) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::Scene1::renderer, spriteLeft3a);
                gd -= 3.5;
            }
            if (position == 3) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteLeft4a);
                gy += 1;
                position = 0; //This achieves the animation effect.
            }

            if (gd == 0) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::Scene1::renderer, spriteRight1a);
                gd += 3.5;
            }

            position++;
        }
        else {}

        return gd;
    }

    if (Scene1::SceneBackground == "1fb") {

        if (gd <= x - 60 && y > 120 && y < 575) {

            if (position == 0) {

                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::Scene1::renderer, spriteRight1a);
                gd += 3.5; //Speed of sprite movement.
            }
            if (position == 1) {

                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::Scene1::renderer, spriteRight2a);
                gd += 3.5;
            }
            if (position == 2) {

                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::Scene1::renderer, spriteRight3a);
                gd += 3.5;
            }
            if (position == 3) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteRight4a);
                gy += 1;
                position = 0; //This achieves the animation effect.
            }

            if (gd == screenWidth - 50) {

                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::Scene1::renderer, spriteLeft1a);
                gd -= 3.5;
            }

            position++;

        }

        else if (gd >= x && y > 120 && y < 575) {
            if (position == 0) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::Scene1::renderer, spriteLeft1a);
                gd -= 3.5;
            }
            if (position == 1) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::Scene1::renderer, spriteLeft2a);
                gd -= 3.5;
            }
            if (position == 2) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::Scene1::renderer, spriteLeft3a);
              //  position = 0;
                gd -= 3.5;
            }
            if (position == 3) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteLeft4a);
                gy += 1;
                position = 0; //This achieves the animation effect.
            }

            if (gd == 0) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::Scene1::renderer, spriteRight1a);
                gd += 3.5;
            }

            position++;
        }
        else {}

        return gd;
    }



    if (Scene1::SceneBackground == "1e") {



        if (gd <= x  && y > 272 && y < 579) {

            if (position == 0) {

                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::Scene1::renderer, spriteRight1a);
                gd += 3.5; //Speed of sprite movement.
            }
            if (position == 1) {

                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::Scene1::renderer, spriteRight2a);
                gd += 3.5;
            }
            if (position == 2) {

                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::Scene1::renderer, spriteRight3a);
                gd += 3.5;
            //    position = 0; //This achieves the animation effect.
            }
            if (position == 3) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteRight4a);
                gy += 1;
                position = 0; //This achieves the animation effect.
            }

            //Set boundries where player can walk
            if (gd == 1000) {

                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::Scene1::renderer, spriteLeft1a);
                gd -= 3.5;
            }

            position++;

        }

        else if (gd >= x  && y > 272 && y < 579) {
            if (position == 0) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::Scene1::renderer, spriteLeft1a);
                gd -= 3.5;
            }
            if (position == 1) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::Scene1::renderer, spriteLeft2a);
                gd -= 3.5;
            }
            if (position == 2) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::Scene1::renderer, spriteLeft3a);
              //  position = 0;
                gd -= 3.5;
            }
            if (position == 3) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteLeft4a);
                gy += 1;
                position = 0; //This achieves the animation effect.
            }

            //Set boundries where player can walk
            if (gd == 0) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::Scene1::renderer, spriteRight1a);
                gd += 3.5;
            }

            position++;
        }

        else {
         //   std::cout << "SCENE 1B!!!!!!" << std::endl;
         //   SDL_DestroyTexture(spriteTexture);
           // spriteTexture = SDL_CreateTextureFromSurface(Scene1::Scene1::renderer, spriteDown1a);
        }

        return gd;
    }


    if (Scene1::SceneBackground == "1b") {



        if (gd <= x - 40 && y > 272 && y < 579) {

            if (position == 0) {

                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteRight1a);
                gd += 3.5; //Speed of sprite movement.
            }
            if (position == 1) {

                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteRight2a);
                gd += 3.5;
            }
            if (position == 2) {

                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteRight3a);
                gd += 3.5;
             //   position = 0; //This achieves the animation effect.
            }
            if (position == 3) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteRight4a);
                gy += 2.5;
                position = 0; //This achieves the animation effect.
            }

            //Set boundries where player can walk
            if (gd == screenWidth - 380) {

                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteLeft1a);
                gd -= 3.5;
            }

            position++;

        }

        else if (gd >= x + 40 && y > 272 && y < 579) {
            if (position == 0) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteLeft1a);
                gd -= 3.5;
            }
            if (position == 1) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteLeft2a);
                gd -= 3.5;
            }
            if (position == 2) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteLeft3a);
              //  position = 0;
                gd -= 3.5;
            }
            if (position == 3) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteLeft4a);
                gy += 2.5;
                position = 0; //This achieves the animation effect.
            }

            //Set boundries where player can walk
            if (gd == 268) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteRight1a);
                gd += 3.5;
            }

            position++;
        }

        else {
       //     std::cout << "SCENE 1B!!!!!!" << std::endl;
          //  SDL_DestroyTexture(spriteTexture);
            //spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteDown1a);
        }

        return gd;
    }


    //Set the coordinates for walking on the given Scene background.
    if (Scene1::SceneBackground == "1") {

        if (gd <= x - 60 && y > 320 && y < 575) {

            if (position == 0) {

                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteRight1a);
                gd += 3.5; //Speed of sprite movement.
            }
            if (position == 1) {

                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteRight2a);
                gd += 3.5;
            }
            if (position == 2) {

                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteRight3a);
                gd += 3.5;
                //position = 0; //This achieves the animation effect.
            }
            if (position == 3) {

                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteRight4a);
                gd += 3.5;
                position = 0; //This achieves the animation effect.
            }

            if (gd == screenWidth - 50) {

                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteLeft1a);
                gd -= 3.5;
            }

            position++;

        }

        else if (gd >= x  && y > 320 && y < 575) {
            if (position == 0) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteLeft1a);
                gd -= 3.5;
            }
            if (position == 1) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteLeft2a);
                gd -= 3.5;
            }
            if (position == 2) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteLeft3a);
              //  position = 0;
                gd -= 3.5;
            }
            if (position == 3) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteLeft4a);
                position = 0;
                gd -= 3.5;
            }

            if (gd == 0) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteRight1a);
                gd += 3.5;
            }

            position++;
        }
        else {}

        return gd;
    }
}//END OF WALK METHOD

int PlayerMovement::walky(int x, int y, int gd, int gy, int screenWidth, int screenHeight, SDL_Texture* spriteTexture, SDL_Texture* ftexture,
    SDL_Texture* dialogmTexture) {

    if (Scene1::inv3Used == 1) {

       spriteDown1a = spriteDownp;
       spriteDown2a = spriteDown2p;
       spriteDown3a = spriteDown3p;
    }

    if (Scene1::SceneBackground == "3b") {
        if (gy < 378 && gd < 626) {
            SDL_DestroyTexture(spriteTexture);
            spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteDown1a);
            _sleep(100);
            gy += 1.5;
            
        }

        else if (gd > 800 && gy < 300) {
            SDL_DestroyTexture(spriteTexture);
            spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteDown1a);
            _sleep(100);
            gy += 2.5;
        }

        
   
        //UP
        else if (gy >= y && y < 570 && y > 0) {

            if (gy < 390) {
                Scene1::SPRITE_SIZE = 70;
            }
            if (gy < 290) {
                Scene1::SPRITE_SIZE = 60;
            }

          

            std::cout << gy << std::endl;
            if (position == 0) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteBack1a);
                gy -= 2.5; //Speed of sprite movement.
            }
            if (position == 1) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteBack2a);
                gy -= 2.5;
            }
            if (position == 2) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteBack3a);
                gy -= 2.5;
                // position = 0; //This achieves the animation effect.
            }
            if (position == 3) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteBack3a);
                gy += 2.5;
                position = 0; //This achieves the animation effect.
            }


            position++;


        }

        else if (gy <= y && gy < 525 && gy > 0) {
         
            if (gy > 390) {
                Scene1::SPRITE_SIZE = 80;
            }

          
            std::cout << "gy is: " << gy << std::endl;
            std::cout << "Down" << std::endl;


            if (position == 0) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteDown3a);
                gy += 2.5; //Speed of sprite movement.
            }
            if (position == 1) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteDown1a);
                gy += 2.5;
            }
            if (position == 2) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteDown2a);
                gy += 2.5;
                // position = 0; //This achieves the animation effect.
            }
            if (position == 3) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteDown2a);
                gy += 2.5;
                position = 0; //This achieves the animation effect.
            }



            position++;


        }


        return gy;
    }

    if (Scene1::SceneBackground == "3a") {


        //UP
        if (gy >= y && y < 570 && y >0) {


            std::cout << gy << std::endl;
            if (position == 0) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteBack1a);
                gy -= 2.5; //Speed of sprite movement.
            }
            if (position == 1) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteBack2a);
                gy -= 2.5;
            }
            if (position == 2) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteBack3a);
                gy -= 2.5;
                // position = 0; //This achieves the animation effect.
            }
            if (position == 3) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteBack3a);
                gy += 2.5;
                position = 0; //This achieves the animation effect.
            }


            position++;


        }

        else if (gy <= y && y < 590 && gy > 0) {


            std::cout << "gy is: " << gy << std::endl;
            std::cout << "Down" << std::endl;


            if (position == 0) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteDown3a);
                gy += 2.5; //Speed of sprite movement.
            }
            if (position == 1) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteDown1a);
                gy += 2.5;
            }
            if (position == 2) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteDown2a);
                gy += 2.5;
                // position = 0; //This achieves the animation effect.
            }
            if (position == 3) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteDown2a);
                gy += 2.5;
                position = 0; //This achieves the animation effect.
            }



            position++;


        }


        return gy;
    }


    if (Scene1::SceneBackground == "1e") {


        //UP
        if (gy >= y && y < 570 && y >330) {


            std::cout << gy << std::endl;
            if (position == 0) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteBack1a);
                gy -= 2.5; //Speed of sprite movement.
            }
            if (position == 1) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteBack2a);
                gy -= 2.5;
            }
            if (position == 2) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteBack3a);
                gy -= 2.5;
               // position = 0; //This achieves the animation effect.
            }
            if (position == 3) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteBack3a);
                gy += 2.5;
                position = 0; //This achieves the animation effect.
            }


            position++;


        }

        else if (gy <= y && y < 580 && gy < 386) {


            std::cout << "gy is: " << gy << std::endl;
            std::cout << "Down" << std::endl;


            if (position == 0) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteDown3a);
                gy += 2.5; //Speed of sprite movement.
            }
            if (position == 1) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteDown1a);
                gy += 2.5;
            }
            if (position == 2) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteDown2a);
                gy += 2.5;
               // position = 0; //This achieves the animation effect.
            }
            if (position == 3) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteDown2a);
                gy += 2.5;
                position = 0; //This achieves the animation effect.
            }



            position++;


        }


        return gy;
    }


    if (Scene1::SceneBackground == "1b") {


        //UP
        if (gy >= y && y < 570 && y >330 ) {


            std::cout << gy << std::endl;
            if (position == 0) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteBack1a);
                gy -= 2.5; //Speed of sprite movement.
            }
            if (position == 1) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteBack2a);
                gy -= 2.5;
            }
            if (position == 2) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteBack3a);
                gy -= 2.5;
              //  position = 0; //This achieves the animation effect.
            }
            if (position == 3) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteBack3a);
                gy += 2.5;
                position = 0; //This achieves the animation effect.
            }

          

            position++;


        }

        else if (gy <= y && y < 580 && gy < 200) {


            std::cout << "gy is: " << gy << std::endl;
            std::cout << "Down" << std::endl;


            if (position == 0) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteDown3a);
                gy += 2.5; //Speed of sprite movement.
            }
            if (position == 1) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteDown1a);
                gy += 2.5;
            }
            if (position == 2) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteDown2a);
                gy += 2.5;
              //  position = 0; //This achieves the animation effect.
            }
            if (position == 3) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteDown2a);
                gy += 2.5;
                position = 0; //This achieves the animation effect.
            }


            position++;


        }


        return gy;
    }


    if (Scene1::SceneBackground == "1f") {


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

        if (gy >= y && y < 575 && y >158) {


            std::cout << gy << std::endl;
            if (position == 0) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteBack1a);
                gy -= 2.5; //Speed of sprite movement.
            }
            if (position == 1) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteBack2a);
                gy -= 2.5;
            }
            if (position == 2) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteBack3a);
                gy -= 2.5;
              //  position = 0; //This achieves the animation effect.
            }
            if (position == 3) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteBack3a);
                gy += 2.5;
                position = 0; //This achieves the animation effect.
            }

            position++;


        }

        else if (gy <= y - 100 && y < 575) {

          //  Scene1::SPRITE_SIZE = 120;

            std::cout << "gy is: " << gy << std::endl;
            std::cout << "Down" << std::endl;


            if (position == 0) {
                SDL_DestroyTexture(spriteTexture);

                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteDown3a);
                gy += 2.5; //Speed of sprite movement.
            }
            if (position == 1) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteDown1a);
                gy += 2.5;
            }
            if (position == 2) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteDown2a);
                gy += 2.5;
              //  position = 0; //This achieves the animation effect.
            }
            if (position == 3) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteDown2a);
                gy += 2.5;
                position = 0; //This achieves the animation effect.
            }


            position++;


        }


        return gy;
    }

    if (Scene1::SceneBackground == "1fb") {


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

        if (gy >= y && y < 575 && y >158) {


            std::cout << gy << std::endl;
            if (position == 0) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteBack1a);
                gy -= 2.5; //Speed of sprite movement.
            }
            if (position == 1) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteBack2a);
                gy -= 2.5;
            }
            if (position == 2) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteBack3a);
                gy -= 2.5;
               // position = 0; //This achieves the animation effect.
            }
            if (position == 3) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteBack3a);
                gy += 2.5;
                position = 0; //This achieves the animation effect.
            }


            position++;


        }

        else if (gy <= y - 100 && y < 575) {

            //  Scene1::SPRITE_SIZE = 120;

            std::cout << "gy is: " << gy << std::endl;
            std::cout << "Down" << std::endl;

          
            if (position == 0) {
                SDL_DestroyTexture(spriteTexture);

                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteDown3a);
                gy += 2.5; //Speed of sprite movement.
            }
            if (position == 1) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteDown1a);
                gy += 2.5;
            }
            if (position == 2) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteDown2a);
                gy += 2.5;
             //   position = 0; //This achieves the animation effect.
            }
            if (position == 3) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteDown2a);
                gy += 2.5;
                position = 0; //This achieves the animation effect.
            }



            position++;


        }


        return gy;
    }

    if (Scene1::SceneBackground == "1da") {

        

        if (gy >= y && y < 575 && y >290 && x > 300) {


            std::cout << gy << std::endl;
            if (position == 0) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteBack1a);
                gy -= 2.5; //Speed of sprite movement.
            }
            if (position == 1) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteBack2a);
                gy -= 2.5;
            }
            if (position == 2) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteBack3a);
                gy -= 2.5;
             //   position = 0; //This achieves the animation effect.
            }
            if (position == 3) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteBack3a);
                gy += 2.5;
                position = 0; //This achieves the animation effect.
            }


            position++;


        }

        else if (gy <= y - 100 && y < 565 && x > 300) {

            //  Scene1::SPRITE_SIZE = 120;

            std::cout << "gy is: " << gy << std::endl;
            std::cout << "Down" << std::endl;


            if (position == 0) {
                SDL_DestroyTexture(spriteTexture);

                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteDown3a);
                gy += 2.5; //Speed of sprite movement.
            }
            if (position == 1) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteDown1a);
                gy += 2.5;
            }
            if (position == 2) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteDown2a);
                gy += 2.5;
                //position = 0; //This achieves the animation effect.
            }
            if (position == 3) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteDown2a);
                gy += 2.5;
                position = 0; //This achieves the animation effect.
            }


            position++;


        }


        return gy;
    }



    if (Scene1::SceneBackground == "1") {

        if (gy < 390) {
            Scene1::SPRITE_SIZE = 90;
        }
        if (gy < 400) {
            Scene1::SPRITE_SIZE = 110;
        }

        if (gy > 440) {
            Scene1::SPRITE_SIZE = 120;
        }

        if (gy >= y && y < 575 && y >258) {


            std::cout << gy << std::endl;
            if (position == 0) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteBack1a);
                gy -= 2.5; //Speed of sprite movement.
            }
            if (position == 1) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteBack2a);
                gy -= 2.5;
            }
            if (position == 2) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteBack3a);
                gy -= 2.5;
              //  position = 0; //This achieves the animation effect.
            }
            if (position == 3) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteBack3a);
                gy -= 2.5;
                position = 0; //This achieves the animation effect.
            }


            position++;


        }

        else if (gy <= y - 100 && y < 575) {

            Scene1::SPRITE_SIZE = 120;

            std::cout << "gy is: " << gy << std::endl;
            std::cout << "Down" << std::endl;


            if (position == 0) {
                SDL_DestroyTexture(spriteTexture);

                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteDown3a);
                gy += 2.5; //Speed of sprite movement.
            }
            if (position == 1) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteDown1a);
                gy += 2.5;
            }
            if (position == 2) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteDown2a);
                gy += 2.5;
             //   position = 0; //This achieves the animation effect.
            }
            if (position == 3) {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, spriteDown2a);
                gy += 2.5;
                position = 0; //This achieves the animation effect.
            }



            position++;


        }


        return gy;
    }
}//END OF WALKY METHOD

>>>>>>> f7761ba1e1b7e59876c961ce44ead324b20db46f
