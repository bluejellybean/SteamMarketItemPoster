#include "stdafx.h"
#include <iostream>
#include "windows.h"
#include "KeyboardSim.h"
#include <vector>

#define SCROLLDOWN -120
#define SCROLLUP 1000

 void leftClick(){  
  INPUT    Input={0};
  // left down 
  Input.type      = INPUT_MOUSE;
  Input.mi.dwFlags  = MOUSEEVENTF_LEFTDOWN;
  ::SendInput(1,&Input,sizeof(INPUT));

  // left up
  ::ZeroMemory(&Input,sizeof(INPUT));
  Input.type      = INPUT_MOUSE;
  Input.mi.dwFlags  = MOUSEEVENTF_LEFTUP;
  ::SendInput(1,&Input,sizeof(INPUT));
}

 
void scrollWheelFunc(int scrollWheelAmount){

	for(int i = 0; i < scrollWheelAmount; i++){
//		std::cout<<"scrollwhellamount"<<scrollWheelAmount<<std::endl;
		mouse_event(MOUSEEVENTF_WHEEL, 0, 0, SCROLLDOWN, 0);
	}
}

void pageNumberClicker(int sleepTime, int pageNumber){
	Sleep(sleepTime);
	for(int z = 1; z < pageNumber; z++){
		SetCursorPos(1020,965);
		Sleep(sleepTime);
		leftClick();
	}
}

void scrollAndClickSell(int scrollWheelAmount, int sleepTime, int sellButtonYAxisPos){

			scrollWheelFunc(scrollWheelAmount);
			Sleep(sleepTime);
			SetCursorPos(1095,sellButtonYAxisPos);
			leftClick();
}

void slotClicker(int sleepTime,int slotNumber, int *slotAxis){
			slotNumber -= 1;
			SetCursorPos(slotAxis[slotNumber % 5],slotAxis[(slotNumber / 5) + 5]);
			Sleep(sleepTime);
			leftClick();
}

void mainLoops(int dValue, int cValue, int sleepTime,int pageNumber,int slotNumber, int scrollWheelAmount,int sellButtonYAxisPos){
	KeyboardSim nks;
	//1020,965 == next arrow
	//->this is now slotAxis[10]//985,890  == slot 25(will change this to have an array for all 25 slots)
	//1095,920 == first sell button(NEED to change this to accept different inputs because button moves with item)
	//620,755  == I agree to terms checkbox
	//1230,755 == ok, put up for sale button
	//1270,670 == final ok button

	//int xAxis[5]={573,673,773,873,973};
	//int yAxis[5]={477,577,677,777,877};
	//985,890    1095,920,  
	int points[6] = {620,755 ,1230,755,  1270,670};

	int slotAxis[10]={573,673,773,873,973,477,577,677,777,877};

	nks.dollarValue = dValue;
	nks.centValue = cValue;

	Sleep(sleepTime);

	int x = 0, y = 1;
	
		pageNumberClicker(sleepTime, pageNumber);

		slotClicker(sleepTime, slotNumber, slotAxis);

		scrollAndClickSell(scrollWheelAmount, sleepTime, sellButtonYAxisPos);

		Sleep(sleepTime);
		nks.enterValuesIntoSteam();

		for(int i = 0; i < 3; i++){
		Sleep(sleepTime);
		SetCursorPos(points[x],points[y]);	
		Sleep(sleepTime);
		leftClick();
		x+=2;
		y+=2;
	}
	////////refreshes page
	Sleep(3000);
	nks.simulateKeyPress(0x74);
}

 void mainSellFunction(int dValue, int cValue, int numberOfitemsToSell,int scrollWheelAmount, int sleepTime, int pageNumber, int slotNumber,int sellButtonYAxisPos){
	//this sleep is for clicking into steam
	//TODO: make steam focused on top then start
	Sleep(3000);
	SetCursorPos(200,835);
	Sleep(200);
	leftClick();

	mouse_event(MOUSEEVENTF_WHEEL, 0, 0, SCROLLUP, 0);
	Sleep(200);
	scrollWheelFunc(2);

	for(int i = 0; i < numberOfitemsToSell; i++){
		mainLoops(dValue, cValue, sleepTime, pageNumber, slotNumber,scrollWheelAmount, sellButtonYAxisPos);
	}
}