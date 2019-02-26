#include "GameObjectDodgeball.h"
#include "GameEngine.h"
#include <iostream>
#include <cstdlib>

GameObjectDodgeball::GameObjectDodgeball()
{
	for (int x = 0; x < 5; x++) {
		for (int y = 0; y < 5; y++) {
			texture[x][y] = ' ';
		}
	}

	texture[1][1] = '/';
	texture[2][1] = '-';
	texture[3][1] = '\\';
	
	texture[1][2] = '|';
	texture[2][2] = '@';
	texture[3][2] = '|';

	texture[1][3] = '\\';
	texture[2][3] = '-';
	texture[3][3] = '/';

	position = { 5, 5 };
	velocity = { 1, -1 };
	boundingBox = CollisionBox(1, 1, 3, 3);
}

void GameObjectDodgeball::tick(double delta)
{
	timeTilMove--;
	if (timeTilMove == 0) {
		boundingBox.setCoordinates(position.x + velocity.x + 1, position.y + velocity.y + 1);
		if (game::getCurrentState()->overlapsStatic(this)) {
			//Bounce
			velocity.x *= -1;
			velocity.y *= -1;
		}
		else {
			position.x += velocity.x;
			position.y += velocity.y;
		}
		//std::cout << "Dodgeball X " << position.x << " Y" << position.y << "\n";
		timeTilMove = 3;
	}
}