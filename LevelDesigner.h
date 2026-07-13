#pragma once
#include"Chunk.h"
#include"Player.h"


class LevelDesigner : public Behaviour_Adapter{
	Player p;
	
	int GlobalChunkCounter = 0;
public:
	inline static std::vector<Chunk> Array_Chunks;

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

	void ReplaceChunk(bool dir) {

	}

	void AddChunk(Chunk& chunk) {
		Array_Chunks[GlobalChunkCounter] = chunk;
		GlobalChunkCounter = (GlobalChunkCounter+1)%4;
		
	}

	void MakeChunks() {
		int ChunkCounter;

		for (ChunkCounter = 0; ChunkCounter < 4; ChunkCounter++) {
			int x = -400 + (200 * ChunkCounter);
			int y = -800;

			Chunk chunk(x, y, 200, 800, ChunkCounter, {}, 0,0);
			AddChunk(chunk);
		}
	}

	void DrawChunks() {
		for (Chunk& chunk: Array_Chunks) {
			//DEBUG Visual Chunks
			Vector2& XY = chunk.GetXY();
			Vector2& WH = chunk.GetWH();
			
			DrawRectangleLines(XY.x, XY.y, WH.x, WH.y, WHITE);

		}
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
		MakeChunks();
	}


	void Update() override {
		
		Vector2 CurPos = p.GetPlayerPos();
		//MoveChunksWithPlayer(CurPos);
		DrawChunks();
		
	}
	
	LevelDesigner(Player ply) {
		Array_Chunks = std::vector<Chunk>(4);
		p = ply;
	}

};