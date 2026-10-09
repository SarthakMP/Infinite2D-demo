#pragma once
#include"Headers/Screens/Screen.h"
class StartScreen : public Scree_Adapter{
public:
	static inline std::string WorldName ="";
	static inline std::string Seed = "";

	static inline bool TextboxList[2] = { false,false };

	static inline Rectangle WorldNameTextBox, SeedTextBox, StartNewButton, OptionsButton,BackButton;

public:
	void InitializeChildern() override;
	void InitializeButtons() override;
	void Render() override;
	int GetButtonInfo() override;
	std::string GetButtonType() override;
	Screen* GetNextScreen() override;
	void SetText(const std::string& text, const std::string& Type) override;


	StartScreen() = default;
	StartScreen(Camera2D& cam);

};