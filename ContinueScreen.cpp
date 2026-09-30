#include "Headers/Screens/ContinueScreen.h"

void ContinueScreen::InitializeChildern()
{

}

void ScrollBar::InitializeScrollBar(Point TrackXY, Point ThumbXY, Point TrackWH, Point ThumbWH, Point in_MousePos) {
	track_w = TrackWH.x;
	track_h = TrackWH.y;

	thumb_w = ThumbWH.x;
	thumb_h = ThumbWH.y;

	track = Rectangle(TrackXY.x, TrackXY.y, track_w, track_h);
	thumb = Rectangle(ThumbXY.x, ThumbXY.y, thumb_w, thumb_h);
	MousePos = in_MousePos;
}

void ContinueScreen::MoveAndInsertWorld(std::pair<ObservableRectangle,std::string> in_world, bool ShiftTowards) { // 0: left, 1: right
	if (ShiftTowards == 0) {
		for(size_t i =0; i<MaxObservableWorldCount-1; i++){
			ObservableWorldList[i] = ObservableWorldList[i + 1];
		}
		ObservableWorldList[5] = in_world;
	}
	else {
		for(int i = MaxObservableWorldCount - 1; i >= 1; i--) {
			ObservableWorldList[i] = ObservableWorldList[i - 1];
		}
		ObservableWorldList[0] = in_world;
	}
}

void ContinueScreen::Update() {


	bool isUP = 0;
	bool isDOWN = 0;

	if (IsKeyPressed(KEY_UP))
		isUP = 1;
	else if (IsKeyPressed(KEY_DOWN))
		isDOWN = 1;


	for (auto& world_Title : WorldList) {

		// world.first.rec.height = 90, +10 it to make the height of the slot
		
		if (isDOWN) { //Move down the list
			world_Title.first.rec.y -= world_Title.first.rec.height + 10;
			ScrlBar1.thumb.y += (CountRatio)*WorldCount;
		}
		else if(isUP){ //Move up the list
			world_Title.first.rec.y += world_Title.first.rec.height + 10;
			ScrlBar1.thumb.y -= (CountRatio)*WorldCount;
		}

		if (world_Title.first.rec.y < ScreenBackground.y) {
			world_Title.first.isObservable = false;
		}
		else if (world_Title.first.rec.y > (ScreenBackground.y + Bkg_H)) {
			world_Title.first.isObservable = false;
		}
		else {
			world_Title.first.isObservable = true;
		}
		//TODO Add the functionality for scrollable worlds with smooth world-Title rendering. 
		

	}

	isUP = 0;
	isDOWN = 0;


}

void ContinueScreen::OnMouseUp() {
	ScrlBar1.OnMouseUp();
}

void ContinueScreen::OnMouseDown() {
	if (CheckBoundingArea(MousePos, ScrlBar1.thumb)) {
		ScrlBar1.OnMouseDown();
	}
}

void ContinueScreen::InitializeButtons()
{
	
	ScreenBackground = Rectangle(Cam.target.x  - Bkg_W * 0.5f, Cam.target.y - Bkg_H * 0.5f, Bkg_W, Bkg_H);
	GetScreenList();
	CountRatio = WorldCount != 0 ?  static_cast<float>(MaxObservableWorldCount) /  WorldCount : 1;

	ScrlBar1.InitializeScrollBar(Point(300, -Bkg_H * 0.5f), Point(310, -Bkg_H * 0.5f + 10), Point(40, Bkg_H), Point(20, (CountRatio) * Bkg_H), MousePos);
}

void ContinueScreen::Render()
{
	//Backgroudn Rec
	DrawRectangle(ScreenBackground.x, ScreenBackground.y, Bkg_W, Bkg_H, WHITE);
	
	if (WorldCount != 0) {
		for (auto& world : WorldList) { //Change it to Oberservable later
			if (!world.first.isObservable) continue; // remove this later
			DrawRectanglePro(world.first.rec, { 0,0 }, 0, GetColor(0x47bc90FF));
			DrawTextEx(F, world.second.c_str(), { world.first.rec.x + 10,world.first.rec.y + world.first.rec.height * 0.5f }, 20, 1, BLACK);
		}
	}
	else
	{
		DrawTextEx(F, "No Worlds added yet", { ScreenBackground.x + 10,ScreenBackground.y + ScreenBackground.height*0.05f }, 20, 1, RED);
	}
	ScrlBar1.UpdateMousePos(MousePos);
	ScrlBar1.Render();

}

int ContinueScreen::GetButtonInfo()
{
	if (CheckBoundingArea(MousePos, ScreenBackground)) {

		for (auto& world : WorldList) { //Change it to Oberservable later
			if (CheckBoundingArea(MousePos, world.first.rec)) {
				LocWorldName = world.second;
				return CONTINUE_BUTTON_ID;
			}
		}
	}
	else if (CheckBoundingArea(MousePos, ScrlBar1.track)) {
		return -1;
	}
	else {
		return BACK_BUTTON_ID;
	}
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

			ObservableRectangle world = ObservableRectangle(ScreenBackground.x + 5,  ScreenBackground.y + 5 + counter*100, ScreenBackground.width - 10, float(100 - 10),false);

			WorldList.push_back({ world,worldName });
			

			counter += 1;
			WorldCount = counter;
		}
	}
	std::cout << "TOTAL WORLD COUNT: " << WorldCount << std::endl;
	
}

ContinueScreen::ContinueScreen(Camera2D& cam)
{
	Cam = cam;
	InitializeButtons();
}
