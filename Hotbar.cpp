#include"Headers/GUI/Hotbar.h"

//int  HotbarGUI::GetButtonInfo(const Rectangle& rec,const Point& Pos,const int i) {
//
//}

void HotbarGUI::InitializeSlots()
{
	
	Point base = GUI::BoundingPointsPtr[2];
	
	int offset = 3;
	for (int i = -offset; i < offset; i++) {
		int x = base.x +  i * Block_W;
		int y = base.y - Scr_H * 0.5f;

		Rectangle slot = Rectangle(x, y, Block_W - 10, Block_H - 10);
		HotbarSlots[i + offset] = { slot,WHITE};
		BasePos[i + offset] = Point(slot.x, slot.y);
	}
	
}


void HotbarGUI::OnMouseDownGUI(Vector2 MousePos) {

	int count = 0;
	//Convert screen coords to worldCoords wrt to LocCam pos
	for (auto& [rec, color] : HotbarSlots) {

		Point WorldMousePos = { MousePos.x + ScrCenter.x ,-(-MousePos.y + ScrCenter.y) };

		if (CheckBoundingArea(WorldMousePos, rec)) {
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
		}
		else {
			rec.x = ScrCenter.x + static_cast<int>(BasePos[count].x);
		}

		rec.y = -ScrCenter.y - Block_H + Scr_H*0.5f ;
		
		count++;
		DrawRectangle(rec.x, rec.y, rec.width, rec.height, color);
	}
	
}

void HotbarGUI::RenderGUI() {
	Point pos = GUI::BoundingPointsPtr[2];

	//DrawCircle(pos.x, -pos.y, 100, RED);
	/*
	for (auto& [rec, color] : HotbarSlots) {
		DrawRectangle(rec.x, rec.y, rec.width, rec.height, color);
	}
	*/
}