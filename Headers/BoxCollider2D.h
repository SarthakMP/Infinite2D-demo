#pragma once
#include"Point.h"
#include"Collision2D.h"

class BoxCollider2D : public Collision2D {

public:
	Rectangle Rec;
	Point Origin;

	void SetHitBox(Point Org, Point WH, Color clr);
	const Point GetHitBoxPos();
	const Point GetHitBoxOrigin();

	const Rectangle GetHitBox();

	static bool CheckBoxCollision(BoxCollider2D HB_A, BoxCollider2D HB_B);
	static bool CheckRayCollision(BoxCollider2D HB_A, BoxCollider2D HB_B, Raycast2D& rayhit);

	BoxCollider2D();
	BoxCollider2D(Rectangle rec);

	static void DrawBox(Vector2 a, Vector2 b);
};