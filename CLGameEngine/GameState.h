#pragma once
//
//  GameState.hpp
//  CommandLineAnimator
//
//  Created by Period 2 on 2019-02-14.
//  Copyright © 2019 Period 2. All rights reserved.
//

#ifndef GameState_hpp
#define GameState_hpp

#include "pch.h"
#include <stdio.h>
#include "Screen.h"
#include "GameObject.h"

//A game state represents a game's base class.
//Games may have multiple states such as a menue state, and a gameplay state.
//A game state has controll of the screen and and recieves logic updates from the main loop.
class GameState {
public:
	//Instructs the game state to update.
	//double delta - the number of milliseconds since the last frame.
	//Using delta in logic allows consistent movement regardless of frame rate.
	void tick(double delta);
	//Instructs the game state to render it's game objects to the screen.
	//May be overridden to allow custom object handling.
	//Param Screen - a reffernce to the display which will be used to draw the display.
	void render(Screen *display);
	//An array of objects in the game to be updated and rendered each frame.
	//A derrived game state may put it's objects into this array to have them automatically added to the game.
	GameObject objects[255];
};

#endif /* GameState_hpp */
