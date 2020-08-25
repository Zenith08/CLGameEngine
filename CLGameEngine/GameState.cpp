//
//  GameState.cpp
//  CommandLineAnimator
//
//  Created by Period 2 on 2019-02-14.
//  Copyright © 2019 Period 2. All rights reserved.
//
#include "pch.h"
#include "GameState.h"

//Default blank constructor.
GameState::GameState() {

}

//Defines tick, a tick runs once per frame.
void GameState::tick(double delta) {
	//Ticks each game object within the game state.
	for (int i = 0; i < 255; i++) {
		if (objects[i]) {
			objects[i]->tick(delta);
		}
	}
}

//Renders the screen. Called once per frame.
void GameState::render(Screen *display) {
	//Renders each object within the game state.
	for (int i = 0; i < 255; i++) {
		if (objects[i]) {
			objects[i]->render(display);
		}
	}
}

//Easily adds a new game object to the world without overwriting previous game objects.
void GameState::addGameObject(GameObject * newObj)
{
	int index = 0; //Start at 0, used to check what index the game object needs to be inserted to.
	while (objects[index]) { //While an object exists at the current index
		index++; //Move to the next index
	}
	objects[index] = newObj; //Then put the new object into the first available index.
}

//Indicates an object is a game object, and has a collision box which should be available to all other game objects.
void GameState::addStaticCollider(GameObject * staticObj)
{
	addGameObject(staticObj); //First, a static collider is also a game object so make it one.
	int index = 0; //Then start at 0 for static colliders
	while (staticCollision[index]) { //While there is a static collider at this index
		index++; //Move to the next index.
	}
	staticCollision[index] = staticObj; //Then put the static collider into the precached list.
}
//Loops through each static collider to make sure the user has no collisions with it.
bool GameState::overlapsStatic(GameObject * dynamicQuestion)
{
	int i = 0; //To make looping through each collider easier
	while (staticCollision[i]) { //While the static collider at i is not null/empty
		if (Collisions::overlapping(dynamicQuestion->boundingBox, staticCollision[i]->boundingBox)) { //Check if the collider overlaps with the dynamic collider input.
			return true; //If it does, return true and end.
		}
		i++; //Otherwise, move to the next one.
	}
	//If we've checked each collider and found no collision, return false.
	return false;
}
