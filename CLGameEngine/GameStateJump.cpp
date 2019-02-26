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
	//cout << "Constructor called" << endl;
	wallTop1 = GameObjectWall(1, 0, 5, 1);
	wallTop2 = GameObjectWall(6, 0, 5, 1);

	wallBottom1 = GameObjectWall(1, 11, 5, 1);
	wallBottom2 = GameObjectWall(6, 11, 5, 1);

	wallLeft1 = GameObjectWall(0, 1, 1, 5);
	wallLeft2 = GameObjectWall(0, 6, 1, 5);

	wallRight1 = GameObjectWall(11, 1, 1, 5);
	wallRight2 = GameObjectWall(11, 6, 1, 5);

	ball = GameObjectBall();
	dodgeball = GameObjectDodgeball();
	
	addStaticCollider(&wallTop1);
	addStaticCollider(&wallTop2);
	addStaticCollider(&wallBottom1);
	addStaticCollider(&wallBottom2);
	addStaticCollider(&wallLeft1);
	addStaticCollider(&wallLeft2);
	addStaticCollider(&wallRight1);
	addStaticCollider(&wallRight2);

	addGameObject(&ball);
	addGameObject(&dodgeball);
}

void GameStateJump::tick(double delta) {
	GameState::tick(delta);
	//cout << "Tick" << endl;
}

void GameStateJump::render(Screen *display) {
	GameState::render(display);
	//cout << "Render" << endl;
}
