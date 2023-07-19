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
bool AI::playerTalk; //This is enabled if the player needs to say something.
int AI::dialogNumber = 0; //This is to identify what dialog the player will see on any given scene.

//This starts the dialog when the player looks at something.
void startDialog() {
    AI::aiStop = 1;
    std::this_thread::sleep_for(0.5s);
    Scene1::sceneHalt = 1;
}

void stopDialog() {
    std::this_thread::sleep_for(1s);
    Scene1::sceneHalt = 0;
    AI::aiStop = 0;
    AI::aiPlayMessages = false;
    AI::playerTalk = false;

}

void Messages() {
    while (!Scene1::threadRipper) {   
        
        if (Scene1::SceneBackground == "1" && AI::playerTalk == true && AI::dialogNumber == 1) {
            if (AI::beenThereAlready.find("0") != std::string::npos) { PlayerInteraction::playerMessage = 1000; }
            else {
                AI::aiStop = 1;
                PlayerInteraction::playerMessage = 1;
                std::this_thread::sleep_for(1.5s);
                Scene1::sceneHalt = 1;

                PlayerInteraction::playerMessage = 2;
                std::this_thread::sleep_for(1s);
                Scene1::sceneHalt = 0;
                AI::aiStop = 0;
                AI::aiPlayMessages = false;
                AI::playerTalk = false;

            }
        }
       
        if (Scene1::SceneBackground == "1" && AI::playerTalk == true && AI::dialogNumber == 2) {
            if (AI::beenThereAlready.find("2") != std::string::npos) { PlayerInteraction::playerMessage = 1000; }
            else {
                AI::aiStop = 1;
                PlayerInteraction::playerMessage = 3;
                std::this_thread::sleep_for(1.5s);
                Scene1::sceneHalt = 1;

                PlayerInteraction::playerMessage = 4;
                stopDialog();

            }
        }     

        if (Scene1::SceneBackground == "1" && AI::playerTalk == true && AI::dialogNumber == 3) {
            if (AI::beenThereAlready.find("3") != std::string::npos) { PlayerInteraction::playerMessage = 1000; }
            else {
                    startDialog();
                    AI::aiStop = 1;
                    PlayerInteraction::playerMessage = 5;
                    std::this_thread::sleep_for(1.5s);
                    Scene1::sceneHalt = 1;

                    PlayerInteraction::playerMessage = 6;
                    stopDialog();
                  

                }            

        }

        if (Scene1::SceneBackground == "1" && AI::playerTalk == true && AI::dialogNumber == 4) {
            if (AI::beenThereAlready.find("4") != std::string::npos) { PlayerInteraction::playerMessage = 1000; }
            else {
                startDialog();
                PlayerInteraction::playerMessage = 7;
                std::this_thread::sleep_for(1.5s);
                Scene1::sceneHalt = 1;

                PlayerInteraction::playerMessage = 8;
                stopDialog();

            }
        }

        if (Scene1::SceneBackground == "1b" && AI::continueGame == false && AI::playerTalk == true && AI::dialogNumber == 5) {
            if (AI::beenThereAlready.find("5") != std::string::npos) { PlayerInteraction::playerMessage = 1000; }
            else {
                AI::aiStop = 1;
                PlayerInteraction::playerMessage = 9;
                std::this_thread::sleep_for(1.5s);
                Scene1::sceneHalt = 1;

                PlayerInteraction::playerMessage = 10;
                stopDialog();
                AI::beenThereAlready.append("5");

            }
        }

        if (Scene1::SceneBackground == "1b" && AI::playerTalk == true && AI::dialogNumber == 6) {
            if (AI::beenThereAlready.find("6") != std::string::npos) { PlayerInteraction::playerMessage = 1000; }
            else {
                startDialog();
                PlayerInteraction::playerMessage = 11;
                std::this_thread::sleep_for(1.5s);
                Scene1::sceneHalt = 1;

                PlayerInteraction::playerMessage = 12;
                stopDialog();

            }
        }
        if (Scene1::SceneBackground == "1f" && AI::playerTalk == true && AI::dialogNumber == 20) {
            startDialog();
            PlayerInteraction::playerMessage = 32;
            stopDialog();
        }

        if(Scene1::SceneBackground == "1" && AI::continueGame == false && AI::aiPlayMessages == true) {
            if (AI::beenThereAlready.find("1") != std::string::npos) { PlayerInteraction::playerMessage = 1000; }
            else{
            
                PlayerInteraction::playerMessage = 18;
                startDialog();
           
                PlayerInteraction::playerMessage =16;
                startDialog();
                   
                PlayerInteraction::playerMessage = 17;
                stopDialog();
                AI::beenThereAlready.append("1");
            }
        }

        if (Scene1::SceneBackground == "1e" && AI::continueGame == false && AI::aiPlayMessages == true ) {

            if (AI::beenThereAlready.find("1e") != std::string::npos) { PlayerInteraction::playerMessage = 1000; }
            else {
           
                PlayerInteraction::playerMessage = 18;
                startDialog();

                PlayerInteraction::playerMessage = 19;
                stopDialog();
                AI::beenThereAlready.append("1e");
            }
           
        }

        if (Scene1::SceneBackground == "1" && AI::playerTalk == true && AI::dialogNumber == 7) {
            if (AI::beenThereAlready.find("7") != std::string::npos) { PlayerInteraction::playerMessage = 1000; }
            else {
                startDialog();
                PlayerInteraction::playerMessage = 13;
                stopDialog();

            }
        }

        if (Scene1::SceneBackground == "1" && AI::playerTalk == true && AI::dialogNumber == 8) {
            if (AI::beenThereAlready.find("8") != std::string::npos) { PlayerInteraction::playerMessage = 1000; }
            else {
                startDialog();
                PlayerInteraction::playerMessage = 15;
                stopDialog();
            }
        }

        if (Scene1::SceneBackground == "1b" && AI::playerTalk == true && AI::dialogNumber == 9) {
            if (AI::beenThereAlready.find("9") != std::string::npos) { PlayerInteraction::playerMessage = 1000; }
            else {
                startDialog();
                PlayerInteraction::playerMessage = 20;
                stopDialog();;

            }
        }
        if (Scene1::SceneBackground == "1b" && AI::playerTalk == true && AI::dialogNumber == 10) {
            if (AI::beenThereAlready.find("10") != std::string::npos) { PlayerInteraction::playerMessage = 1000; }
            else {
                startDialog();
                PlayerInteraction::playerMessage = 21;
                           

                PlayerInteraction::playerMessage = 22;
                stopDialog();

            }
        }

        if ( AI::playerTalk == true && AI::dialogNumber == 11) {
            if (AI::beenThereAlready.find("11") != std::string::npos) { PlayerInteraction::playerMessage = 1000; }
            else {
                startDialog();
                PlayerInteraction::playerMessage = 23;
                stopDialog();

            }
        }

        if (AI::playerTalk == true && AI::dialogNumber == 12) {
            if (AI::beenThereAlready.find("12") != std::string::npos) { PlayerInteraction::playerMessage = 1000; }
            else {
                startDialog();
                PlayerInteraction::playerMessage = 24;
                stopDialog();

            }
        }

        if (AI::playerTalk == true && AI::dialogNumber == 13) {
            if (AI::beenThereAlready.find("13") != std::string::npos) { PlayerInteraction::playerMessage = 1000; }
            else {
                startDialog();
                PlayerInteraction::playerMessage = 25;
                stopDialog();

            }
        }

        if (AI::playerTalk == true && AI::dialogNumber == 14) {
            if (AI::beenThereAlready.find("14") != std::string::npos) { PlayerInteraction::playerMessage = 1000; }
            else {
                startDialog();
                PlayerInteraction::playerMessage = 26;
                stopDialog();

            }
        }

        if (Scene1::SceneBackground == "1fb" && AI::aiPlayMessages == true) {
            if (AI::beenThereAlready.find("15") != std::string::npos) { PlayerInteraction::playerMessage = 1000; }
            else {
                startDialog();
                PlayerInteraction::playerMessage = 27;
                stopDialog();
                AI::beenThereAlready.append("15");
               
               
            }

        }

        if (Scene1::SceneBackground == "1da" && AI::aiPlayMessages == true && AI::dialogNumber == 16) {
            if (AI::beenThereAlready.find("16") != std::string::npos) { PlayerInteraction::playerMessage = 1000; }
            else {
                startDialog();
                PlayerInteraction::playerMessage = 28;
                
                stopDialog();
                AI::beenThereAlready.append("16");


            }

        }

        if (Scene1::SceneBackground == "1da" && AI::aiPlayMessages == true && AI::dialogNumber == 17) {
            if (AI::beenThereAlready.find("17") != std::string::npos) { PlayerInteraction::playerMessage = 1000; }
            else {

                startDialog();
                PlayerInteraction::playerMessage = 29;
                            
                stopDialog();


            }

        }
        if (Scene1::SceneBackground == "1da" && AI::aiPlayMessages == true && AI::dialogNumber == 18) {
            if (AI::beenThereAlready.find("18") != std::string::npos) { PlayerInteraction::playerMessage = 1000; }
            else {

                startDialog();
                PlayerInteraction::playerMessage = 30;
               
                stopDialog();


            }

        }
        if (Scene1::SceneBackground == "1da" && AI::aiPlayMessages == true && AI::dialogNumber == 19) {
            if (AI::beenThereAlready.find("19") != std::string::npos) { PlayerInteraction::playerMessage = 1000; }
            else {

                startDialog();
                PlayerInteraction::playerMessage = 31;
              
                stopDialog();


            }

        }

    }
}


void AI::ToadTalk() {

    std::thread t(Messages);
    t.detach();


}