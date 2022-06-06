#pragma once
#include "wx/wx.h"
class WidgetsFrame : public wxFrame
{
public:
	WidgetsFrame();
	~WidgetsFrame();
	int numCellsX = 10;
	int numCellsY = 10;
	int* mineField = nullptr;
	bool isFirstClick = true;
	wxButton** buttons;
	void OnButtonClicked(wxCommandEvent& evt);
	wxDECLARE_EVENT_TABLE();
};

