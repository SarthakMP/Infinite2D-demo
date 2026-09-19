#pragma once
#include"Headers/GUI/GUI.h"
#include"Headers/Screens/Screen.h"
#include"Headers/GUI/Inventory.h"
#include"Headers/GUI/GUIHandler.h"
#include <tuple>

class SideToolbarGUI : public GUI {

	const int PaddingX = 20, PaddingY = 20;
	const int Block_H = 50, Block_W = 50;
	Rectangle ClickableArea;
public:
	Screen* Ptr;
	std::unique_ptr<InventoryGUI> InventorySlot;
	std::tuple<Rectangle, CLITERAL(Color)> SideToolGUISlots[2];
	Point BasePos[2];
	
public:

	void InitializeSlots();
	void OnMouseDownGUI(Vector2 MousePos);
	void UpdateGUI();
	void RenderGUI();

	SideToolbarGUI(Camera2D& cam) : GUI(cam) { InitializeSlots(); }
	SideToolbarGUI(Camera2D& cam,Screen* screen) : GUI(cam),Ptr(screen) {
		InitializeSlots();
		
	}

	virtual ~SideToolbarGUI() = default;
};
