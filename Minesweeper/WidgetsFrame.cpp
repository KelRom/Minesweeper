#include "WidgetsFrame.h"
wxBEGIN_EVENT_TABLE(WidgetsFrame, wxFrame)
END_EVENT_TABLE()
WidgetsFrame::WidgetsFrame() : wxFrame(nullptr, wxID_ANY, "Minesweeper", wxPoint(200, 200), wxSize(500, 500))
{

}
WidgetsFrame::~WidgetsFrame()
{

}
