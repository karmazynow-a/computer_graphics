#pragma once

#include "GUIFrame.h"

#include <wx/graphics.h>
#include <wx/colordlg.h>
#include <wx/wfstream.h>
#include <wx/dcbuffer.h>
#include <wx/wx.h>

class GUI : public GUIFrame {
    friend class BasicDrawPane;

    public:
    GUI ();
    ~GUI ();
    void getBananaPos(int input);
    void saveToFile( wxCommandEvent& event );
	void checkBanana( wxCommandEvent& event );
	void starColor( wxCommandEvent& event );
	void textOnText( wxCommandEvent& event );
	void moveBananaOnScroll( wxScrollEvent& event );
    void bananaProgressOnUpdateUI( wxUpdateUIEvent& event );
	void changeFigure( wxCommandEvent& event );
	void onPaint( wxPaintEvent& event ) ;
	void GUIFrameOnUpdateUI( wxUpdateUIEvent& event );
	void render (wxClientDC &dcCli);

	private:
        wxFileDialog * save;
        wxPoint bananaPos;
        wxColour * starColorCurr;
        bool isBanana;
        wxString str;
        int figurePicked;
        wxPoint star[5];
        wxBitmap *banana;
        wxImageHandler *pngHandler;
};
