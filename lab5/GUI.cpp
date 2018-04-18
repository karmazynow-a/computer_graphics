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
	this->SetSizeHints( wxSize( 600,400 ), wxDefaultSize );
	
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxHORIZONTAL );
	
	WxPanel = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	WxPanel->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNHIGHLIGHT ) );
	
	bSizer1->Add( WxPanel, 1, wxEXPAND | wxALL, 5 );
	
	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxVERTICAL );
	
	m_button_load_geometry = new wxButton( this, wxID_ANY, _("Wczytaj Geometrię"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2->Add( m_button_load_geometry, 0, wxALIGN_CENTER, 5 );
	
	wxFlexGridSizer* fgSizer1;
	fgSizer1 = new wxFlexGridSizer( 0, 3, 0, 0 );
	fgSizer1->SetFlexibleDirection( wxBOTH );
	fgSizer1->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText19 = new wxStaticText( this, wxID_ANY, _("Translacja X:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText19->Wrap( -1 );
	fgSizer1->Add( m_staticText19, 0, wxALL, 5 );
	
	WxSB_TranslationX = new wxSlider( this, wxID_ANY, 50, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	WxSB_TranslationX->SetMinSize( wxSize( 100,-1 ) );
	
	fgSizer1->Add( WxSB_TranslationX, 0, wxALL, 5 );
	
	WxST_TranslationX = new wxStaticText( this, wxID_ANY, _("0"), wxDefaultPosition, wxDefaultSize, 0 );
	WxST_TranslationX->Wrap( -1 );
	WxST_TranslationX->SetMinSize( wxSize( 30,-1 ) );
	
	fgSizer1->Add( WxST_TranslationX, 0, wxALL, 5 );
	
	m_staticText21 = new wxStaticText( this, wxID_ANY, _("Translacja Y:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText21->Wrap( -1 );
	fgSizer1->Add( m_staticText21, 0, wxALL, 5 );
	
	WxSB_TranslationY = new wxSlider( this, wxID_ANY, 50, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	WxSB_TranslationY->SetMinSize( wxSize( 100,-1 ) );
	
	fgSizer1->Add( WxSB_TranslationY, 0, wxALL, 5 );
	
	WxST_TranslationY = new wxStaticText( this, wxID_ANY, _("0"), wxDefaultPosition, wxDefaultSize, 0 );
	WxST_TranslationY->Wrap( -1 );
	fgSizer1->Add( WxST_TranslationY, 0, wxALL, 5 );
	
	m_staticText23 = new wxStaticText( this, wxID_ANY, _("Translacja Z:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText23->Wrap( -1 );
	fgSizer1->Add( m_staticText23, 0, wxALL, 5 );
	
	WxSB_TranslationZ = new wxSlider( this, wxID_ANY, 50, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	WxSB_TranslationZ->SetMinSize( wxSize( 100,-1 ) );
	
	fgSizer1->Add( WxSB_TranslationZ, 0, wxALL, 5 );
	
	WxST_TranslationZ = new wxStaticText( this, wxID_ANY, _("0"), wxDefaultPosition, wxDefaultSize, 0 );
	WxST_TranslationZ->Wrap( -1 );
	fgSizer1->Add( WxST_TranslationZ, 0, wxALL, 5 );
	
	m_staticText25 = new wxStaticText( this, wxID_ANY, _("Obrót X:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText25->Wrap( -1 );
	fgSizer1->Add( m_staticText25, 0, wxALL, 5 );
	
	WxSB_RotateX = new wxSlider( this, wxID_ANY, 50, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	WxSB_RotateX->SetMinSize( wxSize( 100,-1 ) );
	
	fgSizer1->Add( WxSB_RotateX, 0, wxALL, 5 );
	
	WxST_RotateX = new wxStaticText( this, wxID_ANY, _("0"), wxDefaultPosition, wxDefaultSize, 0 );
	WxST_RotateX->Wrap( -1 );
	fgSizer1->Add( WxST_RotateX, 0, wxALL, 5 );
	
	m_staticText27 = new wxStaticText( this, wxID_ANY, _("Obrót Y:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText27->Wrap( -1 );
	fgSizer1->Add( m_staticText27, 0, wxALL, 5 );
	
	WxSB_RotateY = new wxSlider( this, wxID_ANY, 50, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	WxSB_RotateY->SetMinSize( wxSize( 100,-1 ) );
	
	fgSizer1->Add( WxSB_RotateY, 0, wxALL, 5 );
	
	WxST_RotateY = new wxStaticText( this, wxID_ANY, _("0"), wxDefaultPosition, wxDefaultSize, 0 );
	WxST_RotateY->Wrap( -1 );
	fgSizer1->Add( WxST_RotateY, 0, wxALL, 5 );
	
	m_staticText29 = new wxStaticText( this, wxID_ANY, _("Obrót Z:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText29->Wrap( -1 );
	fgSizer1->Add( m_staticText29, 0, wxALL, 5 );
	
	WxSB_RotateZ = new wxSlider( this, wxID_ANY, 50, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	WxSB_RotateZ->SetMinSize( wxSize( 100,-1 ) );
	
	fgSizer1->Add( WxSB_RotateZ, 0, wxALL, 5 );
	
	WxST_RotateZ = new wxStaticText( this, wxID_ANY, _("0"), wxDefaultPosition, wxDefaultSize, 0 );
	WxST_RotateZ->Wrap( -1 );
	fgSizer1->Add( WxST_RotateZ, 0, wxALL, 5 );
	
	m_staticText31 = new wxStaticText( this, wxID_ANY, _("Skala X:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText31->Wrap( -1 );
	fgSizer1->Add( m_staticText31, 0, wxALL, 5 );
	
	WxSB_ScaleX = new wxSlider( this, wxID_ANY, 50, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	WxSB_ScaleX->SetMinSize( wxSize( 100,-1 ) );
	
	fgSizer1->Add( WxSB_ScaleX, 0, wxALL, 5 );
	
	WxST_ScaleX = new wxStaticText( this, wxID_ANY, _("1.0"), wxDefaultPosition, wxDefaultSize, 0 );
	WxST_ScaleX->Wrap( -1 );
	fgSizer1->Add( WxST_ScaleX, 0, wxALL, 5 );
	
	m_staticText33 = new wxStaticText( this, wxID_ANY, _("Skala Y:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText33->Wrap( -1 );
	fgSizer1->Add( m_staticText33, 0, wxALL, 5 );
	
	WxSB_ScaleY = new wxSlider( this, wxID_ANY, 50, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	WxSB_ScaleY->SetMinSize( wxSize( 100,-1 ) );
	
	fgSizer1->Add( WxSB_ScaleY, 0, wxALL, 5 );
	
	WxST_ScaleY = new wxStaticText( this, wxID_ANY, _("1.0"), wxDefaultPosition, wxDefaultSize, 0 );
	WxST_ScaleY->Wrap( -1 );
	fgSizer1->Add( WxST_ScaleY, 0, wxALL, 5 );
	
	m_staticText35 = new wxStaticText( this, wxID_ANY, _("Skala Z:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText35->Wrap( -1 );
	fgSizer1->Add( m_staticText35, 0, wxALL, 5 );
	
	WxSB_ScaleZ = new wxSlider( this, wxID_ANY, 50, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	WxSB_ScaleZ->SetMinSize( wxSize( 100,-1 ) );
	
	fgSizer1->Add( WxSB_ScaleZ, 0, wxALL, 5 );
	
	WxST_ScaleZ = new wxStaticText( this, wxID_ANY, _("1.0"), wxDefaultPosition, wxDefaultSize, 0 );
	WxST_ScaleZ->Wrap( -1 );
	fgSizer1->Add( WxST_ScaleZ, 0, wxALL, 5 );
	
	
	bSizer2->Add( fgSizer1, 1, wxEXPAND, 5 );
	
	
	bSizer1->Add( bSizer2, 0, wxALIGN_RIGHT, 5 );
	
	
	this->SetSizer( bSizer1 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	WxPanel->Connect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( MyFrame1::WxPanel_Repaint ), NULL, this );
	m_button_load_geometry->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::m_button_load_geometry_click ), NULL, this );
	WxSB_TranslationX->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_TranslationX->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_TranslationX->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_TranslationX->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_TranslationX->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_TranslationX->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_TranslationX->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_TranslationX->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_TranslationX->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_TranslationY->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_TranslationY->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_TranslationY->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_TranslationY->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_TranslationY->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_TranslationY->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_TranslationY->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_TranslationY->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_TranslationY->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_TranslationZ->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_TranslationZ->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_TranslationZ->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_TranslationZ->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_TranslationZ->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_TranslationZ->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_TranslationZ->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_TranslationZ->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_TranslationZ->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_RotateX->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_RotateX->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_RotateX->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_RotateX->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_RotateX->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_RotateX->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_RotateX->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_RotateX->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_RotateX->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_RotateY->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_RotateY->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_RotateY->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_RotateY->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_RotateY->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_RotateY->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_RotateY->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_RotateY->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_RotateY->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_RotateZ->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_RotateZ->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_RotateZ->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_RotateZ->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_RotateZ->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_RotateZ->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_RotateZ->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_RotateZ->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_RotateZ->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_ScaleX->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_ScaleX->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_ScaleX->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_ScaleX->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_ScaleX->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_ScaleX->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_ScaleX->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_ScaleX->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_ScaleX->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_ScaleY->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_ScaleY->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_ScaleY->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_ScaleY->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_ScaleY->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_ScaleY->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_ScaleY->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_ScaleY->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_ScaleY->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_ScaleZ->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_ScaleZ->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_ScaleZ->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_ScaleZ->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_ScaleZ->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_ScaleZ->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_ScaleZ->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_ScaleZ->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_ScaleZ->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
}

MyFrame1::~MyFrame1()
{
	// Disconnect Events
	WxPanel->Disconnect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( MyFrame1::WxPanel_Repaint ), NULL, this );
	m_button_load_geometry->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::m_button_load_geometry_click ), NULL, this );
	WxSB_TranslationX->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_TranslationX->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_TranslationX->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_TranslationX->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_TranslationX->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_TranslationX->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_TranslationX->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_TranslationX->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_TranslationX->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_TranslationY->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_TranslationY->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_TranslationY->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_TranslationY->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_TranslationY->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_TranslationY->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_TranslationY->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_TranslationY->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_TranslationY->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_TranslationZ->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_TranslationZ->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_TranslationZ->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_TranslationZ->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_TranslationZ->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_TranslationZ->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_TranslationZ->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_TranslationZ->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_TranslationZ->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_RotateX->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_RotateX->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_RotateX->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_RotateX->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_RotateX->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_RotateX->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_RotateX->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_RotateX->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_RotateX->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_RotateY->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_RotateY->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_RotateY->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_RotateY->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_RotateY->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_RotateY->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_RotateY->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_RotateY->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_RotateY->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_RotateZ->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_RotateZ->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_RotateZ->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_RotateZ->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_RotateZ->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_RotateZ->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_RotateZ->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_RotateZ->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_RotateZ->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_ScaleX->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_ScaleX->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_ScaleX->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_ScaleX->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_ScaleX->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_ScaleX->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_ScaleX->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_ScaleX->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_ScaleX->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_ScaleY->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_ScaleY->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_ScaleY->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_ScaleY->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_ScaleY->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_ScaleY->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_ScaleY->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_ScaleY->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_ScaleY->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_ScaleZ->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_ScaleZ->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_ScaleZ->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_ScaleZ->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_ScaleZ->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_ScaleZ->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_ScaleZ->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_ScaleZ->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	WxSB_ScaleZ->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MyFrame1::Scrolls_Updated ), NULL, this );
	
}
