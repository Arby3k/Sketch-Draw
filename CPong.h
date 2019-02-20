#pragma once
#include "stdafx.h"
#include "CBase4618.h"

class CPong:public CBase4618{


public:

	/** CPong.h
	*
	* A very simple game of pong
	*
	* @author Arbab Ahmed
	*
	* @version 0.1 -- 14 Feb 2019
	*/
	CPong(int, int, int);
	~CPong();

	/** Update things
	*
	*
	*
	*/
	void update();

	/** Draw things
	*
	*
	*
	*/

	void draw();

	int BGR;

private:

	float prevX;
	float prevY;

	 float rawX;
	 float rawY;
	 float posX;
	 float posY;
};

