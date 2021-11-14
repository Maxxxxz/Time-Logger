#include <wx/wxprec.h>

#include <string>
#include "config.h"
#include "TLFrame.h"

#ifdef _WIN32
    const auto file = "./settings.yaml";
#endif
#ifdef unix
    const auto file = "";
#endif

#include "panels/CalendarPanel.h"

class TimeLogger : public wxApp
{
public:
    virtual bool OnInit();
private:
    Conf cfg;
    CalendarPanel* panelCalendar;
};

IMPLEMENT_APP(TimeLogger)

// Load up the user's chosen default frame
bool TimeLogger::OnInit()
{
    Config::getInstance().loadSettings(file);

    this->cfg = Config::getInstance().getConf();

    TLFrame *frame = new TLFrame(
        this->cfg,
        this->cfg.about_title,
        wxPoint(this->cfg.top_level_window_pos_x, this->cfg.top_level_window_pos_y),
        wxSize(this->cfg.top_level_window_length, this->cfg.top_level_window_height)
    );

    // Move CalendarPanel to notebook
    this->panelCalendar = new CalendarPanel(frame);

    // Create Notebook
    // Add CalendarPanel to Notebook
    // Add IssuePanel to Notebook
    // Utilize wxNotebook::SetSelection to set default tab selection

    frame->Show( true );
    return true;
}
