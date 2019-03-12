#include "pch.h"
#include "GSSpaceInvaders.h"
#include "GameInput.h"
#include <iostream>
#include <sstream>

//Default constructor is all we need. Nothing is going to change.
GSSpaceInvaders::GSSpaceInvaders():GameState()
{
	//Set up all of the basic game objects.
	left1 = GameObjectWall(0, 0, 1, 5);
	left2 = GameObjectWall(0, 5, 1, 5);
	left3 = GameObjectWall(0, 10, 1, 5);
	right1 = GameObjectWall(14, 0, 1, 5);
	right2 = GameObjectWall(14, 5, 1, 5);
	right3 = GameObjectWall(14, 10, 1, 5);

	shield1 = GObjShield({ 1, 11 });
	shields[0] = &shield1;
	shield2 = GObjShield({ 6, 11 });
	shields[1] = &shield2;
	shield3 = GObjShield({ 11, 11 });
	shields[2] = &shield3;

	//Also add them to the game.
	addStaticCollider(&shield1);
	addStaticCollider(&shield2);
	addStaticCollider(&shield3);

	//Create a player.
	player = SIPlayer();

	//Add the walls to the game
	addStaticCollider(&left1);
	addStaticCollider(&left2);
	addStaticCollider(&left3);
	addStaticCollider(&right1);
	addStaticCollider(&right2);
	addStaticCollider(&right3);

	//Add the player to the game.
	addGameObject(&player);

	//Create and setup the space invaders. They are handled independently of normal game objects.
	for (int y = 0; y < 3; y++) {
		for (int x = 0; x < 4; x++) { //This loops 12 times and places 4 invaders on three rows.
			invaders[y * 4 + x] = GObjSpaceInvader({ 1 + x * 3, y * 2 });
			activeInvaders[y * 4 + x] = &invaders[y * 4 + x];
			addGameObject(&invaders[y * 4 + x]);
		}
	}
}

//Logic and stuff
void GSSpaceInvaders::tick(double delta)
{
	if (playerState == ALIVE) { //If the game is running normally
		for (int i = 0; i < NUM_SHOTS; i++) { //Update each shot by calling tick.
			if (activeShots[i]) { //Check if the shot is null
				activeShots[i]->tick(delta); //Then tick it.
			}
		}

		//Check if an invader has reached the end.
		//Also checks if the player wins. ie. all invaders are dead.
		int aliveInvaders = 0;
		for (int i = 0; i < NUM_INVADERS; i++) { //For each of the invaders
			if (activeInvaders[i]) { //Check if it is null
				if (activeInvaders[i]->isLiving()) { //Also check if it is alive
					aliveInvaders++; //If this is never called, all the invaders are dead and the player wins.
					if (activeInvaders[i]->position.y >= 12) { //If an invader has made it to the player, the player loses.
						playerState = DEAD; //Setting the state to dead tells the rest of the program to stop and display the dead message.
					}
				}
			}
		}

		if (aliveInvaders == 0) { //If none of the invaders were alive earlier in the program
			playerState = WIN; //The player wins.
		}

		//Ticks each of the game objects which are registered with the master game state.
		GameState::tick(delta);

	}
	else if (playerState == DEAD || playerState == WIN) { //If the player won or lost
		if (input::getPressed() == 112) { //Check if they press P to play again.
			//Reset the game
			reset();
			input::usedPress(); //And use the keypress so we don't have it next tick.
		}
	}
}

