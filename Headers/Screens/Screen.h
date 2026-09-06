#pragma once
#include"Headers/Point.h"
#include"Headers/GUI/GUI.h"
#include<memory>
#include<vector>
class Screen : public Behaviour_Adapter {

public:
	Camera2D Cam = { 0 };
	std::vector<Rectangle> Buttons;
	std::vector<std::unique_ptr<Screen>> Children;
	std::vector<std::unique_ptr<GUI>> GUIs;
	Screen* targetScreen = nullptr;
	Screen* parentScreen = nullptr;

	Point MousePos;
public:
	virtual void InitializeChildern() = 0;
	virtual void InitializeButtons() = 0;
	virtual void DrawButtons() = 0;
	virtual int GetButtonInfo() = 0;
	virtual std::string GetButtonType() =0;
	virtual Screen* GetNextScreen() = 0;
	virtual void SetText(std::string text) = 0;
	virtual void UpdateCam(const Point& pos) = 0;

	Screen(Camera2D& cam) : Cam(cam) {}
	Screen() = default;



	virtual ~Screen() = default;
};


class Scree_Adapter : public Screen {
public:
	void InitializeChildern() override {}
	void InitializeButtons() override {}
	void DrawButtons() override {}
	int GetButtonInfo() override { return 0;  }
	std::string GetButtonType() override { return ""; }
	Screen* GetNextScreen() override { return nullptr; }
	void SetText(std::string text) override {}
	void UpdateCam(const Point& pos) override {};

	Scree_Adapter(Camera2D& cam): Screen(cam) {
		Cam = cam;
	}
	Scree_Adapter() {}

	bool CheckBoundingArea(const Point& pos, const Rectangle& rec, const Point& origin = { 0,0 }) {
		float minX = rec.x - origin.x;
		float minY = rec.y - origin.y;

		float maxX = minX + rec.width;
		float maxY = minY + rec.height;

		return  (pos.x >= minX) && (pos.x <= maxX) &&
			(pos.y >= minY) && (pos.y <= maxY);
	}

	 ~Scree_Adapter() = default;
};