#include "SceneRender.h"
#include "Textures.h"
#include "Scene1.h"

using namespace brightland;


//Global Static Variables

//This is used to identify which button was pressed. For example: New Game button.
std::string buttonID = "";

//Returns hover trigger for buttons
int SceneRender::HoverButtons(int x, int y) {

    //New game hover button (main menu)
    if (x >= 159 && x <=376 && y >=480 && y <=546 && Scene1::SceneBackground == "0") {  
        Scene1::hoverSound = 1;
        buttonID = "New Game";
        return 1;
    }
    //Continue game hover button (main menu)
    if (x >= 159 && x <= 376 && y >= 378 && y <= 438 && Scene1::SceneBackground == "0") {
        Scene1::hoverSound = 1;
        buttonID = "Continue Game";
        return 1;
    }
    //Player Options hover button (main menu)
    if (x >= 159 && x <= 376 && y >= 573 && y <= 644 && Scene1::SceneBackground == "0") {
        Scene1::hoverSound = 1;
        buttonID = "Player Options";
        return 1;
    }
   
    //Plus hover button (main menu)
    if (x >= 619 && x <= 691 && y >= 149 && y <= 178 && Scene1::SceneBackground == "01") {
        buttonID = "Plus";
        return 1;
    }
    //Minus hover button (main menu)
    if (x >= 281 && x <= 353 && y >= 149 && y <= 178 && Scene1::SceneBackground == "01") {
        buttonID = "Minus";
        return 1;
    }
    //Pickup hover button (bottom menu)
    if (x > 61 && x < 146 && y > 643 && y < 690) {
        buttonID = "Pickup";
        return 1;
    }
    //Open hover button (bottom menu)
    if (x > 178 && x < 232 && y > 723 && y < 744) {
        buttonID = "Open";
        return 1;
    }
    //Pull hover button (bottom menu)
    if (x > 59 && x < 114 && y > 723 && y < 744) {
        buttonID = "Pull";
        return 1;
    }
    //Look hover button (bottom menu)
    if (x > 57 && x < 145 && y > 621 && y < 647) {
        buttonID = "Look";
        return 1;
    }
    //Use hover button (bottom menu)
    if (x > 190 && x < 227 && y > 676 && y < 690) {
        buttonID = "Use";
        return 1;
    }



    return 0;
}


//Renders the scene backgrounds for the game.
void SceneRender::sceneRender() {


    if (Scene1::SceneBackground == "01") {
        SDL_RenderCopy(Scene1::renderer, Textures::poptions, NULL, &Textures::background);
    }


    if (Scene1::SceneBackground == "1") {
        SDL_RenderCopy(Scene1::renderer, Textures::texture, NULL, &Textures::background);
    }

    if (Scene1::SceneBackground == "1b") {
        SDL_RenderCopy(Scene1::renderer, Textures::wreakageScene, NULL, &Textures::background);
    }

    if (Scene1::SceneBackground == "1e") {
        SDL_RenderCopy(Scene1::renderer, Textures::scene1e, NULL, &Textures::background);
    }

    if (Scene1::SceneBackground == "1f") {
        SDL_RenderCopy(Scene1::renderer, Textures::scene1f, NULL, &Textures::background);
    }

    if (Scene1::SceneBackground == "1fb") {
        SDL_RenderCopy(Scene1::renderer, Textures::scene1fb, NULL, &Textures::background);
    }

    if (Scene1::SceneBackground == "1da") {
        SDL_RenderCopy(Scene1::renderer, Textures::scene1d, NULL, &Textures::background);
    }

    if (Scene1::SceneBackground == "1db") {
        SDL_RenderCopy(Scene1::renderer, Textures::scene1d2, NULL, &Textures::background);
    }

    if (Scene1::SceneBackground == "3a") {
        SDL_RenderCopy(Scene1::renderer, Textures::scene3a, NULL, &Textures::background);
    }
    if (Scene1::SceneBackground == "3b") {
        SDL_RenderCopy(Scene1::renderer, Textures::scene3b, NULL, &Textures::background);
    }
    if (Scene1::SceneBackground == "3d") {
        SDL_RenderCopy(Scene1::renderer, Textures::caveScene2, NULL, &Textures::background);
    }
    if (Scene1::SceneBackground == "3f") {
        SDL_RenderCopy(Scene1::renderer, Textures::scene3f, NULL, &Textures::background);

        //if the number 7 was NOT found in the objectToDestroy string then display the object on the scene.
        if (Scene1::objectToDestroy.find("7") == std::string::npos) {
            SDL_RenderCopy(Scene1::renderer, Textures::objectTextureSparkle, &PlayerObjects::srcrect9, &PlayerObjects::dstrect9);
        }

        if (Scene1::secretTrigger < 2) {
            SDL_RenderCopy(Scene1::renderer, Textures::rocks4, NULL, &Textures::background5);
        }
            
    }
   
}

