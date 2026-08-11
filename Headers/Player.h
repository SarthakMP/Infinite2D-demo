#pragma once
#include"Behaviour.h"
#include"Point.h"
#include"BoxCollider2D.h"
#include<iostream>

class Player : public Behaviour_Adapter {
	

	unsigned short hitbox_w = 100, hitbox_h = 100;
	
	inline static bool isGrounded = false;
	inline static BoxCollider2D HitBox;
	inline static Point Player_Pos = Point(0, 0);
	inline static Point Player_Vel = Point(0, 0);
	inline static unsigned int Player_Speed = 5;

public:

	static void SetIsGrounded(bool val);
	static bool GetIsGrounded();

	static void SetPlayerPos(const Point& pos);
	static Point GetPlayerPos();

	static void SetVelocity(const Point& vel);
	static void SetVelocity(float x_in,float y_in);
	static Point GetVelocity();

	static BoxCollider2D GetHitBox();

	void DrawPlayer();

	void Start();

	void Update();
	
	void Render();
};