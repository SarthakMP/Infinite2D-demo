#pragma once
#include"Headers/GUI/GUI.h"
#include"Headers/Screens/Screen.h"
#include"Headers/GUI/Inventory.h"
#include"Headers/GUI/GUIHandler.h"
#include <tuple>

class SideToolbarGUI : public GUI {


	const int id_Gui = 1;
	const int PaddingX = 20, PaddingY = 20;
	const int Block_H = 50, Block_W = 50;
	const int CloseGui_H = 50, CloseGui_W = 50;
	int InventoryGui_H = 0, InventoryGui_W = 0;
	Rectangle ClickableArea;
	Rectangle CloseButton;
public:
	Screen* Ptr = nullptr;
	std::unique_ptr<InventoryGUI> InventorySlot;
	std::tuple<Rectangle, CLITERAL(Color)> SideToolGUISlots[2];
	Point BasePos[2];
	
public:
	int GetGuiId();
	void InitializeSlots();
	void OnMouseDownGUI(Vector2 MousePos);
	void UpdateGUI();
	void RenderGUI();

	SideToolbarGUI(Camera2D& cam) : GUI(cam) { 
		InitializeSlots(); 
	
	}
	SideToolbarGUI(Camera2D& cam,Screen* screen) : GUI(cam),Ptr(screen) {
		InitializeSlots();
		
	}

	virtual ~SideToolbarGUI() = default;
};
