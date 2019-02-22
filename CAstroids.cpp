#include "stdafx.h"
#include "CAstroids.h"



#define BUT1 33
#define BUT2 32


SDL_Texture *shipTex, *rockTex, *missTex, *lifeTexture, *scoreTexture;
SDL_Color textColor = { 255, 255, 255 };
std::string Life_Text, Score_Text;
//SDL_Rect srcS, destS;

Rock r;
Missile m;




CAstroids::CAstroids(int comport)
{

	mCControl.init_com(comport);
	window = SDL_CreateWindow("Test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1000, 800, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, 0);
	
	std::string textureText;

	SDL_Surface *tmpSurface = IMG_Load("assets/Ship.png");
	shipTex = SDL_CreateTextureFromSurface(renderer, tmpSurface);
	SDL_FreeSurface(tmpSurface);
	
	tmpSurface = IMG_Load("assets/Rock.png");
	rockTex = SDL_CreateTextureFromSurface(renderer, tmpSurface);
	SDL_FreeSurface(tmpSurface);

	tmpSurface = IMG_Load("assets/missile.png");
	missTex = SDL_CreateTextureFromSurface(renderer, tmpSurface);
	SDL_FreeSurface(tmpSurface);

	font = TTF_OpenFont("assets/arial.ttf", 16);

	ship.lives = 10;
	ship.score = 0;

	Life_Text = "Lives:  " + std::to_string(ship.lives);
	Score_Text = "Score:" + std::to_string(ship.score);

	SDL_Surface *textSurface = TTF_RenderText_Solid(font, Life_Text.c_str(), textColor);
	lifeTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
	SDL_FreeSurface(textSurface);



}


CAstroids::~CAstroids()
{

}

void CAstroids::update() {
	cnt++;
	
	SDL_QueryTexture(lifeTexture, nullptr, nullptr, &ship.LIFE.w, &ship.LIFE.h);
	SDL_QueryTexture(scoreTexture, nullptr, nullptr, &ship.SCORE.w, &ship.SCORE.h);

	ship.LIFE.x = 990 - ship.LIFE.w;
	ship.LIFE.y = 10;
	ship.SCORE.x = 990 - ship.SCORE.w;
	ship.SCORE.y = 10 + ship.LIFE.h;

	ship.pos.w = 50;
	ship.pos.h = 64;

	float tmpX;
	float tmpY;

	mCControl.get_analog(tmpX, tmpY);

	ship.pos.x = (tmpX * 1.2) - 125;
	ship.pos.y = ((800 - tmpY) * 1.25) + 5;

	ship.leftShip = ship.pos.x;
	ship.rightShip = ship.pos.x + ship.pos.w;
	ship.topShip = ship.pos.y;
	ship.bottomShip = ship.pos.y + ship.pos.h;
	

	if (ship.pos.y >= 736) {
		ship.pos.y = 736;
	}
	if (ship.pos.y <= 0) {
		ship.pos.y = 0;
	}

	if (ship.pos.x >= 950) {
		ship.pos.x = 950;
	}
	if (ship.pos.x <= 0) {
		ship.pos.x = 0;
	}
	
	// Missile / asteroid detection
	for (int i = 0; i < rocks.size(); i++) {
		for (int j = 0; j < missiles.size(); j++) {

			//If the leftmost or rightmost point of the first sprite lies somewhere inside the second, continue.
			if ((rocks[i].leftRock >= missiles[j].leftM  && rocks[i].leftRock <= missiles[j].rightM) ||
				(rocks[i].rightRock >= missiles[j].leftM && rocks[i].rightRock <= missiles[j].rightM)) {
				//Now we look at the y axis:
				if ((rocks[i].topRock >= missiles[j].topM  && rocks[i].topRock <= missiles[j].bottomM) ||
					(rocks[i].bottomRock >= missiles[j].topM  && rocks[i].bottomRock <= missiles[j].bottomM)) {
					//The sprites appear to overlap.
					missiles[j].hit = 1; //that missile has been hit
					rocks[i].hit = 1;    // that rock has been hit
					ship.score += 100;

				}
			}
		}
	}


	for (int i = 0; i < rocks.size(); i++) {
		if (rocks[i].hit == 1) {
			rocks.erase(rocks.begin() + i);
		}
	}

	for (int i = 0; i < missiles.size(); i++) {
		if (missiles[i].hit == 1) {
			missiles.erase(missiles.begin() + i);
		}
	}
	
	
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, shipTex, NULL, &ship.pos);

	for (int i = 0; i < rocks.size(); i++) {
		SDL_RenderCopy(renderer, rockTex, NULL, &rocks[i].pos);
	}
	for (int i = 0; i < missiles.size(); i++) {
		SDL_RenderCopy(renderer, missTex, NULL, &missiles[i].pos);
	}

	
	//Render Text on screen

	Life_Text = "Lives:  " + std::to_string(ship.lives);
	SDL_Surface *textSurface = TTF_RenderText_Solid(font, Life_Text.c_str(), textColor);
	lifeTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
	SDL_FreeSurface(textSurface);
	SDL_RenderCopy(renderer, lifeTexture, nullptr, &ship.LIFE);

	Life_Text = "Score:  " + std::to_string(ship.score);
	textSurface = TTF_RenderText_Solid(font, Life_Text.c_str(), textColor);
	scoreTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
	SDL_FreeSurface(textSurface);
	SDL_RenderCopy(renderer, scoreTexture, nullptr, &ship.SCORE);

	SDL_RenderPresent(renderer);
}

