#include "CalendarPanel.h"

CalendarPanel::CalendarPanel(wxFrame* parent) : wxPanel(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER)
{
    this->parent = parent;

    Connect(wxEVT_PAINT, wxPaintEventHandler(CalendarPanel::OnPaint));
    Connect(wxEVT_SIZE, wxSizeEventHandler(CalendarPanel::OnSize));
}

void CalendarPanel::OnSize(wxSizeEvent& evt)
{
    Refresh();
}

void CalendarPanel::OnPaint(wxPaintEvent& evt)
{
    wxPaintDC dc(this);
    dc.DrawText(wxString::Format(wxT("%s"), "hello"), 50, 50);
}