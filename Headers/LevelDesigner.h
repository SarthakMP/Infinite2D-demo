#pragma once
#include"Chunk.h"
#include"Player.h"
#include<string>
#include <filesystem>
#include<math.h>

class LevelDesigner : public Behaviour_Adapter{
	inline static Player* p;
	
public:
	inline static Chunk ChunksArray[6];
	inline static std::string WorldName = "";
	inline static std::string baseWorldsPath = std::string(WORLD_DIR) +"/";
	inline static std::string baseChunksPath = "";
	inline static std::string basePlayersPath = "";

	inline static int ChunksWidth = 400, ChunksHeight=800;

	inline static void AddChunk(Chunk& chunk);
	inline static void GenerateChunk(const Point& PlayerPos);
	inline static void DrawChunks();
	inline static void GenerateBlocks(Chunk& NewChunk, int x, int y);
	inline static void NewChunk(const std::string& Chunkpath, const int& chunk_id,const Point& XY, const int& i, const int& offset, int AddChunk);
	

	void Start();
	
	void Update();

	void Render();

	LevelDesigner(std::unique_ptr<Player>& ply);

};