#pragma once
#include <wx/wx.h>

class MainFrame : public wxFrame
{
public:
	MainFrame(const wxString& title);
	void Timer_Tick(wxTimerEvent& evt);
private:
	wxWindow* GetCtrl(int id);
	template<typename T> T* GetCtrl(int id);
	wxButton* btn;
	void BA(wxCommandEvent& evt);
	void HandleControllerInput();
};