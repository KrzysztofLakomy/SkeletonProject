#include "GUIMyFrame1.h"

GUIMyFrame1::GUIMyFrame1(wxWindow* parent)
	:
	MyFrame1(parent)
{
	_bones.push_back(Line(Vec(-100, -102, 0), Vec(-60, -100, 0), "left forearm"));
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

	_joints.push_back(Circle(Vec(-60, -100, 0), "left elbow"));
	_joints.push_back(Circle(Vec(-10, -100, 0), "left shoulder"));
	_joints.push_back(Circle(Vec(0, -100, 0), "neck"));
	_joints.push_back(Circle(Vec(10, -100, 0), "right shoulder"));
	_joints.push_back(Circle(Vec(60, -100, 0), "right elbow"));
	_joints.push_back(Circle(Vec(0, -50, 0), "upper back"));
	_joints.push_back(Circle(Vec(0, 0, 0), "lower back"));
	_joints.push_back(Circle(Vec(-10, 5, 0), "left hip"));
	_joints.push_back(Circle(Vec(10, 5, 0), "right hip"));
	_joints.push_back(Circle(Vec(-20, 65, 0), "left knee"));
	_joints.push_back(Circle(Vec(20, 65, 0), "right knee"));


	sliders.push_back(m_left_forearm_slider);
	sliders.push_back(m_right_forearm_slider);
	sliders.push_back(m_left_arm_side_slider);
	sliders.push_back(m_right_arm_side_slider);
	sliders.push_back(m_left_arm_front_slider);
	sliders.push_back(m_right_arm_front_slider);
	sliders.push_back(m_left_tibia_slider);
	sliders.push_back(m_right_tibia_slider);
	sliders.push_back(m_left_thigh_side_slider);
	sliders.push_back(m_right_thigh_side_slider);
	sliders.push_back(m_left_thigh_front_slider);
	sliders.push_back(m_right_thigh_front_slider);
	sliders.push_back(m_middle_back_front_slider);
	sliders.push_back(m_middle_back_side_slider);
	sliders.push_back(m_lower_back_front_slider);
	sliders.push_back(m_lower_back_side_slider);

	if (m_pLogFile == NULL)
	{
		m_pLogFile = fopen("log.txt", "w+");
		delete wxLog::SetActiveTarget(new wxLogStderr(m_pLogFile));
	}
}

void GUIMyFrame1::m_panel2OnLeftDown(wxMouseEvent& event)
{
	start_point = event.GetPosition();
	is_panel_clicked = true;
	m_panel2->Refresh();
}

void GUIMyFrame1::m_panel2OnLeftUp(wxMouseEvent& event)
{
	start_point = wxPoint(0, 0);
	is_panel_clicked = false;
}

void GUIMyFrame1::m_panel2OnMotion(wxMouseEvent& event)
{
	if (event.LeftIsDown() && is_panel_clicked) {
		alpha = static_cast<double>(event.GetPosition().x) - static_cast<double>(start_point.x);
		beta = static_cast<double>(start_point.y) - static_cast<double>(event.GetPosition().y);
	}
	m_panel2->Refresh();
}

void GUIMyFrame1::m_panel2OnPaint(wxPaintEvent& event)
{
	wxClientDC dcClient(m_panel2);
	m_panel2->Refresh();
	m_panel2->Update();
	draw(dcClient);
}

void GUIMyFrame1::m_panel2OnUpdateUI(wxUpdateUIEvent& event)
{
	wxClientDC dcClient(m_panel2);
	draw(dcClient);
}

void GUIMyFrame1::onTimelineClick(wxMouseEvent& event)
{
	wxPoint clickPoint = event.GetPosition();
	sort(framesConfig.begin(), framesConfig.end());
	int width, height;
	m_timeline_panel->GetSize(&width, &height);
	if (is_enableAnimation_clicked) {
		for (int i = 0; i < linesPosition.size(); i++) {
			if (clickPoint.x >= 0 && clickPoint.x < linesPosition[0].x) {

				configurableFrames.push_back(0);
				selectedFrame = 0;
				m_selectedFrameText->SetValue(wxString::Format(wxT("%i"), 1));
				int index = myFind(framesConfig, 0);
				if (index != -1) {
					setSlidersPosition(framesConfig[index].second);
				}
				else {
					reset();
				}
			}
			else if (clickPoint.x < linesPosition[i].x && clickPoint.x >= linesPosition[i - 1].x) {
				configurableFrames.push_back(i);
				m_selectedFrameText->SetLabelText(wxString::Format(wxT("%i"), i + 1));
				selectedFrame = i;
				int index = myFind(framesConfig, i);
				if (index != -1) {
					setSlidersPosition(framesConfig[index].second);
				}
				else {
					reset();
				}
			}
		}
	}
}

void GUIMyFrame1::onTimelinePaint(wxPaintEvent& event)
{
	wxClientDC dcClientTimeline(m_timeline_panel);
	m_timeline_panel->Refresh();
	m_timeline_panel->Update();
	drawForAnimation(dcClientTimeline);

}

