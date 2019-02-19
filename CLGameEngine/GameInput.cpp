#include "GameInput.h"

int input::getPressed() {
	return _kbhit();
}