#include"Headers/GUI/Hotbar.h"


int  HotbarGUI::GetButtonInfo() {
	for (int i = 0; i < 6; i++) {
		Rectangle& rec = HotbarSlots[i];
		if (CheckBoundingArea(MousePos, rec)) {
			return i;
		}
	}

}

void HotbarGUI::InitializeSlots()
{
	
	Point base = GUI::BoundingPointsPtr[2];
	
	int offset = 3;
	for (int i = -offset; i < offset; i++) {
		int x = base.x +  i * Block_W;
		int y = base.y - Scr_H * 0.5f;

		Rectangle slot = Rectangle(x, y, Block_W - 10, Block_H - 10);
		HotbarSlots[i + offset] = slot;
		BasePos[i + offset] = Point(slot.x, slot.y);
	}
	
}


void HotbarGUI::UpdateGUI() {
	// update the position of GUI wrt to Camera
	Point pos = GUI::BoundingPointsPtr[2];

	int count = 0;
	for (auto& rec : HotbarSlots) {

		int dx = pos.x - rec.x;
		int dy = pos.y - rec.y;

		float dis = Point::Magnitude(pos,Point(rec.x,rec.y));
		if (dis > 0.0001f) {
			rec.x = static_cast<int>(std::lerp(static_cast<float>(rec.x), static_cast<float>(pos.x + BasePos[count].x), 0.4f));
		}
		else {
			rec.x = pos.x + static_cast<int>(BasePos[count].x);
		}

		rec.y = pos.y;
	
		std::cout <<"id: "<<count <<":" << rec.x << "," << rec.y << std::endl;

		count++;
	}
	std::cout << std::endl;
}

void HotbarGUI::DrawGUI(){


}

void HotbarGUI::RenderGUI() {
	for (auto& rec : HotbarSlots) {
		DrawRectangle(rec.x, rec.y, rec.width, rec.height, RED);
	}
}