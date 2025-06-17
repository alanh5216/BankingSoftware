#include "Mainframe.h"
#include <wx/wx.h>
#include <wx/statbmp.h>
#include <wx/sizer.h>
#include <wx/mstream.h>

MainFrame::MainFrame(const wxString& Title) : wxFrame(nullptr, wxID_ANY, Title, wxDefaultPosition, wxSize(800, 600)) {
    wxImage::AddHandler(new wxPNGHandler);

    // Panels
    wxPanel* panel_top = new wxPanel(this);
    wxPanel* panel_middle_left = new wxPanel(this);
    wxPanel* panel_middle_right = new wxPanel(this);
    wxPanel* panel_bottom = new wxPanel(this);

    // Sizers
    wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer* middleSizer = new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer* leftSizer = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer* rightSizer_vrtcl = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer* rightSizer_hzntl = new wxBoxSizer(wxHORIZONTAL);

    // Set background colors
    panel_top->SetBackgroundColour(wxColor(50, 50, 50));
    panel_middle_left->SetBackgroundColour(wxColor(100, 100, 100));
    panel_middle_right->SetBackgroundColour(wxColor(150, 150, 150));
    panel_bottom->SetBackgroundColour(wxColor(50, 50, 50));

    // Top text
    wxStaticText* topText = new wxStaticText(panel_top, wxID_ANY, "Top Panel Text");
    topText->SetForegroundColour(*wxWHITE);
    wxBoxSizer* topSizer = new wxBoxSizer(wxVERTICAL);
    topSizer->Add(topText, 1, wxALIGN_CENTER | wxALL, 10);
    panel_top->SetSizer(topSizer);

    // Bottom text
    wxStaticText* bottomText = new wxStaticText(panel_bottom, wxID_ANY, "Bottom Panel Text");
    bottomText->SetForegroundColour(*wxWHITE);
    wxBoxSizer* bottomSizer = new wxBoxSizer(wxVERTICAL);
    bottomSizer->Add(bottomText, 1, wxALIGN_CENTER | wxALL, 10);
    panel_bottom->SetSizer(bottomSizer);

    // Load and add image
    wxBitmap logoBitmap("Documents/BankingSoftware/logo.png", wxBITMAP_TYPE_PNG);
    wxBitmapBundle logoBundle(logoBitmap);
    wxStaticBitmap* logoWidget = new wxStaticBitmap(panel_middle_left, wxID_ANY, logoBundle);
    logoWidget->SetScaleMode(wxStaticBitmap::Scale_AspectFit);
    logoWidget->SetMinSize(wxSize(0, 0)); // Let the image scale down ***IMPORTANT***

    leftSizer->Add(logoWidget, 1, wxEXPAND | wxALL, 10);
    panel_middle_left->SetSizer(leftSizer);

    // Right panel content
    wxTextCtrl* textCtrl = new wxTextCtrl(panel_middle_right, wxID_ANY, "TextTextTextText", wxDefaultPosition, wxDefaultSize, wxTE_PASSWORD);
    textCtrl->SetMinSize(wxSize(0,0));
    rightSizer_vrtcl->AddStretchSpacer(3);
    rightSizer_vrtcl->Add(textCtrl, 4, wxEXPAND); 
    rightSizer_vrtcl->AddStretchSpacer(3);

    rightSizer_hzntl->AddStretchSpacer(2);
    rightSizer_hzntl->Add(rightSizer_vrtcl, 6, wxEXPAND);
    rightSizer_hzntl->AddStretchSpacer(2);
    panel_middle_right->SetSizer(rightSizer_hzntl);                      

    // Assemble middle
    middleSizer->Add(panel_middle_left, 1, wxEXPAND);
    middleSizer->Add(panel_middle_right, 1, wxEXPAND);

    // Assemble all
    mainSizer->Add(panel_top, 20, wxEXPAND);         // 15% of total height
    mainSizer->Add(middleSizer, 60, wxEXPAND);       // 70% of total height
    mainSizer->Add(panel_bottom, 20, wxEXPAND);      // 15% of total height

    this->SetSizer(mainSizer); //if use SetSizerAndFit then it will make it so that it can only go as small as the text control can be as small
    this->Layout();
}
