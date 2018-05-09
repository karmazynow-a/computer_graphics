#include <wx/wx.h>
#include "GUIMyFrame1.h"

class MyApp : public wxApp {

public:

 virtual bool OnInit();
 virtual int OnExit() { return 0; }

};

IMPLEMENT_APP(MyApp);

bool MyApp::OnInit() 
{
 GUIMyFrame1 *mainFrame = new GUIMyFrame1(NULL);
 mainFrame->Show(true);
 SetTopWindow(mainFrame);

 return true;
}