#pragma once
#include"Headers/GUI/GUI.h"

class HotbarGUI : public GUI {


	int Block_H = 50, Block_W = 50;
public:

	void InitializeSlots();
	
	Point tempPoints[4];

	void DrawGUI();
	void RenderGUI();
	int GetButtonInfo();

	void UpdateGUI();

	Rectangle HotbarSlots[6] = {};
	Point BasePos[6];
	HotbarGUI(Camera2D& cam): GUI(cam){
		InitializeSlots();
	}
};