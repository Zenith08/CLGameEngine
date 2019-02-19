//
//  GameStateJump.cpp
//  CommandLineAnimator
//
//  Created by Period 2 on 2019-02-15.
//  Copyright © 2019 Period 2. All rights reserved.
//

#include <iostream>
#include "GameStateJump.h"

GameStateJump::GameStateJump() : GameState() {
	cout << "Constructor called" << endl;
	//GameObjectBall ball = GameObjectBall();
	//objects[0] = ball;
}

void GameStateJump::tick(double delta) {
	GameState::tick(delta);
	cout << "Tick" << endl;
}

void GameStateJump::render(Screen *display) {
	GameState::render(display);
	cout << "Render" << endl;
}
