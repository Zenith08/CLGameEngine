//
//  CollisionBox.cpp
//  CommandLineAnimator
//
//  Created by Period 2 on 2019-02-13.
//  Copyright © 2019 Period 2. All rights reserved.
//

#include "CollisionBox.h"

//A default constructor which simply calls CollisionBox(int, int, int, int) with default arguments.
CollisionBox::CollisionBox() {
	CollisionBox(0, 0, 1, 1);
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

//Checks if box 1 and box 2 are overlapping at any point.
//True if box1 and box2 are overlapping.
//False otherwise.
bool Collisions::overlapping(CollisionBox box1, CollisionBox box2) {
	//First, check if the boxes are crossing on the x dimension.
	//if(box2 left < box1 left < box2 right OR box2 left < box1 right < box2 right)
	if ((box1.x >= box2.x && box1.x <= box2.x + box2.width) || (box1.x + box1.width >= box2.x && box1.x + box1.width <= box2.x + box2.width)) {
		//if(box2 top < box1 top < box2 bottom OR box2 top < box1 bottom < box2 top)
		if ((box1.y >= box2.y && box1.y <= box2.y + box2.height) || (box1.y + box1.height >= box2.y && box1.y + box1.height <= box2.y + box2.height)) {
			return true; //The boxes are then overlapping.
		}
	}
	//Else
	return false;
}
