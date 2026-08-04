#pragma once
#include"Point.h"

class Ray2D {
public:
	Point Dir;
	Point To, Origin;
	Color clr;


	Ray2D() : To(Point(0, 0)), Origin(Point(0, 0)), clr(Color()) {}
	Ray2D(Point in_target, Point in_org, Color in_clr) : To(in_target), Origin(in_org), clr(in_clr) {}

	void DrawRay2D();
};