#include "Headers/Screens/ContinueScreen.h"

void ContinueScreen::InitializeChildern()
{
}

void ContinueScreen::InitializeButtons()
{
}

void ContinueScreen::DrawButtons()
{
}

int ContinueScreen::GetButtonInfo()
{
	return 0;
}

std::string ContinueScreen::GetButtonType()
{
	return std::string();
}

Screen* ContinueScreen::GetNextScreen()
{
	Screen* next = targetScreen;
	targetScreen = nullptr;
	return next;
}

ContinueScreen::ContinueScreen(Camera2D& cam)
{
}
