#include "GameInput.h"
#include <thread>
#include <iostream>
#include "GameEngine.h"

//The last key the user pressed. -1 indicates nothing was pressed.
int input::lastKeypress = -1;
//A thread which can wait for a keypress and then notify the main thread.
std::thread input::listenThread(inputLoop);

//Allows the user program to get the last key the user pressed.
//Will be a key code if one was pressed or -1 otherwise.
int input::getPressed() {
	return lastKeypress;
}

//This method is where the listenThread starts and exists. This is how input is accepted without interrupting the main thread.
void input::inputLoop()
{
	while (game::contPlaying) { //When this is false, listenThread will exit the loop and return. The join() call in the main engine will then return indicating it is safe to exit the program.
		if (lastKeypress != 113) { //Key 113 is the keypress for Q. When this is pressed, this thread should not call _getch() and should instead be prepared to shutdown.
			lastKeypress = _getch(); //_getch() waits for a key to be pressed and then returns it as an int keycode. If the thread waits here after pressing Q another button would have to be pressed.
		}
	}
}
//Indicates that the key that was pressed has influenced the main program.
//Resetting this prevents the same key from firing each tick until another key is pressed giving more controll over game logic.
//As a side effect, each button press should only ever be processed once and therefore each key should only have one function at a time.
void input::usedPress()
{
	lastKeypress = -1;
}
