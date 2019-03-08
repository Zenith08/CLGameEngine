#include "pch.h"
#include "GObjShield.h"


GObjShield::GObjShield()
{
	GObjShield({-5, -5});
}

GObjShield::GObjShield(Vector2 initial) :GameObject()
{
	position = { initial.x, initial.y };
	start = { initial.x, initial.y };

	clearTexture();

	texture[0][0] = '/';
	texture[1][0] = '=';
	texture[2][0] = '\\';
	texture[0][1] = '=';
	texture[1][1] = '=';
	texture[2][1] = '=';

	for (int x = 0; x < 5; x++) {
		for (int y = 0; y < 5; y++) {
			damage1[x][y] = ' ';
			damage2[x][y] = ' ';
		}
	}

	damage1[1][0] = '=';

	damage1[0][1] = '=';
	damage1[1][1] = '=';
	damage1[2][1] = '=';

	damage2[1][0] = '-';

	damage2[0][1] = '-';

	damage2[2][1] = '-';
	
	boundingBox = CollisionBox(position.x, position.y, 3, 2);
}

void GObjShield::tick(double delta)
{
	GameObject::tick(delta);
}

void GObjShield::render(Screen * display)
{
	if (life == 3) {
		GameObject::render(display);
	}
	else if (life == 2) {
		display->draw(damage1, position.x, position.y);
	}
	else if (life == 1) {
		display->draw(damage2, position.x, position.y);
	}
	else {
		//Don't render
	}
}

bool GObjShield::damage()
{
	life--;
	if (life <= 0) {
		position.x = -5;
		position.y = -5;
		return true;
	}
	else {
		return false;
	}
}

void GObjShield::respawn()
{
	life = 3;
	position = { start.x, start.y };
}

bool GObjShield::living()
{
	if (life > 0) {
		return true;
	}
	else {
		return false;
	}
}
