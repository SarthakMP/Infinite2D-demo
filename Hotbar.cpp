#include"Headers/GUI/Hotbar.h"

void HotbarGUI::InitializeSlots()
{

	Point Center = ScrCenter;
	
	int offset = 3;
	for (int i = -offset; i < offset; i++) {
		int h = Block_H - 10;
		int w = Block_W - 10;
		
		int x = i * Block_W;
		int y = ScrCenter.y - Scr_H - Block_H;

		Rectangle slot = Rectangle(x, y, w, h);
		HotbarSlots[i + offset] = { slot,WHITE};
		BasePos[i + offset] = Point(slot.x, slot.y);
	}

	int H = Block_H + PaddingY * 2;
	int W = Block_W * 6 + PaddingX * 2;
	int X = ScrCenter.x;
	int Y = -ScrCenter.y;

	ClickableArea = Rectangle(X,Y ,W ,H );
}


void HotbarGUI::OnMouseDownGUI(Vector2 MousePos) {
	Point WorldMousePos = { MousePos.x + ScrCenter.x ,-(-MousePos.y + ScrCenter.y) };
	if (GUIHandler::CheckBoundingArea(WorldMousePos, ClickableArea) == false)return;

	int count = 0;
	//Convert screen coords to worldCoords wrt to LocCam pos
	for (auto& [rec, color] : HotbarSlots) {

		if (GUIHandler::CheckBoundingArea(WorldMousePos, rec)) {
			std::cout << "Clicked on: " << count << " Slot" << std::endl;
		}

		count++;
	}
	
}


void HotbarGUI::UpdateGUI() {
	// update the position of GUI wrt to Camera
	
	int count = 0;
	for (auto& [rec,color] : HotbarSlots) {

		int dx = ScrCenter.x - rec.x;
		int dy = -ScrCenter.y + rec.y;

		float dis = Point::Magnitude(ScrCenter,Point(rec.x,rec.y));
		if (dis > 0.0001f) {
			rec.x = static_cast<int>(std::lerp(static_cast<float>(rec.x), static_cast<float>(ScrCenter.x + BasePos[count].x), 0.4f));
			
			//ClickableArea.x = static_cast<int>(std::lerp(static_cast<float>(ClickableArea.x), static_cast<float>(ScrCenter.x - ClickableArea.width * 0.5f - PaddingX), 0.4f));
		}
		else {
			rec.x = ScrCenter.x + static_cast<int>(BasePos[count].x);
		}

		rec.y = -ScrCenter.y - Block_H + Scr_H*0.5f ;

		ClickableArea.x = ScrCenter.x - ClickableArea.width * 0.5f;
		ClickableArea.y = -ScrCenter.y  + ( Scr_H) * 0.5f - ClickableArea.height +PaddingY;
		count++;
	}
	
}

void HotbarGUI::RenderGUI() {
	Point pos = GUI::BoundingPointsPtr[2];

	DrawRectangleLines(ClickableArea.x, ClickableArea.y, ClickableArea.width, ClickableArea.height, GREEN);

	for (auto& [rec, color] : HotbarSlots) {
		DrawRectangle(rec.x, rec.y, rec.width, rec.height, color);
	}

}