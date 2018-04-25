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
#include <wx/scrolwin.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/button.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/slider.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class MyFrame1
///////////////////////////////////////////////////////////////////////////////
class MyFrame1 : public wxFrame 
{
	private:
	
	protected:
		wxScrolledWindow* m_scrolledWindow;
		wxButton* m_b_grayscale;
		wxButton* m_b_blur;
		wxButton* m_b_mirror;
		wxButton* m_b_replace;
		wxButton* m_b_rescale;
		wxButton* m_b_rotate;
		wxButton* m_b_rotate_hue;
		wxButton* m_b_mask;
		wxSlider* m_s_brightness;
		wxStaticText* m_staticText2;
		wxSlider* m_s_contrast;
		wxButton* m_b_prewitt;
		
		// Virtual event handlers, overide them in your derived class
		virtual void m_scrolledWindow_update( wxUpdateUIEvent& event ) { event.Skip(); }
		virtual void m_b_grayscale_click( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_b_blur_click( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_b_mirror_click( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_b_replace_click( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_b_rescale_click( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_b_rotate_click( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_b_rotate_hue_click( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_b_mask_click( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_s_brightness_scroll( wxScrollEvent& event ) { event.Skip(); }
		virtual void m_s_contrast_scroll( wxScrollEvent& event ) { event.Skip(); }
		virtual void m_b_prewitt_click( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_b_threshold_click( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		wxStaticText* m_staticText1;
		wxButton* m_b_threshold;
		
		MyFrame1( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("GFK Lab 06"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 600,400 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		
		~MyFrame1();
	
};

#endif //__GUI_H__
