#pragma once
#include <wx/wx.h>
#include "ControlGrid.h"
#include "GamepadController.h"

class MainFrame : public wxFrame
{
public:
	MainFrame(const wxString& title);
	wxBoxSizer* menu;
	ControlGrid* GetGrid();
	void ControllerInput(ControllerKey key);
	void Shown();

private:
	ControlGrid* grid;
	wxPanel* panel;
	wxWindow* GetCtrl(int id);
	template<typename T> T* GetCtrl(int id);
	wxButton* btn;
	void BA(wxCommandEvent& evt);
	void AddItem(wxCommandEvent& e);
};