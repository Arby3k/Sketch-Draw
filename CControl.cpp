#include "Stdafx.h"
#include "CControl.h"
//#include "Client.h"
#include "Server.h"
#include "Serial.h"

#include <string>
#include <iostream>
#include <thread>

#include "opencv.hpp"


using namespace std;


void CControl::printMenu() {
	std::cout << "**************************************** \n"
		<< "Embedded System Control \n"
		<< "**************************************** \n\n"
		<< "(A)nalog Read \n"
		<< "(D)igital Read/Write \n"
		<< "(S)ervo Dance \n"
		<< "(B)utton Test \n"
		<< "(Q)uit \n"
		<< "\nCommand:";
}

CControl::CControl()
{
}
CControl::~CControl()
{
	//imitation is the highest form of flattery
	set_data(0, 37, 0);
	set_data(0, 38, 0);
	set_data(0, 39, 0);
}

void CControl::init_com(int comport) {
	// Comport class
	string cmprt = "COM" + to_string(comport);
	_com.open(cmprt);
}

bool CControl::get_data(int type, int channel, int &result) {
	// TX and RX strings
	std::string tx_str = "G " + to_string(type) + " " + to_string(channel) + "\n";
	std::string rx_str;

	// temporary storage
	char buff[2];

	// Send TX string
	_com.write(tx_str.c_str(), tx_str.length());
	Sleep(1); // wait for ADC conversion, etc. May not be needed?

	rx_str = "";
	// start timeout count
	double start_time = cv::getTickCount();

	buff[0] = 0;
	// Read 1 byte and if an End Of Line then exit loop
	// Timeout after 1 second, if debugging step by step this will cause you to exit the loop
	while (buff[0] != '\n' && (cv::getTickCount() - start_time) / cv::getTickFrequency() < 1.0)
	{
		if (_com.read(buff, 1) > 0)
		{
			rx_str = rx_str + buff[0];
		}
	}

	//printf("\nRX: %s", rx_str.c_str());

	rx_str.erase(0, rx_str.find(" ") + 1);
	rx_str.erase(0, rx_str.find(" ") + 1);
	rx_str.erase(0, rx_str.find(" ") + 1);

	result = stof(rx_str.substr(0, rx_str.find(",")));

	return true;

}

bool CControl::set_data(int type, int channel, int val) {
	// TX and RX strings
	std::string tx_str = "S " + to_string(type) + " " + to_string(channel) + " " + to_string(val) + "\n";
	std::string rx_str;

	// temporary storage
	char buff[2];

	// Send TX string
	_com.write(tx_str.c_str(), tx_str.length());
	Sleep(1); // wait for ADC conversion, etc. May not be needed?

	rx_str = "";
	// start timeout count
	double start_time = cv::getTickCount();

	buff[0] = 0;
	// Read 1 byte and if an End Of Line then exit loop
	// Timeout after 1 second, if debugging step by step this will cause you to exit the loop
	while (buff[0] != '\n' && (cv::getTickCount() - start_time) / cv::getTickFrequency() < 1.0)
	{
		if (_com.read(buff, 1) > 0)
		{
			rx_str = rx_str + buff[0];
		}
	}

	//printf("\nRX: %s", rx_str.c_str());

	return true;

}

void CControl::get_analog(float &x, float &y) {
	int xNow;
	int yNow;

	CControl::get_data(1, 15, xNow);
	x = xNow;
	
	CControl::get_data(1, 9, yNow);
	y = yNow;
}


void CControl::get_button(int b, int &bState) {

	int data;
	int newData = 1;
	int counter = 1;
	
		get_data(0, b, data);

		if (data == newData)
			counter = 1;
		else {
			counter -= 1;
			if (counter == 0) {
				newData = data;

				if (newData == 0 && counter == 0) {
					bState = 1;
					Sleep(10);
					counter = 1;
					//cout << "Button has been pressed: " << count << "times\r";
				}
			}

		}

}