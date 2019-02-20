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

using namespace Collisions;
using namespace std;

//The game loop is the main function where every frame state#tick and state#rendered will be called from the code.
//The loop will then wait until enough time has elapsed before calling a new frame such that the update rate = fps.
void gameLoop();
//A simple helper method which causes the thread to sleep for a given number of milliseconds.
void delay(int mSec);

//The number of updates per second the program will target. The game loop will sleep until at least this time passes between frames.
const double fps = 30.0;
//The number of milliseconds that must pass before a new frame is started. This is set in initialization and simply used for the delay method.
const double frametime = 1000.0 / fps;

//The current game state to run. It will recieve updates from the engine at the number of fps.
GameStateJump jumper = GameStateJump();
GameStateJump *state = &jumper;
//The screen for the game to be rendered to. The screen has the ability to be drawn to and redrawn each frame.
Screen display = Screen();

//This is for testing or built in game states. In theory, a user would have their own main() method to run and simply call gameLoop() in this class.
int main(int argc, const char * argv[]) {
	// insert code here...
	std::cout << "Hello, World!\n"; //A good check if the program has even started.
	//Makes sure the display is blank. Serves as an initializer.
	display.clear();
	//Defines a texture for testing purposes.
	char cTex[5][5] = { {'a', 'a', 'a', 'a', 'a'},
		{'a', 'a', 'a', 'a', 'a'},
		{'a', 'a', 'a', 'a', 'a'},
		{'a', 'a', 'a', 'a', 'a'},
		{'a', 'a', 'a', 'a', 'a'} };

	//Draws the test texture to the screen. See display#draw()
	display.draw(cTex, 6, 14);
	//Defines a second test texture.
	char cTexB[5][5] = { {'b', 'b', 'b', 'b', 'b'},
		{'b', 'b', 'b', 'b', 'b'},
		{'b', 'b', 'b', 'b', 'b'},
		{'b', 'b', 'b', 'b', 'b'},
		{'b', 'b', 'b', 'b', 'b'} };
	//Part of debug code. Draws the second texture to the screen.
	display.draw(cTexB, 12, 7);
	//Renders the screen. See screen#render()
	display.render();
	cout << "Render";
	//Starts the main game loop with whatever game state has been configured.
	gameLoop();
	//Has to be there but currently doesn't run.
	return 0;
}

void gameLoop() {
	//Initalize time variables used to maintain consistent frame rates.
	chrono::high_resolution_clock::time_point current; //What time is it now?
	chrono::high_resolution_clock::time_point last; //What time was it last frame?
	chrono::duration<double, milli> deltaTime; //What is the difference in time between now and last frame?

	current = chrono::high_resolution_clock::now(); //Sets the current time to be equal to this time.
	last = chrono::high_resolution_clock::now(); //Initializes the time of last frame to now. Just to have a base value, it should not matter.
	deltaTime = current - last; //Initializes delta time, should not matter.

	while (true) {
		//Print frame rate and frametime for testing purposes to make sure the delay is working properly.
		cout << "FPS: " << 1000 / deltaTime.count() << "\n";
		cout << "Delta: " << deltaTime.count() << "\n";
		cout << "Pressed: " << input::getPressed() << "\n";

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
	}
}

//Waits for a specific number of milliseconds.
void delay(int mSec) {
	this_thread::sleep_for(chrono::milliseconds(mSec));
}