void CAstroids::draw() {

		m.pos.w = 10;
		m.pos.h = 25;

	if (cnt % 150 == 0 && rocks.size() < 10) {
		
		float rand = std::rand() % 70 + 40;
		float rand2 = std::rand() % 70 + 40;

		int randR = std::rand() % 7 - 3;
		int randR2 = std::rand() % 3 + 1;

		r.velX = randR;
		r.velY = randR2;

		r.pos.w = rand ;
		r.pos.h = rand2;
		
		r.pos.x = std::rand() % 940 + 1;
		r.pos.y = -5;

		r.leftRock = r.pos.x;
		r.rightRock = r.pos.x + r.pos.w;
		r.topRock = r.pos.y;
		r.bottomRock= r.pos.y + r.pos.h;

		rocks.push_back(r);
		std::cout << rocks[0].leftRock << "\n";
	}
	
	for (int i = 0; i < rocks.size(); i++) {

		if (rocks[i].leftRock <= 0) {
			rocks[i].velX = rocks[i].velX * (-1);
			//std::cout << rocks[0].velX << "\n";
		}

		if (rocks[i].rightRock >= 1000) {
			rocks[i].velX = rocks[i].velX * (-1);
			//std::cout << rocks[i].velX << "\n";
		}

		if (rocks[i].bottomRock >= 800) {
			rocks.erase(rocks.begin() + i);
		}
		
	}
	

	for (int i = 0; i < rocks.size(); i++) {
		
		rocks[i].pos.y += rocks[i].velY;
		rocks[i].pos.x += rocks[i].velX;

		rocks[i].leftRock = rocks[i].pos.x;
		rocks[i].rightRock = rocks[i].pos.x + rocks[i].pos.w;
		rocks[i].topRock = rocks[i].pos.y;
		rocks[i].bottomRock = rocks[i].pos.y + rocks[i].pos.h;
		
	}

	static int data;
	static int newData = 1;
	static int counter = 1;

	mCControl.get_data(0, BUT1, data);

	if (data == newData)
		counter = 1;
	else {
		counter -= 1;
		if (counter == 0) {
			newData = data;

			if (newData == 0 && counter == 0 && missiles.size() <= 4) {

				m.pos.x = ship.pos.x + (ship.pos.w / 2);
				m.pos.y = ship.pos.y;

				m.leftM = m.pos.x;
				m.rightM = m.pos.x + m.pos.w;
				m.topM = m.pos.y;
				m.bottomM = m.pos.y + m.pos.h;


				missiles.push_back(m);
				counter = 1;

			}
		}

	}

	static int data2;
	static int newData2 = 1;
	static int counter2 = 1;

	mCControl.get_data(0, BUT2, data2);

	if (data2 == newData2)
		counter2 = 1;
	else {
		counter2 -= 1;
		if (counter2 == 0) {
			newData2 = data2;

			if (newData2 == 0 && counter2 == 0 ) {

				ship.lives = 10;
				ship.score = 0;
				missiles.clear();
				rocks.clear();

				counter = 1;

			}
		}

	}
	
	for (int i = 0; i < missiles.size(); i++) {
		int velocity = -3;
		missiles[i].pos.y += velocity;
	
		missiles[i].leftM = missiles[i].pos.x;
		missiles[i].rightM = missiles[i].pos.x + missiles[i].pos.w;
		missiles[i].topM = missiles[i].pos.y;
		missiles[i].bottomM = missiles[i].pos.y + missiles[i].pos.h;
		
		if (missiles[i].pos.y <= -4) {
			missiles.erase(missiles.begin() + i);
		}
				
	}




	//Ship / asteroid detection
	for (int i = 0; i < rocks.size(); i++) {
		
			//If the leftmost or rightmost point of the first sprite lies somewhere inside the second, continue.
			if ((rocks[i].leftRock >= ship.leftShip  && rocks[i].leftRock <= ship.rightShip) ||
				(rocks[i].rightRock >= ship.leftShip && rocks[i].rightRock <= ship.rightShip)) {
				//Now we look at the y axis:
				if ((rocks[i].topRock >= ship.topShip  && rocks[i].topRock <= ship.bottomShip) ||
					(rocks[i].bottomRock >= ship.topShip  && rocks[i].bottomRock <= ship.bottomShip)) {
					//The sprites appear to overlap.
					
					rocks.erase(rocks.begin() + i);
					ship.score -= 50;
					ship.lives--;


				}
			}
		
	}

	if (ship.lives == 0){

		ship.lives = 10;
		ship.score = 0;
		missiles.clear();
		rocks.clear();
	
	}

}
