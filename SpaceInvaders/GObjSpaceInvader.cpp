#include "pch.h"
#include "GObjSpaceInvader.h"
#include "GameEngine.h"
#include "GSSpaceInvaders.h"
#include "GameObjectShot.h"
#include <iostream>
#include <stdlib.h>

//Create the invader and set defaults.
GObjSpaceInvader::GObjSpaceInvader(Vector2 initial)
{
	//Setup the base texture.
	clearTexture();
	texture[0][0] = '(';
	texture[1][0] = '-';
	texture[2][0] = ')';
	texture[0][1] = '|';
	texture[2][1] = '|';

	//Setup the other two textures.
	for (int x = 0; x < 5; x++) {
		for (int y = 0; y < 5; y++) {
			animL[x][y] = ' ';
		}
	}

	animL[0][0] = '(';
	animL[1][0] = '-';
	animL[2][0] = ')';
	animL[0][1] = '/';
	animL[2][1] = '/';

	for (int x = 0; x < 5; x++) {
		for (int y = 0; y < 5; y++) {
			animR[x][y] = ' ';
		}
	}

	animR[0][0] = '(';
	animR[1][0] = '-';
	animR[2][0] = ')';
	animR[0][1] = '\\';
	animR[2][1] = '\\';

	//Set default position, store our initial position, and set the bounding box.
	position = { initial.x, initial.y };
	start = { initial.x, initial.y };
	boundingBox = CollisionBox(position.x, position.y, 3, 2);
}

//Prevents errors.
GObjSpaceInvader::GObjSpaceInvader()
{
	GObjSpaceInvader({ -5, -5 });
}

//Allows movement and firing logic to run.
void GObjSpaceInvader::tick(double delta)
{
	//If we are dead none of this matters.
	if (alive) {
		//Time delay slows everything down.
		time--;
		if (time == 0) {
			time = delays;
			//Some quick animation handling.
			currentFrame++; //Moves to the next frame in the animation.
			if (currentFrame > 3) { //If we have run out of frames
				currentFrame = 0; //Reset to the begining.
			}

			//End animation stuff.

			//Starts movement logic.
			if (moveDirection == LEFT) { //If we are going left
				boundingBox.x--; //Try to move left
				if (game::getCurrentState()->overlapsStatic(this)) { //If we are hitting a wall
					position.y++; //Move down instead
					moveDirection = RIGHT; //And move the other way.
				}
				else { //If we can move left
					position.x--; //Then do it.
				}
			}
			else if (moveDirection == RIGHT) { //Equivilent to else{} but shows more clarity.
				boundingBox.x++; //Try to move right
				if (game::getCurrentState()->overlapsStatic(this)) { //If we are hitting a wall
					position.y++; //Move down instead
					moveDirection = LEFT; //And move the other way.
				}
				else { //If we can move left
					position.x++; //Then do it.
				}
			}
			//End movement logic

			//Starts shooting logic
			GSSpaceInvaders *stateInvaders = dynamic_cast<GSSpaceInvaders*>(game::getCurrentState());

			//Generate a random number between 0 and 99. If it is smaller than shooting, it will fire.
			//If this invader is over top of the player, the probability of shooting goes up by 8%
			if (std::rand() % 100 < (shooting + (stateInvaders->targetingPlayer(this) * 8))) {
				stateInvaders->addShot(GameObjectShot(1, { position.x + 1, position.y }, INVADER));
			}
		}
	}
	//Updates the bounding box coordinates to the current position.
	GameObject::tick(delta);
}

//Custom animations.
void GObjSpaceInvader::render(Screen * display)
{
	if (alive) { //If we're dead, don't render.
		if (currentFrame == 0 || currentFrame == 2) { //Having 2 conditions for the neutral frame avoids jumping from the left to the right frame.
			display->draw(texture, position.x, position.y);
		}
		else if (currentFrame == 1) { //The frame for the left animation.
			display->draw(animL, position.x, position.y);
		}
		else if (currentFrame == 3) { //The frame for the right animation.
			display->draw(animR, position.x, position.y);
		}
	}
}

//Are we alive? If so, this returns true.
bool GObjSpaceInvader::isLiving()
{
	return alive;
}

//Kills the invader and removes it.
void GObjSpaceInvader::kill()
{
	alive = false; //We're no longer alive.
	position.x = -5; //Effectivly kills the invader and removes it from the game.
	position.y = -5;
}

//Resets the invader and reinitalizes stuff.
void GObjSpaceInvader::respawn()
{
	//Sets the invader to it's initial posiion.
	position = { start.x, start.y };
	//We are now alive again.
	alive = true;
	//Move right by default.
	moveDirection = RIGHT;
	//Reset the animation loop.
	currentFrame = 1;
}
