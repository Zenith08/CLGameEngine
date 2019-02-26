#include "GameInput.h"
#include <thread>
#include <iostream>
#include "GameEngine.h"

int input::lastKeypress = -1;
std::thread input::listenThread(inputLoop);

int input::getPressed() {
	if (lastKeypress != -1) {
		return lastKeypress;
	}
	return -1;
}

void input::inputLoop()
{
	while (game::contPlaying) {
		if (lastKeypress != 113) {
			lastKeypress = _getch();
		}
	}
}

void input::usedPress()
{
	lastKeypress = -1;
}
