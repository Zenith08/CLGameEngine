#include "pch.h"
#include "GObjSpaceInvader.h"
#include <iostream>

GObjSpaceInvader::GObjSpaceInvader(Vector2 initial)
{
	clearTexture();
	texture[0][0] = '(';
	texture[1][0] = '-';
	texture[2][0] = ')';
	texture[0][1] = '|';
	texture[2][1] = '|';

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

	position = { initial.x, initial.y };
	boundingBox = CollisionBox(position.x, position.y, 3, 2);
}

GObjSpaceInvader::GObjSpaceInvader()
{
	GObjSpaceInvader({ -5, -5 });
}

void GObjSpaceInvader::tick(double delta)
{
	time--;
	if (time == 0) {
		time = delays;
		currentFrame++;
		if (currentFrame > 3) {
			currentFrame = 0;
		}
	}

	GameObject::tick(delta);
}

void GObjSpaceInvader::render(Screen * display)
{
	if (currentFrame == 0 || currentFrame == 2) {
		display->draw(texture, position.x, position.y);
	}
	else if (currentFrame == 1) {
		display->draw(animL, position.x, position.y);
	}
	else if (currentFrame == 3) {
		display->draw(animR, position.x, position.y);
	}
}
