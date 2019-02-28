//
//  GameStateJump.cpp
//  CommandLineAnimator
//
//  Created by Period 2 on 2019-02-15.
//  Copyright © 2019 Period 2. All rights reserved.
//

#include <iostream>
#include "GameStateJump.h"
#include "GameInput.h"
#include "FileInput.h"
#include <sstream>

GameStateJump::GameStateJump() : GameState() {
	//cout << "Constructor called" << endl;
	//Create variables for each game object in use.
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
	
	//Then add them to the game state. addStaticCollider() also calls addGameObject().
	addStaticCollider(&wallTop1);
	addStaticCollider(&wallTop2);
	addStaticCollider(&wallBottom1);
	addStaticCollider(&wallBottom2);
	addStaticCollider(&wallLeft1);
	addStaticCollider(&wallLeft2);
	addStaticCollider(&wallRight1);
	addStaticCollider(&wallRight2);

	//Add the dynamic objects to the game, but not to the static colliders.
	addGameObject(&ball);
	addGameObject(&dodgeball);
	
	gameScore = 0;
	
	vector<int> scores = file::loadScores("dodgeball.dat");
	if (scores.size() > 0) {
		highScore = scores[0];
	}
	else {
		file::saveScores("dodgeball.dat", scores);
		highScore = 0;
	}
}

//Right now we don't need it but we will.
void GameStateJump::tick(double delta) {
	GameState::tick(delta);
	//If we are playing the game still
	if (inGame == playing) {
		gameScore++;
		//Then check if the player has died.
		if (Collisions::overlapping(dodgeball.boundingBox, ball.boundingBox)) {
			inGame = dead; //If the player has died, indicate that to the rest of the code.
			if (gameScore > highScore) {
				highScore = gameScore;
				//Save the new high score
				vector<int> score = vector<int>();
				score.push_back(highScore);
				file::saveScores("dodgeball.dat", score);
			}
		}
		else {

		}
	}
	//If the player is dead
	else if (inGame == dead) {
		//See if the player wants to start again.
		if (input::getPressed() == 112) {
			//If they do then reset the game to a default state.
			input::usedPress();
			//Reset
			gameScore = 0;
			ball.position.x = 2;
			ball.position.y = 2;
			dodgeball.position.x = 5;
			dodgeball.position.y = 5;
			dodgeball.velocity.x = 1;
			inGame = playing;
		}
	}
	//cout << "Tick" << endl;
}

//Will be useful later.
void GameStateJump::render(Screen *display) {
	//If the player is not dead
	if (inGame == playing) {
		GameState::render(display); //Draw the game normally.

		display->drawString(getGameScore(), 0, 12);
		if (highScore != 0) {
			display->drawString(getHighScore(), 0, 13);
		}
	}
	else if (inGame == dead) { //Otherwise tell them what has happened and how to reset.
		display->drawString("You died, to", 2, 3);
		display->drawString("play again, ", 2, 4);
		display->drawString("press P", 4, 5);
		display->drawString("Or press Q", 2, 6);
		display->drawString("to quit.", 4, 7);
		display->drawString(getGameScore(), 2, 8);
		display->drawString(getHighScore(), 2, 9);
	}
	//cout << "Render" << endl;
}

//Source https://www.systutorials.com/131/convert-string-to-int-and-reverse/
string GameStateJump::getGameScore()
{
	std::stringstream ss;
	ss << "Score: ";
	ss << gameScore;
	return ss.str();
}

string GameStateJump::getHighScore()
{
	std::stringstream ss;
	ss << "Score: ";
	ss << highScore;
	return ss.str();
}
