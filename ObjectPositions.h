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
		static int ROCKS_X;
		static int ROCKS_Y;
		static int ROCKS_SX;
		static int ROCKS_SY;

		//Objects that can be picked up.
		static int PDA_X;
		static int PDA_Y;
		static int PDA_SX;
		static int PDA_SY;
		static int ATAPE_X;
		static int ATAPE_Y;
		static int TENT_X;
		static int TENT_Y;

		//Inventory
		static int INV1_X;
		static int INV1_Y;
		static int INV1_SX;
		static int INV1_SY;

		//Hover Interactions
		static int MOON_X;
		static int MOON_Y;
		
		//Menu
		static int USE_X;
		static int USE_Y;
		static int OPEN_X;
		static int OPEN_Y;
		static int LOOK_X;
		static int LOOK_Y;
		static int PICKUP_X;
		static int PICKUP_Y;
		static int PULL_X;
		static int PULL_Y;
		static int MENU_Y;
		static int MENU_HY;
		static int HOVERTEXT_X;
		static int HOVERTEXT_Y;
		static int NEWGAME_X;
		static int NEWGAME_Y;
		static int CONTINUE_X;
		static int CONTINUE_Y;
		static int OPTIONS_X;
		static int OPTIONS_Y;

		//Offset for click boundries. Depending on the resolution these boundries would need to be increased or decreased.
		static int OFFSET_X;
		static int OFFSET_Y;


		//Background
		static int BACKGROUND_H;

		float CalcObjectYPositionPercentage(float position, std::string objectName);
		float CalcObjectXPositionPercentage(float position, std::string objectName);
		float CalcObjectXAbsolutePosition(float position, std::string objectName);
		float CalcObjectYAbsolutePosition(float position, std::string objectName);
		int CalcAssetSize(int size,float percentIncrease);
		int CalcAssetDecreaseSize(int size, int percentDecrease);

		void PlaceMenuYPosition();
		//void PlaceHoverObjects();
		void SetBackgroundHeight();
		void PlaceSceneObjects();
		void SetHoverTextPosition();
		void PlaceInventoryObjects();

	};
}