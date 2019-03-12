#include "pch.h"
#include "GameObjectShot.h"
#include "GSSpaceInvaders.h"
#include "GameEngine.h"
#include <iostream>

//Default constructor creates a shot with default properties.
GameObjectShot::GameObjectShot()
{
	GameObjectShot(1, { -1, -1 }, PLAYER);
}

//Create a shot with a velocity, position, and shooter.
GameObjectShot::GameObjectShot(int vel, Vector2 initial, bool src)
{
	//Wipe the texture to start with a clean slate.
	clearTexture();

	//Changes the texture based on who is shooting.
	//This makes a player's shot appear as ! and an invaders shot appear as *.
	if (src == PLAYER) {
		texture[0][0] = '!';
	}
	else if (src == INVADER) {
		texture[0][0] = '*';
	}

	//Setup the default CollisionBox
	boundingBox = CollisionBox(initial.x, initial.y, 1, 1);
	//Setting default variables and values.
	velocity = vel;
	wait = vel;
	position.x = initial.x;
	position.y = initial.y;
	shooter = src;
}

void GameObjectShot::tick(double delta)
{
	if (position.x < 0) { //This allows the object to be easily disabled. by setting it's x coordinate off screen.
		//Don't tick
	}
	else { //Tick normally
		//Allows an easy way to slow down how fast a shot moves.
		wait--; //Decrement our timer.
		if (wait <= 0) { //If our timer is 0,
			wait = velocity; //Set it up to run again.
			if (shooter == PLAYER) { //If the player fired this shot, 
				//Move up towards the invaders.
				position.y--;
			}
			else if (shooter == INVADER) { //If the invaders fired this shot
				//Move down towards the player.
				position.y++;
			}
		}

		GameObject::tick(delta); //Moves collision box to match movement.

		//Regardless of who shot it a shot can still damage a shield.
		//Gets a gameState instance for Space Invaders allowing easy access to other game objects.
		GSSpaceInvaders *stateInvaders = dynamic_cast<GSSpaceInvaders*>(game::getCurrentState());

		//If this shot hits a shield
		if (stateInvaders->collideShield(this)) {
			//Then remove it from existance.
			position.x = -1;
			position.y = -1; //Effectivly kills this shot.
		}

		if (shooter == PLAYER) { //This check prevents players from hitting themselves or invaders from hitting each other.
			if (stateInvaders->collideInvaders(this)) { //If we are colliding with an invader:
				position.x = -1;
				position.y = -1; //Effectivly kills this shot.
			}
		}
		else if (shooter == INVADER) {
			if (stateInvaders->collidePlayer(this)) { //If we are colliding with the player:
				position.x = -1;
				position.y = 15; //Effectivly kills this shot.
			}
		}
	}
}

void GameObjectShot::render(Screen * display)
{
	if (position.x < 0) { //Allows easy disabling of the shot by simply setting x to be smaller than 0.
		//Don't render
	}
	else { //Do render.
		GameObject::render(display);
	}
}
