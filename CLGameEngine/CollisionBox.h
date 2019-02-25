#pragma once
//
//  CollisionBox.hpp
//  CommandLineAnimator
//
//  Created by Period 2 on 2019-02-13.
//  Copyright © 2019 Period 2. All rights reserved.
//

#ifndef CollisionBox_hpp
#define CollisionBox_hpp

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

	int getRightEdge();
	int getBottomEdge();
};
//All functions for CollisionBox which are not class specific.
namespace Collisions {
	//Are the two boxes overlapping in two dimensional space.
	//Returns true if they are.
	bool overlapping(CollisionBox box1, CollisionBox box2);
}

#endif /* CollisionBox_hpp */
