#pragma once
#include"Behaviour.h"
#include<iostream>
class Player : public Behaviour_Adapter {
	
	Texture2D Player_texture;
	unsigned short hitbox_w = 50, hitbox_h = 100;
	
public:
	inline static Vector2 Player_Pos = Vector2(0,0);
	inline static unsigned int Player_Speed = 5;

	void SetPlayerPos(Vector2 pos);
	Vector2 GetPlayerPos();
	void SetPlayerTexture(Texture2D text);

	void DrawPlayer();

	void Start();

	void Update();

};