#include "pch.h"
#include "GObjShield.h"

//Default constructor
GObjShield::GObjShield()
{
	GObjShield({-5, -5});
}

//Create and setup a shield.
GObjShield::GObjShield(Vector2 initial) :GameObject()
{
	//Set the position and starting position to the provided one.
	position = { initial.x, initial.y };
	start = { initial.x, initial.y };

	//Blank texture to start with.
	clearTexture();

	//Healthy shield texture.
	texture[0][0] = '/';
	texture[1][0] = '=';
	texture[2][0] = '\\';
	texture[0][1] = '=';
	texture[1][1] = '=';
	texture[2][1] = '=';

	//Manually clear the damaged texture.
	for (int x = 0; x < 5; x++) {
		for (int y = 0; y < 5; y++) {
			damage1[x][y] = ' ';
			damage2[x][y] = ' ';
		}
	}

	//Then populate it with the damaged texture.
	damage1[1][0] = '=';

	damage1[0][1] = '=';
	damage1[1][1] = '=';
	damage1[2][1] = '=';

	//And the more damaged texture.
	damage2[1][0] = '-';

	damage2[0][1] = '-';

	damage2[2][1] = '-';
	
	//Set the default collision box for the shield.
	boundingBox = CollisionBox(position.x, position.y, 3, 2);
}

void GObjShield::tick(double delta)
{
	GameObject::tick(delta); //Shown just for clarity.
}

//Based on our life, render the shield.
void GObjShield::render(Screen * display)
{
	if (life == 3) { //If we are healthy draw the healthy texture.
		GameObject::render(display); //GameObject::render is analogous to display->draw(texture, ...);
	}
	else if (life == 2) { //Draws the slightly damaged texture.
		display->draw(damage1, position.x, position.y);
	}
	else if (life == 1) { //Draws the very damaged texture.
		display->draw(damage2, position.x, position.y);
	}
	else { //If we are here, then the shield is destroyed.
		//Don't render
	}
}

//Inflicts damage and checks for destruction.
bool GObjShield::damage()
{
	//Decrement the life.
	life--;
	if (life <= 0) { //If this damage destroyed the shield,
		position.x = -5; //Move the shield out of the playable area. This will effectivly disable it.
		position.y = -5;
		return true; //True means this damage destroyed the shield.
	}
	else {
		return false; //False means this damage did not destroy the shield.
	}
}

//Respawns the shield and resets it for another game.
void GObjShield::respawn()
{
	life = 3; //Reset our life.
	position = { start.x, start.y }; //Set it to it's initial coordinates instead of the middle of nowhere.
}

//If the shield is living and can block a shot this returns true.
bool GObjShield::living()
{
	if (life > 0) {
		return true; //As long as we have 1 life we are living.
	}
	else {
		return false; //If we don't have any life then we are not living.
	}
}
