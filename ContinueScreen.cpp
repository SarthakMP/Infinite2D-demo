#include "Headers/Screens/ContinueScreen.h"

void ContinueScreen::InitializeChildern()
{

}

void ContinueScreen::InitializeButtons()
{
	
	ScreenBackground = Rectangle(Cam.target.x  - Bkg_W * 0.5f, Cam.target.y - Bkg_H * 0.5f, Bkg_W, Bkg_H);
}

void ContinueScreen::DrawButtons()
{
	//Backgroudn Rec
	DrawRectangle(ScreenBackground.x, ScreenBackground.y, Bkg_W, Bkg_H, WHITE);
	GetScreenList();
	if (WorldCount != 0) {
		for (auto& world : WorldList) {

			DrawRectanglePro(world.first, { 0,0 }, 0, GetColor(0x47bc90FF));
			DrawTextEx(F, world.second.c_str(), { world.first.x + 10,world.first.y + world.first.height * 0.5f }, 20, 1, BLACK);
		}
		
	}
	else
	{
		DrawTextEx(F, "No Worlds added yet", { ScreenBackground.x + 10,ScreenBackground.y + ScreenBackground.height*0.05f }, 20, 1, RED);
	}
}

int ContinueScreen::GetButtonInfo()
{
	int Scr_W = GetScreenWidth(), Scr_H = GetScreenHeight();
	Point MousePos = Point(GetMousePosition().x - Scr_W / 2, (GetMousePosition().y - Scr_H / 2));

	for (auto& world : WorldList) {
		if (CheckBoundingArea(MousePos, world.first)) {
			LocWorldName = world.second;
			return 1;
		}
	}

	return -2;
}

std::string ContinueScreen::GetButtonType()
{

	return LocWorldName;
}

Screen* ContinueScreen::GetNextScreen()
{
	Screen* next = targetScreen;
	targetScreen = nullptr;
	return next;
}


void ContinueScreen::GetScreenList(){

	int counter = 0;
	std::string path = LevelDesigner::baseWorldsPath;
	if (std::filesystem::exists(path) && std::filesystem::is_directory(path) ) {
		
		for (const auto& entry : std::filesystem::directory_iterator(path)) {

			std::string path_str = entry.path().string();
			std::string_view view(path_str);
			std::string_view Str = view.substr(path.size(), path.back());
			std::string worldName(Str);

			Rectangle world = Rectangle(ScreenBackground.x + 5,  ScreenBackground.y + 5 + counter*100, ScreenBackground.width - 10,  100 - 10);
			
			WorldList.push_back({world,worldName });

			
			counter += 1;
			WorldCount = counter;
		}
	}

}

ContinueScreen::ContinueScreen(Camera2D& cam)
{
	Cam = cam;
	InitializeButtons();
}
