#include <wx/wxprec.h>

#include <string>
#include "config.h"

#ifdef _WIN32
    const auto file = "./settings.yaml";
#endif
#ifdef unix
    const auto file = "";
#endif

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif
class TimeLogger: public wxApp
{
public:
    virtual bool OnInit();
private:
    Conf cfg;
};
class TLFrame: public wxFrame
{
public:
    TLFrame(const Conf& cfg, const wxString& title, const wxPoint& pos, const wxSize& size);
private:
    void OnHello(wxCommandEvent& event);
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
    wxDECLARE_EVENT_TABLE();
    Conf cfg;
};

wxBEGIN_EVENT_TABLE(TLFrame, wxFrame)
    EVT_MENU(wxID_EXIT,  TLFrame::OnExit)
    EVT_MENU(wxID_ABOUT, TLFrame::OnAbout)
wxEND_EVENT_TABLE()
wxIMPLEMENT_APP(TimeLogger);

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
TLFrame::TLFrame(const Conf& cfg, const wxString& title, const wxPoint& pos, const wxSize& size)
        : wxFrame(NULL, wxID_ANY, title, pos, size)
{
    this->cfg = cfg;
    wxMenu *menuFile = new wxMenu;
    // Save / Backup / Export
    // menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT, this->cfg.menu_quit);
    wxMenu *menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);
    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append( menuFile, this->cfg.menu_file );
    menuBar->Append( menuHelp, this->cfg.menu_help );
    SetMenuBar( menuBar );
}
void TLFrame::OnExit(wxCommandEvent& event)
{
    Close( true );
}
void TLFrame::OnAbout(wxCommandEvent& event)
{
    wxMessageBox( this->cfg.about_text,
                  this->cfg.about_title, wxOK | wxICON_INFORMATION );
}
