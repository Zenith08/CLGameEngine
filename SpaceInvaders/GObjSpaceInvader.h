#pragma once

#include <GameObject.h>

//Natural language options for which way the invader is moving.
#define LEFT false
#define RIGHT true

//Space invaders have animated textures, can move, and can shoot.
class GObjSpaceInvader :
	public GameObject
{
	//The ammount of frames before each movement update.
	int delays = 15;
	//The probability that this invader shoots on any given movement update.
	int shooting = 2;
	//Texture is the neutral frame
	//The other 2 are animation frames.
	char animL[5][5];
	char animR[5][5];
	//What frame are we currently on. Actually 1 less than we expect to have rendered because at the start of render it is incremented.
	int currentFrame = 1;
	//The time until next update equals the time we will wait before each update.
	int time = delays;
	bool alive = true; //Starting out alive. Changed to false when the invader gets shot.
	bool moveDirection = RIGHT; //Start the game by moving right.
	//The coordinates the invader started at before any movements.
	Vector2 start;

public:
	//Default constructor
	GObjSpaceInvader();
	//Create an invader and set it's position.
	GObjSpaceInvader(Vector2 initial);
	//Movement and shooting and stuff.
	void tick(double delta);
	//Animations and stuff.
	void render(Screen *display);
	//Have we been shot yet? If so, this returns false.
	bool isLiving();
	//Shoots the invader and kills it.
	void kill();
	//Resets the invader to it's default position and sets it to living.
	void respawn();
};
