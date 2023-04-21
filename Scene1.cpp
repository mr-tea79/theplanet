
/* Adventure Game Creator Engine by Damian Baldry @ Brightland. Written in 2020
   Very much a work in progress!
   V3.05 (September 2022)

*/

#include <thread>
#include <iostream>
#include <algorithm>
#include <chrono>
#include "Scene1.h"
#include "PlayerMovement.h"
#include "PlayerObjects.h"
#include "PlayerInteraction.h"
#include "MenuInteraction.h"
#include "AI.h"
#include "Inventory.h"
#include "Textures.h"
#include "SceneRender.h"
#include "ObjectRender.h"
#include "SDL_mixer.h"
#include "Sound.h"
#include <vector>
#include "SceneInteraction.h"
#include "ObjectPositions.h"

using namespace std;
using namespace brightland;

//Initialize the global variables accessed by other classes.
std::string Scene1::useStatement = "";
std::string Scene1::openStatement = "";
std::string Scene1::lookStatement = "";
std::string Scene1::pickUpStatement = "";
std::string Scene1::actionStatement = "";
std::string Scene1::SceneTransitionStatement = "";
std::string Scene1::SceneBackground = "3e";
std::string gameMessage; //Used to display messages that tell the story.
std::string Scene1::objectToDestroy;

//Main Game window and Text dialog window.
SDL_Window* Scene1::window;
SDL_Rect Scene1::textRect;
TTF_Font* Scene1::font;
SDL_Surface* Scene1::fsurface;
SDL_Color Scene1::fcolor;
SDL_Color Scene1::bcolor;

//Screen Dimensions.
int Scene1::HEIGHT = 768;
int Scene1::WIDTH = 1024;

//Player variables
int Scene1::xPosition;
int Scene1::yPosition;
int Scene1::SPRITE_SIZE;

int Scene1:: playerIsMoving = 0;  //This is used to prevent the sprite from stuttering when walking due to the _sleep which prevents a memory leak when repeatedly hovering over objects. You need to adjust values in the movement class which I'll mention in that class.
bool playerMessage = false;  //Used to keep the player text on the screen long enough that you can actually read it!
bool Scene1::continueGame = false;
bool Scene1::newGame = false;
static bool checkHoverLocation = false;
int Scene1::threadRipper = 0; //Thread 2 stopper.
bool Scene1::fullScreenTrigger = false;

//Scene variables
int Scene1::action; //Used to trigger action texture.
int Scene1::sceneHalt = 0;  //sceneHalt is useful for displaying player messages and scene transitions. 
int Scene1::secretTrigger = 0;  //This is used to tell the program that a secret has been found.
int Scene1::menuSound = 0; //For menu clicking sounds.
int Scene1::hoverSound = 0; //For object hover sounds.
bool Scene1::mouseClick = false;
int Scene1::tLoader = 0;  //Used to prevent the same textures being loaded in twice. Needs looking at as I don't think its working correctly.
int Scene1::inGame = 0;
bool Scene1::doPerfCheck = true; //This is to inform the system to do a performance check of hardware.
bool Scene1::quitGame = false;
//int Scene1::soundCount = 0;

int Scene1::moveX;
int Scene1::moveY;
int moveXA;
int moveXY;
int Scene1::xp;
int Scene1::yp;
int Scene1::playerXP;
int Scene1::playerYP;
int Scene1::xpc;
int Scene1::ypc;

static int mouseHold = 0;
int Scene1::hoverHold = 0;

SDL_Rect Scene1::gdSprite;
SDL_Renderer* Scene1::renderer;


//This will help when transitioning to a new scene. 
void Scene1::DoAction() {
    SDL_Delay(100);
    action = 0;
}

bool Scene1::checkFScreenStatus(bool status) {
    Scene1::fullScreenTrigger = status;
    if (Scene1::fullScreenTrigger == true) {
        SDL_SetWindowFullscreen(window, SDL_TRUE);
    }
    else{ SDL_SetWindowFullscreen(window, SDL_FALSE); }
    return status;
}