void GUIMyFrame1::onTimelineUpdate(wxUpdateUIEvent& event)
{
	wxClientDC dcClientTimeline(m_timeline_panel);
	drawForAnimation(dcClientTimeline);
}

void GUIMyFrame1::m_button1OnButtonClick(wxCommandEvent& event)
{

	reset();
}

void GUIMyFrame1::onEnableAnimationClicked(wxCommandEvent& event)
{
	is_enableAnimation_clicked = !is_enableAnimation_clicked;
	animationVector.clear();
	if (!is_enableAnimation_clicked)
		m_enableAnimationButton->SetLabelText("Enable Animation");
	else
		m_enableAnimationButton->SetLabelText("Disable Animation");

}

void GUIMyFrame1::onSaveFrameConfigurationClicked(wxCommandEvent& event)
{
	saveSliders();
}

void GUIMyFrame1::onStartAnimationButonClick(wxCommandEvent& event)
{
	if (myFind(framesConfig, 0) == -1) {
		reset();
		selectedFrame = 0;
		saveSliders();
	}
	is_startAnimation_clicked = !is_startAnimation_clicked;
	sort(framesConfig.begin(), framesConfig.end());
	selectedFrame = 0;
	std::vector<int> howToChange;

	int a = 0;
	int b = 0;
	for (int i = 0; i < framesConfig.size(); i++) {
		howToChange.clear();
		if (i == 0) {
			for (int j = 0; j < framesConfig[i].second.size(); j++) {
				a = (framesConfig[i].second[j] - sliders[j]->GetValue());
				howToChange.push_back(a);
			}
			animationVector.push_back(howToChange);
		}
		else {
			for (int j = 0; j < framesConfig[i].second.size(); j++) {
				a = (framesConfig[i].second[j] - framesConfig[i - 1].second[j]);

				if (a != 0) {
					b = (framesConfig[i].first - framesConfig[i - 1].first);
					howToChange.push_back(a / b);
				}
				else {
					howToChange.push_back(0);
				}
			}
		}
		for (int j = 0; j < b; j++)
			animationVector.push_back(howToChange);
	}
}

void GUIMyFrame1::onStopButtonClick(wxCommandEvent& event)
{
	m_animationTimer.Stop();
}

void GUIMyFrame1::onTimerTick(wxTimerEvent& event)
{
	animate();
}


void GUIMyFrame1::reset()
{
	m_left_forearm_slider->SetValue(0);
	m_right_forearm_slider->SetValue(0);
	m_left_arm_side_slider->SetValue(50);
	m_right_arm_side_slider->SetValue(50);
	m_left_arm_front_slider->SetValue(0);
	m_right_arm_front_slider->SetValue(0);
	m_left_tibia_slider->SetValue(0);
	m_right_tibia_slider->SetValue(0);
	m_left_thigh_side_slider->SetValue(0);
	m_right_thigh_side_slider->SetValue(0);
	m_left_thigh_front_slider->SetValue(50);
	m_right_thigh_front_slider->SetValue(50);
	m_middle_back_front_slider->SetValue(0);
	m_middle_back_side_slider->SetValue(50);
	m_lower_back_front_slider->SetValue(0);
	m_lower_back_side_slider->SetValue(50);
}

void GUIMyFrame1::saveSliders()
{
	std::vector<int> slidersValues;
	for (auto& element : sliders) {
		slidersValues.push_back(element->GetValue());
	}
	int index = myFind(framesConfig, selectedFrame);
	savedFrames.push_back(selectedFrame);
	if (index == -1)
		framesConfig.push_back(make_pair(selectedFrame, slidersValues));
	else
		framesConfig[index].second = slidersValues;
}

