#include "pch.h"
#include "GameObjectShot.h"
#include "GSSpaceInvaders.h"
#include "GameEngine.h"
#include <iostream>


GameObjectShot::GameObjectShot()
{
	GameObjectShot(1, { -1, -1 }, PLAYER);
}

GameObjectShot::GameObjectShot(int vel, Vector2 initial, bool src)
{
	clearTexture();

	if (src == PLAYER) {
		texture[0][0] = '!';
	}
	else if (src == INVADER) {
		texture[0][0] = '*';
	}

	boundingBox = CollisionBox(initial.x, initial.y, 1, 1);
	velocity = vel;
	wait = vel;
	position.x = initial.x;
	position.y = initial.y;
	shooter = src;
}

void GameObjectShot::tick(double delta)
{
	if (position.x < 0) {
		//Don't render
	}
	else { //Tick normally
		wait--;
		if (wait <= 0) {
			wait = velocity;
			if (shooter == PLAYER) {
				//Move up.
				position.y--;
			}
			else if (shooter == INVADER) {
				//Move down
				position.y++;
			}
		}

		GameObject::tick(delta); //Moves collision box.

		if (shooter == PLAYER) {
			GSSpaceInvaders *stateInvaders = dynamic_cast<GSSpaceInvaders*>(game::getCurrentState());

			if (stateInvaders->collideInvaders(this)) {
				position.y = -1; //Effectivly kills this shot.
			}
		}
		else if (shooter == INVADER) {
			GSSpaceInvaders *stateInvaders = dynamic_cast<GSSpaceInvaders*>(game::getCurrentState());

			if (stateInvaders->collidePlayer(this)) {
				position.y = 15; //Effectivly kills this shot.
			}
		}
	}
}

void GameObjectShot::render(Screen * display)
{
	if (position.x < 0) {
		//Don't render
	}
	else { //Do render.
		GameObject::render(display);
	}
}
