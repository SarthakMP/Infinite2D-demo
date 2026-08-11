#pragma once
#include"Behaviour.h"
#include<iostream>
class Point {
public:
	float x, y;

	Point() : x(0), y(0) {}

	Point(float a) : x(a), y(a) {}

	Point(float in_x, float in_y) : x(in_x), y(in_y) {}

	Point(const Vector2& vec) : x(vec.x), y(vec.y) {}

	static inline float Magnitude(Point A, Point B) {
		return std::hypot(B.x - A.x, B.y - A.y);
	}


	static inline float Dot(Point A, Point B) {
		return (A.x * B.x + A.y * B.y);
	}

	static inline float sign(float a) {
		return a > 0 ? 1 : a < 0 ? -1 : 0;
	}

	Point operator-() const {
		return Point(-x, -y);
	}

	friend std::ostream& operator<<(std::ostream& os, const Point& p);
	friend const Point operator+(Point A, Point B);
	friend const Point operator-(Point A, Point B);
	friend const Point operator*(Point A, Point B);

	friend const Point operator+(Point A, float B);
	friend const Point operator-(Point A, float B);
	friend const Point operator*(Point A, float B);
	friend const Point operator/(Point A, float B);
	friend const Point operator+=(Point A, float B);
	friend const Point operator+=(Point A, Point B);
	friend const Point operator-=(Point A, float B);
	friend const Point operator-=(Point A, Point B);
};

static inline std::ostream& operator<<(std::ostream& os, const Point& p) {
	os << "(" << p.x << "," << p.y << ")" << "\n";
	return os;
}

static inline const  Point operator+(Point A, Point B) {
	return Point(A.x + B.x, A.y + B.y);
}
static inline const  Point operator-(Point A, Point B) {
	return Point(A.x - B.x, A.y - B.y);
}
static inline  const Point operator*(Point A, Point B) {
	return Point(A.x * B.x, A.y * B.y);
}


static inline const  Point operator+(Point A, float B) {
	return Point(A.x + B, A.y + B);
}

static inline const  Point operator-(Point A, float B) {
	return Point(A.x - B, A.y - B);
}

static inline const  Point operator-(float B, Point A) {
	return Point(B - A.x, B - A.y);
}

static inline const  Point operator*(Point A, float B) {
	return Point(A.x * B, A.y * B);
}

static inline const Point operator/(Point A, float B) {
	return Point(A.x / B, A.y / B);
}

static inline const Point operator+=(Point A, float B)
{
	return Point(A.x + B, A.y + B);
}

static inline const Point operator+=(Point A, Point B) {
	return Point(A.x + B.x, A.y + B.x);
}

static inline const Point operator-=(Point A, float B)
{
	return Point(A.x - B, A.y - B);
}

static inline const Point operator-=(Point A, Point B)
{
	return Point(A.x - B.x, A.y - B.x);
}
