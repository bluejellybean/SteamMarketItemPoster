#include "stdafx.h"
#include <iostream>
#include "menus.h"
#include "mainLoops.h"
#include "KeyboardSim.h"
#include <fstream>

menus::menus(){
	//Constructor
	menuOption = 0;

	menus::dValue = 0;
	menus::cValue = 0;
	menus::tempNumber = 0;
	menus::numberOfitemsToSell = 0;
	//userChangeableVariables
	menus::pageNumber = 3; 
	menus::scrollWheelAmount = 2;
	menus::sleepTime = 3000;
	menus::slotNumber = 1;
	menus::sellButtonYAxisPos = 800;//920;//TODO: change this to 0 or something for construct


	printOutMainMenu();
}

void menus::loadPresetVariables(){
	
	std::ifstream in("userVariables.txt");
	in>>pageNumber>>scrollWheelAmount>>sleepTime>>slotNumber>>sellButtonYAxisPos;
	in.close();
	//pageNumber = 3;
	//scrollWheelAmount = 2;
	//sleepTime = 3000;
	//slotNumber = 1;
	//sellButtonYAxisPos = 800
}

void menus::saveNewVariables(){
	std::ofstream out("userVariables.txt");
	out<<pageNumber<<"\n"<<scrollWheelAmount<<"\n"<<sleepTime<<"\n"<<slotNumber<<"\n"<<sellButtonYAxisPos;
	out.close();
}

void menus::gotoMainMenuOnAnyKey() {//rename to gotoMainMenuOnAnyKey
	std::cout<<"Enter any key to go back to the main menu..."<<std::endl;
	menuOptionIntChecker(menuOption);

	switch(menuOption) {
	case 1:
		printOutMainMenu();
    	//menuOption = 0;
		menuLogic();
	default:
		printOutMainMenu();
		//menuOption = 0;
		menuLogic();
	}
}

void menus::printOutMainMenu(){
	menuOption = 0;
	std::cout<<"(1). Start Selling" <<std::endl;
	std::cout<<"(2). Options" <<std::endl;
	std::cout<<"(3). How-To" <<std::endl;
	std::cout<<"(4). About" <<std::endl;
	std::cout<<"\n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n"<<std::endl;
}

void menus::menuLogic(){
	menuOption = menuOptionIntChecker(menuOption);

	switch (menuOption) {
	case 1:
		mainLoopOption();
		break;
	case 2:
		optionsMenu();
		break;
	case 3:
		howtoMenu();
		break;
	case 4:
		aboutMenu();
		break;
	default:
		printOutMainMenu();
		menuOption = 0;
		menuLogic();
	}
}

int menus::menuOptionIntChecker(int checkedNumber){
	checkedNumber = 0;
	std::cin>>checkedNumber;
	if(!std::cin>>checkedNumber){
		std::cin.clear();
		std::cin.ignore(1000,'\n');
	}
	return checkedNumber;
}

void menus::optionMenuLogic(){	
	menuOption = menuOptionIntChecker(menuOption);

	switch (menuOption) {
	case 1:
		setSleepTime();
		break;
	case 2:
		setPageNumber();
		break;
	case 3:
		setSlotNumber();
		break;
	case 4:
		setScrollAmount();
		break;
	case 5:
		setSellButtonYAxisPos();
		break;
	default:
		printOutMainMenu();
		menuLogic();
		break;
	}
}

void menus::setSleepTime(){
	std::cout<<"Current time between events is: "<<sleepTime<<std::endl;
	std::cout<<"Enter new time between events:"<<std::endl;
	std::cout<<"\n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n"<<std::endl;
	tempNumber = 0;
	tempNumber = menuOptionIntChecker(tempNumber);

	if(tempNumber > 0){
		sleepTime = tempNumber;
	}
	saveNewVariables();
	optionsMenu();
}

void menus::setPageNumber(){
	std::cout<<"Current page number is: "<<pageNumber<<std::endl;
	std::cout<<"Emter a new page number:"<<std::endl;
	std::cout<<"\n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n"<<std::endl;
	tempNumber = 0;
	tempNumber = menuOptionIntChecker(tempNumber);
	
	if(tempNumber > 0){
		pageNumber = tempNumber;
	}
	saveNewVariables();
	optionsMenu();
}

void menus::setSlotNumber(){
	std::cout<<"Current slot number is: "<<slotNumber<<std::endl;
	std::cout<<"Enter a new slot number:"<<std::endl;
	std::cout<<"\n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n"<<std::endl;
	tempNumber = 0;
	tempNumber = menuOptionIntChecker(tempNumber);
	
	if(tempNumber > 0 && tempNumber < 26){
		slotNumber = tempNumber;
	}
	saveNewVariables();
	optionsMenu();
}

