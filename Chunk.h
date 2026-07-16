#pragma once
#include"raymath.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdint>

class Chunk {

	unsigned int chunk_id;

	uint16_t chunk_h, chunk_w;
	int chunk_x, chunk_y;
	int base_x, base_y;
	Vector2 XY,WH;
	std::vector< std::vector<Vector2>> blocks;
	size_t size_y, size_x;

public:
	void serialize(std::ofstream& out) {
		out.write(reinterpret_cast<const char*>(&chunk_id), sizeof(chunk_id));
		out.write(reinterpret_cast<const char*>(&chunk_h), sizeof(chunk_h));
		out.write(reinterpret_cast<const char*>(&chunk_w), sizeof(chunk_w));
		out.write(reinterpret_cast<const char*>(&chunk_x), sizeof(chunk_x));
		out.write(reinterpret_cast<const char*>(&chunk_y), sizeof(chunk_y));
		out.write(reinterpret_cast<const char*>(&base_x), sizeof(base_x));
		out.write(reinterpret_cast<const char*>(&base_y), sizeof(base_y));
		out.write(reinterpret_cast<const char*>(&XY), sizeof(XY));
		out.write(reinterpret_cast<const char*>(&WH), sizeof(WH));
		out.write(reinterpret_cast<const char*>(&size_y), sizeof(size_y));
		out.write(reinterpret_cast<const char*>(&size_x), sizeof(size_x));

		size_t outer_size = blocks.size();
		out.write(reinterpret_cast<const char*>(&outer_size), sizeof(outer_size));

		for (const auto& row : blocks) {
			size_t inner_size = row.size();
			out.write(reinterpret_cast<const char*>(&inner_size), sizeof(inner_size));
			if (inner_size > 0) {
				out.write(reinterpret_cast<const char*>(row.data()), inner_size * sizeof(Vector2));
			}
		}
	}

	void deserialize(std::ifstream& in) {
		
		in.read(reinterpret_cast<char*>(&chunk_id), sizeof(chunk_id));
		in.read(reinterpret_cast<char*>(&chunk_h), sizeof(chunk_h));
		in.read(reinterpret_cast<char*>(&chunk_w), sizeof(chunk_w));
		in.read(reinterpret_cast<char*>(&chunk_x), sizeof(chunk_x));
		in.read(reinterpret_cast<char*>(&chunk_y), sizeof(chunk_y));
		in.read(reinterpret_cast<char*>(&base_x), sizeof(base_x));
		in.read(reinterpret_cast<char*>(&base_y), sizeof(base_y));
		in.read(reinterpret_cast<char*>(&XY), sizeof(XY));
		in.read(reinterpret_cast<char*>(&WH), sizeof(WH));
		in.read(reinterpret_cast<char*>(&size_y), sizeof(size_y));
		in.read(reinterpret_cast<char*>(&size_x), sizeof(size_x));

		size_t outer_size = 0;
		in.read(reinterpret_cast<char*>(&outer_size), sizeof(outer_size));
		blocks.resize(outer_size);

		for (size_t i = 0; i < outer_size; ++i) {
			size_t inner_size;
			in.read(reinterpret_cast<char*>(&inner_size), sizeof(inner_size));
			blocks[i].resize(inner_size);
			if (inner_size > 0) {
				in.read(reinterpret_cast<char*>(blocks[i].data()), inner_size * sizeof(Vector2));
			}
		}
	}



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