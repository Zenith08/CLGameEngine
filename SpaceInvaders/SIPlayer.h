#pragma once

#include <GameObject.h>
#include "GameObjectShot.h"
#include "Screen.h"

//The player starts with 100 life. Makes changing this easy.
#define MAX_LIFE 100

//The player is controlled by a user and can move and shoot.
class SIPlayer :
	public GameObject
{
	//Start with the max ammount of life.
	int life = MAX_LIFE;
public:
	//Default constructor is all we need. We know the conditions of the player each game. It's always the same.
	SIPlayer();

	//Moving and shooting.
	void tick(double delta);
	//Draws the player to the screen.
	void render(Screen *display);
	//Damages the player.
	//Returns true if the damage kills the player.
	bool damage(int damage);
	//Respawns the player and resets its position.
	void respawn();
	//Returns the ammount of life the player currently has.
	int getLife();
};
