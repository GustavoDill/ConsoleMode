#pragma once
#include <wx/wx.h>

class ControlGrid : public wxPanel
{
public:
    wxButton* btn;
    ControlGrid(wxWindow* parent,
        const wxPoint& pos = wxDefaultPosition,
        const wxSize& size = wxDefaultSize,
        wxWindowID winid = wxID_ANY,
        long style = wxTAB_TRAVERSAL | wxNO_BORDER,
        const wxString& name = wxASCII_STR(wxPanelNameStr));

    void RemoveButton(int index);

    void SelectButton(int index);

    void UnselectAll();

    void AddButton(wxControl* ctrl);
    int items;
    int selectedIndex = -1;
    int margin;


};

