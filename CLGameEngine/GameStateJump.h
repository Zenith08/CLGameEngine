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

//An example derrived game state.
class GameStateJump : public GameState {
public:
	GameStateJump();
	void tick(double delta);
	void render(Screen *display);
};

#endif /* GameStateJump_hpp */
