
/* Adventure Game Creator Engine by Damian Baldry @ Brightland. Written in 2020
   Very much a work in progress!
   V1.0

*/

#include "Scene1.h"
#include <iostream>
#include <algorithm>
#include "PlayerMovement.h"
#include "PlayerObjects.h"
#include "PlayerInteraction.h"
#include "MenuInteraction.h"
#include "Inventory.h"
#include <tuple>
#include <chrono>
#include "Textures.h"

using namespace std;
using namespace brightland;

//Initialize the global use statement variable accessed by menu Interaction class.
std::string Scene1::useStatement = "";
std::string Scene1::SceneBackground = "1";
int Scene1::xPosition;
int Scene1::yPosition;
int Scene1::SPRITE_SIZE;

//Used for ingame player messages.
int Scene1::playerMessage = 1;
static int mouseHold = 0;

//Global inventory used variables. This prevents constant database checking which slows the game down.
int Scene1::inv3Used;  //Duct Tape.
int Scene1::inv4Used;  //Tent
int Scene1::inv5Used; //Pipe

SDL_Rect Scene1::gdSprite;
SDL_Texture* Scene1::objectTexture;
SDL_Texture* Scene1::objectTexture2;
SDL_Texture* Scene1::objectTexture3;
SDL_Texture* Scene1::objectTexture4;
SDL_Texture* Scene1::objectTexture5;
SDL_Texture* Scene1::objectTexture6;
SDL_Texture* Scene1::objectTexture7;
SDL_Texture* Scene1::objectTextureAirBox;
SDL_Texture* Scene1::objectTexturePipe;

SDL_Renderer* Scene1::renderer;

static int tLoader = 0;  //Used to prevent the same textures being loaded in twice.


