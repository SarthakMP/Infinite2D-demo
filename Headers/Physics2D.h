#pragma once
#include"Headers/Behaviour.h"
#include"Headers/Point.h"
class Physics2D : public Behaviour_Adapter {
public:
	inline static float Gravity = -9.81f;

	void AddGravity(Point& Pos);

	void Update();
	void Start();

};