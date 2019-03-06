#include "pch.h"
#include "GSSpaceInvaders.h"
#include <iostream>

GSSpaceInvaders::GSSpaceInvaders():GameState()
{
	left1 = GameObjectWall(0, 0, 1, 5);
	left2 = GameObjectWall(0, 5, 1, 5);
	left3 = GameObjectWall(0, 10, 1, 5);
	right1 = GameObjectWall(14, 0, 1, 5);
	right2 = GameObjectWall(14, 5, 1, 5);
	right3 = GameObjectWall(14, 10, 1, 5);

	player = SIPlayer();

	addStaticCollider(&left1);
	addStaticCollider(&left2);
	addStaticCollider(&left3);
	addStaticCollider(&right1);
	addStaticCollider(&right2);
	addStaticCollider(&right3);

	addGameObject(&player);

	testInvader = GObjSpaceInvader();
	addGameObject(&testInvader);
}

void GSSpaceInvaders::tick(double delta)
{
	for (int i = 0; i < NUM_SHOTS; i++) {
		if (activeShots[i]) {
			activeShots[i]->tick(delta);
		}
	}
	GameState::tick(delta);
}

void GSSpaceInvaders::render(Screen * display)
{
	for (int i = 0; i < NUM_SHOTS; i++) {
		if (activeShots[i]) {
			activeShots[i]->render(display);
		}
	}
	GameState::render(display);
}

void GSSpaceInvaders::addShot(GameObjectShot shot)
{
	shots[numShots] = shot;
	activeShots[numShots] = &shots[numShots];
	numShots++;
	if (numShots >= NUM_SHOTS) {
		numShots = 0;
	}
}


