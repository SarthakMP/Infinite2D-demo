#pragma once
#include"Behaviour.h"
#include<iostream>
class Player : public Behaviour_Adapter {
	
	Texture2D Player_texture;
	unsigned short hitbox_w = 50, hitbox_h = 100;
	
	

public:
	inline static Vector2 Player_Pos = Vector2(0,0);
	inline static unsigned int Player_Speed = 5;

	void SetPlayerPos(Vector2 pos) {
		Player_Pos = pos;
	}
	Vector2 GetPlayerPos() {
		return Player_Pos;
	}
	void SetPlayerTexture(Texture2D text) {
		Player_texture = text;
	}

	void DrawPlayer() {
		//DEBUG ONLY
		DrawRectangle(Player_Pos.x, Player_Pos.y, 100, 100, WHITE);
	}

	void Start() override {
		SetPlayerPos(Vector2Zero());
	}

	void Update() override {
		DrawPlayer();
	}

};