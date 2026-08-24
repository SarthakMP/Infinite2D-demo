#include "Headers/Screens/StartScreen.h"

void StartScreen::InitializeChildern()
{

}

void StartScreen::InitializeButtons()
{
	
	StartNewButton = Rectangle(Cam.target.x - 200, Cam.target.y + 200, 100, 50);
	BackButton = Rectangle(Cam.target.x + 200, Cam.target.y + 200, 100, 50);
	
	WorldNameTextBox = Rectangle(Cam.target.x, Cam.target.y, 500, 100);

	
}
Font F;
void StartScreen::DrawButtons()
{
	DrawRectanglePro(StartNewButton, { StartNewButton.width*0.5f,StartNewButton.height * 0.5f },0, WHITE);
	DrawText("Start", StartNewButton.x - 20, StartNewButton.y, 20, BLACK);
	
	DrawRectanglePro(BackButton, { BackButton.width * 0.5f,BackButton.height * 0.5f }, 0, WHITE);
	DrawText("<- Back", BackButton.x - 20, BackButton.y, 20, BLACK);

	DrawRectanglePro(WorldNameTextBox, { WorldNameTextBox.width * 0.5f,WorldNameTextBox.height * 0.5f }, 0, WHITE);

}

std::string StartScreen::GetButtonType() {

	int type = GetButtonInfo();

	switch (type)
	{
	case 0: {
		return "_Start";
	}
	case 1: {
		return "_Textbox";
	}
	default:
		break;
	}
}

int StartScreen::GetButtonInfo()
{

	int Scr_W = GetScreenWidth(), Scr_H = GetScreenHeight();
	Point MousePos = Point(GetMousePosition().x - Scr_W / 2, (GetMousePosition().y - Scr_H / 2));

	if (CheckBoundingArea(MousePos, StartNewButton, { StartNewButton.width * 0.5f,StartNewButton.height * 0.5f })) {
		return 0;
	}

	if (CheckBoundingArea(MousePos, WorldNameTextBox, { WorldNameTextBox.width * 0.5f,WorldNameTextBox.height * 0.5f })) {
		return 1;
	}

	if (CheckBoundingArea(MousePos, BackButton, { BackButton.width * 0.5f,BackButton.height * 0.5f })) {
		return -2;
	}

	return -1;
}

Screen* StartScreen::GetNextScreen()
{
	Screen* next = targetScreen;
	targetScreen = nullptr;
	return next;
}

StartScreen::StartScreen(Camera2D& cam)
{
	Cam = cam;
	InitializeButtons();
}
