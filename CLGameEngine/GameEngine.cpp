#include "GameEngine.h"
#include <chrono>
#include <thread>
#include <iostream>
#include "GameInput.h"
#include "FileInput.h"

//const double game::fps = 30.0;
	//The number of milliseconds that must pass before a new frame is started. This is set in initialization and simply used for the delay method.
//const double game::frametime = 1000.0 / fps;

//Code 27 ends the game

//The current game state to run. It will recieve updates from the engine at the number of fps.
GameState *game::state;
//The screen for the game to be rendered to. The screen has the ability to be drawn to and redrawn each frame.
Screen game::display = Screen();

//Whether or not the player wants to keep playing.
//Setting this to false exits the game in a controlled way.
bool game::contPlaying = true;

//The main loop of the game where a GameState recievs ticks and render calls.
void game::gameLoop()
{
	//Initalize time variables used to maintain consistent frame rates.
	chrono::high_resolution_clock::time_point current; //What time is it now?
	chrono::high_resolution_clock::time_point last; //What time was it last frame?
	chrono::duration<double, milli> deltaTime; //What is the difference in time between now and last frame?

	current = chrono::high_resolution_clock::now(); //Sets the current time to be equal to this time.
	last = chrono::high_resolution_clock::now(); //Initializes the time of last frame to now. Just to have a base value, it should not matter.
	deltaTime = current - last; //Initializes delta time, should not matter.
	double sleepTime = 0; //The length of time we should sleep before rendering the next frame.

	//Setting this to true before starting the loop makes sense. That way the loop actually runs.
	contPlaying = true;
#
#ifdef DEBUG_MODE
	//DEBUG
	int frames = 0;
#endif

	while (contPlaying) {

		//Print frame rate and frametime for testing purposes to make sure the delay is working properly.
#ifdef DEBUG_MODE
		frames++;
		cout << "Frame " << frames << "\n";
		cout << "FPS: " << 1000 / deltaTime.count() << "\n" << "Delta: " << deltaTime.count() << "\n" << "Pressed: " << input::getPressed() << "\n";
#endif
		//Ticks the current game state for logic updates.
		//Delta time is included so logic update rate can be independent of frame rate.
		state->tick(deltaTime.count());
		//Clear the screen to prepare for the next frame.
		display.clear();
		//Tells the game state to draw it's textures.
		state->render(&display);
		//Render display to the terminal.
		display.render();

		current = chrono::high_resolution_clock::now(); //Sets the current time to where we are after the frame.
		deltaTime = current - last; //Finds how much time has passed.

		//Find out how long we need to sleep for.
		sleepTime = frametime - deltaTime.count();
		if (sleepTime > 1) { //Make sure we are sleeping for at least 1 msec. ie. not 0 msecs.
			delay(sleepTime); //Just wait until we're ready for the next frame
		}

#ifdef DEBUG_MODE //This will allow accurate display of the current frame rate. But we just don't need it if we aren't debugging so lets improve performance instead.
		//Then continue on to the next frame.
		current = chrono::high_resolution_clock::now(); //Allows us to get accurate frame rate readings
		deltaTime = current - last; //Will be used for accurate fps calculation
#endif

		//Lastly set this current frame to the last frame and start over again.
		last = chrono::high_resolution_clock::now();

		//Allows the player to end the game by pressing q.
		if (input::getPressed() == 113) {
			contPlaying = false;
			//input::usedPress();
		}
	}
	input::listenThread.join();
}

//Simple to use delay method to enable cleaner code.
//Just calls the equivilant function of this_thread.
void game::delay(int mSec)
{
	this_thread::sleep_for(chrono::milliseconds(mSec));
}

//Gets the current running game state. Useful for when accessing the gameState from a gameObject.
GameState * game::getCurrentState()
{
	return state;
}
