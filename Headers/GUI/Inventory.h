#pragma once
#include"Headers/GUI/GUI.h"

class InventoryGUI : public GUI {

	int Block_H = 100, Block_W = 100;
	float PaddingX = 20, PaddingY = 20;
	Rectangle ClickableArea = {0,0,0,0};

	Rectangle InventoryScreenGUI;
	std::vector<std::vector<Rectangle>> InventoryBlocks;
	Point BasePoint = 0;
public:
	InventoryGUI(Camera2D& cam) : GUI(cam) { IntializeInventoryGUI(); }
	void IntializeInventoryGUI();

	void UpdateGUI();
	void RenderGUI();
};