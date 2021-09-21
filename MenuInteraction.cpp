#include "MenuInteraction.h"
#include <SDL.h>
#include <iostream>
#include "Scene1.h"
#include "Textures.h"
#include "Inventory.h"
#include "PlayerInteraction.h"

using namespace brightland;


static std::string useStatement;
static std::string openStatement;
static std::string lookStatement;
static std::string pickUpStatement;
static std::string actionStatement;
static std::string pullStatement;


//These 2 lines will deal when the player uses the wrong item. 
int MenuInteraction::wrongAction = 0;
std::string MenuInteraction::wrongActionMessage = "";  //Custom response to the player.

static int playerMessage;


void MenuInteraction::doAction() {
    Scene1::sceneHalt = 1;
    Scene1::action = 1;
    Scene1::actionStatement = "";
}

//This deals with the items being used wrong. For example, you try and use a tent with the tape.. This is not essential but it allows you to customize the message when using the wrong item.
void MenuInteraction::useChecker() {

    if (Scene1::useStatement.find("Use Self Inflating Tent with") != std::string::npos && Scene1::useStatement.find("Use Self Inflating Tent with Sandy clearing") == std::string::npos && Scene1::useStatement != "Use Self Inflating Tent with Self Inflating Tent") {
        MenuInteraction::wrongAction = 1;
        wrongActionMessage = "I can't set up a tent with that! I need a clear space.";
    }
    if (Scene1::useStatement.find("Use Pipe with") != std::string::npos && Scene1::useStatement.find("Use Pipe with Oxygenator 5000") == std::string::npos && Scene1::useStatement != "Use Pipe with Pipe") {
        MenuInteraction::wrongAction = 1;
        wrongActionMessage = "The pipe won't work with that!";
    }
    if (Scene1::useStatement.find("Pick up Loose rocks") != std::string::npos){
        MenuInteraction::wrongAction = 1;
        wrongActionMessage = "I don't want to pick them up, they are quite heavy!";
    }
    if (Scene1::useStatement.find("Use Loose rocks") != std::string::npos) {
        MenuInteraction::wrongAction = 1;
        wrongActionMessage = "They aren't round, so I can't use them as bowling balls.";
    }

}

