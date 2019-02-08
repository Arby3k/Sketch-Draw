#include "stdafx.h"
#include "CBase4618.h"


CBase4618::CBase4618 (CControl _mCControl, cv::Mat _mCanvas)
{
	mCControl = _mCControl;
	mCanvas = _mCanvas;
}

CBase4618::CBase4618() {

}

CBase4618::~CBase4618()
{

}

void CBase4618::update()
{

}

void CBase4618::draw()
{

}

void CBase4618::run()
{

	do {
		
		draw();
		update();

	} while (cv::waitKey(1) != 'q');
}

