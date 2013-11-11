#include "stdafx.h"
#include "KeyboardSim.h"
#include <iostream>
#include "windows.h"

KeyboardSim::KeyboardSim(void){
	int dollarValue = 0;
	int centValue = 0;
}

void KeyboardSim::enterValuesIntoSteam(){
	//full dollar amount

	//3 digit dollar
	if(dollarValue > 99){
		Sleep(200);
		simulateKeyPress(convertIntToHex(getUserValueDigitsONES(dollarValue)));
		Sleep(200);
		simulateKeyPress(convertIntToHex(getUserValueDigitsTENS(dollarValue)));
		Sleep(200);
		simulateKeyPress(convertIntToHex(getUserValueDigitsHUNDREDS(dollarValue)));
	//2 digit dollar
	} else if(dollarValue > 9){
		Sleep(200);
		simulateKeyPress(convertIntToHex(getUserValueDigitsTENS(dollarValue)));
		Sleep(200);
		simulateKeyPress(convertIntToHex(getUserValueDigitsHUNDREDS(dollarValue)));
	//1 digit dollar
	}else if(dollarValue >= 0){
		Sleep(200);
		simulateKeyPress(convertIntToHex(dollarValue));
	}
	Sleep(200);

	simulateKeyPress(0xBE);//.

	//cent amount
	Sleep(200);
	simulateKeyPress(convertIntToHex(getUserValueDigitsTENS(centValue)));
	Sleep(200);
	simulateKeyPress(convertIntToHex(getUserValueDigitsHUNDREDS(centValue)));
}

//Keyboard Click---------------------------
void KeyboardSim::simulateKeyPress(int x){
	INPUT ip;

	ip.type = INPUT_KEYBOARD;
	ip.ki.wScan = 0;
	ip.ki.time = 0;
	ip.ki.dwExtraInfo = 0;

	ip.ki.wVk = x;//0x41;
	ip.ki.dwFlags = 0;
	SendInput(1, &ip, sizeof(INPUT));

	//keyup
	ip.ki.dwFlags = KEYEVENTF_KEYUP;
	SendInput(1, &ip, sizeof(INPUT));
}

//takes a number (216) and gets 6
int KeyboardSim::getUserValueDigitsHUNDREDS(int fullNumber){
	int hundredsPlace = 0;
	hundredsPlace = fullNumber % 10;
	return hundredsPlace;
}

//takes a number (216) and gets 1
int KeyboardSim::getUserValueDigitsTENS(int fullNumber){
	int tensPlace = 0;
	tensPlace = fullNumber / 10 % 10;
	return tensPlace;
}

//takes a number (216) and gets 2
int KeyboardSim::getUserValueDigitsONES(int fullNumber){
	int onesPlace = 0;
	onesPlace = fullNumber / 100 % 10;
	return onesPlace;
}

//takes a integer and turns it into a hex number for sim keyboard
int KeyboardSim::convertIntToHex(int oldValue){	
	int newValue = 0;	
	switch (oldValue){
	case 0: newValue = 0x30;
		break;
	case 1:	newValue = 0x31;
		break;
	case 2: newValue = 0x32;
		break;
	case 3:	newValue = 0x33;
		break;
	case 4: newValue = 0x34;
		break;
	case 5: newValue = 0x35;
		break;
	case 6: newValue = 0x36;
		break;
	case 7:	newValue = 0x37;
		break;
	case 8: newValue = 0x38;
		break;
	case 9:	newValue = 0x39;
		break;
	}
	return newValue;
}

KeyboardSim::~KeyboardSim(void){
}