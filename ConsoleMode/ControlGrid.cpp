#include "ControlGrid.h"

ControlGrid::ControlGrid(wxWindow* parent,
    const wxPoint& pos,
    const wxSize& size ,
    wxWindowID winid,
    long style,
    const wxString& name) : wxPanel(parent, winid, pos, size, style, name) {


    SetClientSize(350, 500);
    SetBackgroundColour(0xFF555555);

}