#include"Headers/GUI/Inventory.h"
#include <iostream>
void InventoryGUI::IntializeInventoryGUI()
{

	InventoryScreenGUI.width = Inventory_W;
	InventoryScreenGUI.height = Inventory_H;

	InventoryScreenGUI.x = ScrCenter.x - (Scr_W + Inventory_W) * 0.5f;
	InventoryScreenGUI.y = ScrCenter.y - Inventory_H *0.5f;

	ClickableArea.x = InventoryScreenGUI.x;
	ClickableArea.y = InventoryScreenGUI.y;

	ClickableArea.width = InventoryScreenGUI.width + PaddingX;
	ClickableArea.height = InventoryScreenGUI.height + PaddingY;


	BasePoint = Point(InventoryScreenGUI.x, InventoryScreenGUI.y);

	InventoryBlocks.assign(4, std::vector<std::pair<int,TexturedRectangle>>(10));

	float x = InventoryScreenGUI.x;
	float y = InventoryScreenGUI.y;
	
	TexturedRectangle Grass(x , y, InventoryBlockW, InventoryBlockH);
	BasePoints[0][0] = Point(Grass.rec.x, Grass.rec.y);
	
	TexturedRectangle Dirt(x + InventoryBlockW + BlockPaddingX*0.5f, y , InventoryBlockW, InventoryBlockH);
	BasePoints[0][1] = Point(Dirt.rec.x, Dirt.rec.y);
	TexturedRectangle Stone(x + 2 * (InventoryBlockW + BlockPaddingX * 0.5f), y, InventoryBlockW, InventoryBlockH);
	BasePoints[0][2] = Point(Stone.rec.x, Stone.rec.y);
	
	InventoryBlocks[0][0] = { 0,Grass};
	InventoryBlocks[0][1] = { 1,Grass};
	InventoryBlocks[0][2] = { 2,Grass};

}


int InventoryGUI::GetGuiId() {
	return id_Gui;
}

void InventoryGUI::OnMouseDownGUI(Vector2 in_MousePos) {


	Point WorldMousePos = { in_MousePos.x + ScrCenter.x ,-(-in_MousePos.y + ScrCenter.y) };

	if (!GUIHandler::CheckBoundingArea(WorldMousePos, ClickableArea)) return;

	if (GUIHandler::CheckBoundingArea(WorldMousePos, InventoryScreenGUI)) {
		//TODO Add the ability to click on the inventory icons and add them to the hotbar
		//Either by right clicking -> which find a firt empty slot in the hotbar
		//Or by pressing the key_one -> key_six ( which add block to the respective slot
		// Added the ability to drag & drop the block here




	}


	
}
void InventoryGUI::OnMouseHoverGUI(Vector2 in_MousePos) {

	Point WorldMousePos = { in_MousePos.x + ScrCenter.x ,-(-in_MousePos.y + ScrCenter.y) };
	int row_count = 0;
	for (auto& row : InventoryBlocks) {
		for (auto& block : row) {
			if (block.second.rec.height == 0) return;

			if (GUIHandler::CheckBoundingArea(WorldMousePos, block.second.rec)) {
				int key = GetKeyPressed();
				if (key >= KEY_ONE && key <= KEY_FIVE) {
					std::get<1>(HotbarGUI::HotbarSlots[key]).second = InventoryBlocks[row_count][block.first].second.texture;
				}
			}

		}
		row_count++;
	}

}



void InventoryGUI::UpdateGUI() {

	InventoryScreenGUI.x = ScrCenter.x + static_cast<int>(BasePoint.x);
	InventoryScreenGUI.y = -ScrCenter.y - Inventory_H * 0.5f;

	ClickableArea.x = ScrCenter.x - ClickableArea.width * 0.5f;
	ClickableArea.y = -ScrCenter.y - ClickableArea.height * 0.5f;

	int row_count = 0;
	for (auto& row : InventoryBlocks) {
		
		for (auto& [id, Textrec] : row) {
			Textrec.rec.x = ScrCenter.x + static_cast<int>(BasePoints[row_count][id].x) + BlockPaddingX;
			Textrec.rec.y = -ScrCenter.y - static_cast<int>(BasePoints[row_count][id].y) + BlockPaddingY;
		}
		row_count++;
	}
	
}

void InventoryGUI::RenderGUI() {
	Point pos = GUI::BoundingPointsPtr[2];

	DrawRectangleLines(ClickableArea.x, ClickableArea.y, ClickableArea.width, ClickableArea.height, GREEN);
	DrawRectangle(InventoryScreenGUI.x, InventoryScreenGUI.y, InventoryScreenGUI.width, InventoryScreenGUI.height, GRAY);

	for (auto& row : InventoryBlocks) {
		for (auto& [id,Textrec] : row) {
			DrawTexturePro(TexturesMap[id], Rectangle(0, 0, 32, 32), Textrec.rec, { 0,0 }, 0, WHITE);
		}
	}

}
