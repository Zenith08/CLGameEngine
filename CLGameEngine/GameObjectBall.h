#pragma once
#include "GameObject.h"
class GameObjectBall :
	public GameObject
{
public:
	GameObjectBall();

	void tick(double delta);
};

