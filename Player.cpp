#include"Headers/Player.h"

void Player::SetPlayerPos(Vector2 pos) {
	Player_Pos = pos;
}
Vector2 Player::GetPlayerPos() {
	return Player_Pos;
}
void Player::SetPlayerTexture(Texture2D text) {
	Player_texture = text;
}

void Player::DrawPlayer() {
	//DEBUG ONLY
	DrawRectangle(Player_Pos.x, Player_Pos.y, 100, 100, WHITE);
}

void Player::Start(){
	SetPlayerPos(Vector2Zero());
}

void Player::Update(){
	DrawPlayer();
}