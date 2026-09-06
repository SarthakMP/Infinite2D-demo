#pragma once
#include"Behaviour.h"
#include"Point.h"
#include"BoxCollider2D.h"
#include <fstream>
#include<filesystem>

class Player : public Behaviour_Adapter {
	
	inline static Point Player_Pos;
	
	inline static unsigned short hitbox_w, hitbox_h;
	inline static bool isGrounded;
	inline static BoxCollider2D HitBox;
	inline static Point Player_Vel = Point(0, 0);
	
	inline static std::string LocWorldName = "";
	inline static std::string basePlayersPath = std::string(WORLD_DIR) + "/";

public:
	inline static unsigned int Player_Speed = 5;
	inline static bool isGameContinued;
	static void SetIsGrounded(bool val);
	static bool GetIsGrounded();

	static void SetPlayerPos(const Point& pos);
	static Point GetPlayerPos();

	static void SetVelocity(const Point& vel);
	static void SetVelocity(float x_in,float y_in);

	static Point GetVelocity();

	static void UpdateHitbox();
	static BoxCollider2D GetHitBox();

	void SetWorldName(std::string& WorldName);

	void DrawPlayer();

	void Start();

	void Update();
	
	void Render();

	static void serialize(std::ofstream& out);
	static void deserialize(std::ifstream& in);

	void Save();

	Player();
};