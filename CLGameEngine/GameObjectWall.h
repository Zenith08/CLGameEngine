#pragma once
#include "GameObject.h"
//A procedural wall to be used for the game.
class GameObjectWall :
	public GameObject
{
public:
	GameObjectWall();
	GameObjectWall(int x, int y, int width, int height);
};

