#pragma once
#include"Chunk.h"
#include"Player.h"
#include<string>
#include <filesystem>
#include<math.h>

class LevelDesigner : public Behaviour_Adapter{
	inline static std::unique_ptr<Player> p;
	
public:
	inline static Chunk ChunksArray[6];
	inline static std::string baseChunksPath = std::string(SOURCE_DIR) + "Chunks/";

	inline static int ChunksWidth = 400, ChunksHeight=800;

	inline static void AddChunk(Chunk& chunk);

	inline static void GenerateChunk(const Point& PlayerPos);

	inline static void DrawChunks();

	inline static void GenerateBlocks(Chunk& NewChunk, int x, int y);

	void Start();
	
	void Update();

	void Render();

	LevelDesigner(std::unique_ptr<Player>& ply);

};