#pragma once
#include"Point.h"
#include"Collision2D.h"

class BoxCollider2D : public Collision2D {
	bool isActive = false;
public:
	Rectangle Rec;
	Point Origin;
	Color clr;



	void SetHitBox(Point Org, Point WH, Color clr);
	const Point GetHitBoxPos();
	const Point GetHitBoxOrigin();

	const void SetActive(bool flag);
	const bool GetActive();

	const Rectangle GetHitBox();

	static bool CheckBoxCollision(BoxCollider2D HB_A, BoxCollider2D HB_B);
	static bool CheckRayCollision(BoxCollider2D HB_A, BoxCollider2D HB_B, Raycast2D& rayhit);

	BoxCollider2D();
	BoxCollider2D(Rectangle rec);
	BoxCollider2D(Rectangle rec,Color clr);

	static void DrawBox(Vector2 a, Vector2 b);
};