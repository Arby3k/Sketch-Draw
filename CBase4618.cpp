#include "stdafx.h"
#include "CBase4618.h"



CBase4618::CBase4618(void) {

}

CBase4618::~CBase4618()
{

}

void CBase4618::run()
{

	do {
		
		draw();
		update();

	} while (cv::waitKey(1) != 'q');
	//imitation is the highest form of flattery
	mCControl.set_data(0, 37, 0);
	mCControl.set_data(0, 38, 0);
	mCControl.set_data(0, 39, 0);
}

