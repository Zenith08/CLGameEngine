#include "GameObjectBall.h"



GameObjectBall::GameObjectBall()
{
	GameObject::GameObject();
	//Now setup the rest of it.
	texture[2][2] = '*';
	position = { 1, 1 };
	boundingBox = CollisionBox(1, 1, 1, 1);
}