void GSSpaceInvaders::render(Screen * display)
{
	//If the player was shot, flashFrame will be bigger than 0
	if (flashFrame >= 0) {
		flashFrame--; //If thats the case decrement it
		for (int i = 0; i < 14; i++) { //And draw the flash frame as Xs accorss the screen.
			display->drawString("XXXXXXXXXXXXXXX", 0, i);
		}
	}

	//Renders all normal game objects
	GameState::render(display);

	//And also the shots.
	for (int i = 0; i < NUM_SHOTS; i++) {
		if (activeShots[i]) {
			activeShots[i]->render(display);
		}
	}

	//If the player lost
	if (playerState == DEAD) { //Give them the message and how to play again.
		display->drawString("Game Over!", 3, 3);
		display->drawString("Press P", 4, 4);
		display->drawString("To play again.", 0, 5);
	}
	else if (playerState == WIN) { //If the player won, tell them so and let them play again.
		display->drawString("You Win!", 3, 3);
		display->drawString("Press P", 4, 4);
		display->drawString("To play again.", 0, 5);
	}

	//This is done last so it is always rendered.
	//Displays the player's life to the screen.
	std::stringstream ss; //A stringstream allows propper conversion from int to string
	ss << "Life: "; //Append the initial life count
	ss << player.getLife(); //And then the player's life
	//Now draw it to the screen.
	display->drawString(ss.str(), 1, 0);
}

//Lets the player and invaders add a shot to the game.
void GSSpaceInvaders::addShot(GameObjectShot shot)
{
	shots[numShots] = shot; //Sets the shot to be in the game at the current position.
	activeShots[numShots] = &shots[numShots];
	numShots++; //Then advance the position
	if (numShots >= NUM_SHOTS) { //If we are out of shots
		numShots = 0; //Reset the position. This will overwrite existing shots but with 32 shots it should already be offscreen by the time it is overwriten.
	}
}

//Checks if a shot has hit an invader
bool GSSpaceInvaders::collideInvaders(GameObjectShot *shot)
{
	for (int i = 0; i < NUM_INVADERS; i++) { //For each invader
		if (activeInvaders[i]) { //Null check
			if (activeInvaders[i]->isLiving()) { //Check if it hasn't already been shot
				if (Collisions::overlapping(activeInvaders[i]->boundingBox, shot->boundingBox)) { //Then check if the shot overlaps with it
					activeInvaders[i]->kill(); //If it does, kill the invader
					return true; //And return true.
				}
			}
		}
	}
	return false; //If not, return false.
}

//Checks if a shot hits the player.
bool GSSpaceInvaders::collidePlayer(GameObjectShot * shot)
{
	if (Collisions::overlapping(shot->boundingBox, player.boundingBox) == true) { //Check collision box
		if (player.damage(25)) { //Deal 25 damage to the player
			playerState = DEAD; //If damage returned true it means the player is dead. So update game state based on that.
		}
		flashFrame = 5; //Lastly play the flash frame animation.
		return true; //And return true.
	}
	else {
		return false; //otherwise return false.
	}
}

//Checks if a shot has hit a shield
bool GSSpaceInvaders::collideShield(GameObjectShot * shot)
{
	for (int i = 0; i < 3; i++) { //For each shield
		if (shields[i]) { //Check null
			if (shields[i]->living()) { //Then check if it is actually alive
				if (Collisions::overlapping(shields[i]->boundingBox, shot->boundingBox)) { //Then check if it is overlapping the shot
					shields[i]->damage(); //If so, then damage the shield and return true.
					return true;
				}
			}
		}
	}
	return false; //Otherwise return false.
}

//Checks if a space invader is above the player
bool GSSpaceInvaders::targetingPlayer(GObjSpaceInvader * invader)
{
	if (invader->boundingBox.x < player.boundingBox.getRightEdge() && player.boundingBox.getRightEdge() > invader->boundingBox.x) { //Only checks overlapping on X coordinates
		return true; //Then returns true if there is overlap.
	}
	else {
		return false; //Otherwise returns false.
	}
}

//Resets the game so the player can play again.
void GSSpaceInvaders::reset()
{
	//For each invader
	for (int i = 0; i < NUM_INVADERS; i++) {
		if (activeInvaders[i]) {
			activeInvaders[i]->respawn(); //Respawn it
		}
	}
	//For each shield
	for (int i = 0; i < 3; i++) {
		if (shields[i]) {
			shields[i]->respawn(); //Respawn it
		}
	}
	//For each shot
	for (int i = 0; i < NUM_SHOTS; i++) {
		shots[i].position = { -1, -1 }; //Remove it. This way the board starts fresh from shots.
	}
	//Respawn the player
	player.respawn();
	//And indicate the game state is now alive again.
	playerState = ALIVE;
}
