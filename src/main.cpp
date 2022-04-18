#include <wx/wxprec.h>
#include <wx/notebook.h>

#include <string>
#include "config.h"
#include "TLFrame.h"
#include "panels/CalendarPanel.h"
#include "panels/TasksPanel.h"

#ifdef _WIN32
    const auto file = "../settings.yaml";
#endif
#ifdef unix
    const auto file = "";
#endif

class TimeLogger : public wxApp
{
public:
    virtual bool OnInit();
private:
    Conf cfg;
    wxNotebook* panels;
    CalendarPanel* panelCalendar;
    TasksPanel* panelTasks;
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

    // Create Notebook
    // Add CalendarPanel to Notebook
    // Add TaskPanel to Notebook
    // Utilize wxNotebook::SetSelection to set default tab selection
    this->panels = new wxNotebook(frame, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxNB_TOP);

    this->panelCalendar = new CalendarPanel((wxFrame*)this->panels, &(this->cfg));
    this->panels->AddPage(this->panelCalendar, "Calendar");

    this->panelTasks = new TasksPanel((wxFrame*)this->panels);
    this->panels->AddPage(this->panelTasks, "Tasks");

    frame->Show( true );
    return true;
}
