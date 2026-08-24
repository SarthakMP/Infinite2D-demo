#pragma once
#include"Headers/Screens/Screen.h"
class StartScreen : public Screen{
public:
	static inline std::string WorldName ="";

	static inline Rectangle WorldNameTextBox, StartNewButton, OptionsButton,BackButton;

public:
	void InitializeChildern() override;
	void InitializeButtons() override;
	void DrawButtons() override;
	int GetButtonInfo() override;
	std::string GetButtonType() override;
	Screen* GetNextScreen() override;

	StartScreen() = default;
	StartScreen(Camera2D& cam);

};