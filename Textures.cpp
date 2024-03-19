#include <iostream>
#include "Textures.h"
#include "Scene1.h"
#include "MenuInteraction.h"
#include "AI.h"
#include "ObjectPositions.h"

using namespace brightland;

//Custom mouse cursor.
SDL_Texture* Textures::cursor;
SDL_Rect Textures::RCursor;

//Hover Button Textures
SDL_Texture* Textures::hoverNewGame;
SDL_Texture* Textures::hoverContinueGame;
SDL_Texture* Textures::hoverOptions;
SDL_Texture* Textures::hoverPlus;
SDL_Texture* Textures::hoverMinus;
SDL_Texture* Textures::hoverPickup;
SDL_Texture* Textures::hoverOpen;
SDL_Texture* Textures::hoverLook;
SDL_Texture* Textures::hoverPull;
SDL_Texture* Textures::hoverUse;
SDL_Texture* Textures::hoverLog;
SDL_Texture* Textures::hoverExit;
SDL_Texture* Textures::hoverNoSound;
SDL_Texture* Textures::HoverContinue1;
SDL_Texture* Textures::hoverFScreen;
SDL_Texture* Textures::hoverExitGame;


//Text Texture
SDL_Texture* Textures::ftexture;

//Menu Texture.
SDL_Texture* Textures::menuTexture;

//Scene Textures.
SDL_Texture* Textures::scene1f;
SDL_Texture* Textures::scene1fa;
SDL_Texture* Textures::scene1fb;
SDL_Texture* Textures::scene1d;
SDL_Texture* Textures::scene1d2;
SDL_Texture* Textures::scene3a;
SDL_Texture* Textures::scene3b;
SDL_Texture* Textures::scene3e;
SDL_Texture* Textures::scene3f;
SDL_Texture* Textures::wreakageScene;
SDL_Texture* Textures::scene1e;
SDL_Texture* Textures::texture;
SDL_Texture* Textures::starsTexture;
SDL_Texture* Textures::computerScene1;
SDL_Texture* Textures::computerScene2;
SDL_Texture* Textures::caveScene1;
SDL_Texture* Textures::caveScene2;
SDL_Texture* Textures::mainMenu;
SDL_Texture* Textures::poptions;
SDL_Texture* Textures::blink;
SDL_Texture* Textures::scene4a;
SDL_Texture* Textures::scene4b;


SDL_Rect Textures::background;
SDL_Rect Textures::background2;
SDL_Rect Textures::background3;
SDL_Rect Textures::background4;
SDL_Rect Textures::background5;
SDL_Rect Textures::menuBackground;
SDL_Rect Textures::rSecretDrawing;

//Hover Rect
SDL_Rect Textures::RHoverNewGame;
SDL_Rect Textures::RHoverConinueGame;
SDL_Rect Textures::RHoverOptions;
SDL_Rect Textures::RHoverMinus;
SDL_Rect Textures::RHoverPlus;
SDL_Rect Textures::RHoverPickup;
SDL_Rect Textures::RHoverOpen;
SDL_Rect Textures::RHoverPull;
SDL_Rect Textures::RHoverLook;
SDL_Rect Textures::RHoverUse;
SDL_Rect Textures::RHoverLog;
SDL_Rect Textures::RHoverExit;
SDL_Rect Textures::RHoverNoSound;
SDL_Rect Textures::RHoverContinue1;
SDL_Rect Textures::RHoverFScreen;
SDL_Rect Textures::RHoverExitGame;

//Overlay Textures.
SDL_Texture* Textures::rocks;
SDL_Texture* Textures::rocks2;
SDL_Texture* Textures::rocks3;
SDL_Texture* Textures::rocks4;
SDL_Texture* Textures::secretDrawing;

