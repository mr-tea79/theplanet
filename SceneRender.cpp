#include "SceneRender.h"
#include "Textures.h"

using namespace brightland;

//Renders the scene backgrounds for the game.
void SceneRender::sceneRender() {


    if (Scene1::SceneBackground == "1") {
        SDL_RenderCopy(Scene1::renderer, Textures::texture, NULL, &Scene1::background);
    }

    if (Scene1::SceneBackground == "1b") {
        SDL_RenderCopy(Scene1::renderer, Textures::wreakageScene, NULL, &Scene1::background);
    }

    if (Scene1::SceneBackground == "1e") {
        SDL_RenderCopy(Scene1::renderer, Textures::scene1e, NULL, &Scene1::background);
    }

    if (Scene1::SceneBackground == "1f") {
        SDL_RenderCopy(Scene1::renderer, Textures::scene1f, NULL, &Scene1::background);
    }

    if (Scene1::SceneBackground == "1fb") {
        SDL_RenderCopy(Scene1::renderer, Textures::scene1fb, NULL, &Scene1::background);
    }

    if (Scene1::SceneBackground == "1da") {
        SDL_RenderCopy(Scene1::renderer, Textures::scene1d, NULL, &Scene1::background);
    }

    if (Scene1::SceneBackground == "1db") {
        SDL_RenderCopy(Scene1::renderer, Textures::scene1d2, NULL, &Scene1::background);
    }

    if (Scene1::SceneBackground == "3a") {
        SDL_RenderCopy(Scene1::renderer, Textures::scene3a, NULL, &Scene1::background);
    }
    if (Scene1::SceneBackground == "3b") {
        SDL_RenderCopy(Scene1::renderer, Textures::scene3b, NULL, &Scene1::background);
    }
    if (Scene1::SceneBackground == "3d") {
        SDL_RenderCopy(Scene1::renderer, Textures::caveScene2, NULL, &Scene1::background);
    }
   
}

//Renders objects that appear in front of the player like rocks as an example.
void SceneRender::sceneRenderOverlay() {

    if (Scene1::SceneBackground == "1") {
        SDL_RenderCopy(Scene1::renderer, Textures::starsTexture, &PlayerObjects::srcrect3, &PlayerObjects::dstrect3);
        SDL_RenderCopy(Scene1::renderer, Textures::rocks, NULL, &Scene1::background2);
    }


    if (Scene1::SceneBackground == "1c") {

        SDL_RenderCopy(Scene1::renderer, Textures::computerScene1, NULL, &Scene1::background);
    }

    if (Scene1::SceneBackground == "1d") {

        SDL_RenderCopy(Scene1::renderer, Textures::computerScene2, NULL, &Scene1::background);
    }

    if (Scene1::SceneBackground == "1e") {

        SDL_RenderCopy(Scene1::renderer, Textures::rocks2, NULL, &Scene1::background3);
    }

   if (Scene1::SceneBackground == "3c") {
    SDL_RenderCopy(Scene1::renderer, Textures::caveScene1, NULL, &Scene1::background);
   }

   if (Scene1::SceneBackground == "3d") {
       SDL_RenderCopy(Scene1::renderer, Textures::rocks3, NULL, &Scene1::background4);
   }

    //Cut Scene (Hide sprite)
    if (Scene1::SceneBackground == "1fa") {
        SDL_RenderCopy(Scene1::renderer, Textures::scene1fa, NULL, &Scene1::background);
    }
    //Cardboard Box (In front of sprite)
    if (Scene1::SceneBackground == "1da" || Scene1::SceneBackground == "1db") {
        SDL_RenderCopy(Scene1::renderer, Textures::objectTexture6, &PlayerObjects::srcrect6, &PlayerObjects::dstrect6);

    }


}

