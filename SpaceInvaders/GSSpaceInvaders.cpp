#include "pch.h"
#include "GSSpaceInvaders.h"
#include "GameInput.h"
#include <iostream>
#include <sstream>

GSSpaceInvaders::GSSpaceInvaders():GameState()
{
	left1 = GameObjectWall(0, 0, 1, 5);
	left2 = GameObjectWall(0, 5, 1, 5);
	left3 = GameObjectWall(0, 10, 1, 5);
	right1 = GameObjectWall(14, 0, 1, 5);
	right2 = GameObjectWall(14, 5, 1, 5);
	right3 = GameObjectWall(14, 10, 1, 5);

	shield1 = GObjShield({ 1, 11 });
	shields[0] = &shield1;
	shield2 = GObjShield({ 6, 11 });
	shields[1] = &shield2;
	shield3 = GObjShield({ 11, 11 });
	shields[2] = &shield3;

	addStaticCollider(&shield1);
	addStaticCollider(&shield2);
	addStaticCollider(&shield3);

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
			invaders[y * 4 + x] = GObjSpaceInvader({ 1 + x * 3, y * 2 });
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
		//Also checks if the player wins. ie. all invaders are dead.
		int aliveInvaders = 0;
		for (int i = 0; i < NUM_INVADERS; i++) {
			if (activeInvaders[i]) {
				//cout << "Invader position " << activeInvaders[i]->position.y << " and living = " << activeInvaders[i]->isLiving() << "\n";
				if (activeInvaders[i]->isLiving()) {
					aliveInvaders++;
					if (activeInvaders[i]->position.y >= 12) {
						playerState = DEAD;
					}
				}
			}
		}

		if (aliveInvaders == 0) {
			playerState = WIN;
		}

		GameState::tick(delta);

	}
	else if (playerState == DEAD || playerState == WIN) {
		if (input::getPressed() == 112) {
			//Reset the game
			reset();
		}
	}
}

void GSSpaceInvaders::render(Screen * display)
{
	if (flashFrame >= 0) {
		flashFrame--;
		for (int i = 0; i < 14; i++) {
			display->drawString("XXXXXXXXXXXXXXX", 0, i);
		}
	}

	GameState::render(display);

	for (int i = 0; i < NUM_SHOTS; i++) {
		if (activeShots[i]) {
			activeShots[i]->render(display);
		}
	}

	if (playerState == DEAD) {
		display->drawString("Game Over!", 3, 3);
		display->drawString("Press P", 4, 4);
		display->drawString("To play again.", 0, 5);
	}
	else if (playerState == WIN) {
		display->drawString("You Win!", 3, 3);
		display->drawString("Press P", 4, 4);
		display->drawString("To play again.", 0, 5);
	}

	std::stringstream ss;
	ss << "Life: ";
	ss << player.getLife();

	display->drawString(ss.str(), 1, 0);
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

bool GSSpaceInvaders::collidePlayer(GameObjectShot * shot)
{
	if (Collisions::overlapping(shot->boundingBox, player.boundingBox) == true) {
		if (player.damage(25)) {
			playerState = DEAD;
		}
		flashFrame = 5;
		return true;
	}
	else {
		return false;
	}
}

bool GSSpaceInvaders::collideShield(GameObjectShot * shot)
{
	for (int i = 0; i < 3; i++) {
		if (shields[i]) {
			if (shields[i]->living()) {
				if (Collisions::overlapping(shields[i]->boundingBox, shot->boundingBox)) {
					shields[i]->damage();
					return true;
				}
			}
		}
	}
	return false;
}

bool GSSpaceInvaders::targetingPlayer(GObjSpaceInvader * invader)
{
	if (invader->boundingBox.x < player.boundingBox.getRightEdge() && player.boundingBox.getRightEdge() > invader->boundingBox.x) {
		return true;
	}
	else {
		return false;
	}
}

void GSSpaceInvaders::reset()
{
	for (int i = 0; i < NUM_INVADERS; i++) {
		if (activeInvaders[i]) {
			activeInvaders[i]->respawn();
		}
	}
	for (int i = 0; i < 3; i++) {
		if (shields[i]) {
			shields[i]->respawn();
		}
	}
	player.respawn();
	playerState = ALIVE;
}
