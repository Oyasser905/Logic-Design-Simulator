#include "AddORgate2.h"
#include "..\ApplicationManager.h"

AddORgate2::AddORgate2(ApplicationManager* pApp) :Action(pApp)
{

}

AddORgate2::~AddORgate2(void)
{

}

void AddORgate2::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("2-Input OR Gate: Click to add the gate");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();

}

void AddORgate2::Execute()
{
	//Get Center point of the Gate
	ReadActionParameters();
	int yup, ybot;
	Output* pOut = pManager->GetOutput();

	//Calculate the rectangle Corners
	int Len = UI.AND2_Width;
	int Wdth = UI.AND2_Height;

	GraphicsInfo GInfo; //Gfx info to be used to construct the AND2 gate

	GInfo.x1 = Cx - Len / 2;
	GInfo.x2 = Cx + Len / 2;
	GInfo.y1 = Cy - Wdth / 2;
	GInfo.y2 = Cy + Wdth / 2;
	yup = (Cy-30) / 50;
	yup *= 50;
	yup += 5;

	ybot = (Cy-30) / 50;
	ybot *= 50;
	ybot += 55;
	if (abs(((Cy - 30) - yup)) > abs((Cy - 30) - ybot))
	{
		GInfo.y1 = ybot;
	}
	else
	{
		GInfo.y1 = yup;
	}
	
	//int q = Cy / 100;

	//// 1st possible closest number 
	//int n1 = 50 * q;

	//// 2nd possible closest number 
	//int n2 = (Cy * 50) > 0 ? (50 * (q + 1)) : (50 * (q - 1));

	//// if true, then n1 is the required closest number 
	//if (abs(Cy - n1) < abs(Cy - n2))
	//{
	//	GInfo.y1 = n1;

	//}
	//else
	//{
	//	GInfo.y1 = n2;
	//}

	OR2* pA = new OR2(GInfo, AND2_FANOUT);
	pManager->AddComponent(pA);
}

void AddORgate2::Undo()
{

}

void AddORgate2::Redo()
{

}