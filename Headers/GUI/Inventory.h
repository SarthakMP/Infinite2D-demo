#pragma once
#include"Headers/GUI/GUI.h"
#include"Headers/GUI/GUIHandler.h"
#include"Headers/GUI/Hotbar.h"
#include"Headers/Rectangle.h"

class InventoryGUI : public GUI {

	const int id_Gui = INVENTORY_ID;
	const int Inventory_H = 400, Inventory_W = 400;
	const int InventoryBlockH = 50, InventoryBlockW = 50;
	const float BlockPaddingX = 10, BlockPaddingY = 10;
	const float PaddingX = 100, PaddingY = 100;
	Rectangle ClickableArea = {0,0,0,0};
	static inline std::vector<std::vector<std::pair<int,TexturedRectangle>>> InventoryBlocks;

	Point BasePoints[4][10];
	Point BasePoint = 0;
public:
	Rectangle InventoryScreenGUI;

public:
	InventoryGUI(Camera2D& cam) : GUI(cam) { IntializeInventoryGUI(); }
	void IntializeInventoryGUI();

	int GetGuiId();
	void OnMouseHoverGUI(Vector2 in_MousePos);
	void OnMousePressedGUI(Vector2 in_MousePos);
	//void OnMouseDownGUI(Vector2 in_MousePos);
	void UpdateGUI();
	void RenderGUI();
};