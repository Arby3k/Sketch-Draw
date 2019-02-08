#pragma once

#include "stdafx.h"
#include "CControl.h"
#include "opencv.hpp"


/** CBase4618.h
*
* Base Class for mini games
*
* @author Arbab Ahmed
*
* @version 0.1 -- 07 Feb 2019
*/
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