void GUIMyFrame1::draw(wxClientDC& dcClient)
{
	wxBufferedDC dc(&dcClient);
	PrepareDC(dc);
	dc.Clear();
	dc.SetBrush(wxBrush(*wxWHITE_BRUSH));

	int w, h;
	m_panel2->GetSize(&w, &h);


	dc.SetPen(wxPen(wxColor(0, 0, 0), 2));


	Matrix trans = translate(w / 2.0, h / 2.0, 0);

	//do obracania szkieletem
	Matrix rot_y = rotate_y(alpha);
	Matrix rot_x = rotate_x(beta);
	Matrix rot = mat_mat_multiply(rot_x, rot_y);


	Matrix trans_left_forearm = translate(60, 100, 0);
	Matrix rot_left_forearm = rotate_z(m_left_forearm_slider->GetValue() * 0.9);
	Matrix transback_left_forearm = translate(-60, -100, 0);

	Matrix trans_right_forearm = translate(-60, 100, 0);
	Matrix rot_right_forearm = rotate_z(-m_right_forearm_slider->GetValue() * 0.9);
	Matrix transback_right_forearm = translate(60, -100, 0);

	Matrix trans_left_arm = translate(10, 100, 0);
	Matrix rot_left_arm_side = rotate_z((m_left_arm_side_slider->GetValue() - 50.0) * 1.8);
	Matrix rot_left_arm_front = rotate_y(m_left_arm_front_slider->GetValue() * 0.9);
	Matrix transback_left_arm = translate(-10, -100, 0);

	Matrix trans_right_arm = translate(-10, 100, 0);
	Matrix rot_right_arm_side = rotate_z((m_right_arm_side_slider->GetValue() - 50.0) * 1.8);
	Matrix rot_right_arm_front = rotate_y(m_right_arm_front_slider->GetValue() * 0.9);
	Matrix transback_right_arm = translate(10, -100, 0);

	Matrix trans_left_tibia = translate(20, -65, 0);
	Matrix rot_left_tibia = rotate_x(m_left_tibia_slider->GetValue() * 0.9);
	Matrix transback_left_tibia = translate(-20, 65, 0);

	Matrix trans_right_tibia = translate(-20, -65, 0);
	Matrix rot_right_tibia = rotate_x(m_right_tibia_slider->GetValue() * 0.9);
	Matrix transback_right_tibia = translate(20, 65, 0);

	Matrix trans_left_thigh = translate(10, -5, 0);
	Matrix rot_left_thigh_side = rotate_z(m_left_thigh_side_slider->GetValue() * 0.6);
	Matrix rot_left_thigh_front = rotate_x((m_left_thigh_front_slider->GetValue() - 50.0) * 0.9);
	Matrix transback_left_thigh = translate(-10, 5, 0);

	Matrix trans_right_thigh = translate(-10, -5, 0);
	Matrix rot_right_thigh_side = rotate_z(-m_right_thigh_side_slider->GetValue() * 0.6);
	Matrix rot_right_thigh_front = rotate_x((m_right_thigh_front_slider->GetValue() - 50.0) * 0.9);
	Matrix transback_right_thigh = translate(10, 5, 0);

	Matrix trans_upper_back = translate(0, 50, 0);
	Matrix rot_upper_back_front = rotate_x(m_middle_back_front_slider->GetValue() * 0.10);
	Matrix rot_upper_back_side = rotate_z((m_middle_back_side_slider->GetValue() - 50.0) * 0.2);
	Matrix transback_upper_back = translate(0, -50, 0);

	Matrix rot_lower_back_front = rotate_x(m_lower_back_front_slider->GetValue() * 0.35);
	Matrix rot_lower_back_side = rotate_z((m_lower_back_side_slider->GetValue() - 50.0) * 0.5);

	for (auto& a : _bones) {
		Vec beg = a.begin();
		Vec en = a.end();

		if (a.name() == "neck") {
			//ruch szyi przy pochyleniu do przodu middle back
			beg = mat_vec_multiply(trans_upper_back, beg);
			beg = mat_vec_multiply(rot_upper_back_front, beg);
			beg = mat_vec_multiply(transback_upper_back, beg);

			en = mat_vec_multiply(trans_upper_back, en);
			en = mat_vec_multiply(rot_upper_back_front, en);
			en = mat_vec_multiply(transback_upper_back, en);



			//ruch szyi przy middle back do boku
			beg = mat_vec_multiply(trans_upper_back, beg);
			beg = mat_vec_multiply(rot_upper_back_side, beg);
			beg = mat_vec_multiply(transback_upper_back, beg);

			en = mat_vec_multiply(trans_upper_back, en);
			en = mat_vec_multiply(rot_upper_back_side, en);
			en = mat_vec_multiply(transback_upper_back, en);


			//ruch szyja dolna czesc kregoslupa przod
			beg = mat_vec_multiply(rot_lower_back_front, beg);

			en = mat_vec_multiply(rot_lower_back_front, en);


			//ruch szyja dolna czesc kregoslupa boki
			beg = mat_vec_multiply(rot_lower_back_side, beg);

			en = mat_vec_multiply(rot_lower_back_side, en);
		}

		if (a.name() == "left shoulder") {
			//ruch lewego barku przy pochyleniu do przodu middle back
			beg = mat_vec_multiply(trans_upper_back, beg);
			beg = mat_vec_multiply(rot_upper_back_front, beg);
			beg = mat_vec_multiply(transback_upper_back, beg);

			en = mat_vec_multiply(trans_upper_back, en);
			en = mat_vec_multiply(rot_upper_back_front, en);
			en = mat_vec_multiply(transback_upper_back, en);



			//ruch lwey bark przy middle back do boku
			beg = mat_vec_multiply(trans_upper_back, beg);
			beg = mat_vec_multiply(rot_upper_back_side, beg);
			beg = mat_vec_multiply(transback_upper_back, beg);

			en = mat_vec_multiply(trans_upper_back, en);
			en = mat_vec_multiply(rot_upper_back_side, en);
			en = mat_vec_multiply(transback_upper_back, en);


			//ruch lewy bark dolna czesc kregoslupa przod
			beg = mat_vec_multiply(rot_lower_back_front, beg);

			en = mat_vec_multiply(rot_lower_back_front, en);


			//ruch lewy bark dolna czesc kregoslupa boki
			beg = mat_vec_multiply(rot_lower_back_side, beg);

			en = mat_vec_multiply(rot_lower_back_side, en);

		}

		if (a.name() == "right shoulder") {
			//ruch lewego barku przy pochyleniu do przodu middle back
			beg = mat_vec_multiply(trans_upper_back, beg);
			beg = mat_vec_multiply(rot_upper_back_front, beg);
			beg = mat_vec_multiply(transback_upper_back, beg);

			en = mat_vec_multiply(trans_upper_back, en);
			en = mat_vec_multiply(rot_upper_back_front, en);
			en = mat_vec_multiply(transback_upper_back, en);



			//ruch prawy bark przy middle back do boku
			beg = mat_vec_multiply(trans_upper_back, beg);
			beg = mat_vec_multiply(rot_upper_back_side, beg);
			beg = mat_vec_multiply(transback_upper_back, beg);

			en = mat_vec_multiply(trans_upper_back, en);
			en = mat_vec_multiply(rot_upper_back_side, en);
			en = mat_vec_multiply(transback_upper_back, en);


			//ruch prawy bark dolna czesc kregoslupa przod
			beg = mat_vec_multiply(rot_lower_back_front, beg);

			en = mat_vec_multiply(rot_lower_back_front, en);


			//ruch prawy bark dolna czesc kregoslupa boki
			beg = mat_vec_multiply(rot_lower_back_side, beg);

			en = mat_vec_multiply(rot_lower_back_side, en);
		}




		if (a.name() == "left forearm") {
			//ruch lewa reka w ³okciu
			beg = mat_vec_multiply(trans_left_forearm, beg);
			beg = mat_vec_multiply(rot_left_forearm, beg);
			beg = mat_vec_multiply(transback_left_forearm, beg);


			//do lewej reki ca³ej w bok
			beg = mat_vec_multiply(trans_left_arm, beg);
			beg = mat_vec_multiply(rot_left_arm_side, beg);
			beg = mat_vec_multiply(transback_left_arm, beg);

			en = mat_vec_multiply(trans_left_arm, en);
			en = mat_vec_multiply(rot_left_arm_side, en);
			en = mat_vec_multiply(transback_left_arm, en);


			//do lewej rek calej do przodu
			beg = mat_vec_multiply(trans_left_arm, beg);
			beg = mat_vec_multiply(rot_left_arm_front, beg);
			beg = mat_vec_multiply(transback_left_arm, beg);

			en = mat_vec_multiply(trans_left_arm, en);
			en = mat_vec_multiply(rot_left_arm_front, en);
			en = mat_vec_multiply(transback_left_arm, en);




			//ruch lewego przedramienia przy middle back do przodu
			beg = mat_vec_multiply(trans_upper_back, beg);
			beg = mat_vec_multiply(rot_upper_back_front, beg);
			beg = mat_vec_multiply(transback_upper_back, beg);

			en = mat_vec_multiply(trans_upper_back, en);
			en = mat_vec_multiply(rot_upper_back_front, en);
			en = mat_vec_multiply(transback_upper_back, en);



			//ruch lewe przedramie przy middle back do boku
			beg = mat_vec_multiply(trans_upper_back, beg);
			beg = mat_vec_multiply(rot_upper_back_side, beg);
			beg = mat_vec_multiply(transback_upper_back, beg);

			en = mat_vec_multiply(trans_upper_back, en);
			en = mat_vec_multiply(rot_upper_back_side, en);
			en = mat_vec_multiply(transback_upper_back, en);



			//ruch lewe przedramie dolna czesc kregoslupa przod
			beg = mat_vec_multiply(rot_lower_back_front, beg);

			en = mat_vec_multiply(rot_lower_back_front, en);


			//ruch lewe przedramie dolna czesc kregoslupa boki
			beg = mat_vec_multiply(rot_lower_back_side, beg);

			en = mat_vec_multiply(rot_lower_back_side, en);
		}

		if (a.name() == "left arm") {

			//do lewej reki w bok
			beg = mat_vec_multiply(trans_left_arm, beg);
			beg = mat_vec_multiply(rot_left_arm_side, beg);
			beg = mat_vec_multiply(transback_left_arm, beg);


			//do lewej reki do przodu
			beg = mat_vec_multiply(trans_left_arm, beg);
			beg = mat_vec_multiply(rot_left_arm_front, beg);
			beg = mat_vec_multiply(transback_left_arm, beg);



			//ruch lewej reki przy pochyleniu do przodu middle back
			beg = mat_vec_multiply(trans_upper_back, beg);
			beg = mat_vec_multiply(rot_upper_back_front, beg);
			beg = mat_vec_multiply(transback_upper_back, beg);

			en = mat_vec_multiply(trans_upper_back, en);
			en = mat_vec_multiply(rot_upper_back_front, en);
			en = mat_vec_multiply(transback_upper_back, en);



			//ruch lewa reka przy middle back do boku
			beg = mat_vec_multiply(trans_upper_back, beg);
			beg = mat_vec_multiply(rot_upper_back_side, beg);
			beg = mat_vec_multiply(transback_upper_back, beg);

			en = mat_vec_multiply(trans_upper_back, en);
			en = mat_vec_multiply(rot_upper_back_side, en);
			en = mat_vec_multiply(transback_upper_back, en);



			//ruch lewa reka dolna czesc kregoslupa przod
			beg = mat_vec_multiply(rot_lower_back_front, beg);

			en = mat_vec_multiply(rot_lower_back_front, en);


			//ruch lewa reka dolna czesc kregoslupa boki
			beg = mat_vec_multiply(rot_lower_back_side, beg);

			en = mat_vec_multiply(rot_lower_back_side, en);
		}

		if (a.name() == "right forearm") {

			//ruch prawa reka w ³okciu
			en = mat_vec_multiply(trans_right_forearm, en);
			en = mat_vec_multiply(rot_right_forearm, en);
			en = mat_vec_multiply(transback_right_forearm, en);


			//do prawej reki ca³ej w bok
			beg = mat_vec_multiply(trans_right_arm, beg);
			beg = mat_vec_multiply(rot_right_arm_side, beg);
			beg = mat_vec_multiply(transback_right_arm, beg);

			en = mat_vec_multiply(trans_right_arm, en);
			en = mat_vec_multiply(rot_right_arm_side, en);
			en = mat_vec_multiply(transback_right_arm, en);


			//do prawej rek calej do przodu
			beg = mat_vec_multiply(trans_right_arm, beg);
			beg = mat_vec_multiply(rot_right_arm_front, beg);
			beg = mat_vec_multiply(transback_right_arm, beg);

			en = mat_vec_multiply(trans_right_arm, en);
			en = mat_vec_multiply(rot_right_arm_front, en);
			en = mat_vec_multiply(transback_right_arm, en);



			//ruch prawego przedramienia przy pochyleniu do przodu middle back
			beg = mat_vec_multiply(trans_upper_back, beg);
			beg = mat_vec_multiply(rot_upper_back_front, beg);
			beg = mat_vec_multiply(transback_upper_back, beg);

			en = mat_vec_multiply(trans_upper_back, en);
			en = mat_vec_multiply(rot_upper_back_front, en);
			en = mat_vec_multiply(transback_upper_back, en);



			//ruch prawe przedramie przy middle back do boku
			beg = mat_vec_multiply(trans_upper_back, beg);
			beg = mat_vec_multiply(rot_upper_back_side, beg);
			beg = mat_vec_multiply(transback_upper_back, beg);

			en = mat_vec_multiply(trans_upper_back, en);
			en = mat_vec_multiply(rot_upper_back_side, en);
			en = mat_vec_multiply(transback_upper_back, en);



			//ruch prawe przedramie dolna czesc kregoslupa przod
			beg = mat_vec_multiply(rot_lower_back_front, beg);

			en = mat_vec_multiply(rot_lower_back_front, en);


			//ruch prawe przedramie dolna czesc kregoslupa boki
			beg = mat_vec_multiply(rot_lower_back_side, beg);

			en = mat_vec_multiply(rot_lower_back_side, en);

		}

		if (a.name() == "right arm") {

			//do prawej reki w bok
			en = mat_vec_multiply(trans_right_arm, en);
			en = mat_vec_multiply(rot_right_arm_side, en);
			en = mat_vec_multiply(transback_right_arm, en);


			//do prawej reki do przodu
			en = mat_vec_multiply(trans_right_arm, en);
			en = mat_vec_multiply(rot_right_arm_front, en);
			en = mat_vec_multiply(transback_right_arm, en);



			//ruch prawej reki przy pochyleniu do przodu middle back
			beg = mat_vec_multiply(trans_upper_back, beg);
			beg = mat_vec_multiply(rot_upper_back_front, beg);
			beg = mat_vec_multiply(transback_upper_back, beg);

			en = mat_vec_multiply(trans_upper_back, en);
			en = mat_vec_multiply(rot_upper_back_front, en);
			en = mat_vec_multiply(transback_upper_back, en);



			//ruch prawa reka przy middle back do boku
			beg = mat_vec_multiply(trans_upper_back, beg);
			beg = mat_vec_multiply(rot_upper_back_side, beg);
			beg = mat_vec_multiply(transback_upper_back, beg);

			en = mat_vec_multiply(trans_upper_back, en);
			en = mat_vec_multiply(rot_upper_back_side, en);
			en = mat_vec_multiply(transback_upper_back, en);



			//ruch prawa reka dolna czesc kregoslupa przod
			beg = mat_vec_multiply(rot_lower_back_front, beg);

			en = mat_vec_multiply(rot_lower_back_front, en);


			//ruch prawa reka dolna czesc kregoslupa boki
			beg = mat_vec_multiply(rot_lower_back_side, beg);

			en = mat_vec_multiply(rot_lower_back_side, en);
		}

		if (a.name() == "left tibia") {
			//ruch lewy piszczel
			en = mat_vec_multiply(trans_left_tibia, en);
			en = mat_vec_multiply(rot_left_tibia, en);
			en = mat_vec_multiply(transback_left_tibia, en);


			//ruch lewego piszczela przy lewym udzie w bok
			en = mat_vec_multiply(trans_left_thigh, en);
			en = mat_vec_multiply(rot_left_thigh_side, en);
			en = mat_vec_multiply(transback_left_thigh, en);

			beg = mat_vec_multiply(trans_left_thigh, beg);
			beg = mat_vec_multiply(rot_left_thigh_side, beg);
			beg = mat_vec_multiply(transback_left_thigh, beg);


			//ruch lewego piszczela przy lewym udzie przod/tyl
			beg = mat_vec_multiply(trans_left_thigh, beg);
			beg = mat_vec_multiply(rot_left_thigh_front, beg);
			beg = mat_vec_multiply(transback_left_thigh, beg);

			en = mat_vec_multiply(trans_left_thigh, en);
			en = mat_vec_multiply(rot_left_thigh_front, en);
			en = mat_vec_multiply(transback_left_thigh, en);

		}

		if (a.name() == "left thigh") {

			//ruch lewe udo bok
			en = mat_vec_multiply(trans_left_thigh, en);
			en = mat_vec_multiply(rot_left_thigh_side, en);
			en = mat_vec_multiply(transback_left_thigh, en);


			//ruch lewe udo przod tyl
			en = mat_vec_multiply(trans_left_thigh, en);
			en = mat_vec_multiply(rot_left_thigh_front, en);
			en = mat_vec_multiply(transback_left_thigh, en);
		}

		if (a.name() == "right tibia") {
			//ruch prawy piszczel
			en = mat_vec_multiply(trans_right_tibia, en);
			en = mat_vec_multiply(rot_right_tibia, en);
			en = mat_vec_multiply(transback_right_tibia, en);


			//ruch prawy piszczel przy prawym udzie w bok
			en = mat_vec_multiply(trans_right_thigh, en);
			en = mat_vec_multiply(rot_right_thigh_side, en);
			en = mat_vec_multiply(transback_right_thigh, en);

			beg = mat_vec_multiply(trans_right_thigh, beg);
			beg = mat_vec_multiply(rot_right_thigh_side, beg);
			beg = mat_vec_multiply(transback_right_thigh, beg);


			//ruch prawy piszczel przy prawym udzie przod/tyl
			en = mat_vec_multiply(trans_right_thigh, en);
			en = mat_vec_multiply(rot_right_thigh_front, en);
			en = mat_vec_multiply(transback_right_thigh, en);

			beg = mat_vec_multiply(trans_right_thigh, beg);
			beg = mat_vec_multiply(rot_right_thigh_front, beg);
			beg = mat_vec_multiply(transback_right_thigh, beg);


		}

		if (a.name() == "right thigh") {
			//ruch prawe udo bok
			en = mat_vec_multiply(trans_right_thigh, en);
			en = mat_vec_multiply(rot_right_thigh_side, en);
			en = mat_vec_multiply(transback_right_thigh, en);

			//ruch prawe udo przod/tyl
			en = mat_vec_multiply(trans_right_thigh, en);
			en = mat_vec_multiply(rot_right_thigh_front, en);
			en = mat_vec_multiply(transback_right_thigh, en);
		}

		if (a.name() == "upper backbone") {
			//ruch gornej czesci kregoslupa w przod
			beg = mat_vec_multiply(trans_upper_back, beg);
			beg = mat_vec_multiply(rot_upper_back_front, beg);
			beg = mat_vec_multiply(transback_upper_back, beg);


			//ruch gornej czesci kregoslupa w bok
			beg = mat_vec_multiply(trans_upper_back, beg);
			beg = mat_vec_multiply(rot_upper_back_side, beg);
			beg = mat_vec_multiply(transback_upper_back, beg);


			//ruch gorna czesc kregoslupa dolna czesc kregoslupa przod
			beg = mat_vec_multiply(rot_lower_back_front, beg);

			en = mat_vec_multiply(rot_lower_back_front, en);


			//ruch gorna czesc kregoslupa dolna czesc kregoslupa boki
			beg = mat_vec_multiply(rot_lower_back_side, beg);

			en = mat_vec_multiply(rot_lower_back_side, en);
		}

		if (a.name() == "lower backbone") {
			//ruch dolnej czesci kregoslupa przod
			beg = mat_vec_multiply(rot_lower_back_front, beg);

			//ruch dolnej czesci kregoslupa boki
			beg = mat_vec_multiply(rot_lower_back_side, beg);
		}


		beg = mat_vec_multiply(rot, beg);
		en = mat_vec_multiply(rot, en);

		beg = mat_vec_multiply(trans, beg);
		en = mat_vec_multiply(trans, en);

		dc.DrawLine(beg.X(), beg.Y(), en.X(), en.Y());
	}

	for (auto& j : _joints) {
		Vec cen = j.center();

		if (j.name() == "left elbow") {
			//lewy staw lokiec bok w ramieniu
			cen = mat_vec_multiply(trans_left_arm, cen);
			cen = mat_vec_multiply(rot_left_arm_side, cen);
			cen = mat_vec_multiply(transback_left_arm, cen);


			//lewy staw lokiec przod w ramieniu
			cen = mat_vec_multiply(trans_left_arm, cen);
			cen = mat_vec_multiply(rot_left_arm_front, cen);
			cen = mat_vec_multiply(transback_left_arm, cen);


			//ruch lewy staw lokiec przy pochyleniu do przodu middle back
			cen = mat_vec_multiply(trans_upper_back, cen);
			cen = mat_vec_multiply(rot_upper_back_front, cen);
			cen = mat_vec_multiply(transback_upper_back, cen);


			//ruch lewy staw lokiec przy middle back do boku
			cen = mat_vec_multiply(trans_upper_back, cen);
			cen = mat_vec_multiply(rot_upper_back_side, cen);
			cen = mat_vec_multiply(transback_upper_back, cen);


			//ruch lewy lokiec dolna czesc kregoslupa przod
			cen = mat_vec_multiply(rot_lower_back_front, cen);


			//ruch lewy lokiec dolna czesc kregoslupa boki
			cen = mat_vec_multiply(rot_lower_back_side, cen);

		}

		if (j.name() == "left shoulder") {
			//lewy bark przod w middle back
			cen = mat_vec_multiply(trans_upper_back, cen);
			cen = mat_vec_multiply(rot_upper_back_front, cen);
			cen = mat_vec_multiply(transback_upper_back, cen);

			//lewy bark bok w middle back
			cen = mat_vec_multiply(trans_upper_back, cen);
			cen = mat_vec_multiply(rot_upper_back_side, cen);
			cen = mat_vec_multiply(transback_upper_back, cen);

			//ruch lewy bark dolna czesc kregoslupa przod
			cen = mat_vec_multiply(rot_lower_back_front, cen);


			//ruch lewy bark dolna czesc kregoslupa boki
			cen = mat_vec_multiply(rot_lower_back_side, cen);
		}

		if (j.name() == "neck") {
			//ruch kark przy pochyleniu do przodu middle back
			cen = mat_vec_multiply(trans_upper_back, cen);
			cen = mat_vec_multiply(rot_upper_back_front, cen);
			cen = mat_vec_multiply(transback_upper_back, cen);

			//ruch akrk przy middle back do boku
			cen = mat_vec_multiply(trans_upper_back, cen);
			cen = mat_vec_multiply(rot_upper_back_side, cen);
			cen = mat_vec_multiply(transback_upper_back, cen);

			//ruch kark dolna czesc kregoslupa przod
			cen = mat_vec_multiply(rot_lower_back_front, cen);

			//ruch akrk dolna czesc kregoslupa boki
			cen = mat_vec_multiply(rot_lower_back_side, cen);
		}

		if (j.name() == "right shoulder") {
			//ruch lewego barku przy pochyleniu do przodu middle back
			cen = mat_vec_multiply(trans_upper_back, cen);
			cen = mat_vec_multiply(rot_upper_back_front, cen);
			cen = mat_vec_multiply(transback_upper_back, cen);

			//ruch prawy bark przy middle back do boku
			cen = mat_vec_multiply(trans_upper_back, cen);
			cen = mat_vec_multiply(rot_upper_back_side, cen);
			cen = mat_vec_multiply(transback_upper_back, cen);

			//ruch prawy bark dolna czesc kregoslupa przod
			cen = mat_vec_multiply(rot_lower_back_front, cen);

			//ruch prawy bark dolna czesc kregoslupa boki
			cen = mat_vec_multiply(rot_lower_back_side, cen);
		}

		if (j.name() == "right elbow") {
			//prawy staw lokiec bok w ramieniu
			cen = mat_vec_multiply(trans_right_arm, cen);
			cen = mat_vec_multiply(rot_right_arm_side, cen);
			cen = mat_vec_multiply(transback_right_arm, cen);


			//prawy staw lokiec przod w ramieniu
			cen = mat_vec_multiply(trans_right_arm, cen);
			cen = mat_vec_multiply(rot_right_arm_front, cen);
			cen = mat_vec_multiply(transback_right_arm, cen);


			//ruch prawy staw lokiec przy pochyleniu do przodu middle back
			cen = mat_vec_multiply(trans_upper_back, cen);
			cen = mat_vec_multiply(rot_upper_back_front, cen);
			cen = mat_vec_multiply(transback_upper_back, cen);


			//ruch prawy staw lokiec przy middle back do boku
			cen = mat_vec_multiply(trans_upper_back, cen);
			cen = mat_vec_multiply(rot_upper_back_side, cen);
			cen = mat_vec_multiply(transback_upper_back, cen);


			//ruch prawy lokiec dolna czesc kregoslupa przod
			cen = mat_vec_multiply(rot_lower_back_front, cen);


			//ruch prawy lokiec dolna czesc kregoslupa boki
			cen = mat_vec_multiply(rot_lower_back_side, cen);
		}

		if (j.name() == "upper back") {
			//ruch gornej czesci kregoslupa w przod
			cen = mat_vec_multiply(trans_upper_back, cen);
			cen = mat_vec_multiply(rot_upper_back_front, cen);
			cen = mat_vec_multiply(transback_upper_back, cen);


			//ruch gornej czesci kregoslupa w bok
			cen = mat_vec_multiply(trans_upper_back, cen);
			cen = mat_vec_multiply(rot_upper_back_side, cen);
			cen = mat_vec_multiply(transback_upper_back, cen);

			//ruch gorna czesc kregoslupa dolna czesc kregoslupa przod
			cen = mat_vec_multiply(rot_lower_back_front, cen);

			//ruch gorna czesc kregoslupa dolna czesc kregoslupa boki
			cen = mat_vec_multiply(rot_lower_back_side, cen);
		}

		if (j.name() == "left knee") {
			//ruch lewe kolano przy lewym udzie w bok
			cen = mat_vec_multiply(trans_left_thigh, cen);
			cen = mat_vec_multiply(rot_left_thigh_side, cen);
			cen = mat_vec_multiply(transback_left_thigh, cen);

			//ruch lewe kolano przy lewym udzie przod/tyl
			cen = mat_vec_multiply(trans_left_thigh, cen);
			cen = mat_vec_multiply(rot_left_thigh_front, cen);
			cen = mat_vec_multiply(transback_left_thigh, cen);
		}

		if (j.name() == "right knee") {
			//ruch prawe kolano przy prawym udzie w bok
			cen = mat_vec_multiply(trans_right_thigh, cen);
			cen = mat_vec_multiply(rot_right_thigh_side, cen);
			cen = mat_vec_multiply(transback_right_thigh, cen);

			//ruch prawe kolano przy prawym udzie przod/tyl
			cen = mat_vec_multiply(trans_right_thigh, cen);
			cen = mat_vec_multiply(rot_right_thigh_front, cen);
			cen = mat_vec_multiply(transback_right_thigh, cen);
		}

		cen = mat_vec_multiply(rot, cen);
		cen = mat_vec_multiply(trans, cen);

		dc.DrawCircle(cen.X(), cen.Y(), j.radius());

		if (is_startAnimation_clicked) {
			int amountOfFrames = wxAtoi(m_amountOfFramesText->GetValue());
			m_animationTimer.Start(5000 / amountOfFrames, true);
		}
	}
}

