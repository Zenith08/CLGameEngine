#pragma once
#include "GameObject.h"

class GameObjectShot : public GameObject
{
	int velocity;
	int wait;

public:
	GameObjectShot();
	GameObjectShot(int vel, Vector2 initial);
	void tick(double delta);
	void render(Screen *display);
};

