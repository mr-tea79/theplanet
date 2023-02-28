#pragma once
#include <string>

namespace brightland {
	class ObjectPositions
	{
	private:

	public:

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

		float CalcObjectYPosition(float position, std::string objectName);
		float CalcObjectXPosition(float position, std::string objectName);

	};
}