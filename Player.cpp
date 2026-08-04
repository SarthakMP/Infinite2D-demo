#include"Headers/Player.h"

void Player::SetPlayerPos(Point& pos) {
	Player_Pos = pos;
}
Point Player::GetPlayerPos() {
	return Player_Pos;
}
void Player::SetVelocity(Point& vel)
{
	Player_Vel = vel;
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
	DrawRectangle(Player_Pos.x - 50, Player_Pos.y - 50, 100, 100, WHITE);
}

void Player::Start(){
	Point Zero(0, 0);
	SetPlayerPos(Zero);
}

void Player::Update(){
	DrawPlayer();
}