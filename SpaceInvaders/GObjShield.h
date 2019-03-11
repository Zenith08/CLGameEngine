#pragma once

#include <GameObject.h>
#include "Screen.h"

class GObjShield :
	public GameObject
{
	int life = 3;
	//Texture is healthy shield
	char damage1[5][5];
	char damage2[5][5];
	Vector2 start;

public:
	GObjShield();
	GObjShield(Vector2 initial);
	void tick(double delta);
	void render(Screen *display);
	bool damage();
	void respawn();
	bool living();
};

