#pragma once
#include "GameObject.h"
//A procedural wall to be used for the game.
//Walls can be a maximum of 5x5 and will auto generate a collision box and a texture based on the provided dimensions in the constructor.
class GameObjectWall :
	public GameObject
{
public:
	//A default constructor to make it work properly with arrays and avoid null errors.
	GameObjectWall();
	//Initalizes a procedural wall with the arguments specified.
	//Inputs: x, y - The coordinates in 2D space of the wall.
	//width, height - The size of the wall in 2D space.
	//The constructor will automatically generate a texture and collision box.
	//These walls are not intended to move.
	GameObjectWall(int x, int y, int width, int height);
};

