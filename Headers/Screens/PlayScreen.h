#pragma once
#include"Headers/Screens/Screen.h"
#include"Headers/GUI/Hotbar.h"

class PlayScreen : public Scree_Adapter
{
public:
	void InitializeGUIs();

	PlayScreen(Camera2D& in_cam) : Scree_Adapter(in_cam){
		
		InitializeGUIs();

	}

	~PlayScreen();
};