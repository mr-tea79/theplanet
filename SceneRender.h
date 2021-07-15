#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "Scene1.h"


namespace brightland {

	class SceneRender {

	public:
		void sceneRender();
		void sceneRenderOverlay(int x, int y);
		int HoverButtons(int x, int y);

	};


}