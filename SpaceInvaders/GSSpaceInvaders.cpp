#include "pch.h"
#include "GSSpaceInvaders.h"


GSSpaceInvaders::GSSpaceInvaders():GameState()
{
	left1 = GameObjectWall(0, 0, 1, 5);
	left2 = GameObjectWall(0, 5, 1, 5);
	left3 = GameObjectWall(0, 10, 1, 5);
	right1 = GameObjectWall(14, 0, 1, 5);
	right2 = GameObjectWall(14, 5, 1, 5);
	right3 = GameObjectWall(14, 10, 1, 5);

	addStaticCollider(&left1);
	addStaticCollider(&left2);
	addStaticCollider(&left3);
	addStaticCollider(&right1);
	addStaticCollider(&right2);
	addStaticCollider(&right3);
}

void GSSpaceInvaders::tick(double delta)
{
	GameState::tick(delta);
}

void GSSpaceInvaders::render(Screen * display)
{
	GameState::render(display);
}
