#include"Headers/CameraMovement.h"
#include<iostream>

float CameraMovement::GetHorizontalInput()
{
	float input = 0;

	if (IsKeyDown(KEY_D)) {
		isHorizontalPressed = true;
		input= 1;
		CameraMovement::Hdir = 1;
		return input;
	}
	if (IsKeyDown(KEY_A)) {
		isHorizontalPressed = true;
		input= -1;
		CameraMovement::Hdir = -1;
		return input;
	}
	
	isHorizontalPressed = false;
	return 0;
}

float CameraMovement::GetVerticalInput() {
	float input = 0;
	if (IsKeyDown(KEY_W)) {
		isVerticalPressed = true;
		input= -1;
		CameraMovement::Vdir= -1;
		return input;
	}
	else if (IsKeyDown(KEY_S)) {
		isVerticalPressed = true;
		input = 1;
		CameraMovement::Vdir = 1;
		return input;
	}
	isVerticalPressed = false;
	return 0;
}

void CameraMovement::MoveCameraTo(Vector2 To)
{

	Vector2 currPos = m_Camera.target;
	Vector2 newPos = Vector2Add(currPos, To);
	m_Camera.target = newPos;


}

Camera2D CameraMovement::MoveCamera() {

	Vector2 input = Vector2(GetHorizontalInput() * CameraSpeed, GetVerticalInput() * CameraSpeed);
	if (isHorizontalPressed || isVerticalPressed) {
		MoveCameraTo(input);
	}
	return m_Camera;
}



CameraMovement::CameraMovement(Camera2D& cam) {
	m_Camera = cam;
}
\
CameraMovement::CameraMovement() {

}

