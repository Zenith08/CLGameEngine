#include "GameObjectBall.h"
#include "GameInput.h"
#include "GameEngine.h"
#include <iostream>

GameObjectBall::GameObjectBall()
{
	GameObject::GameObject();
	//Now setup the rest of it.
	//Sets the entire texture to BLANK
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
	//Checks for movement keypresses and sees if they are allowable.
	//std::cout << "Ball recieved tick" << endl;
	if (input::getPressed() == 72) { //Up
		//Move the collision box to see if this movement is allowable.
		boundingBox.setCoordinates(boundingBox.x, boundingBox.y - 1);
		if (!game::getCurrentState()->overlapsStatic(this)) { //Then check if we collide with the static walls.
			//If we don't, then move the ball and indicate the button press has been used.
			position.y -= 1;
			input::usedPress();
		}
	} //This logic is repeated 4 times, one for each direction.
	else if (input::getPressed() == 80) { //Down
		//std::cout << "Key pressed \n";
		boundingBox.setCoordinates(boundingBox.x, boundingBox.y + 1);
		if (!game::getCurrentState()->overlapsStatic(this)) {
			//std::cout << "no collision" << endl;
			position.y += 1;
			input::usedPress();
		}
	}
	else if (input::getPressed() == 77) { //Left
		boundingBox.setCoordinates(boundingBox.x+1, boundingBox.y);
		if (!game::getCurrentState()->overlapsStatic(this)) {
			//std::cout << "no collision" << endl;
			position.x += 1;
			input::usedPress();
		}
	}
	else if (input::getPressed() == 75) { //Right
		boundingBox.setCoordinates(boundingBox.x-1, boundingBox.y);
		if (!game::getCurrentState()->overlapsStatic(this)) {
			//std::cout << "no collision" << endl;
			position.x -= 1;
			input::usedPress();
		}
	}

	GameObject::tick(delta);
}