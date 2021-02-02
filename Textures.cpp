#include <iostream>

#include "Textures.h"
#include "Scene1.h"

using namespace brightland;


SDL_Texture* Textures::menuTexture;

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
SDL_Texture* Textures::sceneTexture;

SDL_Texture* Textures::rocks;
SDL_Texture* Textures::rocks2;
SDL_Texture* Textures::computerScene1;
SDL_Texture* Textures::computerScene2;


SDL_Texture* Textures::invTexture1;
SDL_Texture* Textures::invTexture2;
SDL_Texture* Textures::invTexture3;
SDL_Texture* Textures::invTexture4;
SDL_Texture* Textures::invTexture5;
SDL_Texture* Textures::invTexture6;

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

SDL_Texture* Textures::spriteTexture;
SDL_Surface* Textures::spriteDown1;
SDL_Surface* Textures::spriteDownp;
SDL_Surface* Textures::spriteBack1a;

void Textures::Scene1Textures() {


    SDL_DestroyTexture(scene1f);
    SDL_DestroyTexture(scene1fa);
    SDL_DestroyTexture(scene1fb);
    SDL_DestroyTexture(scene1d);
    SDL_DestroyTexture(scene1d2);

    //Load in all Scene textures here. Only do this once as it uses RAM to do this.
    menuSurface = IMG_Load("menu.png");
    
    imageSurface = IMG_Load("scene1.png");
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

    sceneTexture = SDL_CreateTextureFromSurface(Scene1::renderer, stars);

    invTexture1 = SDL_CreateTextureFromSurface(Scene1::renderer, pda);
    invTexture2 = SDL_CreateTextureFromSurface(Scene1::renderer, flag);
    invTexture3 = SDL_CreateTextureFromSurface(Scene1::renderer, tape);
    invTexture4 = SDL_CreateTextureFromSurface(Scene1::renderer, tent);

    menuTexture = SDL_CreateTextureFromSurface(Scene1::renderer, menuSurface);
    spriteTexture = SDL_CreateTextureFromSurface(Scene1::renderer, Textures::spriteDown1);
   

}

void Textures::Scene2Textures() {

    //Clear out textures that will no longer be required to free up memory.
   
    
    SDL_DestroyTexture(invTexture3);
    imageSurface8 =  IMG_Load("Scenes/Scene1f.png");
    imageSurface9 =  IMG_Load("Scenes/Scene1fa.png");
    scene1f = SDL_CreateTextureFromSurface(Scene1::renderer, imageSurface8);
    scene1fa = SDL_CreateTextureFromSurface(Scene1::renderer, imageSurface9);
    


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

   
    imageSurface10 = IMG_Load("Scenes/Scene1fb.png");
    imageSurface11 = IMG_Load("Scenes/Scene1d.png");
    imageSurface12 = IMG_Load("Scenes/Scene1d2.png");
    imageSurface13 = IMG_Load("Scenes/Scene3a.png");
    imageSurface14 = IMG_Load("Scenes/Scene3b.png");
    scene1fb = SDL_CreateTextureFromSurface(Scene1::renderer, imageSurface10);
    scene1d = SDL_CreateTextureFromSurface(Scene1::renderer, imageSurface11);
    scene1d2 = SDL_CreateTextureFromSurface(Scene1::renderer, imageSurface12);
    scene3a = SDL_CreateTextureFromSurface(Scene1::renderer, imageSurface13);
    scene3b = SDL_CreateTextureFromSurface(Scene1::renderer, imageSurface14);

 
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


}