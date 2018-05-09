///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Dec  8 2017)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "GUI.h"

///////////////////////////////////////////////////////////////////////////

MyFrame1::MyFrame1( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( -1,-1 ), wxDefaultSize );
	
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );
	
	m_panel1 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxSize( 500,500 ), wxTAB_TRAVERSAL );
	m_panel1->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_ACTIVECAPTION ) );
	m_panel1->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_ACTIVECAPTION ) );
	m_panel1->SetMinSize( wxSize( 500,500 ) );
	m_panel1->SetMaxSize( wxSize( 500,500 ) );
	
	bSizer1->Add( m_panel1, 1, wxEXPAND | wxALL, 5 );
	
	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxHORIZONTAL );
	
	wxStaticBoxSizer* sbSizer1;
	sbSizer1 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Tryb rysowania") ), wxHORIZONTAL );
	
	sbSizer1->SetMinSize( wxSize( -1,60 ) ); 
	m_cb_Kontur = new wxCheckBox( sbSizer1->GetStaticBox(), wxID_ANY, _("Kontur"), wxDefaultPosition, wxDefaultSize, 0 );
	m_cb_Kontur->SetValue(true); 
	sbSizer1->Add( m_cb_Kontur, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_cb_Mapa = new wxCheckBox( sbSizer1->GetStaticBox(), wxID_ANY, _("Mapa"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer1->Add( m_cb_Mapa, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_rb_NC = new wxRadioButton( sbSizer1->GetStaticBox(), wxID_ANY, _("N/C"), wxDefaultPosition, wxDefaultSize, 0 );
	m_rb_NC->SetValue( true ); 
	m_rb_NC->Enable( false );
	
	sbSizer1->Add( m_rb_NC, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_rb_NZC = new wxRadioButton( sbSizer1->GetStaticBox(), wxID_ANY, _("N/Z/C"), wxDefaultPosition, wxDefaultSize, 0 );
	m_rb_NZC->Enable( false );
	
	sbSizer1->Add( m_rb_NZC, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_rb_Na_szaro = new wxRadioButton( sbSizer1->GetStaticBox(), wxID_ANY, _("Na szaro"), wxDefaultPosition, wxDefaultSize, 0 );
	m_rb_Na_szaro->Enable( false );
	
	sbSizer1->Add( m_rb_Na_szaro, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	
	bSizer3->Add( sbSizer1, 1, 0, 5 );
	
	sbSizer2 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Wybor funkcji") ), wxHORIZONTAL );
	
	m_tb_function_1 = new wxToggleButton( sbSizer2->GetStaticBox(), wxID_ANY, _("1"), wxDefaultPosition, wxSize( 27,27 ), 0 );
	sbSizer2->Add( m_tb_function_1, 0, wxALL, 5 );
	
	
	sbSizer2->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_tb_function_2 = new wxToggleButton( sbSizer2->GetStaticBox(), wxID_ANY, _("2"), wxDefaultPosition, wxSize( 27,27 ), 0 );
	sbSizer2->Add( m_tb_function_2, 0, wxALL, 5 );
	
	
	sbSizer2->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_tb_function_3 = new wxToggleButton( sbSizer2->GetStaticBox(), wxID_ANY, _("3"), wxDefaultPosition, wxSize( 27,27 ), 0 );
	sbSizer2->Add( m_tb_function_3, 0, wxALL, 5 );
	
	
	sbSizer2->Add( 0, 0, 1, wxEXPAND, 5 );
	
	m_tb_function_4 = new wxToggleButton( sbSizer2->GetStaticBox(), wxID_ANY, _("4"), wxDefaultPosition, wxSize( 27,27 ), 0 );
	sbSizer2->Add( m_tb_function_4, 0, wxALL, 5 );
	
	
	bSizer3->Add( sbSizer2, 1, wxALIGN_RIGHT, 5 );
	
	
	bSizer1->Add( bSizer3, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxHORIZONTAL );
	
	m_s_ile_poziomic = new wxSlider( this, wxID_ANY, 5, 1, 9, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	m_s_ile_poziomic->SetMinSize( wxSize( 200,-1 ) );
	
	bSizer4->Add( m_s_ile_poziomic, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	
	bSizer4->Add( 0, 0, 1, wxALIGN_CENTER_VERTICAL|wxEXPAND, 5 );
	
	m_st_liczba_poziomic = new wxStaticText( this, wxID_ANY, _("Liczba poziomic: 5"), wxDefaultPosition, wxDefaultSize, 0 );
	m_st_liczba_poziomic->Wrap( -1 );
	bSizer4->Add( m_st_liczba_poziomic, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	
	bSizer4->Add( 0, 0, 1, wxALIGN_CENTER_VERTICAL|wxEXPAND, 5 );
	
	m_tb_pokaz_punkty = new wxToggleButton( this, wxID_ANY, _("pp"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer4->Add( m_tb_pokaz_punkty, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	
	bSizer1->Add( bSizer4, 1, wxEXPAND, 5 );
	
	
	this->SetSizer( bSizer1 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	this->Connect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( MyFrame1::UpdateUI ) );
	m_cb_Kontur->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( MyFrame1::m_cb_Kontur_Click ), NULL, this );
	m_cb_Mapa->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( MyFrame1::m_cb_Mapa_Click ), NULL, this );
	m_rb_NC->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( MyFrame1::m_cb_Mapa_Click ), NULL, this );
	m_rb_NZC->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( MyFrame1::m_cb_Mapa_Click ), NULL, this );
	m_rb_Na_szaro->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( MyFrame1::m_cb_Mapa_Click ), NULL, this );
	m_tb_function_1->Connect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( MyFrame1::m_tb_function_1_click ), NULL, this );
	m_tb_function_2->Connect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( MyFrame1::m_tb_function_2_click ), NULL, this );
	m_tb_function_3->Connect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( MyFrame1::m_tb_function_3_click ), NULL, this );
	m_tb_function_4->Connect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( MyFrame1::m_tb_function_4_click ), NULL, this );
	m_s_ile_poziomic->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MyFrame1::m_s_ile_poziomic_scroll ), NULL, this );
	m_s_ile_poziomic->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MyFrame1::m_s_ile_poziomic_scroll ), NULL, this );
	m_s_ile_poziomic->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MyFrame1::m_s_ile_poziomic_scroll ), NULL, this );
	m_s_ile_poziomic->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MyFrame1::m_s_ile_poziomic_scroll ), NULL, this );
	m_s_ile_poziomic->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MyFrame1::m_s_ile_poziomic_scroll ), NULL, this );
	m_s_ile_poziomic->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MyFrame1::m_s_ile_poziomic_scroll ), NULL, this );
	m_s_ile_poziomic->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MyFrame1::m_s_ile_poziomic_scroll ), NULL, this );
	m_s_ile_poziomic->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MyFrame1::m_s_ile_poziomic_scroll ), NULL, this );
	m_s_ile_poziomic->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MyFrame1::m_s_ile_poziomic_scroll ), NULL, this );
	m_tb_pokaz_punkty->Connect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( MyFrame1::m_tb_pokaz_punkty_toggle ), NULL, this );
}

