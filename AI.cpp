#include "AI.h"
#include "Scene1.h"
#include "thread"
#include <iostream>
#include "PlayerInteraction.h"


using namespace brightland;
using namespace std;

int AI::aiStop = 0; //This is used to halt the user from moving while the AI is talking to the player.

void Messages() {
    while (!Scene1::threadRipper) {   

        if(Scene1::SceneBackground == "1"){
          
       // std::cout << PlayerInteraction::playerMessage << std::endl;
      
        if (PlayerInteraction::playerMessage == 100) {
            AI::aiStop = 1;
            PlayerInteraction::playerMessage = 15;
            std::this_thread::sleep_for(2s);  
            Scene1::sceneHalt = 1;                     
        }

        if (PlayerInteraction::playerMessage == 100) {
            PlayerInteraction::playerMessage =16;
            std::this_thread::sleep_for(2s);
            
        }

        if (PlayerInteraction::playerMessage == 100) {          
            PlayerInteraction::playerMessage = 17;
            std::this_thread::sleep_for(2s);
            Scene1::sceneHalt = 0;
            AI::aiStop = 0;
            PlayerInteraction::playerMessage = 200;
            
        }

       
    }
    }
}

void AI::ToadTalk() {

    std::thread t(Messages);
    t.detach();


}