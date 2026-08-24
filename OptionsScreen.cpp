#include "Headers/Screens/OptionsScreen.h"

void Options::InitializeChildern()
{
}

void Options::InitializeButtons()
{
	BackButton = Rectangle(Cam.target.x, Cam.target.y +150, 100, 50);

}

void Options::DrawButtons()
{
	DrawRectangle(BackButton.x, BackButton.y, BackButton.width, BackButton.height, WHITE);
	DrawText("<--", BackButton.x, BackButton.y, 50, BLACK);

}

int Options::GetButtonInfo()
{
	int Scr_W = GetScreenWidth(), Scr_H = GetScreenHeight();
	Point MousePos = Point(GetMousePosition().x - Scr_W / 2, (GetMousePosition().y - Scr_H / 2));


	if (CheckBoundingArea(MousePos, BackButton)) {
		return -2;
	}

	return -1;
}
std::string Options::GetButtonType()
{
	return std::string();
}
Screen* Options::GetNextScreen()
{
	return nullptr;
}
Options::Options(Camera2D& in_Cam) {
	Cam = in_Cam;
	InitializeButtons();
}

