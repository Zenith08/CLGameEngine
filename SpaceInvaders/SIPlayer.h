#pragma once

#include <GameObject.h>
#include "GameObjectShot.h"
#include "Screen.h"

#define MAX_LIFE 100

class SIPlayer :
	public GameObject
{
	int life = MAX_LIFE;
public:
	SIPlayer();

	void tick(double delta);
	void render(Screen *display);
	bool damage(int damage);
	void respawn();
	int getLife();
};

