#pragma once
#include"Behaviour.h"
#include"Point.h"
#include<iostream>
class Player : public Behaviour_Adapter {
	
	Texture2D Player_texture;
	unsigned short hitbox_w = 50, hitbox_h = 100;
	
public:
	inline static Point Player_Pos = Point(0,0);
	inline static unsigned int Player_Speed = 5;

	static void SetPlayerPos(Point& pos);
	static Point GetPlayerPos();
	void SetPlayerTexture(Texture2D text);

	void DrawPlayer();

	void Start();

	void Update();

};