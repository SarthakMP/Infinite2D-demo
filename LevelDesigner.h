#pragma once
#include"Chunk.h"
#include"Player.h"
#include<string>
#include <filesystem>
#include<math.h>
#include"DoublyLinkList.h"

class LevelDesigner : public Behaviour_Adapter{
	Player p;
	
	int GlobalChunkCounter = 0;
public:
	inline static Chunk ChunksArray[6];
	inline static std::string baseChunksPath = std::string(SOURCE_DIR) + "Chunks/";

	inline static int ChunksWidth = 400, ChunksHeight=800;

	#pragma region OLD_CODE
	/*
	std::vector< std::vector<Vector2>> GenerateRandomBlocksInChunk(int x, int y) {
		uint16_t height = 8, width = 4;
		std::vector< std::vector<Vector2>> blocks(height, std::vector<Vector2>(width));

		for (size_t row = 0; row < height; row++) {
			for (size_t col = 0; col < width; col++) {
				int num1 = (rand() %( (x + 200) - (x) + 1) + x)/100;
				int num2 = (rand() %( (y + 700) - (y+400) + 1) + (y+400))/100;
				if ((num1 + num2) > 0) {
					blocks[row][col] = Vector2{ float(num1 * 100),float(num2 * 100)};
				}
			}
		}

		return blocks;
	}


	void GenerateChunk(Vector2 PlayerPos) {
		int ClampedPos = int(PlayerPos.x / 200);
		int x = -400 + (200 * ClampedPos);
		int y = -800;

		Chunk chunk(x, y, 200, 800, ClampedPos, {}, 0, 0);
		
		std::string path = std::string(SOURCE_DIR) + "Chunks/" + "chunk_" + std::to_string(ClampedPos) + ".dat";
		std::ofstream outFile(path, std::ios::binary);
		chunk.serialize(outFile);

	}

	void GenerateChunks(Vector2& PlayerPos) {
		// Generate Chunks and store them in the binary file
		int ClampedPos = int(PlayerPos.x / 200);
		for (int ChunkCounter = ClampedPos - 1; ChunkCounter <= ClampedPos + 3; ChunkCounter++) {
			int x = -400 + (200 * ChunkCounter);
			int y = -800;

			Chunk chunk(x, y, 200, 800, ChunkCounter, {}, 0,0);
			std::string path = std::string(SOURCE_DIR)+"Chunks/" + "chunk_" + std::to_string(ChunkCounter-2) + ".dat";
			std::ofstream outFile(path, std::ios::binary);
			chunk.serialize(outFile);
			outFile.close();	
			
		}
	}

	void FetchChunks(Vector2& PlayerPos) {
		// Fetch Chunks from the binary file and store them in the Array_Chunks vector
		int clampedPos = int(PlayerPos.x / 200);

		std::string path = std::string(SOURCE_DIR) + "Chunks/" + "chunk_" + std::to_string(clampedPos) + ".dat";

		std::ifstream in(path, std::ios::binary);
		if (!in) {
			std::cerr << "Error opening file for reading." << std::endl;
			return;
		}
		Chunk chunk;
		chunk.deserialize(in);
		in.close();
		

	}

	void DrawChunks() {


	}
	
	void RenderBlocks(int id) {

		Chunk& chunk = Array_Chunks[id];
		std::vector< std::vector<Vector2>>& blocks = chunk.GetBlocks();

		for (size_t row = 0; row < blocks.size(); row++) {
			for (size_t col = 0; col < blocks[0].size(); col++)
			{
				Vector2 block_pos = blocks[row][col];
				DrawRectangle(block_pos.x, block_pos.y, 50, 50, WHITE);
			}

		}
	}


	void MoveChunksWithPlayer(Vector2 PlayerPos) {
		for(int i =0; i<Array_Chunks.size(); i++){
			Vector2 ChunksPos = Array_Chunks[i].GetBaseXY();
			Array_Chunks[i].SetXY(PlayerPos.x + ChunksPos.x, ChunksPos.y);
		}
	}
	

	void Start() override {
		Vector2 CurPos = p.GetPlayerPos();
//		GenerateChunks(CurPos);
	}


	void Update() override {
		
		Vector2 CurPos = p.GetPlayerPos();

		//GenerateChunk(CurPos);
		//FetchChunks(CurPos);
		//MoveChunksWithPlayer(CurPos);
		//DrawChunks();
		
	}
	
	LevelDesigner(Player ply) {
		p = ply;
	}
	*/
	
	#pragma endregion
	int m_sign(int Pos) {
		return (Pos > 0) - (Pos < 0);
	}

	void AddChunk(Chunk& chunk) {
		
		if (chunk.Getid() < ChunksArray[0].Getid()) { 
			for (int i = 5; i > 0; i--) {
				ChunksArray[i] = ChunksArray[i-1];
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
	void GenerateChunk(const Vector2& PlayerPos) {

		int delta = PlayerPos.x - PrevPos.x;
		if (delta == 0) return;

		

		int sign = m_sign(delta);

		int CurrentChunkId = static_cast<int>(std::floor(static_cast<double>(PlayerPos.x) / ChunksWidth));
		int y = -ChunksHeight;
		
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

	void DrawChunks() {
		for (Chunk& chunk : ChunksArray) {
			Vector2 Pos = chunk.GetXY();
			Vector2 Size = chunk.GetWH();
			DrawRectangleLines(Pos.x, Pos.y, Size.x, Size.y, WHITE);
		}
	}

	void Start() {


		if (!std::filesystem::is_directory(baseChunksPath)) {
			std::filesystem::create_directory(baseChunksPath);
		}

		int offset = 3;
		for (int i = -offset; i <= offset; i++) {

			std::string path = baseChunksPath + "chunk_" + std::to_string(i) + ".dat";
			Chunk NewChunk(i * ChunksWidth, -ChunksHeight, ChunksWidth, ChunksHeight, i);
			std::ofstream outfile(path, std::ios::binary);
			NewChunk.serialize(outfile);
			ChunksArray[i + offset] = NewChunk;
			outfile.close();
			
		}

	}
	
	void Update() {
		Vector2 PlyPos = p.GetPlayerPos();

		GenerateChunk(PlyPos);
		DrawChunks();
		PrevPos = PlyPos;
	}

	LevelDesigner(Player& ply) {
		ply = p;
	}

};