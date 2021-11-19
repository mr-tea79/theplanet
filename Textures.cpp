#include <iostream>

#include "Textures.h"
#include "Scene1.h"

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

SDL_Rect Textures::background;
SDL_Rect Textures::background2;
SDL_Rect Textures::background3;
SDL_Rect Textures::background4;
SDL_Rect Textures::background5;
SDL_Rect Textures::menuBackground;

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

//Overlay Textures.
SDL_Texture* Textures::rocks;
SDL_Texture* Textures::rocks2;
SDL_Texture* Textures::rocks3;
SDL_Texture* Textures::rocks4;

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

SDL_Surface* Textures::Sblink;



void Textures::LoadActionTextures() {
    spriteAction = IMG_Load("PlayerMovement/ThePlanet/spriteAction1.png");

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

    //Background dimensions (x,y,width,height).
    //Main background Rect
    menuBackground = { 0, 0, 1200, 768 };

    //Main background Rect
    background = { 0, 0, 1024, 600 };

    //Background overlay Rects (Rocks in foreground etc)
    background2 = { 0, 200, 1500, 400 };

    //This is the hill on the rocky path scene.
    background3 = { 0, 310, 1100, 300 }; 

    //This is the rock in the cave scene
    background4 = { -30, 268, 398, 329 };

    //This is the rock in the cave scene
    background5 = { 490, 200, 100, 60 };

    //This is for the main menu hover buttons
    RHoverNewGame = { 180, 480, 272, 61 };
    RHoverConinueGame = { 180, 376, 272, 61 };
    RHoverOptions = { 180,579,272,61 };
    RHoverPlus = { 600,139,104,54 };
    RHoverMinus = { 281,139,104,54 };
    RHoverPickup = { 45,655,124,54 };
    RHoverLook = { 45,610,100,50 };
    RHoverOpen = { 160,710,100,44 };
    RHoverUse = { 160,660,100,44 };
    RHoverPull = { 45,710,100,44 };
    RCursor = { 100, 310, 50, 50}; //Custom mouse cursor.

    SDL_DestroyTexture(scene1f);
    SDL_DestroyTexture(scene1fa);
    SDL_DestroyTexture(scene1fb);
    SDL_DestroyTexture(scene1d);
    SDL_DestroyTexture(scene1d2);

    //Load in all Scene textures here. Only do this once as it uses RAM to do this.
    menuSurface = IMG_Load("menu.png");
    
    imageSurface = IMG_Load("Scenes/scene1.png");
    imageSurface2 = IMG_Load("Scenes/rocks.png");
    imageSurface3 = IMG_Load("Scenes/ComputerScreen.png");
    imageSurface4 = IMG_Load("Scenes/scene1b1.png");
    imageSurface5 = IMG_Load("Scenes/ComputerScreen1.png");
    imageSurface6 = IMG_Load("Scenes/Scene1e.png");
    imageSurface7 = IMG_Load("Scenes/rocks2.png");
    imageSurface19 = IMG_Load("Scenes/gameMenu.png");
    imageSurface22 = IMG_Load("Scenes/poptions.png");

    Sblink = IMG_Load("PlayerMovement/ThePlanet/blink.png");

    //Hover Button Surfaces
    ShoverNewGame = IMG_Load("Scenes/HoverButtons/menuNewGameHover.png");
    ShoverContinueGame = IMG_Load("Scenes/HoverButtons/menuContinueHover.png");
    ShoverOptions = IMG_Load("Scenes/HoverButtons/playerOptionsHover.png");
    ShoverMinus = IMG_Load("Scenes/HoverButtons/hoverMinus.png");
    ShoverPlus = IMG_Load("Scenes/HoverButtons/hoverPlus.png");
    ShoverPickup = IMG_Load("Scenes/HoverButtons/pickup.png");
    ShoverOpen = IMG_Load("Scenes/HoverButtons/open.png");
    ShoverPull = IMG_Load("Scenes/HoverButtons/pull.png");
    ShoverUse = IMG_Load("Scenes/HoverButtons/use.png");
    ShoverLook = IMG_Load("Scenes/HoverButtons/look.png");
     
    Scursor = IMG_Load("Scenes/Cursors/mousePointer.png");

    cursor = SDL_CreateTextureFromSurface(Scene1::renderer, Scursor);
    hoverNewGame = SDL_CreateTextureFromSurface(Scene1::renderer, ShoverNewGame);
    hoverContinueGame = SDL_CreateTextureFromSurface(Scene1::renderer, ShoverContinueGame);
    hoverOptions = SDL_CreateTextureFromSurface(Scene1::renderer, ShoverOptions);
    hoverMinus = SDL_CreateTextureFromSurface(Scene1::renderer, ShoverMinus);
    hoverPlus = SDL_CreateTextureFromSurface(Scene1::renderer, ShoverPlus);
    hoverPickup = SDL_CreateTextureFromSurface(Scene1::renderer, ShoverPickup);
    hoverLook = SDL_CreateTextureFromSurface(Scene1::renderer, ShoverLook);
    hoverUse = SDL_CreateTextureFromSurface(Scene1::renderer, ShoverUse);
    hoverOpen = SDL_CreateTextureFromSurface(Scene1::renderer, ShoverOpen);
    hoverPull = SDL_CreateTextureFromSurface(Scene1::renderer, ShoverPull);

    pda = IMG_Load("Objects/pda.png");
    flag = IMG_Load("Objects/flagr.png");
    stars = IMG_Load("Objects/stars3.png");
    tape = IMG_Load("Objects/tape.png");
    tent = IMG_Load("Objects/tent.png");

    spriteDown1 = IMG_Load("PlayerMovement/ThePlanet/sprite.png");
    spriteDownp = IMG_Load("PlayerMovement/ThePlanet/spritep.png");
    spriteBack1a = IMG_Load("PlayerMovement/ThePlanet/spriteback1.png");
    spritePick = IMG_Load("PlayerMovement/ThePlanet/spritePick.png");
    spritePickp = IMG_Load("PlayerMovement/ThePlanet/spritePickp.png");

    texture = SDL_CreateTextureFromSurface(Scene1::renderer, imageSurface);
   
    computerScene1 = SDL_CreateTextureFromSurface(Scene1::renderer, imageSurface3);
   
    computerScene2 = SDL_CreateTextureFromSurface(Scene1::renderer, imageSurface5);
   
    wreakageScene = SDL_CreateTextureFromSurface(Scene1::renderer, imageSurface4);
   
    scene1e = SDL_CreateTextureFromSurface(Scene1::renderer, imageSurface6);
   
    rocks = SDL_CreateTextureFromSurface(Scene1::renderer, imageSurface2);
   
    rocks2 = SDL_CreateTextureFromSurface(Scene1::renderer, imageSurface7);
   
    mainMenu = SDL_CreateTextureFromSurface(Scene1::renderer, imageSurface19);

    poptions = SDL_CreateTextureFromSurface(Scene1::renderer, imageSurface22);

    objectTexture = SDL_CreateTextureFromSurface(Scene1::renderer, pda);
    objectTexture2 = SDL_CreateTextureFromSurface(Scene1::renderer, flag);
    objectTexture4 = SDL_CreateTextureFromSurface(Scene1::renderer, tape);
    objectTexture5 = SDL_CreateTextureFromSurface(Scene1::renderer, tent);
    starsTexture = SDL_CreateTextureFromSurface(Scene1::renderer, stars);
    blink = SDL_CreateTextureFromSurface(Scene1::renderer, Sblink);
    
    invTexture1 = SDL_CreateTextureFromSurface(Scene1::renderer, pda);
    invTexture2 = SDL_CreateTextureFromSurface(Scene1::renderer, flag);
    invTexture3 = SDL_CreateTextureFromSurface(Scene1::renderer, tape);
    invTexture4 = SDL_CreateTextureFromSurface(Scene1::renderer, tent);
  
    menuTexture = SDL_CreateTextureFromSurface(Scene1::renderer, menuSurface);

    spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, Textures::spriteDown1);
   
    //Free up surfaces (Memory Management)
    SDL_FreeSurface(pda);
    SDL_FreeSurface(stars);
    SDL_FreeSurface(flag);
    SDL_FreeSurface(imageSurface);
    SDL_FreeSurface(imageSurface3);
    SDL_FreeSurface(tape);
    SDL_FreeSurface(tent);
    SDL_FreeSurface(menuSurface);
    SDL_FreeSurface(imageSurface5);
    SDL_FreeSurface(imageSurface4);
    SDL_FreeSurface(imageSurface6);
    SDL_FreeSurface(imageSurface2);
    SDL_FreeSurface(imageSurface7);
    SDL_FreeSurface(imageSurface19);
    SDL_FreeSurface(imageSurface22);
    SDL_FreeSurface(ShoverNewGame);
    SDL_FreeSurface(ShoverContinueGame);
    SDL_FreeSurface(ShoverOptions);
    SDL_FreeSurface(ShoverPlus);
    SDL_FreeSurface(ShoverMinus);
    SDL_FreeSurface(ShoverPickup);
    SDL_FreeSurface(ShoverPull);
    SDL_FreeSurface(ShoverOpen);
    SDL_FreeSurface(ShoverLook);
    SDL_FreeSurface(ShoverUse);
    SDL_FreeSurface(Scursor);
    SDL_FreeSurface(Sblink);
 
}

