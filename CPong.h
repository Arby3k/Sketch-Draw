#pragma once
#include "stdafx.h"
#include "CBase4618.h"

class CPong:public CBase4618{


public:


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
};

