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
	m_panel2->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOW ) );
	m_panel2->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOW ) );

	bSize2->Add( m_panel2, 10, wxEXPAND | wxALL, 5 );

	m_timeline_panel = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxBORDER_THEME|wxTAB_TRAVERSAL );
	m_timeline_panel->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_GRAYTEXT ) );

	bSize2->Add( m_timeline_panel, 2, wxEXPAND | wxALL, 5 );


	bSizer1->Add( bSize2, 5, wxEXPAND, 5 );

	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer71;
	bSizer71 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxVERTICAL );

	m_left_forearm_slider = new wxSlider( this, wxID_ANY, 0, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	bSizer3->Add( m_left_forearm_slider, 0, wxALL, 5 );

	m_staticText9 = new wxStaticText( this, wxID_ANY, wxT("Left Forearm"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText9->Wrap( -1 );
	bSizer3->Add( m_staticText9, 0, wxALIGN_CENTER|wxALL, 5 );

	m_left_arm_side_slider = new wxSlider( this, wxID_ANY, 50, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	bSizer3->Add( m_left_arm_side_slider, 0, wxALL, 5 );

	m_staticText10 = new wxStaticText( this, wxID_ANY, wxT("Left Arm Side"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText10->Wrap( -1 );
	bSizer3->Add( m_staticText10, 0, wxALIGN_CENTER|wxALL, 5 );

	m_left_arm_front_slider = new wxSlider( this, wxID_ANY, 0, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	bSizer3->Add( m_left_arm_front_slider, 0, wxALL, 5 );

	m_staticText11 = new wxStaticText( this, wxID_ANY, wxT("Left Arm Front"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText11->Wrap( -1 );
	bSizer3->Add( m_staticText11, 0, wxALIGN_CENTER|wxALL, 5 );

	m_left_tibia_slider = new wxSlider( this, wxID_ANY, 0, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	bSizer3->Add( m_left_tibia_slider, 0, wxALL, 5 );

	m_staticText19 = new wxStaticText( this, wxID_ANY, wxT("Left Tibia"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText19->Wrap( -1 );
	bSizer3->Add( m_staticText19, 0, wxALIGN_CENTER|wxALL, 5 );

	m_left_thigh_side_slider = new wxSlider( this, wxID_ANY, 0, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	bSizer3->Add( m_left_thigh_side_slider, 0, wxALL, 5 );

	m_staticText20 = new wxStaticText( this, wxID_ANY, wxT("Left Thigh Side"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText20->Wrap( -1 );
	bSizer3->Add( m_staticText20, 0, wxALIGN_CENTER|wxALL, 5 );

	m_left_thigh_front_slider = new wxSlider( this, wxID_ANY, 50, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	bSizer3->Add( m_left_thigh_front_slider, 0, wxALL, 5 );

	m_staticText21 = new wxStaticText( this, wxID_ANY, wxT("Left Thigh Front"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText21->Wrap( -1 );
	bSizer3->Add( m_staticText21, 0, wxALIGN_CENTER|wxALL, 5 );

	m_middle_back_front_slider = new wxSlider( this, wxID_ANY, 0, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	bSizer3->Add( m_middle_back_front_slider, 0, wxALL, 5 );

	m_staticText22 = new wxStaticText( this, wxID_ANY, wxT("Middle Back front"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText22->Wrap( -1 );
	bSizer3->Add( m_staticText22, 0, wxALIGN_CENTER|wxALL, 5 );

	m_lower_back_front_slider = new wxSlider( this, wxID_ANY, 0, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	bSizer3->Add( m_lower_back_front_slider, 0, wxALL, 5 );

	m_staticText161 = new wxStaticText( this, wxID_ANY, wxT("Lower Back Front"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText161->Wrap( -1 );
	bSizer3->Add( m_staticText161, 0, wxALIGN_CENTER, 5 );


	bSizer71->Add( bSizer3, 0, 0, 5 );

	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer( wxVERTICAL );

	m_right_forearm_slider = new wxSlider( this, wxID_ANY, 0, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	bSizer7->Add( m_right_forearm_slider, 0, wxALL, 5 );

	m_staticText12 = new wxStaticText( this, wxID_ANY, wxT("Right Forearm"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText12->Wrap( -1 );
	bSizer7->Add( m_staticText12, 0, wxALIGN_CENTER|wxALL, 5 );

	m_right_arm_side_slider = new wxSlider( this, wxID_ANY, 50, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	bSizer7->Add( m_right_arm_side_slider, 0, wxALL, 5 );

	m_staticText13 = new wxStaticText( this, wxID_ANY, wxT("Right Arm Side"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText13->Wrap( -1 );
	bSizer7->Add( m_staticText13, 0, wxALIGN_CENTER|wxALL, 5 );

	m_right_arm_front_slider = new wxSlider( this, wxID_ANY, 0, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	bSizer7->Add( m_right_arm_front_slider, 0, wxALL, 5 );

	m_staticText14 = new wxStaticText( this, wxID_ANY, wxT("Right Arm Front"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText14->Wrap( -1 );
	bSizer7->Add( m_staticText14, 0, wxALIGN_CENTER|wxALL, 5 );

	m_right_tibia_slider = new wxSlider( this, wxID_ANY, 0, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	bSizer7->Add( m_right_tibia_slider, 0, wxALL, 5 );

	m_staticText15 = new wxStaticText( this, wxID_ANY, wxT("Right Tibia"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText15->Wrap( -1 );
	bSizer7->Add( m_staticText15, 0, wxALIGN_CENTER|wxALL, 5 );

	m_right_thigh_side_slider = new wxSlider( this, wxID_ANY, 0, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	bSizer7->Add( m_right_thigh_side_slider, 0, wxALL, 5 );

	m_staticText16 = new wxStaticText( this, wxID_ANY, wxT("Right Thigh Side"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText16->Wrap( -1 );
	bSizer7->Add( m_staticText16, 0, wxALIGN_CENTER|wxALL, 5 );

	m_right_thigh_front_slider = new wxSlider( this, wxID_ANY, 50, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	bSizer7->Add( m_right_thigh_front_slider, 0, wxALL, 5 );

	m_staticText17 = new wxStaticText( this, wxID_ANY, wxT("Right Thigh Front"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText17->Wrap( -1 );
	bSizer7->Add( m_staticText17, 0, wxALIGN_CENTER|wxALL, 5 );

	m_middle_back_side_slider = new wxSlider( this, wxID_ANY, 50, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	bSizer7->Add( m_middle_back_side_slider, 0, wxALL, 5 );

	m_staticText18 = new wxStaticText( this, wxID_ANY, wxT("MIddle Back Side"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText18->Wrap( -1 );
	bSizer7->Add( m_staticText18, 0, wxALIGN_CENTER|wxALL, 5 );

	m_lower_back_side_slider = new wxSlider( this, wxID_ANY, 50, 0, 100, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL );
	bSizer7->Add( m_lower_back_side_slider, 0, wxALL, 5 );

	m_staticText151 = new wxStaticText( this, wxID_ANY, wxT("Lower Back Side"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText151->Wrap( -1 );
	bSizer7->Add( m_staticText151, 0, wxALIGN_CENTER, 5 );

	m_button1 = new wxButton( this, wxID_ANY, wxT("Reset"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer7->Add( m_button1, 0, wxALIGN_CENTER|wxALL, 5 );


	bSizer71->Add( bSizer7, 0, 0, 5 );


	bSizer6->Add( bSizer71, 10, wxEXPAND, 5 );

	wxStaticBoxSizer* sbSizer1;
	sbSizer1 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Animation") ), wxVERTICAL );

	wxStaticBoxSizer* sbSizer3;
	sbSizer3 = new wxStaticBoxSizer( new wxStaticBox( sbSizer1->GetStaticBox(), wxID_ANY, wxT("Amount of frames") ), wxVERTICAL );

	m_amountOfFramesText = new wxTextCtrl( sbSizer3->GetStaticBox(), wxID_ANY, wxT("30"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer3->Add( m_amountOfFramesText, 0, wxALL, 5 );

	m_enableAnimationButton = new wxButton( sbSizer3->GetStaticBox(), wxID_ANY, wxT("Enable Animation"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer3->Add( m_enableAnimationButton, 0, wxALL, 5 );


	sbSizer1->Add( sbSizer3, 1, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );

	wxBoxSizer* bSizer8;
	bSizer8 = new wxBoxSizer( wxHORIZONTAL );

	m_saveFrameButton = new wxButton( sbSizer1->GetStaticBox(), wxID_ANY, wxT("Save Frame Configuration"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer8->Add( m_saveFrameButton, 0, wxALL, 5 );


	sbSizer1->Add( bSizer8, 1, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0 );

	wxBoxSizer* bSizer10;
	bSizer10 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText181 = new wxStaticText( sbSizer1->GetStaticBox(), wxID_ANY, wxT("Selected frame:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText181->Wrap( -1 );
	bSizer10->Add( m_staticText181, 0, wxALL, 5 );

	m_selectedFrameText = new wxTextCtrl( sbSizer1->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_selectedFrameText->Enable( false );
	m_selectedFrameText->SetMaxSize( wxSize( 25,-1 ) );

	bSizer10->Add( m_selectedFrameText, 0, wxALL, 1 );

	m_repeatCheckBox = new wxCheckBox( sbSizer1->GetStaticBox(), wxID_ANY, wxT("Repeat"), wxDefaultPosition, wxDefaultSize, 0 );
	m_repeatCheckBox->SetValue(true);
	bSizer10->Add( m_repeatCheckBox, 0, wxALL, 5 );


	sbSizer1->Add( bSizer10, 1, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2 );

	wxBoxSizer* bSizer9;
	bSizer9 = new wxBoxSizer( wxHORIZONTAL );

	m_startAnimationButton = new wxButton( sbSizer1->GetStaticBox(), wxID_ANY, wxT("Start"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer9->Add( m_startAnimationButton, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	m_stopButton = new wxButton( sbSizer1->GetStaticBox(), wxID_ANY, wxT("Stop"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer9->Add( m_stopButton, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );


	sbSizer1->Add( bSizer9, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer101;
	bSizer101 = new wxBoxSizer( wxHORIZONTAL );

	m_saveAnimationToText = new wxButton( sbSizer1->GetStaticBox(), wxID_ANY, wxT("Save to file"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer101->Add( m_saveAnimationToText, 0, wxALL, 5 );

	m_loadFromFile = new wxButton( sbSizer1->GetStaticBox(), wxID_ANY, wxT("Load from file"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer101->Add( m_loadFromFile, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );


	sbSizer1->Add( bSizer101, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer11;
	bSizer11 = new wxBoxSizer( wxVERTICAL );

	m_saveAnimationToFileButton = new wxButton( sbSizer1->GetStaticBox(), wxID_ANY, wxT("Save to graphic files"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer11->Add( m_saveAnimationToFileButton, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL|wxALL, 5 );


	sbSizer1->Add( bSizer11, 1, wxEXPAND, 5 );


	bSizer6->Add( sbSizer1, 1, wxEXPAND, 2 );


	bSizer1->Add( bSizer6, 1, wxEXPAND, 5 );


	this->SetSizer( bSizer1 );
	this->Layout();
	m_animationTimer.SetOwner( this, wxID_ANY );

	this->Centre( wxBOTH );

	// Connect Events
	m_panel2->Connect( wxEVT_LEFT_DOWN, wxMouseEventHandler( MyFrame1::m_panel2OnLeftDown ), NULL, this );
	m_panel2->Connect( wxEVT_LEFT_UP, wxMouseEventHandler( MyFrame1::m_panel2OnLeftUp ), NULL, this );
	m_panel2->Connect( wxEVT_MOTION, wxMouseEventHandler( MyFrame1::m_panel2OnMotion ), NULL, this );
	m_panel2->Connect( wxEVT_PAINT, wxPaintEventHandler( MyFrame1::m_panel2OnPaint ), NULL, this );
	m_panel2->Connect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( MyFrame1::m_panel2OnUpdateUI ), NULL, this );
	m_timeline_panel->Connect( wxEVT_LEFT_DCLICK, wxMouseEventHandler( MyFrame1::onTimelineClick ), NULL, this );
	m_timeline_panel->Connect( wxEVT_PAINT, wxPaintEventHandler( MyFrame1::onTimelinePaint ), NULL, this );
	m_timeline_panel->Connect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( MyFrame1::onTimelineUpdate ), NULL, this );
	m_button1->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::m_button1OnButtonClick ), NULL, this );
	m_enableAnimationButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::onEnableAnimationClicked ), NULL, this );
	m_saveFrameButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::onSaveFrameConfigurationClicked ), NULL, this );
	m_startAnimationButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::onStartAnimationButonClick ), NULL, this );
	m_stopButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::onStopButtonClick ), NULL, this );
	m_saveAnimationToText->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::onSaveToFileClicked ), NULL, this );
	m_loadFromFile->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::onLoadFromFileAnimationButton ), NULL, this );
	m_saveAnimationToFileButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::onSaveAnimationToFileButtonClick ), NULL, this );
	this->Connect( wxID_ANY, wxEVT_TIMER, wxTimerEventHandler( MyFrame1::onTimerTick ) );
}

MyFrame1::~MyFrame1()
{
	// Disconnect Events
	m_panel2->Disconnect( wxEVT_LEFT_DOWN, wxMouseEventHandler( MyFrame1::m_panel2OnLeftDown ), NULL, this );
	m_panel2->Disconnect( wxEVT_LEFT_UP, wxMouseEventHandler( MyFrame1::m_panel2OnLeftUp ), NULL, this );
	m_panel2->Disconnect( wxEVT_MOTION, wxMouseEventHandler( MyFrame1::m_panel2OnMotion ), NULL, this );
	m_panel2->Disconnect( wxEVT_PAINT, wxPaintEventHandler( MyFrame1::m_panel2OnPaint ), NULL, this );
	m_panel2->Disconnect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( MyFrame1::m_panel2OnUpdateUI ), NULL, this );
	m_timeline_panel->Disconnect( wxEVT_LEFT_DCLICK, wxMouseEventHandler( MyFrame1::onTimelineClick ), NULL, this );
	m_timeline_panel->Disconnect( wxEVT_PAINT, wxPaintEventHandler( MyFrame1::onTimelinePaint ), NULL, this );
	m_timeline_panel->Disconnect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( MyFrame1::onTimelineUpdate ), NULL, this );
	m_button1->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::m_button1OnButtonClick ), NULL, this );
	m_enableAnimationButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::onEnableAnimationClicked ), NULL, this );
	m_saveFrameButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::onSaveFrameConfigurationClicked ), NULL, this );
	m_startAnimationButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::onStartAnimationButonClick ), NULL, this );
	m_stopButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::onStopButtonClick ), NULL, this );
	m_saveAnimationToText->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::onSaveToFileClicked ), NULL, this );
	m_loadFromFile->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::onLoadFromFileAnimationButton ), NULL, this );
	m_saveAnimationToFileButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyFrame1::onSaveAnimationToFileButtonClick ), NULL, this );
	this->Disconnect( wxID_ANY, wxEVT_TIMER, wxTimerEventHandler( MyFrame1::onTimerTick ) );

}
