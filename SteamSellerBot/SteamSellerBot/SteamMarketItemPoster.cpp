#include "stdafx.h"
#include <iostream>
#include "windows.h"
#include "menus.h"
#include "mainLoops.h"
#include "KeyboardSim.h"

//void FindCursorPos();
int main (){
	menus newMenu;

	newMenu.loadPresetVariables();
	newMenu.menuLogic();

}

//This is just a tool to help get x y cords

//void FindCursorPos(){
//	POINT p;
//	while(1){
//		if (GetCursorPos(&p))
//		{
//			std::cout<<p.x<<","<<p.y<<std::endl;
//		}
//		Sleep(25);
//	}
//}