//Inventory Textures.
SDL_Texture* Textures::invTexture1;
SDL_Texture* Textures::invTexture2;
SDL_Texture* Textures::invTexture3;
SDL_Texture* Textures::invTexture4;
SDL_Texture* Textures::invTexture5;
SDL_Texture* Textures::invTexture6;
SDL_Texture* Textures::invTexture7;

//Object Textures.
SDL_Texture* Textures::objectTexture;
SDL_Texture* Textures::objectTexture2;
SDL_Texture* Textures::objectTexture3;
SDL_Texture* Textures::objectTexture4;
SDL_Texture* Textures::objectTexture5;
SDL_Texture* Textures::objectTexture6;
SDL_Texture* Textures::objectTexture7;
SDL_Texture* Textures::objectTextureAirBox;
SDL_Texture* Textures::objectTexturePipe;
SDL_Texture* Textures::objectTexturePipeAction;
SDL_Texture* Textures::objectTextureLantern;
SDL_Texture* Textures::objectTextureSparkle;

//Action Textures
SDL_Surface* Textures::spriteAction;

//Player Textures
SDL_Texture* Textures::spriteTexture;

//Player Surfaces.
SDL_Surface* Textures::spriteDown1;
SDL_Surface* Textures::spritePick;
SDL_Surface* Textures::spritePickp;

SDL_Surface* Textures::spriteDownTape;
SDL_Surface* Textures::spriteDown1a;
SDL_Surface* Textures::spriteDown2a;
SDL_Surface* Textures::spriteDown3a;

SDL_Surface* Textures::spriteDownp;
SDL_Surface* Textures::spriteDown2p;
SDL_Surface* Textures::spriteDown3p;

SDL_Surface* Textures::spriteRight1a;
SDL_Surface* Textures::spriteRight2a;
SDL_Surface* Textures::spriteRight3a;
SDL_Surface* Textures::spriteRight4a;

SDL_Surface* Textures::spriteLeft1a;
SDL_Surface* Textures::spriteLeft2a;
SDL_Surface* Textures::spriteLeft3a;
SDL_Surface* Textures::spriteLeft4a;

SDL_Surface* Textures::spriteBack1a;
SDL_Surface* Textures::spriteBack2a;
SDL_Surface* Textures::spriteBack3a;
SDL_Surface* Textures::spriteSurface;


void Textures::LoadActionTextures() {
    spriteAction = IMG_Load("PlayerMovement/ThePlanet/spriteAction1.png");

}

int Textures::AssetSizeCalc(std::string texture) {
    int result = 0;
    texture == "PLAYER_MENU_W" && Scene1::WIDTH == 1920 ? result = 72 : 0;
    texture == "PLAYER_MENU_H" && Scene1::WIDTH == 1920 ? result = 40 : 0;
    texture == "PLAYER_MENU_W" && Scene1::WIDTH == 1024 ? result = 0 : 0;
    texture == "PLAYER_MENU_H" && Scene1::WIDTH == 1024 ? result = 0 : 0;

    return result;
}

