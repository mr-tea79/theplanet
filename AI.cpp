#include "AI.h"
#include "Scene1.h"
#include "thread"
#include <iostream>
#include "PlayerInteraction.h"


using namespace brightland;
using namespace std;

int AI::aiStop = 0; //This is used to halt the user from moving while the AI is talking to the player.
std::string AI::beenThereAlready = ""; //This is to prevent the AI from repeating itself if you revisit an area that had dialog.
bool AI::continueGame;  //This is used to halt the messages if you are continuing a game.
bool AI::aiPlayMessages;

void Messages() {
    while (!Scene1::threadRipper) {   

   //     std::cout << "Been there already: " << AI::beenThereAlready << std::endl;
      

        if(Scene1::SceneBackground == "1" && AI::continueGame == false && AI::aiPlayMessages == true) {
            if (AI::beenThereAlready.find("1") != std::string::npos) { PlayerInteraction::playerMessage = 1000; }
            else{
                AI::aiStop = 1;
                PlayerInteraction::playerMessage = 15;
                std::this_thread::sleep_for(2s);  
                Scene1::sceneHalt = 1;                     
           
                PlayerInteraction::playerMessage =16;
                std::this_thread::sleep_for(2s);
                Scene1::sceneHalt = 1;
                   
                PlayerInteraction::playerMessage = 17;
                std::this_thread::sleep_for(2s);
                Scene1::sceneHalt = 0;
                AI::aiStop = 0;
                AI::aiPlayMessages = false;
                AI::beenThereAlready.append("1");
            }
        }

        if (Scene1::SceneBackground == "1e" && AI::continueGame == false && AI::aiPlayMessages == true ) {

            if (AI::beenThereAlready.find("2") != std::string::npos) { PlayerInteraction::playerMessage = 1000; }
            else {
                AI::aiStop = 1;
                PlayerInteraction::playerMessage = 18;
                std::this_thread::sleep_for(2s);
                Scene1::sceneHalt = 1;

                PlayerInteraction::playerMessage = 19;
                std::this_thread::sleep_for(2s);
                Scene1::sceneHalt = 0;
                AI::aiStop = 0;
                AI::aiPlayMessages = false;
                AI::beenThereAlready.append("22");
            }
           
        }
    }
}

void AI::ToadTalk() {

    std::thread t(Messages);
    t.detach();


}