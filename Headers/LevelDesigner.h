#pragma once
#include"Chunk.h"
#include"Player.h"
#include<string>
#include <filesystem>
#include<math.h>

class LevelDesigner : public Behaviour_Adapter{
	inline static Player p;
	
	int GlobalChunkCounter = 0;
public:
	inline static Chunk ChunksArray[6];
	inline static std::string baseChunksPath = std::string(SOURCE_DIR) + "Chunks/";

	inline static int ChunksWidth = 400, ChunksHeight=800;

	inline static void AddChunk(Chunk& chunk);

	inline static void GenerateChunk(const Vector2& PlayerPos);

	inline static void DrawChunks();

	void Start();
	
	void Update();

	LevelDesigner(Player& ply);

};