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
		
		Point RelativeDistance = Point(MousePos.x - GetScreenWidth() * 0.5f, -(MousePos.y - GetScreenHeight() *0.5f)) + PlayerPos;
		
		
		int CurrentChunkId = static_cast<int>(std::floor(static_cast<double>(RelativeDistance.x) / LevelDesigner::ChunksWidth));
		
		for (auto& chunk : LevelDesigner::ChunksArray) {
			
			
			if (chunk.Getid() != CurrentChunkId) { continue; }

			// This Relative distance should be taken from the Curr chunk
			Point RelativeChunkDistance = Point(RelativeDistance.x - chunk.GetXY().x , RelativeDistance.y - chunk.GetXY().y);


			float x = std::floor(std::abs(RelativeChunkDistance.x * 0.01f));
			float y = std::floor(std::abs(RelativeChunkDistance.y * 0.01f));


			DrawCircle(x, y, 10, RED);

			if ((x < 0 || x>3) || (y < 0 || y>7)) return;

			//BoxCollider2D& block = chunk.Blocks->at(x + 4*y);
			chunk.Blocks->erase(x + 4 * y);
			chunk.isDirty = true;
		}
		
	}

}

BlockModifier::BlockModifier(Camera2D& cam)
{
	LocCam = cam;
	zoom = 1 / LocCam.zoom;
}

