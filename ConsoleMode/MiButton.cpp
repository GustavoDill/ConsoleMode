#include "MiButton.h"

    MiButton::MiButton(wxWindow* parent, wxWindowID id, const wxString& label, wxPoint location) : wxControl(parent, id, location, wxSize(250, 28), wxBORDER_NONE) {
        SetLabel(label);
        SetBackgroundStyle(wxBG_STYLE_CUSTOM);
        Connect(-1, wxEVT_LEFT_DOWN, wxMouseEventHandler(MiButton::OnMouseEvent));
        Connect(-1, wxEVT_PAINT, wxPaintEventHandler(MiButton::OnPaint));
        selectedColour = wxColour(0, 0, 0);
    }

    void MiButton::OnPaint(wxPaintEvent& event) {
        wxPaintDC dc(this);
        wxRect rect = GetClientRect();

        

        // Draw a gradient background
        //dc.GradientFillLinear(rect, startColor, endColor, wxSOUTH);
        if (selected) {
            dc.GradientFillConcentric(rect, GetSelectedColour(), GetSelectedColour());


        }
        else {
            dc.GradientFillConcentric(rect, GetBackgroundColour(), GetBackgroundColour());
        }

        //dc.GradientFillLinear(rect, GetBackgroundColour(), GetBackgroundColour());

        // Draw the button label
        dc.SetFont(GetFont());
        dc.SetTextForeground(wxColour(0, 0, 0));       

        dc.DrawLabel(GetLabel(), rect, wxALIGN_CENTER);
        

    }

    wxColour MiButton::GetSelectedColour() {
        return selectedColour;
    }

    void MiButton::SetSelectedColour(wxColour color) {
        selectedColour = color;
        Refresh();
    }
    void MiButton::SetSelected(bool selected) {
        this->selected = selected;
        Refresh();
    }

    bool MiButton::GetSelected() {
        return selected;
    }

    void MiButton::OnMouseEvent(wxMouseEvent& event)  {
        if (event.LeftDown())
        {
            // Change the button's background color when clicked
            SetSelected(!selected);
        }

    }