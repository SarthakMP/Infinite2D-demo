#pragma once
#include"Point.h"
#include"Player.h"
#include"Physics2D.h"

class PlayerMovement : public Physics2D {
	static inline float PlayerSpeed = 5;
public:

	static void Move();

	void Update() override;
	void Render() override;

	void OnMouseDown();

	PlayerMovement();

};