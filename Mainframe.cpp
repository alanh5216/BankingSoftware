#include "Mainframe.h"
#include <wx/wx.h>

MainFrame::MainFrame(const wxString& Title) : wxFrame(nullptr, wxID_ANY, Title) {

    wxPanel* panel_top = new wxPanel(this);
    wxPanel* panel_middle_left = new wxPanel(this);
    wxPanel* panel_middle_right = new wxPanel(this);
    wxPanel* panel_bottom = new wxPanel(this);

    wxBoxSizer* sizer_vertical = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer* sizer_horizontal = new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer* sizer_middle_left = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer* sizer_middle_right = new wxBoxSizer(wxVERTICAL);

    wxTextCtrl* textCtrl = new wxTextCtrl(panel_middle_right, wxID_ANY, "TextTextTextText", wxDefaultPosition, wxDefaultSize, wxTE_PASSWORD);

    panel_top           ->SetBackgroundColour(wxColor(50,50,50));
    panel_middle_left   ->SetBackgroundColour(wxColor(100,100,100));
    panel_middle_right  ->SetBackgroundColour(wxColor(100,100,100));
    panel_bottom        ->SetBackgroundColour(wxColor(50,50,50));

    sizer_vertical      ->Add(panel_top,1, wxEXPAND);
    sizer_horizontal    ->Add(panel_middle_left,1, wxEXPAND);
    sizer_horizontal    ->Add(panel_middle_right,1, wxEXPAND);
    sizer_vertical      ->Add(sizer_horizontal,3, wxEXPAND);
    sizer_vertical      ->Add(panel_bottom,1, wxEXPAND);
    sizer_middle_right  ->Add(textCtrl, 0, wxALL | wxALIGN_CENTER, 10);

    panel_middle_right->SetSizer(sizer_middle_right);

    this->SetSizer(sizer_vertical);
    this->Layout();
}