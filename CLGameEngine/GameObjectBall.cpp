#include "GameObjectBall.h"
#include "GameInput.h"
#include "GameEngine.h"
#include <iostream>

GameObjectBall::GameObjectBall()
{
	GameObject::GameObject();
	//Now setup the rest of it.
	for (int x = 0; x < 5; x++) {
		for (int y = 0; y < 5; y++) {
			texture[x][y] = ' ';
		}
	}

	texture[0][0] = '*';
	position = { 4, 4 };
	boundingBox = CollisionBox(1, 1, 1, 1);
}

void GameObjectBall::tick(double delta)
{
	//std::cout << "Ball recieved tick" << endl;
	std::cout << "Ball X " << position.x << " Y" << position.y << "\n";
	if (input::getPressed() == 72) { //Up
		boundingBox.setCoordinates(boundingBox.x, boundingBox.y - 1);
		if (!game::getCurrentState()->overlapsStatic(this)) {
			position.y -= 1;
			input::usedPress();
		}
	}
	else if (input::getPressed() == 80) {
		//std::cout << "Key pressed \n";
		boundingBox.setCoordinates(boundingBox.x, boundingBox.y + 1);
		if (!game::getCurrentState()->overlapsStatic(this)) {
			//std::cout << "no collision" << endl;
			position.y += 1;
			input::usedPress();
		}
	}
	else if (input::getPressed() == 77) {
		boundingBox.setCoordinates(boundingBox.x+1, boundingBox.y);
		if (!game::getCurrentState()->overlapsStatic(this)) {
			//std::cout << "no collision" << endl;
			position.x += 1;
			input::usedPress();
		}
	}
	else if (input::getPressed() == 75) {
		boundingBox.setCoordinates(boundingBox.x-1, boundingBox.y);
		if (!game::getCurrentState()->overlapsStatic(this)) {
			//std::cout << "no collision" << endl;
			position.x -= 1;
			input::usedPress();
		}
	}

	GameObject::tick(delta);
}