#include <iostream>

#include "Textures.h"
#include "Scene1.h"

using namespace brightland;

SDL_Texture* Textures::scene1f;
SDL_Texture* Textures::scene1fa;
SDL_Texture* Textures::scene1fb;
SDL_Texture* Textures::scene1d;
SDL_Texture* Textures::scene1d2;
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


void Textures::Scene1Textures() {


    SDL_DestroyTexture(scene1f);
    SDL_DestroyTexture(scene1fa);
    SDL_DestroyTexture(scene1fb);
    SDL_DestroyTexture(scene1d);
    SDL_DestroyTexture(scene1d2);



    //Scene Object Surfaces (no interaction).
    stars = NULL;

    //Scene Object Textures (no interaction).
    sceneTexture = NULL;

    invTexture1 = NULL;
    invTexture2 = NULL;
    invTexture3 = NULL;
    invTexture4 = NULL;

    //Player Object Surfaces.
    pda = NULL;
    flag = NULL;

    imageSurface = NULL;
    imageSurface2 = NULL;
    imageSurface3 = NULL;
    imageSurface4 = NULL;
    imageSurface5 = NULL;
    imageSurface6 = NULL;
    imageSurface7 = NULL;


    //Player Object Textures.
    Scene1::objectTexture = NULL;
    Scene1::objectTexture2 = NULL;
    Scene1::objectTexture3 = NULL;
    Scene1::objectTexture4 = NULL;
    Scene1::objectTexture5 = NULL;

    //Load in all Scene textures here. Only do this once as it uses RAM to do this.
    imageSurface = IMG_Load("scene1.png");
    imageSurface2 = IMG_Load("Scenes/rocks.png");
    imageSurface3 = IMG_Load("Scenes/ComputerScreen.png");
    imageSurface4 = IMG_Load("Scenes/scene1b1.png");
    imageSurface5 = IMG_Load("Scenes/ComputerScreen1.png");
    imageSurface6 = IMG_Load("Scenes/Scene1e.png");
    imageSurface7 = IMG_Load("Scenes/rocks2.png");



    //dialog = IMG_Load("Dialog/scene1_intro.png");
   // dialogm = IMG_Load("Dialog/scene1_moon.png");
    pda = IMG_Load("Objects/pda.png");
    flag = IMG_Load("Objects/flagr.png");
    stars = IMG_Load("Objects/stars3.png");
    tape = IMG_Load("Objects/tape.png");
    tent = IMG_Load("Objects/tent.png");

    texture = SDL_CreateTextureFromSurface(Scene1::renderer, imageSurface);
    computerScene1 = SDL_CreateTextureFromSurface(Scene1::renderer, imageSurface3);
    computerScene2 = SDL_CreateTextureFromSurface(Scene1::renderer, imageSurface5);
    wreakageScene = SDL_CreateTextureFromSurface(Scene1::renderer, imageSurface4);
    scene1e = SDL_CreateTextureFromSurface(Scene1::renderer, imageSurface6);
    rocks = SDL_CreateTextureFromSurface(Scene1::renderer, imageSurface2);
    rocks2 = SDL_CreateTextureFromSurface(Scene1::renderer, imageSurface7);

    Scene1::objectTexture = SDL_CreateTextureFromSurface(Scene1::renderer, pda);
    Scene1::objectTexture2 = SDL_CreateTextureFromSurface(Scene1::renderer, flag);
    Scene1::objectTexture4 = SDL_CreateTextureFromSurface(Scene1::renderer, tape);
    Scene1:: objectTexture5 = SDL_CreateTextureFromSurface(Scene1::renderer, tent);

    sceneTexture = SDL_CreateTextureFromSurface(Scene1::renderer, stars);

    invTexture1 = SDL_CreateTextureFromSurface(Scene1::renderer, pda);
    invTexture2 = SDL_CreateTextureFromSurface(Scene1::renderer, flag);
    invTexture3 = SDL_CreateTextureFromSurface(Scene1::renderer, tape);
    invTexture4 = SDL_CreateTextureFromSurface(Scene1::renderer, tent);

    SDL_FreeSurface(imageSurface);
    SDL_FreeSurface(imageSurface2);
    SDL_FreeSurface(imageSurface3);
    SDL_FreeSurface(imageSurface4);
    SDL_FreeSurface(imageSurface5);
    SDL_FreeSurface(imageSurface6);
    SDL_FreeSurface(imageSurface7);


}

void Textures::Scene2Textures() {

    //Clear out textures that will no longer be required to free up memory.
    SDL_DestroyTexture(computerScene1);
    SDL_DestroyTexture(computerScene2);
    SDL_DestroyTexture(wreakageScene);
    SDL_DestroyTexture(scene1f);
    SDL_DestroyTexture(scene1fa);
    SDL_DestroyTexture(rocks);
  //  SDL_DestroyTexture(rocks2);
    SDL_DestroyTexture(Scene1::objectTexture5);
    SDL_DestroyTexture(Scene1::objectTexture4);
    SDL_DestroyTexture(invTexture3);
    SDL_DestroyTexture(sceneTexture);

    //Player Object Textures.
    Scene1::objectTexture6 = NULL;
 

    imageSurface8 = NULL;
    imageSurface9 = NULL;
    imageSurface10 = NULL;
    imageSurface11 = NULL;
    pipe = NULL;

    pipe = IMG_Load("Objects/pipe.png");


    imageSurface8 =  IMG_Load("Scenes/Scene1f.png");
    imageSurface9 =  IMG_Load("Scenes/Scene1fa.png");
    imageSurface10 = IMG_Load("Scenes/Scene1fb.png");
    imageSurface11 = IMG_Load("Scenes/Scene1d.png");
    imageSurface12 = IMG_Load("Scenes/Scene1d2.png");
    boxOpened =      IMG_Load("Objects/boxopened.png");
    boxClosed =      IMG_Load("Objects/boxclosed.png");
    boxEmpty =       IMG_Load("Objects/boxopenede.png");

    scene1f = SDL_CreateTextureFromSurface(Scene1::renderer, imageSurface8);
    scene1fa = SDL_CreateTextureFromSurface(Scene1::renderer, imageSurface9);
    scene1fb = SDL_CreateTextureFromSurface(Scene1::renderer, imageSurface10);
    scene1d = SDL_CreateTextureFromSurface(Scene1::renderer, imageSurface11);
    scene1d2 = SDL_CreateTextureFromSurface(Scene1::renderer, imageSurface12);

    Scene1::objectTexture6 = SDL_CreateTextureFromSurface(Scene1::renderer, boxClosed);
    Scene1::objectTexture5 = SDL_CreateTextureFromSurface(Scene1::renderer, boxOpened);
    Scene1::objectTexture7 = SDL_CreateTextureFromSurface(Scene1::renderer, boxEmpty);

    invTexture3 = SDL_CreateTextureFromSurface(Scene1::renderer, pipe);

    SDL_FreeSurface(imageSurface8);
    SDL_FreeSurface(imageSurface9);
    SDL_FreeSurface(imageSurface10);
    SDL_FreeSurface(imageSurface11);
    SDL_FreeSurface(imageSurface12);

}