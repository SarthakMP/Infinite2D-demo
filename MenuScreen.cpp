#include"Headers/MenuScreen.h"

void Menu::InitializeButtons() {

	int Scr_W = GetScreenWidth(), Scr_H = GetScreenHeight();


	ContiuneButton = Rectangle(Scr_W, Scr_H + 200,100,100);
	StartNewButton = Rectangle(Scr_W, Scr_H - 200, 100, 100);

}

void Menu::DrawButtons()
{
	DrawRectangle(ContiuneButton.x, ContiuneButton.y, ContiuneButton.width, ContiuneButton.height, WHITE);
	DrawRectangle(StartNewButton.x, StartNewButton.y, StartNewButton.width, StartNewButton.height, WHITE);
}



void Menu::Update(){
}

void Menu::Start() {
	InitializeButtons();
}

void Menu::Render() {

}

Menu::Menu() {


}

Menu::~Menu()
{
}
