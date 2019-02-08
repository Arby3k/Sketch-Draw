#include "stdafx.h"

#include <string>
#include <iostream>
#include <iomanip>
#include <thread>
#include <stdlib.h>
#include <conio.h>


//#include "Client.h"
#include "Server.h"
#include "Serial.h" // Must include Windows.h after Winsock2.h, so Serial must include after Client/Server

// OpenCV Include
#include "opencv.hpp"

// OpenCV Library
#pragma comment(lib,".\\opencv\\lib\\opencv_world310d.lib")

#include "Cbase4618.h"
#include "CControl.h"
#include "CSketch.h"

using namespace std;
enum type { DIGITAL, ANALOG, SERVO };



int main(int argc, char* argv[])
{
	//test_com();
	//do_image();
	//do_video ();
    //clientserver();

	//MSP.init_com(5);
	// Old code
	/*
	char inputSelect;
	//char q;

	do {
		MSP.printMenu();
		cin >> inputSelect;

		int data;
		int count = 0;

		switch (inputSelect) {

		case 'A':
		case 'a': {
			do {
				MSP.get_data(ANALOG, 9, data);
				cout << setw(40) <<"ANALOG TEST: Verticle Y = " << setw(6) << data  << setw(6) << "(" << data * 100 / 1024 << "%)";

				MSP.get_data(ANALOG, 15, data);
				cout << setw(40) << " Horizontal X = " << setw(6) << data << setw(6) << "(" << data * 100 / 1024 << "%)\r";
			} while (1);
			break;
		}
		case 'D':
		case 'd': {
			do{
				MSP.get_data(DIGITAL, 32, data);
				MSP.set_data(DIGITAL, 38, data);
				cout << "Digital input: Push Button 2 = " << data << "\r";
			} while (1);
			break;
		}
		case 'S':
		case 's': {

			do {
				MSP.set_data(SERVO, 0, 10);
				Sleep(1000);
				MSP.set_data(SERVO, 0, 160);
				Sleep(1000);
			} while (1);
			
			break;
		}
		case 'B':
		case 'b': {
			int newData = 1;
			int counter = 1;
			while (1) {
				MSP.get_data(DIGITAL, 33, data);
							
					if (data == newData)
						counter = 1;
					else {
						counter -= 1;
						if (counter == 0) {
							newData = data;
							
							if (newData == 0 && counter == 0) {
								count++;
								Sleep(30);
								counter = 1;
								cout << "Button has been pressed: " << count << "times\r";
							}
						}
						
					}

				
			}
			break;
		}

		case 'Q':
		case 'q':
			cout << "Quiting" << endl;
			exit(0);
			break;
		default:
			cout << "Command not found\n";
			inputSelect = 0;
			break;

		}
		if (inputSelect != 0) {
			cout << "Back to Main Menu?(y/n): ";
			cin >> inputSelect;
		}


	} while (inputSelect == 'Y' || inputSelect == 'y' || inputSelect == 0);

	*/

	CSketch etch(800, 5);

	etch.run();

	return 0;

}
