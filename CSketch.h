#pragma once


#include "stdafx.h"
#include "CControl.h"
#include "CBase4618.h"

class CSketch : public CBase4618
{
public:
	CSketch(cv::Size, int);
	~CSketch();

	void update(double &xPosition, double &yPosition);

	void draw(int x, int y);
	bool btnPressed(int gpioPin);


private:
	cv::Size drawWindow;
	int BGR;

};

