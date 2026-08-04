#include"Headers/CameraMovement.h"


void CameraMovement::MoveCamera() {

	int KeyVerticalPressed = IsKeyDown(KEY_W) == true ? -1 : IsKeyDown(KEY_S) == true ? 1 : 0;
	int KeyHorizontalPressed = IsKeyDown(KEY_D) == true ? 1 : IsKeyDown(KEY_A) == true ? -1 : 0;

	Point Vel = Point(KeyHorizontalPressed * CameraSpeed, KeyVerticalPressed * CameraSpeed);

	if (KeyHorizontalPressed != 0) {
		m_Camera->target.x += Vel.x;
	}

	if (KeyVerticalPressed != 0) {

		m_Camera->target.y += Vel.y;
	}

}



void CameraMovement::Update() {
	MoveCamera();
}

CameraMovement::CameraMovement(Camera2D& cam) {
		m_Camera = &cam;
}


