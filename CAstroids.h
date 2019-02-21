#pragma once
#include "stdafx.h"
#include "CBase4618.h"
#include "SDL.h"
#include "SDL_image.h"

#include <vector>

#include "Ship.h"
#include "Rock.h"
#include "missile.h"



class CAstroids:public CBase4618{


public:
	CAstroids(int);
	~CAstroids();

	/** Draw things
	*
	*
	*
	*/
	void draw();
	

	/** update the screen things
	*
	*
	*
	*/
	void update();
	

private:

	SDL_Renderer *renderer;
	SDL_Window *window;

	Ship ship;
	std::vector <Rock> rocks;
	std::vector <Missile> missiles;
	

	int cnt = 0;
};

