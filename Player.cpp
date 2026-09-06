#include"Headers/Player.h"

void Player::SetIsGrounded(bool val)
{
	isGrounded = val;
}

bool Player::GetIsGrounded()
{
	return isGrounded;
}

void Player::SetPlayerPos(const Point& pos) {
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

void Player::UpdateHitbox()
{
	HitBox.Origin = Player_Pos;

	HitBox.Rec.y = Player_Pos.y - (hitbox_h * 0.5f);
	HitBox.Rec.x = Player_Pos.x - (hitbox_w * 0.5f);
}


BoxCollider2D Player::GetHitBox()
{
	return HitBox;
}

void Player::SetWorldName(std::string& WorldName)
{
	LocWorldName = WorldName;
}

void Player::DrawPlayer() {
	//DEBUG ONLY
	//DrawCircle(Player::GetHitBox().Origin.x, Player::GetHitBox().Origin.y, 10, RED);
	DrawRectangleLines(Player::GetHitBox().Rec.x, Player::GetHitBox().Rec.y, Player::GetHitBox().Rec.height, Player::GetHitBox().Rec.width, GREEN);

	DrawRectangle(Player::GetHitBox().Rec.x, Player::GetHitBox().Rec.y, Player::GetHitBox().Rec.height, Player::GetHitBox().Rec.width, WHITE);

}

void Player::Start(){
	hitbox_h = 100;
	hitbox_w = 100;

	Point Zero(0, 500);
	SetPlayerPos(Zero);

	HitBox.Rec.height = hitbox_h;
	HitBox.Rec.width = hitbox_w;
	
	HitBox.Origin = Player_Pos;

	HitBox.Rec.y = HitBox.Origin.y - (hitbox_h * 0.5f);
	HitBox.Rec.x = HitBox.Origin.x - (hitbox_w * 0.5f);
}

void Player::Update(){
	Player_Pos.y += Player_Vel.y * deltatime;
	Player_Pos.x += Player_Vel.x * deltatime;
	UpdateHitbox();
}

void Player::Render() {
	DrawPlayer();
}



void Player::serialize(std::ofstream& out) {

	out.write(reinterpret_cast<const char*>(&Player_Pos), sizeof(Player_Pos));

}

void Player::deserialize(std::ifstream& in) {

	in.read(reinterpret_cast<char*>(&Player_Pos), sizeof(Player_Pos));

}

void Player::Save() {

	if (basePlayersPath.empty() || LocWorldName.empty()) {
		return;
	}

	basePlayersPath = std::string(WORLD_DIR) + '/' + LocWorldName + "/Player/";
	std::string path = basePlayersPath + "Player_Info.dat";
	
	std::error_code ec;
	std::filesystem::create_directories(basePlayersPath, ec);
	if (ec) {
		std::cout << "ERROR: " << ec << std::endl;
		return;
	}
	std::ofstream outFile(path, std::ios::binary);

	if (!outFile.is_open() || !outFile.good()) {
		return;
	}

	serialize(outFile);

}


Player::Player() {
	hitbox_h = 100;
	hitbox_w = 100;
}


