#pragma once
#include "GameObject.h"
//Actually used as a player class but renaming it will cause chaos in other files.
//The "ball" (player) is capable of moving in all 4 directions and has an associated collision box.
//This is used in the dodgeball game.
class GameObjectBall :
	public GameObject
{
public:
	//A default constructor to set up basics.
	GameObjectBall();
	//Allows updating movement and collision box position.
	void tick(double delta);
};

