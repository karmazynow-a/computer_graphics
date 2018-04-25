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

 wxImage::AddHandler(new wxJPEGHandler);           // Dodajemy handlery do formatow
 wxImage::AddHandler(new wxPNGHandler);            // z jakich bedziemy korzytsac
 wxImage image;
 {
  wxLogNull logNo;
  if (!image.LoadFile("test.jpg"))
  {
   wxMessageBox(_("Nie udalo sie zaladowac obrazka"));
   mainFrame->Destroy();
   return true;
  } else
  {
   mainFrame->Img_Org = image.Copy();              // Kopiujemy obrazek do Img_Org
   mainFrame->Img_Cpy = mainFrame->Img_Org.Copy(); // Kopiujemy obrazek do Img_Cpy
   if (!image.LoadFile("mask.png"))
   {
    wxMessageBox(_("Nie uda\u0142o si\u0119 za\u0142adowac maski"));
    mainFrame->Destroy();
    return true;
   }
   else mainFrame->Img_Mask = image.Copy();        // Kopiujemy maske do Img_Mask
  }
 }

 mainFrame->Show(true);
 SetTopWindow(mainFrame);

 return true;
}
