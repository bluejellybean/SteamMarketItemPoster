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

//scrollWheelDown
void scrollWheelFunc(int scrollWheelAmount){
	
	for(int i = 0; i < scrollWheelAmount; i++){
		mouse_event(MOUSEEVENTF_WHEEL, 0, 0, SCROLLDOWN, 0);
	}
}

//clicks the next page button x amount of times 
void pageNumberClicker(int sleepTime, int pageNumber){

	Sleep(sleepTime);
	for(int z = 1; z < pageNumber; z++){
		SetCursorPos(1020,965);
		Sleep(sleepTime);
		leftClick();
	}
}

//should allow scroll to sell buttons that are not located in range normally
void scrollAndClickSell(int scrollWheelAmount, int sleepTime, int sellButtonYAxisPos){

	scrollWheelFunc(scrollWheelAmount);
	Sleep(sleepTime);
	SetCursorPos(1095,sellButtonYAxisPos);
	leftClick();
}

//clicks slot in the inventory
void slotClicker(int sleepTime,int slotNumber, int *slotAxis){
	
	slotNumber -= 1;
	SetCursorPos(slotAxis[slotNumber % 5],slotAxis[(slotNumber / 5) + 5]);
	Sleep(sleepTime);
	leftClick();
}

//main selling loop
void mainLoops(int dValue, int cValue, int sleepTime,int pageNumber,int slotNumber, int scrollWheelAmount,int sellButtonYAxisPos){
	
	KeyboardSim nks;
	
	//620,755  == I agree to terms checkbox
	//1230,755 == ok, put up for sale button
	//1270,670 == final ok button
	int points[6] = {620,755 ,1230,755,  1270,670};
	
	//x and y for the inventory positions
	int slotAxis[10]={573,673,773,873,973,477,577,677,777,877};

	//for use with points array
	int x = 0, y = 1;
	nks.dollarValue = dValue;
	nks.centValue = cValue;

	Sleep(sleepTime);

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
	//hardcoded in an attempt to avoid refresh issues before steam allows
	Sleep(3000);

	//refreshes page
	nks.simulateKeyPress(0x74);
}

 void mainSellFunction(int dValue, int cValue, int numberOfitemsToSell,int scrollWheelAmount, int sleepTime, int pageNumber, int slotNumber,int sellButtonYAxisPos){
	
	 //buffer time
	Sleep(sleepTime);
	
	//Clicks into steam to get focus of the window
	//TODO: check if there is a better solution to this(windows api?)
	SetCursorPos(200,835);
	Sleep(200);
	leftClick();

	//scroll page all the way up
	mouse_event(MOUSEEVENTF_WHEEL, 0, 0, SCROLLUP, 0);
	Sleep(200);
	//scroll page down two clicks. allows page arrow to be visable
	scrollWheelFunc(2);

	//loops the main selling func
	for(int i = 0; i < numberOfitemsToSell; i++){
		mainLoops(dValue, cValue, sleepTime, pageNumber, slotNumber,scrollWheelAmount, sellButtonYAxisPos);
	}
}