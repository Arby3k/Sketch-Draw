#pragma once

#include "stdafx.h"
#include "CBase4618.h"



class CSketch : public CBase4618 {

public:


	CSketch(int, int);
	~CSketch();

	/** update the screen things
	*
	*
	*
	*/
	void update();


	/** draw things
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

