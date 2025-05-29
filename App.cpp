#include "App.h"
#include "Mainframe.h"
#include <wx/wx.h>

wxIMPLEMENT_APP(App);

bool App::OnInit() {
    MainFrame* mainFrame = new MainFrame("C++ GUI");

    //mainFrame->SetClientSize(800,600);
    //mainFrame->SetSize(mainFrame->GetBestSize());
    mainFrame->Maximize();
    mainFrame->Center();
    mainFrame->Show();
    //mainFrame->ShowFullScreen(true);
    return true;
}