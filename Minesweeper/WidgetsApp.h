#pragma once
#include "wx/wx.h"
#include "WidgetsFrame.h"
class WidgetsApp : public wxApp
{
private:
	WidgetsFrame* window = nullptr;

public:
	WidgetsApp();
	~WidgetsApp();
	virtual bool OnInit();
};