int Textures::AssetPosCalc(std::string texture) {
    int result = 0;
    //This function will recieve a texture name and then depending on the resolution, will alter the position.

    //Resolution 1920x1080
    texture == "PICKUP_X" && Scene1::WIDTH == 1920 ? result = 70 : 0;
    texture == "PICKUP_Y" && Scene1::WIDTH == 1920 ? result = 25 : 0;
    texture == "OPEN_X" && Scene1::WIDTH == 1920 ? result = 80 : 0;
    texture == "OPEN_Y" && Scene1::WIDTH == 1920 ? result = 40 : 0;
    texture == "USE_X" && Scene1::WIDTH == 1920 ? result = 70 : 0;
    texture == "USE_Y" && Scene1::WIDTH == 1920 ? result = 28 : 0;
    texture == "PULL_X" && Scene1::WIDTH == 1920 ? result = 80 : 0;
    texture == "PULL_Y" && Scene1::WIDTH == 1920 ? result = 18 : 0;
    texture == "LOOK_X" && Scene1::WIDTH == 1920 ? result = 80 : 0;
    texture == "LOOK_Y" && Scene1::WIDTH == 1920 ? result = 18 : 0;
    texture == "NEWGAME_Y" && Scene1::WIDTH == 1920 ? result = 25 : 0;
    texture == "NEWGAME_X" && Scene1::WIDTH == 1920 ? result = 85 : 0;

    //Resolution 1024x768
    texture == "PICKUP_X" && Scene1::WIDTH == 1024 ? result = 50 : 0;
    texture == "PICKUP_Y" && Scene1::WIDTH == 1024 ? result = 25 : 0;
    texture == "OPEN_X" && Scene1::WIDTH == 1024 ? result = 60 : 0;
    texture == "OPEN_Y" && Scene1::WIDTH == 1024 ? result = 20 : 0;
    texture == "USE_X" && Scene1::WIDTH == 1024 ? result = 50 : 0;
    texture == "USE_Y" && Scene1::WIDTH == 1024 ? result = 28 : 0;
    texture == "PULL_X" && Scene1::WIDTH == 1024 ? result = 60 : 0;
    texture == "PULL_Y" && Scene1::WIDTH == 1024 ? result = 18 : 0;
    texture == "LOOK_X" && Scene1::WIDTH == 1024 ? result = 40 : 0;
    texture == "LOOK_Y" && Scene1::WIDTH == 1024 ? result = 18 : 0;
    texture == "NEWGAME_Y" && Scene1::WIDTH == 1024 ? result = 18 : 0;
    texture == "NEWGAME_X" && Scene1::WIDTH == 1024 ? result = 40 : 0;

    return result;
}

