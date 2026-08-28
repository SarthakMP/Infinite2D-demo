#include"Headers/Physics2D.h"
#include"Headers/Player.h"


std::shared_ptr<std::vector<BoxCollider2D>> NearBlocks;

int m_sign(float x) {
	return x >= 0 ? 1 : -1;
}

void  Physics2D::Update() {


#pragma region Attempt-3

	Player::SetIsGrounded(false);

	int CurrentChunkId = static_cast<int>(std::floor(static_cast<double>(Player::GetPlayerPos().x) / LevelDesigner::ChunksWidth));

	Point velocity = Player::GetVelocity();

	for (auto& chunk : LevelDesigner::ChunksArray) {
		BoxCollider2D playerBox = Player::GetHitBox();

		if (std::abs(chunk.Getid() - CurrentChunkId) > 1) { continue; }
		if (!chunk.Blocks) continue;

		for (auto it = chunk.Blocks->begin(); it != chunk.Blocks->end(); it++) {
			
			BoxCollider2D surfaceBox = it->second;

			float dx = playerBox.Origin.x - surfaceBox.Origin.x;
			float dy = playerBox.Origin.y - surfaceBox.Origin.y;
			
			float CombinedHalfHeight = (playerBox.Rec.height + surfaceBox.Rec.height) * 0.5f;
			float CombinedHalfWidth = (playerBox.Rec.width + surfaceBox.Rec.width) * 0.5f;
			
			if (std::abs(dy) < CombinedHalfHeight && std::abs(dx) < CombinedHalfWidth) {
				
				//DrawLine(playerBox.Origin.x, playerBox.Origin.y, surfaceBox.Origin.x, surfaceBox.Origin.y, RED);
				
				if (BoxCollider2D::CheckBoxCollision(playerBox, surfaceBox)) {

					float OverlapY = (CombinedHalfHeight - std::abs(dy)) - 0.01f;
					float OverlapX = (CombinedHalfWidth - std::abs(dx)) - 0.01f;

					if (OverlapY < OverlapX) {
						playerBox.Origin.y += (dy>0)? OverlapY : -OverlapY;
						if (dy > 0) Player::SetIsGrounded(true);
					}
					else{
						playerBox.Origin.x += (dx > 0) ? OverlapX : -OverlapX;
					}
					
					Player::UpdateHitbox();
					Player::SetPlayerPos(playerBox.Origin);
				}
			}

			

		}

	}
	
	

#pragma endregion

	Point Pos = Player::GetPlayerPos();
	if (Pos.y < -2000) {
		Pos.y = 0;
		Player::SetPlayerPos(Pos); // Set Spawn Point TODO Add a dynamic Spawn point 
	}
}