#include"Headers/MenuScreen.h"

void Menu::InitializeButtons() {

	int Scr_W = GetScreenWidth(), Scr_H = GetScreenHeight();


	ContiuneButton = Rectangle(Scr_W, Scr_H + 200,100,100);
	StartNewButton = Rectangle(Scr_W, Scr_H - 200, 100, 100);

}

void Menu::DrawButtons()
{
	DrawRectangle(ContiuneButton.x + Cam.target.x, ContiuneButton.y + Cam.target.y, ContiuneButton.width, ContiuneButton.height, WHITE);
	DrawRectangle(StartNewButton.x + Cam.target.x, StartNewButton.y + Cam.target.y, StartNewButton.width, StartNewButton.height, WHITE);
}

int Menu::GetButtonInfo() {
	return 0;
}

void Menu::Update(){
}

void Menu::Start() {
	
}

void Menu::Render() {
	InitializeButtons();


}

Menu::Menu(Camera2D& WorldCamera) {
	Cam = WorldCamera;

}

Menu::~Menu()
{
}
