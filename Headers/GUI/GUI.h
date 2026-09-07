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

	virtual void RenderGUI() = 0;
	virtual void UpdateGUI() = 0;
	virtual int GetButtonInfo() = 0;	
	virtual void OnMouseDownGUI(Vector2 in_MousePos) = 0;

	virtual	~GUIBase() = default;
};

class GUI : public GUIBase {

protected:
	static inline std::shared_ptr<Point[4]> BoundingPointsPtr;
	static inline Point ScrCenter = 0;
public:

	void RenderGUI() override {}
	void UpdateGUI() override {};
	int GetButtonInfo() override { return 0; }
	void OnMouseDownGUI(Vector2 in_MousePos) override {};
	
	GUI(Camera2D& Cam) :GUIBase(Cam) {

		Scr_W = GetScreenWidth();
		Scr_H = GetScreenHeight();

		ScrCenter = { Scr_W * 0.5f,Scr_H * 0.5f };
	}

	GUI(Camera2D& Cam, std::shared_ptr<Point[4]>& in_BoundingPointsPtr) :GUIBase(Cam) {
		Scr_W = GetScreenWidth();
		Scr_H = GetScreenHeight();
		BoundingPointsPtr = in_BoundingPointsPtr;
		ScrCenter = { Scr_W * 0.5f,Scr_H * 0.5f };
	}

	void SetBoundingPoints(std::shared_ptr<Point[4]>& UpdatedPoints) {
		BoundingPointsPtr = UpdatedPoints;

		Point top = BoundingPointsPtr[0], left = BoundingPointsPtr[1];

		ScrCenter = { left.x + Scr_W * 0.5f ,top.y - Scr_H * 0.5f };

	}



	GUI() = default;

	~GUI() {
		//delete BoundingPointsPtr;
	};
};