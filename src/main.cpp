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

class MyApp: public wxApp
{
public:
    virtual bool OnInit();
private:
    Conf cfg;
};

class MyFrame: public wxFrame
{
public:
    MyFrame(const Conf& cfg, const wxString& title, const wxPoint& pos, const wxSize& size);
private:
    void OnHello(wxCommandEvent& event);
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
    wxDECLARE_EVENT_TABLE();
    Conf cfg;
};

enum
{
    ID_Hello = 1
};

wxBEGIN_EVENT_TABLE(MyFrame, wxFrame)
    EVT_MENU(ID_Hello,   MyFrame::OnHello)
    EVT_MENU(wxID_EXIT,  MyFrame::OnExit)
    EVT_MENU(wxID_ABOUT, MyFrame::OnAbout)
wxEND_EVENT_TABLE()

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{

    Config::getInstance().loadSettings(file);

    this->cfg = Config::getInstance().getConf();

    MyFrame *frame = new MyFrame(
        this->cfg,
        this->cfg.about_title,
        wxPoint(this->cfg.top_level_window_pos_x, this->cfg.top_level_window_pos_y),
        wxSize(this->cfg.top_level_window_length, this->cfg.top_level_window_height)
        );
    frame->Show( true );
    return true;
}

MyFrame::MyFrame(const Conf& cfg, const wxString& title, const wxPoint& pos, const wxSize& size)
        : wxFrame(NULL, wxID_ANY, title, pos, size)
{
    this->cfg = cfg;
    wxMenu *menuFile = new wxMenu;
    menuFile->Append(ID_Hello, "&Hello...\tCtrl-H",
                     "Help string shown in status bar for this menu item");
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);
    wxMenu *menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);
    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append( menuFile, this->cfg.menu_file );
    menuBar->Append( menuHelp, this->cfg.menu_help );
    SetMenuBar( menuBar );
    CreateStatusBar();
    SetStatusText( "Welcome to wxWidgets!" );
}

void MyFrame::OnExit(wxCommandEvent& event)
{
    Close( true );
}

void MyFrame::OnAbout(wxCommandEvent& event)
{
    wxMessageBox( "This is a wxWidgets' Hello world sample",
                  "About Hello World", wxOK | wxICON_INFORMATION );
}

void MyFrame::OnHello(wxCommandEvent& event)
{
    wxLogMessage("Hello world from wxWidgets!");
}

// #include <iostream>

// int main(int argc, char const *argv[])
// {
//     std::cout << "Hello, World!" << std::endl;
//     return 0;
// }
