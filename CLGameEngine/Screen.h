#pragma once
//
//  Screen.hpp
//  CommandLineAnimator
//
//  Created by Period 2 on 2019-02-07.
//  Copyright © 2019 Period 2. All rights reserved.
//

#ifndef Screen_hpp
#define Screen_hpp

#include "pch.h"
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

const int XSIZE = 15;
const int YSIZE = 15;
//BLANK is treated as transparency in textures. The char will be ignored and any previously rendered char will still show.
const string BLANK = " ";
//EMPTY is treated as blackness in textures. It will override anythign prevously drawn to that position but will not be rendered to the screen itsself.
const char EMPTY = '?';
//NEW is a simple helper string to easily call on a new line.
const string NEW = "\n";

//A class representing a screen drawn to the termianl.
//Useful for drawing objects to the screen on a consistent basis.
class Screen {
private:
	//Storing the display this way allows for easy access and edits durring the program.
	//It is leveraged for "texture" rendering.
	char display[XSIZE][YSIZE];

public:
	//A default constructor.
	//Initializes the array and other variables.
	Screen();

	//Draws a texture to the current display.
	//Characters which are ' ' will be ignored.
	//Characters which are '?' will not be rendered but will be written to the screen.
	//Args:
	//texture - a 5x5 char array which will be drawn to the screen.
	//x - the X position of the top left corner of the texture. Can be outside the range of the window but will be ignored.
	//y - the Y position of the top left corner. Follows the same limitations as the x argument.
	void draw(char texture[5][5], int x, int y);
	//Draws a string to the current display.
	//The string will override anything currently present.
	//'?' characters will not be rendered to the screen.
	//Args:
	//print - the string to display on screen.
	//x - the X position of the left side of the string. Will be ignored if it is outside the main window range.
	//y - the Y position of the string. Follows the same limitations as the x argument.
	void drawString(string print, int x, int y);
	//Renders the current display to the screen.
	//Characters which are '?' are not rendered and replaced by ' '.
	void render();
	//Clears the screen setting each array position to '?'.
	void clear();
};

#endif /* Screen_hpp */
