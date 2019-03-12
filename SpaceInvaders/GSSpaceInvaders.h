#pragma once

#include <GameState.h>
#include "Screen.h"
#include "GameObjectWall.h"
#include "SIPlayer.h"
#include "GObjSpaceInvader.h"
#include "GObjShield.h"

//Global constants for key variables.
#define NUM_SHOTS 32
#define NUM_INVADERS 12
#define ALIVE 0
#define DEAD 1
#define WIN 2

//A GSSpaceInvaders is a GameState which runs the game Space Invaders.
class GSSpaceInvaders :
	public GameState
{
public:
	int numShots = 0; //The number of shots currently on screen.
	int playerState = ALIVE; //Sets the internal game state to alive.

	//The shots which have been fired. Includes both the player's and invader's shots.
	GameObjectShot shots[NUM_SHOTS] = {};
	GameObjectShot *activeShots[NUM_SHOTS] = {}; //For some reason checking null on a pointer works but doing it to the actual objects cause chaos.

	//All of the invaders in the game.
	GObjSpaceInvader invaders[NUM_INVADERS] = {};
	GObjSpaceInvader *activeInvaders[NUM_INVADERS] = {}; //Idk why but using pointers works better.
	
	//Basic Walls
	GameObjectWall left1;
	GameObjectWall left2;
	GameObjectWall left3;
	GameObjectWall right1;
	GameObjectWall right2;
	GameObjectWall right3;

	//The shields the player gets
	GObjShield shield1;
	GObjShield shield2;
	GObjShield shield3;

	//Allows easy access to all 3 shields without hard coding it.
	GObjShield *shields[3] = {};

	//The player will be the same every time.
	SIPlayer player;

	//Flashes the screen when the player is shot for a brief period of time.
	int flashFrame = 0;

	//Default constructor is all we need.
	GSSpaceInvaders();
	//Logic
	void tick(double delta);
	//Drawing stuff. Notibly shots which are independent of normal game objects.
	void render(Screen *display);
	//Allows the player and invader to add shots to the game.
	void addShot(GameObjectShot shot);
	//Checks if a shot hits an invader. If so, returns true.
	bool collideInvaders(GameObjectShot *shot);
	//Checks if a shot hits a player. If so, returns true.
	bool collidePlayer(GameObjectShot *shot);
	//Checks if a shot hits a shield. If so, returns true.
	bool collideShield(GameObjectShot *shot);
	//Checks if the invader is currently above the player. If so, returns true.
	bool targetingPlayer(GObjSpaceInvader *invader);
	//Reset the game to allow the player to play again.
	void reset();
};
