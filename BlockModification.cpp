#include"Headers/BlockModification.h"

void BlockModifier::Start() {

}

void BlockModifier::Update() {

}

void BlockModifier::OnMouseDown() {
	Point PlayerPos = Player::GetPlayerPos();
	Point MousePos = GetMousePosition();
	bool isInside = (MousePos.x >= 50 && MousePos.x <= (GetScreenWidth() - 50)) &&
					(MousePos.y >= 50 && MousePos.y <= GetScreenHeight() - 50);

	if (isInside) {
		
		Point RelativeDistance = Point(MousePos.x - GetScreenWidth() * 0.5f, -(MousePos.y - GetScreenHeight() *0.5f)) + PlayerPos;
		
		
		int CurrentChunkId = static_cast<int>(std::floor(static_cast<double>(RelativeDistance.x) / LevelDesigner::ChunksWidth));
		
		for (auto& chunk : LevelDesigner::ChunksArray) {

			if (chunk.Getid() != CurrentChunkId) { continue; }

			// This Relative distance should be taken from the Curr chunk
			Point RelativeChunkDistance = Point(RelativeDistance.x - chunk.GetXY().x , RelativeDistance.y - chunk.GetXY().y);


			float x = std::floor(std::abs(RelativeChunkDistance.x * 0.01f));
			float y = std::floor(std::abs(RelativeChunkDistance.y * 0.01f));

			if ((x < 0 || x>3) // 0-3 chunks X space (index)
				|| (y < 0 || y>64)) return; // 0-64 chunks Y space (index)

			//BoxCollider2D& block = chunk.Blocks->at(x + 4*y);

			std::cout << x + 4 * y << std::endl;
			chunk.Blocks->erase(x + 4 * y);
			chunk.isDirty = true;
		}
		
	}

}

void BlockModifier::OnMouse2Down() {
	Point PlayerPos = Player::GetPlayerPos();
	Point MousePos = GetMousePosition();
	bool isInside = (MousePos.x >= 50 && MousePos.x <= (GetScreenWidth() - 50)) &&
					(MousePos.y >= 50 && MousePos.y <= GetScreenHeight() - 50);

	if (isInside) {

		Point RelativeDistance = Point(MousePos.x - GetScreenWidth() * 0.5f, -(MousePos.y - GetScreenHeight() * 0.5f)) + PlayerPos;
		int CurrentChunkId = static_cast<int>(std::floor(static_cast<double>(RelativeDistance.x) / LevelDesigner::ChunksWidth));

		for (auto& chunk : LevelDesigner::ChunksArray) {

			if (chunk.Getid() != CurrentChunkId) { continue; }

			// This Relative distance should be taken from the Curr chunk
			Point RelativeChunkDistance = Point(RelativeDistance.x - chunk.GetXY().x, RelativeDistance.y - chunk.GetXY().y);

			float x = std::floor(std::abs(RelativeChunkDistance.x * 0.01f));
			float y = std::floor(std::abs(RelativeChunkDistance.y * 0.01f));

			int id = x + 4 * y;

			if (chunk.Blocks->find(id) == chunk.Blocks->end()) {
				int block_x = chunk.GetXY().x + x * LevelDesigner::block_w;
				int block_y = chunk.GetXY().y + y * LevelDesigner::block_h;
				BoxCollider2D block(Rectangle(block_x, block_y, LevelDesigner::block_w, LevelDesigner::block_h), WHITE);
				block.id = id;
				(*chunk.Blocks)[block.id] = block;
				//std::cout <<"Current Player Pos: "<<PlayerPos<< " Block ADDED at: " << block_x << "," << block_y << std::endl;
			}

		}
		
	}

}

BlockModifier::BlockModifier(Camera2D& cam)
{
	LocCam = cam;
	zoom = 1 / LocCam.zoom;
}

