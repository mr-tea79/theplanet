
/* Adventure Game Creator Engine by Damian Baldry @ Brightland. Written in 2020
   Very much a work in progress!
   V3.01 (April 2021)

*/

#include <iostream>
#include <algorithm>
#include <chrono>
#include "Scene1.h"
#include "PlayerMovement.h"
#include "PlayerObjects.h"
#include "PlayerInteraction.h"
#include "MenuInteraction.h"
#include "Inventory.h"
#include "Textures.h"
#include "SceneRender.h"
#include "ObjectRender.h"


using namespace std;
using namespace brightland;

//Initialize the global variables accessed by other classes.
std::string Scene1::useStatement = "";
std::string Scene1::openStatement = "";
std::string Scene1::lookStatement = "";
std::string Scene1::actionStatement = "";
std::string Scene1::SceneTransitionStatement = "";
std::string Scene1::SceneBackground = "1";
std::string gameMessage; //Used to display messages that tell the story.
std::string Scene1::objectToDestroy;

//Main Game window and Text dialog window.
SDL_Window* Scene1::window;
SDL_Rect Scene1::textRect;
TTF_Font* Scene1::font;
SDL_Surface* Scene1::fsurface;
SDL_Color Scene1::fcolor;
SDL_Color Scene1::bcolor;
SDL_Texture* Scene1::ftexture = NULL;
SDL_Rect Scene1::dTexture;
SDL_Rect Scene1::background;
SDL_Rect Scene1::background2;
SDL_Rect Scene1::background3;
SDL_Rect Scene1::background4;
int Scene1::xPosition;
int Scene1::yPosition;
int Scene1::SPRITE_SIZE;
int playerIsMoving = 0;  //This is used to prevent the sprite from stuttering when walking due to the _sleep which prevents a memory leak when repeatedly hovering over objects. You need to adjust values in the movement class which I'll mention in that class.

int Scene1::action; //Used to trigger action texture.
int Scene1::sceneHalt = 0;  //sceneHalt is useful for displaying player messages and scene transitions. 
bool playerMessage = false;  //Used to keep the player text on the screen long enough that you can actually read it!
bool Scene1::mouseClick = false;

SDL_Rect Scene1::gdSprite;
SDL_Renderer* Scene1::renderer;

int Scene1::tLoader = 0;  //Used to prevent the same textures being loaded in twice. Needs looking at as I don't think its working correctly.


//This will help when transitioning to a new scene. 
void Scene1::DoAction() {
    _sleep(100);
    action = 0;
}

