#pragma once
#include "GameObject.h"

#define PLAYER true
#define INVADER false

class GameObjectShot : public GameObject
{
	int velocity;
	int wait;
	bool shooter;

public:
	GameObjectShot();
	GameObjectShot(int vel, Vector2 initial, bool src);
	void tick(double delta);
	void render(Screen *display);
};

