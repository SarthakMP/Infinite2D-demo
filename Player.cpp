#include"Headers/Player.h"

void Player::SetPlayerPos(Point& pos) {
	Player_Pos = pos;
}

Point Player::GetPlayerPos() {
	return Player_Pos;
}

void Player::SetVelocity(const Point& vel)
{
	Player_Vel = vel;
}
void Player::SetVelocity(float x_in, float y_in)
{
	Player_Vel = Point(x_in,y_in);
}

Point Player::GetVelocity()
{
	return Player_Vel;
}


BoxCollider2D Player::GetHitBox()
{
	return HitBox;
}

void Player::DrawPlayer() {
	//DEBUG ONLY
	DrawCircle(Player::GetHitBox().Origin.x, Player::GetHitBox().Origin.y, 10, RED);
	DrawRectangle(Player_Pos.x - 50, Player_Pos.y - 50, 100, 100, WHITE);
	DrawRectangleLines(Player::GetHitBox().Rec.x, Player::GetHitBox().Rec.y - 50, Player::GetHitBox().Rec.height, Player::GetHitBox().Rec.width, GREEN);
}

void Player::Start(){
	Point Zero(0, 0);
	SetPlayerPos(Zero);

	HitBox.Rec.height = hitbox_h;
	HitBox.Rec.width = hitbox_w;
	
	HitBox.Origin.y = Player_Pos.y;
	HitBox.Origin.x = Player_Pos.x;

	HitBox.Rec.y = HitBox.Origin.y;
	HitBox.Rec.x = HitBox.Origin.x - hitbox_w * 0.5f;
}

void Player::Update(){
	HitBox.Origin.y = Player_Pos.y;
	HitBox.Origin.x = Player_Pos.x;

	HitBox.Rec.y = HitBox.Origin.y;
	HitBox.Rec.x = HitBox.Origin.x - hitbox_w * 0.5f;

	Player_Pos.y += Player_Vel.y * deltatime;
	Player_Pos.x += Player_Vel.x * deltatime;
}

void Player::Render() {
	DrawPlayer();
}

