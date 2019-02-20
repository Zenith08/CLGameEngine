#pragma once

#include <conio.h>
#include <thread>

namespace input {
	extern int lastKeypress;
	extern std::thread listenThread;

	int getPressed();
	void inputLoop();
}