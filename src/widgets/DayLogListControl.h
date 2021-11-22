#ifndef DAY_LOG_CTRL
#define DAY_LOG_CTRL

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include "wx/listctrl.h"

class DayLogListControl : public wxListCtrl
{
    // Hover event will display an "add" button on the bottom of the list
    // Clicking the "add" button will prompt the add event in which a log is added
};

#endif