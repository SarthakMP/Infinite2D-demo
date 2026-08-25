#pragma once
#include"Headers/Screens/Screen.h"
#include"Headers/Screens/StartScreen.h"
#include "Headers/LevelDesigner.h"
#include <filesystem>
class ContinueScreen : public Scree_Adapter {
public:
	Font F = Font();
	static inline int Bkg_W = 600, Bkg_H = 600;
	static inline int OptionSelected = -1;
	static inline Rectangle ScreenBackground;
	static inline int WorldCount = 0;
	static inline std::vector<std::pair<Rectangle,std::string>> WorldList;
	static inline std::string LocWorldName;

public:
	
	void InitializeChildern() override;
	void InitializeButtons() override;
	void DrawButtons() override;
	int GetButtonInfo() override;
	std::string GetButtonType() override;
	Screen* GetNextScreen() override;
	void GetScreenList();

	ContinueScreen(Camera2D& cam);


};