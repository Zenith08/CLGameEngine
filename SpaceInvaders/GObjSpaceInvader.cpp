#include "pch.h"
#include "GObjSpaceInvader.h"
#include "GameEngine.h"
#include "GSSpaceInvaders.h"
#include "GameObjectShot.h"
#include <iostream>
#include <stdlib.h>

GObjSpaceInvader::GObjSpaceInvader(Vector2 initial)
{
	clearTexture();
	texture[0][0] = '(';
	texture[1][0] = '-';
	texture[2][0] = ')';
	texture[0][1] = '|';
	texture[2][1] = '|';

	for (int x = 0; x < 5; x++) {
		for (int y = 0; y < 5; y++) {
			animL[x][y] = ' ';
		}
	}

	animL[0][0] = '(';
	animL[1][0] = '-';
	animL[2][0] = ')';
	animL[0][1] = '/';
	animL[2][1] = '/';

	for (int x = 0; x < 5; x++) {
		for (int y = 0; y < 5; y++) {
			animR[x][y] = ' ';
		}
	}

	animR[0][0] = '(';
	animR[1][0] = '-';
	animR[2][0] = ')';
	animR[0][1] = '\\';
	animR[2][1] = '\\';

	position = { initial.x, initial.y };
	start = { initial.x, initial.y };
	boundingBox = CollisionBox(position.x, position.y, 3, 2);
}

GObjSpaceInvader::GObjSpaceInvader()
{
	GObjSpaceInvader({ -5, -5 });
}

void GObjSpaceInvader::tick(double delta)
{
	//If we are dead none of this matters.
	if (alive) {
		//Time delay slows everything down.
		time--;
		if (time == 0) {
			time = delays;
			//Some quick animation handling.
			currentFrame++;
			if (currentFrame > 3) {
				currentFrame = 0;
			}

			//End animation stuff.

			//Starts movement logic.
			if (moveDirection == LEFT) { //If we are going left
				boundingBox.x--; //Try to move left
				if (game::getCurrentState()->overlapsStatic(this)) { //If we are hitting a wall
					position.y++; //Move down instead
					moveDirection = RIGHT; //And move the other way.
				}
				else { //If we can move left
					position.x--; //Then do it.
				}
			}
			else if (moveDirection == RIGHT) { //Equivilent to else{} but shows more clarity.
				boundingBox.x++; //Try to move right
				if (game::getCurrentState()->overlapsStatic(this)) { //If we are hitting a wall
					position.y++; //Move down instead
					moveDirection = LEFT; //And move the other way.
				}
				else { //If we can move left
					position.x++; //Then do it.
				}
			}
			//End movement logic

			//Starts shooting logic
			GSSpaceInvaders *stateInvaders = dynamic_cast<GSSpaceInvaders*>(game::getCurrentState());

			if (std::rand() % 100 < (shooting + (stateInvaders->targetingPlayer(this) * 8))) {
				stateInvaders->addShot(GameObjectShot(1, { position.x + 1, position.y }, INVADER));
			}
		}
	}
	//Updates the bounding box coordinates to the current position.
	GameObject::tick(delta);
}

void GObjSpaceInvader::render(Screen * display)
{
	if (alive) {
		if (currentFrame == 0 || currentFrame == 2) {
			display->draw(texture, position.x, position.y);
		}
		else if (currentFrame == 1) {
			display->draw(animL, position.x, position.y);
		}
		else if (currentFrame == 3) {
			display->draw(animR, position.x, position.y);
		}
	}
}

bool GObjSpaceInvader::isLiving()
{
	return alive;
}

void GObjSpaceInvader::kill()
{
	alive = false;
	position.x = -5;
	position.y = -5;
}

void GObjSpaceInvader::respawn()
{
	position = { start.x, start.y };
	alive = true;
	moveDirection = RIGHT;
	currentFrame = 1;
}
