#pragma once

#include "GameObject.h"

//Natural Language options for the object shooting a missile. Can be the player or space invader.
#define PLAYER true
#define INVADER false

//Represents a "missile" shot by either the player or a space invader.
class GameObjectShot : public GameObject
{
	int velocity; //The number of frames to wait before each movement.
	int wait; //The length of time to wait inbetween movement logic updates.
	bool shooter; //The object who fired this shot. Either a PLAYER or an INVADER

public:
	//A default constructor prevents errors.
	GameObjectShot();
	//Creates a Shot with a velocity, starting position, and shooter.
	//Params:
	//vel - the velocity of the missile.
	//initial - The starting position of this shot in a vector format. (x, y)
	//src - The source of the missile. Can be either a PLAYER or an INVADER.
	GameObjectShot(int vel, Vector2 initial, bool src);
	//Tick allows custom game logic to be executed by the shot.
	void tick(double delta);
	//Render allows custom rendering of the texture and is used to disable rendering in certain situations.
	void render(Screen *display);
};
