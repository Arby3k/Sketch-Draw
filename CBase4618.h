#pragma once

#include "stdafx.h"
#include "CControl.cpp"
#include "opencv.hpp"

class CBase4618
{
	
protected:
	CControl mCControl;
	cv::Mat mCanvas;

public:
	CBase4618(CControl mCControl, cv::Mat mCanvas);
	
	CBase4618();

	~CBase4618();

	virtual void update();

	virtual void draw();

	void run();
};