void menus::setScrollAmount(){
	std::cout<<"Current scroll wheel amount is: "<<scrollWheelAmount<<std::endl;
	std::cout<<"Enter new scroll wheel amount:"<<std::endl;
	std::cout<<"\n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n"<<std::endl;
	tempNumber = 0;
	tempNumber = menuOptionIntChecker(tempNumber);
	
	if(tempNumber >= 0){
		scrollWheelAmount = tempNumber;
	}
	saveNewVariables();
	optionsMenu();
}
/////////////SellButtonYAxisPos///////////////////////
//////////////////////////////////////////////////////
void menus::setSellButtonYAxisPos(){
	std::cout<<"Current Y axis is: "<<sellButtonYAxisPos<<std::endl;
	std::cout<<"Enter new Y axis value:"<<std::endl;
	std::cout<<"Note* you may have to play with this value a little bit"<<std::endl;
	std::cout<<"\n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n"<<std::endl;
	tempNumber = 0;
	tempNumber = menuOptionIntChecker(tempNumber);
	if(tempNumber > 0){
		sellButtonYAxisPos = tempNumber;
	}

	saveNewVariables();
	optionsMenu();
}

void menus::confirmMainLoopInformation(){
	menuOption = menuOptionIntChecker(menuOption);
	
	switch (menuOption) {
	case 1:
		break;
	default:
		std::cout<<"default";
		printOutMainMenu();
		menuLogic();
	}
}
//////////////MAIN LOOP HERE//////////////////////
//////////////////////////////////////////////////
void menus::mainLoopOption(){
	
	//int dValue = 0;
	//int cValue = 0;
	//int numberOfitemsToSell = 0;
	
	std::cout<<"Enter how many Items for sale: "<<std::endl;
	std::cout<<"\n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n"<<std::endl;
	std::cin>>numberOfitemsToSell;
	
	std::cout<<"Enter Dollar Amount: "<<std::endl;
	std::cout<<"\n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n"<<std::endl;
	std::cin>> dValue;
	
	std::cout<<"Enter Coin Amount: "<<std::endl;
	std::cout<<"\n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n"<<std::endl;
	std::cin>>cValue;

	//confirm order
	std::cout<<"Confirm Listing:"<<std::endl;
	if(cValue < 10){
		std::cout<<numberOfitemsToSell<<" Items to sellat: $"<<dValue<<".0"<<cValue<<" each"<<std::endl;
	}else{
		std::cout<<numberOfitemsToSell<<" Items to sell at: $"<<dValue<<"."<<cValue<<" each"<<std::endl;
	}
	std::cout<<"\n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n"<<std::endl;
	std::cout<<"Enter 1 to contiune:"<<std::endl;
	
	confirmMainLoopInformation();
	
	mainSellFunction(dValue, cValue, numberOfitemsToSell, scrollWheelAmount,sleepTime,pageNumber,slotNumber,sellButtonYAxisPos);
	
	printOutMainMenu();
	menuLogic();
}

void menus::optionsMenu(){
	std::cout<<"(1). Time between events:           " <<sleepTime<<std::endl;
	std::cout<<"(2). Page number item is on:        "<<pageNumber<<std::endl;
	std::cout<<"(3). Inventory slot to click:       "<<slotNumber<<std::endl;
	std::cout<<"(4). Scroll Wheel amount:           "<<scrollWheelAmount<<std::endl;
	std::cout<<"(5). Y axis positon on sell button: "<<sellButtonYAxisPos<<std::endl;
	//new lines will need to be updated on every change
	std::cout<<"\n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n"<<std::endl;
	optionMenuLogic();
}

void menus::howtoMenu(){

	//order subject to change
	std::cout<<"1. Enter the # of items you wish to sell"<<std::endl;
	std::cout<<"2. Enter the dollar value"<<std::endl;
	std::cout<<"3. Enter the cent value"<<std::endl;
	std::cout<<"4. Enter page that item will be on(MUST be same slot for every order!)"<<std::endl;
	std::cout<<"5. Open steam to your inventory"<<std::endl;
	std::cout<<"6. Wait! Seriously though, don't touch your pc until it's done"<<std::endl;
	
	//new lines will need to be updated on every change
	std::cout<<"\n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n"<<std::endl;
	gotoMainMenuOnAnyKey();
}

void menus::aboutMenu(){

	std::cout<<"Version 1.0"<<std::endl;
	std::cout<<"This program is still under development and may contain bugs."<<std::endl;
	std::cout<<"software developed by Alex Barkell. 2013"<<std::endl;
	std::cout<<std::endl;
	
	//new lines will need to be updated on every change
	std::cout<<"\n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n"<<std::endl;
	gotoMainMenuOnAnyKey();
}

menus::~menus(void){
}