void Textures::MovementTextures() {

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

void Textures::Scene1Textures() {
    ObjectPositions op; //ObjectPositions.cpp
    op.SetBackgroundHeight();
    op.PlaceSceneObjects();

    //Set hover button locations depending on resolution. Adjusting size of image will need to be calculated also so that it scales properly.
    op.CalcObjectXAbsolutePosition(9, "PICKUP_X"), op.CalcObjectYAbsolutePosition(88, "PICKUP_Y");
    op.CalcObjectXAbsolutePosition(9, "LOOK_X"), op.CalcObjectYAbsolutePosition(82, "LOOK_Y");
    op.CalcObjectXAbsolutePosition(20, "USE_X"), op.CalcObjectYAbsolutePosition(89, "USE_Y");
    op.CalcObjectXAbsolutePosition(21, "OPEN_X"), op.CalcObjectYAbsolutePosition(95, "OPEN_Y");
    op.CalcObjectXAbsolutePosition(9, "PULL_X"), op.CalcObjectYAbsolutePosition(95, "PULL_Y");
    op.CalcObjectXAbsolutePosition(20, "NEWGAME_X"), op.CalcObjectYAbsolutePosition(65, "NEWGAME_Y");


    //Background dimensions (x,y,width,height).
    //Main Menu Rect
    menuBackground = { 0, 0, Scene1::WIDTH, Scene1::HEIGHT };

    //Main background Rect
    background = { 0, 0, Scene1::WIDTH, ObjectPositions::BACKGROUND_H };

    //Background overlay Rects (Rocks in foreground etc) SX and SY are the size of the rocks within the rect.
    background2 = { ObjectPositions::ROCKS_X, ObjectPositions::ROCKS_Y, ObjectPositions::ROCKS_SX, ObjectPositions::ROCKS_SY };

    //This is the hill on the rocky path scene.
    background3 = { 0, 310, 1100, 300 }; 

    //This is the rock in the cave scene
    background4 = { -30, 268, 398, 329 };

    //This is the rock in the cave scene
    background5 = { 490, 200, 100, 60 };

    //This is for the main menu hover buttons (x,y,width of image, height of image)
    RHoverNewGame = { ObjectPositions::NEWGAME_X - AssetPosCalc("NEWGAME_X"),ObjectPositions::NEWGAME_Y - AssetPosCalc("NEWGAME_Y"),op.CalcAssetSize(240,AssetSizeCalc("PLAYER_MENU_W")),op.CalcAssetSize(60,AssetSizeCalc("PLAYER_MENU_H"))};
    RHoverConinueGame = { 180, 376, 272, 61 };
    RHoverOptions = { 180,579,272,61 };
    RHoverPlus = { 600,139,104,54 };
    RHoverMinus = { 281,139,104,54 };

    RHoverPickup = { ObjectPositions::PICKUP_X - AssetPosCalc("PICKUP_X"),ObjectPositions::PICKUP_Y - AssetPosCalc("PICKUP_Y"),op.CalcAssetSize(124,AssetSizeCalc("PLAYER_MENU_W")),op.CalcAssetSize(54,AssetSizeCalc("PLAYER_MENU_H"))};
    RHoverLook = { ObjectPositions::LOOK_X - AssetPosCalc("LOOK_X"),ObjectPositions::LOOK_Y - AssetPosCalc("LOOK_Y"),op.CalcAssetSize(100,AssetSizeCalc("PLAYER_MENU_W")),op.CalcAssetSize(50,AssetSizeCalc("PLAYER_MENU_H"))};
    RHoverOpen = { ObjectPositions::OPEN_X -AssetPosCalc("OPEN_X"),ObjectPositions::OPEN_Y - AssetPosCalc("OPEN_Y"),op.CalcAssetSize(100,AssetSizeCalc("PLAYER_MENU_W")),op.CalcAssetSize(50,AssetSizeCalc("PLAYER_MENU_H"))};
    RHoverUse = { ObjectPositions::USE_X -AssetPosCalc("USE_X"),ObjectPositions::USE_Y - AssetPosCalc("USE_Y"),op.CalcAssetSize(100,AssetSizeCalc("PLAYER_MENU_W")),op.CalcAssetSize(44,AssetSizeCalc("PLAYER_MENU_H"))};
    RHoverPull = { ObjectPositions::PULL_X -AssetPosCalc("PULL_X"),ObjectPositions::PULL_Y - AssetPosCalc("PULL_Y"),op.CalcAssetSize(100,AssetSizeCalc("PLAYER_MENU_W")),op.CalcAssetSize(44,AssetSizeCalc("PLAYER_MENU_H"))};
    RCursor = { 100, 310, 50, 50}; //Custom mouse cursor.
    rSecretDrawing = { 940,260,100,240 };
    RHoverLog = { 343,541,150,46 };
    RHoverExit = { 30,541,150,46 };
    RHoverNoSound = { 23,20,60,54 };
    RHoverContinue1 = { 780,480,190,54 };
    RHoverFScreen = { 731,40,252,60 };
    RHoverExitGame = { 17,700,50,50 };

    SDL_DestroyTexture(scene1f);
    SDL_DestroyTexture(scene1fa);
    SDL_DestroyTexture(scene1fb);
    SDL_DestroyTexture(scene1d);
    SDL_DestroyTexture(scene1d2);

    //Load in all Scene textures here. Only do this once as it uses RAM to do this.
    imageSurface = IMG_Load("menu.png");
    menuTexture = SDL_CreateTextureFromSurface(Scene1::renderer, imageSurface);
    SDL_FreeSurface(imageSurface);
    
    imageSurface = IMG_Load("Scenes/scene1.png");
    texture = SDL_CreateTextureFromSurface(Scene1::renderer, imageSurface);
    SDL_FreeSurface(imageSurface);

    imageSurface = IMG_Load("Scenes/rocks.png");
    rocks = SDL_CreateTextureFromSurface(Scene1::renderer, imageSurface);
    SDL_FreeSurface(imageSurface);

    imageSurface = IMG_Load("Scenes/ComputerScreen.png");
    computerScene1 = SDL_CreateTextureFromSurface(Scene1::renderer, imageSurface);
    SDL_FreeSurface(imageSurface);

    imageSurface = IMG_Load("Scenes/ComputerScreen1.png");
    computerScene2 = SDL_CreateTextureFromSurface(Scene1::renderer, imageSurface);
    SDL_FreeSurface(imageSurface);

    imageSurface = IMG_Load("Scenes/scene1b1.png");
    wreakageScene = SDL_CreateTextureFromSurface(Scene1::renderer, imageSurface);
    SDL_FreeSurface(imageSurface);

    imageSurface = IMG_Load("Scenes/Scene1e.png");
    scene1e = SDL_CreateTextureFromSurface(Scene1::renderer, imageSurface);
    SDL_FreeSurface(imageSurface);

    imageSurface = IMG_Load("Scenes/rocks2.png");
    rocks2 = SDL_CreateTextureFromSurface(Scene1::renderer, imageSurface);
    SDL_FreeSurface(imageSurface);

    //Main Menu
    imageSurface = IMG_Load("Scenes/gameMenu.png");
    mainMenu = SDL_CreateTextureFromSurface(Scene1::renderer, imageSurface);
    SDL_FreeSurface(imageSurface);

    //Hover Button Surfaces
    imageSurface = IMG_Load("Scenes/poptions.png");
    poptions = SDL_CreateTextureFromSurface(Scene1::renderer, imageSurface);
    SDL_FreeSurface(imageSurface);
      
    imageSurface = IMG_Load("PlayerMovement/ThePlanet/blink.png");
    blink = SDL_CreateTextureFromSurface(Scene1::renderer, imageSurface);
    SDL_FreeSurface(imageSurface);

    imageSurface = IMG_Load("Scenes/HoverButtons/menuNewGameHover.png");
    hoverNewGame = SDL_CreateTextureFromSurface(Scene1::renderer, imageSurface);
    SDL_FreeSurface(imageSurface);

    imageSurface = IMG_Load("Scenes/HoverButtons/log.png");
    hoverLog = SDL_CreateTextureFromSurface(Scene1::renderer, imageSurface);
    SDL_FreeSurface(imageSurface);

    imageSurface = IMG_Load("Scenes/HoverButtons/exit.png");
    hoverExit = SDL_CreateTextureFromSurface(Scene1::renderer, imageSurface);
    SDL_FreeSurface(imageSurface);

    imageSurface = IMG_Load("Scenes/HoverButtons/noSound.png");
    hoverNoSound = SDL_CreateTextureFromSurface(Scene1::renderer, imageSurface);
    SDL_FreeSurface(imageSurface);

    imageSurface = IMG_Load("Scenes/HoverButtons/fscreenEnabled.png");
    hoverFScreen = SDL_CreateTextureFromSurface(Scene1::renderer, imageSurface);
    SDL_FreeSurface(imageSurface);

    imageSurface = IMG_Load("Scenes/HoverButtons/menuContinueHover.png");
    hoverContinueGame = SDL_CreateTextureFromSurface(Scene1::renderer, imageSurface);
    SDL_FreeSurface(imageSurface);

    imageSurface = IMG_Load("Scenes/HoverButtons/continue1.png");
    HoverContinue1 = SDL_CreateTextureFromSurface(Scene1::renderer, imageSurface);
    SDL_FreeSurface(imageSurface);

    imageSurface = IMG_Load("Scenes/HoverButtons/playerOptionsHover.png");
    hoverOptions = SDL_CreateTextureFromSurface(Scene1::renderer, imageSurface);
    SDL_FreeSurface(imageSurface);

    imageSurface = IMG_Load("Scenes/HoverButtons/hoverExit.png");
    hoverExitGame = SDL_CreateTextureFromSurface(Scene1::renderer, imageSurface);
    SDL_FreeSurface(imageSurface);

   
    imageSurface = IMG_Load("Scenes/HoverButtons/hoverMinus.png");
    hoverMinus = SDL_CreateTextureFromSurface(Scene1::renderer, imageSurface);
    SDL_FreeSurface(imageSurface);

    imageSurface = IMG_Load("Scenes/HoverButtons/hoverPlus.png");
    hoverPlus = SDL_CreateTextureFromSurface(Scene1::renderer, imageSurface);
    SDL_FreeSurface(imageSurface);

    imageSurface = IMG_Load("Scenes/HoverButtons/pickup.png");
    hoverPickup = SDL_CreateTextureFromSurface(Scene1::renderer, imageSurface);
    SDL_FreeSurface(imageSurface);

    imageSurface = IMG_Load("Scenes/HoverButtons/open.png");
    hoverOpen = SDL_CreateTextureFromSurface(Scene1::renderer, imageSurface);
    SDL_FreeSurface(imageSurface);

    imageSurface = IMG_Load("Scenes/HoverButtons/look.png");
    hoverLook = SDL_CreateTextureFromSurface(Scene1::renderer, imageSurface); 
    SDL_FreeSurface(imageSurface);

    imageSurface = IMG_Load("Scenes/HoverButtons/pull.png");
    hoverPull = SDL_CreateTextureFromSurface(Scene1::renderer, imageSurface);
    SDL_FreeSurface(imageSurface);


    imageSurface = IMG_Load("Scenes/HoverButtons/use.png");
    hoverUse = SDL_CreateTextureFromSurface(Scene1::renderer, imageSurface);
    SDL_FreeSurface(imageSurface);
     

    imageSurface = IMG_Load("Scenes/Cursors/mousePointer.png");
    cursor = SDL_CreateTextureFromSurface(Scene1::renderer, imageSurface);
    SDL_FreeSurface(imageSurface);
    
  
    //Objects
    imageSurface = IMG_Load("Objects/pda.png");
    invTexture1 = SDL_CreateTextureFromSurface(Scene1::renderer, imageSurface);
    objectTexture = SDL_CreateTextureFromSurface(Scene1::renderer, imageSurface);
    SDL_FreeSurface(imageSurface);
    
    imageSurface = IMG_Load("Objects/flagr.png");
    invTexture2 = SDL_CreateTextureFromSurface(Scene1::renderer, imageSurface);
    objectTexture2 = SDL_CreateTextureFromSurface(Scene1::renderer, imageSurface);
    SDL_FreeSurface(imageSurface);

    imageSurface = IMG_Load("Objects/tape.png");
    invTexture3 = SDL_CreateTextureFromSurface(Scene1::renderer, imageSurface);
    objectTexture4 = SDL_CreateTextureFromSurface(Scene1::renderer, imageSurface);
    SDL_FreeSurface(imageSurface);

    imageSurface = IMG_Load("Objects/stars3.png");
    starsTexture = SDL_CreateTextureFromSurface(Scene1::renderer, imageSurface);
    SDL_FreeSurface(imageSurface);
    
    imageSurface = IMG_Load("Objects/tent.png");
    invTexture4 = SDL_CreateTextureFromSurface(Scene1::renderer, imageSurface);
    objectTexture5 = SDL_CreateTextureFromSurface(Scene1::renderer, imageSurface);
    SDL_FreeSurface(imageSurface);
    
    //Player Textures
    spriteDown1 = IMG_Load("PlayerMovement/ThePlanet/sprite.png");
    spriteDownp = IMG_Load("PlayerMovement/ThePlanet/spritep.png");
    spriteBack1a = IMG_Load("PlayerMovement/ThePlanet/spriteback1.png");
    spritePick = IMG_Load("PlayerMovement/ThePlanet/spritePick.png");
    spritePickp = IMG_Load("PlayerMovement/ThePlanet/spritePickp.png");

    spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, Textures::spriteDown1);
   
}

