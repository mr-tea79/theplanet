#include "MenuInteraction.h"
#include <SDL.h>
#include <iostream>
#include "Scene1.h"
#include "Textures.h"
#include "Inventory.h"

using namespace brightland;


static std::string useStatement;
static std::string openStatement;
static std::string lookStatement;
static std::string pickUpStatement;
static std::string actionStatement;


static int playerMessage;


void MenuInteraction::doAction() {
    Scene1::sceneHalt = 1;
    Scene1::action = 1;
    Scene1::actionStatement = "";
}

std::string MenuInteraction::MenuAction(int x, int y, int gd, int gy, int mInteraction) {

    std::string actionMessage;

    PlayerObjects pob;
    Inventory inv;

    if (x > 57 && x < 145 && y > 621 && y < 647) {
        useStatement = "";  //Important
        actionStatement = Scene1::actionStatement = "Look at";
        actionMessage = "Look at what?";
        lookStatement = "";
        
    }

    if (x > 61 && x < 146 && y > 643 && y < 690) {
        useStatement = "";
        actionStatement = Scene1::actionStatement = "Pick up";
        actionMessage = "Pick up what?";
        pickUpStatement = "";
    }

    if (x > 190 && x < 227 && y > 676 && y < 690) {
        useStatement = "";
        actionStatement = Scene1::actionStatement = "Use";
        actionMessage = "Use what?";
        useStatement = "";
    }

    if (x > 178 && x < 232 && y > 723 && y < 744) {
        useStatement = "";
        actionStatement = Scene1::actionStatement = "Open";
        actionMessage = "Open what?";
        openStatement = "";
    }

    return actionMessage;
}

