#include "MenuInteraction.h"
#include <SDL.h>
#include <iostream>
#include "Scene1.h"
#include "Textures.h"
#include "Inventory.h"
#include "PlayerInteraction.h"
#include "Sound.h"
#include "AI.h"
#include "ObjectPositions.h"

using namespace brightland;


static std::string useStatement;
static std::string openStatement;
static std::string lookStatement;
//static std::string pickUpStatement;
static std::string actionStatement;
static std::string pullStatement;

std::string MenuInteraction::pickUpStatement;
//These 2 lines will deal when the player uses the wrong item.
int MenuInteraction::wrongAction = 0;
std::string MenuInteraction::wrongActionMessage = "";  //Custom response to the player.

static int playerMessage;


void MenuInteraction::doAction() {
    Scene1::sceneHalt = 1;
    Scene1::action = 1;
    Scene1::actionStatement = "";
}

//Clear interaction statement variables
void MenuInteraction::clearMessages() {
    useStatement = "";
    openStatement = "";
    lookStatement = "";
    pickUpStatement = "";
    pullStatement = "";
    actionStatement = "";
}

//This deals with the items being used wrong. For example, you try and use a tent with the tape.. This is not essential but it allows you to customize the message when using the wrong item.
void MenuInteraction::useChecker(int gd, int gy) {

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
    if (Scene1::useStatement.find("Pick up Rocks") != std::string::npos && gd > 540) {
        AI::aiPlayMessages = true;
        AI::dialogNumber = 13;
        AI::playerTalk = true;
        Scene1::useStatement = "";
        doAction();
    }
}

