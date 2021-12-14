#include "DayLogListControl.h"

DayLogListControl::DayLogListControl(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style, const wxString& name)
{
    wxScrolled<wxPanel>(parent, id, pos, size, style, name);
}

bool DayLogListControl::SetBackgroundColour(const wxColour &color)
{
    return wxScrolled::SetBackgroundColour(color);
}