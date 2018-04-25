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
	
	m_scrolledWindow = new wxScrolledWindow( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxVSCROLL );
	m_scrolledWindow->SetScrollRate( 5, 5 );
	bSizer1->Add( m_scrolledWindow, 1, wxEXPAND | wxALL, 5 );
	
	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxVERTICAL );
	
	wxGridSizer* gSizer1;
	gSizer1 = new wxGridSizer( 0, 2, 0, 0 );
	
	m_b_grayscale = new wxButton( this, wxID_ANY, _("Grayscale"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizer1->Add( m_b_grayscale, 0, wxALL, 5 );
	
	m_b_blur = new wxButton( this, wxID_ANY, _("Blur"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizer1->Add( m_b_blur, 0, wxALL, 5 );
	
	m_b_mirror = new wxButton( this, wxID_ANY, _("Mirror"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizer1->Add( m_b_mirror, 0, wxALL, 5 );
	
	m_b_replace = new wxButton( this, wxID_ANY, _("Replace"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizer1->Add( m_b_replace, 0, wxALL, 5 );
	
	m_b_rescale = new wxButton( this, wxID_ANY, _("Rescale"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizer1->Add( m_b_rescale, 0, wxALL, 5 );
	
	m_b_rotate = new wxButton( this, wxID_ANY, _("Rotate"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizer1->Add( m_b_rotate, 0, wxALL, 5 );
	
	m_b_rotate_hue = new wxButton( this, wxID_ANY, _("Rotate HUE"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizer1->Add( m_b_rotate_hue, 0, wxALL, 5 );
	
	m_b_mask = new wxButton( this, wxID_ANY, _("Mask"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizer1->Add( m_b_mask, 0, wxALL, 5 );
	
	
	bSizer2->Add( gSizer1, 1, wxEXPAND, 5 );
	
	m_staticText1 = new wxStaticText( this, wxID_ANY, _("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1->Wrap( -1 );
	bSizer2->Add( m_staticText1, 0, wxALIGN_CENTER|wxALL, 5 );
	
	m_s_brightness = new wxSlider( this, wxID_ANY, 100, 0, 200, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	bSizer2->Add( m_s_brightness, 0, wxALIGN_CENTER|wxALL|wxEXPAND, 5 );
	
	m_staticText2 = new wxStaticText( this, wxID_ANY, _("Kontrast"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2->Wrap( -1 );
	bSizer2->Add( m_staticText2, 0, wxALIGN_CENTER|wxALL, 5 );
	
	m_s_contrast = new wxSlider( this, wxID_ANY, 100, 0, 200, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	bSizer2->Add( m_s_contrast, 0, wxALIGN_CENTER|wxALL|wxEXPAND, 5 );
	
	m_b_prewitt = new wxButton( this, wxID_ANY, _("Maska Prewitta"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2->Add( m_b_prewitt, 0, wxALIGN_CENTER|wxALL|wxEXPAND, 5 );
	
	m_b_threshold = new wxButton( this, wxID_ANY, _("Próg 128"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2->Add( m_b_threshold, 0, wxALIGN_CENTER|wxALL|wxEXPAND, 5 );
	
	
	bSizer1->Add( bSizer2, 0, wxALIGN_RIGHT, 5 );
	
	
	this->SetSizer( bSizer1 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_scrolledWindow->Connect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( MyFrame1::m_scrolledWindow_update ), NULL, this );
	m_b_grayscale->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::m_b_grayscale_click ), NULL, this );
	m_b_blur->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::m_b_blur_click ), NULL, this );
	m_b_mirror->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::m_b_mirror_click ), NULL, this );
	m_b_replace->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::m_b_replace_click ), NULL, this );
	m_b_rescale->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::m_b_rescale_click ), NULL, this );
	m_b_rotate->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::m_b_rotate_click ), NULL, this );
	m_b_rotate_hue->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::m_b_rotate_hue_click ), NULL, this );
	m_b_mask->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::m_b_mask_click ), NULL, this );
	m_s_brightness->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MyFrame1::m_s_brightness_scroll ), NULL, this );
	m_s_brightness->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MyFrame1::m_s_brightness_scroll ), NULL, this );
	m_s_brightness->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MyFrame1::m_s_brightness_scroll ), NULL, this );
	m_s_brightness->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MyFrame1::m_s_brightness_scroll ), NULL, this );
	m_s_brightness->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MyFrame1::m_s_brightness_scroll ), NULL, this );
	m_s_brightness->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MyFrame1::m_s_brightness_scroll ), NULL, this );
	m_s_brightness->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MyFrame1::m_s_brightness_scroll ), NULL, this );
	m_s_brightness->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MyFrame1::m_s_brightness_scroll ), NULL, this );
	m_s_brightness->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MyFrame1::m_s_brightness_scroll ), NULL, this );
	m_s_contrast->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MyFrame1::m_s_contrast_scroll ), NULL, this );
	m_s_contrast->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MyFrame1::m_s_contrast_scroll ), NULL, this );
	m_s_contrast->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MyFrame1::m_s_contrast_scroll ), NULL, this );
	m_s_contrast->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MyFrame1::m_s_contrast_scroll ), NULL, this );
	m_s_contrast->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MyFrame1::m_s_contrast_scroll ), NULL, this );
	m_s_contrast->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MyFrame1::m_s_contrast_scroll ), NULL, this );
	m_s_contrast->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MyFrame1::m_s_contrast_scroll ), NULL, this );
	m_s_contrast->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MyFrame1::m_s_contrast_scroll ), NULL, this );
	m_s_contrast->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MyFrame1::m_s_contrast_scroll ), NULL, this );
	m_b_prewitt->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::m_b_prewitt_click ), NULL, this );
	m_b_threshold->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::m_b_threshold_click ), NULL, this );
}

