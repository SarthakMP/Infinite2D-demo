#pragma once
#include"Headers/Screens/Screen.h"

class Options : public Screen {
public:

	static inline std::vector<Screen*> Children;
	static inline Rectangle BackButton;
public:
	void InitializeChildern() override;
	void InitializeButtons() override;
	void DrawButtons() override;
	int GetButtonInfo() override;
	std::string GetButtonType() override;
	Screen* GetNextScreen() override;

	Options(Camera2D& in_cam);
};