int Scene1::scene1() {

    cout << "Initialize" << endl;
    scene = 1; //Scene Number.
        
    //Set initial position of game character and the size of the character.
    xPosition = 10;
    yPosition = 430;

    //Use this to jump to a scene. Comment the 4 lines below out and uncomment the SPRITE_SIZE =120 to return to normal.
    SceneBackground = "1";
    
   // SPRITE_SIZE = 10;
   // xPosition = 310;
   // yPosition = 350;

    //THIS IS THE DEFAULT SCENE
    //Normal Size (Uncomment)
    SPRITE_SIZE = 120;

    
    //Static variables that are updated while the program is running.
    static int position;
    static int mInteraction;

    //Used to check which objects are currently picked up by the user.
    static std::string gameObject;

    //Strings used for message handing. Contain returned values from the game loop.
    std::string interactionMessage;
    std::string useMessage;
    std::string openMessage;
    std::string lookMessage;
    std::string actionMessage;

  
    //Allow usage of .png images.
    int imgFlags = IMG_INIT_PNG;

    //Player location variables.
    int gd;
    int gy;
    int x =0, y = 0;
    int wx=0,wy=0;
     
    //Text Dialog.
    fsurface =       NULL;
    
    //Image RECTS are used to hold in game images and are set to a given position (x,y,height,width).
    
    //Main background Rect
    background = { 0, 0, 1024, 600 };

    //Background overlay Rects (Rocks in foreground etc)
    background2 = { 0, 200, 1500, 400 };
    
    //This is the hill on the rocky path scene.
    background3 = { 0, 310, 1100, 300 };

    //Interaction Menu Rect
    menu = { 0, 600, 1024, 568 };
  
    SDL_Surface* SDL_DisplayFormat(SDL_Surface * surface);

    SDL_Init(SDL_INIT_EVERYTHING);
    TTF_Init();

    window = SDL_CreateWindow("The Planet and Bonita", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI | SDL_WINDOW_RESIZABLE);
    windowSurface =  SDL_GetWindowSurface(window);
    renderer =       SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED || SDL_RENDERER_PRESENTVSYNC); //|| SDL_RENDERER_PRESENTVSYNC
       //             SDL_SetWindowFullscreen(window, SDL_TRUE);  //Stretch the screen.
    font =           TTF_OpenFont("arial.ttf", 25);
    fcolor =         { 255, 255, 255 }; //Font colour.
    bcolor =         { 0,0,0 }; //Font background colour.
  
    //Something to do with the font texture.
    SDL_QueryTexture(ftexture, NULL, NULL, &texW, &texH);
  
    //Place the player sprite in the chosen location.
    gdSprite.x = xPosition;
    gdSprite.y = yPosition;

    //Initialize Textures
    Textures tex;
    tex.LoadActionTextures();
    tex.Scene1Textures();
    tex.MovementTextures();
    //tex.Scene2Textures();
   // tex.Scene3Textures();
 
    //Purge the Inventory for a new game. SAVE GAME feature will be added at the end of the project.
    Inventory inv;
    inv.purgeDatabase();

    //Menu Interaction USE, LOOK etc.
    MenuInteraction mob;
   
    //Load player movement class.
    PlayerMovement player;

    //Load player movement class.
    PlayerObjects pob;

    //Load player message class.
    PlayerInteraction pi;

    //Load Scene Render class
    SceneRender sr;

    //Load Ojbect Render class
    ObjectRender obr;

    //Game loop.
    while (!gameover)
    {        
        //Place player objects in the game.
        pob.ObjectController();

        //Show patch on suit
        if (Inventory::inv3Used == 1) {
            Textures::spriteDown1 = Textures::spriteDownp;
            Textures::spritePick = Textures::spritePickp;
        }

    

        SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);

        SDL_RenderClear(renderer);

        if (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_WINDOWEVENT:
                switch (event.window.event)
                {
                case SDL_WINDOWEVENT_RESIZED: {
					SDL_RenderSetScale(renderer, event.window.data1 / (float)WIDTH, event.window.data2 / (float)HEIGHT);
                } break;
                case SDL_WINDOWEVENT_ENTER:
                    break;

                case SDL_WINDOWEVENT_LEAVE:   
                    break;
                }
                break;

                case SDL_QUIT:
                    gameover = 1;
                    break;

                //Mouse Hover Game Interaction.
                case SDL_MOUSEMOTION:      
                        //Event Motion coordinates. Where the mouse moves on the screen.
                        x = event.motion.x;
                        y = event.motion.y;
                        gd = gdSprite.x;
                        gy = gdSprite.y;
                    
                        if (event.motion.y > 589 && event.motion.x < 289 || event.motion.y == gy + 90 || event.motion.y == gy - 90 || event.motion.x == gd + 90 || event.motion.x == gd - 90) {                                                  
                            playerMessage = false;
                        }


                        //This addresses the movement to the left issue where the player never reaches to destination and prevents hover interaction.
                        if (playerMessage != true && interactionMessage == "") {                          
                            //Prevents sleep from kicking in when walking to a target.
                            if (gdSprite.x < gd && gdSprite.y < y || gdSprite.x > gd && gdSprite.y > y) {
                                SDL_DestroyTexture(ftexture);
                                playerIsMoving = 0;                           
                            }
                           
                            else {                               
                                SDL_DestroyTexture(ftexture);
                                SDL_DestroyTexture(Textures::spriteTexture);
                                Textures::spriteTexture = SDL_CreateTextureFromSurface(renderer, Textures::spriteDown1); //Makes player face you when you are hovering.                     
                            }
                          
                                interactionMessage = pob.HoverObjects(x, y, scene, gd, gy);                            
                        }

                        if (interactionMessage != "" && playerIsMoving !=1) {   
                            pi.InteractionControllerHover(interactionMessage);
                        }                 

                        break;                    
                    
                case SDL_KEYDOWN:
                    switch (event.key.keysym.sym)
                    {
                        case SDLK_ESCAPE:
                        case SDLK_q:
                        gameover = 1;
                        break;
                    }
                    break;          
                }
                
        }

        keystate = SDL_GetKeyboardState(NULL);

        if (SDL_MOUSEBUTTONUP) {       
     
        }
        if (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_LEFT)) {
            mouseClick = true;
            playerIsMoving = 0;
            playerMessage = false;
            SceneTransitionStatement = "";  //Clear the static clicked location (The location you sent your player to).
            //The following 2 lines will allow you to use an object with another object.
            interactionMessage = pob.HoverObjects(x, y, scene, gd, gy);
            useStatement = interactionMessage;

            //This fixes the bug where if you decide to not to commit to picking something up.
            if (interactionMessage == "") {
                actionStatement = "";
               
            }

            if(sceneHalt == 0 && playerMessage !=true ){
                SDL_DestroyTexture(Textures::spriteTexture);
                Textures::spriteTexture = SDL_CreateTextureFromSurface(renderer, Textures::spriteDown1);              
            }
                      
            Uint8 buttons = SDL_GetMouseState(&wx, &wy);
            gd = gdSprite.x;
            gy = gdSprite.y;

            //Show coordinates in console for object placement.
            cout << string(100, '\n');
            std::cout << "Mouse Click X Location = " << x << std::endl;
            std::cout << "" << std::endl;
            std::cout << "Mouse Click Y Location = " << y << std::endl;
            std::cout << "" << std::endl;
            std::cout << "Current Player X Position is: " << gdSprite.x << std::endl;
            std::cout << "" << std::endl;
            std::cout << "Current Player Y Position is: " << gdSprite.y << std::endl;
            std::cout << "" << std::endl;
            std::cout << "Current Scene is: " << SceneBackground << std::endl;
            std::cout << "" << std::endl;

        
            //Get interaction message.         
            interactionMessage = pob.ObjectInteraction( x, y, gd, gy);           
            actionMessage = mob.MenuAction(x, y, gd, gy, mInteraction, Textures::spriteTexture, renderer, Textures::spriteDown1, "");
                  
            if (actionMessage != "" || actionStatement != "") {   
               pi.InteractionControllerLook(actionMessage, gameObject);
            }

            if (interactionMessage != "") {
                pi.InteractionControllerObject(interactionMessage, gameObject);
            }
        }
   
        gd = gdSprite.x;
        gy = gdSprite.y;

        //These messages are displayed to help tell the story.
        gameMessage = pi.DisplayPlayerMessages();

        if (gameMessage != "") {
            interactionMessage = gameMessage;
            PlayerInteraction::playerMessage = 100;
        }

        if (interactionMessage != "" && sceneHalt == 1) {
            playerMessage = true;
            pi.InteractionControllerObject(interactionMessage, gameObject);
        }

        if (actionMessage != "Pick up what?") {
            gameObject = mob.PickUp(x, y, gd, gy, mInteraction, Textures::spriteTexture, renderer, Textures::spritePick, Textures::spriteBack1a,"");
        }
        if (actionMessage != "Look at what?") {
            lookMessage = mob.Look(x, y, gd, gy, mInteraction, Textures::spriteTexture, renderer, Textures::spriteDown1, Textures::spriteBack1a, "");
        }
        if (actionMessage != "Use what?") {
            useMessage = mob.Use(x, y, gd, gy, mInteraction, Textures::spriteTexture, renderer, Textures::spriteDown1, Textures::spriteBack1a, "");
        }
        if (actionMessage != "Open what?") {
            openMessage = mob.Open(x, y, gd, gy, mInteraction, Textures::spriteTexture, renderer, Textures::spriteDown1, "");
        }

        if (lookMessage != "" ) {  
            playerMessage = true;
            pi.InteractionControllerLook(lookMessage, gameObject);         
        }

        if (useMessage != "") {
            playerMessage = true;
            pi.InteractionControllerUse(useMessage, gameObject);
        }

        if (openMessage != "") {
            playerMessage = true;
            pi.InteractionControllerOpen(openMessage, gameObject);
        }

 
        if (wx > gdSprite.x || wx < gdSprite.x) {
          
            if(action !=1 ){
                //This is critical and prevents sprite from disappearing.
                SDL_DestroyTexture(Textures::spriteTexture);
                Textures::spriteTexture = SDL_CreateTextureFromSurface(renderer, Textures::spriteDown1);
            }
            else {
                DoAction();
            }
           
            if (sceneHalt == 0) {
                playerMessage = false;
                gdSprite.x = player.walk(wx, wy, gd, gy, WIDTH, HEIGHT, Textures::spriteTexture, ftexture, dialogmTexture);
                playerIsMoving = 1;
                _sleep(1);

                if (wy < gdSprite.y || wy > gdSprite.y) {
                   
                    //The following 2 statements will allow the player to move across and then up or down.
                    if (y <= gdSprite.y && wx <= gdSprite.x + 75 && wx >= gdSprite.x){
                        gdSprite.y = player.walky(wx, wy, gd, gy, WIDTH, HEIGHT, Textures::spriteTexture, ftexture, dialogmTexture);
                        playerIsMoving = 0;
                     
                    }
                    if (y >= gdSprite.y && wx <= gdSprite.x + 75 && wx >= gdSprite.x){
                        gdSprite.y = player.walky(wx, wy, gd, gy, WIDTH, HEIGHT, Textures::spriteTexture, ftexture, dialogmTexture);
                        playerIsMoving = 0;
                      
                    }                              
                    _sleep(1);  //This makes the animation of the character look a bit more realistic and less like she's on skates. _sleep is probably not the best way of doing this, but it does work so..
                }
            }
            else {
                //This code prevents the character from continuing to walk when changing scenes.
                    x = gdSprite.x;
                    y = gdSprite.y;
                    wx = gdSprite.x;
                    wy = gdSprite.y;

                    _sleep(300);
                    sceneHalt = 0;
            }
            
            //This is where I am attempting to allow the player to walk directly to another scene after the user has chosen the destination. This is not perfect yet.
            if (gdSprite.x < gd || gdSprite.x > gd || gdSprite.y < gy || gdSprite.y >gy) {
                interactionMessage = pob.ObjectInteraction(x, y, gd, gy);
            }
            else
                playerIsMoving = 0;  //Player is not moving.        
          
    }

        //RENDERING SECTION. THIS IS WHERE THE GRAPHICS ARE RENDERED IN THE GAME LOOP. I TRIED MOVING THIS TO ANOTHER CLASS BUT ALL SORTS OF THINGS WENT WRONG.
        //Render the window
        SDL_RenderClear(renderer);
        
        sr.sceneRender();  //Render the game scene backgrounds.

    
        //This needs to go here, don't move it!
        SDL_RenderCopy(renderer, Textures::menuTexture, NULL, &menu);   
 
        obr.objectRender(); //Render the game objects (Things that the player can pick up).

        //Set character size.
        gdSprite.w = SPRITE_SIZE;
        gdSprite.h = SPRITE_SIZE;
          
        if(PlayerInteraction::playerMessage > 3){
            //Render main character
            SDL_RenderCopy(renderer, Textures::spriteTexture, NULL, &gdSprite);
        }
     
    
        sr.sceneRenderOverlay(); //Render objects in front of sprite.

        SDL_RenderCopy(renderer, ftexture, NULL, &textRect);
     
       
        interactionMessage = ""; // Clear the interaction message on every loop.
        gameMessage = "";
        useMessage = "";
        //Make something appear!    
        SDL_RenderPresent(renderer);
  
    }

    

    //Clean up after yourself!
    SDL_DestroyRenderer(renderer); //Destroy Renderer should destroy ALL textures.
    SDL_DestroyWindow(window);
    TTF_CloseFont(font);
 
    return 0;

    TTF_Quit();
    SDL_Quit();
}
