#pragma once
#include"Headers/Behaviour.h"
#include"raymath.h"

class CameraMovement  {
public:

	inline static int Hdir,Vdir;

	inline static  Camera2D m_Camera;
	inline static bool isHorizontalPressed = false, isVerticalPressed=false;
	inline static float CameraSpeed = 5.0f;
	static float GetHorizontalInput();
	static float GetVerticalInput();
	static void MoveCameraTo(Vector2 To);
	static Camera2D MoveCamera();

	CameraMovement();
	CameraMovement(Camera2D& Camera);

};
