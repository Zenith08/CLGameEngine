//
//  GameStateJump.hpp
//  CommandLineAnimator
//
//  Created by Period 2 on 2019-02-15.
//  Copyright © 2019 Period 2. All rights reserved.
//

#ifndef GameStateJump_hpp
#define GameStateJump_hpp

#include "pch.h"
#include <stdio.h>
#include "GameState.h"
#include "Screen.h"
#include "GameObjectWall.h"
#include "GameObjectBall.h"
#include "GameObjectDodgeball.h"

#define EASY true
#define HARD false

//An example derrived game state.
class GameStateJump : public GameState {
public:
	//The game objects used in this game.
	GameObjectWall wallTop1;
	GameObjectWall wallTop2;

	GameObjectWall wallBottom1;
	GameObjectWall wallBottom2;

	GameObjectWall wallLeft1;
	GameObjectWall wallLeft2;

	GameObjectWall wallRight1;
	GameObjectWall wallRight2;

	GameObjectBall ball;
	GameObjectDodgeball dodgeball;

	const int playing = 0;
	const int dead = 1;
	const int difficultySelect = 2;

	int inGame = difficultySelect;

	bool difficulty = HARD;

	//A default constructor lets us initalize everything.
	GameStateJump();
	//Used for custom logic and displaying to the screen.
	void tick(double delta);
	void render(Screen *display);

	int gameScore;
	int highScore;
	int easyHighScore;

	//Helper methods to convert the scores to strings which can be drawn to the screen effectivly.
	string getGameScore();
	string getHighScore();
};

#endif /* GameStateJump_hpp */
