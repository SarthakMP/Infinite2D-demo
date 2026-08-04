#pragma once
#include"Ray2D.h"
class Raycast2D : public Ray2D {
public:
	Point HitPoint;

	Raycast2D() {
		HitPoint = Point(0, 0);
	}
};