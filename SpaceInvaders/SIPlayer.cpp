#include "pch.h"
#include "SIPlayer.h"


SIPlayer::SIPlayer() : GameObject()
{
	for (int x = 0; x < 5; x++) {
		for (int y = 0; y < 5; y++) {
			texture[x][y] = ' ';
		}
	}

	//TODO Resize
	position = { 13, 4 };
	boundingBox = CollisionBox(1, 1, 1, 1);
}
