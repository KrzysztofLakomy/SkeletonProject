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
	_bones.push_back(Line(Vec(-10, 5, 0), Vec(-20, 65, 0), "left thigh"));
	_bones.push_back(Line(Vec(10, 5, 0), Vec(20, 65, 0), "right thigh"));
	_bones.push_back(Line(Vec(-20, 65, 0), Vec(-25, 135, 0), "left tibia"));
	_bones.push_back(Line(Vec(20, 65, 0), Vec(25, 135, 0), "right tibia"));
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
		
		if (a.name() == "neck") {
			//ruch szyi przy pochyleniu do przodu middle back
			beg = mat_vec_multiply(translate(0, 50, 0), beg);
			beg = mat_vec_multiply(rotate_x(m_middle_back_front_slider->GetValue() * 0.10), beg);
			beg = mat_vec_multiply(translate(0, -50, 0), beg);

			en = mat_vec_multiply(translate(0, 50, 0), en);
			en = mat_vec_multiply(rotate_x(m_middle_back_front_slider->GetValue() * 0.10), en);
			en = mat_vec_multiply(translate(0, -50, 0), en);



			//ruch szyi przy middle back do boku
			beg = mat_vec_multiply(translate(0, 50, 0), beg);
			beg = mat_vec_multiply(rotate_z((m_middle_back_side_slider->GetValue() - 50.0) * 0.2), beg);
			beg = mat_vec_multiply(translate(0, -50, 0), beg);

			en = mat_vec_multiply(translate(0, 50, 0), en);
			en = mat_vec_multiply(rotate_z((m_middle_back_side_slider->GetValue() - 50.0) * 0.2), en);
			en = mat_vec_multiply(translate(0, -50, 0), en);


			//ruch szyja dolna czesc kregoslupa przod
			beg = mat_vec_multiply(rotate_x(m_lower_back_front_slider->GetValue() * 0.35), beg);

			en = mat_vec_multiply(rotate_x(m_lower_back_front_slider->GetValue() * 0.35), en);


			//ruch szyja dolna czesc kregoslupa boki
			beg = mat_vec_multiply(rotate_z((m_lower_back_side_slider->GetValue() - 50.0) * 0.5), beg);

			en = mat_vec_multiply(rotate_z((m_lower_back_side_slider->GetValue() - 50.0) * 0.5), en);
		}

		if (a.name() == "left shoulder") {
			//ruch lewego barku przy pochyleniu do przodu middle back
			beg = mat_vec_multiply(translate(0, 50, 0), beg);
			beg = mat_vec_multiply(rotate_x(m_middle_back_front_slider->GetValue() * 0.10), beg);
			beg = mat_vec_multiply(translate(0, -50, 0), beg);

			en = mat_vec_multiply(translate(0, 50, 0), en);
			en = mat_vec_multiply(rotate_x(m_middle_back_front_slider->GetValue() * 0.10), en);
			en = mat_vec_multiply(translate(0, -50, 0), en);



			//ruch lwey bark przy middle back do boku
			beg = mat_vec_multiply(translate(0, 50, 0), beg);
			beg = mat_vec_multiply(rotate_z((m_middle_back_side_slider->GetValue() - 50.0) * 0.2), beg);
			beg = mat_vec_multiply(translate(0, -50, 0), beg);

			en = mat_vec_multiply(translate(0, 50, 0), en);
			en = mat_vec_multiply(rotate_z((m_middle_back_side_slider->GetValue() - 50.0) * 0.2), en);
			en = mat_vec_multiply(translate(0, -50, 0), en);


			//ruch lewy bark dolna czesc kregoslupa przod
			beg = mat_vec_multiply(rotate_x(m_lower_back_front_slider->GetValue() * 0.35), beg);

			en = mat_vec_multiply(rotate_x(m_lower_back_front_slider->GetValue() * 0.35), en);


			//ruch lewy bark dolna czesc kregoslupa boki
			beg = mat_vec_multiply(rotate_z((m_lower_back_side_slider->GetValue() - 50.0) * 0.5), beg);

			en = mat_vec_multiply(rotate_z((m_lower_back_side_slider->GetValue() - 50.0) * 0.5), en);
			
		}

		if (a.name() == "right shoulder") {
			//ruch lewego barku przy pochyleniu do przodu middle back
			beg = mat_vec_multiply(translate(0, 50, 0), beg);
			beg = mat_vec_multiply(rotate_x(m_middle_back_front_slider->GetValue() * 0.10), beg);
			beg = mat_vec_multiply(translate(0, -50, 0), beg);

			en = mat_vec_multiply(translate(0, 50, 0), en);
			en = mat_vec_multiply(rotate_x(m_middle_back_front_slider->GetValue() * 0.10), en);
			en = mat_vec_multiply(translate(0, -50, 0), en);



			//ruch prawy bark przy middle back do boku
			beg = mat_vec_multiply(translate(0, 50, 0), beg);
			beg = mat_vec_multiply(rotate_z((m_middle_back_side_slider->GetValue() - 50.0) * 0.2), beg);
			beg = mat_vec_multiply(translate(0, -50, 0), beg);

			en = mat_vec_multiply(translate(0, 50, 0), en);
			en = mat_vec_multiply(rotate_z((m_middle_back_side_slider->GetValue() - 50.0) * 0.2), en);
			en = mat_vec_multiply(translate(0, -50, 0), en);


			//ruch prawy bark dolna czesc kregoslupa przod
			beg = mat_vec_multiply(rotate_x(m_lower_back_front_slider->GetValue() * 0.35), beg);

			en = mat_vec_multiply(rotate_x(m_lower_back_front_slider->GetValue() * 0.35), en);


			//ruch prawy bark dolna czesc kregoslupa boki
			beg = mat_vec_multiply(rotate_z((m_lower_back_side_slider->GetValue() - 50.0) * 0.5), beg);

			en = mat_vec_multiply(rotate_z((m_lower_back_side_slider->GetValue() - 50.0) * 0.5), en);
		}




		if (a.name() == "left forearm") {
			//ruch lewa reka w ³okciu
			beg = mat_vec_multiply(translate(60, 100, 0), beg);
			beg = mat_vec_multiply(rotate_z(m_left_forearm_slider->GetValue() * 0.9),beg);
			beg = mat_vec_multiply(translate(-60, -100, 0), beg);

			
			//do lewej reki ca³ej w bok
			beg = mat_vec_multiply(translate(10, 100, 0), beg);
			beg = mat_vec_multiply(rotate_z((m_left_arm_side_slider->GetValue() - 50.0) * 1.8), beg);
			beg = mat_vec_multiply(translate(-10, -100, 0), beg);

			en = mat_vec_multiply(translate(10, 100, 0), en);
			en = mat_vec_multiply(rotate_z((m_left_arm_side_slider->GetValue() - 50.0) * 1.8), en);
			en = mat_vec_multiply(translate(-10, -100, 0), en);


			//do lewej rek calej do przodu
			beg = mat_vec_multiply(translate(10, 100, 0), beg);
			beg = mat_vec_multiply(rotate_y((m_left_arm_front_slider->GetValue() * 0.9)), beg);
			beg = mat_vec_multiply(translate(-10, -100, 0), beg);

			en = mat_vec_multiply(translate(10, 100, 0), en);
			en = mat_vec_multiply(rotate_y((m_left_arm_front_slider->GetValue() * 0.9)), en);
			en = mat_vec_multiply(translate(-10, -100, 0), en);




			//ruch lewego przedramienia przy middle back do przodu
			beg = mat_vec_multiply(translate(0, 50, 0), beg);
			beg = mat_vec_multiply(rotate_x(m_middle_back_front_slider->GetValue() * 0.10), beg);
			beg = mat_vec_multiply(translate(0, -50, 0), beg);

			en = mat_vec_multiply(translate(0, 50, 0), en);
			en = mat_vec_multiply(rotate_x(m_middle_back_front_slider->GetValue() * 0.10), en);
			en = mat_vec_multiply(translate(0, -50, 0), en);



			//ruch lewe przedramie przy middle back do boku
			beg = mat_vec_multiply(translate(0, 50, 0), beg);
			beg = mat_vec_multiply(rotate_z((m_middle_back_side_slider->GetValue() - 50.0) * 0.2), beg);
			beg = mat_vec_multiply(translate(0, -50, 0), beg);

			en = mat_vec_multiply(translate(0, 50, 0), en);
			en = mat_vec_multiply(rotate_z((m_middle_back_side_slider->GetValue() - 50.0) * 0.2), en);
			en = mat_vec_multiply(translate(0, -50, 0), en);



			//ruch lewe przedramie dolna czesc kregoslupa przod
			beg = mat_vec_multiply(rotate_x(m_lower_back_front_slider->GetValue() * 0.35), beg);

			en = mat_vec_multiply(rotate_x(m_lower_back_front_slider->GetValue() * 0.35), en);


			//ruch lewe przedramie dolna czesc kregoslupa boki
			beg = mat_vec_multiply(rotate_z((m_lower_back_side_slider->GetValue() - 50.0) * 0.5), beg);

			en = mat_vec_multiply(rotate_z((m_lower_back_side_slider->GetValue() - 50.0) * 0.5), en);
		}

		if (a.name() == "left arm") {

			//do lewej reki w bok
			beg = mat_vec_multiply(translate(10, 100, 0), beg);
			beg = mat_vec_multiply(rotate_z((m_left_arm_side_slider->GetValue() - 50.0) * 1.8), beg);
			beg = mat_vec_multiply(translate(-10, -100, 0), beg);


			//do lewej reki do przodu
			beg = mat_vec_multiply(translate(10, 100, 0), beg);
			beg = mat_vec_multiply(rotate_y(m_left_arm_front_slider->GetValue() * 0.9), beg);
			beg = mat_vec_multiply(translate(-10, -100, 0), beg);



			//ruch lewej reki przy pochyleniu do przodu middle back
			beg = mat_vec_multiply(translate(0, 50, 0), beg);
			beg = mat_vec_multiply(rotate_x(m_middle_back_front_slider->GetValue() * 0.10), beg);
			beg = mat_vec_multiply(translate(0, -50, 0), beg);

			en = mat_vec_multiply(translate(0, 50, 0), en);
			en = mat_vec_multiply(rotate_x(m_middle_back_front_slider->GetValue() * 0.10), en);
			en = mat_vec_multiply(translate(0, -50, 0), en);



			//ruch lewa reka przy middle back do boku
			beg = mat_vec_multiply(translate(0, 50, 0), beg);
			beg = mat_vec_multiply(rotate_z((m_middle_back_side_slider->GetValue() - 50.0) * 0.2), beg);
			beg = mat_vec_multiply(translate(0, -50, 0), beg);

			en = mat_vec_multiply(translate(0, 50, 0), en);
			en = mat_vec_multiply(rotate_z((m_middle_back_side_slider->GetValue() - 50.0) * 0.2), en);
			en = mat_vec_multiply(translate(0, -50, 0), en);



			//ruch lewa reka dolna czesc kregoslupa przod
			beg = mat_vec_multiply(rotate_x(m_lower_back_front_slider->GetValue() * 0.35), beg);

			en = mat_vec_multiply(rotate_x(m_lower_back_front_slider->GetValue() * 0.35), en);


			//ruch lewa reka dolna czesc kregoslupa boki
			beg = mat_vec_multiply(rotate_z((m_lower_back_side_slider->GetValue() - 50.0) * 0.5), beg);

			en = mat_vec_multiply(rotate_z((m_lower_back_side_slider->GetValue() - 50.0) * 0.5), en);
		}

		if (a.name() == "right forearm") {

			//ruch prawa reka w ³okciu
			en = mat_vec_multiply(translate(-60, 100, 0), en);
			en = mat_vec_multiply(rotate_z(-m_right_forearm_slider->GetValue() * 0.9), en);
			en = mat_vec_multiply(translate(60, -100, 0), en);


			//do prawej reki ca³ej w bok
			beg = mat_vec_multiply(translate(-10, 100, 0), beg);
			beg = mat_vec_multiply(rotate_z((m_right_arm_side_slider->GetValue() - 50.0) * 1.8), beg);
			beg = mat_vec_multiply(translate(10, -100, 0), beg);

			en = mat_vec_multiply(translate(-10, 100, 0), en);
			en = mat_vec_multiply(rotate_z((m_right_arm_side_slider->GetValue() - 50.0) * 1.8), en);
			en = mat_vec_multiply(translate(10, -100, 0), en);


			//do prawej rek calej do przodu
			beg = mat_vec_multiply(translate(-10, 100, 0), beg);
			beg = mat_vec_multiply(rotate_y((m_right_arm_front_slider->GetValue() * 0.9)), beg);
			beg = mat_vec_multiply(translate(10, -100, 0), beg);

			en = mat_vec_multiply(translate(-10, 100, 0), en);
			en = mat_vec_multiply(rotate_y((m_right_arm_front_slider->GetValue() * 0.9)), en);
			en = mat_vec_multiply(translate(10, -100, 0), en);



			//ruch prawego przedramienia przy pochyleniu do przodu middle back
			beg = mat_vec_multiply(translate(0, 50, 0), beg);
			beg = mat_vec_multiply(rotate_x(m_middle_back_front_slider->GetValue() * 0.10), beg);
			beg = mat_vec_multiply(translate(0, -50, 0), beg);

			en = mat_vec_multiply(translate(0, 50, 0), en);
			en = mat_vec_multiply(rotate_x(m_middle_back_front_slider->GetValue() * 0.10), en);
			en = mat_vec_multiply(translate(0, -50, 0), en);


			
			//ruch prawe przedramie przy middle back do boku
			beg = mat_vec_multiply(translate(0, 50, 0), beg);
			beg = mat_vec_multiply(rotate_z((m_middle_back_side_slider->GetValue() - 50.0) * 0.2), beg);
			beg = mat_vec_multiply(translate(0, -50, 0), beg);

			en = mat_vec_multiply(translate(0, 50, 0), en);
			en = mat_vec_multiply(rotate_z((m_middle_back_side_slider->GetValue() - 50.0) * 0.2), en);
			en = mat_vec_multiply(translate(0, -50, 0), en);



			//ruch prawe przedramie dolna czesc kregoslupa przod
			beg = mat_vec_multiply(rotate_x(m_lower_back_front_slider->GetValue() * 0.35), beg);

			en = mat_vec_multiply(rotate_x(m_lower_back_front_slider->GetValue() * 0.35), en);


			//ruch prawe przedramie dolna czesc kregoslupa boki
			beg = mat_vec_multiply(rotate_z((m_lower_back_side_slider->GetValue() - 50.0) * 0.5), beg);

			en = mat_vec_multiply(rotate_z((m_lower_back_side_slider->GetValue() - 50.0) * 0.5), en);

		}

		if (a.name() == "right arm") {

			//do prawej reki w bok
			en = mat_vec_multiply(translate(-10, 100, 0), en);
			en = mat_vec_multiply(rotate_z((m_right_arm_side_slider->GetValue() - 50.0) * 1.8), en);
			en = mat_vec_multiply(translate(10, -100, 0), en);


			//do prawej reki do przodu
			en = mat_vec_multiply(translate(-10, 100, 0), en);
			en = mat_vec_multiply(rotate_y(m_right_arm_front_slider->GetValue() * 0.9), en);
			en = mat_vec_multiply(translate(10, -100, 0), en);



			//ruch prawej reki przy pochyleniu do przodu middle back
			beg = mat_vec_multiply(translate(0, 50, 0), beg);
			beg = mat_vec_multiply(rotate_x(m_middle_back_front_slider->GetValue() * 0.10), beg);
			beg = mat_vec_multiply(translate(0, -50, 0), beg);

			en = mat_vec_multiply(translate(0, 50, 0), en);
			en = mat_vec_multiply(rotate_x(m_middle_back_front_slider->GetValue() * 0.10), en);
			en = mat_vec_multiply(translate(0, -50, 0), en);



			//ruch prawa reka przy middle back do boku
			beg = mat_vec_multiply(translate(0, 50, 0), beg);
			beg = mat_vec_multiply(rotate_z((m_middle_back_side_slider->GetValue() - 50.0) * 0.2), beg);
			beg = mat_vec_multiply(translate(0, -50, 0), beg);

			en = mat_vec_multiply(translate(0, 50, 0), en);
			en = mat_vec_multiply(rotate_z((m_middle_back_side_slider->GetValue() - 50.0) * 0.2), en);
			en = mat_vec_multiply(translate(0, -50, 0), en);



			//ruch prawa reka dolna czesc kregoslupa przod
			beg = mat_vec_multiply(rotate_x(m_lower_back_front_slider->GetValue() * 0.35), beg);

			en = mat_vec_multiply(rotate_x(m_lower_back_front_slider->GetValue() * 0.35), en);


			//ruch prawa reka dolna czesc kregoslupa boki
			beg = mat_vec_multiply(rotate_z((m_lower_back_side_slider->GetValue() - 50.0) * 0.5), beg);

			en = mat_vec_multiply(rotate_z((m_lower_back_side_slider->GetValue() - 50.0) * 0.5), en);
		}

		if (a.name() == "left tibia") {

			//ruch lewy piszczel
			en = mat_vec_multiply(translate(20, -65, 0), en);
			en = mat_vec_multiply(rotate_x(m_left_tibia_slider->GetValue() * 0.9), en);
			en = mat_vec_multiply(translate(-20, 65, 0), en);


			//ruch lewego piszczela przy lewym udzie w bok
			en = mat_vec_multiply(translate(10, -5, 0), en);
			en = mat_vec_multiply(rotate_z(m_left_thigh_side_slider->GetValue() * 0.6), en);
			en = mat_vec_multiply(translate(-10, 5, 0), en);

			beg = mat_vec_multiply(translate(10, -5, 0), beg);
			beg = mat_vec_multiply(rotate_z(m_left_thigh_side_slider->GetValue() * 0.6), beg);
			beg = mat_vec_multiply(translate(-10, 5, 0), beg);


			//ruch lewego piszczela przy lewym udzie przod/tyl
			beg = mat_vec_multiply(translate(10, -5, 0), beg);
			beg = mat_vec_multiply(rotate_x((m_left_thigh_front_slider->GetValue() - 50.0) * 0.9), beg);
			beg = mat_vec_multiply(translate(-10, 5, 0), beg);

			en = mat_vec_multiply(translate(10, -5, 0), en);
			en = mat_vec_multiply(rotate_x((m_left_thigh_front_slider->GetValue() - 50.0) * 0.9), en);
			en = mat_vec_multiply(translate(-10, 5, 0), en);

		}

		if (a.name() == "left thigh") {

			//ruch lewe udo bok
			en = mat_vec_multiply(translate(10, -5, 0), en);
			en = mat_vec_multiply(rotate_z(m_left_thigh_side_slider->GetValue() * 0.6), en);
			en = mat_vec_multiply(translate(-10, 5, 0), en);


			//ruch lewe udo przod tyl
			en = mat_vec_multiply(translate(10, -5, 0), en);
			en = mat_vec_multiply(rotate_x((m_left_thigh_front_slider->GetValue() -50.0)* 0.9), en);
			en = mat_vec_multiply(translate(-10, 5, 0), en);
		}

		if (a.name() == "right tibia") {
			//ruch prawy piszczel
			en = mat_vec_multiply(translate(-20, -65, 0), en);
			en = mat_vec_multiply(rotate_x(m_right_tibia_slider->GetValue() * 0.9), en);
			en = mat_vec_multiply(translate(20, 65, 0), en);


			//ruch prawy piszczel przy prawym udzie w bok
			en = mat_vec_multiply(translate(-10, -5, 0), en);
			en = mat_vec_multiply(rotate_z(-m_right_thigh_side_slider->GetValue() * 0.6), en);
			en = mat_vec_multiply(translate(10, 5, 0), en);

			beg = mat_vec_multiply(translate(-10, -5, 0), beg);
			beg = mat_vec_multiply(rotate_z(-m_right_thigh_side_slider->GetValue() * 0.6), beg);
			beg = mat_vec_multiply(translate(10, 5, 0), beg);


			//ruch prawy piszczel przy prawym udzie przod/tyl
			en = mat_vec_multiply(translate(-10, -5, 0), en);
			en = mat_vec_multiply(rotate_x((m_right_thigh_front_slider->GetValue() -50.0)* 0.9), en);
			en = mat_vec_multiply(translate(10, 5, 0), en);

			beg = mat_vec_multiply(translate(-10, -5, 0), beg);
			beg = mat_vec_multiply(rotate_x((m_right_thigh_front_slider->GetValue() - 50.0) * 0.9), beg);
			beg = mat_vec_multiply(translate(10, 5, 0), beg);

			
		}

		if (a.name() == "right thigh") {
			//ruch prawe udo bok
			en = mat_vec_multiply(translate(-10, -5, 0), en);
			en = mat_vec_multiply(rotate_z(-m_right_thigh_side_slider->GetValue() * 0.6), en);
			en = mat_vec_multiply(translate(10, 5, 0), en);

			//ruch prawe udo przod/tyl
			en = mat_vec_multiply(translate(-10, -5, 0), en);
			en = mat_vec_multiply(rotate_x((m_right_thigh_front_slider->GetValue() -50.0)* 0.9), en);
			en = mat_vec_multiply(translate(10, 5, 0), en);
		}

		if (a.name() == "upper backbone") {
			//ruch gornej czesci kregoslupa w przod
			beg = mat_vec_multiply(translate(0, 50, 0), beg);
			beg = mat_vec_multiply(rotate_x(m_middle_back_front_slider->GetValue() * 0.10), beg);
			beg = mat_vec_multiply(translate(0, -50, 0), beg);


			//ruch gornej czesci kregoslupa w bok
			beg = mat_vec_multiply(translate(0, 50, 0), beg);
			beg = mat_vec_multiply(rotate_z((m_middle_back_side_slider->GetValue()-50.0) * 0.2), beg);
			beg = mat_vec_multiply(translate(0, -50, 0), beg);


			//ruch gorna czesc kregoslupa dolna czesc kregoslupa przod
			beg = mat_vec_multiply(rotate_x(m_lower_back_front_slider->GetValue() * 0.35), beg);

			en = mat_vec_multiply(rotate_x(m_lower_back_front_slider->GetValue() * 0.35), en);


			//ruch gorna czesc kregoslupa dolna czesc kregoslupa boki
			beg = mat_vec_multiply(rotate_z((m_lower_back_side_slider->GetValue() - 50.0) * 0.5), beg);

			en = mat_vec_multiply(rotate_z((m_lower_back_side_slider->GetValue() - 50.0) * 0.5), en);
		}

		if (a.name() == "lower backbone") {
			//ruch dolnej czesci kregoslupa przod
			beg = mat_vec_multiply(rotate_x(m_lower_back_front_slider->GetValue() * 0.35), beg);

			//ruch dolnej czesci kregoslupa boki
			beg = mat_vec_multiply(rotate_z((m_lower_back_side_slider->GetValue() - 50.0) * 0.5), beg);
		}


		beg = mat_vec_multiply(rot, beg);
		en = mat_vec_multiply(rot, en);

		beg = mat_vec_multiply(trans, beg);
		en = mat_vec_multiply(trans, en);

		dc.DrawLine(beg.X(), beg.Y(), en.X(), en.Y());
	}
}