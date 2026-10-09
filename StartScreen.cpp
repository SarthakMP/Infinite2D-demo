#include "Headers/Screens/StartScreen.h"

void StartScreen::InitializeChildern()
{

}

void StartScreen::InitializeButtons()
{
	
	StartNewButton = Rectangle(Cam.target.x - 200, Cam.target.y + 200, 100, 50);
	BackButton = Rectangle(Cam.target.x + 200, Cam.target.y + 200, 100, 50);
	
	WorldNameTextBox = Rectangle(Cam.target.x, Cam.target.y - 120, 500, 50);
	SeedTextBox = Rectangle(Cam.target.x, Cam.target.y, 500, 50);
	
}
Font F;
void StartScreen::Render()
{
	DrawRectanglePro(StartNewButton, { StartNewButton.width*0.5f,StartNewButton.height * 0.5f },0, WHITE);
	DrawText("Start", StartNewButton.x - 20, StartNewButton.y, 20, BLACK);
	
	DrawRectanglePro(BackButton, { BackButton.width * 0.5f,BackButton.height * 0.5f }, 0, WHITE);
	DrawText("<- Back", BackButton.x - 20, BackButton.y, 20, BLACK);
	
	
	DrawText("World Name", WorldNameTextBox.x - WorldNameTextBox.width*0.5f, WorldNameTextBox.y  - WorldNameTextBox.height, 20, WHITE);
	DrawRectanglePro(WorldNameTextBox, { WorldNameTextBox.width * 0.5f,WorldNameTextBox.height * 0.5f }, 0, WHITE);
	DrawTextEx(F, WorldName.c_str(), { WorldNameTextBox.x - (WorldNameTextBox.width * 0.5f) + 20, WorldNameTextBox.y - 10 }, 20, 1, BLACK);

	DrawText("Seed", SeedTextBox.x - SeedTextBox.width * 0.5f, SeedTextBox.y - SeedTextBox.height, 20, WHITE);
	DrawRectanglePro(SeedTextBox, { SeedTextBox.width * 0.5f,SeedTextBox.height * 0.5f }, 0, WHITE);
	DrawTextEx(F, Seed.c_str(), { SeedTextBox.x - (SeedTextBox.width * 0.5f) + 20, SeedTextBox.y - 10 }, 20, 1, BLACK);

	// FOR clearification of which textbox is selected add a yellow border around it.
	if (TextboxList[0]) {
		DrawRectangleLinesEx(Rectangle(WorldNameTextBox.x - WorldNameTextBox.width * 0.5f, WorldNameTextBox.y - WorldNameTextBox.height * 0.5f, WorldNameTextBox.width, WorldNameTextBox.height),2, RED);
	}
	else  {
		DrawRectangleLinesEx(Rectangle(SeedTextBox.x - SeedTextBox.width * 0.5f, SeedTextBox.y - SeedTextBox.height * 0.5f, SeedTextBox.width, SeedTextBox.height),2, RED);
	}
}

std::string StartScreen::GetButtonType() {

	int type = GetButtonInfo();

	switch (type)
	{
	case START_BUTTON_ID: {
		return "_Start";
	}
	case WORLDNAMETEXTBOX_BUTTON_ID: {
		TextboxList[0] = true;
		TextboxList[1] = false;
		return "_WorldNameTextbox";
	}
	case SEEDTEXTBOX_BUTTON_ID: {
		TextboxList[0] = false;
		TextboxList[1] = true;
		return "_SeedTextbox";
	}
	case BACK_BUTTON_ID: {
		return "_Back";
	}
	default:
		break;
	}
}

int StartScreen::GetButtonInfo()
{

	if (CheckBoundingArea(MousePos, StartNewButton, { StartNewButton.width * 0.5f,StartNewButton.height * 0.5f })) {
		return START_BUTTON_ID;
	}

	if (CheckBoundingArea(MousePos, BackButton, { BackButton.width * 0.5f,BackButton.height * 0.5f })) {
		return BACK_BUTTON_ID;
	}

	if (CheckBoundingArea(MousePos, WorldNameTextBox, { WorldNameTextBox.width * 0.5f,WorldNameTextBox.height * 0.5f })) {
		return WORLDNAMETEXTBOX_BUTTON_ID;
	}

	if (CheckBoundingArea(MousePos, SeedTextBox, { SeedTextBox.width * 0.5f,SeedTextBox.height * 0.5f })) {
		return SEEDTEXTBOX_BUTTON_ID;
	}



	return -11;
}

Screen* StartScreen::GetNextScreen()
{
	Screen* next = targetScreen;
	targetScreen = nullptr;
	return next;
}

void StartScreen::SetText(const std::string& text,const std::string& Type)
{
	if (text.empty()) return;
	
	if (Type._Equal("_World")) {

		WorldName = text;
	}
	if (Type._Equal("_Seed")) {

		Seed = text;
	}
}


StartScreen::StartScreen(Camera2D& cam)
{
	Cam = cam;
	InitializeButtons();
}
