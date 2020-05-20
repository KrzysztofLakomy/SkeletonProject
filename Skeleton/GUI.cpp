///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct 26 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "GUI.h"

///////////////////////////////////////////////////////////////////////////

MyFrame1::MyFrame1( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSize2;
	bSize2 = new wxBoxSizer( wxVERTICAL );

	m_panel2 = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_panel2->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOW ) );

	bSize2->Add( m_panel2, 1, wxEXPAND | wxALL, 5 );


	bSizer1->Add( bSize2, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxVERTICAL );

	m_slider4 = new wxSlider( this, wxID_ANY, 0, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	bSizer3->Add( m_slider4, 0, wxALL, 5 );

	m_staticText9 = new wxStaticText( this, wxID_ANY, wxT("Left Forearm"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText9->Wrap( -1 );
	bSizer3->Add( m_staticText9, 0, wxALIGN_CENTER|wxALL, 5 );

	m_slider7 = new wxSlider( this, wxID_ANY, 50, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	bSizer3->Add( m_slider7, 0, wxALL, 5 );

	m_staticText10 = new wxStaticText( this, wxID_ANY, wxT("Left Arm Side"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText10->Wrap( -1 );
	bSizer3->Add( m_staticText10, 0, wxALIGN_CENTER|wxALL, 5 );

	m_slider8 = new wxSlider( this, wxID_ANY, 50, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	bSizer3->Add( m_slider8, 0, wxALL, 5 );

	m_staticText11 = new wxStaticText( this, wxID_ANY, wxT("aa"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText11->Wrap( -1 );
	bSizer3->Add( m_staticText11, 0, wxALIGN_CENTER|wxALL, 5 );

	m_slider15 = new wxSlider( this, wxID_ANY, 50, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	bSizer3->Add( m_slider15, 0, wxALL, 5 );

	m_staticText19 = new wxStaticText( this, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText19->Wrap( -1 );
	bSizer3->Add( m_staticText19, 0, wxALIGN_CENTER|wxALL, 5 );

	m_slider16 = new wxSlider( this, wxID_ANY, 50, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	bSizer3->Add( m_slider16, 0, wxALL, 5 );

	m_staticText20 = new wxStaticText( this, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText20->Wrap( -1 );
	bSizer3->Add( m_staticText20, 0, wxALIGN_CENTER|wxALL, 5 );

	m_slider17 = new wxSlider( this, wxID_ANY, 50, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	bSizer3->Add( m_slider17, 0, wxALL, 5 );

	m_staticText21 = new wxStaticText( this, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText21->Wrap( -1 );
	bSizer3->Add( m_staticText21, 0, wxALIGN_CENTER|wxALL, 5 );

	m_slider18 = new wxSlider( this, wxID_ANY, 50, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	bSizer3->Add( m_slider18, 0, wxALL, 5 );

	m_staticText22 = new wxStaticText( this, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText22->Wrap( -1 );
	bSizer3->Add( m_staticText22, 0, wxALIGN_CENTER|wxALL, 5 );


	bSizer1->Add( bSizer3, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer( wxVERTICAL );

	m_slider5 = new wxSlider( this, wxID_ANY, 50, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	bSizer7->Add( m_slider5, 0, wxALL, 5 );

	m_staticText12 = new wxStaticText( this, wxID_ANY, wxT("Right Forearm"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText12->Wrap( -1 );
	bSizer7->Add( m_staticText12, 0, wxALIGN_CENTER|wxALL, 5 );

	m_slider9 = new wxSlider( this, wxID_ANY, 50, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	bSizer7->Add( m_slider9, 0, wxALL, 5 );

	m_staticText13 = new wxStaticText( this, wxID_ANY, wxT("Right Arm"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText13->Wrap( -1 );
	bSizer7->Add( m_staticText13, 0, wxALIGN_CENTER|wxALL, 5 );

	m_slider10 = new wxSlider( this, wxID_ANY, 50, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	bSizer7->Add( m_slider10, 0, wxALL, 5 );

	m_staticText14 = new wxStaticText( this, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText14->Wrap( -1 );
	bSizer7->Add( m_staticText14, 0, wxALIGN_CENTER|wxALL, 5 );

	m_slider11 = new wxSlider( this, wxID_ANY, 50, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	bSizer7->Add( m_slider11, 0, wxALL, 5 );

	m_staticText15 = new wxStaticText( this, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText15->Wrap( -1 );
	bSizer7->Add( m_staticText15, 0, wxALIGN_CENTER|wxALL, 5 );

	m_slider12 = new wxSlider( this, wxID_ANY, 50, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	bSizer7->Add( m_slider12, 0, wxALL, 5 );

	m_staticText16 = new wxStaticText( this, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText16->Wrap( -1 );
	bSizer7->Add( m_staticText16, 0, wxALIGN_CENTER|wxALL, 5 );

	m_slider13 = new wxSlider( this, wxID_ANY, 50, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	bSizer7->Add( m_slider13, 0, wxALL, 5 );

	m_staticText17 = new wxStaticText( this, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText17->Wrap( -1 );
	bSizer7->Add( m_staticText17, 0, wxALIGN_CENTER|wxALL, 5 );

	m_slider14 = new wxSlider( this, wxID_ANY, 50, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	bSizer7->Add( m_slider14, 0, wxALL, 5 );

	m_staticText18 = new wxStaticText( this, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText18->Wrap( -1 );
	bSizer7->Add( m_staticText18, 0, wxALIGN_CENTER|wxALL, 5 );


	bSizer1->Add( bSizer7, 0, wxEXPAND, 5 );


	this->SetSizer( bSizer1 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	m_panel2->Connect( wxEVT_LEFT_DOWN, wxMouseEventHandler( MyFrame1::m_panel2OnLeftDown ), NULL, this );
	m_panel2->Connect( wxEVT_LEFT_UP, wxMouseEventHandler( MyFrame1::m_panel2OnLeftUp ), NULL, this );
	m_panel2->Connect( wxEVT_MOTION, wxMouseEventHandler( MyFrame1::m_panel2OnMotion ), NULL, this );
	m_panel2->Connect( wxEVT_PAINT, wxPaintEventHandler( MyFrame1::m_panel2OnPaint ), NULL, this );
	m_panel2->Connect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( MyFrame1::m_panel2OnUpdateUI ), NULL, this );
	m_slider4->Connect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MyFrame1::m_slider4OnScroll ), NULL, this );
	m_slider4->Connect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MyFrame1::m_slider4OnScroll ), NULL, this );
	m_slider4->Connect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MyFrame1::m_slider4OnScroll ), NULL, this );
	m_slider4->Connect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MyFrame1::m_slider4OnScroll ), NULL, this );
	m_slider4->Connect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MyFrame1::m_slider4OnScroll ), NULL, this );
	m_slider4->Connect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MyFrame1::m_slider4OnScroll ), NULL, this );
	m_slider4->Connect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MyFrame1::m_slider4OnScroll ), NULL, this );
	m_slider4->Connect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MyFrame1::m_slider4OnScroll ), NULL, this );
	m_slider4->Connect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MyFrame1::m_slider4OnScroll ), NULL, this );
}

MyFrame1::~MyFrame1()
{
	// Disconnect Events
	m_panel2->Disconnect( wxEVT_LEFT_DOWN, wxMouseEventHandler( MyFrame1::m_panel2OnLeftDown ), NULL, this );
	m_panel2->Disconnect( wxEVT_LEFT_UP, wxMouseEventHandler( MyFrame1::m_panel2OnLeftUp ), NULL, this );
	m_panel2->Disconnect( wxEVT_MOTION, wxMouseEventHandler( MyFrame1::m_panel2OnMotion ), NULL, this );
	m_panel2->Disconnect( wxEVT_PAINT, wxPaintEventHandler( MyFrame1::m_panel2OnPaint ), NULL, this );
	m_panel2->Disconnect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( MyFrame1::m_panel2OnUpdateUI ), NULL, this );
	m_slider4->Disconnect( wxEVT_SCROLL_TOP, wxScrollEventHandler( MyFrame1::m_slider4OnScroll ), NULL, this );
	m_slider4->Disconnect( wxEVT_SCROLL_BOTTOM, wxScrollEventHandler( MyFrame1::m_slider4OnScroll ), NULL, this );
	m_slider4->Disconnect( wxEVT_SCROLL_LINEUP, wxScrollEventHandler( MyFrame1::m_slider4OnScroll ), NULL, this );
	m_slider4->Disconnect( wxEVT_SCROLL_LINEDOWN, wxScrollEventHandler( MyFrame1::m_slider4OnScroll ), NULL, this );
	m_slider4->Disconnect( wxEVT_SCROLL_PAGEUP, wxScrollEventHandler( MyFrame1::m_slider4OnScroll ), NULL, this );
	m_slider4->Disconnect( wxEVT_SCROLL_PAGEDOWN, wxScrollEventHandler( MyFrame1::m_slider4OnScroll ), NULL, this );
	m_slider4->Disconnect( wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler( MyFrame1::m_slider4OnScroll ), NULL, this );
	m_slider4->Disconnect( wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler( MyFrame1::m_slider4OnScroll ), NULL, this );
	m_slider4->Disconnect( wxEVT_SCROLL_CHANGED, wxScrollEventHandler( MyFrame1::m_slider4OnScroll ), NULL, this );

}