std::string MenuInteraction::Look(int x, int y, int gd, int gy, int mInteraction) {

    std::string lookMessage;

    PlayerObjects pob;
    Inventory inv;
    int n = lookStatement.length();

    if (n < 8) { //Don't override hover if a pick up statement has been selected. This is important, otherwise player will pick up anything within range no matter what you chose to pick up.
        lookStatement = pob.HoverObjects(x, y, 1, gd, gy);
    }
    if (lookStatement == "Look at Cave door drawing") {
        lookMessage = "Seems like a cave door with the artifact placed in it. Weird.";
        SDL_DestroyTexture(Textures::spriteTexture);
        SDL_CreateTextureFromSurface(Scene1::renderer, Textures::spriteBack1a);
        doAction();
        lookStatement = "";
    }

    if (lookStatement == "Look at Artifact drawing") {
        lookMessage = "That looks like an artifact which has a line pointing to south America.";
        SDL_DestroyTexture(Textures::spriteTexture);
        SDL_CreateTextureFromSurface(Scene1::renderer, Textures::spriteBack1a);
        doAction();
        lookStatement = "";
    }

    if (lookStatement == "Look at Alien solar system drawing") {
        lookMessage = "I think this is the system I am in. Those lines are the planet that I am on.";
        SDL_DestroyTexture(Textures::spriteTexture);
        SDL_CreateTextureFromSurface(Scene1::renderer, Textures::spriteBack1a);
        doAction();
        lookStatement = "";
    }
    if (lookStatement == "Look at Human drawing") {
        lookMessage = "What looks like an elderly human kneeling before that large person";
        SDL_DestroyTexture(Textures::spriteTexture);
        SDL_CreateTextureFromSurface(Scene1::renderer, Textures::spriteBack1a);
        doAction();
        lookStatement = "";
    }
    if (lookStatement == "Look at Flying saucer drawing") {
        lookMessage = "That looks like an Alien Craft approaching Planet Earth!";
        SDL_DestroyTexture(Textures::spriteTexture);
        SDL_CreateTextureFromSurface(Scene1::renderer, Textures::spriteBack1a);
        doAction();
        lookStatement = "";
    }
    if (lookStatement == "Look at Large Alien drawing") {
        lookMessage = "That is one big looking person with a very long head.";
        SDL_DestroyTexture(Textures::spriteTexture);
        SDL_CreateTextureFromSurface(Scene1::renderer, Textures::spriteBack1a);
        doAction();
        lookStatement = "";
    }
    if (lookStatement == "Look at Planet drawing") {
        lookMessage = "That is Earth, I can see the Americas.";
        SDL_DestroyTexture(Textures::spriteTexture);
        SDL_CreateTextureFromSurface(Scene1::renderer, Textures::spriteBack1a);
        doAction();
        lookStatement = "";
    }


    if (lookStatement == "Look at Smooth surface") {
        lookMessage = "How can I look at that, it's pitch black!";
        SDL_DestroyTexture(Textures::spriteTexture);
        SDL_CreateTextureFromSurface(Scene1::renderer, Textures::spriteBack1a);
        doAction();
        lookStatement = "";
    }

    if (gy < 208 && gd > 400 && gd < 529 && lookStatement == "Look at Crash site") {
        lookMessage = "My crashed ship, no chance of repairing.";
        SDL_DestroyTexture(Textures::spriteTexture);
        SDL_CreateTextureFromSurface(Scene1::renderer, Textures::spriteBack1a);
        doAction();
        lookStatement = "";
    }

    if (gy < 90 && gd > 670 && lookStatement == "Look at Crators") {
        lookMessage = "These crators are lined up in a row, very strange.";
        SDL_DestroyTexture(Textures::spriteTexture);
        SDL_CreateTextureFromSurface(Scene1::renderer, Textures::spriteBack1a);
        doAction();
        lookStatement = "";
    }

    if (gy > 300 && gy < 340 && lookStatement == "Look at Wreckage") {
        lookMessage = "That's one of the engines.";
        SDL_DestroyTexture(Textures::spriteTexture);
        SDL_CreateTextureFromSurface(Scene1::renderer, Textures::spriteBack1a);
        doAction();
        lookStatement = "";
    }

    if (x >= 613 && x <= 640 && y >= 335 && y <= 378 && lookStatement == "Look at Stuffed toy") {
        lookMessage = "That's George";
        SDL_DestroyTexture(Textures::spriteTexture);
        SDL_CreateTextureFromSurface(Scene1::renderer, Textures::spriteBack1a);
        doAction();
        lookStatement = "";
    }


    if (gd >= 622 && gd <= 700 && gy > 425 && inv.checkItem("PDA") != 1 && lookStatement == "Look at White plastic thingy") {

        lookMessage = "That's my PDA";
        Scene1::actionStatement = "";
        lookStatement = "";
        Scene1::sceneHalt = 1;
    }

    if (lookStatement == "Look at The moon") {

        lookMessage = "Very Earthlike";
        SDL_DestroyTexture(Textures::spriteTexture);
        SDL_CreateTextureFromSurface(Scene1::renderer, Textures::spriteBack1a);
        doAction();
        lookStatement = "";
    }

    if (lookStatement == "Look at Self Inflating Tent") {
        lookMessage = "It's a tent that, well, inflates";
        SDL_DestroyTexture(Textures::spriteTexture);
        SDL_CreateTextureFromSurface(Scene1::renderer, Textures::spriteBack1a);
        doAction();
        lookStatement = "";
    }

    if (lookStatement == "Look at Ape Tape") {
        lookMessage = "Ooh, Ape Tape!";
        SDL_DestroyTexture(Textures::spriteTexture);
        SDL_CreateTextureFromSurface(Scene1::renderer, Textures::spriteBack1a);
        doAction();
        lookStatement = "";
    }

    if (lookStatement == "Look at Flag" && gd > 526) {
        lookMessage = "That's the mission flag";
        doAction();
        lookStatement = "";
    }
    /* Rocky path */
    if (lookStatement == "Look at Rocks" && gd >= 640) {
        lookMessage = "That's a Meteorite";
        doAction();
        lookStatement = "";
    }

    else {
    }

    return lookMessage;
}


