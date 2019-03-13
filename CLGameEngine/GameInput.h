#pragma once

#include <conio.h>
#include <thread>

namespace input {
	//The last key the user pressed.
	//Should be accessed by getPressed(), used to escape threading issues.
	extern int lastKeypress;
	//The thread which will listen on _getch() without interrupting the main game.
	extern std::thread listenThread;

	//Returns the last key that was pressed or -1 if the key has been used already.
	int getPressed();
	//The loop which the extra thread will execute on. Should not be called... Ever.
	void inputLoop();
	//Indicates the last press has been processed and should now be removed so that it is not calculated again each frame until the keypress changes.
	void usedPress();
}
