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
		wxSlider* m_slider4;
		wxStaticText* m_staticText9;
		wxSlider* m_slider7;
		wxStaticText* m_staticText10;
		wxSlider* m_slider8;
		wxStaticText* m_staticText11;
		wxSlider* m_slider15;
		wxStaticText* m_staticText19;
		wxSlider* m_slider16;
		wxStaticText* m_staticText20;
		wxSlider* m_slider17;
		wxStaticText* m_staticText21;
		wxSlider* m_slider18;
		wxStaticText* m_staticText22;
		wxSlider* m_slider5;
		wxStaticText* m_staticText12;
		wxSlider* m_slider9;
		wxStaticText* m_staticText13;
		wxSlider* m_slider10;
		wxStaticText* m_staticText14;
		wxSlider* m_slider11;
		wxStaticText* m_staticText15;
		wxSlider* m_slider12;
		wxStaticText* m_staticText16;
		wxSlider* m_slider13;
		wxStaticText* m_staticText17;
		wxSlider* m_slider14;
		wxStaticText* m_staticText18;

		// Virtual event handlers, overide them in your derived class
		virtual void m_panel2OnLeftDown( wxMouseEvent& event ) { event.Skip(); }
		virtual void m_panel2OnLeftUp( wxMouseEvent& event ) { event.Skip(); }
		virtual void m_panel2OnMotion( wxMouseEvent& event ) { event.Skip(); }
		virtual void m_panel2OnPaint( wxPaintEvent& event ) { event.Skip(); }
		virtual void m_panel2OnUpdateUI( wxUpdateUIEvent& event ) { event.Skip(); }
		virtual void m_slider4OnScroll( wxScrollEvent& event ) { event.Skip(); }


	public:

		MyFrame1( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 887,574 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~MyFrame1();

};