MyFrame1::~MyFrame1()
{
	// Disconnect Events
	m_scrolledWindow->Disconnect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( MyFrame1::m_scrolledWindow_update ), NULL, this );
	m_b_grayscale->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::m_b_grayscale_click ), NULL, this );
	m_b_blur->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::m_b_blur_click ), NULL, this );
	m_b_mirror->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::m_b_mirror_click ), NULL, this );
	m_b_replace->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::m_b_replace_click ), NULL, this );
	m_b_rescale->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::m_b_rescale_click ), NULL, this );
	m_b_rotate->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::m_b_rotate_click ), NULL, this );
	m_b_rotate_hue->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::m_b_rotate_hue_click ), NULL, this );
	m_b_mask->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::m_b_mask_click ), NULL, this );
	m_s_brightness->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MyFrame1::m_s_brightness_scroll ), NULL, this );
	m_s_brightness->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MyFrame1::m_s_brightness_scroll ), NULL, this );
	m_s_brightness->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MyFrame1::m_s_brightness_scroll ), NULL, this );
	m_s_brightness->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MyFrame1::m_s_brightness_scroll ), NULL, this );
	m_s_brightness->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MyFrame1::m_s_brightness_scroll ), NULL, this );
	m_s_brightness->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MyFrame1::m_s_brightness_scroll ), NULL, this );
	m_s_brightness->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MyFrame1::m_s_brightness_scroll ), NULL, this );
	m_s_brightness->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MyFrame1::m_s_brightness_scroll ), NULL, this );
	m_s_brightness->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MyFrame1::m_s_brightness_scroll ), NULL, this );
	m_s_contrast->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MyFrame1::m_s_contrast_scroll ), NULL, this );
	m_s_contrast->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MyFrame1::m_s_contrast_scroll ), NULL, this );
	m_s_contrast->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MyFrame1::m_s_contrast_scroll ), NULL, this );
	m_s_contrast->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MyFrame1::m_s_contrast_scroll ), NULL, this );
	m_s_contrast->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MyFrame1::m_s_contrast_scroll ), NULL, this );
	m_s_contrast->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MyFrame1::m_s_contrast_scroll ), NULL, this );
	m_s_contrast->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MyFrame1::m_s_contrast_scroll ), NULL, this );
	m_s_contrast->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MyFrame1::m_s_contrast_scroll ), NULL, this );
	m_s_contrast->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MyFrame1::m_s_contrast_scroll ), NULL, this );
	m_b_prewitt->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::m_b_prewitt_click ), NULL, this );
	m_b_threshold->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::m_b_threshold_click ), NULL, this );
	
}
