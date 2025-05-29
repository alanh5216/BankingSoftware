#include "Mainframe.h"
#include <wx/wx.h>

MainFrame::MainFrame(const wxString& Title) : wxFrame(nullptr, wxID_ANY, Title) {

    wxPanel* panel_top = new wxPanel(this);
    wxPanel* panel_middle_left = new wxPanel(this);
    wxPanel* panel_middle_right = new wxPanel(this);
    wxPanel* panel_bottom = new wxPanel(this);

    wxBoxSizer* sizer_vertical = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer* sizer_horizontal = new wxBoxSizer(wxHORIZONTAL);

    wxTextCtrl* textCtrl = new wxTextCtrl(panel_middle_left, wxID_ANY, "Text", wxPoint(500, 145), wxSize(200, -1), wxTE_PASSWORD);

    panel_top           ->SetBackgroundColour(wxColor(200,200,200));
    panel_middle_left   ->SetBackgroundColour(wxColor(200,200,100));
    panel_middle_right  ->SetBackgroundColour(wxColor(200,100,100));
    panel_bottom        ->SetBackgroundColour(wxColor(100,100,100));

    sizer_vertical      ->Add(panel_top,1, wxEXPAND);
    sizer_horizontal    ->Add(panel_middle_left,1, wxEXPAND);
    sizer_horizontal    ->Add(panel_middle_right,1, wxEXPAND);
    sizer_vertical      ->Add(sizer_horizontal,3, wxEXPAND);
    sizer_vertical      ->Add(panel_bottom,1, wxEXPAND);

    this->SetSizerAndFit(sizer_vertical);
}