#ifndef PANEL_CALENDAR
#define PANEL_CALENDAR

#include "../widgets/DayLogListControl.h"

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

class CalendarPanel : public wxPanel
{
public:
    CalendarPanel(wxFrame* parent);

    void OnSize(wxSizeEvent& evt);
    void OnPaint(wxPaintEvent& evt);
private:
    wxFrame* parent;
    // DayLogListControl* list;
    wxListCtrl* list;
};


#endif