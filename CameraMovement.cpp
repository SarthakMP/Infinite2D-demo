#include"Headers/CameraMovement.h"


void CameraMovement::MoveCamera() {

	Vector2 PlayerPos = Vector2(Player::GetPlayerPos().x, -Player::GetPlayerPos().y);
	m_Camera->target = PlayerPos;

}



void CameraMovement::Update() {
	MoveCamera();
}

CameraMovement::CameraMovement(Camera2D& cam) {
		m_Camera = &cam;
}


