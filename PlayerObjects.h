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
        static int boxOpened;
        static SDL_Rect srcrect;
        static SDL_Rect dstrect;
        static SDL_Rect srcrect2;
        static SDL_Rect dstrect2;
        static SDL_Rect srcrect3;
        static SDL_Rect dstrect3;
        static SDL_Rect srcrect4;
        static SDL_Rect dstrect4;
        static SDL_Rect srcrect5;
        static SDL_Rect dstrect5;
        static SDL_Rect srcrect6;
        static SDL_Rect dstrect6;
        static SDL_Rect srcrect7;
        static SDL_Rect dstrect7;
        static SDL_Rect srcrect8;
        static SDL_Rect dstrect8;
        static SDL_Rect srcrect9;
        static SDL_Rect dstrect9;
       

        std::string HoverObjects(int x, int y, int scene, int gd, int gy);
        std::string DestroyObjects(std::string gameObject);
        std::tuple<int, int, int, int, int> ObjectSettings(int scene, int a, int b, int c, int d);
        std::tuple<int, int, int, int, int> placeObject(int scene, int a, int b, int c, int d);
        std::string ObjectInteraction(int x, int y, int playerCurrentLocationx,int playerCurrentLocationy);
        std::string ObjectInteractionM1(int playerCurrentLocationX, int playerCurrentLocationY);
        void ObjectController();
        void SetSpritePosition(int x, int y);
       
     
    };
}
#endif