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
	
	m_staticText1 = new wxStaticText( this, wxID_ANY, _("Układ Świata"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1->Wrap( -1 );
	bSizer2->Add( m_staticText1, 0, wxALIGN_CENTER|wxALL, 5 );
	
	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText2 = new wxStaticText( this, wxID_ANY, _("x0:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2->Wrap( -1 );
	bSizer3->Add( m_staticText2, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	WxEdit_x0 = new wxTextCtrl( this, wxID_ANY, _("-1.0"), wxDefaultPosition, wxSize( 50,-1 ), 0 );
	bSizer3->Add( WxEdit_x0, 0, wxALL, 5 );
	
	m_staticText3 = new wxStaticText( this, wxID_ANY, _("y0:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3->Wrap( -1 );
	bSizer3->Add( m_staticText3, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	WxEdit_y0 = new wxTextCtrl( this, wxID_ANY, _("-2.0"), wxDefaultPosition, wxSize( 50,-1 ), 0 );
	bSizer3->Add( WxEdit_y0, 0, wxALL, 5 );
	
	
	bSizer2->Add( bSizer3, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText7 = new wxStaticText( this, wxID_ANY, _("x1:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText7->Wrap( -1 );
	bSizer4->Add( m_staticText7, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	WxEdit_x1 = new wxTextCtrl( this, wxID_ANY, _("1.0"), wxDefaultPosition, wxSize( 50,-1 ), 0 );
	bSizer4->Add( WxEdit_x1, 0, wxALL, 5 );
	
	m_staticText8 = new wxStaticText( this, wxID_ANY, _("y1:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText8->Wrap( -1 );
	bSizer4->Add( m_staticText8, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	WxEdit_y1 = new wxTextCtrl( this, wxID_ANY, _("2.0"), wxDefaultPosition, wxSize( 50,-1 ), 0 );
	bSizer4->Add( WxEdit_y1, 0, wxALL, 5 );
	
	
	bSizer2->Add( bSizer4, 1, wxEXPAND, 5 );
	
	m_staticText9 = new wxStaticText( this, wxID_ANY, _("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText9->Wrap( -1 );
	bSizer2->Add( m_staticText9, 0, wxALIGN_CENTER|wxALL, 5 );
	
	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText10 = new wxStaticText( this, wxID_ANY, _("Alpha:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText10->Wrap( -1 );
	bSizer5->Add( m_staticText10, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	WxScrollBar_alpha = new wxScrollBar( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSB_HORIZONTAL );
	bSizer5->Add( WxScrollBar_alpha, 1, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	WxStaticText_alpha = new wxStaticText( this, wxID_ANY, _("0"), wxDefaultPosition, wxDefaultSize, 0 );
	WxStaticText_alpha->Wrap( -1 );
	WxStaticText_alpha->SetMinSize( wxSize( 23,-1 ) );
	
	bSizer5->Add( WxStaticText_alpha, 0, wxALIGN_CENTER, 5 );
	
	
	bSizer2->Add( bSizer5, 1, wxEXPAND, 5 );
	
	WxRB_Middle = new wxRadioButton( this, wxID_ANY, _("RadioBtn"), wxDefaultPosition, wxDefaultSize, 0 );
	WxRB_Middle->SetValue( true ); 
	bSizer2->Add( WxRB_Middle, 0, wxALIGN_CENTER|wxALL, 5 );
	
	WxRB_Center = new wxRadioButton( this, wxID_ANY, _("RadioBtn"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2->Add( WxRB_Center, 0, wxALIGN_CENTER|wxALL, 5 );
	
	m_staticText81 = new wxStaticText( this, wxID_ANY, _("Translacja o wektor"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText81->Wrap( -1 );
	bSizer2->Add( m_staticText81, 0, wxALIGN_CENTER|wxALL, 5 );
	
	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText91 = new wxStaticText( this, wxID_ANY, _("dX"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText91->Wrap( -1 );
	bSizer6->Add( m_staticText91, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	WxEdit_dX = new wxTextCtrl( this, wxID_ANY, _("0.0"), wxDefaultPosition, wxSize( 50,-1 ), 0 );
	bSizer6->Add( WxEdit_dX, 0, wxALL, 5 );
	
	m_staticText101 = new wxStaticText( this, wxID_ANY, _("dY"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText101->Wrap( -1 );
	bSizer6->Add( m_staticText101, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	WxEdit_dY = new wxTextCtrl( this, wxID_ANY, _("0.0"), wxDefaultPosition, wxSize( 50,-1 ), 0 );
	bSizer6->Add( WxEdit_dY, 0, wxALL, 5 );
	
	
	bSizer2->Add( bSizer6, 1, wxEXPAND, 5 );
	
	m_staticText11 = new wxStaticText( this, wxID_ANY, _("Wartou015Bci na wykresie:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText11->Wrap( -1 );
	bSizer2->Add( m_staticText11, 0, wxALIGN_CENTER|wxALL, 5 );
	
	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText12 = new wxStaticText( this, wxID_ANY, _("x_start"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText12->Wrap( -1 );
	bSizer7->Add( m_staticText12, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	WxEdit_x_start = new wxTextCtrl( this, wxID_ANY, _("-1.0"), wxDefaultPosition, wxSize( 50,-1 ), 0 );
	bSizer7->Add( WxEdit_x_start, 0, wxALL, 5 );
	
	m_staticText13 = new wxStaticText( this, wxID_ANY, _("x_stop"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText13->Wrap( -1 );
	bSizer7->Add( m_staticText13, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	WxEdit_x_stop = new wxTextCtrl( this, wxID_ANY, _("2.0"), wxDefaultPosition, wxSize( 50,-1 ), 0 );
	bSizer7->Add( WxEdit_x_stop, 0, wxALL, 5 );
	
	
	bSizer2->Add( bSizer7, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer8;
	bSizer8 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText14 = new wxStaticText( this, wxID_ANY, _("y_min:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText14->Wrap( -1 );
	bSizer8->Add( m_staticText14, 0, wxALIGN_CENTER|wxALL, 5 );
	
	Ly_min = new wxStaticText( this, wxID_ANY, _("?"), wxDefaultPosition, wxDefaultSize, 0 );
	Ly_min->Wrap( -1 );
	bSizer8->Add( Ly_min, 0, wxALIGN_CENTER|wxALL, 5 );
	
	m_staticText16 = new wxStaticText( this, wxID_ANY, _("y_min:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText16->Wrap( -1 );
	bSizer8->Add( m_staticText16, 0, wxALIGN_CENTER|wxALL, 5 );
	
	Ly_max = new wxStaticText( this, wxID_ANY, _("?"), wxDefaultPosition, wxDefaultSize, 0 );
	Ly_max->Wrap( -1 );
	bSizer8->Add( Ly_max, 0, wxALIGN_CENTER|wxALL, 5 );
	
	
	bSizer2->Add( bSizer8, 1, wxALIGN_CENTER|wxALL, 5 );
	
	wxString WxChoiceChoices[] = { _("x+sin(4x)"), _("x^2"), _("0.5*e^(4x-3x^2)") };
	int WxChoiceNChoices = sizeof( WxChoiceChoices ) / sizeof( wxString );
	WxChoice = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, WxChoiceNChoices, WxChoiceChoices, 0 );
	WxChoice->SetSelection( 0 );
	bSizer2->Add( WxChoice, 0, wxALIGN_CENTER|wxALL, 5 );
	
	m_button1 = new wxButton( this, wxID_ANY, _("Do ukladu swiata"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2->Add( m_button1, 0, wxALIGN_CENTER|wxALL, 5 );
	
	wxBoxSizer* bSizer9;
	bSizer9 = new wxBoxSizer( wxHORIZONTAL );
	
	m_button2 = new wxButton( this, wxID_ANY, _("Wczytaj"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer9->Add( m_button2, 0, wxALL, 5 );
	
	m_button3 = new wxButton( this, wxID_ANY, _("Zapisz"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer9->Add( m_button3, 0, wxALL, 5 );
	
	
	bSizer2->Add( bSizer9, 1, wxALIGN_CENTER|wxALL, 5 );
	
	
	bSizer1->Add( bSizer2, 0, wxALIGN_RIGHT, 5 );
	
	
	this->SetSizer( bSizer1 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( MyFrame1::MainFormClose ) );
	WxPanel->Connect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( MyFrame1::WxPanel_Repaint ), NULL, this );
	WxEdit_x0->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MyFrame1::WxEdit_x0_Update ), NULL, this );
	WxEdit_y0->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MyFrame1::WxEdit_y0_Update ), NULL, this );
	WxEdit_x1->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MyFrame1::WxEdit_x1_Update ), NULL, this );
	WxEdit_y1->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MyFrame1::WxEdit_y1_Update ), NULL, this );
	WxScrollBar_alpha->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MyFrame1::WxScrollBar_alpha_Update ), NULL, this );
	WxScrollBar_alpha->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MyFrame1::WxScrollBar_alpha_Update ), NULL, this );
	WxScrollBar_alpha->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MyFrame1::WxScrollBar_alpha_Update ), NULL, this );
	WxScrollBar_alpha->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MyFrame1::WxScrollBar_alpha_Update ), NULL, this );
	WxScrollBar_alpha->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MyFrame1::WxScrollBar_alpha_Update ), NULL, this );
	WxScrollBar_alpha->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MyFrame1::WxScrollBar_alpha_Update ), NULL, this );
	WxScrollBar_alpha->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MyFrame1::WxScrollBar_alpha_Update ), NULL, this );
	WxScrollBar_alpha->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MyFrame1::WxScrollBar_alpha_Update ), NULL, this );
	WxScrollBar_alpha->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MyFrame1::WxScrollBar_alpha_Update ), NULL, this );
	WxRB_Middle->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( MyFrame1::WxRB_Middle_Click ), NULL, this );
	WxRB_Center->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( MyFrame1::WxRB_Center_Click ), NULL, this );
	WxEdit_dX->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MyFrame1::WxEdit_dX_Update ), NULL, this );
	WxEdit_dY->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MyFrame1::WxEdit_dY_Update ), NULL, this );
	WxEdit_x_start->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MyFrame1::WxEdit_x_start_Update ), NULL, this );
	WxEdit_x_stop->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MyFrame1::WxEdit_x_stop_Update ), NULL, this );
	WxChoice->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( MyFrame1::WxChoice_Selected ), NULL, this );
	m_button1->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::m_button1_click ), NULL, this );
	m_button2->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::m_button2_click ), NULL, this );
	m_button3->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::m_button3_click ), NULL, this );
}

MyFrame1::~MyFrame1()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( MyFrame1::MainFormClose ) );
	WxPanel->Disconnect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( MyFrame1::WxPanel_Repaint ), NULL, this );
	WxEdit_x0->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MyFrame1::WxEdit_x0_Update ), NULL, this );
	WxEdit_y0->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MyFrame1::WxEdit_y0_Update ), NULL, this );
	WxEdit_x1->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MyFrame1::WxEdit_x1_Update ), NULL, this );
	WxEdit_y1->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MyFrame1::WxEdit_y1_Update ), NULL, this );
	WxScrollBar_alpha->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MyFrame1::WxScrollBar_alpha_Update ), NULL, this );
	WxScrollBar_alpha->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MyFrame1::WxScrollBar_alpha_Update ), NULL, this );
	WxScrollBar_alpha->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MyFrame1::WxScrollBar_alpha_Update ), NULL, this );
	WxScrollBar_alpha->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MyFrame1::WxScrollBar_alpha_Update ), NULL, this );
	WxScrollBar_alpha->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MyFrame1::WxScrollBar_alpha_Update ), NULL, this );
	WxScrollBar_alpha->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MyFrame1::WxScrollBar_alpha_Update ), NULL, this );
	WxScrollBar_alpha->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MyFrame1::WxScrollBar_alpha_Update ), NULL, this );
	WxScrollBar_alpha->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MyFrame1::WxScrollBar_alpha_Update ), NULL, this );
	WxScrollBar_alpha->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MyFrame1::WxScrollBar_alpha_Update ), NULL, this );
	WxRB_Middle->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( MyFrame1::WxRB_Middle_Click ), NULL, this );
	WxRB_Center->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( MyFrame1::WxRB_Center_Click ), NULL, this );
	WxEdit_dX->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MyFrame1::WxEdit_dX_Update ), NULL, this );
	WxEdit_dY->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MyFrame1::WxEdit_dY_Update ), NULL, this );
	WxEdit_x_start->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MyFrame1::WxEdit_x_start_Update ), NULL, this );
	WxEdit_x_stop->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MyFrame1::WxEdit_x_stop_Update ), NULL, this );
	WxChoice->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( MyFrame1::WxChoice_Selected ), NULL, this );
	m_button1->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::m_button1_click ), NULL, this );
	m_button2->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::m_button2_click ), NULL, this );
	m_button3->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::m_button3_click ), NULL, this );
	
}
