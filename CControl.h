#pragma once

#include "stdafx.h"
#include "Serial.h"

/** CControl.h
*
* A very simple control class
*
* @author Arbab Ahmed
*
* @version 0.1 -- 24 January 2019
*/
class CControl {

public:
	/** Prints main menu
	*
	*
	*/
	void printMenu();
	
	Serial _com; 

	CControl();
	~CControl();

	/** Initiates comport.
	*
	* @param comport the comport MSP is connected to
	*/
	void init_com(int comport);

	/** Writes a string of bytes to the serial port to get data according to type selected
	*
	* @param type      DIGITAL ANALOG or SERVO
	* @param channel   The channel this is on
	* @param result    The output from this channel
	*
	* 
	*/
	bool get_data(int type, int channel, int &result);

	/** Writes a string of bytes to the serial port to set data according to type selected
	*
	* @param type      DIGITAL ANALOG or SERVO
	* @param channel   The channel this is on
	* @param val       The value being set to this channel
	*
	*
	*/
	bool set_data(int type, int channel, int val);

};