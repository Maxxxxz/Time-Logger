// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif
class TimeLogger: public wxApp
{
public:
    virtual bool OnInit();
};
class TLFrame: public wxFrame
{
public:
    TLFrame(const wxString& title, const wxPoint& pos, const wxSize& size);
private:
    void OnHello(wxCommandEvent& event);
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
    wxDECLARE_EVENT_TABLE();
};

wxBEGIN_EVENT_TABLE(TLFrame, wxFrame)
    EVT_MENU(wxID_EXIT,  TLFrame::OnExit)
    EVT_MENU(wxID_ABOUT, TLFrame::OnAbout)
wxEND_EVENT_TABLE()
wxIMPLEMENT_APP(TimeLogger);

// Load up the user's chosen default frame
bool TimeLogger::OnInit()
{
    TLFrame *frame = new TLFrame( "Time Logger", wxPoint(50, 50), wxSize(750, 500) );
    frame->Show( true );
    return true;
}
TLFrame::TLFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
        : wxFrame(NULL, wxID_ANY, title, pos, size)
{
    wxMenu *menuFile = new wxMenu;
    // Save / Backup / Export
    // menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT, "&Quit\tCtrl-Q");
    wxMenu *menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);
    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append( menuFile, "&File" );
    menuBar->Append( menuHelp, "&Help" );
    SetMenuBar( menuBar );
    // CreateStatusBar();
    SetStatusText( "Welcome to wxWidgets!" );
}
void TLFrame::OnExit(wxCommandEvent& event)
{
    Close( true );
}
void TLFrame::OnAbout(wxCommandEvent& event)
{
    wxMessageBox( "This is a wxWidgets' Hello world sample",
                  "About Hello World", wxOK | wxICON_INFORMATION );
}