std::string MenuInteraction::MenuAction(int x, int y, int gd, int gy, int mInteraction) {

    std::string actionMessage;
    ObjectPositions op;
    
   
    if (Scene1::mouseMoveYPercent >=80 && Scene1::mouseMoveYPercent<=83 && Scene1::mouseMoveXPercent >=5 && Scene1::mouseMoveXPercent <=14 ) {
        Scene1::menuSound = 1;
        useStatement = "";  //Important
        actionStatement = Scene1::actionStatement = "Look at";
        actionMessage = "Look at what?";
        Scene1::SceneTransitionStatement = "";
        lookStatement = "";        
    }

  
    if (Scene1::mouseMoveYPercent >= 86 && Scene1::mouseMoveYPercent <= 89 && Scene1::mouseMoveXPercent >= 6 && Scene1::mouseMoveXPercent <= 16) {
        Scene1::menuSound = 1;
        useStatement = "";
        actionStatement = Scene1::actionStatement = "Pick up";
        actionMessage = "Pick up what?";
        pickUpStatement = "";     
    }
   
   
    if (Scene1::mouseMoveYPercent >= 86 && Scene1::mouseMoveYPercent <= 90 && Scene1::mouseMoveXPercent >= 18 && Scene1::mouseMoveXPercent <= 24) {
        Scene1::menuSound = 1;
        useStatement = "";
        actionStatement = Scene1::actionStatement = "Use";
        actionMessage = "Use what?";
        useStatement = "";
    }


    if (Scene1::mouseMoveYPercent >= 94 && Scene1::mouseMoveYPercent <= 98 && Scene1::mouseMoveXPercent >= 17 && Scene1::mouseMoveXPercent <= 23) {
        Scene1::menuSound = 1;
        useStatement = "";
        actionStatement = Scene1::actionStatement = "Open";
        actionMessage = "Open what?";
        openStatement = "";
    }

 
    if (Scene1::mouseMoveYPercent >= 94 && Scene1::mouseMoveYPercent <= 97 && Scene1::mouseMoveXPercent >= 6 && Scene1::mouseMoveXPercent <= 16) {
        Scene1::menuSound = 1;
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
    Textures tex;

    int n = lookStatement.length();

    if (n < 8) { 
        //Don't override hover if a pick up statement has been selected. 
        //This is important, otherwise player will pick up anything within range no matter what you chose to pick up.
        lookStatement = pob.HoverObjects(x, y, 1, gd, gy);
    }

    if (lookStatement == "Look at Mound" && Scene1::SceneBackground == "4a") {
        lookMessage = "Hmmmm very unusual.";
        lookStatement = "";
        tex.TextureUpdater(Textures::spriteBack1a, "Action");      
    }

    if (gd > 650 && lookStatement == "Look at Markings" && Scene1::SceneBackground == "4a") {
        lookMessage = "TOAD1000: will need more examples to translate, use personal computer to record.";
        lookStatement = "";
        tex.TextureUpdater(Textures::spriteBack1a, "Action");    
    }

    if (gd > 650 && lookStatement == "Look at Entrance") {
        lookMessage = "Looks like a stairwell, this is crazy!";
        lookStatement = "";
        tex.TextureUpdater(Textures::spriteBack1a, "Action");  
    }

    if (gd > 800 && lookStatement == "Look at Drawing") {
        lookMessage = "That's Earth and the Solar System, strange..";
        Scene1::secretTrigger = 4;
        lookStatement = "";
        tex.TextureUpdater(Textures::spriteBack1a, "Action");    
    }


    if (gd > 800 && lookStatement == "Look at Strange peg") {
        lookMessage = "It's a peg with a latch on it, hmmmm";
        lookStatement = "";
        tex.TextureUpdater(Textures::spriteBack1a, "Action");  
    }

    if (lookStatement == "Look at Disc") {
        lookMessage = "A gold disc with markings on it and a small hole in the middle";
        lookStatement = "";
        tex.TextureUpdater(Textures::spriteDown1, "Action");       
    }

    if (lookStatement == "Look at Spaceflix") {
        lookMessage = "I have 5 billion films and TV shows stored on it!";
        lookStatement = "";
        tex.TextureUpdater(Textures::spriteDown1, "Action");
     
    }

    if (lookStatement == "Look at Sparkling object" && gd > 360 && gy <260) {
        lookMessage = "It's a small gold disc!";
        lookStatement = "";
        tex.TextureUpdater(Textures::spriteBack1a, "Action");
      
    }

    if (lookStatement == "Look at Pot plant") {
        AI::aiPlayMessages = true;
        AI::dialogNumber = 18;
        AI::playerTalk = true;
        lookStatement = "";
        tex.TextureUpdater(Textures::spriteBack1a, "Action");   
    }

    if (lookStatement == "Look at Oxygenator 5000" && gd > 700 ) {
        lookMessage = "It's for topping up oxygen in my suit!";
        lookStatement = "";
        tex.TextureUpdater(Textures::spriteBack1a, "Action");    
    }

    if (lookStatement == "Look at Cardboard box") {
        AI::aiPlayMessages = true;
        AI::dialogNumber = 19;
        AI::playerTalk = true;
        lookStatement = "";
        tex.TextureUpdater(Textures::spriteDown1, "Action");
    
    }


    if (gy < 260 && gd > 300 && lookStatement == "Look at Loose rocks") {
        lookMessage = "Hmmmm what's this?";
        lookStatement = "";
        tex.TextureUpdater(Textures::spriteBack1a, "Action"); 
    }


    if (lookStatement == "Look at Big X") {
        lookMessage = "I think this is where I am.. I think this is a map.";
        lookStatement = "";
        tex.TextureUpdater(Textures::spriteDown1, "Action"); 
    }

    if (lookStatement == "Look at Odd formation") {
        lookMessage = "Not sure what this is supposed to be?";
        lookStatement = "";
        tex.TextureUpdater(Textures::spriteDown1, "Action");
    }

    if (lookStatement == "Look at Location of interest") {
        lookMessage = "Whatever this is, it has to be significant.";
        Scene1::secretTrigger = 1; //Unlock hidden area.
        lookStatement = "";
        tex.TextureUpdater(Textures::spriteDown1, "Action");   
    }


    if (lookStatement == "Look at Marks in dirt") {
        Scene1::SceneBackground = "3e";     
      //  Scene1::xPosition = 545;
        PlayerInteraction::playerMessage = 12;
        Scene1::sceneHalt = 1;
        lookStatement = "";
        Scene1::actionStatement = "";
    }

    if (lookStatement == "Look at PDA") {
        AI::aiPlayMessages = true;
        AI::dialogNumber = 7;
        AI::playerTalk = true;
        lookStatement = "";
        tex.TextureUpdater(Textures::spriteDown1, "Action");
   
    }

    if (lookStatement == "Look at Self Inflating Tent") {
        AI::aiPlayMessages = true;
        AI::dialogNumber = 9;
        AI::playerTalk = true;
        lookStatement = "";
        tex.TextureUpdater(Textures::spriteBack1a, "Action");
   
    }

    if (lookStatement == "Look at Ape Tape") {      
        //lookMessage = "No job is too much for APE TAPE.";
        AI::aiPlayMessages = true;
        AI::dialogNumber = 6;
        AI::playerTalk = true;
        lookStatement = "";
        tex.TextureUpdater(Textures::spriteBack1a, "Action");

    }

    if (lookStatement == "Look at Flag") {
        AI::aiPlayMessages = true;
        AI::dialogNumber = 10;
        AI::playerTalk = true;
        lookStatement = "";
        tex.TextureUpdater(Textures::spriteDown1, "Action");

    }

    if (lookStatement == "Look at Battery Lantern") {
        AI::aiPlayMessages = true;
        AI::dialogNumber = 17;
        AI::playerTalk = true;
        lookStatement = "";
        tex.TextureUpdater(Textures::spriteBack1a, "Action");
     
    }

    if (lookStatement == "Look at Pipe") {
        lookMessage = "This is used with an Oxygenator.";
        lookStatement = "";
        tex.TextureUpdater(Textures::spriteDown1, "Action");
  
    }

    if (lookStatement == "Look at Human remains") {
        lookMessage = "Unbelievable! I wonder if this is the woman in the cave drawing.";
        lookStatement = "";
        tex.TextureUpdater(Textures::spriteBack1a, "Action");

    }

    if (lookStatement == "Look at Cave door drawing") {
        lookMessage = "Seems like a cave door with the artifact placed in it. Weird.";
        lookStatement = "";
        tex.TextureUpdater(Textures::spriteBack1a, "Action");
  
    }

    if (lookStatement == "Look at Artifact drawing") {
        lookMessage = "That looks like an artifact which has a line pointing to south America.";
        lookStatement = "";
        tex.TextureUpdater(Textures::spriteBack1a, "Action");

    }

    if (lookStatement == "Look at Alien solar system drawing") {
        lookMessage = "I think this is the system I am in. Those lines are the planet that I am on.";
        lookStatement = "";
        tex.TextureUpdater(Textures::spriteBack1a, "Action");
   
    }
    if (lookStatement == "Look at Human drawing") {
        lookMessage = "What looks like an elderly human kneeling before that large person";
        lookStatement = "";
        tex.TextureUpdater(Textures::spriteBack1a, "Action");

    }
    if (lookStatement == "Look at Flying saucer drawing") {
        lookMessage = "That looks like an Alien Craft approaching Planet Earth!";
        lookStatement = "";
        tex.TextureUpdater(Textures::spriteBack1a, "Action");
   
    }
    if (lookStatement == "Look at Large Alien drawing") {
        lookMessage = "That is one big looking person with a very long head.";
        lookStatement = "";
        tex.TextureUpdater(Textures::spriteBack1a, "Action");
  
    }
    if (lookStatement == "Look at Planet drawing") {
        lookMessage = "That is Earth, I can see the Americas.";
        lookStatement = "";
        tex.TextureUpdater(Textures::spriteBack1a, "Action");
  
    }


    if (lookStatement == "Look at Smooth surface") {
        lookMessage = "How can I look at that, it's pitch black!";
        lookStatement = "";
        tex.TextureUpdater(Textures::spriteBack1a, "Action");
    
    }

    if (gy < 208 && gd > 400 && gd < 529 && lookStatement == "Look at Crash site") {
        lookMessage = "My crashed ship, no chance of repairing.";
        lookStatement = "";
        tex.TextureUpdater(Textures::spriteBack1a, "Action");
 
    }

    if (gy < 90 && gd > 670 && lookStatement == "Look at Crators") {
        lookMessage = "These crators are lined up in a row, very strange.";
        lookStatement = "";
        tex.TextureUpdater(Textures::spriteBack1a, "Action");
   
    }

    if (Scene1::xp >= 40 && Scene1::yp <= 50 && lookStatement == "Look at Wreckage") {     
      //  lookMessage = "That's one of the engines.";
        AI::aiPlayMessages = true;
        AI::dialogNumber = 4;
        AI::playerTalk = true;
        lookStatement = "";
        tex.TextureUpdater(Textures::spriteBack1a, "Action");

       
    }

    if (x >= 613 && x <= 640 && y >= 335 && y <= 378 && lookStatement == "Look at Stuffed toy") {
        lookMessage = "That's George";
        lookStatement = "";
        tex.TextureUpdater(Textures::spriteBack1a, "Action");

    }

 
    if (gd >= 622 && gd <= 700 && gy > 425 && inv.checkItem("PDA") != 1 && lookStatement == "Look at White plastic thingy") {
        AI::aiPlayMessages = true;
        AI::dialogNumber = 7;
        AI::playerTalk = true;
        Scene1::actionStatement = "";
        lookStatement = "";
        Scene1::sceneHalt = 1;
    }

  


    /* Sandy clearing */
    if (lookStatement == "Look at Sandy clearing" && gd <= 900 && gd > 300 && gy <= 360) {
  
        AI::aiPlayMessages = true;
        AI::dialogNumber = 20;
        AI::playerTalk = true;
        lookStatement = "";
        tex.TextureUpdater(Textures::spriteBack1a, "Action");
  
    
    }

    if (lookStatement == "Look at The moon") {
        AI::aiPlayMessages = true;
        AI::dialogNumber = 8;
        AI::playerTalk = true;
        lookStatement = "";
        tex.TextureUpdater(Textures::spriteBack1a, "Action");

    }
    if (lookStatement == "Look at White plastic thingy" && Scene1::xp >= 40 ) {
        AI::aiPlayMessages = true;
        AI::dialogNumber = 20;
        AI::playerTalk = true;
        lookStatement = "";
        tex.TextureUpdater(Textures::spriteBack1a, "Action");

    }

 
    /* Rocky path */
    if (lookStatement == "Look at Rocks" && gd >= 640) {
        AI::aiPlayMessages = true;
        AI::dialogNumber = 12;
        AI::playerTalk = true;
        lookStatement = "";
        tex.TextureUpdater(Textures::spriteBack1a, "Action");
    }

    else {
    }

    return lookMessage;
}


std::string MenuInteraction::Open(int x, int y, int gd, int gy, int mInteraction) {
    //New
    std::string openMessage;

    PlayerObjects pob;
    Textures tex;

    int n = openStatement.length();

    if (n < 8)
        openStatement = pob.HoverObjects(x, y, 1, gd, gy);

    if (gd >= 410 && gy > 400 && openStatement == "Open Cardboard box") {
        openMessage = "Oh, what's this?";
        openStatement = "";
        tex.TextureUpdater(Textures::spriteDown1, "Action");
        Textures::objectTexture6 = Textures::objectTexture5;
        PlayerObjects::boxOpened = 1;
    
      
    }

    else {
    }

    return openMessage;
}

std::string MenuInteraction::Use(int x, int y, int gd, int gy, int mInteraction) {

    std::string useMessage;
    Textures tex;
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
            return useMessage;
        }
        useStatement = "";
        tex.TextureUpdater(Textures::spriteAction, "Action");
        inv.useItem("Tape");
        Inventory::inv.append("3");
        AI::aiPlayMessages = true;
        AI::dialogNumber = 11;
        AI::playerTalk = true;
      
    }


    if (useStatement == "Use PDA") {
        tex.TextureUpdater(Textures::spriteDown1, "Action");
        useStatement = "";
        Scene1::useStatement = "with";
        Scene1::actionStatement = "Use PDA with";

    }
    if (Scene1::useStatement == "Use PDA with Markings" && gd > 600) {
        tex.TextureUpdater(Textures::spriteDown1, "Action");
        useMessage = "TOAD1000: Recorded";
        Scene1::secretTrigger++;
        std::cout << Scene1::secretTrigger << std::endl;
        Scene1::actionStatement = "";
        Scene1::useStatement = ""; //Very Important or you will get a memory leak.
       
       

    }

    if (useStatement == "Use Spaceflix") {
        useStatement = "";
        tex.TextureUpdater(Textures::spriteDown1, "Action");
        useMessage = "Maybe later!";
     
    }


    if (useStatement == "Use Wreckage") {
        useStatement = "";
        tex.TextureUpdater(Textures::spriteBack1a, "Action");
        useMessage = "It's wrecked!";
     
    }

    if (useStatement == "Use Smooth surface") {
        useStatement = "";
        tex.TextureUpdater(Textures::spriteBack1a, "Action");
        useMessage = "I'll just have a quick sit down, ahhhh nice.";
  
    }

    if (useStatement == "Use Sandy clearing") {
        useStatement = "";
        tex.TextureUpdater(Textures::spriteBack1a, "Action");
        AI::aiPlayMessages = true;
        AI::dialogNumber = 14;
        AI::playerTalk = true;
   
    }

    if (useStatement == "Use Oxygenator 5000" && gd >700 ) {
        useStatement = "";
        tex.TextureUpdater(Textures::spriteBack1a, "Action");
        useMessage = "It's missing the connector pipe.";
 
    }

    if (useStatement == "Use Disc") {
        tex.TextureUpdater(Textures::spriteDown1, "Action");
        useStatement = "";
        Scene1::useStatement = "with";
        Scene1::actionStatement = "Use Disc with";

    }

    if (Scene1::useStatement == "Use Disc with Strange peg" && gd > 800) {
        tex.TextureUpdater(Textures::spriteBack1a, "Action");
        useMessage = "Oooh some text has appeared on the wall!";
        inv.useItem("Disc");
       
        Inventory::inv.append("8");
        Scene1::actionStatement = "";
        Scene1::useStatement = ""; //Very Important or you will get a memory leak.
        Scene1::secretTrigger = 3; //Unlock hidden area.

    }

    if (useStatement == "Use Pipe") {
        tex.TextureUpdater(Textures::spriteDown1, "Action");
        useStatement = "";
        Scene1::useStatement = "with";
        Scene1::actionStatement = "Use Pipe with";
        
    }

    if (useStatement == "Use Battery Lantern") {
        tex.TextureUpdater(Textures::spriteDown1, "Action");
        useStatement = "";
        Scene1::useStatement = "with";
        Scene1::actionStatement = "Use Battery Lantern with";
    }

    if (Scene1::useStatement == "Use Battery Lantern with Smooth surface") {
        tex.TextureUpdater(Textures::spriteBack1a, "Action");
        useMessage = "Let there be light!";
        inv.useItem("Battery Lantern");
     
        Inventory::inv.append("7");
        Scene1::actionStatement = "";
        Scene1::useStatement = ""; //Very Important or you will get a memory leak.
       // Scene1::xPosition = 606;
      //  Scene1::yPosition = 460;
        PlayerObjects pob;
     //   pob.SetSpritePosition(Scene1::xPosition, Scene1::yPosition);
    
         //Change scene.
        Scene1::SceneBackground = "3d";
    }


    if (Scene1::useStatement == "Use Pipe with Oxygenator 5000" && gd > 720 ) {
        tex.TextureUpdater(Textures::spriteBack1a, "Action");
        useMessage = "TOAD 1000: Suit has been pressurized!";     
        inv.useItem("Pipe");
      
        Inventory::inv.append("5");
        Scene1::actionStatement = "";
        Scene1::useStatement = ""; //Very Important or you will get a memory leak.

    }
   
    if (useStatement == "Use Self Inflating Tent") {
        tex.TextureUpdater(Textures::spriteDown1, "Action");
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
        tex.TextureUpdater(Textures::spriteDown1, "Action");
        useMessage = wrongActionMessage;
        wrongAction = 0;
        Scene1::actionStatement = "";
        Scene1::useStatement = "";
 
    }
    
    return useMessage;

}


