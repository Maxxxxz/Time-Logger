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
    frame->Show( true );
    return true;
}
