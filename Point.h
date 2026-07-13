#pragma once

class Point {

public:
	int x, y;
	Point(int in_x, int in_y) : x(in_x), y(in_y) {}
	
	Point operator+(Point b) {
		return Point(x + b.x, y + b.y);
	}
	Point operator-(Point b) {
		return Point(x - b.x, y - b.y);
	}
	Point operator*(Point b) {
		return Point(x * b.x, y * b.y);
	}

	Point() {
		x = 0;
		y = 0;
	}

};