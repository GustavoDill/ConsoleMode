#include "ControlGrid.h"
#include "MiButton.h"
#include <wx/button.h>


ControlGrid::ControlGrid(wxWindow* parent,
    const wxPoint& pos,
    const wxSize& size ,
    wxWindowID winid,
    long style,
    const wxString& name) : wxPanel(parent, winid, pos, size, style, name) {

    margin = 2;

    SetClientSize(350, 500);
    SetBackgroundColour(0xFF555555);

}
void ControlGrid::RemoveButton(int index) {
    delete this->GetChildren()[index];
}

void ControlGrid::SelectButton(int index) {
    selectedIndex = index;

}
void ControlGrid::UnselectAll() {

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