#ifndef DAY_LOG_CTRL
#define DAY_LOG_CTRL

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include "wx/listctrl.h"

class DayLogListControl : public wxPanel
{
    // Hover event will display an "add" button on the bottom of the list
    // Clicking the "add" button will prompt the add event in which a log is added
public:
    DayLogListControl(wxWindow* parent, wxWindowID id = -1, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxHSCROLL|wxVSCROLL, const wxString& name = "scrolledWindow");
    // bool SetBackgroundColour(const wxColour &color);
private:

};

#endif