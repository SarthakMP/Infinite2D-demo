#pragma once
#include"raylib.h"
#include"raymath.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdint>

class Chunk {

	int chunk_id;

	uint16_t chunk_h, chunk_w;
	int chunk_x, chunk_y;
	int base_x, base_y;
	Vector2 XY,WH;
	std::vector< std::vector<Vector2>> blocks;
	size_t size_y, size_x;

public:
	void serialize(std::ofstream& out);

	void deserialize(std::ifstream& in);

public:

	std::vector< std::vector<Vector2>>& GetBlocks();
	
	void SetXY(float in_x, float in_y);

	Vector2& GetBaseXY();

	Vector2& GetXY();
	Vector2& GetWH();
	
	int Getid();

	Chunk();
	
	Chunk(int c_x, int c_y, int c_w, int c_h, int c_i, std::vector<std::vector<Vector2>> b, int b_x, int b_y);

	Chunk(int c_x, int c_y, int c_w, int c_h, int c_i);

};