#include "MainFrame.h"
#include <wx/wx.h>
#include "MiButton.h"

enum IDs {
	ID_NONE = -1
};

//wxTimer m_timer;

MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title) {
	panel = new wxPanel(this, wxID_ANY, wxDefaultPosition, this->GetClientSize());

	wxButton* btn = new wxButton(panel, -1, "Add");
	wxButton* add = new wxButton(panel, -1, "Down", wxPoint(0, 32), wxSize(76, 28));

	grid = new ControlGrid(panel, wxPoint(100, 20), wxSize(250, 800), -1, wxFIXED_MINSIZE);
	btn->Bind(wxEVT_BUTTON, &MainFrame::AddItem, this);


	for (size_t i = 0; i < 10; i++)
	{
		AddItem(*(new wxCommandEvent()));
	}

}

void MainFrame::Shown()
{
	grid->SelectButton(0);
}
void MainFrame::AddItem(wxCommandEvent& e) {
	grid->AddButton(new wxButton(panel, wxID_ANY, "ITEM " + std::to_string(grid->GetCount())));
}
ControlGrid* MainFrame::GetGrid()
{
	return grid;
}

void MainFrame::ControllerInput(ControllerKey key) {
	bool wait = true;
	switch (key)
	{
	case ControllerKey::DPAD_DOWN: 
		grid->SelectButton(grid->selectedIndex + 1);
		break;

	case ControllerKey::DPAD_UP:
		grid->SelectButton(grid->selectedIndex - 1);
		break;

	case ControllerKey::A:
		 auto dlg = new wxMessageDialog(this, grid->GetSelectedButton()->GetLabel(), "Selected Item", wxOK | wxICON_INFORMATION);
		 dlg->ShowModal();
		 break;


	
	}
	if (wait)
		Sleep(200);
}

wxWindow* MainFrame::GetCtrl(int id) { return this->GetChildren()[0]->GetChildren()[id - 2]; }

template<typename T> T* MainFrame::GetCtrl(int id) {
	return (T*)this->GetChildren()[0]->GetChildren()[id - 2];
}