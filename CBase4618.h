#pragma once

#include "stdafx.h"
#include "CControl.cpp"
#include "opencv.hpp"

class CBase4618
{
public:

	CBase4618();

	~CBase4618();

	virtual void update() = 0;

	virtual void draw() = 0;

	void run();

	CControl mCControl;
	cv::Mat mCanvas;

};

