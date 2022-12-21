#include "MainFrame.h"
#include <wx/wx.h>
#include "MiButton.h"

enum IDs {

};
//wxTimer m_timer;

MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title) {
	wxPanel* panel = new wxPanel(this, wxID_ANY, wxDefaultPosition, this->GetClientSize());

    //m_timer.SetOwner(this, wxID_ANY);
    //m_timer.Bind(wxEVT_TIMER, &MainFrame::Timer_Tick, this);
    //m_timer.Start(20);

	btn = new wxButton(panel, -1, "Disable");

	MiButton* btn2 = new MiButton(panel, -1, "AAAAA", wxPoint(100, 300));

	new wxButton(panel, -1, "ASDFSADF", wxPoint(100, 100));
	new wxButton(panel, -1, "ASDFSADF", wxPoint(200, 200));
	new wxButton(panel, -1, "ASDFSADF", wxPoint(300, 300));
	new wxButton(panel, -1, "ASDFSADF", wxPoint(400, 400));
	new wxButton(panel, -1, "ASDFSADF", wxPoint(500, 500));

	wxMenuBar* joystickSubMenu;

	btn->Bind(wxEVT_BUTTON, &MainFrame::BA, this);
//EnableFullScreenView();
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