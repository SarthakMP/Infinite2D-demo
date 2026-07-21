#pragma once
#include"Player.h"
#include<iostream>
class PlayerMovement : public Player{
	Player p;

	void Move(Point in, Point CurPos) {
		in = in * p.Player_Speed;
		Point nextPos = Point::PointAdd(in , CurPos) ;
		p.SetPlayerPos(nextPos);
	}

	bool isPressed = false;
	Point GetInput() {
		Point input = Point(0, 0);
		if (IsKeyDown(KEY_D)) {
			input.x = 1.0f;
			isPressed = true;
			return input;
		}
		if (IsKeyDown(KEY_A)) {
			input.x = -1.0f;
			isPressed = true;
			return input;
		}

		if (IsKeyDown(KEY_SPACE)) {
			input.y = 1.0f;
			isPressed = true;
			return input;
		}

		isPressed = false;
		return Point(0, 0);
	}


	void Update() override {
		
		Point in = GetInput();
		if (isPressed) {
			Point CurPos = p.GetPlayerPos();
			Move(in, CurPos);
		}

	}

public:
	PlayerMovement(Player& ply) {
		p = ply;
	}

};