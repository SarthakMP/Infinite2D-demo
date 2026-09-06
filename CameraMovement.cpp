#include"Headers/CameraMovement.h"


void CameraMovement::MoveCamera() {

	Vector2 PlayerPos = Vector2(Player::GetPlayerPos().x, -Player::GetPlayerPos().y);
	m_Camera->target = Vector2Lerp(m_Camera->target, PlayerPos,0.4f);
}

void CameraMovement::Update() {
	MoveCamera();
}

CameraMovement::CameraMovement(Camera2D& cam) {
	m_Camera = &cam;
}


