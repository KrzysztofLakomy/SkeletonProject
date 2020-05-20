#include "GUIMyFrame1.h"

GUIMyFrame1::GUIMyFrame1( wxWindow* parent )
:
MyFrame1( parent )
{
	_bones.push_back(Line(Vec(-100,-102,0), Vec(-60,-100,0), "left forearm"));
	_bones.push_back(Line(Vec(-60, -100, 0), Vec(-10, -100, 0), "left arm"));
	_bones.push_back(Line(Vec(-10, -100, 0), Vec(0, -100, 0), "left shoulder"));
	_bones.push_back(Line(Vec(0, -100, 0), Vec(0, -110, 0), "neck"));
	_bones.push_back(Line(Vec(0, -100, 0), Vec(10, -100, 0), "right shoulder"));
	_bones.push_back(Line(Vec(10, -100, 0), Vec(60, -100, 0), "right arm"));
	_bones.push_back(Line(Vec(60, -100, 0), Vec(100, -102, 0), "right forearm"));
	_bones.push_back(Line(Vec(0, -100, 0), Vec(0, -50, 0), "upper backbone"));
	_bones.push_back(Line(Vec(0, -50, 0), Vec(0, 0, 0), "lower backbone"));
	_bones.push_back(Line(Vec(0, 0, 0), Vec(-10, 5, 0), "left hip"));
	_bones.push_back(Line(Vec(0, 0, 0), Vec(10, 5, 0), "right hip"));
	_bones.push_back(Line(Vec(-10, 5, 0), Vec(-40, 65, 0), "left thigh"));
	_bones.push_back(Line(Vec(10, 5, 0), Vec(40, 65, 0), "right thigh"));
	_bones.push_back(Line(Vec(-40, 65, 0), Vec(-80, 125, 0), "left tibia"));
	_bones.push_back(Line(Vec(40, 65, 0), Vec(80, 125, 0), "right tibia"));
}

void GUIMyFrame1::m_panel2OnLeftDown( wxMouseEvent& event )
{
start_point = event.GetPosition();
is_panel_clicked = true;
m_panel2->Refresh();
}

void GUIMyFrame1::m_panel2OnLeftUp( wxMouseEvent& event )
{
start_point = wxPoint(0, 0);
is_panel_clicked = false;
}

void GUIMyFrame1::m_panel2OnMotion( wxMouseEvent& event )
{
if (event.LeftIsDown()&& is_panel_clicked) {
alpha = event.GetPosition().x - start_point.x;
beta = start_point.y - event.GetPosition().y;
}
m_panel2->Refresh();
}

void GUIMyFrame1::m_panel2OnPaint( wxPaintEvent& event )
{
wxClientDC dcClient(m_panel2);
m_panel2->Refresh();
m_panel2->Update();
draw(dcClient);
}

void GUIMyFrame1::m_panel2OnUpdateUI( wxUpdateUIEvent& event )
{
wxClientDC dcClient(m_panel2);
draw(dcClient);
}

void GUIMyFrame1::m_slider4OnScroll( wxScrollEvent& event )
{
// TODO: Implement m_slider4OnScroll
}


void GUIMyFrame1::draw(wxClientDC& dcClient) 
{
	wxBufferedDC dc(&dcClient);
	PrepareDC(dc);
	dc.Clear();
	dc.SetBrush(wxBrush(*wxWHITE_BRUSH));

	int w, h;
	m_panel2->GetSize(&w, &h);

	dc.SetPen(wxPen(wxColor(0,0,0),3));

	
	Matrix trans = translate(w / 2.0, h / 2.0, 0);

	///translacja do ruszania ramieniem dla punktu w lokciu
	Matrix trans_left_arm_side = translate(50.0 - (50.0 * cos((-1.0 * (m_slider7->GetValue() - 50.0) * 1.8) * 3.1415 / 180.0)), 
									  50.0 * sin((-1.0 * (m_slider7->GetValue() - 50.0) * 1.8) * 3.1415 / 180.0), 0);

	//translacja do ruszania ramieniem dla punktu w koncowce przedramienia
	Matrix trans_left_arm_forearm_side = translate(90.0 - (90.0 * cos((-1.0 * (m_slider7->GetValue() - 50.0) * 1.8) * 3.1415 / 180.0)),
											  90.0 * sin((-1.0 * (m_slider7->GetValue() - 50.0) * 1.8) * 3.1415 / 180.0), 0);
	
	Matrix rot_y = rotate_y(alpha);
	Matrix rot_x = rotate_x(beta);
	Matrix rot = mat_mat_multiply(rot_x, rot_y);
	//
	for (auto& a : _bones) {
		Vec beg = a.begin();
		Vec en = a.end();
		if (a.name() == "left forearm") {

			//translacja zgiecie lewej reki w lokciu
			Matrix trans_left_forearm = translate(40.05 * cos((-1.0 * (m_slider7->GetValue() - 50.0) * 1.8) * 3.1415 / 180.0) - (40.05 * cos((-1.0 * m_slider4->GetValue() * 0.9 - (m_slider7->GetValue() - 50.0) * 1.8) * 3.1415 / 180.0)),
				(40.05*sin((1.0*(m_slider7->GetValue() - 50.0) * 1.8) * 3.1415 / 180.0) + (40.05 * sin((-1.0 * m_slider4->GetValue() * 0.9 - (m_slider7->GetValue() - 50.0) * 1.8) * 3.1415 / 180.0))), 0);

			beg = mat_vec_multiply(trans_left_forearm, beg);

			beg = mat_vec_multiply(trans_left_arm_forearm_side, beg);
			en = mat_vec_multiply(trans_left_arm_side, en);
			
		}

		if (a.name() == "left arm") {
			beg = mat_vec_multiply(trans_left_arm_side, beg);
			
		}

		beg = mat_vec_multiply(rot, beg);
		en = mat_vec_multiply(rot, en);

		beg = mat_vec_multiply(trans, beg);
		en = mat_vec_multiply(trans, en);

		dc.DrawLine(beg.X(), beg.Y(), en.X(), en.Y());
	}
}