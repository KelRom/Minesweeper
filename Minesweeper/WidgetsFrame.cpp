#include "WidgetsFrame.h"
wxBEGIN_EVENT_TABLE(WidgetsFrame, wxFrame)
END_EVENT_TABLE()
WidgetsFrame::WidgetsFrame() : wxFrame(nullptr, wxID_ANY, "Minesweeper", wxPoint(200, 200), wxSize(500, 500))
{
	buttons = new wxButton* [numCellsX * numCellsY];
	wxGridSizer* grid = new wxGridSizer(numCellsX, numCellsY, 0, 0);
	for (int x = 0; x < numCellsX; x++)
	{
		for (int y = 0; y < numCellsY; y++)
		{
			buttons[y * numCellsX + x] = new wxButton(this, 10000 + (y * numCellsX + x));
			grid->Add(buttons[y * numCellsX + x], 1, wxEXPAND | wxALL);
		}
	}
	this->SetSizer(grid);
	grid->Layout();
}
WidgetsFrame::~WidgetsFrame()
{
	delete[] buttons;
}
