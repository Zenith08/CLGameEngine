#pragma once
#include "GameObject.h"
//Actually used as a player class but renaming it will cause chaos in other files.
class GameObjectBall :
	public GameObject
{
public:
	//A default constructor to set up basics.
	GameObjectBall();
	//Allows updating movement and collision box position.
	void tick(double delta);
};

