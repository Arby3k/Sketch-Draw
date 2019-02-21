#pragma once
#include "SDL.h"

class Rock
{
public:
	Rock();
	~Rock();

	SDL_Rect pos; //rock postion/size
	int hit;
		
};

