#include"Headers/GUI/Inventory.h"

void InventoryGUI::IntializeInventoryGUI()
{

	InventoryScreenGUI.width = Block_W;
	InventoryScreenGUI.height = Block_H;

	InventoryScreenGUI.x = ScrCenter.x - (Scr_W + Block_W) * 0.5f;
	InventoryScreenGUI.y = ScrCenter.y - Block_H*0.5f;

	ClickableArea.x = InventoryScreenGUI.x;
	ClickableArea.y = InventoryScreenGUI.y;

	ClickableArea.width = InventoryScreenGUI.width + PaddingX;
	ClickableArea.height = InventoryScreenGUI.height + PaddingY;


	BasePoint = Point(InventoryScreenGUI.x, InventoryScreenGUI.y);

}

void InventoryGUI::UpdateGUI() {

	
	int dx = ScrCenter.x - InventoryScreenGUI.x;
	int dy = -ScrCenter.y + InventoryScreenGUI.y;

	float dis = Point::Magnitude(ScrCenter, Point(InventoryScreenGUI.x, InventoryScreenGUI.y));
	if (dis > 0.0001f) {
		InventoryScreenGUI.x = static_cast<int>(std::lerp(static_cast<float>(InventoryScreenGUI.x), static_cast<float>(ScrCenter.x + BasePoint.x), 0.4f));

		//ClickableArea.x = static_cast<int>(std::lerp(static_cast<float>(ClickableArea.x), static_cast<float>(ScrCenter.x - ClickableArea.width * 0.5f - PaddingX), 0.4f));
	}
	else {
		InventoryScreenGUI.x = ScrCenter.x + static_cast<int>(BasePoint.x);
	}

	InventoryScreenGUI.y = -ScrCenter.y - Block_H * 0.5f;

	ClickableArea.x = ScrCenter.x - ClickableArea.width * 0.5f;
	ClickableArea.y = -ScrCenter.y + (Scr_H) * 0.5f - ClickableArea.height + PaddingY;
	
}

void InventoryGUI::RenderGUI() {
	Point pos = GUI::BoundingPointsPtr[2];

	DrawRectangleLines(InventoryScreenGUI.x, InventoryScreenGUI.y, InventoryScreenGUI.width, InventoryScreenGUI.height, YELLOW);
}
