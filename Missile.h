#pragma once
#include "SDL.h"

class Missile
{
public:
	Missile();
	~Missile();

	SDL_Rect pos; //missile postion/size

	int leftM, rightM;
	int topM, bottomM;

	int hit = 0;

};

