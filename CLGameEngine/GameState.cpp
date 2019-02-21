//
//  GameState.cpp
//  CommandLineAnimator
//
//  Created by Period 2 on 2019-02-14.
//  Copyright © 2019 Period 2. All rights reserved.
//

#include "GameState.h"

GameState::GameState() {
	
}

void GameState::tick(double delta) {
	//Ticks each game object within the game state.
	for (int i = 0; i < 255; i++) {
		if (objects[i] != nullptr) {
			objects[i]->tick(delta);
		}
	}
}

void GameState::render(Screen *display) {
	//Renders each object within the game state.
	for (int i = 0; i < 255; i++) {
		if (objects[i] != nullptr) {
			objects[i]->render(display);
		}
	}
}

void GameState::addGameObject(GameObject * newObj)
{
	int index = 0;
	while (objects[index] != nullptr) {
		index++;
	}
	objects[index] = newObj;
}

void GameState::addStaticCollider(GameObject * staticObj)
{
	addGameObject(staticObj);
	int index = 0;
	while (staticCollision[index] != nullptr) {
		index++;
	}
	staticCollision[index] = staticObj;
}

bool GameState::overlapsStatic(GameObject * dynamicQuestion)
{
	for (int i = 0; i < 128; i++) {
		if (Collisions::overlapping(dynamicQuestion->boundingBox, staticCollision[i]->boundingBox)) {
			return true;
		}
	}
	return false;
}
