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
#include <wx/checkbox.h>
#include <wx/radiobut.h>
#include <wx/sizer.h>
#include <wx/statbox.h>
#include <wx/tglbtn.h>
#include <wx/slider.h>
#include <wx/stattext.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class MyFrame1
///////////////////////////////////////////////////////////////////////////////
class MyFrame1 : public wxFrame 
{
	private:
	
	protected:
		wxPanel* m_panel1;
		wxCheckBox* m_cb_Kontur;
		wxCheckBox* m_cb_Mapa;
		wxRadioButton* m_rb_NC;
		wxRadioButton* m_rb_NZC;
		wxRadioButton* m_rb_Na_szaro;
		wxToggleButton* m_tb_function_1;
		wxToggleButton* m_tb_function_2;
		wxToggleButton* m_tb_function_3;
		wxToggleButton* m_tb_function_4;
		wxSlider* m_s_ile_poziomic;
		wxStaticText* m_st_liczba_poziomic;
		wxToggleButton* m_tb_pokaz_punkty;
		
		// Virtual event handlers, overide them in your derived class
		virtual void UpdateUI( wxUpdateUIEvent& event ) { event.Skip(); }
		virtual void m_cb_Kontur_Click( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_cb_Mapa_Click( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_tb_function_1_click( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_tb_function_2_click( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_tb_function_3_click( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_tb_function_4_click( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_s_ile_poziomic_scroll( wxScrollEvent& event ) { event.Skip(); }
		virtual void m_tb_pokaz_punkty_toggle( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		wxStaticBoxSizer* sbSizer2;
		
		MyFrame1( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("GFK Lab 07"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 520,650 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		
		~MyFrame1();
	
};

#endif //__GUI_H__