void Textures::Scene2Textures() {

    //Clear out textures that will no longer be required to free up memory. 
    SDL_DestroyTexture(invTexture3);

    //Load in new textures.
    imageSurface8 =  IMG_Load("Scenes/Scene1f.png");
    imageSurface9 =  IMG_Load("Scenes/Scene1fa.png");
    scene1f = SDL_CreateTextureFromSurface(Scene1::renderer, imageSurface8);
    scene1fa = SDL_CreateTextureFromSurface(Scene1::renderer, imageSurface9);

    //Free up surfaces (Memory Management)
    SDL_FreeSurface(imageSurface8);
    SDL_FreeSurface(imageSurface9);

}

void Textures::Scene3Textures() {

    //Clear out textures that will no longer be required to free up memory.
    imageSurface = NULL;
    imageSurface2 = NULL;
    imageSurface3 = NULL;
    imageSurface4 = NULL;
    imageSurface5 = NULL;
    imageSurface6 = NULL;
    imageSurface7 = NULL;

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
    imageSurface10 = IMG_Load("Scenes/Scene1fb.png");
    imageSurface11 = IMG_Load("Scenes/Scene1d.png");
    imageSurface12 = IMG_Load("Scenes/Scene1d2.png");
    imageSurface13 = IMG_Load("Scenes/Scene3a.png");
    imageSurface14 = IMG_Load("Scenes/Scene3b.png");
    imageSurface15 = IMG_Load("Scenes/scene3c.png");
    imageSurface16 = IMG_Load("Scenes/scene3d.png");
    imageSurface17 = IMG_Load("Scenes/rocks3.png");
    imageSurface21 = IMG_Load("Scenes/rocks4.png");
    imageSurface18 = IMG_Load("Scenes/scene3e.png");
    imageSurface20 = IMG_Load("Scenes/scene3f.png");

    scene1fb = SDL_CreateTextureFromSurface(Scene1::renderer, imageSurface10);  
    scene1d = SDL_CreateTextureFromSurface(Scene1::renderer, imageSurface11);  
    scene1d2 = SDL_CreateTextureFromSurface(Scene1::renderer, imageSurface12);
    scene3a = SDL_CreateTextureFromSurface(Scene1::renderer, imageSurface13);  
    scene3b = SDL_CreateTextureFromSurface(Scene1::renderer, imageSurface14);
    caveScene1 = SDL_CreateTextureFromSurface(Scene1::renderer, imageSurface15);
    caveScene2 = SDL_CreateTextureFromSurface(Scene1::renderer, imageSurface16);
    rocks3 = SDL_CreateTextureFromSurface(Scene1::renderer, imageSurface17);
    rocks4 = SDL_CreateTextureFromSurface(Scene1::renderer, imageSurface21);
    scene3e = SDL_CreateTextureFromSurface(Scene1::renderer, imageSurface18);
    scene3f = SDL_CreateTextureFromSurface(Scene1::renderer, imageSurface20);
   
    boxOpened = IMG_Load("Objects/boxopened.png");
    boxClosed = IMG_Load("Objects/boxclosed.png");
    boxEmpty = IMG_Load("Objects/boxopenede.png");
    pipeBox = IMG_Load("Objects/pipec.png");
    airBox = IMG_Load("Objects/airBox.png");
    lantern = IMG_Load("Objects/lantern.png");
    pipe = IMG_Load("Objects/pipe.png");
    sparkle = IMG_Load("Objects/sparkleObject.png");
    disc = IMG_Load("Objects/disc.png");

    objectTexture6 = SDL_CreateTextureFromSurface(Scene1::renderer, boxClosed);
    objectTexture5 = SDL_CreateTextureFromSurface(Scene1::renderer, boxOpened);
    objectTexture7 = SDL_CreateTextureFromSurface(Scene1::renderer, boxEmpty);
    objectTextureAirBox = SDL_CreateTextureFromSurface(Scene1::renderer, airBox);
    objectTexturePipe = SDL_CreateTextureFromSurface(Scene1::renderer, pipeBox);
    objectTextureLantern = SDL_CreateTextureFromSurface(Scene1::renderer, lantern);
    objectTextureSparkle = SDL_CreateTextureFromSurface(Scene1::renderer, sparkle);

    invTexture3 = SDL_CreateTextureFromSurface(Scene1::renderer, pipe);
    invTexture6 = SDL_CreateTextureFromSurface(Scene1::renderer, lantern);
    invTexture7 = SDL_CreateTextureFromSurface(Scene1::renderer, disc);
    
    //Free up surfaces (Memory Management)
    SDL_FreeSurface(imageSurface10);
    SDL_FreeSurface(imageSurface11);
    SDL_FreeSurface(imageSurface12);
    SDL_FreeSurface(imageSurface13);
    SDL_FreeSurface(imageSurface14);
    SDL_FreeSurface(imageSurface15);
    SDL_FreeSurface(imageSurface16);
    SDL_FreeSurface(imageSurface17);
    SDL_FreeSurface(imageSurface18);
    SDL_FreeSurface(imageSurface20);
    SDL_FreeSurface(imageSurface21);
    SDL_FreeSurface(lantern);
    SDL_FreeSurface(pipe);
    SDL_FreeSurface(pipeBox);
    SDL_FreeSurface(airBox);
    SDL_FreeSurface(boxEmpty);
    SDL_FreeSurface(boxOpened);
    SDL_FreeSurface(boxClosed);
    SDL_FreeSurface(sparkle);
    SDL_FreeSurface(disc);

}