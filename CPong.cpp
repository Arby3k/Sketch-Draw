#include "stdafx.h"
#include "CPong.h"

#define BUT1 33
#define BUT2 32

CPong::CPong(int windowX, int windowY, int _comport)
{

	mCControl.init_com(_comport);
	mCanvas = cv::Mat::zeros(cv::Size(windowX, windowY), CV_8UC3);
	cv::line(mCanvas, cv::Size(500, 0), cv::Size(500, 800), cv::Scalar(0, 0, 255), 2, CV_AA, 0);
	cv::putText(mCanvas, "Test", cv::Size(0, 100), CV_FONT_HERSHEY_PLAIN, 2, cv::Scalar(100, 255, 100), 2);
	
	//cv::imshow("Window-of-Doom", mCanvas);

}


CPong::~CPong()
{
}

void CPong::update()
{
/*
	float rawPosX;
	float rawPosY;
	static float posY;
	static float posX;
	static float OldY = 800 / 2;
	static float OldX = 800 / 2;
	static int BGR = 1;
	int b1 = 0;
	int b2 = 0;
	float scale = 1.8;

	mCControl.get_analog(rawPosX, rawPosY);
	posY = 800 - rawPosY;
	posX = rawPosX;

	posX = (posX * scale) - 500;
	posY = (posY * scale) + 300;

	if (posX <= 0)
		posX = 0;

	if (posX >= 800)
		posX = 800;

	if (posY <= 0)
		posY = 0;

	if (posY >= 800)
		posY = 800;


	std::cout << "rawX: " << rawPosX << "  rawY: " << rawPosY << "\n";
	//std::cout << "X: " << posX << "  Y: " << posY << "\n";

	//mCControl.get_button(BUT2, b2);
	//std::cout <<"b2:" << b2 << "    BGR: " << BGR << "\r";

	//std::cout << b1 << "\r";


	int data;
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
				BGR++;
				Sleep(10);
				counter = 1;
				//cout << "Button has been pressed: " << count << "times\r";
			}
		}

	}


	if (BGR == 4) {
		BGR = 1;
	}


	if (BGR == 1)
	{
		mCControl.set_data(0, 39, 1);
		mCControl.set_data(0, 38, 0);
		mCControl.set_data(0, 37, 0);

		cv::line(mCanvas, cv::Size(OldX, OldY), cv::Size(posX, posY), cv::Scalar(0, 0, 255), 2, CV_AA, 0);
		OldX = posX;
		OldY = posY;

	}
	else if (BGR == 2)
	{
		mCControl.set_data(0, 39, 0);
		mCControl.set_data(0, 38, 1);
		mCControl.set_data(0, 37, 0);
		cv::line(mCanvas, cv::Size(OldX, OldY), cv::Size(posX, posY), cv::Scalar(0, 255, 0), 2, CV_AA, 0);
		OldX = posX;
		OldY = posY;
	}
	else if (BGR == 3)
	{
		mCControl.set_data(0, 39, 0);
		mCControl.set_data(0, 38, 0);
		mCControl.set_data(0, 37, 1);
		cv::line(mCanvas, cv::Size(OldX, OldY), cv::Size(posX, posY), cv::Scalar(255, 0, 0), 2, CV_AA, 0);
		OldX = posX;
		OldY = posY;
	}




	mCControl.get_button(BUT1, b1);
	if (b1 == 1) {
		mCanvas = cv::Mat::zeros(mCanvas.size(), mCanvas.type()); //Blanked image from online
		std::cout << "\rclear";
	}

	*/
     cv::imshow("Window-of-Doom", mCanvas);
}

void CPong::draw()
{
	static float rawX;
	static float rawY;
	static float posX;
	static float posY;

	mCControl.get_analog(rawX, rawY);
	posY = rawY * .75;
	if (posY >= 700) {
		posY = 700;
	}
	posX = rawX;

	cv::rectangle(mCanvas, cv::Size(2, posY), cv::Size(6, posY+100), cv::Scalar(255, 0, 0), CV_FILLED, CV_AA, 0);

	cv::Mat::zeros(mCanvas.size(),mCanvas.type());
}