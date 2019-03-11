#include "GameObject.h"

//Create a defualt game object. Recommended to call to prevent errors.
//Everything can be overridden later.
GameObject::GameObject()
{
	//Avoids null errors by defining default values.
	boundingBox = CollisionBox();
	position = { 0, 0 };
}

//Default tick method makes sure the bounding box is at the current coordinates.
void GameObject::tick(double delta) {
	//Update the bounding box position to the current coordinates.
	boundingBox.setCoordinates(position.x, position.y);
}

//Default render method draws the texture at the current position.
void GameObject::render(Screen *display) {
	//Draw the texture to the screen at the current position.
	display->draw(texture, position.x, position.y);
}

//Clearing the texture at the start of initalization allows easy starting of a texture on a clean slate.
//Avoids having any unintended blank characters.
void GameObject::clearTexture()
{
	for (int x = 0; x < 5; x++) {
		for (int y = 0; y < 5; y++) {
			texture[x][y] = ' ';
		}
	}
}
