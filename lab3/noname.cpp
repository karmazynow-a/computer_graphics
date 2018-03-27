///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 17 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "noname.h"

///////////////////////////////////////////////////////////////////////////

GUIFrame::GUIFrame( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* sizMain;
	sizMain = new wxBoxSizer( wxHORIZONTAL );


	canvas = new wxGridSizer( 0, 0, 0, 0 );
/*
	panelCanvas = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
	panelCanvas->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNHIGHLIGHT ) );
	panelCanvas->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BTNHIGHLIGHT ) );

	canvas->Add( panelCanvas, 0, wxEXPAND, 5 );
*/

    canvas->SetMinSize( wxSize( 400,400 ) );
	sizMain->Add( canvas, 1, wxALL|wxEXPAND, 5 );


	wxGridSizer* menu;
	menu = new wxGridSizer( 0, 1, 0, 0 );

	menu->SetMinSize( wxSize( 200,-1 ) );
	btnSave = new wxButton( this, wxID_ANY, wxT("Zapis do pliku"), wxDefaultPosition, wxDefaultSize, 0 );
	menu->Add( btnSave, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	btnBanana = new wxCheckBox( this, wxID_ANY, wxT("banan"), wxPoint( -1,-1 ), wxDefaultSize, 0 );
	menu->Add( btnBanana, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	moveBanana = new wxScrollBar( this, wxID_ANY, wxDefaultPosition, wxSize( 180,-1 ), wxSB_HORIZONTAL );
	menu->Add( moveBanana, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	bananaProgress = new wxGauge( this, wxID_ANY, 100, wxDefaultPosition, wxDefaultSize, wxGA_HORIZONTAL );
	bananaProgress->SetValue( 0 );
	menu->Add( bananaProgress, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	btnColorStar = new wxButton( this, wxID_ANY, wxT("kolor gwiazdki"), wxDefaultPosition, wxDefaultSize, 0 );
	menu->Add( btnColorStar, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	text = new wxTextCtrl( this, wxID_ANY, wxT("tekst"), wxDefaultPosition, wxDefaultSize, 0 );
	menu->Add( text, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	comboFigure = new wxComboBox( this, wxID_ANY, wxT("gwiazdka"), wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	comboFigure->Append( wxT("gwiazdka") );
	comboFigure->Append( wxT("księżyc") );
	comboFigure->Append( wxT("słonko") );
	comboFigure->SetSelection( 0 );
	menu->Add( comboFigure, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	sizMain->Add( menu, 0, wxTOP, 5 );


	this->SetSizer( sizMain );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events

	this->Connect( wxEVT_PAINT, wxPaintEventHandler( GUIFrame::onPaint ) );
	this->Connect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( GUIFrame::GUIFrameOnUpdateUI ) );
	btnSave->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::saveToFile ), NULL, this );
	btnBanana->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( GUIFrame::checkBanana ), NULL, this );
	moveBanana->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( GUIFrame::moveBananaOnScroll ), NULL, this );
	moveBanana->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( GUIFrame::moveBananaOnScroll ), NULL, this );
	moveBanana->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( GUIFrame::moveBananaOnScroll ), NULL, this );
	moveBanana->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( GUIFrame::moveBananaOnScroll ), NULL, this );
	moveBanana->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( GUIFrame::moveBananaOnScroll ), NULL, this );
	moveBanana->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( GUIFrame::moveBananaOnScroll ), NULL, this );
	moveBanana->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( GUIFrame::moveBananaOnScroll ), NULL, this );
	moveBanana->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( GUIFrame::moveBananaOnScroll ), NULL, this );
	moveBanana->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( GUIFrame::moveBananaOnScroll ), NULL, this );
	btnColorStar->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::starColor ), NULL, this );
	text->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( GUIFrame::textOnText ), NULL, this );
	comboFigure->Connect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( GUIFrame::changeFigure ), NULL, this );
}

GUIFrame::~GUIFrame()
{
	// Disconnect Events
    this->Disconnect( wxEVT_PAINT, wxPaintEventHandler( GUIFrame::onPaint ) );
	this->Disconnect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( GUIFrame::GUIFrameOnUpdateUI ) );
	btnSave->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::saveToFile ), NULL, this );
	btnBanana->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( GUIFrame::checkBanana ), NULL, this );
	moveBanana->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( GUIFrame::moveBananaOnScroll ), NULL, this );
	moveBanana->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( GUIFrame::moveBananaOnScroll ), NULL, this );
	moveBanana->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( GUIFrame::moveBananaOnScroll ), NULL, this );
	moveBanana->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( GUIFrame::moveBananaOnScroll ), NULL, this );
	moveBanana->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( GUIFrame::moveBananaOnScroll ), NULL, this );
	moveBanana->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( GUIFrame::moveBananaOnScroll ), NULL, this );
	moveBanana->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( GUIFrame::moveBananaOnScroll ), NULL, this );
	moveBanana->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( GUIFrame::moveBananaOnScroll ), NULL, this );
	moveBanana->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( GUIFrame::moveBananaOnScroll ), NULL, this );
	bananaProgress->Disconnect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( GUIFrame::bananaProgressOnUpdateUI ), NULL, this );
	btnColorStar->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( GUIFrame::starColor ), NULL, this );
	text->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( GUIFrame::textOnText ), NULL, this );
	comboFigure->Disconnect( wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler( GUIFrame::changeFigure ), NULL, this );

}
