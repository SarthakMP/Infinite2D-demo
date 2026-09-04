#include"./Headers/Chunk.h"
#include"string.h"

void Chunk::serialize(std::ofstream& out) {
	out.write(reinterpret_cast<const char*>(&chunk_id), sizeof(chunk_id));

	bool hasHitBox = (HitBox != nullptr);
	out.write(reinterpret_cast<const char*>(&hasHitBox), sizeof(hasHitBox));

	if (hasHitBox) {
		out.write(reinterpret_cast<const char*>(HitBox.get()), sizeof(BoxCollider2D));
	}
	
	size_t count = (Blocks) ? Blocks->size() : 0;
	out.write(reinterpret_cast<const char*>(&count), sizeof(count));

	if (count > 0) {
		for (const auto& [id, block] : *Blocks) {
			out.write(reinterpret_cast<const char*>(&id), sizeof(id));
			out.write(reinterpret_cast<const char*>(&block), sizeof(BoxCollider2D));
		}
	}
	
}

void Chunk::deserialize(std::ifstream& in) {

	in.read(reinterpret_cast<char*>(&chunk_id), sizeof(chunk_id));

	bool hasHitBox = false;
	in.read(reinterpret_cast<char*>(&hasHitBox), sizeof(hasHitBox));
	
	if (hasHitBox) {
		HitBox = std::make_shared<BoxCollider2D>();
		in.read(reinterpret_cast<char*>(HitBox.get()), sizeof(BoxCollider2D));
	}
	else {
		HitBox.reset();
	}
	

	Blocks = std::make_shared<std::map<int,BoxCollider2D>>();

	size_t count = 0;
	in.read(reinterpret_cast<char*>(&count), sizeof(count));
	for (size_t i = 0; i < count; ++i) {
		int id=0;
		BoxCollider2D block;
		in.read(reinterpret_cast<char*>(&id), sizeof(id));
		in.read(reinterpret_cast<char*>(&block), sizeof(BoxCollider2D));

		Blocks->emplace(id, block);
	}


}



void Chunk::SetXY(float in_x, float in_y) {
	HitBox->Rec.x = in_x;
	HitBox->Rec.y = in_y;
}

Vector2& Chunk::GetXY() {
	XY.x = HitBox->Rec.x;
	XY.y = HitBox->Rec.y;
	return XY;
}
Vector2& Chunk::GetWH() {
	WH.x = HitBox->Rec.width;
	WH.y = HitBox->Rec.height;
	return WH;
}
int Chunk::Getid() {
	return chunk_id;
}

Chunk::Chunk() {
	XY = { 0,0 };
	WH = { 0,0 };
	chunk_id = 0;

	HitBox = std::make_shared<BoxCollider2D>();
	Blocks = std::make_shared<std::map<int,BoxCollider2D>>();
}


void Chunk::load(std::string& worldName, std::string& path)
{
	if (std::filesystem::exists(path)) {
		std::ifstream in(path, std::ios::binary);
		if (in.is_open()) {
			deserialize(in);
		}
		in.close();
	}
}


void Chunk::save(std::string& worldName)
{
	std::string baseChunksPath = std::string(WORLD_DIR) + "/" + worldName + "/Chunks/" + "chunk_" + std::to_string(chunk_id) + ".dat";

	std::ofstream out(baseChunksPath, std::ios::binary);
	if (out.is_open()) {
		serialize(out);
		out.close();
	}
	
}

Chunk::Chunk(int c_x, int c_y, int c_w, int c_h, int c_i) : chunk_id(c_i) {
	WH = { 0,0 };
	XY = { 0,0 };

	HitBox = std::make_shared<BoxCollider2D>();
	Blocks = std::make_shared<std::map<int, BoxCollider2D>>();

	HitBox->Rec.x = c_x;
	HitBox->Rec.y = c_y;

	HitBox->Rec.width = c_w;
	HitBox->Rec.height = c_h;

	HitBox->Origin.x = HitBox->Rec.x + c_w * 0.5f;
	HitBox->Origin.y = HitBox->Rec.y + c_h * 0.5f;

}