std::string MenuInteraction::MenuAction(int x, int y, int gd, int gy, int mInteraction) {

    std::string actionMessage;

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

    if (x > 59 && x < 114 && y > 723 && y < 744 && Scene1::SceneBackground != "0") {
        useStatement = "";
        actionStatement = Scene1::actionStatement = "Pull";
        actionMessage = "Pull what?";
        pullStatement = "";
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


    if (lookStatement == "Look at Sparkling object" && gd > 360 && gy <260) {
        lookMessage = "It's a small gold disc!";
        SDL_DestroyTexture(Textures::spriteTexture);
        SDL_CreateTextureFromSurface(Scene1::renderer, Textures::spriteBack1a);
        doAction();
        lookStatement = "";
    }

    if (gy < 260 && gd > 300 && lookStatement == "Look at Loose rocks") {
        lookMessage = "Hmmmm what's this?";
        SDL_DestroyTexture(Textures::spriteTexture);
        SDL_CreateTextureFromSurface(Scene1::renderer, Textures::spriteBack1a);
        doAction();
        lookStatement = "";
    }


    if (lookStatement == "Look at Big X") {
        lookMessage = "I think this is where I am.. I think this is a map.";
        SDL_DestroyTexture(Textures::spriteTexture);
        SDL_CreateTextureFromSurface(Scene1::renderer, Textures::spriteDown1);
        doAction();
        lookStatement = "";
    }

    if (lookStatement == "Look at Odd formation") {
        lookMessage = "Not sure what this is supposed to be?";
        SDL_DestroyTexture(Textures::spriteTexture);
        SDL_CreateTextureFromSurface(Scene1::renderer, Textures::spriteDown1);
        doAction();
        lookStatement = "";
    }

    if (lookStatement == "Look at Location of interest") {
        lookMessage = "Whatever this is, it has to be significant.";
        Scene1::secretTrigger = 1; //Unlock hidden area.
        SDL_DestroyTexture(Textures::spriteTexture);
        SDL_CreateTextureFromSurface(Scene1::renderer, Textures::spriteDown1);
        doAction();
        lookStatement = "";
    }


    if (lookStatement == "Look at Marks in dirt") {
        Scene1::SceneBackground = "3e";     
        Scene1::xPosition = 545;
        PlayerInteraction::playerMessage = 12;
        Scene1::sceneHalt = 1;
        lookStatement = "";
        Scene1::actionStatement = "";
    }

    if (lookStatement == "Look at PDA") {
        lookMessage = "This is my personal computer that is linked to TOAD1000.";
        SDL_DestroyTexture(Textures::spriteTexture);
        SDL_CreateTextureFromSurface(Scene1::renderer, Textures::spriteDown1);
        doAction();
        lookStatement = "";
    }

    if (lookStatement == "Look at Self Inflating Tent") {
        lookMessage = "This is my habitat that inflates.";
        SDL_DestroyTexture(Textures::spriteTexture);
        SDL_CreateTextureFromSurface(Scene1::renderer, Textures::spriteDown1);
        doAction();
        lookStatement = "";
    }

    if (lookStatement == "Look at Ape Tape") {
        lookMessage = "No job is too much for APE TAPE.";
        SDL_DestroyTexture(Textures::spriteTexture);
        SDL_CreateTextureFromSurface(Scene1::renderer, Textures::spriteDown1);
        doAction();
        lookStatement = "";
    }

    if (lookStatement == "Look at Flag") {
        lookMessage = "Just need somewhere to put it.";
        SDL_DestroyTexture(Textures::spriteTexture);
        SDL_CreateTextureFromSurface(Scene1::renderer, Textures::spriteDown1);
        doAction();
        lookStatement = "";
    }

    if (lookStatement == "Look at Battery Lantern") {
        lookMessage = "Says on the back 5000 lumens.";
        SDL_DestroyTexture(Textures::spriteTexture);
        SDL_CreateTextureFromSurface(Scene1::renderer, Textures::spriteDown1);
        doAction();
        lookStatement = "";
    }

    if (lookStatement == "Look at Pipe") {
        lookMessage = "This is used with an Oxygenator.";
        SDL_DestroyTexture(Textures::spriteTexture);
        SDL_CreateTextureFromSurface(Scene1::renderer, Textures::spriteDown1);
        doAction();
        lookStatement = "";
    }

    if (lookStatement == "Look at Human remains") {
        lookMessage = "Unbelievable! I wonder if this is the woman in the cave drawing.";
        SDL_DestroyTexture(Textures::spriteTexture);
        SDL_CreateTextureFromSurface(Scene1::renderer, Textures::spriteBack1a);
        doAction();
        lookStatement = "";
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

    /* Sandy clearing */
    if (lookStatement == "Look at Sandy clearing" && gd <= 900 && gd > 300 && gy <= 360) {
        lookMessage = "It's very flat here.";
        SDL_DestroyTexture(Textures::spriteTexture);
        SDL_CreateTextureFromSurface(Scene1::renderer, Textures::spriteBack1a);
        doAction();
        lookStatement = "";
    }

    if (lookStatement == "Look at The moon") {

        lookMessage = "Very Earthlike";
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
        Inventory::inv.append("3");
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

    if (useStatement == "Use Sandy clearing") {
        SDL_DestroyTexture(Textures::spriteTexture);
        SDL_CreateTextureFromSurface(Scene1::renderer, Textures::spriteBack1a);
        useMessage = "This could be ideal for setting up my tent!";
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
        Inventory::inv.append("7");
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
        Inventory::inv.append("5");
        Scene1::actionStatement = "";
        Scene1::useStatement = ""; //Very Important or you will get a memory leak.

    }
   
    if (useStatement == "Use Self Inflating Tent") {
        SDL_DestroyTexture(Textures::spriteTexture);
        SDL_CreateTextureFromSurface(Scene1::renderer, Textures::spriteDown1);
        useStatement = "";
        Scene1::useStatement = "with";
        Scene1::actionStatement = "Use Self Inflating Tent with";
    }

    if (Scene1::useStatement == "Use Self Inflating Tent with Sandy clearing") {
        
        inv.useItem("Tent");
        Inventory::inv.append("4");
        Scene1::actionStatement = "";
        //Change scene.
        Scene1::SceneBackground = "1fa";
    }
    
    if (wrongAction == 1) {
        SDL_DestroyTexture(Textures::spriteTexture);
        SDL_CreateTextureFromSurface(Scene1::renderer, Textures::spriteDown1);
        useMessage = wrongActionMessage;
        wrongAction = 0;
        Scene1::actionStatement = "";
        Scene1::useStatement = "";
        doAction();
    }
    
    return useMessage;

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

            if (menuMessages == "PDA" && pickUpStatement == "Pick up White plastic thingy" && gd >= 622 && gd <= 691 && gy > 425) {
                SDL_DestroyTexture(Textures::spriteTexture);
                SDL_CreateTextureFromSurface(Scene1::renderer, Textures::spritePick); //Shows a different player movement when picking up things.
               
                pickUpStatement = "";
                inv.SQLInsertInventory(gameObject, 0);
                doAction();
                std::string object = pob.DestroyObjects(gameObject);
                Scene1::objectToDestroy.append(object);
            }

            if (menuMessages == "Disc" && pickUpStatement == "Pick up Sparkling object") {
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

            if (menuMessages == "Pipe" && pickUpStatement == "Pick up Plastic Pipe") {
              
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


std::string MenuInteraction::Pull(int x, int y, int gd, int gy, int mInteraction) {

    std::string pullMessage;

    PlayerObjects pob;
    Inventory inv;
    int n = pullStatement.length();

    if (n < 8) {
        pullStatement = pob.HoverObjects(x, y, 1, gd, gy);
    }
  
    if (gy < 260 && gd > 300 && pullStatement == "Pull Loose rocks") {
        SDL_DestroyTexture(Textures::spriteTexture);
        SDL_CreateTextureFromSurface(Scene1::renderer, Textures::spriteBack1a);
        pullMessage = "Oooh!";
        pullStatement = "";
        doAction();
        Scene1::secretTrigger = 2;
    }

  

    return pullMessage;

}

