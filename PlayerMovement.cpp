#include"Headers/PlayerMovement.h"
#include<iostream>

Point m_abs(Point A) {
	return A.x < 0 || A.y < 0 ? -A : A;
}

void PlayerMovement::Move(Point& PlayerPos)
{
	int KeyVerticalPressed = IsKeyDown(KEY_W) == true ? 1 : IsKeyDown(KEY_S) == true ? -1 : 0;
	int KeyHorizontalPressed = IsKeyDown(KEY_D) == true ? 1 : IsKeyDown(KEY_A) == true ? -1 : 0;

	Point Vel = Point(KeyHorizontalPressed * PlayerSpeed, KeyVerticalPressed * PlayerSpeed);

	if (KeyHorizontalPressed != 0) {
		Player::SetVelocity(Vel);
		PlayerPos.x += Player::GetVelocity().x;
	}

	if (KeyVerticalPressed != 0) {

		Player::SetVelocity(Vel);
		PlayerPos.y += Player::GetVelocity().y;
	}
}
void PlayerMovement::AddCollisions(std::shared_ptr<Collision2D> col) {
	Collision.push(col);
}

void PlayerMovement::Update() {
	Point Ppos = Player::GetPlayerPos();
	Move(Ppos);
	Player::SetPlayerPos(Ppos);

	std::queue < std::shared_ptr<Collision2D>> temp = Collision;

	while (!temp.empty()) {

		Point Hit;

		BoxCollider2D playerBox = Player::GetHitBox();
		BoxCollider2D surfaceBox = temp.front()->GetHitBox();

		if (Collision2D::CheckBoxCollision(playerBox, surfaceBox, Hit)) {

			float dx = playerBox.Origin.x - surfaceBox.Origin.x;
			float dy = playerBox.Origin.y - surfaceBox.Origin.y;

			float overlapX = (playerBox.Rec.width + surfaceBox.Rec.width) * 0.5f - std::abs(dx);
			float overlapY = (playerBox.Rec.height + surfaceBox.Rec.height) * 0.5f - std::abs(dy);

			Point new_pos = Ppos;
			if (overlapX < overlapY) {
				if (dx > 0) {
					new_pos -= overlapX;
				}
				else {
					new_pos += overlapX;
				}
			}
			else {
				if (dy > 0) {
					new_pos -= overlapY;
				}
				else {
					new_pos += overlapY;
				}
			}

			Player::SetPlayerPos(new_pos);
		}

		temp.pop();
	}

}

void PlayerMovement::Render() {
	Point Ppos = Player::GetPlayerPos();
	/*
	std::queue < std::shared_ptr<Collision2D>> temp = Collision;
	while (!temp.empty()) {

		Point Surface_Origin = temp.front()->GetHitBoxOrigin();
		//DrawCircle(Surface_Origin.x, Surface_Origin.y, 10, GREEN);

		Ray2D Ray(Surface_Origin, Ppos + 50, GREEN);
		Ray.DrawRay2D();

		temp.pop();
	}
	*/
}

PlayerMovement::PlayerMovement() {

}