#ifndef TL_FRAME
#define TL_FRAME

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include "config.h"
#include "panels/CalendarPanel.h"

class TLFrame: public wxFrame
{
public:
    TLFrame(const Conf& cfg, const wxString& title, const wxPoint& pos, const wxSize& size);
private:
    void OnHello(wxCommandEvent& event);
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
    Conf cfg;
    
    wxDECLARE_EVENT_TABLE();
};

#endif