
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

int Scene1::xPosition;
int Scene1::yPosition;
int Scene1::SPRITE_SIZE;

int Scene1::action; //Used to trigger action texture.
int Scene1::sceneHalt = 0;  //sceneHalt is useful for displaying player messages and scene transitions. 
bool playerMessage = false;  //Used to keep the player text on the screen long enough that you can actually read it!
bool Scene1::mouseClick = false;

SDL_Rect Scene1::gdSprite;
SDL_Renderer* Scene1::renderer;

int Scene1::tLoader = 0;  //Used to prevent the same textures being loaded in twice. Needs looking at.


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
    
  //  SPRITE_SIZE = 170;
   // xPosition = 10;
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

    window = SDL_CreateWindow("The Planet and Bonita", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI);
    windowSurface =  SDL_GetWindowSurface(window);
    renderer =       SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED || SDL_RENDERER_PRESENTVSYNC); //|| SDL_RENDERER_PRESENTVSYNC
       //             SDL_SetWindowFullscreen(window, SDL_TRUE);  //Stretch the screen.
    font =           TTF_OpenFont("arial.ttf", 25);
    fcolor =         { 255, 255, 255 }; //Font colour.
    bcolor =         { 0,0,0 }; //Font background colour.
  
    //Assign the images to the textures.
    ftexture = SDL_CreateTextureFromSurface(renderer, fsurface);
    dialogmTexture = SDL_CreateTextureFromSurface(renderer, fsurface);

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
   // tex.Scene2Textures();
    //tex.Scene3Textures();
 
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
            
                        if (playerMessage != true && interactionMessage == "") {
                            SDL_DestroyTexture(ftexture);                  
                            interactionMessage = pob.HoverObjects(x, y, scene, gd, gy);
                        }
                        if (interactionMessage != "") {
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
            SceneTransitionStatement = "";  //Clear the static clicked location (The location you sent your player to).
 
            //The following 2 lines will allow you to use an object with another object.
            interactionMessage = pob.HoverObjects(x, y, scene, gd, gy);
            useStatement = interactionMessage;

            //This fixes the bug where if you decide to not to commit to picking something up.
            if (interactionMessage == "") {
                actionStatement = "";
               
            }
           //Free up memory for dialog texture and sprite texture. Prevents memory leak!   TRUST ME!
           //Note needs some tweaking. If you remove this your RAM will rocket!                                 
            SDL_DestroyTexture(ftexture); //VERY VERRRRY IMPORTANT (DON'T REMOVE)
           // fsurface = TTF_RenderText_Solid(font, "", fcolor);  //Dont think I need this.
            SDL_DestroyTexture(Textures::spriteTexture);
            Textures::spriteTexture = SDL_CreateTextureFromSurface(renderer, Textures::spriteDown1); 
           
                      
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
         
                _sleep(1);

                if (wy < gdSprite.y || wy > gdSprite.y) {
                   
                    //The following 2 statements will prevent the player from traversing diaginally which just looks..well..wrong. Took ages to get this right!
                    if (y < gdSprite.y && wx < gdSprite.x + 75 && wx >gdSprite.x)
                        gdSprite.y = player.walky(wx, wy, gd, gy, WIDTH, HEIGHT, Textures::spriteTexture, ftexture, dialogmTexture);

                    if (y > gdSprite.y && wx < gdSprite.x + 75 && wx > gdSprite.x)
                        gdSprite.y = player.walky(wx, wy, gd, gy, WIDTH, HEIGHT, Textures::spriteTexture, ftexture, dialogmTexture);

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
               
    }

        //RENDERING SECTION. THIS IS WHERE THE GRAPHICS ARE RENDERED IN THE GAME LOOP. I TRIED MOVING THIS TO ANOTHER CLASS BUT ALL SORTS OF THINGS WENT WRONG.
        //Render the window
        SDL_RenderClear(renderer);
        
        //Which scene to be displayed.
        if(SceneBackground == "1"){
            SDL_RenderCopy(renderer, Textures::texture, NULL, &background);
        }
       
        if (SceneBackground == "1b") { 
            SDL_RenderCopy(renderer, Textures::wreakageScene, NULL, &background);
                   
        }

        if (SceneBackground == "1e") {          
            SDL_RenderCopy(renderer, Textures::scene1e, NULL, &background); 
        }

        if (SceneBackground == "1f" ) {
            SDL_RenderCopy(renderer, Textures::scene1f, NULL, &background);
        }

        if (SceneBackground == "1fb") {
            SDL_RenderCopy(renderer, Textures::scene1fb, NULL, &background);
        }

        if (SceneBackground == "1da") {
            SDL_RenderCopy(renderer, Textures::scene1d, NULL, &background);
        }

        if (SceneBackground == "1db") {
            SDL_RenderCopy(renderer, Textures::scene1d2, NULL, &background);
        }

        if (SceneBackground == "3a") {
            SDL_RenderCopy(renderer, Textures::scene3a, NULL, &background);
        }
        if (SceneBackground == "3b") {
            SDL_RenderCopy(renderer, Textures::scene3b, NULL, &background);
        }

        //This needs to go here, don't move it!
        SDL_RenderCopy(renderer, Textures::menuTexture, NULL, &menu);   
 
        //Display Scene Objects if not destroyed (picked up).     
    
        //PDA Inventory item.
        if (objectToDestroy.find("1") != std::string::npos) {
            SDL_RenderCopy(renderer, Textures::invTexture1, NULL, &Inventory::inv1);        
        }
    
        else if(SceneBackground == "1") {SDL_RenderCopy(renderer, Textures::objectTexture, &PlayerObjects::srcrect, &PlayerObjects::dstrect);}        
     
        //Flag Inventory Item
        if (objectToDestroy.find("2") != std::string::npos ) {    
            SDL_RenderCopy(renderer, Textures::invTexture2, NULL, &Inventory::inv2);
        }
        else if (SceneBackground == "1b") { 
            SDL_RenderCopy(renderer, Textures::objectTexture2, &PlayerObjects::srcrect2, &PlayerObjects::dstrect2);
        }
       
        //Ape Tape Inventory Item.
        if (objectToDestroy.find("3") != std::string::npos) {
            if (Inventory::inv3Used == 0) {             
                    SDL_RenderCopy(renderer, Textures::invTexture3, NULL, &Inventory::inv3);
            }
        }
        else if (SceneBackground == "1b") {    
            SDL_RenderCopy(renderer, Textures::objectTexture4, &PlayerObjects::srcrect4, &PlayerObjects::dstrect4);
        }
        
        //Tent
        if (objectToDestroy.find("4") != std::string::npos) {
            if (Inventory::inv4Used == 0) {
                //This makes sure the inventory item is removed if the player has used the tent.
                SDL_RenderCopy(renderer, Textures::invTexture4, NULL, &Inventory::inv4);
            }
        }
        else if (SceneBackground == "1b") {
            SDL_RenderCopy(renderer, Textures::objectTexture5, &PlayerObjects::srcrect5, &PlayerObjects::dstrect5);
        }

        //Pipe      
        if (objectToDestroy.find("5") != std::string::npos) {
           if(Inventory::inv5Used == 0){
            SDL_RenderCopy(renderer, Textures::invTexture3, NULL, &Inventory::inv3);
           }        
        }

        //Lantern    
        if (objectToDestroy.find("6") != std::string::npos) {
            if (Inventory::inv7Used == 0) {
                SDL_RenderCopy(renderer, Textures::invTexture6, NULL, &Inventory::inv7);
            }
        }
        else if(SceneBackground == "1da" || SceneBackground == "1db") {
            SDL_RenderCopy(renderer, Textures::objectTextureLantern, &PlayerObjects::srcrect8, &PlayerObjects::dstrect8);
        }
        
        //Air Pressure Unit
        if (SceneBackground == "1da" || SceneBackground == "1db") {
            SDL_RenderCopy(renderer, Textures::objectTextureAirBox, &PlayerObjects::srcrect7, &PlayerObjects::dstrect7);
         
        }

        //Set character size.
        gdSprite.w = SPRITE_SIZE;
        gdSprite.h = SPRITE_SIZE;
          
        if(PlayerInteraction::playerMessage > 3){
            //Render main character
            SDL_RenderCopy(renderer, Textures::spriteTexture, NULL, &gdSprite);
        }
        else {
            //THIS WAS A CUTSCENE BUT CURRENTLY NOT IN USE.
            SDL_DestroyTexture(Textures::spriteTexture);
           // Textures::spriteTexture = SDL_CreateTextureFromSurface(renderer, spriteFlat);
            SDL_RenderCopy(renderer, Textures::spriteTexture, NULL, &gdSprite);
        }
    
        //FOREGROUND OBJECTS (SPRITE BEHIND THEM)
        //This will hide the sprite because it comes after the render of the sprite. For example rocks in the foreground where the sprite passes behind them.
        if (SceneBackground == "1") {
            SDL_RenderCopy(renderer, Textures::starsTexture, &PlayerObjects::srcrect3, &PlayerObjects::dstrect3);
            SDL_RenderCopy(renderer, Textures::rocks, NULL, &background2);
        }
       

        if (SceneBackground == "1c") {
           
            SDL_RenderCopy(renderer, Textures::computerScene1, NULL, &background);
        }
  
        if (SceneBackground == "1d") {
          
            SDL_RenderCopy(renderer, Textures::computerScene2, NULL, &background);
        }

        if (SceneBackground == "1e") {
           
            SDL_RenderCopy(renderer, Textures::rocks2, NULL, &background3);
        }

        //Cut Scene (Hide sprite)
        if (SceneBackground == "1fa") {
            SDL_RenderCopy(renderer, Textures::scene1fa, NULL, &background);                   
        }
        //Cardboard Box (In front of sprite)
        if (SceneBackground == "1da" || SceneBackground== "1db") {        
            SDL_RenderCopy(renderer, Textures::objectTexture6, &PlayerObjects::srcrect6, &PlayerObjects::dstrect6);
          
        }
        
        SDL_RenderCopy(renderer, ftexture, NULL, &textRect);
        SDL_RenderCopy(renderer, dialogmTexture, NULL, &menuTextRect);

       
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
