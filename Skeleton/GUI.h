///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct 26 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/panel.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/sizer.h>
#include <wx/slider.h>
#include <wx/stattext.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/button.h>
#include <wx/textctrl.h>
#include <wx/statbox.h>
#include <wx/checkbox.h>
#include <wx/timer.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class MyFrame1
///////////////////////////////////////////////////////////////////////////////
class MyFrame1 : public wxFrame
{
	private:

	protected:
		wxPanel* m_panel2;
		wxPanel* m_timeline_panel;
		wxSlider* m_left_forearm_slider;
		wxStaticText* m_staticText9;
		wxSlider* m_left_arm_side_slider;
		wxStaticText* m_staticText10;
		wxSlider* m_left_arm_front_slider;
		wxStaticText* m_staticText11;
		wxSlider* m_left_tibia_slider;
		wxStaticText* m_staticText19;
		wxSlider* m_left_thigh_side_slider;
		wxStaticText* m_staticText20;
		wxSlider* m_left_thigh_front_slider;
		wxStaticText* m_staticText21;
		wxSlider* m_middle_back_front_slider;
		wxStaticText* m_staticText22;
		wxSlider* m_lower_back_front_slider;
		wxStaticText* m_staticText161;
		wxSlider* m_right_forearm_slider;
		wxStaticText* m_staticText12;
		wxSlider* m_right_arm_side_slider;
		wxStaticText* m_staticText13;
		wxSlider* m_right_arm_front_slider;
		wxStaticText* m_staticText14;
		wxSlider* m_right_tibia_slider;
		wxStaticText* m_staticText15;
		wxSlider* m_right_thigh_side_slider;
		wxStaticText* m_staticText16;
		wxSlider* m_right_thigh_front_slider;
		wxStaticText* m_staticText17;
		wxSlider* m_middle_back_side_slider;
		wxStaticText* m_staticText18;
		wxSlider* m_lower_back_side_slider;
		wxStaticText* m_staticText151;
		wxButton* m_button1;
		wxTextCtrl* m_amountOfFramesText;
		wxButton* m_enableAnimationButton;
		wxButton* m_saveFrameButton;
		wxStaticText* m_staticText181;
		wxTextCtrl* m_selectedFrameText;
		wxCheckBox* m_repeatCheckBox;
		wxButton* m_startAnimationButton;
		wxButton* m_stopButton;
		wxButton* m_saveAnimationToText;
		wxButton* m_loadFromFile;
		wxButton* m_saveAnimationToFileButton;
		wxTimer m_animationTimer;

		// Virtual event handlers, overide them in your derived class
		virtual void m_panel2OnLeftDown( wxMouseEvent& event ) { event.Skip(); }
		virtual void m_panel2OnLeftUp( wxMouseEvent& event ) { event.Skip(); }
		virtual void m_panel2OnMotion( wxMouseEvent& event ) { event.Skip(); }
		virtual void m_panel2OnPaint( wxPaintEvent& event ) { event.Skip(); }
		virtual void m_panel2OnUpdateUI( wxUpdateUIEvent& event ) { event.Skip(); }
		virtual void onTimelineClick( wxMouseEvent& event ) { event.Skip(); }
		virtual void onTimelinePaint( wxPaintEvent& event ) { event.Skip(); }
		virtual void onTimelineUpdate( wxUpdateUIEvent& event ) { event.Skip(); }
		virtual void m_button1OnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void onEnableAnimationClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void onSaveFrameConfigurationClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void onStartAnimationButonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void onStopButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void onSaveToFileClicked( wxCommandEvent& event ) { event.Skip(); }
		virtual void onLoadFromFileAnimationButton( wxCommandEvent& event ) { event.Skip(); }
		virtual void onSaveAnimationToFileButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void onTimerTick( wxTimerEvent& event ) { event.Skip(); }


	public:

		MyFrame1( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 879,843 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~MyFrame1();

};

