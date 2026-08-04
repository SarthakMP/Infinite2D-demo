#include"Headers/LevelDesigner.h"
#include"Headers/PlayerMovement.h"

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

	for (int i = 1; i <= 2; i++) {

		int targetID = CurrentChunkId + (sign * i);

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
			Point origin = Point(ChunksWidth / 2 + x, ChunksHeight/2 + y);
			chunk = Chunk(x, y, ChunksWidth, ChunksHeight, targetID);
			std::ofstream outFile(path, std::ios::binary);

			if (outFile.is_open()) {
				chunk.serialize(outFile);
				outFile.close();
			}
			else {
				std::cerr << "Warning: Could not save chunk to disk: " << path << std::endl;
			}

			AddChunk(chunk);
			
		}


	}
	PrevPos = PlayerPos;


}

void LevelDesigner::DrawChunks() {
	for (Chunk& chunk : ChunksArray) {
		Vector2 Pos = chunk.GetXY();
		Vector2 Size = chunk.GetWH();
		DrawRectangleLines(Pos.x, Pos.y, Size.x, Size.y, WHITE);
	}
}

void LevelDesigner::Start() {


	if (!std::filesystem::is_directory(baseChunksPath)) {
		std::filesystem::create_directory(baseChunksPath);
	}

	int offset = 3;
	for (int i = -offset; i <= offset; i++) {

		std::string path = baseChunksPath + "chunk_" + std::to_string(i) + ".dat";
		int x = i * ChunksWidth;
		int y = -ChunksHeight - 100;

		Chunk NewChunk(x,y, ChunksWidth, ChunksHeight, i);
		PlayerMovement::AddCollisions(NewChunk.HitBox);

		std::ofstream outfile(path, std::ios::binary);
		NewChunk.serialize(outfile);
		ChunksArray[i + offset] = NewChunk;
		outfile.close();

	}

}

void LevelDesigner::Update() {
	Point PlyPos = p.GetPlayerPos();

	GenerateChunk(PlyPos);

	PrevPos = PlyPos;
}

void LevelDesigner::Render() {
	DrawChunks();
}

LevelDesigner::LevelDesigner(Player& ply) {
	p = ply;
}