#include "stdafx.h"
#include "CSketch.h"
#include <iostream>
#include <cstdlib>
#include <cmath>



CSketch::CSketch(cv::Size window, int _comport)
{
	BGR = 1;
	//_com = _comport;
	drawWindow = window;

	mCControl.init_com(5);

	mCanvas.zeros(cv::Size(window, window), CV_8UC3);

	cv::Mat img(cv::Size(window, window), CV_8UC3, cv::Scalar(0, 0, 0));

	mCanvas = img;

}


CSketch::~CSketch()
{
}
