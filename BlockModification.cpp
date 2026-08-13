#include"Headers/BlockModification.h"

void BlockModifier::Start() {

}

void BlockModifier::Update() {

}

void BlockModifier::OnMouseDown() {
	Point PlayerPos = Player::GetPlayerPos();
	Point MousePos = GetMousePosition();
	bool isInside = (MousePos.x >= 0 && MousePos.x <= GetScreenWidth()) &&
		(MousePos.y >= 0 && MousePos.y <= GetScreenHeight());

	if (isInside) {
		
		Point RelativeDistance = Point(MousePos.x - GetScreenWidth() / 2, -(MousePos.y - GetScreenHeight() / 2)) + PlayerPos;

		int CurrentChunkId = static_cast<int>(std::floor(static_cast<double>(RelativeDistance.x) / LevelDesigner::ChunksWidth));
		
		for (auto& chunk : LevelDesigner::ChunksArray) {
			
			if (chunk.Getid() != CurrentChunkId) { continue; }

			// This Relative distance should be taken from the Curr chunk
			Point RelativeChunkDistance = Point(chunk.GetXY().x - RelativeDistance.x, chunk.GetXY().y - RelativeDistance.y );

			float x = std::floor(std::abs(RelativeChunkDistance.x * 0.01f));
			float y = std::floor(std::abs(RelativeChunkDistance.y * 0.01f));

			if ((x < 0 || x>3) || (y < 0 || y>7)) return;

			BoxCollider2D& block = chunk.Blocks->at(x + 4*y);
			
		}
		
	}

}