void Textures::Scene2Textures() {

    //Clear out textures that will no longer be required to free up memory. 
    SDL_DestroyTexture(invTexture3);

    //Load in new textures.
    imageSurface =  IMG_Load("Scenes/Scene1f.png");
    scene1f = SDL_CreateTextureFromSurface(Scene1::renderer, imageSurface);
    SDL_FreeSurface(imageSurface);

    imageSurface =  IMG_Load("Scenes/Scene1fa.png");
    scene1fa = SDL_CreateTextureFromSurface(Scene1::renderer, imageSurface);
    SDL_FreeSurface(imageSurface);
  

}

void Textures::Scene3Textures() {

    SDL_DestroyTexture(invTexture3);
    SDL_DestroyTexture(invTexture3);
    SDL_DestroyTexture(invTexture3);
    SDL_DestroyTexture(invTexture3);
    SDL_DestroyTexture(invTexture3);
    SDL_DestroyTexture(invTexture3);
    SDL_DestroyTexture(rocks);
    SDL_DestroyTexture(rocks2);
    SDL_DestroyTexture(invTexture3);
    SDL_DestroyTexture(scene1f);
    SDL_DestroyTexture(scene1fa);
    SDL_DestroyTexture(scene1e);
    SDL_DestroyTexture(computerScene1);
    SDL_DestroyTexture(computerScene2);
    SDL_DestroyTexture(wreakageScene);
    SDL_DestroyTexture(objectTexture5);
    SDL_DestroyTexture(objectTexture4);


    //Load in new Scene Textures.
    imageSurface = IMG_Load("Scenes/Scene1fb.png");
    scene1fb = SDL_CreateTextureFromSurface(Scene1::renderer, imageSurface);
    SDL_FreeSurface(imageSurface);

    imageSurface = IMG_Load("Scenes/Scene1d.png");
    scene1d = SDL_CreateTextureFromSurface(Scene1::renderer, imageSurface);
    SDL_FreeSurface(imageSurface);

    imageSurface = IMG_Load("Scenes/Scene1d2.png");
    scene1d2 = SDL_CreateTextureFromSurface(Scene1::renderer, imageSurface);
    SDL_FreeSurface(imageSurface);

    imageSurface = IMG_Load("Scenes/Scene3a.png");
    scene3a = SDL_CreateTextureFromSurface(Scene1::renderer, imageSurface);
    SDL_FreeSurface(imageSurface);

    imageSurface = IMG_Load("Scenes/Scene3b.png");
    scene3b = SDL_CreateTextureFromSurface(Scene1::renderer, imageSurface);
    SDL_FreeSurface(imageSurface);
  
    imageSurface = IMG_Load("Scenes/scene3c.png");
    caveScene1 = SDL_CreateTextureFromSurface(Scene1::renderer, imageSurface);
    SDL_FreeSurface(imageSurface);

    imageSurface = IMG_Load("Scenes/scene3d.png");
    caveScene2 = SDL_CreateTextureFromSurface(Scene1::renderer, imageSurface);
    SDL_FreeSurface(imageSurface);

    imageSurface = IMG_Load("Scenes/rocks3.png");
    rocks3 = SDL_CreateTextureFromSurface(Scene1::renderer, imageSurface);
    SDL_FreeSurface(imageSurface);
    
    imageSurface = IMG_Load("Scenes/rocks4.png");
    rocks4 = SDL_CreateTextureFromSurface(Scene1::renderer, imageSurface);
    SDL_FreeSurface(imageSurface);

    imageSurface = IMG_Load("Scenes/scene3e.png");
    scene3e = SDL_CreateTextureFromSurface(Scene1::renderer, imageSurface);
    SDL_FreeSurface(imageSurface);

    imageSurface = IMG_Load("Scenes/scene3f.png");
    scene3f = SDL_CreateTextureFromSurface(Scene1::renderer, imageSurface);
    SDL_FreeSurface(imageSurface);

    imageSurface = IMG_Load("Scenes/planetGlow.png");
    secretDrawing = SDL_CreateTextureFromSurface(Scene1::renderer, imageSurface);
    SDL_FreeSurface(imageSurface);
   
    //Objects
   
    imageSurface = IMG_Load("Objects/boxopened.png");
    objectTexture5 = SDL_CreateTextureFromSurface(Scene1::renderer, imageSurface);
    SDL_FreeSurface(imageSurface);

    imageSurface = IMG_Load("Objects/boxclosed.png");
    objectTexture6 = SDL_CreateTextureFromSurface(Scene1::renderer, imageSurface);
    SDL_FreeSurface(imageSurface);

    imageSurface = IMG_Load("Objects/boxopenede.png");
    objectTexture7 = SDL_CreateTextureFromSurface(Scene1::renderer, imageSurface);
    SDL_FreeSurface(imageSurface);

    imageSurface = IMG_Load("Objects/pipec.png");
    objectTexturePipe = SDL_CreateTextureFromSurface(Scene1::renderer, imageSurface);
    SDL_FreeSurface(imageSurface);

    imageSurface = IMG_Load("Objects/airBox.png");
    objectTextureAirBox = SDL_CreateTextureFromSurface(Scene1::renderer, imageSurface);
    SDL_FreeSurface(imageSurface);


    imageSurface = IMG_Load("Objects/lantern.png");
    invTexture6 = SDL_CreateTextureFromSurface(Scene1::renderer, imageSurface);
    objectTextureLantern = SDL_CreateTextureFromSurface(Scene1::renderer, imageSurface);
    SDL_FreeSurface(imageSurface);


    imageSurface = IMG_Load("Objects/pipe.png");
    invTexture3 = SDL_CreateTextureFromSurface(Scene1::renderer, imageSurface);
    SDL_FreeSurface(imageSurface);


    imageSurface = IMG_Load("Objects/sparkleObject.png");
    objectTextureSparkle = SDL_CreateTextureFromSurface(Scene1::renderer, imageSurface);
    SDL_FreeSurface(imageSurface);

    imageSurface = IMG_Load("Objects/disc.png");
    invTexture7 = SDL_CreateTextureFromSurface(Scene1::renderer, imageSurface);
    SDL_FreeSurface(imageSurface);
  

}

