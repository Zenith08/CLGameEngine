#pragma once
#include <GameObject.h>

#define LEFT false
#define RIGHT true

class GObjSpaceInvader :
	public GameObject
{
	int delays = 15;

	char animL[5][5];
	char animR[5][5];
	int currentFrame = 1;
	int time = delays;
	bool alive = true;
	bool moveDirection = RIGHT;

public:
	GObjSpaceInvader();
	GObjSpaceInvader(Vector2 initial);
	void tick(double delta);
	void render(Screen *display);
	bool isLiving();
	void kill();
};

