#include"./Headers/Chunk.h"

void Chunk::serialize(std::ofstream& out) {
	out.write(reinterpret_cast<const char*>(&chunk_id), sizeof(chunk_id));

	out.write(reinterpret_cast<const char*>(&chunk_h), sizeof(chunk_h));
	out.write(reinterpret_cast<const char*>(&chunk_w), sizeof(chunk_w));

	out.write(reinterpret_cast<const char*>(&chunk_x), sizeof(chunk_x));
	out.write(reinterpret_cast<const char*>(&chunk_y), sizeof(chunk_y));

	
	out.write(reinterpret_cast<const char*>(&Origin), sizeof(Origin));
	/*
	size_t outer_size = blocks.size();
	out.write(reinterpret_cast<const char*>(&outer_size), sizeof(outer_size));

	for (const auto& row : blocks) {
		size_t inner_size = row.size();
		out.write(reinterpret_cast<const char*>(&inner_size), sizeof(inner_size));
		if (inner_size > 0) {
			out.write(reinterpret_cast<const char*>(row.data()), inner_size * sizeof(Vector2));
		}
	}
	*/
}

void Chunk::deserialize(std::ifstream& in) {

	

	in.read(reinterpret_cast<char*>(&chunk_id), sizeof(chunk_id));

	in.read(reinterpret_cast<char*>(&chunk_h), sizeof(chunk_h));
	in.read(reinterpret_cast<char*>(&chunk_w), sizeof(chunk_w));

	in.read(reinterpret_cast<char*>(&chunk_x), sizeof(chunk_x));
	in.read(reinterpret_cast<char*>(&chunk_y), sizeof(chunk_y));

	
	in.read(reinterpret_cast<char*>(&Origin), sizeof(Origin));
	
	/*
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
	*/

}


void Chunk::SetXY(float in_x, float in_y) {
	chunk_x = in_x;
	chunk_y = in_y;
}

Vector2& Chunk::GetBaseXY() {
	XY.x = chunk_x;
	XY.y = chunk_y;
	return XY;
}

Vector2& Chunk::GetXY() {
	XY.x = chunk_x;
	XY.y = chunk_y;
	return XY;
}
Vector2& Chunk::GetWH() {
	WH.x = chunk_w;
	WH.y = chunk_h;
	return WH;
}
int Chunk::Getid() {
	return chunk_id;
}

Chunk::Chunk() {
	XY = { 0,0 };
	chunk_y = 0;
	chunk_x = 0;

	WH = { 0,0 };
	chunk_w = 0;
	chunk_h = 0;


	chunk_id = 0;
	Origin = Point(0, 0);
}

Chunk::Chunk(int c_x, int c_y, int c_w, int c_h, int c_i, Point org) :
	chunk_x(c_x), chunk_y(c_y), chunk_w(c_w), chunk_h(c_h), chunk_id(c_i), Origin(org) {
	WH = { 0,0 };
	XY = { 0,0 };

	Origin.x = chunk_x;
	Origin.y = chunk_y;

	Rec.width = chunk_w;
	Rec.height = chunk_h;


}