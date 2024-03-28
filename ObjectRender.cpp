#include "ObjectRender.h"
#include "Textures.h"

using namespace brightland;

//Renders the objects that the player can pick up etc.

void ObjectRender::objectRender() {
    //Display Scene Objects if not destroyed (picked up).     

    //PDA Inventory item.
    if (Scene1::objectToDestroy.find("1") != std::string::npos) {  
        if (Inventory::inv.find("1")) {
            SDL_RenderCopy(Scene1::renderer, Textures::invTexture1, NULL, &Inventory::inv1);
        }      
    }

    else if (Scene1::SceneBackground == "1") { SDL_RenderCopy(Scene1::renderer, Textures::PDATexture, &PlayerObjects::srcrect, &PlayerObjects::dstrect); }

    //Flag Inventory Item
    if (Scene1::objectToDestroy.find("2") != std::string::npos) {
        SDL_RenderCopy(Scene1::renderer, Textures::invTexture2, NULL, &Inventory::inv2);
    }
    else if (Scene1::SceneBackground == "1b") {
        SDL_RenderCopy(Scene1::renderer, Textures::objectTexture2, &PlayerObjects::srcrect2, &PlayerObjects::dstrect2);
    }

    //Ape Tape Inventory Item.
    if (Scene1::objectToDestroy.find("3") != std::string::npos) {
        if (Inventory::inv.find("3")) {
            SDL_RenderCopy(Scene1::renderer, Textures::invTexture3, NULL, &Inventory::inv3);
        }
    }
    else if (Scene1::SceneBackground == "1b") {
        SDL_RenderCopy(Scene1::renderer, Textures::objectTexture4, &PlayerObjects::srcrect4, &PlayerObjects::dstrect4);
    }

    //Tent
    if (Scene1::objectToDestroy.find("4") != std::string::npos) {
        if (Inventory::inv.find("4") == std::string::npos) {
            //This makes sure the inventory item is removed if the player has used the tent.
            SDL_RenderCopy(Scene1::renderer, Textures::invTexture4, NULL, &Inventory::inv4);
        }
    }
    else if (Scene1::SceneBackground == "1b") {
        SDL_RenderCopy(Scene1::renderer, Textures::objectTexture5, &PlayerObjects::srcrect5, &PlayerObjects::dstrect5);
    }

    //Pipe      
    if (Scene1::objectToDestroy.find("5") != std::string::npos) {
        if (Inventory::inv.find("5") == std::string::npos) {
            SDL_RenderCopy(Scene1::renderer, Textures::invTexture3, NULL, &Inventory::inv3);
        }
    }

    //Lantern    
    if (Scene1::objectToDestroy.find("6") != std::string::npos) {
        if (Inventory::inv.find("7") == std::string::npos) {
            SDL_RenderCopy(Scene1::renderer, Textures::invTexture6, NULL, &Inventory::inv7);
        }
    }
    else if (Scene1::SceneBackground == "1da" || Scene1::SceneBackground == "1db") {
        SDL_RenderCopy(Scene1::renderer, Textures::objectTextureLantern, &PlayerObjects::srcrect8, &PlayerObjects::dstrect8);
    }  

    //Air Pressure Unit
    if (Scene1::SceneBackground == "1da" || Scene1::SceneBackground == "1db") {
        SDL_RenderCopy(Scene1::renderer, Textures::objectTextureAirBox, &PlayerObjects::srcrect7, &PlayerObjects::dstrect7);

    }

    //Disc
    //if the number 7 was found in the objectToDestroy then ...
    if (Scene1::objectToDestroy.find("7") != std::string::npos) {
        //if the number 8 is NOT found in the inv string, then display the inventory item.
        if (Inventory::inv.find("8") == std::string::npos) {
            SDL_RenderCopy(Scene1::renderer, Textures::invTexture7, NULL, &Inventory::inv7);
        }
    }

}