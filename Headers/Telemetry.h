#pragma once
#include"Behaviour.h"
#include"Player.h"
#include"LevelDesigner.h"

class Telemetry{

	Camera2D LocCam;
	Point PlayerCoordsStrPos;
public:
	void TelemetryRender();
	void TelemetryUpdate();

	Telemetry(const Camera2D& WorldCam): LocCam(WorldCam){

	}
};



