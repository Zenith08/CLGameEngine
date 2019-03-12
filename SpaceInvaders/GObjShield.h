#pragma once

#include <GameObject.h>
#include "Screen.h"

//A shield can be shot and can also be destroyed.
class GObjShield :
	public GameObject
{
	//How much damage the shield has. 3 is healthy, 2 is damaged, 1 is badly damaged, 0 is destroyed.
	int life = 3;
	//Texture is healthy shield
	//Damage1 is at life = 2.
	char damage1[5][5];
	//Damage2 is at life = 1.
	char damage2[5][5];
	//The location where the actor starts the game. Used to reset the game and respawn it to the previous location.
	Vector2 start;

public:
	//A default constructor.
	GObjShield();
	//Create a shield and assign it a position in the world.
	GObjShield(Vector2 initial);
	//Custom logic.
	void tick(double delta);
	//Custom rendering for damage states.
	void render(Screen *display);
	//Inflicts damage to the shield.
	//If the damage destroys the shield this will return true.
	bool damage();
	//Respawns the shield.
	void respawn();
	//If this returns true, the shield can block shots and take damage.
	bool living();
};