MyFrame1::~MyFrame1()
{
	// Disconnect Events
	this->Disconnect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( MyFrame1::UpdateUI ) );
	m_cb_Kontur->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( MyFrame1::m_cb_Kontur_Click ), NULL, this );
	m_cb_Mapa->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( MyFrame1::m_cb_Mapa_Click ), NULL, this );
	m_rb_NC->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( MyFrame1::m_cb_Mapa_Click ), NULL, this );
	m_rb_NZC->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( MyFrame1::m_cb_Mapa_Click ), NULL, this );
	m_rb_Na_szaro->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( MyFrame1::m_cb_Mapa_Click ), NULL, this );
	m_tb_function_1->Disconnect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( MyFrame1::m_tb_function_1_click ), NULL, this );
	m_tb_function_2->Disconnect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( MyFrame1::m_tb_function_2_click ), NULL, this );
	m_tb_function_3->Disconnect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( MyFrame1::m_tb_function_3_click ), NULL, this );
	m_tb_function_4->Disconnect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( MyFrame1::m_tb_function_4_click ), NULL, this );
	m_s_ile_poziomic->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MyFrame1::m_s_ile_poziomic_scroll ), NULL, this );
	m_s_ile_poziomic->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MyFrame1::m_s_ile_poziomic_scroll ), NULL, this );
	m_s_ile_poziomic->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MyFrame1::m_s_ile_poziomic_scroll ), NULL, this );
	m_s_ile_poziomic->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MyFrame1::m_s_ile_poziomic_scroll ), NULL, this );
	m_s_ile_poziomic->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MyFrame1::m_s_ile_poziomic_scroll ), NULL, this );
	m_s_ile_poziomic->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MyFrame1::m_s_ile_poziomic_scroll ), NULL, this );
	m_s_ile_poziomic->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MyFrame1::m_s_ile_poziomic_scroll ), NULL, this );
	m_s_ile_poziomic->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MyFrame1::m_s_ile_poziomic_scroll ), NULL, this );
	m_s_ile_poziomic->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MyFrame1::m_s_ile_poziomic_scroll ), NULL, this );
	m_tb_pokaz_punkty->Disconnect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( MyFrame1::m_tb_pokaz_punkty_toggle ), NULL, this );
	
}
