#include "WidgetsFrame.h"
wxBEGIN_EVENT_TABLE(WidgetsFrame, wxFrame)
END_EVENT_TABLE()
WidgetsFrame::WidgetsFrame() : wxFrame(nullptr, wxID_ANY, "Minesweeper", wxPoint(200, 200), wxSize(500, 500))
{
	buttons = new wxButton * [numCellsX * numCellsY];
	
	wxGridSizer* grid = new wxGridSizer(numCellsX, numCellsY, 0, 0);
	
	mineField = new int[numCellsX * numCellsY];

	wxFont font(24, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false);

	for (int x = 0; x < numCellsX; x++)
	{
		for (int y = 0; y < numCellsY; y++)
		{
			buttons[y * numCellsX + x] = new wxButton(this, 10000 + (y * numCellsX + x));
			buttons[y * numCellsX + x]->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &WidgetsFrame::OnButtonClicked, this);
			buttons[y * numCellsX + x]->SetFont(font);
			grid->Add(buttons[y * numCellsX + x], 1, wxEXPAND | wxALL);

			mineField[y * numCellsX + x] = 0;

		}
	}
	this->SetSizer(grid);
	grid->Layout();
}
WidgetsFrame::~WidgetsFrame()
{
	delete[] buttons;
	delete[] mineField;
}

void WidgetsFrame::OnButtonClicked(wxCommandEvent& evt)
{
	int x = (evt.GetId() - 10000) % numCellsX;
	int y = (evt.GetId() - 10000) / numCellsY;

	if (isFirstClick)
	{
		int mines = 30;
		while (mines)
		{
			int randMineX = rand() % numCellsX;
			int randMineY = rand() % numCellsY;
			if (mineField[randMineY * numCellsX + randMineX] == 0 && randMineX != x && randMineY != y)
			{
				mineField[randMineY * numCellsX + randMineX] = -1;
				mines--;
			}
		}
		isFirstClick = false;
	}

	//disable button, preventing it from being pressed again.
	buttons[y * numCellsX + x]->Enable(false);

	if (mineField[y * numCellsX + x] == -1)
	{
		wxMessageBox("BOOOOOOM!! - Game Over :(");

		//reset game 
		isFirstClick = true;
		for (int x = 0; x < numCellsX; x++)
		{
			for (int y = 0; y < numCellsY; y++)
			{
				mineField[y * numCellsX + x] = 0;
				buttons[y * numCellsX + x]->SetLabel("");
				buttons[y * numCellsX + x]->Enable(true);

			}
		}
	}
	else
	{
		//Count neighboring mines
		int numOfNeighboringMines = 0;
		for (int xoffset = -1; xoffset < 2; xoffset++)
		{
			for (int yoffset = -1; yoffset < 2; yoffset++)
			{
				if (x + xoffset >= 0 && x + xoffset < numCellsX && y + yoffset >= 0 && y + yoffset < numCellsY)
				{
					if (mineField[(y + yoffset) * numCellsX + (x + xoffset)] == -1)
					{
						numOfNeighboringMines++;
					}
				}
			}
		}

		if (numOfNeighboringMines > 0)
		{
			buttons[y * numCellsX + x]->SetLabel(std::to_string(numOfNeighboringMines));
		}
	}
	evt.Skip();
}