std::string MenuInteraction::Open(int x, int y, int gd, int gy, int mInteraction) {
    //New
    std::string openMessage;

    PlayerObjects pob;
    Inventory inv;

    int n = openStatement.length();

    if (n < 8)
        openStatement = pob.HoverObjects(x, y, 1, gd, gy);

    if (gd >= 410 && gy > 400 && openStatement == "Open Cardboard box") {
        openMessage = "Oh, what's this?";
        SDL_DestroyTexture(Textures::spriteTexture);
        SDL_CreateTextureFromSurface(Scene1::renderer, Textures::spriteDown1);
        Textures::objectTexture6 = Textures::objectTexture5;
        PlayerObjects::boxOpened = 1;
        doAction();
        openStatement = "";
      
    }

    else {
    }

    return openMessage;
}

std::string MenuInteraction::Use(int x, int y, int gd, int gy, int mInteraction) {

    std::string useMessage;

    PlayerObjects pob;
    Inventory inv;

    int n = useStatement.length();

    if (n < 8) {
        useStatement = pob.HoverObjects(x, y, 1, gd, gy);
    }
    if (useStatement == "Use Ape Tape") {

        if (inv.checkItem("Tape") == 0) {
            useMessage = "I need to pick it up first.";
            useStatement = "";
            doAction();
            return useMessage;
        }

        SDL_DestroyTexture(Textures::spriteTexture);
        SDL_CreateTextureFromSurface(Scene1::renderer, Textures::spriteAction);
        inv.useItem("Tape");
        Inventory::inv3Used = 1;
        useMessage = "That should plug the leak!";
        useStatement = "";
        doAction();
    }
    if (useStatement == "Use Wreckage") {
        SDL_DestroyTexture(Textures::spriteTexture);
        SDL_CreateTextureFromSurface(Scene1::renderer, Textures::spriteBack1a);
        useMessage = "It's wrecked!";
        useStatement = "";
        doAction();
    }

    if (useStatement == "Use Smooth surface") {
        SDL_DestroyTexture(Textures::spriteTexture);
        SDL_CreateTextureFromSurface(Scene1::renderer, Textures::spriteBack1a);
        useMessage = "I'll just have a quick sit down, ahhhh nice.";
        useStatement = "";
        doAction();
    }

    if (useStatement == "Use Pipe") {
        SDL_DestroyTexture(Textures::spriteTexture);
        SDL_CreateTextureFromSurface(Scene1::renderer, Textures::spriteDown1);
        useStatement = "";
        Scene1::useStatement = "with";
        Scene1::actionStatement = "Use Pipe with";
        
    }

    if (useStatement == "Use Battery Lantern") {
        SDL_DestroyTexture(Textures::spriteTexture);
        SDL_CreateTextureFromSurface(Scene1::renderer, Textures::spriteDown1);
        useStatement = "";
        Scene1::useStatement = "with";
        Scene1::actionStatement = "Use Battery Lantern with";
    }

    if (Scene1::useStatement == "Use Battery Lantern with Smooth surface") {
        SDL_DestroyTexture(Textures::spriteTexture);
        SDL_CreateTextureFromSurface(Scene1::renderer, Textures::spriteBack1a);
        useMessage = "Let there be light!";
        inv.useItem("Battery Lantern");
        doAction();
        Inventory::inv7Used = 1;
        Scene1::actionStatement = "";
        Scene1::useStatement = ""; //Very Important or you will get a memory leak.
        Scene1::xPosition = 606;
        Scene1::yPosition = 460;
        PlayerObjects pob;
        pob.SetSpritePosition(Scene1::xPosition, Scene1::yPosition);
    
         //Change scene.
        Scene1::SceneBackground = "3d";
    }


    if (Scene1::useStatement == "Use Pipe with Oxygenator 5000" && gd > 720 ) {
        SDL_DestroyTexture(Textures::spriteTexture);
        SDL_CreateTextureFromSurface(Scene1::renderer, Textures::spriteBack1a);
        useMessage = "TOAD 1000: Suit has been pressurized!";     
        inv.useItem("Pipe");
        doAction();
        Inventory::inv5Used = 1;
        Scene1::actionStatement = "";
        Scene1::useStatement = ""; //Very Important or you will get a memory leak.

    }
   
    if (useStatement == "Use Self Inflating Tent") {
        SDL_DestroyTexture(Textures::spriteTexture);
        SDL_CreateTextureFromSurface(Scene1::renderer, Textures::spriteDown1);
        useMessage = "Ok, where shall I put this tent?";
        useStatement = "";
        Scene1::useStatement = "with";
        Scene1::actionStatement = "Use Self Inflating Tent with";
    }

    if (Scene1::useStatement == "Use Self Inflating Tent with Sandy clearing") {
        
        inv.useItem("Tent");
        Inventory::inv4Used = 1;
        Scene1::actionStatement = "";
        //Change scene.
        Scene1::SceneBackground = "1fa";
    }
   
   

    return useMessage;

    /*  I HAVE KEPT THIS HERE FOR FUTURE REFERENCE BECAUSE I AM CHANGING THE WAY THIS IS DONE.


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

std::string MenuInteraction::PickUp(int x, int y, int gd, int gy, int mInteraction) {

    std::string gameObject;

    PlayerObjects pob;
    Inventory inv;

    int i = 0;
    int items = 0;

    int n = pickUpStatement.length();
    if (n < 8) //Don't override hover if a pick up statement has been selected. This is important, otherwise player will pick up anything within range no matter what you chose to pick up.
        pickUpStatement = pob.HoverObjects(x, y, 1, gd, gy);

    std::string menuMessages = pob.ObjectInteractionM1(gd, gy);
    gameObject = menuMessages;
    items = inv.checkItem(gameObject);

    //If user clicks on the location of the pickup button.
    if (Scene1::actionStatement == "Pick up") {

        if (items < 1) {
            if (menuMessages == "PDA" && pickUpStatement == "Pick up White plastic thingy" && gd >= 622 && gd <= 651 && gy > 425) {
                SDL_DestroyTexture(Textures::spriteTexture);
                SDL_CreateTextureFromSurface(Scene1::renderer, Textures::spritePick); //Shows a different player movement when picking up things.
               
                pickUpStatement = "";
                inv.SQLInsertInventory(gameObject, 0);
                doAction();
                std::string object = pob.DestroyObjects(gameObject);
                Scene1::objectToDestroy.append(object);
            }

            if (menuMessages == "Flag" && pickUpStatement == "Pick up Flag") {
               
                pickUpStatement = "";
                inv.SQLInsertInventory(gameObject, 0);
                doAction();
                std::string object = pob.DestroyObjects(gameObject);
                Scene1::objectToDestroy.append(object);
            }
            if (menuMessages == "Tape" && pickUpStatement == "Pick up Ape Tape") {
                SDL_DestroyTexture(Textures::spriteTexture);
                SDL_CreateTextureFromSurface(Scene1::renderer, Textures::spriteBack1a); //Shows a different player movement when picking up things.
              
                pickUpStatement = "";
                inv.SQLInsertInventory(gameObject, 0);
                doAction();
                std::string object = pob.DestroyObjects(gameObject);
                Scene1::objectToDestroy.append(object);
            }

            if (menuMessages == "Tent" && pickUpStatement == "Pick up Self Inflating Tent") {
                SDL_DestroyTexture(Textures::spriteTexture);
                SDL_CreateTextureFromSurface(Scene1::renderer, Textures::spriteBack1a); //Shows a different player movement when picking up things.
             
                pickUpStatement = "";
                inv.SQLInsertInventory(gameObject, 0);
                doAction();
                std::string object = pob.DestroyObjects(gameObject);
                Scene1::objectToDestroy.append(object);
            }

            if (menuMessages == "Battery Lantern" && pickUpStatement == "Pick up Battery Lantern") {
              
                pickUpStatement = "";
                inv.SQLInsertInventory(gameObject, 0);
                doAction();
                std::string object = pob.DestroyObjects(gameObject);
                Scene1::objectToDestroy.append(object);
            }

            if (menuMessages == "Pipe") {
              
                pickUpStatement = "";
                inv.SQLInsertInventory(gameObject, 0);
                doAction();
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
