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

using namespace Collisions;
using namespace std;

//This is for testing or built in game states. In theory, a user would have their own main() method to run and simply call gameLoop() in this class.
int main(int argc, const char * argv[]) {
	//Starts the main game loop with whatever game state has been configured.
	game::gameLoop();
	//Has to be there but currently doesn't run.
	return 0;
}