#include"Headers/Physics2D.h"
#include"Headers/Player.h"


std::shared_ptr<std::vector<BoxCollider2D>> NearBlocks;

int m_sign(float x) {
	return x >= 0 ? 1 : -1;
}

Point tmpPos = 0;
void  Physics2D::Update() {

#pragma region Attempt-3

	Player::SetIsGrounded(false);

	int CurrentChunkId = static_cast<int>(std::floor(static_cast<double>(Player::GetPlayerPos().x) / LevelDesigner::ChunksWidth));
 
	Point velocity = Player::GetVelocity();

	for (auto& chunk : LevelDesigner::ChunksArray) {

		if (std::abs(chunk.Getid() - CurrentChunkId) > 1) { continue; }
		if (!chunk.Blocks) continue;

		

		for (auto it = chunk.Blocks->begin(); it != chunk.Blocks->end(); it++) {

			BoxCollider2D playerBox = Player::GetHitBox();
			BoxCollider2D surfaceBox = it->second;

			//Check only for block under a threshold

			float dis = Point::Magnitude(surfaceBox.Origin, playerBox.Origin);

			if (dis > (playerBox.GetHitBox().height + surfaceBox.GetHitBox().height * 0.5f)) continue;
			//DrawLine(playerBox.Origin.x, playerBox.Origin.y, surfaceBox.Origin.x, surfaceBox.Origin.y, RED);
			
			float dx = playerBox.Origin.x - surfaceBox.Origin.x;
			float dy = playerBox.Origin.y - surfaceBox.Origin.y;


			float CombinedHalfHeight = (playerBox.Rec.height + surfaceBox.Rec.height) * 0.5f;
			float CombinedHalfWidth = (playerBox.Rec.width + surfaceBox.Rec.width) * 0.5f;

			if (std::abs(dy) < CombinedHalfHeight && std::abs(dx) < CombinedHalfWidth) {

				if (BoxCollider2D::CheckBoxCollision(playerBox, surfaceBox)) {
					float OverlapY = (CombinedHalfHeight - std::abs(dy));
					float OverlapX = (CombinedHalfWidth - std::abs(dx));
					if (OverlapY < OverlapX) {
						if (dy > 0) {

							playerBox.Origin.y += OverlapY;
							Player::SetIsGrounded(true);
						}
						else {
							playerBox.Origin.y -= OverlapY;
						}
						velocity.y = 0;
					}

					Player::SetPlayerPos(playerBox.Origin);
					Player::UpdateHitbox();

					if(OverlapX < OverlapY){
						if (dx > 0) {
							playerBox.Origin.x += OverlapX;
						}

						else {
							playerBox.Origin.x -= OverlapX;
						}
						velocity.x = 0;
					}
					Player::SetPlayerPos(playerBox.Origin);
					Player::UpdateHitbox();
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