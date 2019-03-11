//
//  main.cpp
//  CommandLineAnimator
//
//  Written by Kaiden Richardson
//  The main file is for testing and design purposes. A user would be able to initalize the necessary variables and call gameLoop() to run the game state they have created.
//  Known Limmitations: There is no display of how to play any given game.
//

#include "pch.h"
#include "GameStateJump.h"
#include "GameEngine.h"

GameStateJump jump = GameStateJump();

//This is for testing or built in game states. In theory, a user would have their own main() method to run and simply call gameLoop() in this class.
int main(int argc, const char * argv[]) {
	//Set the running state to the default state.
	game::state = &jump;
	//Starts the main game loop with whatever game state has been configured.
	game::gameLoop();
	//Ends the game and returns no error code.
	return 0;
}