int Scene1::scene1() {
  
    cout << "Initialize" << endl;
    scene = 1; //Scene Number.
  
    //Use this to jump to a scene. Comment the 4 lines below out and uncomment the SPRITE_SIZE =120 to return to normal.
    SceneBackground = "0";

    //This is the size of the player sprite.
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
    std::string pullMessage;
     
    //Allow usage of .png images.
    int imgFlags = IMG_INIT_PNG;

    //Player location variables.
    int gd;
    int gy;
    int x =0, y = 0;
    int wx=0,wy=0;

    //Testing game loop speed.
    static int timerStop = 0;
     
    //Text Dialog.
    fsurface =       NULL;
    
    //Interaction Menu Rect
    menu = { 0, 600, 1024, 568 };
  
    SDL_Surface* SDL_DisplayFormat(SDL_Surface * surface);

    SDL_Init(SDL_INIT_EVERYTHING);
    TTF_Init();

    window = SDL_CreateWindow("The Planet and Bonita", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN /* | SDL_WINDOW_RESIZABLE*/ | SDL_WINDOW_ALLOW_HIGHDPI);
 
    windowSurface =  SDL_GetWindowSurface(window);
    renderer =       SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED ); 
    font =           TTF_OpenFont("arial.ttf", 25);
    fcolor =         { 255, 255, 255 }; //Font colour.
    bcolor =         { 0,0,0 }; //Font background colour.
    SDL_ShowCursor(SDL_DISABLE); // Disable default mouse pointer because I want to use my customized one!
  
    // Inilialize SDL_mixer , exit if fail
    if (SDL_Init(SDL_INIT_AUDIO) < 0) exit(1);
    Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096);
    Mix_Init(MIX_INIT_MP3);
    
    //Something to do with the font texture.
    SDL_QueryTexture(Textures::ftexture, NULL, NULL, &texW, &texH);
  
    //Place the player sprite in the chosen location.
    gdSprite.x = xPosition;
    gdSprite.y = yPosition;

    //Initialize Textures
    Textures tex;
    Inventory inv;
    tex.LoadActionTextures();
    tex.Scene1Textures(); 
    tex.MovementTextures();

    //TOAD AI - For conversations and story dialog.
    AI ai;
  
    //Menu Interaction USE, LOOK etc.
    MenuInteraction mob;
    
    //Load player movement class.
    PlayerMovement player;

    //Load player movement class.
    PlayerObjects pob;

    //Used for scene transitions of player.
    SceneInteraction si;

    //Load player message class.
    PlayerInteraction pi;

    //Load Scene Render class
    SceneRender sr;

    //Load Ojbect Render class
    ObjectRender obr;

    //Load sound class
    Sound s;

    //Placing objects in the game.
    ObjectPositions op;
    
    //Load in some sounds!
    s.loadMovementSounds();
    s.loadClickSound();
    s.loadHoverSound();
    s.loadSounds("0");

    //Init the TOAD1000 AI Thread.
    ai.ToadTalk();

   

    AI::aiPlayMessages = true;
    PlayerInteraction::playerMessage = 15;

    auto start_time = std::chrono::high_resolution_clock::now();
    //Start the timer.
   // std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
   

    //Create a game save (Only needed to use this once to create the game save record)
    //inv.SQLCreateGameSave(SceneBackground);
    
    //Game loop.
    while (!gameover)
    {        
        //Calculate positions of hover objects.
        std::cout << "Player is Moving=" << playerIsMoving << std::endl;
       // std::cout << "PDA X Position:" << ObjectPositions::PDA_X << std::endl;
       // std::cout << "PDA Y Position:" << ObjectPositions::PDA_Y << std::endl;
        checkFScreenStatus(fullScreenTrigger);
        s.checkSoundStatus(Sound::soundOn);
        Mix_VolumeMusic(MIX_MAX_VOLUME / 7);

            
        yPosition = gdSprite.y;
        xPosition = gdSprite.x;
        gd = gdSprite.x;
        gy = gdSprite.y;

        mob.useChecker(gd, gy); //Deals with wrong use actions. Pain to figure out!
                     

        if (newGame == true) {
            //Purge the Inventory for a new game. SAVE GAME feature will be added at the end of the project.   
            inv.purgeDatabase();
            newGame = false;
        }
        else {
            AI::aiPlayMessages = false;
        }

        //Check what textures and player invetory is required when continuing a game.
        inv.continueGameCheck();

        //Place player objects in the game.
        pob.ObjectController();

        //Show Ape Tape on suit
        if (Inventory::inv.find("3") != std::string::npos) {
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
                case SDL_WINDOWEVENT_ENTER:
                    break;

                case SDL_WINDOWEVENT_LEAVE:   
                    break;
                }
                break;

                case SDL_QUIT:
                    threadRipper = 1;
                    gameover = 1;
                    if (Scene1::SceneBackground != "01" && Scene1::SceneBackground != "0") {
                        inv.gameSave(SceneBackground);
                        inv.gameSpeedSave();
                
                    }
                
                    inv.gameSpeedSave();
                    break;

                //Mouse Hover Game Interaction.
                case SDL_MOUSEMOTION:      
                        //Event Motion coordinates. Where the mouse moves on the screen.
                        x = event.motion.x;
                        y = event.motion.y;
                        gd = gdSprite.x;
                        gy = gdSprite.y;
                        menuSound = 0;
                        mouseHold = 0;  
                        op.PlaceHoverObjects();
                        Scene1::xp = op.CalcObjectXPositionPercentage(x, "X");
                        Scene1::yp = op.CalcObjectYPositionPercentage(y, "Y");
                        xpc = op.CalcObjectXAbsolutePosition(xp, "XPC");
                        ypc = op.CalcObjectYAbsolutePosition(yp, "YPC");


                        moveX = op.CalcObjectXPositionPercentage(x, "X");
                        moveY = op.CalcObjectYPositionPercentage(y, "Y");
                      
                        std::cout << "Mouse X Position: " << moveX << "%" << std::endl;
                        std::cout << "Mouse Y Position: " << moveY << "%" << std::endl;
                   
                        //Update custom cursor location when the mouse moves.
                        Textures::RCursor = { x-24,y-26,50,50 };
                     
                        checkHoverLocation = s.checkHoverLocation(x, y);
                        //This is an attempt to prevent hover sounds looping, a REAL brain teaser if I have saw one!
                                       
                        if (checkHoverLocation == 0 && hoverHold < 1){
                            std::cout << "YES PLAY HOVER SOUND!" << std::endl;
                            s.playHoverSound();
                            hoverHold++;
                        }
                        if (checkHoverLocation == 1) {
                            hoverHold = 0;
                        }

                       // if (event.motion.y > 589 && event.motion.x < 289 || event.motion.y == gy + 90 || event.motion.y == gy - 90 || event.motion.x == gd + 90 || event.motion.x == gd - 90 && AI::aiStop !=1) {
                        if (event.motion.y == gy + 90 || event.motion.y == gy - 90 || event.motion.x == gd + 90 || event.motion.x == gd - 90) {    
                            playerMessage = false;
                            playerIsMoving = 0;
                            sceneHalt = 0; // Fixes issue where hover text appears in speech area.                                                   
                        }
                       

                        //This addresses the movement to the left issue where the player never reaches to destination and prevents hover interaction.
                        if (playerMessage != true && interactionMessage == "" && AI::aiStop !=1 ) {                   
                            
                            //Prevents delay from kicking in when walking to a target.
                            if (gdSprite.x < gd && gdSprite.y < y || gdSprite.x > gd && gdSprite.y > y) {   
                               
                            }                         
                            else {              
                                    SDL_DestroyTexture(Textures::ftexture);
                                    Textures::ftexture = nullptr; //IF YOU REMOVE THIS YOU WILL GET THE PLAYER SPRITE POPPING INTO THE TEXT AREA!
                                    SDL_DestroyTexture(Textures::spriteTexture);
                                    Textures::spriteTexture = nullptr; 
                                    playerIsMoving = 0;
                                    Textures::spriteTexture = SDL_CreateTextureFromSurface(renderer, Textures::spriteDown1); //Makes player face you when you are hovering.  
                                    PlayerMovement::blink = true;                                  
                            }
                         
                            if (playerIsMoving != 1) {
                                interactionMessage = pob.HoverObjects(x, y, scene, gd, gy);
                            }
                        } 
                       
                        if (interactionMessage != "" && playerIsMoving !=1) {                      
                            hoverHold++;
                            pi.InteractionControllerHover(interactionMessage);
                            PlayerMovement::blink = false;                                    
                        }  
                        else {
                           
                        }
                 
                        break;                    
                    
                case SDL_KEYDOWN:
                    switch (event.key.keysym.sym)
                    {
                        case SDLK_ESCAPE:
                           
                        case SDLK_q:
                            if(Scene1::SceneBackground != "01" && Scene1::SceneBackground != "0"){
                                inv.gameSave(SceneBackground);
                            }

                            Scene1::SceneBackground = "0";
                                             
                        break;
                    }
                    break;          
                }                
        }

        keystate = SDL_GetKeyboardState(NULL);

        if (SDL_MOUSEBUTTONUP) {       
            mouseClick = true;
 
        }
        if (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_LEFT) && AI::aiStop !=1) {
            mouseHold++; //Important because it stops a memory leak.
            playerIsMoving = 0;
            playerMessage = false;
            interactionMessage = "";
                       
            //Prevents memory leak          
            SDL_DestroyTexture(Textures::spriteTexture);
            Textures::spriteTexture = nullptr;
            Textures::spriteTexture = SDL_CreateTextureFromSurface(renderer, Textures::spriteDown1); 
           

            SceneTransitionStatement = "";  //Clear the static clicked location (The location you sent your player to).
                  
            mob.useChecker(gd,gy); //Deals with wrong use actions. Pain to figure out!
            
            //The following 2 lines will allow you to use an object with another object.
            interactionMessage = pob.HoverObjects(x, y, scene, gd, gy);
            useStatement = interactionMessage;
         
            //This fixes the bug where if you decide to not to commit to picking something up.
            if (interactionMessage == "") {
                actionStatement = "";
            }
             
            Uint8 buttons = SDL_GetMouseState(&wx, &wy);
            gd = gdSprite.x;
            gy = gdSprite.y;
           

        

           

            //Show coordinates in console for object placement.
            cout << string(100, '\n');
            std::cout << "Mouse Click X Location = " << xp <<"%" << std::endl;
            std::cout << "Mouse Click Converted X position is: " << xpc << "" << std::endl;
            std::cout << "" << std::endl;
            std::cout << "Mouse Click Y Location = " << yp <<"%" <<  std::endl;
            std::cout << "Mouse Click Converted Y position is: " << ypc << "" << std::endl;
            std::cout << "" << std::endl;
            std::cout << "Current Player X Position is: " << gdSprite.x << std::endl;
            std::cout << "" << std::endl;
            std::cout << "Current Player Y Position is: " << gdSprite.y << std::endl;
            std::cout << "" << std::endl;
            std::cout << "Current Scene is: " << SceneBackground << std::endl;
            std::cout << "Mouse Click is: " << mouseHold << std::endl;
            std::cout << "" << std::endl;
            std::cout << "Secret Trigger is currently: " << secretTrigger << std::endl;
            std::cout << "" << std::endl;
            std::cout << "Current Sound Status: " << Sound::soundOn << std::endl;
            std::cout << "" << std::endl;
            std::cout << "Current Player Message is: " << PlayerInteraction::playerMessage << std::endl;
            

            std::cout << "Player Current X Position % is: " << moveX << endl;
            std::cout << "Player Current Y Position % is: " << moveY << endl;
        
            //Get interaction message.         
            interactionMessage = si.sceneTransitions(x, y, gd, gy);
           
            actionMessage = mob.MenuAction(x, y, gd, gy, mInteraction);
         

            //Do not remove this if statement or you will get memory leaks when holding down the mouse button.
            if(mouseClick == true && mouseHold <10 && AI::aiStop !=1){
                if (actionMessage != "" || actionStatement != "" ) {
                    pi.InteractionControllerObject(actionMessage, gameObject);                                   
                }

                if (interactionMessage != "" && AI::aiStop !=1) {
                    pi.InteractionControllerObject(interactionMessage, gameObject);
                   // playerIsMoving = 1;
                }

                //Used for clicking sounds in game.
                if (menuSound == 1 && mouseHold < 3) {
                    s.playClickSound();
                }

                mouseClick = false;
                mouseHold++;
             }
        }
   
        gd = gdSprite.x;
        gy = gdSprite.y;

        //These messages are displayed to help tell the story.
            gameMessage = pi.DisplayPlayerMessages();
      
        if (gameMessage != "") {
            interactionMessage = gameMessage;
            PlayerInteraction::playerMessage =1000; //Stops that memory leak!
        }

        if (interactionMessage != "" && sceneHalt == 1) {
            playerMessage = true;
            pi.InteractionControllerObject(interactionMessage, gameObject);
          
        }
        //Player interaction menu option messages.
        if (actionMessage != "Pick up what?") {     
            gameObject = mob.PickUp(x, y, gd, gy, mInteraction);
        }
        
        if (actionMessage != "Look at what?") {
            lookMessage = mob.Look(x, y, gd, gy, mInteraction);
        }
        if (actionMessage != "Use what?") {
            useMessage = mob.Use(x, y, gd, gy, mInteraction);
        }
        if (actionMessage != "Open what?") {
            openMessage = mob.Open(x, y, gd, gy, mInteraction);
        }
        if (actionMessage != "Pull what?") {
            openMessage = mob.Pull(x, y, gd, gy, mInteraction);
        }

        if (lookMessage != "" ) {  
            playerMessage = true;    
            pi.InteractionControllerObject(lookMessage, gameObject);                 
        }

        if (useMessage != "") {
            playerMessage = true;
            pi.InteractionControllerObject(useMessage, gameObject);
        }

        if (openMessage != "") {
            playerMessage = true;
            pi.InteractionControllerObject(openMessage, gameObject);
        }
        if (pullMessage != "") {
            playerMessage = true;
            pi.InteractionControllerObject(pullMessage, gameObject);
        }
       
 
        if (wx > gdSprite.x || wx < gdSprite.x) {
          
            if(action !=1 ){
                SDL_DestroyTexture(Textures::spriteTexture);
                Textures::spriteTexture = nullptr; //Prevents memory leak.
                Textures::spriteTexture = SDL_CreateTextureFromSurface(renderer, Textures::spriteDown1);
            }
            else{   
               
            }
           
            if (sceneHalt == 0 ) {
                playerMessage = false;
                gdSprite.x = player.walk(wx, wy, gd, gy, WIDTH, HEIGHT);
                //playerIsMoving = 1;
                SDL_Delay(1);
             
                if (wy < gdSprite.y || wy > gdSprite.y) {
                    
                    //The following 2 statements will allow the player to move across and then up or down.
                    if (y <= gdSprite.y && wx <= gdSprite.x + 75 && wx >= gdSprite.x){
                        gdSprite.y = player.walky(wx, wy, gd, gy, WIDTH, HEIGHT);
                        
                     
                    }
                  
                    
                    if (y >= gdSprite.y && wx <= gdSprite.x + 75 && wx >= gdSprite.x){
                     
                        gdSprite.y = player.walky(wx, wy, gd, gy, WIDTH, HEIGHT);
                        
                      
                    }  
                
                    SDL_Delay(1); 
                 
                }
            }
            else {
                //This code prevents the character from continuing to walk when changing scenes.
                    x = gdSprite.x;
                    y = gdSprite.y;
                    wx = gdSprite.x;
                    wy = gdSprite.y;

                    SDL_Delay(300);
                    sceneHalt = 0;
                    playerIsMoving = 0;
            }
            
            //This is where I am attempting to allow the player to walk directly to another scene after the user has chosen the destination. This is not perfect yet.
            if (gdSprite.x < gd || gdSprite.x > gd || gdSprite.y < gy || gdSprite.y >gy) {
                interactionMessage = si.sceneTransitions(x, y, gd, gy);
                s.playMovementSounds();
            }
         
       
    }

        ////////// RENDERING SECTION /////////
        
        //Render the window
        SDL_RenderClear(renderer);
       
        sr.sceneRender();  //Render the game scene backgrounds.
        moveXA = op.CalcObjectXAbsolutePosition(moveX, "PlayerLocationX");
        moveXY = op.CalcObjectYAbsolutePosition(moveY, "PlayerLocationY");
       
    
        //This needs to go here, don't move it!
        //Hide the player interaction menu on main menu screen.
        if(SceneBackground !="0")
            SDL_RenderCopy(renderer, Textures::menuTexture, NULL, &menu);   
 
        obr.objectRender(); //Render the game objects (Things that the player can pick up).

        //Set character size.
        gdSprite.w = SPRITE_SIZE;
        gdSprite.h = SPRITE_SIZE;
          
        if(PlayerInteraction::playerMessage > 3){
            //Render main character
            SDL_RenderCopy(renderer, Textures::spriteTexture, NULL, &gdSprite);
        }
        
        sr.sceneRenderOverlay(event.motion.x, event.motion.y); //Render objects in front of sprite.

        SDL_RenderCopy(renderer, Textures::ftexture, NULL, &textRect); //Renders the text that appears on the screen.
           
        interactionMessage = ""; // Clear the interaction message on every loop.
        gameMessage = "";
        useMessage = "";
        //Make something appear!    
        SDL_RenderPresent(renderer);
        mouseClick = false;    
 
        //Monitor for quit game
        if (quitGame == true) {
            if (Scene1::SceneBackground != "01" && Scene1::SceneBackground != "0") {
                inv.gameSave(SceneBackground);
            }

            Scene1::SceneBackground = "0";
            break;
        }


        auto current_time = std::chrono::high_resolution_clock::now();
        float delta_time = std::chrono::duration<float, std::chrono::milliseconds::period>(current_time - start_time).count();
        start_time = current_time;

   
        if (delta_time < 5.5000) {
            PlayerMovement::hspeed = 2.5;
   
        }
        else {
            PlayerMovement::hspeed = 7.0;
        }   
    }
        
    //Clean up after yourself!
    SDL_DestroyRenderer(renderer); //Destroy Renderer should destroy ALL textures.
    SDL_DestroyWindow(window);
    TTF_CloseFont(font);
    s.freeMusic();
 
    //Close down game.
    return 0;

    TTF_Quit();
    SDL_Quit();
}
