#include "GameEngine.h"
#include <chrono>
#include <thread>
#include <iostream>
#include "GameInput.h"

//const double game::fps = 30.0;
	//The number of milliseconds that must pass before a new frame is started. This is set in initialization and simply used for the delay method.
//const double game::frametime = 1000.0 / fps;

//Code 27 ends the game

//The current game state to run. It will recieve updates from the engine at the number of fps.
GameStateJump game::jumper = GameStateJump();
GameState *game::state = &game::jumper;
//The screen for the game to be rendered to. The screen has the ability to be drawn to and redrawn each frame.
Screen game::display = Screen();

bool game::contPlaying = true;

void game::gameLoop()
{
	//Initalize time variables used to maintain consistent frame rates.
	chrono::high_resolution_clock::time_point current; //What time is it now?
	chrono::high_resolution_clock::time_point last; //What time was it last frame?
	chrono::duration<double, milli> deltaTime; //What is the difference in time between now and last frame?

	current = chrono::high_resolution_clock::now(); //Sets the current time to be equal to this time.
	last = chrono::high_resolution_clock::now(); //Initializes the time of last frame to now. Just to have a base value, it should not matter.
	deltaTime = current - last; //Initializes delta time, should not matter.

	contPlaying = true;

	while (contPlaying) {
		//Print frame rate and frametime for testing purposes to make sure the delay is working properly.
		cout << "FPS: " << 1000 / deltaTime.count() << "\n" << "Delta: " << deltaTime.count() << "\n" << "Pressed: " << input::getPressed() << "\n";
		
		//Ticks the current game state for logic updates.
		//Delta time is included so logic update rate can be independent of frame rate.
		state->tick(deltaTime.count());
		//Clear the screen to prepare for the next frame.
		display.clear();
		//Tells the game state to draw it's textures.
		state->render(&display);
		//Render display to the terminal.
		display.render();

		//Wait to keep a consistent frame rate of 30 fps
		do {
			current = chrono::high_resolution_clock::now(); //Sets the current time to where we are after the frame.
			deltaTime = current - last; //Finds how much time has passed.
			//If we have at least one millisecond until the next frame needs to run, then sleep for that millisecond.
			if (deltaTime.count() + 1.3 < frametime) {
				delay(1);
			}
		} while (deltaTime.count() < frametime); //If there was time to wait, return and update the information.
		//Lastly set this current frame to the last frame and start over again.
		last = chrono::high_resolution_clock::now();

		//Allows the player to end the game by pressing q.
		if (input::getPressed() == 113) {
			contPlaying = false;
			input::usedPress();
		}
	}
}

void game::delay(int mSec)
{
	this_thread::sleep_for(chrono::milliseconds(mSec));
}

GameState * game::getCurrentState()
{
	return state;
}
