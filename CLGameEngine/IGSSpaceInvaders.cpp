#include <iostream>
#include "IGSSpaceInvaders.h"

using namespace std;

IGSSpaceInvaders::IGSSpaceInvaders() : GameState()
{
	cout << "Constructor \n";
	GameObjectWall left1 = GameObjectWall(0, 0, 1, 5);
	GameObjectWall left2 = GameObjectWall(0, 5, 1, 5);
	GameObjectWall left3 = GameObjectWall(0, 10, 1, 5);
	GameObjectWall right1 = GameObjectWall(14, 0, 1, 5);
	GameObjectWall right2 = GameObjectWall(14, 5, 1, 5);
	GameObjectWall right3 = GameObjectWall(14, 10, 1, 5);
	cout << "Walls created \n";
	addStaticCollider(&left1);
	addStaticCollider(&left2);
	addStaticCollider(&left3);
	addStaticCollider(&right1);
	addStaticCollider(&right2);
	addStaticCollider(&right3);
	cout << "Added to colliders \n";
}

void IGSSpaceInvaders::tick(double delta)
{
	GameState::tick(delta);
}

void IGSSpaceInvaders::render(Screen * display)
{
	GameState::render(display);
}
