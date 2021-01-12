#include "NOR3.h"

NOR3::NOR3(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(2, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}


void NOR3::Operate()
{
	//caclulate the output status as the ANDing of the two input pins
	for (int i = 0; i < m_Inputs; i++)
	{
		if (m_InputPins[i].getStatus() == HIGH)
		{
			m_OutputPin.setStatus(LOW);
			break;
		}
		m_OutputPin.setStatus(HIGH);
	}
}

ActionType NOR3::getType() {
	return ADD_NOR_GATE_3;
}
string NOR3::getName()
{
	return "NOR3";
}
GraphicsInfo NOR3::getCenter()
{
	GraphicsInfo gfx = m_GfxInfo;
	gfx.x1 += UI.NOR3_Height / 2;
	gfx.y1 += UI.NOR3_Height / 2;
	return gfx;
}


// Function Draw
// Draws 2-input AND gate
void NOR3::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawNOR3(m_GfxInfo);
}

//returns status of outputpin
int NOR3::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}

//returns status of Inputpin #n
int NOR3::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

GraphicsInfo NOR3::getInputPinPosition(int n)
{
	return GraphicsInfo();
}

GraphicsInfo NOR3::getOutputPinPosition()
{
	return GraphicsInfo();
}

//Set status of an input pin ot HIGH or LOW
void NOR3::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}
void NOR3::savefunc(ofstream& fout)
{
	fout << "NOR3" << " " << id << " " << ((getLabel() == "") ? "$" : getLabel()) << " " << centerx<<" " << centery << endl;

}