int GUIMyFrame1::myFind(std::vector<std::pair<int, std::vector<int>>> whereToLookFor, int whatToLookFor)
{
	for (int i = 0; i < whereToLookFor.size(); i++) {
		if (whereToLookFor[i].first == whatToLookFor)
			return i;
	}
	return -1;
}

void GUIMyFrame1::animate()
{
	if (selectedFrame == 0) {
		setSlidersPosition(framesConfig[0].second);
	}
	int amountOfFrames = wxAtoi(m_amountOfFramesText->GetValue());
	if (selectedFrame < amountOfFrames) {
		for (int i = 0; i < sliders.size(); i++) {
			int currentValue = sliders[i]->GetValue();
			sliders[i]->SetValue(currentValue + animationVector[selectedFrame][i]);
		}
		selectedFrame++;
	}
	else {
		if (m_repeatCheckBox->IsChecked()) {
			selectedFrame = 0;
		}
	}
}

void GUIMyFrame1::setSlidersPosition(std::vector<int> slidersValue)
{
	for (int i = 0; i < sliders.size(); i++) {
		sliders[i]->SetValue(slidersValue[i]);
	}
}

void GUIMyFrame1::drawForAnimation(wxClientDC& dcClient)
{
	wxBufferedDC dc(&dcClient);
	PrepareDC(dc);
	dc.Clear();
	linesPosition.clear();
	if (is_enableAnimation_clicked) {
		m_saveFrameButton->Enable();
		m_startAnimationButton->Enable();
		m_startAnimationButton->Enable();
		m_amountOfFramesText->Disable();
		m_timeline_panel->SetBackgroundColour(wxColor(220, 220, 220));
		int width, height;
		m_timeline_panel->GetSize(&width, &height);
		int amountOfFrames = wxAtoi(m_amountOfFramesText->GetValue());
		if (amountOfFrames != 0 && amountOfFrames != NULL) {
			float frameWidth = width / amountOfFrames;
			dc.SetPen(wxPen(wxColor(255, 0, 0), 2));

			for (int i = 1; i <= amountOfFrames; i++) {
				dc.DrawLine(wxPoint(frameWidth * i, 0), wxPoint(frameWidth * i, height));
				linesPosition.push_back(wxPoint(frameWidth * i, 0));
			}
			for (int i = 0; i < configurableFrames.size(); i++) {
				int pom = configurableFrames[i];

				if (find(savedFrames.begin(), savedFrames.end(), configurableFrames[i]) != savedFrames.end())
					dc.SetBrush(wxBrush(wxColor(255, 0, 0)));
				else
					dc.SetBrush(wxBrush(wxColor(255, 255, 255)));

				if (pom != 0) {
					dc.DrawCircle(wxPoint(linesPosition[pom].x - frameWidth / 2, height / 2), frameWidth / 4);
				}
				else {
					dc.DrawCircle(wxPoint(frameWidth / 2, height / 2), frameWidth / 4);
				}
			}
		}
	}
	else {
		m_timeline_panel->SetBackgroundColour(wxColor(100, 100, 100));
		m_amountOfFramesText->Enable();
		m_saveFrameButton->Disable();
		m_startAnimationButton->Disable();
		m_startAnimationButton->Disable();
		configurableFrames.clear();
		linesPosition.clear();
		m_selectedFrameText->SetValue(wxString::Format(wxT("")));
	}
}
