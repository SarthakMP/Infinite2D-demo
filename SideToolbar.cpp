#include"Headers/GUI/SideToolbar.h"


void SideToolbarGUI::InitializeSlots() {

	Point Center = ScrCenter;

	for (int j = 0; j < 2; j++) {
		int x = Center.x + Scr_W*0.5f;
		int y = j * Block_H - 50;

		Rectangle rec = Rectangle(x,y, Block_W, Block_H - 10);
		SideToolGUISlots[j] = { rec,WHITE };
		BasePos[j] = Point(rec.x, rec.y);

	}

	int W = Block_W + 2 * PaddingX;
	int H = 2 * Block_H  + 2 * PaddingY;
	int X = ScrCenter.x;
	int Y = ScrCenter.y;
	ClickableArea = Rectangle(X, Y, W, H);
}

void SideToolbarGUI::OnMouseDownGUI(Vector2 MousePos)
{
	Point WorldMousePos = { MousePos.x + ScrCenter.x ,-(-MousePos.y + ScrCenter.y) };
	if (!GUIHandler::CheckBoundingArea(WorldMousePos, ClickableArea)) return;

	int count = 0;
	//Convert screen coords to worldCoords wrt to LocCam pos
	for (auto& [rec, color] : SideToolGUISlots) {

		if (GUIHandler::CheckBoundingArea(WorldMousePos, rec)) {
			std::cout << "Clicked on: " << count << " Slot" << std::endl;
		}

		count++;
	}
}

void SideToolbarGUI::UpdateGUI() {

	int count = 0;
	for (auto& [rec, color] : SideToolGUISlots) {

		int dx = ScrCenter.x - rec.x;
		int dy = -ScrCenter.y + rec.y;

		float dis = Point::Magnitude(ScrCenter, Point(rec.x, rec.y));

		if (dis > 0.0001f) {
			rec.y = static_cast<int>(std::lerp(static_cast<float>(rec.y), static_cast<float>(-ScrCenter.y + BasePos[count].y), 0.4f));
			
		}
		else {
			rec.y = ScrCenter.y + static_cast<int>(BasePos[count].y);
		}

		rec.x  = ScrCenter.x - Scr_W * 0.5f;

		ClickableArea.x = ScrCenter.x - (Scr_W + ClickableArea.width - 2*PaddingX) * 0.5f;
		ClickableArea.y = -ScrCenter.y - (ClickableArea.height + PaddingY) * 0.5f;
		count++;
	}

}

void SideToolbarGUI::RenderGUI() {
	
	for (auto& [rec, color] : SideToolGUISlots) {
		DrawRectangle(rec.x, rec.y, rec.width, rec.height, color);
	}

	DrawRectangleLines(ClickableArea.x, ClickableArea.y, ClickableArea.width, ClickableArea.height,GREEN);
}