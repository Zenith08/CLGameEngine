#pragma once
#include "GameObject.h"
class GameObjectDodgeball :
	public GameObject
{
public:
	GameObjectDodgeball();

	int timeTilMove = 3;
	Vector2 velocity;
	void tick(double delta);
};