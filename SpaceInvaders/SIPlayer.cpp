#include "pch.h"
#include "SIPlayer.h"
#include "GameInput.h"
#include "GameEngine.h"
#include "GSSpaceInvaders.h"
#include <iostream>

//A basic constructor is all we need.
SIPlayer::SIPlayer() : GameObject()
{
	//Define the texture.
	clearTexture();

	texture[0][0] = '/';
	texture[1][0] = '*';
	texture[2][0] = '\\';
	texture[0][1] = '|';
	texture[1][1] = '+';
	texture[2][1] = '|';

	//Sets the default position and collision box.
	position = { 6, 13 };
	boundingBox = CollisionBox(position.x, position.y, 3, 2);
}

//Moving and shooting.
void SIPlayer::tick(double delta)
{
	if (input::getPressed() == 77) { //If the player pressed the left arrow key
		boundingBox.setCoordinates(boundingBox.x + 1, boundingBox.y); //Try to move left
		if (!game::getCurrentState()->overlapsStatic(this)) { //If we don't hit a wall
			//Actually move left.
			position.x += 1;
			input::usedPress(); //Use press indicates we no longer need to factor this button next tick.
		}
	}
	else if (input::getPressed() == 75) { //If the player hit the right arrow
		boundingBox.setCoordinates(boundingBox.x - 1, boundingBox.y); //Try to move right
		if (!game::getCurrentState()->overlapsStatic(this)) { //If we don't hit a wall
			//Then move right
			position.x -= 1;
			input::usedPress(); //Use press indicates we no longer need to factor this button next tick.
		}
	}
	else if (input::getPressed() == 72) { //Up arrow, fire.
		//Get a refference to the Gamestate
		GSSpaceInvaders *stateInvaders = dynamic_cast<GSSpaceInvaders*>(game::getCurrentState());
		//Tell it to fire.
		stateInvaders->addShot(GameObjectShot(1, { position.x + 1, position.y }, PLAYER));
		input::usedPress(); //Use press indicates we no longer need to factor this button next tick.
	}
	GameObject::tick(delta); //Tick sets the collision box to the coordinates guaranteeing they are correct.
}

//Shown for clarity.
void SIPlayer::render(Screen * display)
{
	GameObject::render(display);
}

//Damages the player reducing life and checking if the player is dead.
bool SIPlayer::damage(int damage)
{
	life -= damage; //Reduce damage from life.
	if (life <= 0) { //If the damage kills the player
		return true; //Return true.
	}
	else {
		return false; //Otherwise return false.
	}
}

//Respawns the player setting it to the default position and resetting life.
void SIPlayer::respawn()
{
	//Reset life, move to known start posiiton.
	life = MAX_LIFE;
	position = { 6, 13 };
}

//Gets how much life the player currently has.
int SIPlayer::getLife()
{
	return life;
}
