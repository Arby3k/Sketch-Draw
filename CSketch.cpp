#include "stdafx.h"
#include "CSketch.h"
#include <iostream>
#include <cstdlib>
#include <cmath>



CSketch::CSketch(cv::Size window, int _comport)
{

	mCControl.init_com(5);
	mCanvas = cv::Mat::zeros(cv::Size(window, window), CV_8UC3);
	cv::imshow("Window-of-Doom", mCanvas);


}


CSketch::~CSketch()
{
}