//Renders objects that appear in front of the player like rocks as an example.
void SceneRender::sceneRenderOverlay(int x, int y) {

   int hoverTrigger = HoverButtons(x, y);
   if(Scene1::SceneBackground !="0" || Scene1::SceneBackground !="01"){

        if (hoverTrigger == 1 && buttonID == "Pickup") {
            SDL_RenderCopy(Scene1::renderer, Textures::hoverPickup, NULL, &Textures::RHoverPickup);
        }
        if (hoverTrigger == 1 && buttonID == "Pull") {
            SDL_RenderCopy(Scene1::renderer, Textures::hoverPull, NULL, &Textures::RHoverPull);      
        }
        if (hoverTrigger == 1 && buttonID == "Open") {
            SDL_RenderCopy(Scene1::renderer, Textures::hoverOpen, NULL, &Textures::RHoverOpen);        
        }
        if (hoverTrigger == 1 && buttonID == "Look") {
            SDL_RenderCopy(Scene1::renderer, Textures::hoverLook, NULL, &Textures::RHoverLook);        
        }
        if (hoverTrigger == 1 && buttonID == "Use") {
            SDL_RenderCopy(Scene1::renderer, Textures::hoverUse, NULL, &Textures::RHoverUse);
        }
   }

    if (Scene1::SceneBackground == "0") {
       
        SDL_RenderCopy(Scene1::renderer, Textures::mainMenu, NULL, &Textures::menuBackground);
        SDL_RenderCopy(Scene1::renderer, Textures::starsTexture, &PlayerObjects::srcrect3, &PlayerObjects::dstrect3);
        if (hoverTrigger == 1 && buttonID == "New Game") {           
            SDL_RenderCopy(Scene1::renderer, Textures::hoverNewGame, NULL, &Textures::RHoverNewGame);
        }
        if (hoverTrigger == 1 && buttonID == "Continue Game") {
            SDL_RenderCopy(Scene1::renderer, Textures::hoverContinueGame, NULL, &Textures::RHoverConinueGame);
        }
        if (hoverTrigger == 1 && buttonID == "Player Options") {
            SDL_RenderCopy(Scene1::renderer, Textures::hoverOptions, NULL, &Textures::RHoverOptions);
        }
       
    }
    if (Scene1::SceneBackground == "01") {
        if (hoverTrigger == 1 && buttonID == "Plus") {
            SDL_RenderCopy(Scene1::renderer, Textures::hoverPlus, NULL, &Textures::RHoverPlus);
        }
        if (hoverTrigger == 1 && buttonID == "Minus") {
            SDL_RenderCopy(Scene1::renderer, Textures::hoverMinus, NULL, &Textures::RHoverMinus);
        }
    }

    if (Scene1::SceneBackground == "1") {
        SDL_RenderCopy(Scene1::renderer, Textures::starsTexture, &PlayerObjects::srcrect3, &PlayerObjects::dstrect3);
        SDL_RenderCopy(Scene1::renderer, Textures::rocks, NULL, &Textures::background2);
    }


    if (Scene1::SceneBackground == "1c") {

        SDL_RenderCopy(Scene1::renderer, Textures::computerScene1, NULL, &Textures::background);
    }

    if (Scene1::SceneBackground == "1d") {

        SDL_RenderCopy(Scene1::renderer, Textures::computerScene2, NULL, &Textures::background);
    }

    if (Scene1::SceneBackground == "1e") {

        SDL_RenderCopy(Scene1::renderer, Textures::rocks2, NULL, &Textures::background3);
    }

   if (Scene1::SceneBackground == "3c") {
    SDL_RenderCopy(Scene1::renderer, Textures::caveScene1, NULL, &Textures::background);
   }

   if (Scene1::SceneBackground == "3d") {
       SDL_RenderCopy(Scene1::renderer, Textures::rocks3, NULL, &Textures::background4);
   }

   if (Scene1::SceneBackground == "3e") {
       SDL_RenderCopy(Scene1::renderer, Textures::scene3e, NULL, &Textures::background);
   }


    //Cut Scene (Hide sprite)
    if (Scene1::SceneBackground == "1fa") {
        SDL_RenderCopy(Scene1::renderer, Textures::scene1fa, NULL, &Textures::background);
    }
    //Cardboard Box (In front of sprite)
    if (Scene1::SceneBackground == "1da" || Scene1::SceneBackground == "1db") {
        SDL_RenderCopy(Scene1::renderer, Textures::objectTexture6, &PlayerObjects::srcrect6, &PlayerObjects::dstrect6);

    }


    SDL_RenderCopy(Scene1::renderer, Textures::cursor, NULL, &Textures::RCursor);  //Render the custom mouse cursor last of all (keeps it on top).

    if(Scene1::playerIsMoving == 0){
        SDL_RenderCopy(Scene1::renderer, Textures::blink, &PlayerObjects::srcrect10, &PlayerObjects::dstrect10);
    }
}

