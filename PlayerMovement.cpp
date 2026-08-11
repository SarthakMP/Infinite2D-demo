#include"Headers/PlayerMovement.h"
#include"Headers/LevelDesigner.h"
Point m_abs(Point A) {
	return A.x < 0 || A.y < 0 ? -A : A;
}

void PlayerMovement::Move()
{
	Point PlayerPos = Player::GetPlayerPos();
	Point Vel = Player::GetVelocity();
	
	

	int KeyHorizontalPressed = IsKeyDown(KEY_D) == true ? 1 : IsKeyDown(KEY_A) == true ? -1 : 0;

	const float deAcc = 25.0f;
	const float MaxSpeed = 5.0f;
	const float MaxFallingSpeed = 20.0f;

	Point Acc = Point(KeyHorizontalPressed * PlayerSpeed, Physics2D::Gravity.y * deltatime);
	
	if (!Player::GetIsGrounded())
		Vel.y += Acc.y;
	else
		Vel.y = 0;

	if (KeyHorizontalPressed != 0) {
		Vel.x += Acc.x * deltatime;
	}
	else {
		if (Vel.x > 0) {
			Vel.x -= deAcc * deltatime;
			if (Vel.x < 0) Vel.x =0;
		}
		else if(Vel.x < 0) {
			Vel.x += deAcc * deltatime;
			if (Vel.x > 0) Vel.x = 0;
		}
	}

	
	Vel.x = std::clamp(Vel.x, -MaxSpeed, MaxSpeed);
	Vel.y = std::clamp(Vel.y , -MaxFallingSpeed, MaxSpeed);
	
	PlayerPos.x += Vel.x;
	PlayerPos.y += Vel.y;

	Player::SetVelocity(Vel);
	Player::SetPlayerPos(PlayerPos);

}


void  PlayerMovement::Update() {


	Move();

	Physics2D::Update();

}

void PlayerMovement::OnMouseDown() {

}

void PlayerMovement::Render() {
	
}

PlayerMovement::PlayerMovement() {

}