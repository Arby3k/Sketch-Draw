#include "stdafx.h"
#include "CAstroids.h"



#define BUT1 33
#define BUT2 32


SDL_Texture *shipTex, *rockTex;
//SDL_Rect srcS, destS;



CAstroids::CAstroids(int comport)
{

	mCControl.init_com(comport);
	window = SDL_CreateWindow("Test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1000, 800, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, 0);
		
	SDL_Surface *tmpSurface = IMG_Load("assets/Ship.png");
	shipTex = SDL_CreateTextureFromSurface(renderer, tmpSurface);
	SDL_FreeSurface(tmpSurface);

	

	tmpSurface = IMG_Load("assets/Rock.png");
	rockTex = SDL_CreateTextureFromSurface(renderer, tmpSurface);
	SDL_FreeSurface(tmpSurface);

	ship.lives = 3;
		
}


CAstroids::~CAstroids()
{
}

void CAstroids::update() {
	cnt++;
	
	ship.pos.w = 64;
	ship.pos.h = 64;

	float tmpX;
	float tmpY;

	mCControl.get_analog(tmpX, tmpY);

	ship.pos.x = (tmpX * 1.2) - 125;
	ship.pos.y = ((800 - tmpY) * 1.25) + 5;

	std::cout <<"X: " << ship.pos.x << "   Y:" << ship.pos.y << "\n";

	if (ship.pos.y >= 736) {
		ship.pos.y = 736;
	}
	if (ship.pos.y <= 0) {
		ship.pos.y = 0;
	}

	if (ship.pos.x >= 936) {
		ship.pos.x = 936;
	}
	if (ship.pos.x <= 0) {
		ship.pos.x = 0;
	}
	
	/*
	static int data;
	static int newData = 1;
	static int counter = 1;

	mCControl.get_data(0, BUT2, data);

	if (data == newData)
		counter = 1;
	else {
		counter -= 1;
		if (counter == 0) {
			newData = data;

			if (newData == 0 && counter == 0) {
				destS.x = 0;
				destS.y = 0;
				//Sleep(10);
				counter = 1;
				//cout << "Button has been pressed: " << count << "times\r";
			}
		}

	}


*/

	
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, shipTex, NULL, &ship.pos);

	for (int i = 0; i < rocks.size(); i++) {
		SDL_RenderCopy(renderer, rockTex, NULL, &rocks[i].pos);
	}

	SDL_RenderPresent(renderer);
}

void CAstroids::draw() {
	Rock r;

	if (cnt % 10 == 0) {
		
		r.pos.w = 28;
		r.pos.h = 22;
		r.pos.x = cnt;
		r.pos.y = cnt - 5;
		rocks.push_back(r);
	}

	std::string lives = std::to_string(ship.lives);
	cv::putText(mCanvas, lives, cv::Size(450, 50), CV_FONT_HERSHEY_PLAIN, 2, cv::Scalar(100, 255, 100), 2);



}


	//use count to create a rock at specfic time


	//SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);

	/*
	Load screen make it look pretty (Score lives ship and asteroids)

	Spawn astroids as the game moves forward
		Move ship with inputs from the MSP
		Fire rockets with button press from MSP

	Ship / Asteroid collision = -1 life
	Ship / Wall collision = -1 life
	Missle / Asteroid Collision = asteroid destruction and increase in score

	Asteroid/Asteroid collision = nothing they can move about. 
	Wall / Asteroid collision = bounced asteroid

	*/
