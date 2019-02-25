//
//  CollisionBox.cpp
//  CommandLineAnimator
//
//  Created by Period 2 on 2019-02-13.
//  Copyright � 2019 Period 2. All rights reserved.
//

#include "CollisionBox.h"
#include <iostream>

//A default constructor which simply calls CollisionBox(int, int, int, int) with default arguments.
CollisionBox::CollisionBox() {
	CollisionBox(0, 0, 0, 0);
}

//Initializes a CollisionBox with dimensions and size based on the parameters input.
CollisionBox::CollisionBox(int posX, int posY, int sizeX, int sizeY) {
	x = posX;
	y = posY;
	width = sizeX;
	height = sizeY;
}

//Allows easy changing of coordinates for moving objects.
void CollisionBox::setCoordinates(int newX, int newY) {
	x = newX;
	y = newY;
}

//Allows resizing a collision box for objects which cna change size.
void CollisionBox::setDimensions(int newWidth, int newHeight) {
	width = newWidth;
	height = newHeight;
}

int CollisionBox::getRightEdge()
{
	return x+width;
}

int CollisionBox::getBottomEdge()
{
	return y+height;
}

//Checks if box 1 and box 2 are overlapping at any point.
//True if box1 and box2 are overlapping.
//False otherwise.
bool Collisions::overlapping(CollisionBox box1, CollisionBox box2) {
	//First, check if the boxes are crossing on the x dimension.
	//Source https://stackoverflow.com/questions/306316/determine-if-two-rectangles-overlap-each-other
	if (box1.x < box2.getRightEdge() && box1.getRightEdge() > box2.x &&
		box1.y < box2.getBottomEdge() && box1.getBottomEdge() > box2.y) {
		//std::cout << "Collision detected\n";
		return true;
	}
	//Else
	//std::cout << "No collision \n";
	return false;
}
