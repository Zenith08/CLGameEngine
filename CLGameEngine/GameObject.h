#pragma once
//
//  GameObject.hpp
//  CommandLineAnimator
//
//  Created by Period 2 on 2019-02-14.
//  Copyright © 2019 Period 2. All rights reserved.
//  Known Limmitations: All textures must be 5x5 char arrays. They may include ' ' which is a blank but cannot be greater than 5x5.

#ifndef GameObject_hpp
#define GameObject_hpp

#include "pch.h"
#include <stdio.h>
#include "Screen.h"
#include "CollisionBox.h"

//Represents a position in 2 dimensional space.
struct Vector2 {
	int x;
	int y;
};

//Represents an object which exists in two dimensional space, can be interacted with, and can be displayed.
class GameObject {
public:
	GameObject();
	//The position in 2d space.
	Vector2 position;
	//The texture to display. *All textures must be 5x5 chars
	char texture[5][5];
	//The collision box of the object in two dimensional space. Should be mapped to the size of the texture if it includes ' '.
	CollisionBox boundingBox;
	//Allows for updating logic and movement.
	//delta - The number of milliseconds since the last frame.
	//Using delta in movement will achieve consistent movement regardless of framerate.
	virtual void tick(double delta);
	//Instructs the game object to render it's texture to the screen.
	//May be overridden to allow multiple / changing textures.
	//Param Screen - a reffernce to the display which will be used to draw the display.
	virtual void render(Screen *display);
};

#endif /* GameObject_hpp */
