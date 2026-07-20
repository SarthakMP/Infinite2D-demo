#pragma once
#include"Player.h"
#include<iostream>
class PlayerMovement : public Player{
	Player p;

	void Move(Vector2 in,Vector2 CurPos) {
		Vector2 nextPos = Vector2Add(in * p.Player_Speed, CurPos) ;
		p.SetPlayerPos(nextPos);
	}

	bool isPressed = false;
	Vector2 GetInput() {
		Vector2 input = Vector2(0, 0);
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
		isPressed = false;
		return Vector2(0, 0);
	}


	void Update() override {
		
		Vector2 in = GetInput();
		if (isPressed) {
			Vector2 CurPos = p.GetPlayerPos();
			Move(in, CurPos);
		}

	}

public:
	PlayerMovement(Player& ply) {
		p = ply;
	}

};