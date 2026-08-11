#include"Headers/Physics2D.h"
#include"Headers/Player.h"

constexpr float SLIGHT_OVERLAP_SLOP = 0.0f;


std::shared_ptr<std::vector<BoxCollider2D>> NearBlocks;
void  Physics2D::Update() {
	
	Point PlayerPos = Player::GetPlayerPos();

	int CurrentChunkId = static_cast<int>(std::floor(static_cast<double>(PlayerPos.x) / LevelDesigner::ChunksWidth));
	
	float MaxPushLeft=0, MaxPushRight=0, MaxPushUp=0, MaxPushDown = 0;

	bool isGrounded = false;

	for(auto& chunk : LevelDesigner::ChunksArray){
		
		if (std::abs(chunk.Getid() - CurrentChunkId) > 1) { continue; }
		if (!chunk.Blocks) continue;

		for (auto& surfaceBox : *chunk.Blocks) {



			Point currentPos = Player::GetPlayerPos();
			BoxCollider2D playerBox = Player::GetHitBox();
			BoxCollider2D blockBox = surfaceBox.GetHitBox();

			float dx = playerBox.Origin.x - surfaceBox.Origin.x;
			float dy = playerBox.Origin.y - surfaceBox.Origin.y;

			float combinedHalfWidth = (playerBox.Rec.width + blockBox.Rec.width) * 0.5f;
			float combinedHalfHeight = (playerBox.Rec.height + blockBox.Rec.height) * 0.5f;

			if (std::abs(dx) <= combinedHalfWidth + 10.0f  && std::abs(dy) <= combinedHalfHeight + 10.0f) {
				
								
				if (BoxCollider2D::CheckBoxCollision(playerBox, surfaceBox)) {

					float overlapX = (playerBox.Rec.width + surfaceBox.Rec.width) * 0.5f - std::abs(dx);
					float overlapY = (playerBox.Rec.height + surfaceBox.Rec.height) * 0.5f - std::abs(dy);

					if (overlapY <= overlapX || overlapY < SLIGHT_OVERLAP_SLOP) {
						if (dy > 0) {
							currentPos.y += overlapY * 0.51f;
						}
						else {
							currentPos.y -= overlapY * 0.51f;
						}

					}
					else {
						if (dx > 0) {
							currentPos.x += overlapX * 0.51f;
						}
						else {
							currentPos.x -= overlapX * 0.51f;
						}

					}
				}

				Player::SetIsGrounded(true);
				Player::SetPlayerPos(currentPos);
			}


		}

			
	}
	
	
}