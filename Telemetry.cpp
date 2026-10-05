#include"Headers/Telemetry.h"

std::string PlayerCoordsStr;

int ScreenW = 0;
int ScreenH = 0;

void Telemetry::TelemetryUpdate() {
	ScreenW = GetScreenWidth();
	ScreenH = GetScreenHeight();
	Point PlayerPos = Player::GetPlayerPos();

	PlayerCoordsStr = "PLAYER COORDs: " + std::to_string( int(PlayerPos.x)) + "," + std::to_string(int(PlayerPos.y));
	PlayerCoordsStrPos.x = PlayerPos.x + 100 ;
	PlayerCoordsStrPos.y = -PlayerPos.y - ScreenH*0.5f + 100;
}

void Telemetry::TelemetryRender() {


	Point PlayerPos = Player::GetPlayerPos();
	int CurrentChunkId = static_cast<int>(std::floor(static_cast<double>(PlayerPos.x) / 800));
	DrawText(PlayerCoordsStr.c_str(), PlayerCoordsStrPos.x, PlayerCoordsStrPos.y, 20, WHITE);


	for (auto& CurrChunk : LevelDesigner::ChunksArray) {

		DrawText(std::to_string(CurrChunk.Getid()).c_str(), CurrChunk.GetXY().x, CurrChunk.GetXY().y + CurrChunk.GetWH().y, 20, WHITE);
		//if (std::abs(CurrentChunkId - CurrChunk.Getid()) <= 1) continue;

		for (auto it = CurrChunk.Blocks->begin(); it != CurrChunk.Blocks->end(); it++) {
			
			DrawText(std::to_string(it->second.id).c_str(), it->second.Rec.x, -it->second.Rec.y, 20, WHITE);
		}

		
	}

}