void Textures::Scene4Textures() {

   
    SDL_DestroyTexture(scene1fb);
    SDL_DestroyTexture(scene1d);
    SDL_DestroyTexture(scene1d2);
    SDL_DestroyTexture(scene3a);
    SDL_DestroyTexture(scene3b);
    SDL_DestroyTexture(caveScene1);
    SDL_DestroyTexture(caveScene2);
    SDL_DestroyTexture(rocks3);
    SDL_DestroyTexture(rocks4);
    SDL_DestroyTexture(scene3e);
    SDL_DestroyTexture(scene3f);
    SDL_DestroyTexture(secretDrawing);
    SDL_DestroyTexture(invTexture3);
    SDL_DestroyTexture(invTexture6);
    SDL_DestroyTexture(invTexture7);
  
    imageSurface = IMG_Load("Scenes/Scene4a.png");
    scene4a = SDL_CreateTextureFromSurface(Scene1::renderer, imageSurface);
    SDL_FreeSurface(imageSurface);
    
    imageSurface = IMG_Load("Scenes/Scene4b.png");
    scene4b = SDL_CreateTextureFromSurface(Scene1::renderer, imageSurface);
    SDL_FreeSurface(imageSurface);
}

//This will update the player texture and if there is dialog "Action", it will halt the game so that the
//sprite does not flicker.

void Textures::TextureUpdater(SDL_Surface* texture, std::string action) { 
 
    SDL_DestroyTexture(spriteTexture);
    SDL_CreateTextureFromSurface(Scene1::renderer, texture);
      
    if (action == "Action") {
        MenuInteraction mi;
        mi.doAction();
    }
    


}