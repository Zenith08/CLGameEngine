#pragma once
#include <GameState.h>
#include "Screen.h"
#include "GameObjectWall.h"
#include "SIPlayer.h"

class GSSpaceInvaders :
	public GameState
{
public:
	const int NUM_SHOTS = 32;
	int numShots = 0;
	GameObjectShot shots[NUM_SHOTS];

	GameObjectWall left1;
	GameObjectWall left2;
	GameObjectWall left3;
	GameObjectWall right1;
	GameObjectWall right2;
	GameObjectWall right3;

	SIPlayer player;

	GSSpaceInvaders();
	void tick(double delta);
	void render(Screen *display);
	void addShot(GameObjectShot shot);
};