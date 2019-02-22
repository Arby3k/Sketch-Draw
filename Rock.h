#pragma once
#include "SDL.h"

class Rock
{
public:
	Rock();
	~Rock();

	SDL_Rect pos; //rock postion/size

	int leftRock, rightRock;
	int topRock, bottomRock;

	int velX;
	int velY;

	int hit =0;
		
};

