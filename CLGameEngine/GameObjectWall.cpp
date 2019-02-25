#include "GameObjectWall.h"

GameObjectWall::GameObjectWall()
{
	GameObjectWall(0, 0, 1, 1);
}

GameObjectWall::GameObjectWall(int x, int y, int width, int height)
{
	GameObject::GameObject();
	//Define base parameters
	position.x = x;
	position.y = y;
	boundingBox.setDimensions(width, height);
	boundingBox.setCoordinates(x, y);

	//Now build the texture
	for (int lx = 0; lx < 5; lx++) {
		for (int ly = 0; ly < 5; ly++) {
			//If the slot is within the bounds of the wall, then put that into the texture.
			if (lx < width && ly < height) {
				texture[lx][ly] = '#';
			} else { //Otherwise put a blank in.
				texture[lx][ly] = ' ';
			}
		}
	}
}
