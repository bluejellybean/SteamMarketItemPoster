#pragma once
class menus
{
private:
	//saves user variables to userVariables.txt
	void saveNewVariables();

	//prints the main menu
	void printOutMainMenu();

	//func that starts main, user enters values here
	//TODO: change this variable to something better
	void mainLoopOption();

	//Checks that user input is valid
	int menuOptionIntChecker(int);
	//used as a placeholder for changing user variables
	int tempNumber;

	//calls each menu
	void optionsMenu();
	void howtoMenu();
	void aboutMenu();
	
	//on key press, brings back to main menu
	void gotoMainMenuOnAnyKey();
	
	//dollar, cent, and # of items user is selling. Used in mainLoopOption
	int dValue;
	int cValue;
	int numberOfitemsToSell;

	//user variable options
	int sleepTime;
	int scrollWheelAmount;
	int pageNumber;
	int slotNumber;
	int sellButtonYAxisPos;
	//set variables (used for options)
	//TODO: turn these into a single use function(may or may not be able to actually do this)
	void setSleepTime();
	void setPageNumber();
	void setSlotNumber();
	void setScrollAmount();
	void setSellButtonYAxisPos();

	//user confirms info is correct after calling the main loop and enter values
	void confirmMainLoopInformation();

	//on key enter, allows user to set each option
	void optionMenuLogic();
public:
	menus();

	//public to avoid being in construct
	void loadPresetVariables();
	
	//variable for user choosen object
	int menuOption;

	//main menu logic. TODO: change to mainMenuLogic
	void menuLogic();

	//may only need to be private when done
	
	~menus();
};