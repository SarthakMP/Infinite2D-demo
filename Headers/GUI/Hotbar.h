#pragma once
#include"Headers/GUI/GUI.h"
#include"Headers/GUI/GUIHandler.h"

class HotbarGUI : public GUI {

	int Block_H = 50, Block_W = 50;
	float PaddingX = 20, PaddingY = 20;
	Rectangle ClickableArea;

public:
	
	void InitializeSlots();
	
	void RenderGUI();
	void UpdateGUI();

	void OnMouseDownGUI(Vector2 MousePos);

	std::tuple<Rectangle, CLITERAL(Color)> HotbarSlots[6] = {};
	Point BasePos[6];
	HotbarGUI(Camera2D& cam): GUI(cam){

		InitializeSlots();
	}
};