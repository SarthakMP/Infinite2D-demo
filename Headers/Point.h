#pragma once
#include"raylib.h"
#include<iostream>

class Point
{
public:
	int x = 0, y=0;

public:
	Point() {
		x = 0;
		y = 0;
	}
	Point(Vector2 pos) : x(pos.x), y(pos.y) {}
	Point(int in_x, int in_y) :x(in_x), y(in_y) {}
	~Point() {}

	static Point PointAdd(Point& a, Point& b) {
		return Point(a.x + b.x, a.y + b.y);
	}

	static Point PointZero() {
		return Point(0, 0);
	}

	friend inline std::ostream& operator<<(std::ostream& os, const Point& p);
	friend inline Point operator*(const Point& p, const float q);

private:

};

Point operator*(const Point& p, const float q) {
	return Point(p.x * q, p.y * q);
}

std::ostream& operator<<(std::ostream& os, const Point& p) {
	os << "(" << p.x << "," << p.y << ")" << "\n";
	return os;
}
