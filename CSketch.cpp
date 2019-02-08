#include "stdafx.h"
#include "CSketch.h"


CSketch::CSketch(int window, int _comport)
{

	mCControl.init_com(_comport);
	mCanvas = cv::Mat::zeros(cv::Size(window, window), CV_8UC3);
	cv::imshow("Window-of-Doom", mCanvas);
	
}


CSketch::~CSketch()
{
}

void CSketch::update()
{
	xPosition = _cctrl.get_analog(15);
	yPosition = 100 - _cctrl.get_analog(9);

	int data;
	//int color = 1;
	_cctrl.get_data(0, 33, data);

	//if (data == 0) {
	if (btnPressed(0)) {
		color++;
		if (color == 4)
			color = 1;
	}
	if (color == 1)
	{
		_cctrl.set_data(0, 39, 1);
		_cctrl.set_data(0, 38, 0);
		_cctrl.set_data(0, 37, 0);

	}
	else if (color == 2)
	{
		_cctrl.set_data(0, 39, 0);
		_cctrl.set_data(0, 38, 1);
		_cctrl.set_data(0, 37, 0);
	}
	else if (color == 3)
	{
		_cctrl.set_data(0, 39, 0);
		_cctrl.set_data(0, 38, 0);
		_cctrl.set_data(0, 37, 1);
	}
	int clear;
	_cctrl.get_data(0, 32, clear);
	if (clear == 0)
		mCanvas = cv::Mat::zeros(mCanvas.size(), mCanvas.type());
}

void CSketch::draw()
{
	cv::imshow("Window-of-Doom", mCanvas);
}