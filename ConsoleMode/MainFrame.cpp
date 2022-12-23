#include "MainFrame.h"
#include <wx/wx.h>
#include "MiButton.h"

enum IDs {
	ID_NONE = -1
};

//wxTimer m_timer;

MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title) {
	panel = new wxPanel(this, wxID_ANY, wxDefaultPosition, this->GetClientSize());

	grid = new ControlGrid(panel, wxPoint(100, 20), wxSize(250, 800), -1, wxFIXED_MINSIZE);
	wxButton* btn = new wxButton(panel, -1, "Add");
	btn->Bind(wxEVT_BUTTON, &MainFrame::AddItem, this);

	wxButton* btn2 = new wxButton(panel, -1, "Bind");
	btn2->Bind(wxEVT_BUTTON, [this](wxCommandEvent& e) {
		grid->SelectButton(1);
		});

	//menu = new wxBoxSizer(wxVERTICAL);


	//menu->Add(grid, 1, wxFIXED_MINSIZE);

	//panel->SetSizer(menu);

}
void MainFrame::AddItem(wxCommandEvent& e) {
	grid->AddButton(new wxButton(panel, wxID_ANY, "ITEM"));
}


wxWindow* MainFrame::GetCtrl(int id) { return this->GetChildren()[0]->GetChildren()[id - 2]; }

template<typename T> T* MainFrame::GetCtrl(int id) {
	return (T*)this->GetChildren()[0]->GetChildren()[id - 2];
}