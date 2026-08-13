#pragma once
#include <fstream>
#include <map>

#include"Point.h"
#include"BoxCollider2D.h"

class Chunk {

	int chunk_id;
	uint16_t chunk_h, chunk_w;
	int chunk_x, chunk_y;
	Vector2 XY,WH;

public:

	std::shared_ptr<std::map<int,BoxCollider2D>> Blocks;
	std::shared_ptr<BoxCollider2D> HitBox;
	void serialize(std::ofstream& out);

	void deserialize(std::ifstream& in);

public:

	
	void SetXY(float in_x, float in_y);

	Vector2& GetXY();
	Vector2& GetWH();
	
	int Getid();

	Chunk();
	

	Chunk(int c_x, int c_y, int c_w, int c_h, int c_i);

};