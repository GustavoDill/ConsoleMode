#include "MainFrame.h"
#include <wx/wx.h>
#include "MiButton.h"

enum IDs {

};
//wxTimer m_timer;

MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title) {
	wxPanel* panel = new wxPanel(this, wxID_ANY, wxDefaultPosition, this->GetClientSize());

	grid = new ControlGrid(panel, wxPoint(100, 20), wxDefaultSize, -1, wxFIXED_MINSIZE);

	wxBoxSizer* sizer = new wxBoxSizer(wxHORIZONTAL);
	sizer->Add(grid, 1, wxFIXED_MINSIZE);

	btn = new wxButton(panel, -1, "Disable");
	sizer->Add(btn, 0, wxALIGN_TOP | wxTOP | wxBOTTOM);

	panel->SetSizer(sizer);
	//This will cause the grid control to be anchored to the top, left, and right of the panel, and to have a fixed width of 250 pixels.The button will be aligned to




}







void MainFrame::Timer_Tick(wxTimerEvent& evt) {
    //this->HandleControllerInput();
}


void MainFrame::BA(wxCommandEvent& evt) {
	this->ShowFullScreen(false);
}

wxWindow* MainFrame::GetCtrl(int id) { return this->GetChildren()[0]->GetChildren()[id - 2]; }

template<typename T> T* MainFrame::GetCtrl(int id) {
	return (T*)this->GetChildren()[0]->GetChildren()[id - 2];
}