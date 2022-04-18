#include "TasksPanel.h"

TasksPanel::TasksPanel(wxFrame* parent) : wxPanel(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSUNKEN_BORDER)
{
    this->parent = parent;

    Connect(wxEVT_PAINT, wxPaintEventHandler(TasksPanel::OnPaint));
    Connect(wxEVT_SIZE, wxSizeEventHandler(TasksPanel::OnSize));
}

void TasksPanel::OnSize(wxSizeEvent& evt)
{
    Refresh();
}

void TasksPanel::OnPaint(wxPaintEvent& evt)
{
    wxPaintDC dc(this);
    dc.DrawText(wxString::Format(wxT("%s"), "Hello, tasks!"), 50, 50);
}