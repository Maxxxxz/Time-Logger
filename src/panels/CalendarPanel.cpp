#include "CalendarPanel.h"

{
    this->parent = parent;

    // Connect(wxEVT_PAINT, wxPaintEventHandler(CalendarPanel::OnPaint));
CalendarPanel::CalendarPanel(wxFrame* parent, Conf* c) : wxPanel(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER)

    // this->list = new DayLogListControl();
    this->list = new wxListCtrl(this);

    // Add some test data...

    this->list->AppendColumn("Test");

    this->list->InsertItem(1, "Testing");

    Connect(wxEVT_SIZE, wxSizeEventHandler(CalendarPanel::OnSize));
}

void CalendarPanel::OnSize(wxSizeEvent& evt)
{
    Refresh();
}

void CalendarPanel::OnPaint(wxPaintEvent& evt)
{
    // Paint the 6 calendar dividing lines
    // ???
    wxPaintDC dc(this);
    // dc.DrawText(wxString::Format(wxT("%s"), "Hello, calendar!"), 50, 50);
    // Generate line points here
    
    const auto LEN = 6;

    wxPoint list[LEN] = {};

    // dc.SetBrush(*wxGREEN_BRUSH); // green filling
    dc.SetPen(wxPen(wxColor(0,0,0), 1, wxPENSTYLE_SOLID));

    wxSize size = this->GetSize();

    for(auto i = 1; i <= LEN; i++)
    {
        int x = (size.x*i/7);
        dc.DrawLine(wxPoint(x, 0), wxPoint(x, size.y));
    }

    int y = size.y/7;

    dc.DrawLine(wxPoint(0, y), wxPoint(size.x, y));
    
    // dc.DrawRectangle( 300, 100, 400, 200 );

}