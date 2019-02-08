////////////////////////////////////////////////////////////////
// HURT MY HEAD PROJECT
////////////////////////////////////////////////////////////////
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

using namespace std;

enum type { DIGITAL, ANALOG, SERVO };
CBase4618::mCControl MSP;


/*
//void process_msg()
//{
//  MSG msg;
//  while (::PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
//  {
//    ::TranslateMessage(&msg);
//    ::DispatchMessage(&msg);
//  }
//}
//
//////////////////////////////////////////////////////////////////
//// Serial Communication
//////////////////////////////////////////////////////////////////
//void test_com()
//{
//  // Comport class
//  Serial com;
//  com.open("COM3");
//
//  // TX and RX strings
//  std::string tx_str = "S 2 0 100\n";
//  std::string rx_str;
//
//  // temporary storage
//  char buff[2];
//  do
//  {
//    // Send TX string
//		com.write(tx_str.c_str(), tx_str.length());
//    Sleep(10); // wait for ADC conversion, etc. May not be needed?
//  
//    rx_str = "";
//    // start timeout count
//    double start_time = cv::getTickCount();
//
//    buff[0] = 0;
//		// Read 1 byte and if an End Of Line then exit loop
//    // Timeout after 1 second, if debugging step by step this will cause you to exit the loop
//    while (buff[0] != '\n' && (cv::getTickCount() - start_time) / cv::getTickFrequency() < 1.0)
//    {
//      if (com.read(buff, 1) > 0)
//      {
//        rx_str = rx_str + buff[0];
//      }
//    }
//
//    printf ("\nRX: %s", rx_str.c_str());
//  } 
//  while (1);
//}
*/


////////////////////////////////////////////////////////////////
// Display Image on screen
////////////////////////////////////////////////////////////////
/*

void do_image()
{
  cv::Mat im;

  im = cv::imread("BCIT.jpg");

  srand(time(0));

  for (int i = 0; i < 500; i++)
  {
    float radius = 50 * rand() / RAND_MAX;
    cv::Point center = cv::Point(im.size().width*rand() / RAND_MAX, im.size().height*rand() / RAND_MAX);
    
    cv::circle(im, center, radius, cv::Scalar(200, 200, 200), 1, cv::LINE_AA);
    
    im.at<char>(i,i) = 255;
    
    cv::imshow("Image", im);
    cv::waitKey(1);
  }
}

*/

//////////////////////////////////////////////////////////////////
//// Display Video on screen
//////////////////////////////////////////////////////////////////
//void do_video()
//{
//  cv::VideoCapture vid;
//
//  vid.open(0);
//
//  if (vid.isOpened() == TRUE)
//  {
//    do
//    {
//      cv::Mat frame, edges;
//      vid >> frame;
//      if (frame.empty() == false)
//      {
//        cv::cvtColor(frame, edges, cv::COLOR_BGR2GRAY);
//        cv::GaussianBlur(edges, edges, cv::Size(7, 7), 1.5, 1.5);
//        cv::Canny(edges, edges, 0, 30, 3);
//        cv::imshow("edges", edges);
//      }
//    }
//    while (cv::waitKey(10) != ' ');
//  }      
//}		
//    
//
//////////////////////////////////////////////////////////////////
//// Demo client server communication
//////////////////////////////////////////////////////////////////
//Server serv;
//
//// Start TCP server
//void serverfunc()
//{
//  serv.start(4618);
//}
//
//// Send image to TCP server
//void serverimagefunc()
//{
//  cv::VideoCapture vid;
//
//  vid.open(0);
//
//  if (vid.isOpened() == TRUE)
//  {
//    do
//    {
//      cv::Mat frame;
//      vid >> frame;
//      serv.set_txim(frame);
//    }
//    while (cv::waitKey(10) != ' ');
//  }
//}
//
//void clientserver()
//{
//  std::string str;
//  cv::Mat im;
//
//  // Start server
//  std::thread t1(&serverfunc);
//  t1.detach();
//
//  // Start image send to server
//  std::thread t2(&serverimagefunc);
//  t2.detach();
//
//  // Wait until server starts up (webcam is slow)
//  Sleep(2000);
//
//  // connect
//  Client client(4618, "127.0.0.1");
//  //Client client(4618, "192.168.1.80");
//
//  // Wait until server starts up (webcam is slow)
//  Sleep(500);
//
//  client.tx_str("cmd");
//  do
//  {
//    client.rx_str(str);
//    if (str.length() > 0)
//    {
//      std::cout << "\nClient Rx: " << str;
//    }
//  } while (str.length() == 0);
//
//  int count = 0;
//  while (1)
//  {
//    client.tx_str("im");
//
//    if (client.rx_im(im) == TRUE)
//    {
//      if (im.empty() == false)
//      {
//        count++;
//        std::cout << "\nImage received: " << count;
//        cv::imshow("rx", im);
//        cv::waitKey(100);
//      }
//    }
//  }
//}

int main(int argc, char* argv[])
{
	//test_com();
	//do_image();
	//do_video ();
    //clientserver();

	MSP.init_com(5);
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

	return 0;

}
