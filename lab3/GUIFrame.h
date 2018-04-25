///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 17 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __NONAME_H__
#define __NONAME_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/panel.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/checkbox.h>
#include <wx/scrolbar.h>
#include <wx/gauge.h>
#include <wx/textctrl.h>
#include <wx/combobox.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class GUIFrame
///////////////////////////////////////////////////////////////////////////////
class GUIFrame : public wxFrame
{
    protected:
        wxPanel* panelCanvas;
		wxButton* btnSave;
		wxCheckBox* btnBanana;
		wxScrollBar* moveBanana;
		wxGauge* bananaProgress;
		wxButton* btnColorStar;
		wxTextCtrl* text;
		wxComboBox* comboFigure;
		wxGridSizer* canvas;

		// Virtual event handlers, overide them in your derived class
		virtual void saveToFile( wxCommandEvent& event ) { event.Skip(); }
		virtual void checkBanana( wxCommandEvent& event ) { event.Skip(); }
		virtual void moveBananaOnScroll( wxScrollEvent& event ) { event.Skip(); }
		virtual void bananaProgressOnUpdateUI( wxUpdateUIEvent& event ) { event.Skip(); }
		virtual void starColor( wxCommandEvent& event ) { event.Skip(); }
		virtual void textOnText( wxCommandEvent& event ) { event.Skip(); }
		virtual void changeFigure( wxCommandEvent& event ) { event.Skip(); }
		virtual void onPaint( wxPaintEvent& event ) { event.Skip(); }
		virtual void GUIFrameOnUpdateUI( wxUpdateUIEvent& event ) { event.Skip(); }


		GUIFrame( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Lab03"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 711,466 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~GUIFrame();

};

#endif //__NONAME_H__
