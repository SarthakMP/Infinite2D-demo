#pragma once
#include"GUI.h"

class GUIHandler : public GUI {

public:
	inline static bool CheckBoundingArea(const Point& pos, const Rectangle& rec, const Point& origin = { 0,0 }) {
		float minX = rec.x - origin.x;
		float minY = rec.y - origin.y;

		float maxX = minX + rec.width;
		float maxY = minY + rec.height;

		return  (pos.x >= minX) && (pos.x <= maxX) &&
			(pos.y >= minY) && (pos.y <= maxY);
	}


};