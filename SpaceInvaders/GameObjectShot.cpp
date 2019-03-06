#include "pch.h"
#include "GameObjectShot.h"
#include <iostream>


GameObjectShot::GameObjectShot()
{
	GameObjectShot(1, { -1, -1 });
}

GameObjectShot::GameObjectShot(int vel, Vector2 initial)
{
	clearTexture();
	texture[0][0] = '!';
	boundingBox = CollisionBox(initial.x, initial.y, 1, 1);
	velocity = vel;
	wait = vel;
	position.x = initial.x;
	position.y = initial.y;
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
			//Move up.
			position.y--;
		}

		GameObject::tick(delta);
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
