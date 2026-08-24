#pragma once
#include"Headers/Screens/Screen.h"
class ContinueScreen : public Screen {
public:

	static inline int OptionSelected = -1;
	static inline Rectangle ContiuneButton, StartNewButton, OptionsButton;

public:
	void InitializeChildern() override;
	void InitializeButtons() override;
	void DrawButtons() override;
	int GetButtonInfo() override;
	std::string GetButtonType() override;
	Screen* GetNextScreen() override;

	ContinueScreen(Camera2D& cam);


};