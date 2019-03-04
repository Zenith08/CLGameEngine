#include "pch.h"
#include "GSSpaceInvaders.h"


GSSpaceInvaders::GSSpaceInvaders():GameState()
{
	GameObjectWall left1 = GameObjectWall(0, 0, 1, 5);
	GameObjectWall left2 = GameObjectWall(0, 5, 1, 5);
	GameObjectWall left3 = GameObjectWall(0, 10, 1, 5);
	GameObjectWall right1 = GameObjectWall(14, 0, 1, 5);
	GameObjectWall right2 = GameObjectWall(14, 5, 1, 5);
	GameObjectWall right3 = GameObjectWall(14, 10, 1, 5);

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
