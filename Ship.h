#pragma once
#include "SDL.h"


class Ship{


public:
	Ship();
	~Ship();

	SDL_Rect pos;		//Size and Location of ship
	int lives;

};

