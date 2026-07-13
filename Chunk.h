#pragma once
#include"raymath.h"
#include<vector>

class Chunk {

	unsigned int chunk_id;

	uint16_t chunk_h, chunk_w;
	int chunk_x, chunk_y;
	int base_x, base_y;
	Vector2 XY,WH;
	std::vector< std::vector<Vector2>> blocks;
	size_t size_y, size_x;


public:

	std::vector< std::vector<Vector2>>& GetBlocks(){
		return blocks;
	}
	
	void SetXY(float in_x, float in_y) {
		chunk_x = in_x;
		chunk_y = in_y;
	}

	Vector2& GetBaseXY() {
		XY.x = base_x;
		XY.y = base_y;
		return XY;
	}

	Vector2& GetXY() {
		XY.x = chunk_x;
		XY.y = chunk_y;
		return XY;
	}
	Vector2& GetWH() {
		WH.x = chunk_w;
		WH.y = chunk_h;
		return WH;
	}
	unsigned int Getid() {
		return chunk_id;
	}

	Chunk() {
		XY = {};
		chunk_y = 0;
		chunk_x = 0;
		
		WH = {};
		chunk_w = 0;
		chunk_h = 0;
		

		blocks = {};
		size_y = 0;
		size_x = 0;

		chunk_id = 0;

	}
	
	Chunk(int c_x,int c_y,int c_w, int c_h, int c_i, std::vector<std::vector<Vector2>> b, int b_x,int b_y) :
		base_x(c_x), base_y(c_y),chunk_w(c_w), chunk_h(c_h), chunk_id(c_i), blocks(b),size_x(b_x), size_y(b_y){
		chunk_x = base_x;
		chunk_y = base_y;
	}


};