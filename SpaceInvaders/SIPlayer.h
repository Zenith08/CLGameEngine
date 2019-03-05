#pragma once
#include <GameObject.h>
#include "GameObjectShot.h"
#include "Screen.h"

class SIPlayer :
	public GameObject
{
public:
	SIPlayer();

	void tick(double delta);
	void render(Screen *display);
};