int Scene1::scene1() {

    cout << "Initialize" << endl;
    scene = 1;
    //Scene Number.
    

    //Set initial position of game character and the size of the character.
    xPosition = 10;
    yPosition = 430;

    //Use this to jump to a scene. Comment the 4 lines below out and uncomment the SPRITE_SIZE =120 to return to normal.
    SceneBackground = "1da";
    
    SPRITE_SIZE = 180;
   // xPosition = 10;
   // yPosition = 300;

    //THIS IS THE DEFAULT SCENE
    //Normal Size (Uncomment)
  //  SPRITE_SIZE = 120;

    
    //Static variables that are updated while the program is running.
    static int position;
    static int mInteraction;

    //Used to check which objects are currently picked up by the user.
    static std::string objectToDestroy;  
    static std::string gameObject;
    
    //Strings used for message handing. Contain returned values from the game loop.
    std::string interactionMessage;
    std::string useMessage;
    std::string openMessage;

    //Used to prevent hover from removing the message on the screen too quickly. This was a real brain teaser to figure out.
    int messageHolder = 0;
  
    //Used to detecting mouse clicks. The program runs really fast!
    static int mouseHold = 0;
    
    //Allow usage of .png images.
    int imgFlags = IMG_INIT_PNG;

    //Player location variables.
    int gd;
    int gy;
    int x =0, y = 0;

  
    //Text Dialog.
    dialog =         NULL;
    fsurface =       NULL;
  

     
    //Image RECTS are used to hold in game images and are set to a given position (x,y,height,width).
    //Inventory RECTS
    inv1 = { 700, 650, 40, 40 };
    inv2 = { 760, 610, 60, 60 };
    inv3 = { 880, 650, 40, 40 };
    inv4 = { 760, 700, 60, 60 };
    

    //Main background Rect
    background = { 0, 0, 1024, 600 };

    //Background overlay Rect (Rocks in foreground etc)
    background2 = { 0, 200, 1500, 400 };

    background3 = { 0, 310, 1100, 300 };


    menu = { 0, 600, 1024, 568 };
    windowRect = { 921 ,460,78,100 };

    SDL_Surface* SDL_DisplayFormat(SDL_Surface * surface);

    SDL_Init(SDL_INIT_EVERYTHING);
    TTF_Init();

    window =         SDL_CreateWindow("The Planet and Bonita", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI);
    windowSurface =  SDL_GetWindowSurface(window);
    renderer =       SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED || SDL_RENDERER_PRESENTVSYNC); //|| SDL_RENDERER_PRESENTVSYNC
       //              SDL_SetWindowFullscreen(window, SDL_TRUE);  //Stretch the screen.
    font =           TTF_OpenFont("arial.ttf", 25);
    fcolor =         { 255, 255, 255 };


    menuSurface =    IMG_Load("menu.png");
  
    spriteFlat =     IMG_Load("PlayerMovement/ThePlanet/spriteFlat.png");
    spriteDown1 =    IMG_Load("PlayerMovement/ThePlanet/sprite.png");
    spriteDownp =    IMG_Load("PlayerMovement/ThePlanet/spritep.png"); 
  
    menuTexture =    SDL_CreateTextureFromSurface(renderer, menuSurface);
    spriteTexture =  SDL_CreateTextureFromSurface(renderer, spriteDown1);
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
  
    dTexture.x = 10;
    dTexture.y = 300;
    dTexture.w = 300;
    dTexture.h = 200; 


    Textures tex;
    tex.Scene1Textures();
   tex.Scene2Textures();
 
    //Purge the Inventory for a new game.
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
        
        //Place player objects in the game.
        pob.PlaceObjects();


        if (inv3Used == 1)
            spriteDown1 = spriteDownp;

        //Set this to 1 to show the player messages. 5 will skip them.
        playerMessage = 7;
       

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
                    if (event.motion.y < HEIGHT && event.motion.y > 0 && messageHolder != 1 || event.motion.y < 704 && event.motion.x > x + 50 || event.motion.x < x - 50 )  /* && event.motion.x > gdSprite.x + 400 || event.motion.x < gdSprite.x - 400*/ {
                      
                        if(playerMessage > 2){
                        //Reset MessageHolder after the message has been hidden. This prevents messages from disappearing too quickly.
                        messageHolder = 0;

                     
                        //Event Motion coordinates. Where the mouse moves on the screen.
                        x = event.motion.x;
                        y = event.motion.y;
                        gd = gdSprite.x;
                        gy = gdSprite.y;
                        //Find objects that are hoverable.
                       
                        interactionMessage = pob.HoverObjects(x, y, scene, gd, gy);
                       

                                                                
                        if (interactionMessage != "" ) {
                       
                            int interactionMessagelength = interactionMessage.length();
                            const char* im = interactionMessage.c_str();        
                                                  
                            textRect = { 500, 610, interactionMessagelength * 10, 20 };   // The * 10, 20 is a mathematical way of setting the text width depending on the length of the text.
                            fsurface = TTF_RenderText_Solid(font, im, fcolor);
                            ftexture = SDL_CreateTextureFromSurface(renderer, fsurface);
                            _sleep(100); // pauses briefly to allow text to show.
                                                                                                      
                        }

                    else {  
                            SDL_DestroyTexture(ftexture);
                    }

            }
            
                    break;
        }
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
            mouseHold = 0;
            //std::cout << "Mouse button up" << std::endl;
        }
        if (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_LEFT)) {
           
                     
            //This will show the scene intro. To skip the scene intro, comment this out.
           // playerMessage = 5;

            //Free up memory for dialog texture and sprite texture. Prevents memory leak!   TRUST ME!
           //Note needs some tweaking. If you remove this your RAM will rocket!                 
  
            SDL_DestroyTexture(spriteTexture);
            SDL_DestroyTexture(ftexture);
            spriteTexture = SDL_CreateTextureFromSurface(renderer, spriteDown1);
       
            fsurface = TTF_RenderText_Solid(font, "", fcolor);
         
            messageHolder = 0;
                         
            Uint8 buttons = SDL_GetMouseState(&x, &y);
            gd = gdSprite.x;
            gy = gdSprite.y;

            //Show coordinates in console for object placement.
            cout << "Current Mouse click coordinates are:" << endl;
            cout << "x = " << x << endl;
            cout << "y = " << y << endl;
            cout << "Current Player X Position is: " << gdSprite.x << endl;
            cout << "Current Player Y Position is: " << gdSprite.y << endl;
        

            if(mouseHold == 0){
                mouseHold = 1;
                ftexture = SDL_CreateTextureFromSurface(renderer, fsurface);
            //This will kick in when any story intro messages have been shown.
            gdSprite.x = player.walk(x, y, gd, gy, WIDTH, HEIGHT, spriteTexture, ftexture, dialogmTexture);
              
          
            //The following 2 statements will prevent the player from traversing diaginally which causes animation issues. Took ages to get this right!
            if(y < gdSprite.y && x < gdSprite.x +75 && x >gdSprite.x)
                gdSprite.y = player.walky(x, y, gd, gy, WIDTH, HEIGHT, spriteTexture,ftexture, dialogmTexture);
            
            if (y > gdSprite.y && x < gdSprite.x +75 && x > gdSprite.x)
                gdSprite.y = player.walky(x, y, gd, gy, WIDTH, HEIGHT, spriteTexture,ftexture, dialogmTexture);
         
            }
           
            //Get interaction message.
           
            interactionMessage = pob.ObjectInteraction( x, y, gd, gy);
            if (interactionMessage != "") {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(renderer, spriteDown1);
            }

            std::string menuMessage;
            //Clicking objects on the scene.
      
            //Get object pickup message.
            gameObject = mob.PickUp(x, y, gd, gy, mInteraction, spriteTexture, renderer, spriteDown1, "");
            if (gameObject != "") {
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(renderer, spriteDown1);
               
            }
            //Get object use message.
            useMessage = mob.Use(x, y, gd, gy, mInteraction, spriteTexture, renderer, spriteDown1, "");
            openMessage = mob.Open(x, y, gd, gy, mInteraction, spriteTexture, renderer, spriteDown1, "");
    
            //Get object use message.
         //   useMessage = mob.MenuSelect(x, y, gd, gy, mInteraction, spriteTexture, renderer, spriteDown1, "", interactionMessage);
                    
            //Get object Pull message.
         //   useMessage = mob.Pull(scene, x, y, gd, gy, mInteraction, spriteTexture, renderer, spriteDown1, "");

            //Check which objects are picked up.
            if (gameObject != "") {
             
                std::string object;
                object = pob.DestroyObjects(gameObject);
                objectToDestroy.append(object);
                std::cout << objectToDestroy << std::endl;
                //Added the following lines to try and prevent the sprite from disappearing sometimes.
                SDL_DestroyTexture(spriteTexture);
                spriteTexture = SDL_CreateTextureFromSurface(renderer, spriteDown1); 
            }
                                
        
            //Handles all object interaction messages on the game window.          
             if (interactionMessage != "" || useMessage !="" || openMessage !="") {
                 const char* im = interactionMessage.c_str();
                 const char* imu;
                 int useMessageLength;
                 SDL_DestroyTexture(spriteTexture);
                 spriteTexture = SDL_CreateTextureFromSurface(renderer, spriteDown1);
             //    SDL_RenderCopy(renderer, spriteTexture, NULL, &gdSprite);                
                int interactionMessagelength = interactionMessage.length();
                if (useMessage != "") {useMessageLength = useMessage.length(); }
                if (openMessage != "") { useMessageLength = openMessage.length(); }

             
                if (useMessage != "") { imu = useMessage.c_str(); }
                if (openMessage != "") {imu = openMessage.c_str(); }
                const char* imenu = gameObject.c_str();
                                           
                dTexture.x = gdSprite.x - 100;  //Set position of text.

                if(interactionMessage !=""){
                 
                    //Set Scene Background Player Positions. An example would be if you entered a building but you wanted the player to start in the middle of the scene.
                    if (interactionMessage == "Scene1b") {
                        interactionMessage = "";
                        xPosition = 400;               
                        gdSprite.x = xPosition;
                    }

                    if (interactionMessage == "Scene1") {    
                        interactionMessage = "";
                       xPosition = 600;
                       gdSprite.x = xPosition;
                       background2 = { 0, 200, 1500, 400 };
                    }

                    if (interactionMessage == "Scene1e") {
                        interactionMessage = "";
                        xPosition = 100;
                        gdSprite.x = xPosition;
                        gdSprite.y = yPosition;
                  //      SDL_WarpMouseInWindow(window, WIDTH, HEIGHT); //This is to try and prevent a crash.
                    }

                    if (interactionMessage == "Scene1f") {

                        if (tLoader == 0) {
                            tex.Scene2Textures();
                            tLoader = 1;
                        }
                      
                        interactionMessage = "";
                        xPosition = 10;
                        gdSprite.x = xPosition;
                        gdSprite.y = yPosition;

                    }

                    if (interactionMessage == "Scene1fb") {
                        interactionMessage = "";
                        xPosition = 10;
                        gdSprite.x = xPosition;
                        gdSprite.y = yPosition;

                       

                    }

                    if (interactionMessage == "Scene1fa") {
                        interactionMessage = "";
                        xPosition = 200;
                        gdSprite.x = xPosition;
                        gdSprite.y = yPosition;

                    }

                    if (interactionMessage == "Scene1d") {
                        interactionMessage = "";
                       // xPosition = 10;
                        gdSprite.x = xPosition;
                        gdSprite.y = yPosition;

                    }

                    if (interactionMessage == "Scene1d2") {
                        interactionMessage = "";
                       

                    }


                    messageHolder = 1;
                //The following 2 if statements will ensure the dialog text doesn't go off the screen. Needs tweaking a little bit.
                if(gdSprite.x > 130 && gdSprite.x > WIDTH -100){
                    textRect = { gdSprite.x -300, gdSprite.y - 80, interactionMessagelength *10, 20 };
                   
                  //  SDL_ShowCursor(0);
                  
                  //  SDL_WarpMouseInWindow(window, WIDTH, HEIGHT); //Move mouse out of focus to keep text on screen.

                   
                }
                else if (gdSprite.x > 130 && gdSprite.x < WIDTH - 100) {
                    textRect = { gdSprite.x - 100 , gdSprite.y - 80, interactionMessagelength * 10, 20 };
            
                  

                }
               
                else if(gdSprite.x < 130){
                    textRect = { gdSprite.x - 60 , gdSprite.y - 80, interactionMessagelength *10, 20 };
                 
                  
                }  


                }
                //This helps with keeping the message on the screen long enough for the player to actually read it!
                if (useMessage != "" || openMessage != "") {
                    if (useMessage == "Use" || useMessage == "Pull" || openMessage == "Open") {
                        messageHolder = 0;
                    }
                    else {                     
                        messageHolder = 1;
                    }
                   
                    //The following 2 if statements will ensure the dialog text doesn't go off the screen. Needs tweaking a little bit.
                    if (gdSprite.x > 130 && WIDTH - 400) {
                        textRect = { gdSprite.x - 60, gdSprite.y - 100, useMessageLength * 10, 20 };
                    }
                    else if (gdSprite.x < 130) {
                        textRect = { gdSprite.x -60, gdSprite.y - 100, useMessageLength * 10, 20 };
                    }
                 
                }
                         
                //This prevents a memory leak by detecting if the mouse was held down too long. Normally I set this to 5 but I have increased it for testing.
                if (mouseHold < 2) {
              
                     if(interactionMessage !=""){                       
                        fsurface = TTF_RenderText_Solid(font, im, fcolor);                    
                       
                     }
                     //This helps with keeping the message on the screen long enough for the player to actually read it!
                     if (useMessage != "" || openMessage != "") {
                         if (useMessage == "Use" || useMessage == "Pull" || openMessage == "Open") {
                             messageHolder = 0;
                         }
                         else {                          
                             messageHolder = 1;
                         }

                         fsurface = TTF_RenderText_Solid(font, imu, fcolor);           
                     }
                     
                     //Render the text on the screen.
                     
                     ftexture = SDL_CreateTextureFromSurface(renderer, fsurface);
                    _sleep(300); // pauses briefly to allow text to show.
                 
                   // SDL_DestroyTexture(dialogmTexture);
                                  
                    //Increase mouseHold variable by one.
                    mouseHold++;

                    //Delete Pointers
                    im = NULL;
                    imu = NULL;
                    delete(im);
                    delete(imu);        
                   
                }     
             }
             else {                
                mouseHold = 1;       
                SDL_DestroyTexture(ftexture);
                fsurface = NULL;
             }
}
 
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


        

        //This will show the scene player messages in sequence.
        if (playerMessage == 1) {

            interactionMessage = pi.PlayerMessage(scene, 1);

            std::cout << interactionMessage << endl;
            int interactionMessagelength = interactionMessage.length();
            const char* im = interactionMessage.c_str();
            textRect = { 100, 310, interactionMessagelength * 10, 20 };
            _sleep(100); // pauses briefly to allow text to show.                

            fsurface = TTF_RenderText_Solid(font, im, fcolor);
            ftexture = SDL_CreateTextureFromSurface(renderer, fsurface);
            // SDL_RenderCopy(renderer, ftexture, NULL, &textRect);
            playerMessage = 2;


        }
        else if (playerMessage == 2) {

            interactionMessage = pi.PlayerMessage(scene, 2);
            std::cout << interactionMessage << endl;
            int interactionMessagelength = interactionMessage.length();
            const char* im = interactionMessage.c_str();

            textRect = { 100, 310, interactionMessagelength * 10, 20 };
            fsurface = TTF_RenderText_Solid(font, im, fcolor);
            ftexture = SDL_CreateTextureFromSurface(renderer, fsurface);
            _sleep(100); // pauses briefly to allow text to show.  

            playerMessage = 3;
            _sleep(3000);
        }

        else if (playerMessage == 3) {

            interactionMessage = pi.PlayerMessage(scene, 3);
            std::cout << interactionMessage << endl;
            int interactionMessagelength = interactionMessage.length();
            const char* im = interactionMessage.c_str();

            textRect = { 100, 310, interactionMessagelength * 10, 20 };
            fsurface = TTF_RenderText_Solid(font, im, fcolor);
            ftexture = SDL_CreateTextureFromSurface(renderer, fsurface);
            _sleep(100); // pauses briefly to allow text to show.                

            playerMessage = 6;
            _sleep(3000);
        }

        else if (playerMessage == 4) {

            interactionMessage = pi.PlayerMessage(scene, 4);
            std::cout << interactionMessage << endl;
            int interactionMessagelength = interactionMessage.length();
            const char* im = interactionMessage.c_str();

            textRect = { 100, 310, interactionMessagelength * 10, 20 };
            fsurface = TTF_RenderText_Solid(font, im, fcolor);
            ftexture = SDL_CreateTextureFromSurface(renderer, fsurface);
            _sleep(100); // pauses briefly to allow text to show.                

            playerMessage = 5;
          //  _sleep(3000);
        }


        //This is important to allow the last message in the player interaction to be shown.
        else if (playerMessage == 5) {

            interactionMessage = pi.PlayerMessage(scene, 5);
            std::cout << interactionMessage << endl;
            int interactionMessagelength = interactionMessage.length();
            const char* im = interactionMessage.c_str();

            textRect = { 100, 310, interactionMessagelength * 10, 20 };
            fsurface = TTF_RenderText_Solid(font, im, fcolor);
            ftexture = SDL_CreateTextureFromSurface(renderer, fsurface);
            _sleep(100); // pauses briefly to allow text to show.                

            SDL_WarpMouseInWindow(window, WIDTH, HEIGHT); //Move mouse out of focus to keep text on screen.
        
            
                 playerMessage = 6;
        
        }

        else if (playerMessage == 6) {

            interactionMessage = pi.PlayerMessage(scene, 6);
            std::cout << interactionMessage << endl;
            int interactionMessagelength = interactionMessage.length();
            const char* im = interactionMessage.c_str();

            textRect = { 100, 310, interactionMessagelength * 10, 20 };
            fsurface = TTF_RenderText_Solid(font, im, fcolor);
            ftexture = SDL_CreateTextureFromSurface(renderer, fsurface);
            _sleep(100); // pauses briefly to allow text to show.                

            SDL_WarpMouseInWindow(window, WIDTH, HEIGHT); //Move mouse out of focus to keep text on screen.


            playerMessage = 7;

        }


        //This is important to allow the last message in the player interaction to be shown.
        else if (playerMessage == 6) {

            playerMessage = 7;
            _sleep(3000);
        }


        else {
       
        }

        //This needs to go here, don't move it.
        SDL_RenderCopy(renderer, menuTexture, NULL, &menu);   
 
        //Display Scene Objects if not destroyed (picked up).     

        //Scene1a
        //If the object has been picked up
        //PDA Inventory item.
        if (objectToDestroy.find("1") != std::string::npos) {
            SDL_RenderCopy(renderer, Textures::invTexture1, NULL, &inv1);
           
          
        }
    
        else if(SceneBackground == "1") {SDL_RenderCopy(renderer, objectTexture, &PlayerObjects::srcrect, &PlayerObjects::dstrect);}
        
        //Scene1b

        //If the object has been picked up.
        //Flag Inventory Item
        if (objectToDestroy.find("2") != std::string::npos ) {    
            SDL_RenderCopy(renderer, Textures::invTexture2, NULL, &inv2); 
        }


        else if (SceneBackground == "1b") { 
            SDL_RenderCopy(renderer, objectTexture2, &PlayerObjects::srcrect2, &PlayerObjects::dstrect2);

        }
       
        //Duct Tape Inventory Item.
        if (objectToDestroy.find("3") != std::string::npos) {
            if (inv3Used == 0) {             
                    SDL_RenderCopy(renderer, Textures::invTexture3, NULL, &inv3);                         
            }
        }
        else if (SceneBackground == "1b") {
     
            SDL_RenderCopy(renderer, objectTexture4, &PlayerObjects::srcrect4, &PlayerObjects::dstrect4);
   
        }


        //Tent
        if (objectToDestroy.find("4") != std::string::npos) {
            if (inv4Used == 0) {
                //This makes sure the inventory item is removed if the player has used the tent.
                SDL_RenderCopy(renderer, Textures::invTexture4, NULL, &inv4);
            }
        }
        else if (SceneBackground == "1b") {

            SDL_RenderCopy(renderer, objectTexture5, &PlayerObjects::srcrect5, &PlayerObjects::dstrect5);
        }

        //Pipe
       
        if (objectToDestroy.find("5") != std::string::npos) {
           if(inv5Used == 0){
            SDL_RenderCopy(renderer, Textures::invTexture3, NULL, &inv3);
                         
           }
         
        }
        
        if (SceneBackground == "1da" || SceneBackground == "1db") {
            SDL_RenderCopy(renderer, objectTextureAirBox, &PlayerObjects::srcrect7, &PlayerObjects::dstrect7);

        }


        //Display Character
        gdSprite.w = SPRITE_SIZE;
        gdSprite.h = SPRITE_SIZE;
     
       
        if(playerMessage > 3){
            SDL_RenderCopy(renderer, spriteTexture, NULL, &gdSprite);
        }
        else {
            SDL_DestroyTexture(spriteTexture);
            spriteTexture = SDL_CreateTextureFromSurface(renderer, spriteFlat);
            SDL_RenderCopy(renderer, spriteTexture, NULL, &gdSprite);
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
          //  SDL_RenderCopy(renderer, objectTextureAirBox, &srcrect7, &dstrect7);
            SDL_RenderCopy(renderer, objectTexture6, &PlayerObjects::srcrect6, &PlayerObjects::dstrect6);
            
                                
        }
        
   
        SDL_RenderCopy(renderer, ftexture, NULL, &textRect);
        SDL_RenderCopy(renderer, dialogmTexture, NULL, &menuTextRect);

        //Ensures text is always on the top.
        if (interactionMessage != "" || gameObject != "")
            SDL_RenderCopy(renderer, ftexture, NULL, &textRect);
       
        //Render the screen.

       // SDL_RenderCopy(renderer, spriteTexture, NULL, &gdSprite);
       
        interactionMessage = ""; // Clear the interaction message on every loop.
       
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