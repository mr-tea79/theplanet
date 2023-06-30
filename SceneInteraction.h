#pragma once


namespace brightland {

	class SceneInteraction
	{
	public:
		std::string sceneTransitions(int, int, int, int);
		void SetSpritePosition(int x, int y, int s);
		void SetSpritePositionLegacy(int x, int y, int s);

	};

}