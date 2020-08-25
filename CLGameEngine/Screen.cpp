//
//  Screen.cpp
//  CommandLineAnimator
//
//  Created by Period 2 on 2019-02-07.
//  Copyright © 2019 Period 2. All rights reserved.
//
#include "pch.h"
#include "Screen.h"
#include <iostream>
#include <string>

using namespace std;

//Initialize the screen - '?' is treated as ' ' and is used as a default value in the class.
//As a side effect, '?' cannot be used in textures.
Screen::Screen() {
	for (int y = 0; y < YSIZE; y++) {
		for (int x = 0; x < XSIZE; x++) {
			display[x][y] = EMPTY;
		}
	}
}

//Drawing a texture loops through the coordinates on the texture and maps them to coordinates on the display, offset by positions x and y.
//If a texture has pixels outside of the display, they will not be drawn to the display.
void Screen::draw(char texture[5][5], int x, int y) {
	//cout << "Started draw" << endl;
	//cout << "Tex size " << 5 << endl;
	//cout << "Tex 0 " << texture[0][0] << endl;

	//Loop through the texture which has a known width and height of 5.
	for (int xLoop = 0; xLoop < 5; xLoop++) {
		if (xLoop + x < XSIZE && xLoop+x >= 0) { //If this is false, it means the texture wants to draw onto a line that does not exist on the display. Therefore ignore it.
			for (int yLoop = 0; yLoop < 5; yLoop++) {
				//cout << "Texture " << xLoop << ", " << yLoop << " equals " << texture[yLoop][xLoop] << endl;
				if (y + yLoop < YSIZE && yLoop+y >= 0) { //If this is false, it means the texture wants to draw onto a row that does not exist on the display. Therefore ignore it.
					if (texture[xLoop][yLoop] != ' ') { //This lets ' ' to be treated as transparent. It will not override any character underneath it. '?' Will also be transparent because it is not rendered.
						display[x + xLoop][y + yLoop] = texture[xLoop][yLoop]; //If the character is going to be displayed, this will map it to the screen.
					}
				}
				//cout << "Display " << x+xLoop << ", " << y+yLoop << " equals " << display[y+yLoop][x+xLoop] << endl;
			}
		}
	}
	//cout << "Returned" << endl;
}

//Draws a 1 dimensional string to the screen.
void Screen::drawString(string print, int x, int y)
{
	if (y < YSIZE && y >= 0) { //Make sure we are within the array y axis.
		for (unsigned int xLoop = 0; xLoop < print.length(); xLoop++) { //For each character in the string
			if (x + xLoop < XSIZE) { //Make sure it fits on the x axis of the screen.
				display[x + xLoop][y] = print[xLoop]; //Then draw it to the screen.
			}
		}
	}
}

void Screen::render() {
	//cout << wipeScreen << endl;
	//Frame is a single string which will be printed.
	//Minimizing cout calls improves performance and the added cost of the string building is insignificant.
	string frame = ""; //Testing \n

	//For each colum
	for (int y = 0; y < XSIZE; y++) {
		//And each row of each colum
		for (int x = 0; x < XSIZE; x++) {
			if (display[x][y] != EMPTY) { //Check if the character is blank
				frame += display[x][y]; //If it isn't, draw it.
			}
			else {
				frame += BLANK; //If it is, include that.
			}
		}
		//At the end of a row, create a new line for the next row.
		frame += NEW;
	}
	//Once this is done, print the entire thing to the screen.
	//Using endl here will cause a flush of the display buffer guarenteeing that the frame is drawn to the screen quickly.
	cout << frame << flush;
}

void Screen::clear() {
	//For each value in the array
	for (int y = 0; y < YSIZE; y++) {
		for (int x = 0; x < XSIZE; x++) {
			display[x][y] = EMPTY; //Set it to the designated blank character.
		}
	}
}
