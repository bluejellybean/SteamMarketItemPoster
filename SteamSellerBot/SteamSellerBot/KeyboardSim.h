#pragma once
class KeyboardSim
{
private:
	int convertIntToHex(int oldValue);

	//for getting individual digits of numbers
	int getUserValueDigitsHUNDREDS(int fullNumber);
	int getUserValueDigitsTENS(int fullNumber);
	int getUserValueDigitsONES(int fullNumber);

public:
	//user cins these during main loop
	int dollarValue;
	int centValue;

	void mainSellLoop();

	void simulateKeyPress(int);
	void enterValuesIntoSteam();

	KeyboardSim(void);
	~KeyboardSim(void);
};