#include"Headers/Physics2D.h"
#include"Headers/Player.h"


void Physics2D::AddGravity(Point& Pos)
{
	Pos.y+= Gravity;
}

float GroundCheckMul = 1.0f;
void  Physics2D::Update() {
	
	Point PlayerPos = Player::GetPlayerPos();
	Chunk chunk = LevelDesigner::ChunksArray[3];
	Point Playervel = Player::GetVelocity();
	BoxCollider2D playerBox = Player::GetHitBox();
	//TODO Get the Nearest Block from the player position of the chunk;

	std::shared_ptr<std::vector<BoxCollider2D>> NearBlocks;
	for (auto& surfaceBox : *chunk.Blocks) {

		DrawRectangleLines(surfaceBox.GetHitBox().x, surfaceBox.GetHitBox().y, surfaceBox.GetHitBox().width, surfaceBox.GetHitBox().height, GREEN);
		
		if (BoxCollider2D::CheckBoxCollision(playerBox, surfaceBox.GetHitBox())) {
			Point new_pos = PlayerPos;
			float dx = playerBox.Origin.x - surfaceBox.Origin.x;
			float dy = playerBox.Origin.y - surfaceBox.Origin.y;

			float overlapX = (playerBox.Rec.width + surfaceBox.Rec.width) * 0.5f - std::abs(dx);
			float overlapY = (playerBox.Rec.height + surfaceBox.Rec.height) * 0.5f - std::abs(dy);

			if (overlapX < overlapY) {

				if (dx > 0) {
					new_pos.x += overlapX * GroundCheckMul;
				}
				else {
					new_pos.x -= overlapX * GroundCheckMul;
				}

			}
			else {

				if (dy > 0) {
					new_pos.y += overlapY * GroundCheckMul;
				}
				else {
					new_pos.y -= overlapY * GroundCheckMul;
				}

			}
			Player::SetPlayerPos(new_pos);
		}

	}

}