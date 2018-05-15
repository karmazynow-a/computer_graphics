#pragma once
#include "GUIDialog.h"
#include <wx/wx.h>
#include <memory>
#include <vector>

class GUIMyFrame : public MyFrame1{
public:
    GUIMyFrame( wxWindow* parent );
    ~GUIMyFrame();
    void read_file( wxCommandEvent& event );
	void cenzure( wxCommandEvent& event );
	void erode( wxCommandEvent& event );
	void animate( wxCommandEvent& event );
	void MyFrame1OnSize( wxSizeEvent& event );
	void MyFrame1OnUpdateUI( wxUpdateUIEvent& event );
	void OnTimer(wxTimerEvent& event);

	void render (wxClientDC &dc);

    wxImage *img;
    wxImage * tmp;
    wxImage *animation;
    wxTimer *m_timer;
    int currA;
    bool isReady;

    wxDECLARE_EVENT_TABLE();
};





