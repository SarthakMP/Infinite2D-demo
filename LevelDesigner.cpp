#include"Headers/LevelDesigner.h"

static int m_sign(int Pos) {
	return (Pos > 0) - (Pos < 0);
}

void LevelDesigner::AddChunk(Chunk& chunk) {

	if (chunk.Getid() < ChunksArray[0].Getid()) {
		if (ChunksArray[5].isDirty) {
			ChunksArray[5].save(WorldName);
		}

		for (int i = 5; i > 0; i--) {
			ChunksArray[i] = ChunksArray[i - 1];
		}
		ChunksArray[0] = chunk;
	}
	else if (chunk.Getid() > ChunksArray[5].Getid()) {
		if (ChunksArray[0].isDirty) {
			ChunksArray[0].save(WorldName);
		}

		for (int i = 0; i < 5; i++) {
			ChunksArray[i] = ChunksArray[i + 1];
		}
		ChunksArray[5] = chunk;
	}
}
Point PrevPos = Point(0, 0);
void LevelDesigner::GenerateChunk(const Point& PlayerPos) {

	int delta = PlayerPos.x - PrevPos.x;

	int sign = m_sign(delta);
	int CurrentChunkId = static_cast<int>(std::floor(static_cast<double>(PlayerPos.x) / ChunksWidth));
	int y = -ChunksHeight - 100;

	int targetID = CurrentChunkId + (sign);

	std::string path = baseChunksPath + "chunk_" + std::to_string(targetID) + ".dat";
	int x = targetID * ChunksWidth;

	if (std::filesystem::exists(path)) {
		Chunk chunk;
		chunk.load(WorldName);
		AddChunk(chunk);
	}
	else {
		NewChunk(path, targetID, Point(x, y), 0, 0, 1);
	}
	
	PrevPos = PlayerPos;
}

void LevelDesigner::DrawChunks() {

	for (Chunk& chunk : ChunksArray) {
		DrawRectangleLines(chunk.HitBox->Rec.x, chunk.HitBox->Rec.y, chunk.HitBox->Rec.width, chunk.HitBox->Rec.height, RED);
		for (auto it = chunk.Blocks->begin(); it != chunk.Blocks->end(); it++) {
			BoxCollider2D& blocks = it->second;
			
			DrawRectangle(blocks.Rec.x, blocks.Rec.y, blocks.Rec.width, blocks.Rec.height, blocks.color);
		}

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
			block.id = c + 4 * r;
			(*NewChunk.Blocks)[block.id] = block;
		}
	}
}

void LevelDesigner::NewChunk(const std::string& Chunkpath,const int& chunk_id,const Point& XY, const int& i, const int& offset,int Add_Chunk) {

	Chunk NewChunk(XY.x, XY.y, ChunksWidth, ChunksHeight, chunk_id);

	GenerateBlocks(NewChunk, XY.x, XY.y);

	if (Add_Chunk ==0)
		ChunksArray[i + offset - chunk_id] = NewChunk;
	else if (Add_Chunk == 1)
		AddChunk(NewChunk);

	NewChunk.save(WorldName);
}

void LevelDesigner::Start() {

	if (!std::filesystem::is_directory(baseWorldsPath)) {
		std::filesystem::create_directory(baseWorldsPath);
	}

	p->SetWorldName(WorldName);
	baseWorldsPath += WorldName + "/";

	if (!std::filesystem::is_directory(baseWorldsPath)){
		std::filesystem::path worldDir = std::filesystem::path(baseWorldsPath);
		std::error_code ec;
		std::filesystem::create_directories(worldDir, ec);
	}

	baseChunksPath = baseWorldsPath + "Chunks/";
	if (!std::filesystem::is_directory(baseChunksPath)) {
		std::filesystem::create_directory(baseChunksPath);
	}

	std::string path = baseWorldsPath + "Player/" + "Player_Info.dat";
	std::ifstream inFile(path, std::ios::binary);

	if (p->isGameContinued && inFile.is_open()) {
		p->deserialize(inFile);
		inFile.close();
	}

	if (!p->isGameContinued) {
		Point PlayerPos = p->GetPlayerPos();
		int ChunkId = static_cast<int>(std::floor(static_cast<double>(PlayerPos.x) / ChunksWidth));
		int offset = 3;

		for (int i = -offset + ChunkId; i < offset + ChunkId; i++) {

			int x = i * ChunksWidth;
			int y = -ChunksHeight - 100;

			std::string Chunkpath = baseChunksPath + "chunk_" + std::to_string(i) + ".dat";
			NewChunk(Chunkpath, ChunkId,Point(x,y), i, 3, 0);

		}
		p->isGameContinued = true;
	}
	else {
		Point PlayerPos = p->GetPlayerPos();
		int ChunkId = static_cast<int>(std::floor(static_cast<double>(PlayerPos.x) / ChunksWidth));
		std::cout << ChunkId << std::endl;
		int offset = 3;
		
		for (int i = -offset + ChunkId; i < offset + ChunkId; i++) {
			Chunk Chunk;
			std::string Chunkpath = baseChunksPath + "chunk_" + std::to_string(i) + ".dat";
			
			if (std::filesystem::exists(Chunkpath)) {

				std::ifstream in(Chunkpath, std::ios::binary);
				Chunk.load(WorldName);
				ChunksArray[i + offset - ChunkId] = Chunk;
			}
			else {
				int x = i * ChunksWidth;
				int y = -ChunksHeight - 100;
				NewChunk(Chunkpath, ChunkId,Point(x,y), i, 3, 1);

			}
		}
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
	p = ply.get();
}