#pragma once
#include <wx/wx.h>

class MiButton : public wxControl
{
private:
    bool selected;
    wxColour selectedColour;

public:
    void SetSelected(bool selected);
    bool GetSelected();



    MiButton(wxWindow* parent, wxWindowID id, const wxString& label, wxPoint location);
    void OnPaint(wxPaintEvent& event);
    wxColour GetSelectedColour();
    void SetSelectedColour(wxColour color);
    void OnMouseEvent(wxMouseEvent& event);
};

