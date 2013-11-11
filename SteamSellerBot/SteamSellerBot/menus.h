#pragma once
class menus
{
private:
	void saveNewVariables();

	void mainLoopOption();

	int menuOptionIntChecker(int);
	int tempNumber;


	void optionsMenu();
	void howtoMenu();
	void aboutMenu();

	void gotoMainMenuOnAnyKey();

	int dValue;
	int cValue;
	int numberOfitemsToSell;

	//variable options
	int sleepTime;
	int scrollWheelAmount;
	int pageNumber;
	int slotNumber;
	int sellButtonYAxisPos;
	//set variables (used for options)
	//TODO: turn these into a single use function
	void setSleepTime();
	void setPageNumber();
	void setSlotNumber();
	void setScrollAmount();
	void setSellButtonYAxisPos();

	//add to construct
	
	void confirmMainLoopInformation();
	void optionMenuLogic();
public:
	menus();
	void loadPresetVariables();

	int menuOption;
	void menuLogic();

	//may only need to be private when done
	void printOutMainMenu();
	~menus();
};