#pragma once
#include "GameState.h"
#include "GameStateJump.h"
#include "Screen.h"

namespace game {
	//The game loop is the main function where every frame state#tick and state#rendered will be called from the code.
	//The loop will then wait until enough time has elapsed before calling a new frame such that the update rate = fps.
	void gameLoop();
	//A simple helper method which causes the thread to sleep for a given number of milliseconds.
	void delay(int mSec);

	//The number of updates per second the program will target. The game loop will sleep until at least this time passes between frames.
	const double fps = 5.0;
	//The number of milliseconds that must pass before a new frame is started. This is set in initialization and simply used for the delay method.
	const double frametime = 1000.0 / fps;

	//The current game state to run. It will recieve updates from the engine at the number of fps.
	extern GameStateJump jumper; // = GameStateJump();
	extern GameState *state; // = &jumper;
	//The screen for the game to be rendered to. The screen has the ability to be drawn to and redrawn each frame.
	extern Screen display; // = Screen();

	GameState *getCurrentState();
}