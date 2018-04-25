#include "GUI.h"

GUI::GUI () : GUIFrame (NULL) {

    panelCanvas = new wxPanel((wxFrame *)this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
   	panelCanvas->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNHIGHLIGHT ) );
   	panelCanvas->SetMinSize( wxSize( 400,400 ));
   canvas->Add( panelCanvas, 0, wxEXPAND|wxFIXED_MINSIZE, 5 );
   bananaPos.x = int(200);
   getBananaPos(0);
   starColorCurr =  new wxColour(*wxBLACK);
   str = "tekst";
   bananaProgress->SetRange (100);

    moveBanana->SetScrollbar(0, 5, 50, 5);

   star[0]=wxPoint(50,75);
   star[2]=wxPoint(25,100);
   star[3]=wxPoint(75,100);
   star[4]=wxPoint(35,125);
   star[1]=wxPoint(65,125);

    pngHandler = new wxPNGHandler();
    wxImage::AddHandler(pngHandler);

    wxImage * imgBanana = new wxImage(wxSize(50, 38));
    imgBanana->LoadFile("banan.png", wxBITMAP_TYPE_PNG);
    banana = new wxBitmap(*imgBanana);
    save = new wxFileDialog(this, _("Save file"), "", "", "To BMP (*.bmp)|*.bmp|To PNG (*.png)|*.png|To TIFF (*.tiff)|*.tiff|TO JPEG (*.jpeg)|*.jpeg", wxFD_SAVE | wxFD_OVERWRITE_PROMPT);
}

void GUI::GUIFrameOnUpdateUI( wxUpdateUIEvent& event ){
    wxClientDC dc(panelCanvas);
    render (dc);
}

void GUI::onPaint( wxPaintEvent& event ) {
    wxClientDC dc(panelCanvas);
    panelCanvas->Refresh();
    panelCanvas->Update();

    render (dc);
}

void GUI::render (wxClientDC &dcCli){
    wxBufferedDC dc(&dcCli);
	PrepareDC(dc);
	dc.Clear();

    wxSize center = panelCanvas->GetVirtualSize();
    dc.SetDeviceOrigin(center.GetWidth() / 2-250,center.GetHeight() / 2-250);

    dc.SetPen( wxPen( wxColor(0,0,0), 2 ) );
    dc.DrawLine( 250, 200, 250, 300 );
    dc.DrawLine( 250, 300, 250-20, 350 );
    dc.DrawLine( 250, 300, 250+20, 350 );
    dc.DrawLine( 250, 200, 250+20, 250 );
    dc.DrawCircle( wxPoint(250,200-30), 30);

    if (isBanana){
        dc.DrawBitmap(*banana, bananaPos.x - 48, bananaPos.y - 35);
        dc.DrawLine( bananaPos.x, bananaPos.y, 250, 200 );
        dc.SetPen( wxPen( wxColor(0,0,0), 1 ) );
        dc.DrawCircle( wxPoint(250+10,200-35), 5);
        dc.DrawCircle( wxPoint(250-10,200-35), 5);
        dc.DrawEllipticArc( 250-7, 200-20, 15, 10, 180, 0);
        moveBanana->Enable(true);
    }
    else {
        dc.DrawLine( bananaPos.x, bananaPos.y, 250, 200 );
        dc.SetPen( wxPen( wxColor(0,0,0), 1 ) );
        dc.DrawEllipse(250+10,200-35, 5, 7);
        dc.DrawEllipse(250-10,200-35, 7, 5);
        dc.DrawEllipticArc( 250-7, 200-20, 15, 10, 0, 180);
        moveBanana->Enable(false);
    }

    //dc.SetFont (wxFont(10, wxSCRIPT, wxITALIC, wxNORMAL, false));
    dc.DrawText(str, 100, 350);
    dc.SetFont (wxFont(40, wxSCRIPT, wxITALIC, wxNORMAL, false, _("Monotype Corsiva")));
    dc.SetPen(wxPen( wxColor(0,0,0), 20 ,wxPENSTYLE_SOLID ) );
    dc.DrawRotatedText(str, 350, 350, 90);

    dc.SetPen(wxPen(*starColorCurr));
    dc.SetBrush(wxBrush(*starColorCurr));

    if (figurePicked==0) dc.DrawPolygon(5, star, wxWINDING_RULE);
    else if (figurePicked==1){
        dc.SetPen(wxPen(*wxBLACK_PEN));
        dc.SetBrush(wxBrush(*wxGREY_BRUSH));
        dc.DrawCircle( wxPoint(100,100), 25);

        dc.SetBrush(wxBrush(*wxBLACK_BRUSH));
        dc.DrawCircle( wxPoint(105,100), 2);

        dc.SetBrush(wxBrush(*wxTRANSPARENT_BRUSH));
        dc.DrawEllipticArc( 85, 95, 25, 20, 180, 320);

        dc.SetPen(wxPen(*wxWHITE_PEN));
        dc.SetBrush(wxBrush(*wxWHITE_BRUSH));
        dc.DrawCircle( wxPoint(83,83), 25);
    }
    else{
        dc.SetPen(wxPen(*wxBLACK_PEN));
        dc.SetBrush(wxBrush(*wxYELLOW_BRUSH));
        dc.DrawCircle( wxPoint(100,100), 25);
    }

}

void GUI::getBananaPos(int input) {
    bananaPos.y = int(250 - input);
}

void GUI::moveBananaOnScroll( wxScrollEvent& event ){
    getBananaPos(event.GetPosition());
    bananaProgress->SetValue (event.GetPosition()*2);
    Refresh();
}

void GUI::bananaProgressOnUpdateUI( wxUpdateUIEvent& event ){
    bananaProgress->SetValue ((bananaPos.y - 250)*2);
}

void GUI::checkBanana( wxCommandEvent& event ){
    isBanana = event.IsChecked();
    Refresh();
}

void GUI::starColor( wxCommandEvent& event ){
    wxColourDialog wxCD(this);
    if (wxCD.ShowModal() == wxID_OK) *starColorCurr = wxCD.GetColourData().GetColour();
    Refresh();
}

void GUI::textOnText( wxCommandEvent& event ){
    str = event.GetString();
    wxClientDC dc(panelCanvas);
    render (dc);
    Refresh();
}

void GUI::changeFigure( wxCommandEvent& event ){
    figurePicked = event.GetSelection();
    Refresh();
}

void GUI::saveToFile(wxCommandEvent &event) {

    wxClientDC dcClient(panelCanvas);
	wxBufferedDC dcBuff(&dcClient);
	PrepareDC(dcBuff);
	wxInitAllImageHandlers();

	if (save->ShowModal() == wxID_OK)
	{
		Refresh();
		wxString file = save->GetPath();

		wxSize panelSize = panelCanvas->GetVirtualSize();
		wxBitmap *saveBitmap = new wxBitmap(panelSize);

		wxMemoryDC memory;
		memory.SelectObject(*saveBitmap);
		memory.Blit(0, 0, panelSize.GetX(), panelSize.GetY(), &dcBuff, 0, 0, wxCOPY, true);

		wxImage screenshot = saveBitmap->ConvertToImage();
		screenshot.SaveFile(file, wxBITMAP_TYPE_JPEG);

        delete saveBitmap;
	}
}

GUI::~GUI (){
    delete save;
    delete starColorCurr;
    delete banana;
    delete pngHandler;
}
