#ifndef UI_INFO_H
#define UI_INFO_H

#include "..\CMUgraphicsLib\CMUgraphics.h"
#include "..\Defs.h"

//User Interface information file.
//This file contains info that is needed by Input and Output classes to
//handle the user interface

__declspec(selectany) //This line to prevent "redefinition error"

struct UI_Info	//User Interface Info.
{
	MODE AppMode;		//Application Mode (design or simulation)

	static const int	width = 1500, height = 780,	//Window width and height
		wx = 15, wy = 15,			//Window starting coordinates
		StatusBarHeight = 50,	//Status Bar Height
		ToolBarHeight = 80,		//Tool Bar Height (distance from top of window to bottom line of toolbar)
		ToolItemWidth = 150;		//Width of each item in toolbar menu

	color DrawColor;		//Drawing color
	color SelectColor;		//Highlighting color
	color ConnColor;		//Connector color
	color MsgColor;			//Messages color
	color BkGrndColor;		//Back ground color


	//This should be calculated accurately because it will be used later to create connections between gates
	//For now, we will assume that rect width = 50 and height = 50
	static const int	AND2_Width = 83,		//AND2 Gate Image default width
		AND2_Height = 50,		//AND2 Gate Image default height
		NOT_Width = 92,			//NOT Gate Image default width
		NOT_Height = 50,
		NAND2_Width = 87,		//NAND2 Gate Image default width
		NAND2_Height = 50,		//NAND2 Gate Image default height
		OR_Width = 97,			//OR Gate Image default width
		OR_Height = 50;		//OR Gate Image default height
}UI;	//create a single global object UI

#endif