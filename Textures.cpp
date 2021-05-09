#include <iostream>

#include "Textures.h"
#include "Scene1.h"

using namespace brightland;

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
SDL_Texture* Textures::wreakageScene;
SDL_Texture* Textures::scene1e;
SDL_Texture* Textures::texture;
SDL_Texture* Textures::starsTexture;
SDL_Texture* Textures::computerScene1;
SDL_Texture* Textures::computerScene2;
SDL_Texture* Textures::caveScene1;
SDL_Texture* Textures::caveScene2;

//Overlay Textures.
SDL_Texture* Textures::rocks;
SDL_Texture* Textures::rocks2;

//Inventory Textures.
SDL_Texture* Textures::invTexture1;
SDL_Texture* Textures::invTexture2;
SDL_Texture* Textures::invTexture3;
SDL_Texture* Textures::invTexture4;
SDL_Texture* Textures::invTexture5;
SDL_Texture* Textures::invTexture6;

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
   

    objectTexture = SDL_CreateTextureFromSurface(Scene1::renderer, pda);
    objectTexture2 = SDL_CreateTextureFromSurface(Scene1::renderer, flag);
    objectTexture4 = SDL_CreateTextureFromSurface(Scene1::renderer, tape);
    objectTexture5 = SDL_CreateTextureFromSurface(Scene1::renderer, tent);

    starsTexture = SDL_CreateTextureFromSurface(Scene1::renderer, stars);
    SDL_FreeSurface(stars);

    invTexture1 = SDL_CreateTextureFromSurface(Scene1::renderer, pda);
    SDL_FreeSurface(pda);
    invTexture2 = SDL_CreateTextureFromSurface(Scene1::renderer, flag);
    SDL_FreeSurface(flag);
    invTexture3 = SDL_CreateTextureFromSurface(Scene1::renderer, tape);
    SDL_FreeSurface(tape);
    invTexture4 = SDL_CreateTextureFromSurface(Scene1::renderer, tent);
    SDL_FreeSurface(tent);

    menuTexture = SDL_CreateTextureFromSurface(Scene1::renderer, menuSurface);
    SDL_FreeSurface(menuSurface);
    spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, Textures::spriteDown1);
   
    SDL_FreeSurface(imageSurface);
    SDL_FreeSurface(imageSurface3);
    SDL_FreeSurface(imageSurface5);
    SDL_FreeSurface(imageSurface4);
    SDL_FreeSurface(imageSurface6);
    SDL_FreeSurface(imageSurface2);
    SDL_FreeSurface(imageSurface7);
}

void Textures::Scene2Textures() {

    //Clear out textures that will no longer be required to free up memory. 
    SDL_DestroyTexture(invTexture3);

    //Load in new textures.
    imageSurface8 =  IMG_Load("Scenes/Scene1f.png");
    imageSurface9 =  IMG_Load("Scenes/Scene1fa.png");
    scene1f = SDL_CreateTextureFromSurface(Scene1::renderer, imageSurface8);
    scene1fa = SDL_CreateTextureFromSurface(Scene1::renderer, imageSurface9);
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

    scene1fb = SDL_CreateTextureFromSurface(Scene1::renderer, imageSurface10);
    
    scene1d = SDL_CreateTextureFromSurface(Scene1::renderer, imageSurface11);
    
    scene1d2 = SDL_CreateTextureFromSurface(Scene1::renderer, imageSurface12);
  
    scene3a = SDL_CreateTextureFromSurface(Scene1::renderer, imageSurface13);
   
    scene3b = SDL_CreateTextureFromSurface(Scene1::renderer, imageSurface14);
  
    caveScene1 = SDL_CreateTextureFromSurface(Scene1::renderer, imageSurface15);
  
    caveScene2 = SDL_CreateTextureFromSurface(Scene1::renderer, imageSurface16);
   

 
    boxOpened = IMG_Load("Objects/boxopened.png");
    boxClosed = IMG_Load("Objects/boxclosed.png");
    boxEmpty = IMG_Load("Objects/boxopenede.png");
    pipeBox = IMG_Load("Objects/pipec.png");
    airBox = IMG_Load("Objects/airBox.png");
    lantern = IMG_Load("Objects/lantern.png");
    pipe = IMG_Load("Objects/pipe.png");

    objectTexture6 = SDL_CreateTextureFromSurface(Scene1::renderer, boxClosed);
    objectTexture5 = SDL_CreateTextureFromSurface(Scene1::renderer, boxOpened);
    objectTexture7 = SDL_CreateTextureFromSurface(Scene1::renderer, boxEmpty);
    objectTextureAirBox = SDL_CreateTextureFromSurface(Scene1::renderer, airBox);
    objectTexturePipe = SDL_CreateTextureFromSurface(Scene1::renderer, pipeBox);
    objectTextureLantern = SDL_CreateTextureFromSurface(Scene1::renderer, lantern);

    invTexture3 = SDL_CreateTextureFromSurface(Scene1::renderer, pipe);
    invTexture6 = SDL_CreateTextureFromSurface(Scene1::renderer, lantern);
    
    SDL_FreeSurface(imageSurface10);
    SDL_FreeSurface(imageSurface11);
    SDL_FreeSurface(imageSurface12);
    SDL_FreeSurface(imageSurface13);
    SDL_FreeSurface(imageSurface14);
    SDL_FreeSurface(imageSurface15);
    SDL_FreeSurface(imageSurface16);


}