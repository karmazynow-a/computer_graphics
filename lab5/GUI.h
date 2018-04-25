///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Dec  8 2017)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __GUI_H__
#define __GUI_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/intl.h>
#include <wx/panel.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/button.h>
#include <wx/stattext.h>
#include <wx/slider.h>
#include <wx/sizer.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class MyFrame1
///////////////////////////////////////////////////////////////////////////////
class MyFrame1 : public wxFrame 
{
	private:
	
	protected:
		wxStaticText* m_staticText19;
		wxStaticText* m_staticText21;
		wxStaticText* m_staticText23;
		wxStaticText* m_staticText31;
		wxStaticText* m_staticText33;
		wxStaticText* m_staticText35;
		
		// Virtual event handlers, overide them in your derived class
		virtual void WxPanel_Repaint( wxUpdateUIEvent& event ) { event.Skip(); }
		virtual void m_button_load_geometry_click( wxCommandEvent& event ) { event.Skip(); }
		virtual void Scrolls_Updated( wxScrollEvent& event ) { event.Skip(); }
		
	
	public:
		wxPanel* WxPanel;
		wxButton* m_button_load_geometry;
		wxSlider* WxSB_TranslationX;
		wxStaticText* WxST_TranslationX;
		wxSlider* WxSB_TranslationY;
		wxStaticText* WxST_TranslationY;
		wxSlider* WxSB_TranslationZ;
		wxStaticText* WxST_TranslationZ;
		wxStaticText* m_staticText25;
		wxSlider* WxSB_RotateX;
		wxStaticText* WxST_RotateX;
		wxStaticText* m_staticText27;
		wxSlider* WxSB_RotateY;
		wxStaticText* WxST_RotateY;
		wxStaticText* m_staticText29;
		wxSlider* WxSB_RotateZ;
		wxStaticText* WxST_RotateZ;
		wxSlider* WxSB_ScaleX;
		wxStaticText* WxST_ScaleX;
		wxSlider* WxSB_ScaleY;
		wxStaticText* WxST_ScaleY;
		wxSlider* WxSB_ScaleZ;
		wxStaticText* WxST_ScaleZ;
		
		MyFrame1( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("GFK Lab 05"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 600,400 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		
		~MyFrame1();
	
};

#endif //__GUI_H__
