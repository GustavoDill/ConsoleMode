#pragma once
#include "MiButton.h"
#include <wx/wx.h>

class ControlGrid : public wxPanel
{
private:
    int items;

public:
    int GetCount();

    void CallMethod();
    wxButton* btn;
    ControlGrid(wxWindow* parent,
        const wxPoint& pos = wxDefaultPosition,
        const wxSize& size = wxDefaultSize,
        wxWindowID winid = wxID_ANY,
        long style = wxTAB_TRAVERSAL | wxNO_BORDER,
        const wxString& name = wxASCII_STR(wxPanelNameStr));

    void RemoveButton(int index);
    void Unselect(int index);
    void SelectButton(int index);

    MiButton* GetSelectedButton();

    void UnselectAll();

    void AddButton(wxControl* ctrl);
    int selectedIndex = -1;
    int margin;


};

