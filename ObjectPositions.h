#pragma once
#include <string>

namespace brightland {
	class ObjectPositions
	{
	private:

	public:
		//X and Y
		static int x;
		static int y;

		//Player location
		static int PlayerLocationX;
		static int PlayerLocationY;

		//Scene Areas
		static int WREAKAGEDOOR_X;
		static int WREAKAGEDOOR_Y;
		static int ENGINE_X;
		static int ENGINE_Y;

		//Objects that can be picked up.
		static int PDA_X;
		static int PDA_Y;
		static int ATAPE_X;
		static int ATAPE_Y;
		static int TENT_X;
		static int TENT_Y;

		//Hover Interactions
		static int MOON_X;
		static int MOON_Y;
		
		//Menu
		static int USE_X;
		static int USE_Y;
		static int OPEN_X;
		static int OPEN_Y;

		float CalcObjectYPositionPercentage(float position, std::string objectName);
		float CalcObjectXPositionPercentage(float position, std::string objectName);
		float CalcObjectXAbsolutePosition(float position, std::string objectName);
		float CalcObjectYAbsolutePosition(float position, std::string objectName);
		void PlaceHoverObjects();

	};
}