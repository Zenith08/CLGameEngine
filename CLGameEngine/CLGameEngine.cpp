//
//  main.cpp
//  CommandLineAnimator
//
//  Written by Kaiden Richardson
//  The main file is for testing and design purposes. A user would be able to initalize the necessary variables and call gameLoop() to run the game state they have created.
//  Known Limmitations: There is currently no support for keyboard inputs.
//  Date last modified: Friday February 15
//
#include "pch.h"
#include <iostream>
#include <chrono>
#include <thread>
#include "Screen.h"
#include "CollisionBox.h"
#include "GameState.h"
#include "GameStateJump.h"
#include "GameInput.h"
#include "GameEngine.h"
#include "IGSSpaceInvaders.h"

using namespace Collisions;
using namespace std;

GameStateJump jump = GameStateJump();
IGSSpaceInvaders space = IGSSpaceInvaders();

//This is for testing or built in game states. In theory, a user would have their own main() method to run and simply call gameLoop() in this class.
int main(int argc, const char * argv[]) {
	//Set the running state to the default state.
	game::state = &space;
	//Starts the main game loop with whatever game state has been configured.
	game::gameLoop();
	//Ends the game and returns no error code.
	return 0;
}
