#include "stdafx.h"
#include "CPong.h"

#define BUT1 33
#define BUT2 32

CPong::CPong(int windowX, int windowY, int _comport)
{

	mCControl.init_com(_comport);
	mCanvas = cv::Mat::zeros(cv::Size(windowX, windowY), CV_8UC3);
	
	//cv::imshow("Window-of-Doom", mCanvas);

}


CPong::~CPong()
{
}

void CPong::update()
{

     cv::imshow("Window-of-Doom", mCanvas);
	 mCanvas = cv::Mat::zeros(mCanvas.size(), mCanvas.type());
}

void CPong::draw()
{

	static float ballX = 500;
	static float ballY = 400;
	static float xspeed = -8;
	static float yspeed = 8;
	static float P2Pos;

	float rand = std::rand() % 40 -20;
	float rand2 = std::rand() % 40 -20;

	static int t = xspeed;
	static int u = yspeed;


	//rand = rand / 10;
	//rand2 = rand / 10;

	
	// Staic Game State Drawn before anything else to keep it "Under" everything else.
	static int score1 = 0;
	static int score2 = 0;

	std::string score1Str = std::to_string(score1);
	std::string score2Str = std::to_string(score2);

	cv::line(mCanvas, cv::Size(500, 0), cv::Size(500, 800), cv::Scalar(0, 0, 255), 2, CV_AA, 0);
	cv::line(mCanvas, cv::Size(0, 0), cv::Size(1000, 0), cv::Scalar(2500, 255, 255), 2, CV_AA, 0);
	cv::line(mCanvas, cv::Size(0, 800), cv::Size(1000, 800), cv::Scalar(2500, 255, 255), 2, CV_AA, 0);
	cv::putText(mCanvas, "Player 1", cv::Size(100, 50), CV_FONT_HERSHEY_PLAIN, 2, cv::Scalar(100, 255, 100), 2);
	cv::putText(mCanvas, "Player 2", cv::Size(700, 50), CV_FONT_HERSHEY_PLAIN, 2, cv::Scalar(100, 255, 100), 2);
	cv::putText(mCanvas, score1Str, cv::Size(450, 50), CV_FONT_HERSHEY_PLAIN, 2, cv::Scalar(100, 255, 100), 2);
	cv::putText(mCanvas, score2Str, cv::Size(530, 50), CV_FONT_HERSHEY_PLAIN, 2, cv::Scalar(100, 255, 100), 2);







	mCControl.get_analog(rawX, rawY);
	posY = rawY * .75;
	if (posY >= 700) {
		posY = 700;
	}
	if (posY <= 0) {
		posY = 0;
	}
	posX = rawX;

	//Player 1 Paddle
	cv::rectangle(mCanvas, cv::Size(5, 800-posY), cv::Size(20, 700-posY), cv::Scalar(255, 0, 0), CV_FILLED, CV_AA, 0);

	

	
	//Ball

	
	ballX = ballX + xspeed;
	ballY = ballY + yspeed;

	P2Pos = ballY - 50;
	std::cout <<"rand:" << rand << "\r";
	
	cv::circle(mCanvas, cv::Point(ballX, ballY), 20, cv::Scalar(150, 150, 150), CV_FILLED, 1, 0);

	if (((ballY + 15) > 800) || ((ballY - 15) < 0)) {
		yspeed = (yspeed * -1);
	}
		
	if (((ballX - 10) < 25) && ((ballY + 5) <= (820 - posY) && (ballY - 5) >= (680 - posY))) {
		xspeed = (xspeed * -1);
	}

	if (((ballX - 10) < 10)){

		score2++;
		ballX = 500;
		ballY = 400;
		if (rand < 0) {
			xspeed = -t;
		}

		if (rand > 0) {
			xspeed = t;
		}

		if (rand2 < 0) {
			yspeed = -u;
		}

		if (rand2 > 0) {
			yspeed = u;
		}
	}



	//Player 2 Paddle

	if (P2Pos >= 700) {
		P2Pos = 700;
	}
	if (P2Pos <= 0) {
		P2Pos = 0;
	}
	cv::rectangle(mCanvas, cv::Size(980, P2Pos), cv::Size(995, P2Pos + 100), cv::Scalar(0, 255, 255), CV_FILLED, CV_AA, 0);
	
	if (((ballX + 10) > 980)) {
		xspeed = (xspeed * -1);
	}

	if (score2 == 5) {
		mCanvas = cv::Mat::zeros(mCanvas.size(), mCanvas.type());
		cv::imshow("Window-of-Doom", mCanvas);

		do {

		cv::putText(mCanvas, "You LOST!", cv::Size(300, 400), CV_FONT_HERSHEY_PLAIN, 4, cv::Scalar(100, 255, 100), 2);
		cv::imshow("Window-of-Doom", mCanvas);

		} while (cv::waitKey(1) != 'q');

		score2 = 0;
		ballX = 500;
		ballY = 400;
		xspeed = t;
		yspeed = u;
	}
}