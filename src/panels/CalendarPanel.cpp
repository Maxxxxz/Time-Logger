#include "CalendarPanel.h"

using std::string;

void cancelDrag(wxNotifyEvent& evt)
{
    std::cout << "Vetoed drag action" << std::endl;
    evt.Veto();
}

CalendarPanel::CalendarPanel(wxFrame* parent, Conf* c) : wxPanel(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER)
{
    this->parent = parent;
    this->cfg = c;

    // Get day names in language
    this->DAYS.push_back(this->cfg->sunday);
    this->DAYS.push_back(this->cfg->monday);
    this->DAYS.push_back(this->cfg->tuesday);
    this->DAYS.push_back(this->cfg->wednesday);
    this->DAYS.push_back(this->cfg->thursday);
    this->DAYS.push_back(this->cfg->friday);
    this->DAYS.push_back(this->cfg->saturday);

    // Connect(wxEVT_PAINT, wxPaintEventHandler(CalendarPanel::OnPaint));

    auto size = this->GetSize();

    // this->list = new DayLogListControl();
    for(auto i = 0; i < DAYS_OF_WEEK; i++)
    {
        this->lists.push_back(new wxListView(this, wxID_ANY, wxPoint(size.x*i/7, 0), wxSize(size.x/7, size.y)));
        this->lists[i]->AppendColumn(DAYS[i]);
        // Add test data
        this->lists[i]->InsertItem(0, string(DAYS[i]) + string(" Item"));
    }

    
    Bind(wxEVT_LIST_COL_BEGIN_DRAG, &cancelDrag);
    Connect(wxEVT_SIZE, wxSizeEventHandler(CalendarPanel::OnSize));
    Connect(wxEVT_PAINT, wxPaintEventHandler(CalendarPanel::OnPaint));
}

void CalendarPanel::OnSize(wxSizeEvent& evt)
{
    Refresh();
}

void CalendarPanel::OnPaint(wxPaintEvent& evt)
{

    auto size = this->GetSize();

    for(auto i = 0; i < this->lists.size(); i++)
    {
        this->lists[i]->SetSize(size.x*i/7, 0, size.x/7, size.y);
        this->lists[i]->SetColumnWidth(0, size.x/7);
    }
    
}
// void CalendarPanel::OnPaint(wxPaintEvent& evt)
// {
//     // Paint the 6 calendar dividing lines
//     // ???
//     wxPaintDC dc(this);
//     // dc.DrawText(wxString::Format(wxT("%s"), "Hello, calendar!"), 50, 50);
//     // Generate line points here
    
//     const auto LEN = 6;

//     wxPoint list[LEN] = {};

//     // dc.SetBrush(*wxGREEN_BRUSH); // green filling
//     dc.SetPen(wxPen(wxColor(0,0,0), 1, wxPENSTYLE_SOLID));

//     wxSize size = this->GetSize();

//     for(auto i = 1; i <= LEN; i++)
//     {
//         int x = (size.x*i/7);
//         dc.DrawLine(wxPoint(x, 0), wxPoint(x, size.y));
//     }

//     int y = size.y/7;

//     dc.DrawLine(wxPoint(0, y), wxPoint(size.x, y));
    
//     // dc.DrawRectangle( 300, 100, 400, 200 );

// }