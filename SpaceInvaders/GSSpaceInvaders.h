#pragma once
#include <GameState.h>
#include "Screen.h"
#include "GameObjectWall.h"
#include "SIPlayer.h"
#include "GObjSpaceInvader.h"

#define NUM_SHOTS 32
#define NUM_INVADERS 12
#define ALIVE 0
#define DEAD 1

class GSSpaceInvaders :
	public GameState
{
public:
	int numShots = 0;
	int playerState = ALIVE;

	GameObjectShot shots[NUM_SHOTS] = {};
	GameObjectShot *activeShots[NUM_SHOTS] = {};

	GObjSpaceInvader invaders[NUM_INVADERS] = {};
	GObjSpaceInvader *activeInvaders[NUM_INVADERS] = {};

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
	bool collideInvaders(GameObjectShot *shot);
};
