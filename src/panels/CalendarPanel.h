#ifndef PANEL_CALENDAR
#define PANEL_CALENDAR

#include <vector>
#include <string>
#include "../widgets/DayLogListControl.h"
#include "../config.h"

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

const auto DAYS_OF_WEEK = 7;
// const std::vector<std::string> DAYS = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };

class CalendarPanel : public wxPanel
{
public:
    CalendarPanel(wxFrame* parent, Conf* c);

    void OnSize(wxSizeEvent& evt);
    void OnPaint(wxPaintEvent& evt);
private:
    wxFrame* parent;
    // DayLogListControl* list;
    std::vector<wxListView*> lists;
    Conf* cfg;
    std::vector<std::string> DAYS;

};


#endif