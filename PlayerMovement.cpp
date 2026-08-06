#include"Headers/PlayerMovement.h"
#include"Headers/LevelDesigner.h"
Point m_abs(Point A) {
	return A.x < 0 || A.y < 0 ? -A : A;
}

void PlayerMovement::Move(Point& PlayerPos)
{
	int KeyVerticalPressed = IsKeyDown(KEY_W) == true ? 1 : IsKeyDown(KEY_S) == true ? -1 : 0;
	int KeyHorizontalPressed = IsKeyDown(KEY_D) == true ? 1 : IsKeyDown(KEY_A) == true ? -1 : 0;

	float deAcc = 25.0f;
	float MaxSpeed = 5.0f;

	Point Acc = Point(KeyHorizontalPressed * PlayerSpeed, KeyVerticalPressed * PlayerSpeed);
	Point Vel = Player::GetVelocity();
	if (KeyHorizontalPressed != 0) {
		Vel.x += Acc.x * deltatime;
	}
	else {
		if (Vel.x > 0) {
			Vel.x -= deAcc * deltatime;
			if (Vel.x < 0) Vel.x = 0;
		}
		else if(Vel.x < 0) {
			Vel.x += deAcc * deltatime;
			if (Vel.x > 0) Vel.x = 0;
		}
	}

	if (KeyVerticalPressed != 0) {
		Vel.y += Acc.y * deltatime;
	}
	else {
		if (Vel.y > 0) {
			Vel.y -= deAcc * deltatime;
			if (Vel.y < 0) Vel.y = 0;
		}
		else if (Vel.y < 0) {
			Vel.y += deAcc * deltatime;
			if (Vel.y > 0) Vel.y = 0;
		}
	}
	Vel.x = std::clamp(Vel.x, -MaxSpeed, MaxSpeed);
	Vel.y = std::clamp(Vel.y, -MaxSpeed, MaxSpeed);

	Player::SetVelocity(Vel);

	PlayerPos.x += Player::GetVelocity().x;
	PlayerPos.y += Player::GetVelocity().y;
}


void  PlayerMovement::Update() {
	Point PlayerPos = Player::GetPlayerPos();
	Move(PlayerPos);
	Player::SetPlayerPos(PlayerPos);
	
	Physics2D::Update();

	
}

void PlayerMovement::OnMouseDown() {
	Point MousePos = GetMousePosition();
	std::cout << MousePos/100 << std::endl;
}

void PlayerMovement::Render() {
	
}

PlayerMovement::PlayerMovement() {

}