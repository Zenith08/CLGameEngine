#include "GameObjectDodgeball.h"
#include "GameEngine.h"
#include <iostream>
#include <cstdlib>

GameObjectDodgeball::GameObjectDodgeball()
{
	//A rither  painful way to configure the texture.
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

	//Set an initial position, velocity, and create the bounding box for collisions.
	position = { 5, 5 };
	velocity = { 1, -1 };
	boundingBox = CollisionBox(1, 1, 3, 3);
}

void GameObjectDodgeball::tick(double delta)
{
	timeTilMove--; //Slows the ball down by not moving each frame.
	if (timeTilMove == 0) { //Indicates it is a movement frame.
		boundingBox.setCoordinates(position.x + velocity.x + 1, position.y + velocity.y + 1); //Move the collider to check the new coords.
		if (game::getCurrentState()->overlapsStatic(this)) { //Check if the new position overlaps a static collider.
			//If we are overlapping, change the velocity to a new velocity.
			velocity.x *= -1;
			velocity.y *= -1;
			//Reset the bounding box coordinates to the actual position.
			boundingBox.setCoordinates(position.x + 1, position.y + 1);
		}
		else { //If this calls we are able to make the move. Changes the balls coordinates.
			position.x += velocity.x;
			position.y += velocity.y;
		}
		//std::cout << "Dodgeball X " << position.x << " Y" << position.y << "\n";
		timeTilMove = 3; //Resets the frame count until the next movement.
	}
}
