#pragma once

#include "stdafx.h"
#include "CBase4618.h"


/** CSketch.h
*
* A very simple sketch class
*
* @author Arbab Ahmed
*
* @version 0.1 -- 07 Feb 2019
*/
class CSketch : public CBase4618 {

public:


	CSketch(int, int);
	~CSketch();

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

