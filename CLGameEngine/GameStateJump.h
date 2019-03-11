#pragma once

#include "pch.h"
#include <stdio.h>
#include "GameState.h"
#include "Screen.h"
#include "GameObjectWall.h"
#include "GameObjectBall.h"
#include "GameObjectDodgeball.h"

//Natural Language options of the two difficulty modes currently programmed in the game.
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

	//The "ball" is the player.
	GameObjectBall ball;
	//The dodgeball is what the player must avoid.
	GameObjectDodgeball dodgeball;

	//Game states allow easy knowlege of how the player is and allows us to change displaying based on it.
	const int playing = 0; //Player is alive, run the game.
	const int dead = 1; //Player has died, stop logic and display message.
	const int difficultySelect = 2; //The game has started. Let the player choose to play in either easy or hard mode.
	//Higher number because it was added later and changing it is a great way to create bugs.

	//Start the game, let the player choose difficulty.
	int inGame = difficultySelect;

	//The game difficulty. Default to hard but the player can change this.
	bool difficulty = HARD;

	//A default constructor lets us initalize everything.
	GameStateJump();
	//Used for custom logic and displaying to the screen.
	void tick(double delta);
	void render(Screen *display);

	int gameScore; //The player's score in the current game.
	int highScore; //The player's high score in the HARD difficulty.
	int easyHighScore; //The player's high score in the EASY difficulty.

	//Helper methods to convert the scores to strings which can be drawn to the screen effectivly.
	//Returns a displayable string of the current score in the game.
	string getGameScore();
	//Returns a displayable string of the appropriate high score based on the current game mode.
	string getHighScore();
};
