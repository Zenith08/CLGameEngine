#pragma once
#include <GameObject.h>
class GObjSpaceInvader :
	public GameObject
{
	int delays = 15;

	char animL[5][5];
	char animR[5][5];
	int currentFrame = -1;
	int time = delays;

public:
	GObjSpaceInvader();
	void tick(double delta);
	void render(Screen *display);
};

