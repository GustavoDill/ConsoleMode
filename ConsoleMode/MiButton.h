#pragma once
#include <wx/wx.h>

class MiButton : public wxControl
{
public:
    MiButton(wxWindow* parent, wxWindowID id, const wxString& label, wxPoint location) : wxControl(parent, id, location, wxSize(250, 200), wxBORDER_NONE)
    {
        SetLabel(label);
        SetBackgroundStyle(wxBG_STYLE_CUSTOM);
        Connect(-1, wxEVT_LEFT_DOWN, wxMouseEventHandler(MiButton::OnMouseEvent));
        Connect(-1, wxEVT_PAINT, wxPaintEventHandler(MiButton::OnPaint));
       
    }
    void OnPaint(wxPaintEvent& event)
    {
        wxPaintDC dc(this);
        wxRect rect = GetClientRect();

        // Draw a gradient background
        wxColour startColor(128, 128, 128);
        wxColour endColor(192, 192, 192);
        dc.GradientFillLinear(rect, startColor, endColor, wxSOUTH);

        dc.GradientFillLinear(rect, GetBackgroundColour(), GetBackgroundColour());

        // Draw the button label
        dc.SetFont(GetFont());
        dc.SetTextForeground(wxColour(0, 0, 0));
        dc.DrawLabel(GetLabel(), rect, wxALIGN_CENTER);

    }

    void OnMouseEvent(wxMouseEvent& event)
    {
        if (event.LeftDown())
        {
            // Change the button's background color when clicked
            SetBackgroundColour(wxColour(255, 57, 81));
            Refresh();
        }
        
    }
};

