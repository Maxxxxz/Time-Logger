#include "TLFrame.h"

wxBEGIN_EVENT_TABLE(TLFrame, wxFrame)
    EVT_MENU(wxID_EXIT,  TLFrame::OnExit)
    EVT_MENU(wxID_ABOUT, TLFrame::OnAbout)
wxEND_EVENT_TABLE()

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
