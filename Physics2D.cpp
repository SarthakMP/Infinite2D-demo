#include"Headers/Physics2D.h"
#include"Headers/Player.h"
void Physics2D::AddGravity(Point& Pos)
{
	Pos.x += Gravity;
}

void Physics2D::Update() {
	Point PlayerPos = Player::GetPlayerPos();
	std::cout << PlayerPos << std::endl;
}

void Physics2D::Start()
{


}