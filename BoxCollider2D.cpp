#include "Headers/BoxCollider2D.h"
#include <array>

void BoxCollider2D::DrawBox(Vector2 a, Vector2 b)
{
	Vector2 c = Vector2(a.x, b.y);
	Vector2 d = Vector2(b.x, a.y);

	const std::array<Vector2, 4> points = { a,c,d,b };
	DrawTriangleStrip(points.data(), 4, WHITE);

}

const Rectangle BoxCollider2D::GetHitBox() {
	return Rec;
}

bool BoxCollider2D::CheckBoxCollision(BoxCollider2D HB_A, BoxCollider2D HB_B)
{


	/* ATTEMPT 1
	float dx = a.x1 - a.x2;
	float dy = a.y1 - a.y2;

	float minDistanceX = (HB_A.Rec.width / 2 + HB_B.Rec.width / 2);
	float minDistanceY = (HB_A.Rec.height / 2 + HB_B.Rec.height / 2);

	float overlapX = minDistanceX - abs(dx);
	float overlapY = minDistanceY - abs(dy);

	if (overlapX > 0 && overlapY > 0) {
		if (overlapX < overlapY) {
			if (dx < 0) {
				HitPoint.x -= overlapX;
			}
			else {
				HitPoint.x += overlapX;
			}
		}
		else {
			if (dy < 0) {
				HitPoint.y -= overlapY;
			}
			else {
				HitPoint.y += overlapY;
			}

		}

		std::cout << HitPoint << std::endl;
		return true;
	}
	*/

	float dx = HB_A.Origin.x - HB_B.Origin.x;
	float dy = HB_A.Origin.y - HB_B.Origin.y;

	if (std::abs(dx) < 0.001f && std::abs(dy) < 0.001f) return true;

	float halfW = (HB_A.Rec.width + HB_B.Rec.width) * 0.5f;
	float halfH = (HB_A.Rec.height + HB_B.Rec.height) * 0.5f;

	if (halfW >= std::abs(dx) && halfH >= std::abs(dy)) {
		return true;
	}

	return false;

}

bool BoxCollider2D::CheckRayCollision(BoxCollider2D HB_A, BoxCollider2D HB_B, Raycast2D& rayhit)
{
	/*
	Ray2D ray(HB_A.Origin, HB_B.Origin, GREEN);
	ray.Dir = (ray.To - ray.Origin) / Point::Magnitude(ray.To, ray.Dir);

	float mag = Point::Magnitude(ray.Origin, ray.To);

	ray.DrawRay2D();

	float dy = HB_B.Origin.y - HB_A.Origin.y;
	float dx = HB_B.Origin.x - HB_A.Origin.x;

	float maxReach = (std::sqrt(HB_A.Rec.width * HB_A.Rec.width + HB_A.Rec.height * HB_A.Rec.height) +
		std::sqrt(HB_B.Rec.width * HB_B.Rec.width + HB_B.Rec.height * HB_B.Rec.height)) * 0.5f;

	if (mag <= maxReach) {


		float halfH = (HB_B.Rec.height * 0.5f);
		float halfW = (HB_B.Rec.width * 0.5f);

		float x = halfH * (abs(dx) / abs(dy));
		float y = halfW * (abs(dy) / abs(dx));

		if (abs(dy) / (HB_B.Rec.height) > abs(dx) / (HB_B.Rec.width)) {
			rayhit.HitPoint.y = (dy < 0) ? HB_B.Origin.y + halfH : HB_B.Origin.y - halfH;
			rayhit.HitPoint.x = (dx < 0) ? HB_B.Origin.x + x : HB_B.Origin.x - x;
		}
		else {
			rayhit.HitPoint.y = (dy < 0) ? HB_B.Origin.y + y : HB_B.Origin.y - y;
			rayhit.HitPoint.x = (dx < 0) ? HB_B.Origin.x + halfW : HB_B.Origin.x - halfW;
		}

		return true;
	}


	*/

	return false;

}

BoxCollider2D::BoxCollider2D()
{
	Rec = Rectangle(0);
	Origin = Point(0, 0);
}

BoxCollider2D::BoxCollider2D(Rectangle rec) {
	Rec = rec;
	Origin = Point(Rec.x + Rec.width / 2, Rec.y + Rec.height / 2);
}

void BoxCollider2D::SetHitBox(Point Org, Point WH, Color clr) {


	Rec.width = WH.x;
	Rec.height = WH.y;

	Rec.x = Org.x - WH.x / 2;
	Rec.y = Org.y - WH.y / 2;

	Origin = Org;
	Collision2D::color = clr;
}

const Point BoxCollider2D::GetHitBoxPos()
{

	return Point(Rec.x,Rec.y);
}

const Point BoxCollider2D::GetHitBoxOrigin()
{
	return Point(Origin.x,Origin.y);
}
