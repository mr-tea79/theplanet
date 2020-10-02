#pragma once
#ifndef PLAYEROBJECTS_H_
#define PLAYEROBJECTS_H_
#include <tuple>
#include <string>
#include <SDL.h>
#include "MenuInteraction.h"
#include <SDL_ttf.h>

namespace brightland {
    class PlayerObjects
    {

    public:

        std::string HoverObjects(int x, int y, int scene, int gd, int gy);
        std::string DestroyObjects(std::string gameObject);
        std::tuple<int, int, int, int, int> placeObject(int scene, int a, int b, int c, int d);
        std::tuple<int, int, int, int, int> placeObjectA(int scene, int a, int b, int c, int d);
        int PlayerObject(int x, int y, int scene);
        std::string ObjectInteraction(int x, int y, int playerCurrentLocationx,int playerCurrentLocationy);
      //  std::string ObjectInteractionM(int scene, int x, int y, int playerCurrentLocationx, int playerCurrentLocationy);
        std::string PlayerObjects::ObjectInteractionM1(int playerCurrentLocationX, int playerCurrentLocationY);


    };
}
#endif