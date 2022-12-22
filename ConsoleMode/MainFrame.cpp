#include "MainFrame.h"
#include <wx/wx.h>
#include "MiButton.h"

enum IDs {

};
//wxTimer m_timer;

MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title) {
	wxPanel* panel = new wxPanel(this, wxID_ANY, wxDefaultPosition, this->GetClientSize());

	grid = new ControlGrid(panel, wxPoint(100, 20), wxSize(250, 800), -1, wxFIXED_MINSIZE);

	menu = new wxBoxSizer(wxVERTICAL);
	menu->Add(grid, 1, wxFIXED_MINSIZE);
	//menu->Show(false);
	panel->SetSizer(menu);

}



wxWindow* MainFrame::GetCtrl(int id) { return this->GetChildren()[0]->GetChildren()[id - 2]; }

template<typename T> T* MainFrame::GetCtrl(int id) {
	return (T*)this->GetChildren()[0]->GetChildren()[id - 2];
}