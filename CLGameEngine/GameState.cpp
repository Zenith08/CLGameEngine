//
//  GameState.cpp
//  CommandLineAnimator
//
//  Created by Period 2 on 2019-02-14.
//  Copyright © 2019 Period 2. All rights reserved.
//

#include "GameState.h"

void GameState::tick(double delta) {
	//Ticks each game object within the game state.
	for (int i = 0; i < 255; i++) {
		objects[i].tick(delta);
	}
}

void GameState::render(Screen *display) {
	//Renders each object within the game state.
	for (int i = 0; i < 255; i++) {
		objects[i].render(display);
	}
}
