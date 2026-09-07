#pragma once
#include"Headers/GUI/GUI.h"
#include"Headers/GUI/GUIHandler.h"

class HotbarGUI : public GUI {

	int Block_H = 50, Block_W = 50;
public:

	void InitializeSlots();
	

	void RenderGUI();
	//int  GetButtonInfo(const Rectangle& rec, const Point& Pos, const int id);

	void UpdateGUI();
	void OnMouseDownGUI(Vector2 MousePos);

	std::tuple<Rectangle, CLITERAL(Color)> HotbarSlots[6] = {};
	Point BasePos[6];
	HotbarGUI(Camera2D& cam): GUI(cam){
		InitializeSlots();
	}
};