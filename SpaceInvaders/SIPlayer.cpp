#include "pch.h"
#include "SIPlayer.h"
#include "GameInput.h"
#include "GameEngine.h"
#include "GSSpaceInvaders.h"


SIPlayer::SIPlayer() : GameObject()
{
	clearTexture();

	texture[0][0] = '/';
	texture[1][0] = '*';
	texture[2][0] = '\\';
	texture[0][1] = '|';
	texture[1][1] = '+';
	texture[2][1] = '|';

	position = { 6, 13 };
	boundingBox = CollisionBox(position.x, position.y, 3, 2);
}

void SIPlayer::tick(double delta)
{
	if (input::getPressed() == 77) { //Left
		boundingBox.setCoordinates(boundingBox.x + 1, boundingBox.y);
		if (!game::getCurrentState()->overlapsStatic(this)) {
			//std::cout << "no collision" << endl;
			position.x += 1;
			input::usedPress();
		}
	}
	else if (input::getPressed() == 75) { //Right
		boundingBox.setCoordinates(boundingBox.x - 1, boundingBox.y);
		if (!game::getCurrentState()->overlapsStatic(this)) {
			//std::cout << "no collision" << endl;
			position.x -= 1;
			input::usedPress();
		}
	}
	else if (input::getPressed() == 72) { //Up arrow, fire.
		GSSpaceInvaders *stateInvaders = dynamic_cast<GSSpaceInvaders*>(game::getCurrentState());
		stateInvaders->addShot(GameObjectShot(1, { position.x + 1, position.y }, PLAYER));
		input::usedPress();
	}
	GameObject::tick(delta);
}

void SIPlayer::render(Screen * display)
{
	GameObject::render(display);
}

bool SIPlayer::damage(int damage)
{
	life -= damage;
	if (life <= 0) {
		return true;
	}
	else {
		return false;
	}
}

void SIPlayer::respawn()
{
	life = MAX_LIFE;
	position = { 6, 13 };
}

int SIPlayer::getLife()
{
	return life;
}
