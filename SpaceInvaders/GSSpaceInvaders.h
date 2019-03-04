#pragma once
#include <GameState.h>
#include "Screen.h"
#include "GameObjectWall.h"

class GSSpaceInvaders :
	public GameState
{
public:
	GameObjectWall left1;
	GameObjectWall left2;
	GameObjectWall left3;
	GameObjectWall right1;
	GameObjectWall right2;
	GameObjectWall right3;

	GSSpaceInvaders();
	void tick(double delta);
	void render(Screen *display);
};