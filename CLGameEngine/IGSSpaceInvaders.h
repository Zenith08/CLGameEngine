#pragma once

#include "GameObjectWall.h"
#include "GameState.h"

class IGSSpaceInvaders : public GameState
{
public:
	GameObjectWall left1;
	GameObjectWall left2;
	GameObjectWall left3;
	GameObjectWall right1;
	GameObjectWall right2;
	GameObjectWall right3;

	IGSSpaceInvaders();

	void tick(double delta);
	void render(Screen *display);
};