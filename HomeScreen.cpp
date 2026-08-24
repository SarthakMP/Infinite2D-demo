#include"Headers/Screens/HomeScreen.h"

void Home::InitializeChildern()
{
	Children.push_back(std::make_unique<ContinueScreen>(Cam));
	Children.push_back(std::make_unique<StartScreen>(Cam));
	Children.push_back(std::make_unique <Options>(Cam));

}

void Home::InitializeButtons() {

	int Scr_W = GetScreenWidth(), Scr_H = GetScreenHeight();


	ContiuneButton = Rectangle(Cam.target.x - 250, Cam.target.y - 200, 500, 100);
	StartNewButton = Rectangle(Cam.target.x - 250, Cam.target.y, 500, 100);
	OptionsButton = Rectangle(Cam.target.x - 250, Cam.target.y + 200, 500, 100);


	Buttons.push_back(ContiuneButton);
	Buttons.push_back(StartNewButton);
	Buttons.push_back(OptionsButton);
}

Font f;
void Home::DrawButtons()
{
	DrawRectangle(ContiuneButton.x, ContiuneButton.y, ContiuneButton.width, ContiuneButton.height, WHITE);
	DrawTextPro(f, "Continue", { ContiuneButton.x + 110, ContiuneButton.y + 25 }, { 0,0 }, 0, 80, 1, RED);

	DrawRectangle(StartNewButton.x, StartNewButton.y, StartNewButton.width, StartNewButton.height, WHITE);
	DrawTextPro(f, "Start New", { StartNewButton.x + 110, StartNewButton.y + 25 }, { 0,0 }, 0, 80, 1, RED);

	DrawRectangle(OptionsButton.x, OptionsButton.y, OptionsButton.width, OptionsButton.height, WHITE);
	DrawTextPro(f, "Option", { OptionsButton.x + 110, OptionsButton.y + 25 }, { 0,0 }, 0, 80, 1, RED);

}


Screen* Home::GetNextScreen() {
	Screen* next = targetScreen;
	targetScreen = nullptr;
	return next;
}

int Home::GetButtonInfo() {
	int Scr_W = GetScreenWidth(), Scr_H = GetScreenHeight();
	Point MousePos = Point(GetMousePosition().x - Scr_W / 2, (GetMousePosition().y - Scr_H / 2));


	if (CheckBoundingArea(MousePos, ContiuneButton)) {
		return 0;
	}

	if (CheckBoundingArea(MousePos, StartNewButton)) {
		return 1;
	}

	if (CheckBoundingArea(MousePos, OptionsButton)) {
		return 2;
	}

	return -1;
}

std::string Home::GetButtonType()
{
	return std::string();
}


