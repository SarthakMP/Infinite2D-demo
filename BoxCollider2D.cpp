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
	float dx = HB_A.Origin.x - HB_B.Origin.x;
	float dy = HB_A.Origin.y - HB_B.Origin.y;


	float halfW = (HB_A.Rec.width + HB_B.Rec.width) * 0.5f;
	float halfH = (HB_A.Rec.height + HB_B.Rec.height) * 0.5f;

	return (dx <= halfW) && (dy<= halfH);
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
	clr = Color();
	id = 0;
}

BoxCollider2D::BoxCollider2D(Rectangle rec) {
	Rec = rec;
	Origin = Point(Rec.x + Rec.width / 2, Rec.y + Rec.height / 2);
	clr = Color();
	id = 0;
}

BoxCollider2D::BoxCollider2D(Rectangle rec, Color in_clr)
{
	Rec = rec;
	Origin = Point(Rec.x + Rec.width / 2, Rec.y + Rec.height / 2);
	clr = in_clr;
	id = 0;
	
}

void BoxCollider2D::SetHitBox(Point Org, Point WH, Color in_clr) {


	Rec.width = WH.x;
	Rec.height = WH.y;

	Rec.x = Org.x - WH.x / 2;
	Rec.y = Org.y - WH.y / 2;

	Origin = Org;
	clr = in_clr;
}

const Point BoxCollider2D::GetHitBoxPos()
{

	return Point(Rec.x,Rec.y);
}

const Point BoxCollider2D::GetHitBoxOrigin()
{
	return Point(Origin.x,Origin.y);
}


