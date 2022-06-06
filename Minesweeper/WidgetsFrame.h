#pragma once
#include "wx/wx.h"
class WidgetsFrame : public wxFrame
{
public:
	WidgetsFrame();
	~WidgetsFrame();
	wxButton** buttons;
	wxDECLARE_EVENT_TABLE();
};

