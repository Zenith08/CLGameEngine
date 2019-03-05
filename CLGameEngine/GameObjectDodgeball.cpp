#include "GameObjectDodgeball.h"
#include "GameEngine.h"
#include <iostream>
#include <cstdlib>

GameObjectDodgeball::GameObjectDodgeball()
{
	GameObjectDodgeball(false);
}

GameObjectDodgeball::GameObjectDodgeball(bool easy)
{
	//A rither  painful way to configure the texture.
	for (int x = 0; x < 5; x++) {
		for (int y = 0; y < 5; y++) {
			texture[x][y] = ' ';
		}
	}

	if (easy) { //Easy Mode
		texture[0][0] = '/';
		texture[1][0] = '\\';
		texture[0][1] = '\\';
		texture[1][1] = '/';

		position = { 5, 5 };
		velocity = { 1, -1 };
		boundingBox = CollisionBox(position.x, position.y, 2, 2);
	}
	else { //Hard Mode.
		texture[0][0] = '/';
		texture[1][0] = '-';
		texture[2][0] = '\\';

		texture[0][1] = '|';
		texture[1][1] = '@';
		texture[2][1] = '|';

		texture[0][2] = '\\';
		texture[1][2] = '-';
		texture[2][2] = '/';
		boundingBox = CollisionBox(position.x, position.y, 3, 3);
	}

	//Common for both modes.
	//Set an initial position, velocity, and create the bounding box for collisions.
	position = { 5, 5 };
	velocity = { 1, -1 };
}

void GameObjectDodgeball::tick(double delta)
{
	//cout << "VelX = " << velocity.x << " vely " << velocity.y << "\n";
	timeTilMove-=delta; //Slows the ball down by not moving each frame.
	if (timeTilMove <= 0) { //Indicates it is a movement frame.
		boundingBox.setCoordinates(position.x + velocity.x, position.y + velocity.y); //Move the collider to check the new coords.
		if (game::getCurrentState()->overlapsStatic(this)) { //Check if the new position overlaps a static collider.
			//If we are overlapping, change the velocity to a new velocity.
			//Simulate possibilities to see what will work.
			if (velocity.x > 0) {
				velocity.x = roll(-2, 0);
				if (velocity.x == 0) {
					velocity.y = roll(-2, 2);
				}
			}
			else if (velocity.x < 0) {
				velocity.x = roll(0, 2);
				if (velocity.x == 0) {
					velocity.y = roll(-2, 2);
				}
			}
			if (velocity.y > 0) {
				velocity.y = roll(-2, 0);
				if (velocity.y == 0) {
					velocity.x = roll(-2, 2);
				}
			}
			else if (velocity.y < 0) {
				velocity.y = roll(0, 2);
				if (velocity.y == 0) {
					velocity.x = roll(-2, 2);
				}
			}

			while (velocity.x == 0 && velocity.y == 0) {
				velocity.x = roll(-2, 2);
				velocity.y = roll(-2, 2);
			}
		}
		else { //If this calls we are able to make the move. Changes the balls coordinates.
			position.x += velocity.x;
			position.y += velocity.y;
		}
		//std::cout << "Dodgeball X " << position.x << " Y" << position.y << "\n";
		timeTilMove = 100; //Resets the frame count until the next movement.
	}
	GameObject::tick(delta);
}

//https://stackoverflow.com/questions/5891811/generate-random-number-between-1-and-3-in-c
int GameObjectDodgeball::roll(int min, int max)
{
	// x is in [0,1[
	double x = rand() / static_cast<double>(RAND_MAX + 1);
	double minBuff = min;
	double maxBuff = max;

	// [0,1[ * (max - min) + min is in [min,max[
	int that = min + static_cast<int>(x * (maxBuff - minBuff));

	return that;
}
