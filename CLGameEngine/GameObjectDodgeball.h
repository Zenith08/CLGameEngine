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
	double timeTilMove = 100;
	//The velocity the ball will move at stored as a 2 component vector.
	Vector2 velocity;
	//Overriding the tick allows custom movement and bouncing "physics".
	void tick(double delta);
	//Generates a random number between min and max. Not 100% random but close enough.
	int roll(int min, int max);
};