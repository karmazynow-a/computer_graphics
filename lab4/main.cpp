#include <wx-3.0/wx/wx.h>
#include <memory>
#include "GUIMyFrame1.h"

class MyApp : public wxApp {

public:

 virtual bool OnInit();
 virtual int OnExit() { return 0; }

};

IMPLEMENT_APP(MyApp);

bool MyApp::OnInit() 
{
 wxFrame *mainFrame = new GUIMyFrame1(NULL);
 mainFrame->Show(true);
 SetTopWindow(mainFrame);

 return true;
}