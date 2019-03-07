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
	
	for (int y = 0; y < 3; y++) {
		for (int x = 0; x < 4; x++) { //This loops 12 times and places 4 invaders on three rows.
			invaders[y * 4 + x] = GObjSpaceInvader( {1+x*3, y*2} );
			activeInvaders[y * 4 + x] = &invaders[y * 4 + x];
			addGameObject(&invaders[y * 4 + x]);
		}
	}
}

void GSSpaceInvaders::tick(double delta)
{
	if (playerState == ALIVE) {
		for (int i = 0; i < NUM_SHOTS; i++) {
			if (activeShots[i]) {
				activeShots[i]->tick(delta);
			}
		}

		//Check if an invader has reached the end.
		for (int i = 0; i < NUM_INVADERS; i++) {
			if (activeInvaders[i]) {
				//cout << "Invader position " << activeInvaders[i]->position.y << " and living = " << activeInvaders[i]->isLiving() << "\n";
				if (activeInvaders[i]->isLiving() && activeInvaders[i]->position.y >= 12) {
					playerState = DEAD;
				}
			}
		}
		GameState::tick(delta);
	}
}

void GSSpaceInvaders::render(Screen * display)
{
	for (int i = 0; i < NUM_SHOTS; i++) {
		if (activeShots[i]) {
			activeShots[i]->render(display);
		}
	}
	GameState::render(display);

	if (playerState == DEAD) {
		display->drawString("Game Over!", 3, 3);
	}
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

bool GSSpaceInvaders::collideInvaders(GameObjectShot *shot)
{
	for (int i = 0; i < NUM_INVADERS; i++) {
		if (activeInvaders[i]) {
			if (activeInvaders[i]->isLiving()) {
				if (Collisions::overlapping(activeInvaders[i]->boundingBox, shot->boundingBox)) {
					activeInvaders[i]->kill();
					return true;
				}
			}
		}
	}
	return false;
}


