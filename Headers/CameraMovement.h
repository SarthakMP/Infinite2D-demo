#pragma once
#include"Headers/Behaviour.h"
#include"Headers/Point.h"

class CameraMovement : public Behaviour_Adapter {
public:

	inline static int Hdir,Vdir;

	inline static Camera2D* m_Camera = nullptr;
	inline static float CameraSpeed = 5.0f;


	static void MoveCamera();

	CameraMovement(Camera2D& Camera);

	void Update();

};
