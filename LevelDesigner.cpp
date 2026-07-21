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
Vector2 PrevPos = Vector2(0, 0);
void LevelDesigner::GenerateChunk(const Vector2& PlayerPos) {

	int delta = PlayerPos.x - PrevPos.x;
	if (delta == 0) return;



	int sign = m_sign(delta);

	int CurrentChunkId = static_cast<int>(std::floor(static_cast<double>(PlayerPos.x) / ChunksWidth));
	int y = -ChunksHeight - 100;

	for (int i = 1; i <= 2; i++) {

		int targetID = CurrentChunkId + (sign * i);

		std::string path = baseChunksPath + "chunk_" + std::to_string(targetID) + ".dat";
		Chunk chunk;

		/* DEBUG
		std::cout << "Curr Pos: " << PlayerPos.x << " Next First Pos: " << PlayerPos.x + sign * ChunksWidth << " Next Second Pos: " << PlayerPos.x + 2 * sign * ChunksWidth << std::endl;
		std::cout << "Sign: " << sign << std::endl;
		*/

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
		Chunk NewChunk(i * ChunksWidth, -ChunksHeight - 100, ChunksWidth, ChunksHeight, i);
		std::ofstream outfile(path, std::ios::binary);
		NewChunk.serialize(outfile);
		ChunksArray[i + offset] = NewChunk;
		outfile.close();

	}

}

void LevelDesigner::Update() {
	Vector2 PlyPos = p.GetPlayerPos();

	GenerateChunk(PlyPos);
	DrawChunks();
	PrevPos = PlyPos;
}

LevelDesigner::LevelDesigner(Player& ply) {
	p = ply;
}