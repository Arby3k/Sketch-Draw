#pragma once
#include "SDL.h"


class Ship{


public:
	Ship();
	~Ship();

	SDL_Rect pos;		//Size and Location of ship
	SDL_Rect LIFE;
	SDL_Rect SCORE;

	int leftShip, rightShip;
	int topShip, bottomShip;



	int lives;
	int score;

	bool hit = false;


};

