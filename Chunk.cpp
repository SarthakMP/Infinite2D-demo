#include"./Headers/Chunk.h"

void Chunk::serialize(std::ofstream& out) {
	out.write(reinterpret_cast<const char*>(&chunk_id), sizeof(chunk_id));

	out.write(reinterpret_cast<const char*>(&chunk_h), sizeof(chunk_h));
	out.write(reinterpret_cast<const char*>(&chunk_w), sizeof(chunk_w));

	out.write(reinterpret_cast<const char*>(&chunk_x), sizeof(chunk_x));
	out.write(reinterpret_cast<const char*>(&chunk_y), sizeof(chunk_y));

	if (HitBox) {
		out.write(reinterpret_cast<const char*>(HitBox.get()), sizeof(BoxCollider2D));
	}
	
	size_t count = (Blocks) ? Blocks->size() : 0;
	out.write(reinterpret_cast<const char*>(&count), sizeof(count));

	if (count > 0) {
		for (size_t i = 0; i < count; ++i) {
			BoxCollider2D& block = (*Blocks)[i];
			out.write(reinterpret_cast<const char*>(&block), count * sizeof(BoxCollider2D));
		}
	}
	
}

void Chunk::deserialize(std::ifstream& in) {


	in.read(reinterpret_cast<char*>(&chunk_id), sizeof(chunk_id));

	in.read(reinterpret_cast<char*>(&chunk_h), sizeof(chunk_h));
	in.read(reinterpret_cast<char*>(&chunk_w), sizeof(chunk_w));

	in.read(reinterpret_cast<char*>(&chunk_x), sizeof(chunk_x));
	in.read(reinterpret_cast<char*>(&chunk_y), sizeof(chunk_y));

	if (HitBox) {
		in.read(reinterpret_cast<char*>(HitBox.get()), sizeof(BoxCollider2D));
	}
	

	if (!Blocks) {
		Blocks = std::make_shared<std::map<int,BoxCollider2D>>();
	}

	size_t count = 0;
	in.read(reinterpret_cast<char*>(&count), sizeof(count));

	for (size_t i = 0; i < count; ++i) {
		BoxCollider2D block;

		in.read(reinterpret_cast<char*>(&block), sizeof(BoxCollider2D));


		Blocks->emplace(block.id, block);
	}


}


void Chunk::SetXY(float in_x, float in_y) {
	chunk_x = in_x;
	chunk_y = in_y;
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

	HitBox = std::make_shared<BoxCollider2D>();
	Blocks = std::make_shared<std::map<int,BoxCollider2D>>();
}

Chunk::Chunk(int c_x, int c_y, int c_w, int c_h, int c_i) :
	chunk_x(c_x), chunk_y(c_y), chunk_w(c_w), chunk_h(c_h), chunk_id(c_i) {
	WH = { 0,0 };
	XY = { 0,0 };

	HitBox = std::make_shared<BoxCollider2D>();
	Blocks = std::make_shared<std::map<int, BoxCollider2D>>();

	HitBox->Rec.x = chunk_x;
	HitBox->Rec.y = chunk_y;

	HitBox->Rec.width = chunk_w;
	HitBox->Rec.height = chunk_h;

	HitBox->Origin.x = HitBox->Rec.x + chunk_w * 0.5f;
	HitBox->Origin.y = HitBox->Rec.y + chunk_h * 0.5f;

}