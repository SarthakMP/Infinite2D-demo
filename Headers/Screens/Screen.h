#pragma once
#include"Headers/Point.h"
#include<memory>
#include<vector>
class Screen : public Behaviour_Adapter {

public:
	Camera2D Cam = { 0 };
	std::vector<Rectangle> Buttons;
	std::vector<std::unique_ptr<Screen>> Children;
	Screen* targetScreen = nullptr;
	Screen* parentScreen = nullptr;
public:
	virtual void InitializeChildern() = 0;
	virtual void InitializeButtons() = 0;
	virtual void DrawButtons() = 0;
	virtual int GetButtonInfo() = 0;
	virtual std::string GetButtonType() =0;
	virtual Screen* GetNextScreen() = 0;

	Screen(Camera2D& cam) : Cam(cam) {}
	Screen() = default;

	bool CheckBoundingArea(const Point& pos, const Rectangle& rec, const Point& origin = { 0,0 }) {
		float minX = rec.x - origin.x;
		float minY = rec.y - origin.y;

		float maxX = minX + rec.width;
		float maxY = minY + rec.height;

		return  (pos.x >= minX) && (pos.x <= maxX) &&
			(pos.y >= minY) && (pos.y <= maxY);
	}

	virtual ~Screen() = default;
};