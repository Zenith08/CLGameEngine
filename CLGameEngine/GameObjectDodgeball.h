#pragma once
#include "GameObject.h"
//The Dodgeball object for the player to avoid.
class GameObjectDodgeball :
	public GameObject
{
public:
	//A constructor to initialize basic variables and the texture.
	GameObjectDodgeball();
	//Slows the ball down by only moving it once every 3rd frame. Might be adjusted for gameplay balance.
	int timeTilMove = 3;
	//The velocity the ball will move at stored as a 2 component vector.
	Vector2 velocity;
	//Overriding the tick allows custom movement and bouncing "physics".
	void tick(double delta);
};