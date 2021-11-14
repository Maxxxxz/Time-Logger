#ifndef PANEL_TASKS
#define PANEL_TASKS

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

class TasksPanel : public wxPanel
{
public:
    TasksPanel(wxFrame* parent);

    void OnSize(wxSizeEvent& evt);
    void OnPaint(wxPaintEvent& evt);
private:
    wxFrame* parent;
};


#endif