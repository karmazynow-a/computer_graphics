///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 17 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __GUIDIALOG_H__
#define __GUIDIALOG_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/button.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/checkbox.h>
#include <wx/gauge.h>
#include <wx/textctrl.h>
#include <wx/sizer.h>
#include <wx/panel.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
/// Class MyFrame1
///////////////////////////////////////////////////////////////////////////////
class MyFrame1 : public wxFrame
{
	private:

	protected:
		wxButton* m_button1;
		wxButton* m_button2;
		wxButton* m_button3;
		wxCheckBox* m_checkBox1;
		wxGauge* m_gauge1;
		wxTextCtrl* m_textCtrl1;
		wxPanel* m_panel1;

		// Virtual event handlers, overide them in your derived class
		virtual void MyFrame1OnUpdateUI( wxUpdateUIEvent& event ) { event.Skip(); }
		virtual void read_file( wxCommandEvent& event ) { event.Skip(); }
		virtual void cenzure( wxCommandEvent& event ) { event.Skip(); }
		virtual void erode( wxCommandEvent& event ) { event.Skip(); }
		virtual void animate( wxCommandEvent& event ) { event.Skip(); }


	public:

		MyFrame1( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("GFK Lab  8"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 1117,582 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~MyFrame1();

};

#endif //__GUIDIALOG_H__
