#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "Scene1.h"


namespace brightland {

	class SceneRender {

	public:
		void sceneRender(int x, int y);
		void sceneRenderOverlay();
		int HoverButtons(int x, int y);

	};


}