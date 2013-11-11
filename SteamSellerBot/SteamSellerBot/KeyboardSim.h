#pragma once
class KeyboardSim
{
private:
	//converts user entered amounts (dollar and cents) into a useable form for simulateKeyPress
	int convertIntToHex(int oldValue);

	//for getting individual digits of numbers
	int getUserValueDigitsHUNDREDS(int fullNumber);
	int getUserValueDigitsTENS(int fullNumber);
	int getUserValueDigitsONES(int fullNumber);

public:
	//user cins these during main loop
	int dollarValue;
	int centValue;

	//simulates user key presses. used in entering amount of money into steam
	void simulateKeyPress(int);
	void enterValuesIntoSteam();

	KeyboardSim(void);
	~KeyboardSim(void);
};