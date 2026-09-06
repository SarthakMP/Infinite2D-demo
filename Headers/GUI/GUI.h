#pragma once
#include"Headers/Point.h"
#include"Headers/Player.h"
class GUIBase : public Behaviour_Adapter {

protected:
	int Scr_W = 0;
	int Scr_H = 0;
public:
	Camera2D& LocCam;

	Point MousePos;
public:

	
	GUIBase(Camera2D& Cam) : LocCam(Cam) {}

	GUIBase() = default;

	virtual int GetButtonInfo() = 0;
	virtual void DrawGUI() = 0;

	virtual	~GUIBase() = default;
};

class GUI : public GUIBase {

protected:
	static inline std::shared_ptr<Point[4]> BoundingPointsPtr;

public:

	void DrawGUI() override {}
	void RenderGUI() override {}
	int GetButtonInfo() override { return 0; }
	
	GUI(Camera2D& Cam) :GUIBase(Cam) {

		Scr_W = GetScreenWidth();
		Scr_H = GetScreenHeight();
	}

	GUI(Camera2D& Cam, std::shared_ptr<Point[4]>& in_BoundingPointsPtr) :GUIBase(Cam) {
		Scr_W = GetScreenWidth();
		Scr_H = GetScreenHeight();
		BoundingPointsPtr = in_BoundingPointsPtr;
	}

	void SetBoundingPoints(std::shared_ptr<Point[4]>& UpdatedPoints) {
		BoundingPointsPtr = UpdatedPoints;
	}

	bool CheckBoundingArea(const Point& pos, const Rectangle& rec, const Point& origin = { 0,0 }) {
		float minX = rec.x - origin.x;
		float minY = rec.y - origin.y;

		float maxX = minX + rec.width;
		float maxY = minY + rec.height;

		return  (pos.x >= minX) && (pos.x <= maxX) &&
			(pos.y >= minY) && (pos.y <= maxY);
	}

	GUI() = default;

	~GUI() {
		//delete BoundingPointsPtr;
	};
};