#include "ControlGrid.h"
#include <wx/button.h>
#include <typeinfo>
#include <iostream>
#include <map>


ControlGrid::ControlGrid(wxWindow* parent,
	const wxPoint& pos,
	const wxSize& size,
	wxWindowID winid,
	long style,
	const wxString& name) : wxPanel(parent, winid, pos, size, style, name) {

	margin = 2;
	items = 0;
	SetClientSize(350, 500);
	SetBackgroundColour(0xFF555555);

}
void ControlGrid::RemoveButton(int index) {
	delete this->GetChildren()[index];
	items--;
}

int ControlGrid::GetCount()
{
	return items;
}

void ControlGrid::SelectButton(int index) {
	

	// If item doesn't exit ignore select.
	if (index < 0 || items == index) return;

	// Unselect Previous item
	Unselect(selectedIndex);

	// Set selected index
	selectedIndex = index;

	// Get respective button and select it
	(((MiButton*)(GetChildren()[index]))->SetSelected(true));

}
MiButton* ControlGrid::GetSelectedButton() {
	return (((MiButton*)this->GetChildren()[selectedIndex]));
}

void ControlGrid::Unselect(int index) {
	// If item doesn't exit ignore unselect.
	if (index < 0 || index >= items) return;

	(((MiButton*)(GetChildren()[index]))->SetSelected(false));
}

void ControlGrid::UnselectAll() {
	// Unselect currently selected button
	if (selectedIndex != -1) {
		((MiButton*)this->GetChildren()[selectedIndex])->SetSelected(false);
	}

	selectedIndex = -1;
}



void ControlGrid::AddButton(wxControl* ctrl) {


	MiButton* btn = new MiButton(this, items + 2, ctrl->GetLabel(), wxPoint(0, (items * 28) + (items * margin)));
	btn->Bind(wxEVT_BUTTON, ([btn, this](wxCommandEvent& e) {
		delete btn;
	items--;
		}));
	btn->SetSelectedColour(wxColour(70, 70, 255));
	delete ctrl;
	items++;

}