#pragma once
#include <fstream>
#include <map>
#include<filesystem>
#include"Point.h"
#include"BoxCollider2D.h"


class Chunk {

	int chunk_id;
	Vector2 XY,WH;

public:
	bool isDirty = false;
	std::shared_ptr<std::map<int,BoxCollider2D>> Blocks;
	std::shared_ptr<BoxCollider2D> HitBox;
	void serialize(std::ofstream& out);

	void deserialize(std::ifstream& in);

public:

	void load(std::string& worldName, std::string& path);
	void save(std::string& worldName);
	void SetXY(float in_x, float in_y);

	Vector2& GetXY();
	Vector2& GetWH();
	
	int Getid();

	Chunk();

	Chunk(int c_x, int c_y, int c_w, int c_h, int c_i);

};