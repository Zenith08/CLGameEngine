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

//An example derrived game state.
class GameStateJump : public GameState {
public:
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

	GameStateJump();
	void tick(double delta);
	void render(Screen *display);
};

#endif /* GameStateJump_hpp */
