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

	//do obracania szkieletem
	Matrix rot_y = rotate_y(alpha);
	Matrix rot_x = rotate_x(beta);
	Matrix rot = mat_mat_multiply(rot_x, rot_y);
	
	for (auto& a : _bones) {
		Vec beg = a.begin();
		Vec en = a.end();
		if (a.name() == "left forearm") {

			//ruch lewa reka w ³okciu
			beg = mat_vec_multiply(translate(60, 100, 0), beg);
			beg = mat_vec_multiply(rotate_z(m_slider4->GetValue() * 0.9),beg);
			beg = mat_vec_multiply(translate(-60, -100, 0), beg);

			
			//do lewej reki ca³ej w bok
			beg = mat_vec_multiply(translate(10, 100, 0), beg);
			beg = mat_vec_multiply(rotate_z((m_slider7->GetValue() - 50.0) * 1.8), beg);
			beg = mat_vec_multiply(translate(-10, -100, 0), beg);

			en = mat_vec_multiply(translate(10, 100, 0), en);
			en = mat_vec_multiply(rotate_z((m_slider7->GetValue() - 50.0) * 1.8), en);
			en = mat_vec_multiply(translate(-10, -100, 0), en);


			//do lewej rek calej do przodu
			beg = mat_vec_multiply(translate(10, 100, 0), beg);
			beg = mat_vec_multiply(rotate_y((m_slider8->GetValue() * 0.9)), beg);
			beg = mat_vec_multiply(translate(-10, -100, 0), beg);

			en = mat_vec_multiply(translate(10, 100, 0), en);
			en = mat_vec_multiply(rotate_y((m_slider8->GetValue() * 0.9)), en);
			en = mat_vec_multiply(translate(-10, -100, 0), en);
		}

		if (a.name() == "left arm") {

			//do lewej reki w bok
			beg = mat_vec_multiply(translate(10, 100, 0), beg);
			beg = mat_vec_multiply(rotate_z((m_slider7->GetValue() - 50.0) * 1.8), beg);
			beg = mat_vec_multiply(translate(-10, -100, 0), beg);


			//do lewej reki do przodu
			beg = mat_vec_multiply(translate(10, 100, 0), beg);
			beg = mat_vec_multiply(rotate_y(m_slider8->GetValue() * 0.9), beg);
			beg = mat_vec_multiply(translate(-10, -100, 0), beg);
		}

		if (a.name() == "right forearm") {

			//ruch prawa reka w ³okciu
			en = mat_vec_multiply(translate(-60, 100, 0), en);
			en = mat_vec_multiply(rotate_z(-m_slider5->GetValue() * 0.9), en);
			en = mat_vec_multiply(translate(60, -100, 0), en);


			//do prawej reki ca³ej w bok
			beg = mat_vec_multiply(translate(-10, 100, 0), beg);
			beg = mat_vec_multiply(rotate_z((m_slider9->GetValue() - 50.0) * 1.8), beg);
			beg = mat_vec_multiply(translate(10, -100, 0), beg);

			en = mat_vec_multiply(translate(-10, 100, 0), en);
			en = mat_vec_multiply(rotate_z((m_slider9->GetValue() - 50.0) * 1.8), en);
			en = mat_vec_multiply(translate(10, -100, 0), en);


			//do prawej rek calej do przodu
			beg = mat_vec_multiply(translate(-10, 100, 0), beg);
			beg = mat_vec_multiply(rotate_y((m_slider10->GetValue() * 0.9)), beg);
			beg = mat_vec_multiply(translate(10, -100, 0), beg);

			en = mat_vec_multiply(translate(-10, 100, 0), en);
			en = mat_vec_multiply(rotate_y((m_slider10->GetValue() * 0.9)), en);
			en = mat_vec_multiply(translate(10, -100, 0), en);

		}

		if (a.name() == "right arm") {

			//do prawej reki w bok
			en = mat_vec_multiply(translate(-10, 100, 0), en);
			en = mat_vec_multiply(rotate_z((m_slider9->GetValue() - 50.0) * 1.8), en);
			en = mat_vec_multiply(translate(10, -100, 0), en);



			//do prawej reki do przodu
			en = mat_vec_multiply(translate(-10, 100, 0), en);
			en = mat_vec_multiply(rotate_y(m_slider10->GetValue() * 0.9), en);
			en = mat_vec_multiply(translate(10, -100, 0), en);
		}



		beg = mat_vec_multiply(rot, beg);
		en = mat_vec_multiply(rot, en);

		beg = mat_vec_multiply(trans, beg);
		en = mat_vec_multiply(trans, en);

		dc.DrawLine(beg.X(), beg.Y(), en.X(), en.Y());
	}
}