#include <SDL.h>
#include "Scene1.h"

namespace brightland {

	class AI {

	public:
		static bool continueGame;
		static int aiStop;
		static bool playerTalk;
		static bool aiPlayMessages;
		static std::string beenThereAlready;
		static int dialogNumber;

		void ToadTalk();

	};


}
