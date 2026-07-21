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

	friend std::ostream& operator<<(std::ofstream& os, const Point& p);

private:

};

std::ostream& operator<<(std::ostream& os, Point p) {
	os << "(" << p.x << "," << p.y << ")" << "\n";
	return os;
}
