#include"Headers/Physics2D.h"
#include"Headers/Player.h"
void Physics2D::AddGravity(Point& Pos)
{
	Pos.y+= Gravity;
}

void Physics2D::Update() {
	Point PlayerPos = Player::GetPlayerPos();
	std::cout << PlayerPos << std::endl;
	AddGravity(PlayerPos);
	Player::SetPlayerPos(PlayerPos);

}

void Physics2D::Start()
{


}