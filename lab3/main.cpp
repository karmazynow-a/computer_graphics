#include <wx/wxprec.h>
#include <wx/wx.h>

#include "GUIFrame.h"
#include "GUI.h"

class MyApp : public wxApp
{
 public:
  virtual bool OnInit();
  GUI *frame;
};

class MainFrame : public wxFrame
{
public:
 MainFrame();
private:
 void OnExit(wxCommandEvent& event);
};

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{
    frame = new GUI();
    frame->Show();
    return true;

 return true;
}

void MainFrame::OnExit(wxCommandEvent& event)
{
 Close(true);
}
