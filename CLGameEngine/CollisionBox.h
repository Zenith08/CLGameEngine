#pragma once

#include "pch.h"
#include <stdio.h>

//Represents an arbitrary box in two dimensional space.
class CollisionBox {

public:
	int x, y; //The coordinates of the boxes top left corner.
	int width, height; //The width and height of the box starting from the top left corner.

	CollisionBox(); //A default constructor which places a box at 0, 0 with size 1, 1.
	CollisionBox(int posX, int posY, int sizeX, int sizeY); //A normal constructor allowing default values to be set.

	void setCoordinates(int newX, int newY); //Allows moving the box in two dimensional space.
	void setDimensions(int newWidth, int newHeight); //Allows resizing the boxes horizontal and vertical dimensions.

	int getRightEdge(); //Returns the position of the right edge of the box calculated by x+width.
	int getBottomEdge(); //Returns the position of the bottom edge of the box calculated by y+height.
};
//All functions for CollisionBox which are not class specific.
namespace Collisions {
	//Are the two boxes overlapping in two dimensional space.
	//Returns true if they are.
	bool overlapping(CollisionBox box1, CollisionBox box2);
}
