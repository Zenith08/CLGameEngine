#include "GameInput.h"
#include <thread>
#include <iostream>

int input::lastKeypress = -1;
std::thread input::listenThread(inputLoop);

int input::getPressed() {
	if (lastKeypress != -1) {
		int output = lastKeypress;
		lastKeypress = -1;
		return output;
	}
	return -1;
}

void input::inputLoop()
{
	while (true) {
		lastKeypress = _getch();
	}
}
