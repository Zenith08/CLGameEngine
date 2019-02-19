//
//  GameObject.cpp
//  CommandLineAnimator
//
//  Created by Period 2 on 2019-02-14.
//  Copyright © 2019 Period 2. All rights reserved.
//

#include "GameObject.h"

void GameObject::tick(double delta) {
	//Update the bounding box position to the current coordinates.
	boundingBox.setCoordinates(position.x, position.y);
}

void GameObject::render(Screen *display) {
	//Draw the texture to the screen at the current position.
	display->draw(texture, position.x, position.y);
}
