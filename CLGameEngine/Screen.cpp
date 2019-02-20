//
//  Screen.cpp
//  CommandLineAnimator
//
//  Created by Period 2 on 2019-02-07.
//  Copyright © 2019 Period 2. All rights reserved.
//

#include "Screen.h"
#include <iostream>
#include "conio.h"
using namespace std;

//Initialize the screen - '?' is treated as ' ' and is used as a default value in the class.
//As a side effect, '?' cannot be used in textures.
Screen::Screen() {
	for (int y = 0; y < YSIZE; y++) {
		for (int x = 0; x < XSIZE; x++) {
			display[x][y] = '?';
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
		if (xLoop + x < XSIZE) { //If this is false, it means the texture wants to draw onto a line that does not exist on the display. Therefore ignore it.
			for (int yLoop = 0; yLoop < 5; yLoop++) {
				//cout << "Texture " << xLoop << ", " << yLoop << " equals " << texture[yLoop][xLoop] << endl;
				if (y + yLoop < YSIZE) { //If this is false, it means the texture wants to draw onto a row that does not exist on the display. Therefore ignore it.
					if (texture[x][y] != ' ') { //This lets ' ' to be treated as transparent. It will not override any character underneath it.
						display[x + xLoop][y + yLoop] = texture[xLoop][yLoop]; //If the character is going to be displayed, this will map it to the screen.
					}
				}
				//cout << "Display " << x+xLoop << ", " << y+yLoop << " equals " << display[y+yLoop][x+xLoop] << endl;
			}
		}
	}

	//cout << "Returned" << endl;
}

void Screen::render() {
	//cout << wipeScreen << endl;
	for (int y = 0; y < XSIZE; y++) {
		for (int x = 0; x < XSIZE; x++) {
			if (display[x][y] != '?') {
				cout << display[x][y];
			}
			else {
				cout << " ";
			}
		}
		cout << "\n";
	}

	cout << endl;
}

void Screen::clear() {
	for (int y = 0; y < YSIZE; y++) {
		for (int x = 0; x < XSIZE; x++) {
			display[y][x] = '?';
		}
	}
}
