#include"Headers/LevelDesigner.h"

static int m_sign(int Pos) {
	return (Pos > 0) - (Pos < 0);
}

void LevelDesigner::AddChunk(Chunk& chunk) {

	if (chunk.Getid() < ChunksArray[0].Getid()) {
		for (int i = 5; i > 0; i--) {
			ChunksArray[i] = ChunksArray[i - 1];
		}
		ChunksArray[0] = chunk;
	}
	else if (chunk.Getid() > ChunksArray[5].Getid()) {
		for (int i = 0; i < 5; i++) {
			ChunksArray[i] = ChunksArray[i + 1];
		}
		ChunksArray[5] = chunk;
	}
}
Point PrevPos = Point(0, 0);
void LevelDesigner::GenerateChunk(const Point& PlayerPos) {

	int delta = PlayerPos.x - PrevPos.x;
	if (delta == 0) return;

	int sign = m_sign(delta);

	int CurrentChunkId = static_cast<int>(std::floor(static_cast<double>(PlayerPos.x) / ChunksWidth));
	int y = -ChunksHeight - 100;


		int targetID = CurrentChunkId + (sign);

		std::string path = baseChunksPath + "chunk_" + std::to_string(targetID) + ".dat";
		Chunk chunk;

		int x = targetID * ChunksWidth;

		if (std::filesystem::exists(path)) {
			std::ifstream in(path, std::ios::binary);
			if (in.is_open()) {
				chunk.deserialize(in);
				in.close();
				AddChunk(chunk);
			}
		}
		else {
			chunk = Chunk(x, y, ChunksWidth, ChunksHeight, targetID);
			std::ofstream outFile(path, std::ios::binary);

			if (outFile.is_open()) {
				chunk.serialize(outFile);
				outFile.close();
			}
			else {
				std::cerr << "Warning: Could not save chunk to disk: " << path << std::endl;
			}
			GenerateBlocks(chunk, x, y);
			AddChunk(chunk);
			
		}

	PrevPos = PlayerPos;


}

void LevelDesigner::DrawChunks() {
	for (Chunk& chunk : ChunksArray) {

		for (auto& blocks : *chunk.Blocks) {
			if (blocks.GetActive() == false) continue;
			DrawRectangle(blocks.Rec.x, blocks.Rec.y, blocks.Rec.width, blocks.Rec.height, blocks.color);
			//DrawRectangleLines(blocks.Rec.x, blocks.Rec.y, blocks.Rec.width, blocks.Rec.height, GREEN);
		}

		
		Vector2 Pos = chunk.GetXY();
		Vector2 Size = chunk.GetWH();
		DrawRectangleLines(Pos.x, Pos.y, Size.x, Size.y, GREEN);
		//DrawRectangle(chunk.HitBox->Rec.x, chunk.HitBox->Rec.y, chunk.HitBox->Rec.width, chunk.HitBox->Rec.height, RED);
	}
}
float block_h = 100, block_w = 100;

void LevelDesigner::GenerateBlocks(Chunk& NewChunk,int x,int y) {
	int chunk_h = NewChunk.GetWH().y;
	int chunk_w = NewChunk.GetWH().x;
	for (size_t r = 0; r < static_cast<int>(std::floor(chunk_h / 100)); r++) {
		for (size_t c = 0; c < static_cast<int>(std::floor(chunk_w / 100)); c++) {
			int block_x = x + c * block_w ;
			int block_y = y + r * block_h ;
			BoxCollider2D block( Rectangle(block_x, block_y, block_w, block_h),WHITE);
			block.SetActive(true);
			NewChunk.Blocks->push_back(block);
		}
	}
}

void LevelDesigner::Start() {
	p = std::make_unique<Player>();

	if (!std::filesystem::is_directory(baseChunksPath)) {
		std::filesystem::create_directory(baseChunksPath);
	}

	int offset = 3;
	
	for (int i = -offset; i <= offset; i++) {

		std::string path = baseChunksPath + "chunk_" + std::to_string(i) + ".dat";
		int x = i * ChunksWidth;
		int y = -ChunksHeight - 100;

		Chunk NewChunk(x,y, ChunksWidth, ChunksHeight, i);
		
		GenerateBlocks(NewChunk, x, y);


		std::ofstream outfile(path, std::ios::binary);
		NewChunk.serialize(outfile);
		ChunksArray[i + offset] = NewChunk;
		outfile.close();

	}

}

void LevelDesigner::Update() {
	Point PlyPos = p->GetPlayerPos();
	GenerateChunk(PlyPos);
}

void LevelDesigner::Render() {
	DrawChunks();
}

LevelDesigner::LevelDesigner(std::unique_ptr<Player>& ply) {
	p = std::move(ply);
}