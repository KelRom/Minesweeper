#pragma once
#include "wx/wx.h"
class WidgetsFrame : public wxFrame
{
public:
	WidgetsFrame();
	~WidgetsFrame();
	int numCellsX = 10;
	int numCellsY = 10;
	wxButton** buttons;
	wxDECLARE_EVENT_TABLE();
};