std::string MenuInteraction::PickUp(int x, int y, int gd, int gy, int mInteraction) {
  
    std::string gameObject;
    Textures tex;
    PlayerObjects pob;
    Inventory inv;

    std::cout << pickUpStatement << std::endl;
   

    int i = 0;
    int items = 0;

    int n = pickUpStatement.length();
    if (n < 8) //Don't override hover if a pick up statement has been selected. This is important, otherwise player will pick up anything within range no matter what you chose to pick up.
        pickUpStatement = pob.HoverObjects(x, y, 1, gd, gy);

    std::string menuMessages = pob.ObjectInteractionM1(gd, gy);
    //std::cout << menuMessages << std::endl;


    gameObject = menuMessages;
   // std::cout << gameObject << std::endl;
    items = inv.checkItem(gameObject);
 
    //If user clicks on the location of the pickup button.
    if (Scene1::actionStatement == "Pick up") {
       
        if (items < 1) {          
         
            if (menuMessages == "PDA" && pickUpStatement == "Pick up White plastic thingy" ) {
              
                tex.TextureUpdater(Textures::spritePick, "Action");
                pickUpStatement = "";
                inv.SQLInsertInventory(gameObject, 0);
                PlayerObjects::items += " PDA";
             
                std::string object = pob.DestroyObjects(gameObject);
                Scene1::objectToDestroy.append(object);
            }

           
            if (menuMessages == "Disc" && pickUpStatement == "Pick up Sparkling object" && gd > 360 && gy < 260) {
                tex.TextureUpdater(Textures::spriteBack1a, "Action");
                pickUpStatement = "";
                inv.SQLInsertInventory(gameObject, 0);

             
                std::string object = pob.DestroyObjects(gameObject);
                Scene1::objectToDestroy.append(object);
            }


            if (menuMessages == "Flag" && pickUpStatement == "Pick up Flag") {
            
                pickUpStatement = "";
                inv.SQLInsertInventory(gameObject, 0);
             
                std::string object = pob.DestroyObjects(gameObject);
                Scene1::objectToDestroy.append(object);
                PlayerObjects::items += " Flag";
            }
            if (menuMessages == "Tape" && pickUpStatement == "Pick up Ape Tape") {
               
                tex.TextureUpdater(Textures::spriteBack1a, "Action");
                pickUpStatement = "";
                inv.SQLInsertInventory(gameObject, 0);
              
                std::string object = pob.DestroyObjects(gameObject);
                Scene1::objectToDestroy.append(object);
                PlayerObjects::items += " Tape";
            }

            if (menuMessages == "Tent" && pickUpStatement == "Pick up Self Inflating Tent") {
                tex.TextureUpdater(Textures::spriteBack1a, "Action");
                pickUpStatement = "";
                inv.SQLInsertInventory(gameObject, 0);
              
                std::string object = pob.DestroyObjects(gameObject);
                Scene1::objectToDestroy.append(object);
            }

            if (menuMessages == "Battery Lantern" && pickUpStatement == "Pick up Battery Lantern") {     
                pickUpStatement = "";
                inv.SQLInsertInventory(gameObject, 0);
             
                std::string object = pob.DestroyObjects(gameObject);
                Scene1::objectToDestroy.append(object);
            }

            if (menuMessages == "Pipe" && pickUpStatement == "Pick up Plastic Pipe") {
                pickUpStatement = "";
                inv.SQLInsertInventory(gameObject, 0);            
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
    Textures tex;
    PlayerObjects pob;
    Inventory inv;
    int n = pullStatement.length();

    if (n < 8) {
        pullStatement = pob.HoverObjects(x, y, 1, gd, gy);
    }
  
    if (gy < 260 && gd > 400 && gd <569 && pullStatement == "Pull Loose rocks") {
        tex.TextureUpdater(Textures::spriteBack1a, "Action");
        pullMessage = "Oooh!";
        pullStatement = "";
    ;
        Scene1::secretTrigger = 2;
    }

  

    return pullMessage;

}

