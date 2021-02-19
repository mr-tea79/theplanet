
/* Adventure Game Creator Engine by Damian Baldry @ Brightland. Written in 2020
   Very much a work in progress!
   V2.01

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
std::string Scene1::SceneBackground = "1";
std::string gameMessage; //Used to display messages that tell the story.
std::string Scene1::objectToDestroy;

SDL_Window* Scene1::window;
SDL_Rect Scene1::textRect;
TTF_Font* Scene1::font;
SDL_Surface* Scene1::fsurface;
SDL_Color Scene1::fcolor;
SDL_Texture* Scene1::ftexture = NULL;
SDL_Rect Scene1::dTexture;

//int Scene1::mouseHold = 0;
//Used to prevent hover from removing the message on the screen too quickly. This was a real brain teaser to figure out.
//int Scene1::messageHolder = 0;
int Scene1::xPosition;
int Scene1::yPosition;
int Scene1::SPRITE_SIZE;

//Global inventory used variables. This prevents constant database checking which slows the game down.
int Scene1::inv3Used;  //Duct Tape.
int Scene1::inv4Used;  //Tent
int Scene1::inv5Used; //Pipe
int Scene1::inv6Used; //Pressure Suit
int Scene1::inv7Used; //Lantern

int Scene1::action; //Used to trigger action texture.
int Scene1::sceneHalt = 0;
bool playerMessage = false;  //Used to keep the player text on the screen long enough that you can actually read it!

SDL_Rect Scene1::gdSprite;
SDL_Renderer* Scene1::renderer;

int Scene1::tLoader = 0;  //Used to prevent the same textures being loaded in twice.

int Scene1::scene1() {

    cout << "Initialize" << endl;
    scene = 1; //Scene Number.
        
    //Set initial position of game character and the size of the character.
    xPosition = 10;
    yPosition = 430;

    //Use this to jump to a scene. Comment the 4 lines below out and uncomment the SPRITE_SIZE =120 to return to normal.
    SceneBackground = "1";
    
    //SPRITE_SIZE = 10;
   // xPosition = 10;
   // yPosition = 300;

    //THIS IS THE DEFAULT SCENE
    //Normal Size (Uncomment)
     SPRITE_SIZE = 120;

    
    //Static variables that are updated while the program is running.
    static int position;
    static int mInteraction;


    //Used to check which objects are currently picked up by the user.
 
    static std::string gameObject;
    static std::string lastMessage;
    
    //Strings used for message handing. Contain returned values from the game loop.
    std::string interactionMessage;
    std::string useMessage;
    std::string openMessage;
    std::string lookMessage;
    std::string actionMessage;

    //Used to detecting mouse clicks. The program runs really fast!
    //static int mouseHold = 0;
    
    //Allow usage of .png images.
    int imgFlags = IMG_INIT_PNG;

    //Player location variables.
    int gd;
    int gy;
    int x =0, y = 0;
    int wx=0,wy=0;
      

    //Text Dialog.
    dialog =         NULL;
    fsurface =       NULL;
    
    //Image RECTS are used to hold in game images and are set to a given position (x,y,height,width).
    //Inventory RECTS
    inv1 = { 700, 650, 40, 40 };
    inv2 = { 760, 610, 60, 60 };
    inv3 = { 880, 650, 40, 40 };
    inv4 = { 760, 700, 60, 60 };
    inv7 = { 760, 700, 60, 60 };
    
    //Main background Rect
    background = { 0, 0, 1024, 600 };

    //Background overlay Rects (Rocks in foreground etc)
    background2 = { 0, 200, 1500, 400 };
    background3 = { 0, 310, 1100, 300 };

    //Interaction Menu Rect
    menu = { 0, 600, 1024, 568 };
    //windowRect = { 921 ,460,78,100 };

    SDL_Surface* SDL_DisplayFormat(SDL_Surface * surface);

    SDL_Init(SDL_INIT_EVERYTHING);
    TTF_Init();

    window = SDL_CreateWindow("The Planet and Bonita", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI);
    windowSurface =  SDL_GetWindowSurface(window);
    renderer =       SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED || SDL_RENDERER_PRESENTVSYNC); //|| SDL_RENDERER_PRESENTVSYNC
                  //  SDL_SetWindowFullscreen(window, SDL_TRUE);  //Stretch the screen.
    font =           TTF_OpenFont("arial.ttf", 25);
    fcolor =         { 255, 255, 255 };

    dialogTexture =  SDL_CreateTextureFromSurface(renderer, dialog);

    //Assign the images to the textures.
    ftexture = SDL_CreateTextureFromSurface(renderer, fsurface);
    dialogmTexture = SDL_CreateTextureFromSurface(renderer, fsurface);

    //Something to do with the font texture.
    SDL_QueryTexture(ftexture, NULL, NULL, &texW, &texH);
     
    //Free up the RGB surface.
    SDL_FreeSurface(dialog);
 
    //Place the player sprite in the chosen location.
    gdSprite.x = xPosition;
    gdSprite.y = yPosition;

    //Initialize Textures
    Textures tex;
    tex.Scene1Textures();
   // tex.Scene2Textures();
  //  tex.Scene3Textures();
 
    //Purge the Inventory for a new game. SAVE GAME feature will be added at the end of the project.
    Inventory inv;
    inv.purgeDatabase();

    //Load the action textures.
    MenuInteraction mob;
    mob.LoadActionTextures();

    //Load player movement class.
    PlayerMovement player;
    player.LoadMovementTextures();

    //Load player movement class.
    PlayerObjects pob;

    //Load player message class.
    PlayerInteraction pi;
  
    //Game loop.
    while (!gameover)
    {        
        //Place player objects in the game.0o
        pob.PlaceObjects();

        //Show patch on suit
        if (inv3Used == 1) {
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
                   // if (event.motion.x > x + 50 || event.motion.x < x - 50 || event.motion.y > y+50 || event.motion.y < y-50 ) {
                     //   if (messageHolder != 1 ) {
                           
                        //Event Motion coordinates. Where the mouse moves on the screen.
                        x = event.motion.x;
                        y = event.motion.y;
                        gd = gdSprite.x;
                        gy = gdSprite.y;

                        if(playerMessage != true && interactionMessage ==""){
                            interactionMessage = pob.HoverObjects(x, y, scene, gd, gy);
                   

                        if (interactionMessage != "") {

                            pi.InteractionControllerHover(interactionMessage);

                        }

                        //Find objects that are hoverable.
                        if (event.motion.x > x + 150 && event.motion.x < x - 150 && event.motion.y > y + 150 && event.motion.y < y - 150) { //Here I am trying to keep the text on the screen
                    
                            SDL_DestroyTexture(ftexture);
                       
                        }
                        else {
                            
                               
                        }
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
           
            //std::cout << "Mouse button up" << std::endl;
        }
        if (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_LEFT)) {
           //Free up memory for dialog texture and sprite texture. Prevents memory leak!   TRUST ME!
           //Note needs some tweaking. If you remove this your RAM will rocket!  
                     
            SDL_DestroyTexture(Textures::spriteTexture);
            SDL_DestroyTexture(ftexture); //VERY VERRRRY IMPORTANT (DON'T REMOVE)
            Textures::spriteTexture = SDL_CreateTextureFromSurface(renderer, Textures::spriteDown1); 
            fsurface = TTF_RenderText_Solid(font, "", fcolor);
                      
            Uint8 buttons = SDL_GetMouseState(&wx, &wy);
            gd = gdSprite.x;
            gy = gdSprite.y;

            //Show coordinates in console for object placement.
            cout << "Current Mouse click coordinates are:"  << endl;
            cout << "x = " << x << endl;
            cout << "y = " << y << endl;
            cout << "Current Player X Position is: " << gdSprite.x << endl;
            cout << "Current Player Y Position is: " << gdSprite.y << endl;
            cout << "Current Scene is: " << SceneBackground << endl;
        
           
        
            //Get interaction message.         
            interactionMessage = pob.ObjectInteraction( x, y, gd, gy);

           
            std::string menuMessage;
            //Clicking objects on the scene.
      
            
                                    
           // useMessage = mob.Use(x, y, gd, gy, mInteraction, Textures::spriteTexture, renderer, Textures::spriteDown1, ""); 
                    
            openMessage = mob.Open(x, y, gd, gy, mInteraction, Textures::spriteTexture, renderer, Textures::spriteDown1, "");

            actionMessage = mob.MenuAction(x, y, gd, gy, mInteraction, Textures::spriteTexture, renderer, Textures::spriteDown1, "");

          //  lookMessage = mob.Look(x, y, gd, gy, mInteraction, Textures::spriteTexture, renderer, Textures::spriteDown1, "");
        
            //These messages are displayed to help tell the story.
            gameMessage = pi.DisplayPlayerMessages();

            if (gameMessage != "") {
               
                interactionMessage = gameMessage;
                PlayerInteraction::playerMessage = 100;                  
            }     
            
           
           
        
         
            else if (openMessage != "") {                       
                pi.InteractionControllerUse(openMessage, gameObject);
            }
            
           else if (actionMessage != "" || actionStatement != "") {            
               pi.InteractionControllerLook(actionMessage, gameObject);
           }
           else if (interactionMessage != "") {
               playerMessage = true;
               pi.InteractionControllerObject(interactionMessage, gameObject);
           }

           else         
             SDL_DestroyTexture(ftexture); //VERY VERRRRY IMPORTANT (DON'T REMOVE)
          
        }
   
        gd = gdSprite.x;
        gy = gdSprite.y;

        if (actionMessage != "Pick up what?") {
            //Get object pickup message.
            gameObject = mob.PickUp(x, y, gd, gy, mInteraction, Textures::spriteTexture, renderer, Textures::spritePick, "");
        }
        if (actionMessage != "Look at what?") {
            lookMessage = mob.Look(x, y, gd, gy, mInteraction, Textures::spriteTexture, renderer, Textures::spriteDown1, Textures::spriteBack1a, "");
            
        }
        if (actionMessage != "Use what?") {
            useMessage = mob.Use(x, y, gd, gy, mInteraction, Textures::spriteTexture, renderer, Textures::spriteDown1, "");
        }


        if (lookMessage != "") {  
            playerMessage = true;
            pi.InteractionControllerLook(lookMessage, gameObject);
           // actionStatement = "";   
          
        }

        if (useMessage != "") {
            pi.InteractionControllerUse(useMessage, gameObject);
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

                    //The following 2 statements will prevent the player from traversing diaginally which causes animation issues. Took ages to get this right!
                    if (y < gdSprite.y && wx < gdSprite.x + 75 && wx >gdSprite.x)
                        gdSprite.y = player.walky(wx, wy, gd, gy, WIDTH, HEIGHT, Textures::spriteTexture, ftexture, dialogmTexture);

                    if (y > gdSprite.y && wx < gdSprite.x + 75 && wx > gdSprite.x)
                        gdSprite.y = player.walky(wx, wy, gd, gy, WIDTH, HEIGHT, Textures::spriteTexture, ftexture, dialogmTexture);

                    _sleep(1);  //This makes the animation of the character look a bit more realistic and less like she's on skates.
                }
            }
            else {
                //This code keeps the character from continuing to walk when changing scenes.
                    x = gdSprite.x;
                    y = gdSprite.y;
                    wx = gdSprite.x;
                    wy = gdSprite.y;
                    _sleep(300);
                    sceneHalt = 0;

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
            SDL_RenderCopy(renderer, Textures::invTexture1, NULL, &inv1);        
        }
    
        else if(SceneBackground == "1") {SDL_RenderCopy(renderer, Textures::objectTexture, &PlayerObjects::srcrect, &PlayerObjects::dstrect);}        
     
        //Flag Inventory Item
        if (objectToDestroy.find("2") != std::string::npos ) {    
            SDL_RenderCopy(renderer, Textures::invTexture2, NULL, &inv2); 
        }
        else if (SceneBackground == "1b") { 
            SDL_RenderCopy(renderer, Textures::objectTexture2, &PlayerObjects::srcrect2, &PlayerObjects::dstrect2);
        }
       
        //Ape Tape Inventory Item.
        if (objectToDestroy.find("3") != std::string::npos) {
            if (inv3Used == 0) {             
                    SDL_RenderCopy(renderer, Textures::invTexture3, NULL, &inv3);                         
            }
        }
        else if (SceneBackground == "1b") {    
            SDL_RenderCopy(renderer, Textures::objectTexture4, &PlayerObjects::srcrect4, &PlayerObjects::dstrect4);
        }
        
        //Tent
        if (objectToDestroy.find("4") != std::string::npos) {
            if (inv4Used == 0) {
                //This makes sure the inventory item is removed if the player has used the tent.
                SDL_RenderCopy(renderer, Textures::invTexture4, NULL, &inv4);
            }
        }
        else if (SceneBackground == "1b") {
            SDL_RenderCopy(renderer, Textures::objectTexture5, &PlayerObjects::srcrect5, &PlayerObjects::dstrect5);
        }

        //Pipe      
        if (objectToDestroy.find("5") != std::string::npos) {
           if(inv5Used == 0){
            SDL_RenderCopy(renderer, Textures::invTexture3, NULL, &inv3);                        
           }        
        }

        //Lantern    
        if (objectToDestroy.find("6") != std::string::npos) {
            if (inv7Used == 0) {
                SDL_RenderCopy(renderer, Textures::invTexture6, NULL, &inv7);
            }
        }
        else if(SceneBackground == "1da" || SceneBackground == "1db") {
            SDL_RenderCopy(renderer, Textures::objectTextureLantern, &PlayerObjects::srcrect8, &PlayerObjects::dstrect8);
        }
        
        //Air Pressure Unit
        if (SceneBackground == "1da" || SceneBackground == "1db") {
            SDL_RenderCopy(renderer, Textures::objectTextureAirBox, &PlayerObjects::srcrect7, &PlayerObjects::dstrect7);
         
        }

        //Display Character
        gdSprite.w = SPRITE_SIZE;
        gdSprite.h = SPRITE_SIZE;
          
        if(PlayerInteraction::playerMessage > 3){
            SDL_RenderCopy(renderer, Textures::spriteTexture, NULL, &gdSprite);
        }
        else {
            SDL_DestroyTexture(Textures::spriteTexture);
           // Textures::spriteTexture = SDL_CreateTextureFromSurface(renderer, spriteFlat);
            SDL_RenderCopy(renderer, Textures::spriteTexture, NULL, &gdSprite);
        }
    
        //Display Objects and textures for the current scene background.
        if (SceneBackground == "1") {
            SDL_RenderCopy(renderer, Textures::sceneTexture, &PlayerObjects::srcrect3, &PlayerObjects::dstrect3);
            SDL_RenderCopy(renderer, Textures::rocks, NULL, &background2);
        }

        if (SceneBackground == "1b") {
             
        }
        //This will hide the sprite because it comes after the render of the sprite.
        if (SceneBackground == "1c") {
           
            SDL_RenderCopy(renderer, Textures::computerScene1, NULL, &background);
        }
        //This will hide the sprite because it comes after the render of the sprite.
        if (SceneBackground == "1d") {
          
            SDL_RenderCopy(renderer, Textures::computerScene2, NULL, &background);
        }

        if (SceneBackground == "1e") {
           
            SDL_RenderCopy(renderer, Textures::rocks2, NULL, &background3);
        }

        //This will hide the sprite because it comes after the render of the sprite.
        if (SceneBackground == "1fa") {
            SDL_RenderCopy(renderer, Textures::scene1fa, NULL, &background);                   
        }

        if (SceneBackground == "1da" || SceneBackground== "1db") {        
            SDL_RenderCopy(renderer, Textures::objectTexture6, &PlayerObjects::srcrect6, &PlayerObjects::dstrect6);
          
        }
        
        SDL_RenderCopy(renderer, ftexture, NULL, &textRect);
        SDL_RenderCopy(renderer, dialogmTexture, NULL, &menuTextRect);

        //Ensures text is always on the top.
        if (interactionMessage != "" || gameObject != "")
            SDL_RenderCopy(renderer, ftexture, NULL, &textRect);
       

        interactionMessage = ""; // Clear the interaction message on every loop.
        useMessage = "";
        gameMessage = "";
             
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

void Scene1::renderSprite() {
    
    SDL_RenderCopy(renderer, Textures::spriteTexture, NULL, &gdSprite);

}

//Does the action animations.
void Scene1::DoAction() {
    _sleep(300);
    action = 0;
   // sceneHalt = 0;
}
