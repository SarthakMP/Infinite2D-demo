#include"Headers/MenuScreen.h"

void Menu::InitializeButtons() {

	int Scr_W = GetScreenWidth(), Scr_H = GetScreenHeight();


	ContiuneButton = Rectangle(Cam.target.x - 250, Cam.target.y - 200, 500, 100);
	StartNewButton = Rectangle(Cam.target.x - 250, Cam.target.y + 200, 500, 100);

}
Font f; 
void Menu::DrawButtons()
{
	DrawRectangle(ContiuneButton.x, ContiuneButton.y, ContiuneButton.width, ContiuneButton.height, WHITE);
	DrawTextPro(f, "Continue", { ContiuneButton.x + 110, ContiuneButton.y  + 25}, { 0,0 }, 0, 80, 1, RED);
	DrawRectangle(StartNewButton.x, StartNewButton.y, StartNewButton.width, StartNewButton.height, WHITE);
	DrawTextPro(f, "Start New", { StartNewButton.x + 110, StartNewButton.y + 25 }, { 0,0 }, 0, 80, 1, RED);

}

bool CheckBoundingArea(const Point& pos, const Rectangle& rec) {
	return (pos.x >= rec.x) &&
		(pos.x <= rec.x + rec.width) &&
		(pos.y >= rec.y) &&
		(pos.y <= rec.y + rec.height);
}

int Menu::GetButtonInfo() {
	int Scr_W = GetScreenWidth(), Scr_H = GetScreenHeight();
	Point MousePos = Point(GetMousePosition().x - Scr_W/2, (GetMousePosition().y - Scr_H/2));

	if (CheckBoundingArea(MousePos, ContiuneButton)) { 
		return -1; 
	}	

	if (CheckBoundingArea(MousePos, StartNewButton)){	
		return 1;
	}
	return 0;
}

void Menu::Update(){
}

void Menu::Start() {

}

void Menu::Render() {
}

Menu::Menu(Camera2D& WorldCamera) {
	Cam = WorldCamera;
	InitializeButtons();
}

Menu::~Menu()
{
}
